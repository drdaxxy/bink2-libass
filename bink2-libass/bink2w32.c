#include "bink2w32.h"

#include <Simd/SimdLib.h>
#include <ass/ass.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

static ASS_Library* AssHandler;
static ASS_Renderer* AssRenderer;
static ASS_Track* AssTrack;

// partial
typedef struct BINK {
  uint32_t Width;         // Width (1 based, 640 for example)
  uint32_t Height;        // Height (1 based, 480 for example)
  uint32_t Frames;        // Number of frames (1 based, 100 = 100 frames)
  uint32_t FrameNum;      // Frame to *be* displayed (1 based)
  uint32_t LastFrameNum;  // Last frame decompressed or skipped (1 based)

  uint32_t FrameRate;     // Frame Rate Numerator
  uint32_t FrameRateDiv;  // Frame Rate Divisor (frame rate=numerator/divisor)
} BINK;

typedef void*(__stdcall* BINKOPEN)(const char* name, uint32_t flags);
typedef void(__stdcall* BINKCLOSE)(BINK* bnk);
typedef int32_t(__stdcall* BINKCOPYTOBUFFER)(BINK* bnk, void* dest,
                                             int32_t destpitch,
                                             uint32_t destheight,
                                             uint32_t destx, uint32_t desty,
                                             uint32_t flags);
static BINKOPEN BinkOpen = NULL;
static BINKCLOSE BinkClose = NULL;
static BINKCOPYTOBUFFER BinkCopyToBuffer = NULL;

FARPROC p[73] = {NULL};
HINSTANCE hL = NULL;

BOOL WINAPI DllMain(HINSTANCE hInst, DWORD reason, LPVOID reserved) {
  if (reason == DLL_PROCESS_ATTACH) {
    hL = LoadLibrary(".\\real_bink2w32.dll");
    if (!hL) return false;

    getOriginalExports();

    for (size_t i = 0; i < 73; i++) {
      if (!p[i]) {
        MessageBox(NULL, "Supplied Bink version is unsupported.",
                   "bink2-libass", MB_OK);
        return false;
      }
    }

    BinkOpen = (BINKOPEN)GetProcAddress(hL, "_BinkOpen@8");
    BinkClose = (BINKCLOSE)GetProcAddress(hL, "_BinkClose@4");
    BinkCopyToBuffer =
        (BINKCOPYTOBUFFER)GetProcAddress(hL, "_BinkCopyToBuffer@28");
  }
  if (reason == DLL_PROCESS_DETACH) {
    FreeLibrary(hL);
  }

  return true;
}

#ifdef _DEBUG
void msg_callback(int level, const char* fmt, va_list va, void* data) {
  if (level > 6) return;
  char buffer[500];
  vsprintf_s(buffer, 500, fmt, va);
  MessageBox(NULL, buffer, "bink2-libass", MB_OK);
}
#endif

bool initLib() {
  if (AssHandler) return true;

  AssHandler = ass_library_init();
  if (!AssHandler) {
    MessageBox(NULL, "ass_library_init failed!", "bink2-libass", MB_OK);
    return false;
  }

  ass_set_fonts_dir(AssHandler, "subs/fonts");
#ifdef _DEBUG
  ass_set_message_cb(AssHandler, msg_callback, NULL);
#endif

  return true;
}

bool initRenderer() {
  if (AssRenderer) return true;

  AssRenderer = ass_renderer_init(AssHandler);
  if (!AssRenderer) {
    MessageBox(NULL, "ass_renderer_init failed!", "bink2-libass", MB_OK);
    return false;
  }

  ass_set_fonts(AssRenderer, NULL, "sans-serif", ASS_FONTPROVIDER_AUTODETECT,
                NULL, 1);

  return true;
}

void* __stdcall BinkOpen_wrapper(const char* name, uint32_t flags) {
  if (!initLib()) return BinkOpen(name, flags);
  if (AssTrack) {
    ass_free_track(AssTrack);
    AssTrack = NULL;
  }

  if (!initRenderer()) return BinkOpen(name, flags);

  const char* tmp = name;
  if (strrchr(tmp, '\\')) tmp = strrchr(tmp, '\\') + 1;
  if (strrchr(tmp, '/')) tmp = strrchr(tmp, '/') + 1;
  size_t length = strlen(tmp) + strlen("subs/") + strlen(".ass") + 1;
  char* subName = (char*)calloc(length, 1);
  snprintf(subName, length, "subs/%s.ass", tmp);

  AssTrack = ass_read_file(AssHandler, subName, "UTF-8");
  free(subName);
  return BinkOpen(name, flags);
}

void __stdcall BinkClose_wrapper(BINK* bnk) {
  BinkClose(bnk);
  if (AssTrack) {
    ass_free_track(AssTrack);
    AssTrack = NULL;
  }
  if (AssRenderer) {
    ass_renderer_done(AssRenderer);
    AssRenderer = NULL;
  }
}

int32_t __stdcall BinkCopyToBuffer_wrapper(BINK* bnk, void* dest,
                                           int32_t destpitch,
                                           uint32_t destheight, uint32_t destx,
                                           uint32_t desty, uint32_t flags) {

  if (!AssTrack || !AssRenderer)
    return BinkCopyToBuffer(bnk, dest, destpitch, destheight, destx, desty,
                            flags);

  uint32_t destwidth = destpitch / 4;
  ass_set_frame_size(AssRenderer, destwidth, destheight);
  // Not entirely sure whether FrameNum is correct here or off by one, but it's
  // pedantic anyway
  uint32_t curTime = (uint32_t)(
      bnk->FrameNum *
      (1000.0 / ((double)bnk->FrameRate / (double)bnk->FrameRateDiv)));
  size_t align = SimdAlignment();

  // This way our writes are guaranteed to be aligned at least every 4 pixels
  uint8_t* frame =
      (uint8_t*)SimdAllocate(SimdAlign(destpitch * destheight, align), align);
  // TODO: actually use destx and desty (figure out if Bink clips output or
  // expects destpitch/destheight to match)
  int32_t retval =
      BinkCopyToBuffer(bnk, frame, destpitch, destheight, destx, desty, flags);

  ASS_Image* subpict = ass_render_frame(AssRenderer, AssTrack, curTime, NULL);

  for (; subpict; subpict = subpict->next) {
    if (subpict->h == 0 || subpict->w == 0) continue;

    uint8_t* background =
        frame + subpict->dst_x * 4 + subpict->dst_y * destpitch;

    const uint8_t Rf = (subpict->color >> 24) & 0xff;
    const uint8_t Gf = (subpict->color >> 16) & 0xff;
    const uint8_t Bf = (subpict->color >> 8) & 0xff;
    const uint8_t Af = 255 - (subpict->color & 0xff);

    // no, this shouldn't be subpict->stride, subpict->stride is for 1bpp
    size_t fgStride = subpict->w * 4;
    uint8_t* foreground =
        (uint8_t*)SimdAllocate(SimdAlign(subpict->h * fgStride, align), align);
    SimdFillBgra(foreground, fgStride, subpict->w, subpict->h, Bf, Gf, Rf, Af);
    SimdAlphaBlending(foreground, fgStride, subpict->w, subpict->h, 4,
                      subpict->bitmap, subpict->stride, background, destpitch);
    SimdFree(foreground);
  }

// Pure C alpha blend, for reference. Please do not actually use, it's really
// slow.
#if 0
  for (; subpict; subpict = subpict->next) {
    const uint8_t Af = 255 - (subpict->color & 0xff);
    const uint8_t Rf = (subpict->color >> 24) & 0xff;
    const uint8_t Gf = (subpict->color >> 16) & 0xff;
    const uint8_t Bf = (subpict->color >> 8) & 0xff;

    uint8_t* foreground = subpict->bitmap;
    uint8_t* background =
        (uint8_t*)dest + ((subpict->dst_y * destwidth) + subpict->dst_x) * 4;

    for (size_t y = 0; y < subpict->h; y++) {
#pragma omp parallel for
      for (size_t x = 0; x < subpict->w; x++) {
        const uint8_t Aff = (foreground[x] * Af) / 255;
        if (Aff == 0) continue;
        if (Aff == 255) {
          ((uint32_t*)background)[x] = 0xFF000000 | (Bf << 16) | (Gf << 8) | Rf;
          continue;
        }
        const uint8_t invAff = 255 - Aff;
        background[4 * x + 0] = (Aff * Rf + invAff * background[4 * x + 0]) / 255;
        background[4 * x + 1] = (Aff * Gf + invAff * background[4 * x + 1]) / 255;
        background[4 * x + 2] = (Aff * Bf + invAff * background[4 * x + 2]) / 255;
      }
      foreground += subpict->stride;
      background += destpitch;
    }
  }
#endif

  SimdCopy(frame, destpitch, destpitch / 4, destheight, 4, (uint8_t*)dest,
           destpitch);
  SimdFree(frame);

  return retval;
}
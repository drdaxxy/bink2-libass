#include "bink2w32.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

void getOriginalExports() {
  p[0] = GetProcAddress(hL, "_BinkAllocateFrameBuffers@12");
  p[1] = GetProcAddress(hL, "_BinkClose@4");
  p[2] = GetProcAddress(hL, "_BinkCloseTrack@4");
  p[3] = GetProcAddress(hL, "_BinkControlBackgroundIO@8");
  p[4] = GetProcAddress(hL, "_BinkCopyToBuffer@28");
  p[5] = GetProcAddress(hL, "_BinkCopyToBufferRect@44");
  p[6] = GetProcAddress(hL, "_BinkDoFrame@4");
  p[7] = GetProcAddress(hL, "_BinkDoFrameAsync@12");
  p[8] = GetProcAddress(hL, "_BinkDoFrameAsyncMulti@12");
  p[9] = GetProcAddress(hL, "_BinkDoFrameAsyncWait@8");
  p[10] = GetProcAddress(hL, "_BinkDoFramePlane@8");
  p[11] = GetProcAddress(hL, "_BinkFreeGlobals@0");
  p[12] = GetProcAddress(hL, "_BinkGetError@0");
  p[13] = GetProcAddress(hL, "_BinkGetFrameBuffersInfo@8");
  p[14] = GetProcAddress(hL, "_BinkGetGPUDataBuffersInfo@8");
  p[15] = GetProcAddress(hL, "_BinkGetKeyFrame@12");
  p[16] = GetProcAddress(hL, "_BinkGetPlatformInfo@8");
  p[17] = GetProcAddress(hL, "_BinkGetRealtime@12");
  p[18] = GetProcAddress(hL, "_BinkGetRects@4");
  p[19] = GetProcAddress(hL, "_BinkGetSummary@8");
  p[20] = GetProcAddress(hL, "_BinkGetTrackData@8");
  p[21] = GetProcAddress(hL, "_BinkGetTrackID@8");
  p[22] = GetProcAddress(hL, "_BinkGetTrackMaxSize@8");
  p[23] = GetProcAddress(hL, "_BinkGetTrackType@8");
  p[24] = GetProcAddress(hL, "_BinkGoto@12");
  p[25] = GetProcAddress(hL, "_BinkLogoAddress@0");
  p[26] = GetProcAddress(hL, "_BinkNextFrame@4");
  p[27] = GetProcAddress(hL, "_BinkOpen@8");
  p[28] = GetProcAddress(hL, "_BinkOpenDirectSound@4");
  p[29] = GetProcAddress(hL, "_BinkOpenMiles@4");
  p[30] = GetProcAddress(hL, "_BinkOpenTrack@8");
  p[31] = GetProcAddress(hL, "_BinkOpenWaveOut@4");
  p[32] = GetProcAddress(hL, "_BinkOpenWithOptions@12");
  p[33] = GetProcAddress(hL, "_BinkOpenXAudio27@4");
  p[34] = GetProcAddress(hL, "_BinkOpenXAudio28@4");
  p[35] = GetProcAddress(hL, "_BinkOpenXAudio2@4");
  p[36] = GetProcAddress(hL, "_BinkPause@8");
  p[37] = GetProcAddress(hL, "_BinkRegisterFrameBuffers@8");
  p[38] = GetProcAddress(hL, "_BinkRegisterGPUDataBuffers@8");
  p[39] = GetProcAddress(hL, "_BinkRequestStopAsyncThread@4");
  p[40] = GetProcAddress(hL, "_BinkRequestStopAsyncThreadsMulti@8");
  p[41] = GetProcAddress(hL, "_BinkService@4");
  p[42] = GetProcAddress(hL, "_BinkSetError@4");
  p[43] = GetProcAddress(hL, "_BinkSetFileOffset@8");
  p[44] = GetProcAddress(hL, "_BinkSetFrameRate@8");
  p[45] = GetProcAddress(hL, "_BinkSetIO@4");
  p[46] = GetProcAddress(hL, "_BinkSetIOSize@4");
  p[47] = GetProcAddress(hL, "_BinkSetMemory@8");
  p[48] = GetProcAddress(hL, "_BinkSetOSFileCallbacks@16");
  p[49] = GetProcAddress(hL, "_BinkSetPan@12");
  p[50] = GetProcAddress(hL, "_BinkSetSimulate@4");
  p[51] = GetProcAddress(hL, "_BinkSetSoundOnOff@8");
  p[52] = GetProcAddress(hL, "_BinkSetSoundSystem2@12");
  p[53] = GetProcAddress(hL, "_BinkSetSoundSystem@8");
  p[54] = GetProcAddress(hL, "_BinkSetSoundTrack@8");
  p[55] = GetProcAddress(hL, "_BinkSetSpeakerVolumes@20");
  p[56] = GetProcAddress(hL, "_BinkSetVideoOnOff@8");
  p[57] = GetProcAddress(hL, "_BinkSetVolume@12");
  p[58] = GetProcAddress(hL, "_BinkSetWillLoop@8");
  p[59] = GetProcAddress(hL, "_BinkShouldSkip@4");
  p[60] = GetProcAddress(hL, "_BinkStartAsyncThread@8");
  p[61] = GetProcAddress(hL, "_BinkUtilCPUs@0");
  p[62] = GetProcAddress(hL, "_BinkUtilFree@4");
  p[63] = GetProcAddress(hL, "_BinkUtilMalloc@4");
  p[64] = GetProcAddress(hL, "_BinkUtilMutexCreate@8");
  p[65] = GetProcAddress(hL, "_BinkUtilMutexDestroy@4");
  p[66] = GetProcAddress(hL, "_BinkUtilMutexLock@4");
  p[67] = GetProcAddress(hL, "_BinkUtilMutexLockTimeOut@8");
  p[68] = GetProcAddress(hL, "_BinkUtilMutexUnlock@4");
  p[69] = GetProcAddress(hL, "_BinkWait@4");
  p[70] = GetProcAddress(hL, "_BinkWaitStopAsyncThread@4");
  p[71] = GetProcAddress(hL, "_BinkWaitStopAsyncThreadsMulti@8");
  p[72] = GetProcAddress(hL, "_RADTimerRead@0");
}

__declspec(naked) void __stdcall BinkAllocateFrameBuffers_wrapper() {
  __asm
  {
    jmp p[0 * 4];
  }
}

/*
__declspec(naked) void __stdcall BinkClose_wrapper() {
__asm
{
jmp p[1 * 4];
}
}
*/

__declspec(naked) void __stdcall BinkCloseTrack_wrapper() {
  __asm
  {
    jmp p[2 * 4];
  }
}

__declspec(naked) void __stdcall BinkControlBackgroundIO_wrapper() {
  __asm
  {
    jmp p[3 * 4];
  }
}

/*
__declspec(naked) void __stdcall BinkCopyToBuffer_wrapper() {
__asm
{
jmp p[4 * 4];
}
}
*/

__declspec(naked) void __stdcall BinkCopyToBufferRect_wrapper() {
  __asm
  {
    jmp p[5 * 4];
  }
}

__declspec(naked) void __stdcall BinkDoFrame_wrapper() {
  __asm
  {
    jmp p[6 * 4];
  }
}

__declspec(naked) void __stdcall BinkDoFrameAsync_wrapper() {
  __asm
  {
    jmp p[7 * 4];
  }
}

__declspec(naked) void __stdcall BinkDoFrameAsyncMulti_wrapper() {
  __asm
  {
    jmp p[8 * 4];
  }
}

__declspec(naked) void __stdcall BinkDoFrameAsyncWait_wrapper() {
  __asm
  {
    jmp p[9 * 4];
  }
}

__declspec(naked) void __stdcall BinkDoFramePlane_wrapper() {
  __asm
  {
    jmp p[10 * 4];
  }
}

__declspec(naked) void __stdcall BinkFreeGlobals_wrapper() {
  __asm
  {
    jmp p[11 * 4];
  }
}

__declspec(naked) void __stdcall BinkGetError_wrapper() {
  __asm
  {
    jmp p[12 * 4];
  }
}

__declspec(naked) void __stdcall BinkGetFrameBuffersInfo_wrapper() {
  __asm
  {
    jmp p[13 * 4];
  }
}

__declspec(
    naked) void __stdcall BinkGetGPUDataBuffersInfo_wrapper() {
  __asm
  {
    jmp p[14 * 4];
  }
}

__declspec(naked) void __stdcall BinkGetKeyFrame_wrapper() {
  __asm
  {
    jmp p[15 * 4];
  }
}

__declspec(naked) void __stdcall BinkGetPlatformInfo_wrapper() {
  __asm
  {
    jmp p[16 * 4];
  }
}

__declspec(naked) void __stdcall BinkGetRealtime_wrapper() {
  __asm
  {
    jmp p[17 * 4];
  }
}

__declspec(naked) void __stdcall BinkGetRects_wrapper() {
  __asm
  {
    jmp p[18 * 4];
  }
}

__declspec(naked) void __stdcall BinkGetSummary_wrapper() {
  __asm
  {
    jmp p[19 * 4];
  }
}

__declspec(naked) void __stdcall BinkGetTrackData_wrapper() {
  __asm
  {
    jmp p[20 * 4];
  }
}

__declspec(naked) void __stdcall BinkGetTrackID_wrapper() {
  __asm
  {
    jmp p[21 * 4];
  }
}

__declspec(naked) void __stdcall BinkGetTrackMaxSize_wrapper() {
  __asm
  {
    jmp p[22 * 4];
  }
}

__declspec(naked) void __stdcall BinkGetTrackType_wrapper() {
  __asm
  {
    jmp p[23 * 4];
  }
}

__declspec(naked) void __stdcall BinkGoto_wrapper() {
  __asm
  {
    jmp p[24 * 4];
  }
}

__declspec(naked) void __stdcall BinkLogoAddress_wrapper() {
  __asm
  {
    jmp p[25 * 4];
  }
}

__declspec(naked) void __stdcall BinkNextFrame_wrapper() {
  __asm
  {
    jmp p[26 * 4];
  }
}

/*
__declspec(naked) void __stdcall BinkOpen_wrapper() {
__asm
{
jmp p[27 * 4];
}
}
*/

__declspec(naked) void __stdcall BinkOpenDirectSound_wrapper() {
  __asm
  {
    jmp p[28 * 4];
  }
}

__declspec(naked) void __stdcall BinkOpenMiles_wrapper() {
  __asm
  {
    jmp p[29 * 4];
  }
}

__declspec(naked) void __stdcall BinkOpenTrack_wrapper() {
  __asm
  {
    jmp p[30 * 4];
  }
}

__declspec(naked) void __stdcall BinkOpenWaveOut_wrapper() {
  __asm
  {
    jmp p[31 * 4];
  }
}

__declspec(naked) void __stdcall BinkOpenWithOptions_wrapper() {
  __asm
  {
    jmp p[32 * 4];
  }
}

__declspec(naked) void __stdcall BinkOpenXAudio27_wrapper() {
  __asm
  {
    jmp p[33 * 4];
  }
}

__declspec(naked) void __stdcall BinkOpenXAudio28_wrapper() {
  __asm
  {
    jmp p[34 * 4];
  }
}

__declspec(naked) void __stdcall BinkOpenXAudio2_wrapper() {
  __asm
  {
    jmp p[35 * 4];
  }
}

__declspec(naked) void __stdcall BinkPause_wrapper() {
  __asm
  {
    jmp p[36 * 4];
  }
}

__declspec(naked) void __stdcall BinkRegisterFrameBuffers_wrapper() {
  __asm
  {
    jmp p[37 * 4];
  }
}

__declspec(
    naked) void __stdcall BinkRegisterGPUDataBuffers_wrapper() {
  __asm
  {
    jmp p[38 * 4];
  }
}

__declspec(
    naked) void __stdcall BinkRequestStopAsyncThread_wrapper() {
  __asm
  {
    jmp p[39 * 4];
  }
}

__declspec(
    naked) void __stdcall BinkRequestStopAsyncThreadsMulti_wrapper() {
  __asm
  {
    jmp p[40 * 4];
  }
}

__declspec(naked) void __stdcall BinkService_wrapper() {
  __asm
  {
    jmp p[41 * 4];
  }
}

__declspec(naked) void __stdcall BinkSetError_wrapper() {
  __asm
  {
    jmp p[42 * 4];
  }
}

__declspec(naked) void __stdcall BinkSetFileOffset_wrapper() {
  __asm
  {
    jmp p[43 * 4];
  }
}

__declspec(naked) void __stdcall BinkSetFrameRate_wrapper() {
  __asm
  {
    jmp p[44 * 4];
  }
}

__declspec(naked) void __stdcall BinkSetIO_wrapper() {
  __asm
  {
    jmp p[45 * 4];
  }
}

__declspec(naked) void __stdcall BinkSetIOSize_wrapper() {
  __asm
  {
    jmp p[46 * 4];
  }
}

__declspec(naked) void __stdcall BinkSetMemory_wrapper() {
  __asm
  {
    jmp p[47 * 4];
  }
}

__declspec(naked) void __stdcall BinkSetOSFileCallbacks_wrapper() {
  __asm
  {
    jmp p[48 * 4];
  }
}

__declspec(naked) void __stdcall BinkSetPan_wrapper() {
  __asm
  {
    jmp p[49 * 4];
  }
}

__declspec(naked) void __stdcall BinkSetSimulate_wrapper() {
  __asm
  {
    jmp p[50 * 4];
  }
}

__declspec(naked) void __stdcall BinkSetSoundOnOff_wrapper() {
  __asm
  {
    jmp p[51 * 4];
  }
}

__declspec(naked) void __stdcall BinkSetSoundSystem2_wrapper() {
  __asm
  {
    jmp p[52 * 4];
  }
}

__declspec(naked) void __stdcall BinkSetSoundSystem_wrapper() {
  __asm
  {
    jmp p[53 * 4];
  }
}

__declspec(naked) void __stdcall BinkSetSoundTrack_wrapper() {
  __asm
  {
    jmp p[54 * 4];
  }
}

__declspec(naked) void __stdcall BinkSetSpeakerVolumes_wrapper() {
  __asm
  {
    jmp p[55 * 4];
  }
}

__declspec(naked) void __stdcall BinkSetVideoOnOff_wrapper() {
  __asm
  {
    jmp p[56 * 4];
  }
}

__declspec(naked) void __stdcall BinkSetVolume_wrapper() {
  __asm
  {
    jmp p[57 * 4];
  }
}

__declspec(naked) void __stdcall BinkSetWillLoop_wrapper() {
  __asm
  {
    jmp p[58 * 4];
  }
}

__declspec(naked) void __stdcall BinkShouldSkip_wrapper() {
  __asm
  {
    jmp p[59 * 4];
  }
}

__declspec(naked) void __stdcall BinkStartAsyncThread_wrapper() {
  __asm
  {
    jmp p[60 * 4];
  }
}

__declspec(naked) void __stdcall BinkUtilCPUs_wrapper() {
  __asm
  {
    jmp p[61 * 4];
  }
}

__declspec(naked) void __stdcall BinkUtilFree_wrapper() {
  __asm
  {
    jmp p[62 * 4];
  }
}

__declspec(naked) void __stdcall BinkUtilMalloc_wrapper() {
  __asm
  {
    jmp p[63 * 4];
  }
}

__declspec(naked) void __stdcall BinkUtilMutexCreate_wrapper() {
  __asm
  {
    jmp p[64 * 4];
  }
}

__declspec(naked) void __stdcall BinkUtilMutexDestroy_wrapper() {
  __asm
  {
    jmp p[65 * 4];
  }
}

__declspec(naked) void __stdcall BinkUtilMutexLock_wrapper() {
  __asm
  {
    jmp p[66 * 4];
  }
}

__declspec(naked) void __stdcall BinkUtilMutexLockTimeOut_wrapper() {
  __asm
  {
    jmp p[67 * 4];
  }
}

__declspec(naked) void __stdcall BinkUtilMutexUnlock_wrapper() {
  __asm
  {
    jmp p[68 * 4];
  }
}

__declspec(naked) void __stdcall BinkWait_wrapper() {
  __asm
  {
    jmp p[69 * 4];
  }
}

__declspec(naked) void __stdcall BinkWaitStopAsyncThread_wrapper() {
  __asm
  {
    jmp p[70 * 4];
  }
}

__declspec(
    naked) void __stdcall BinkWaitStopAsyncThreadsMulti_wrapper() {
  __asm
  {
    jmp p[71 * 4];
  }
}

__declspec(naked) void __stdcall RADTimerRead_wrapper() {
  __asm
  {
    jmp p[72 * 4];
  }
}
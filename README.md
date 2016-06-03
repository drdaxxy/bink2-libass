# bink2-libass
This project transparently adds Advanced SubStation Alpha subtitle support to Windows games using Bink 2 for video playback.
It currently only supports 32-bit games, though it could be easily extended to 64-bit.
Probably won't work with all Bink 2 games as it is, since I make some assumptions about how the API is used, but this is also easy to fix. Feel free to open an issue if a game doesn't work for you.

## Usage
In your game directory, rename `bink2w32.dll` to `real_bink2w32.dll`, drop in the DLLs, and create a directory called *subs*. If you need non-system fonts, also create a subdirectory in *subs* called *fonts* and put your font files in there. For each video you want to subtitle, place a sub track with the video's filename with .ass added to it into the *subs* directory (e.g. `subs\foo.bk2.ass` for `foo.bk2`).

## Dependencies
* [libass](https://github.com/libass/libass)
* [Simd Library](http://simd.sourceforge.net)

## Compiling
Open project, adjust include/lib paths in project configuration, build.
(Please do tell me if there's a better convention for distributing VC++ projects with external dependencies without using external build tools.)

## License
```
           DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
                   Version 2, December 2004

Copyright (C) 2004 Sam Hocevar <sam@hocevar.net>

Everyone is permitted to copy and distribute verbatim or modified
copies of this license document, and changing it is allowed as long
as the name is changed.

           DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
  TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

 0. You just DO WHAT THE FUCK YOU WANT TO.
```
spoon32
=======
Very work-in-progress Psono client for Windows.

Building
--------
Requires mingw-w64 and bmake. On Debian:

    sudo apt install build-essential mingw-w64 bmake

For a default cross build of `bin/spoon32.exe` and `bin/spoon64.exe`:

    bmake

Other targets:

    bmake win32  # yields bin/spoon32.exe
    bmake win64  # yields bin/spoon64.exe
    bmake msys   # for Windows hosts - yields bin/spoon.exe

For more control, there's a generic mingw Makefile in `src/`. It supports
out-of-tree builds with `BINDIR` and `OBJDIR`.

Author
------
By Sijmen J. Mulder (ik@sjmulder.nl). Licensed under the GNU GPL 3.0
or any later version. See LICENSE.txt.

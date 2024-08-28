spoon32
=======
Very work-in-progress Psono client for Windows.

Building
--------
Currently set up for cross compiling with mingw-w64. On Debian:

    sudo apt install build-essential mingw-w64
    
Then:

     make

This yields `dist/spoon32.exe` and `dist/spoon64.exe` as well as
non-stripped `-dbg.exe` versions.

Author
------
By Sijmen J. Mulder (ik@sjmulder.nl). Licensed under the GNU GPL 3.0
or any later version. See LICENSE.txt.


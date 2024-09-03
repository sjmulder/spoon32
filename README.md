spoon32
=======
Very work-in-progress Psono client for Windows.

Building
--------
Requires mingw-w64. On Debian:

    sudo apt install build-essential mingw-w64

There's a generic mingw Makefile in `src/`. The Makefile in the root has
facilities for out-of-tree builds and cross compiling:

    make 		# or 'make default', uses default CC etc.
    make cross-win32	# uses i686-w64-mingw-gcc etc.
    make cross-win64	# uses x86_64-w64-mingw-gcc etc.

    make cross		# both of the cross targets above
    make dist		# same but also puts files in dist/

Author
------
By Sijmen J. Mulder (ik@sjmulder.nl). Licensed under the GNU GPL 3.0
or any later version. See LICENSE.txt.

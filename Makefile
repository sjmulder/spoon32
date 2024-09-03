MAKE_FLAGS.default+=	OBJDIR=../build/default

MAKE_FLAGS.win32+=	OBJDIR=../build/win32
MAKE_FLAGS.win32+=	PROG=spoon32.exe
MAKE_FLAGS.win32+=	CC=i686-w64-mingw32-gcc
MAKE_FLAGS.win32+=	RESC=i686-w64-mingw32-windres

MAKE_FLAGS.win64+=	OBJDIR=../build/win64
MAKE_FLAGS.win64+=	PROG=spoon64.exe
MAKE_FLAGS.win64+=	CC=i686-w64-mingw32-gcc
MAKE_FLAGS.win64+=	RESC=i686-w64-mingw32-windres

all:	default
cross:	cross-win32 cross-win64

default:	; ${MAKE} -C src ${MAKE_FLAGS.default}
cross-win32:	; ${MAKE} -C src ${MAKE_FLAGS.win32}
cross-win64:	; ${MAKE} -C src ${MAKE_FLAGS.win64}

dist: cross
	mkdir -p dist/
	cp build/win32/spoon32.exe dist/
	cp build/win64/spoon64.exe dist/

clean:
	rm -rf dist/
	${MAKE} -C src ${MAKE_FLAGS.default} clean
	${MAKE} -C src ${MAKE_FLAGS.win32} clean
	${MAKE} -C src ${MAKE_FLAGS.win64} clean

.PHONY:	all dist clean default cross cross-win32 cross-win64

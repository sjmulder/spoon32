MAKE_FLAGS.default+=	OBJDIR=../build/default

MAKE_FLAGS.win32+=	OBJDIR=../build/win32
MAKE_FLAGS.win32+=	PROG=spoon32.exe
MAKE_FLAGS.win32+=	CC=i686-w64-mingw32-gcc
MAKE_FLAGS.win32+=	RESC=i686-w64-mingw32-windres

MAKE_FLAGS.win64+=	OBJDIR=../build/win64
MAKE_FLAGS.win64+=	PROG=spoon64.exe
MAKE_FLAGS.win64+=	CC=x86_64-w64-mingw32-gcc
MAKE_FLAGS.win64+=	RESC=x86_64-w64-mingw32-windres

MAKE_FLAGS.win32s+=	OBJDIR=../build/win32s
MAKE_FLAGS.win32s+=	PROG=spoon32s.exe
MAKE_FLAGS.win32s+=	CC=i686-w64-mingw32-gcc
MAKE_FLAGS.win32s+=	RESC=i686-w64-mingw32-windres
MAKE_FLAGS.win32s+=	CFLAGS="${CFLAGS} -Wall -Wextra -fPIE"
MAKE_FLAGS.win32s+=	LDFLAGS=${LDFLAGS} -Wl,--dynamicbase,--export-all-symbols
MAKE_FLAGS.win32s+=	LDLIBS="-lkernel32 -luser32 -lgdi32"

all:	default
cross:	cross-win32 cross-win64 cross-win32s

default:	; ${MAKE} -C src ${MAKE_FLAGS.default}
cross-win32:	; ${MAKE} -C src ${MAKE_FLAGS.win32}
cross-win64:	; ${MAKE} -C src ${MAKE_FLAGS.win64}
cross-win32s:	; ${MAKE} -C src ${MAKE_FLAGS.win32s}

dist: cross
	mkdir -p dist/
	cp build/win32/spoon32.exe dist/
	cp build/win64/spoon64.exe dist/
	cp build/win32s/spoon32s.exe dist/

clean:
	rm -rf dist/
	${MAKE} -C src ${MAKE_FLAGS.default} clean
	${MAKE} -C src ${MAKE_FLAGS.win32} clean
	${MAKE} -C src ${MAKE_FLAGS.win64} clean
	${MAKE} -C src ${MAKE_FLAGS.win32s} clean

.PHONY:	all dist clean default cross cross-win32 cross-win64 cross-win32s

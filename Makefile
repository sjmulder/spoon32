MAKE_ENV.default+=	OBJDIR=../build/default

MAKE_ENV.win32+=	OBJDIR=../build/win32
MAKE_ENV.win32+=	PROG=spoon32.exe
MAKE_ENV.win32+=	CC=i686-w64-mingw32-gcc
MAKE_ENV.win32+=	RESC=i686-w64-mingw32-windres
MAKE_ENV.win32+=	CFLAGS="\
  -I../vendor/curl-win32/include \
  -I../vendor/libsodium-win32/include"
MAKE_ENV.win32+=	LDFLAGS="\
  -L../vendor/curl-win32/lib \
  -L../vendor/libsodium-win32/lib"

MAKE_ENV.win64+=	OBJDIR=../build/win64
MAKE_ENV.win64+=	PROG=spoon64.exe
MAKE_ENV.win64+=	CC=x86_64-w64-mingw32-gcc
MAKE_ENV.win64+=	RESC=x86_64-w64-mingw32-windres
MAKE_ENV.win64+=	CFLAGS="\
  -I../vendor/curl-win64/include \
  -I../vendor/libsodium-win64/include"
MAKE_ENV.win64+=	LDFLAGS="\
  -L../vendor/curl-win64/lib \
  -L../vendor/libsodium-win64/lib"

all:	default
cross:	cross-win32 cross-win64

default:	; ${MAKE_ENV.default} ${MAKE} -C src
cross-win32:	; ${MAKE_ENV.win32} ${MAKE} -C src
cross-win64:	; ${MAKE_ENV.win64} ${MAKE} -C src

dist: cross
	mkdir -p dist/win32
	cp vendor/curl-win32/bin/libcurl.dll dist/win32/
	cp vendor/libsodium-win32/bin/libsodium-26.dll dist/win32/
	cp build/win32/spoon32.exe dist/win32/

	mkdir -p dist/win64
	cp vendor/curl-win64/bin/libcurl-x64.dll dist/win64/
	cp vendor/libsodium-win64/bin/libsodium-26.dll dist/win64/
	cp build/win64/spoon64.exe dist/win64/

clean:
	rm -rf dist/
	env ${MAKE_ENV.default} ${MAKE} -C src clean
	env ${MAKE_ENV.win32} ${MAKE} -C src clean
	env ${MAKE_ENV.win64} ${MAKE} -C src clean

.PHONY:	all dist clean default cross cross-win32 cross-win64

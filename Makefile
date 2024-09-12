CONFIGS=		win32 win64 msys

MINGW_HOST.win32=	i686-w64-mingw32
BIN_SUFX.win32=		32

MINGW_HOST.win64=	x86_64-w64-mingw32
BIN_SUFX.win64=		64

CC.msys=		gcc

all: win32 win64

.include "mk/configs.mk"

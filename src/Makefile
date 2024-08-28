PROG?=	spoon
RESC?=	windres
STRIP?=	strip

OBJ=	winmain.o \
	resource.o \
	classes/main-wnd.o

DIRS=	classes/

CFLAGS+=	-Wall -Wextra
CFLAGS+=	-DUNICODE -D_UNICODE

LDFLAGS+=	-municode

all: | dirs ${PROG}.exe

dirs:
	mkdir -p ${DIRS}

clean:
	rm -f ${PROG}.exe ${PROG}-dbg.exe *.o

${PROG}.exe: ${PROG}-dbg.exe
	cp ${PROG}-dbg.exe ${PROG}.exe
	${STRIP} ${PROG}.exe

${PROG}-dbg.exe: ${OBJ}
	${LINK.o} -o ${PROG}-dbg.exe ${OBJ}

window.h:		classes/classes.h
resource.o:		resource.h manifest.xml
classes/main-wnd.o:	classes/classes.h resource.h

.SUFFIXES: .rc
.PHONY: all dirs clean

.rc.o:
	${RESC} $< $@


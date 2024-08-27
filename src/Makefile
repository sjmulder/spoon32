PROG?=	spoon.exe
RESC?=	windres

OBJ=	winmain.o \
	resource.o \
	classes/main-wnd.o

DIRS=	classes/

CFLAGS+=	-Wall -Wextra
CFLAGS+=	-DUNICODE -D_UNICODE

LDFLAGS+=	-municode

all: | dirs ${PROG}

dirs:
	mkdir -p ${DIRS}

clean:
	rm -f ${PROG} *.o

${PROG}: ${OBJ}
	${LINK.o} -o ${PROG} ${OBJ}

window.h:		classes/classes.h
resource.o:		resource.h
classes/main-wnd.o:	classes/classes.h resource.h

.SUFFIXES: .rc
.PHONY: all dirs clean

.rc.o:
	${RESC} $< $@


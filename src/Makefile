PROG?=		spoon.exe
RESC?=		windres
OBJDIR?=	.

DIRS=		${OBJDIR}

OBJ=		${OBJDIR}/winmain.o \
		${OBJDIR}/util.o \
		${OBJDIR}/resource.o \
		${OBJDIR}/main-wnd.o

CFLAGS+=	-Wall -Wextra
CFLAGS+=	-DUNICODE -D_UNICODE

LDFLAGS+=	-municode

all: | dirs ${OBJDIR}/${PROG}

dirs:
	mkdir -p ${DIRS}

clean:
	rm -f ${OBJDIR}/${PROG} \
	      ${OBJDIR}/*.o

${OBJDIR}/${PROG}: ${OBJ}
	${LINK.o} -o $@ ${OBJ} ${LDLIBS}

${OBJDIR}/%.o: %.c	; ${COMPILE.c} -o $@ $<
${OBJDIR}/%.o: %.rc	; ${RESC} $< $@

${OBJDIR}/winmain.o:		common.h resource.h 
${OBJDIR}/util.o:		common.h
${OBJDIR}/resource.o:		resource.h manifest.xml
${OBJDIR}/main-wnd.o:		common.h resource.h

.PHONY: all dirs clean

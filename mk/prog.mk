BINDIR?=	.
OBJDIR?=	.
BIN_SUFX?=

.if "${MINGW_HOST}" != ""
CC=		${MINGW_HOST}-gcc
WINDRES=	${MINGW_HOST}-windres
.endif

WINDRES?=	windres

CFLAGS+=	-Wall -Wextra -DUNICODE -D_UNICODE
LDFLAGS+=	-mwindows -municode

all:
.PHONY: all

clean:
.PHONY: clean

dirs:
	mkdir -p ${BINDIR} ${OBJDIR}
.PHONY: dirs

.for prog in ${PROGS}
. for src in ${SOURCES.${prog}}
OBJECTS.${prog}+=	${OBJDIR}/${src:.c=.o}

${OBJDIR}/${src:.c=.o}: ${src} ${HEADERS.${prog}}
	${COMPILE.c} -o ${OBJDIR}/${src:.c=.o} ${src}
. endfor

. for rc in ${RESOURCES.${prog}}
OBJECTS.${prog}+=	${OBJDIR}/${rc:.rc=.o}

${OBJDIR}/${rc:.rc=.o}: ${rc} ${HEADERS.${prog}}
	${WINDRES} ${rc} ${OBJDIR}/${rc:.rc=.o}
. endfor

all: ${BINDIR}/${prog}${BIN_SUFX}.exe

clean:
	rm -f ${BINDIR}/${prog}${BIN_SUFX}.exe ${OBJECTS.${prog}}

${BINDIR}/${prog}${BIN_SUFX}.exe: dirs ${OBJECTS.${prog}}
	${LINK.c} -o ${BINDIR}/${prog}${BIN_SUFX}.exe ${OBJECTS.${prog}}
.endfor

print-vars:
	@echo "PROGS= ${PROGS}"
.for prog in ${PROGS}
. for var in SOURCES RESOURCES OBJECTS
	@echo "${var}.${prog}= ${${var}.${prog}}"
. endfor
.endfor
.PHONY: print-prog-vars

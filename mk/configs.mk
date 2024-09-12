CONFIG_VARS=		CC MINGW_HOST BIN_SUFX

.for config in ${CONFIGS}
. for var in ${CONFIG_VARS}
MAKE_FLAGS.${config}+=	${var}=${${var}.${config}}
. endfor
MAKE_FLAGS.${config}+=	OBJDIR=../obj/${config}
MAKE_FLAGS.${config}+=	BINDIR=../bin
.endfor

all: ${CONFIGS}

.for config in ${CONFIGS}
${config}:
	${MAKE} -C src ${MAKE_FLAGS.${config}}
.PHONY: ${config}
.endfor

clean:
.for config in ${CONFIGS}
	rm -rf obj/${config}/
.endfor
	rm -rf bin/

print-vars:
	@echo "CONFIGS= ${CONFIGS}"
.for config in ${CONFIGS}
	@echo "MAKE_FLAGS.${config}= ${MAKE_FLAGS.${config}}"
.endfor
.PHONY: print-vars

.OBJDIR: .

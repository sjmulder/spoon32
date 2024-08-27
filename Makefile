all: win32 win64

win32:
	${MAKE} -C obj/win32
	cp build/win32/spoon32.exe dist/

win64:
	${MAKE} -C obj/win64
	cp build/win64/spoon64.exe dist/

clean:
	${MAKE} -C build/win32 clean
	${MAKE} -C build/win64 clean

.PHONY: all win32 win64 clean


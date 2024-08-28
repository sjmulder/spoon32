all: win32 win64

win32:
	${MAKE} -C obj/win32
	cp obj/win32/spoon32*.exe dist/

win64:
	${MAKE} -C obj/win64
	cp obj/win64/spoon64*.exe dist/

clean:
	${MAKE} -C obj/win32 clean
	${MAKE} -C obj/win64 clean

.PHONY: all win32 win64 clean

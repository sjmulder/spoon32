#include <windows.h>
#include "classes/classes.h"

int WINAPI
wWinMain(
    [[maybe_unused]] HINSTANCE inst,
    [[maybe_unused]] HINSTANCE prev,
    [[maybe_unused]] LPWSTR cmdline,
    int show_cmd)
{
	HWND wnd;
	BOOL ret;
	MSG msg;

	register_main_wnd();

	wnd = create_main_wnd();
	ShowWindow(wnd, show_cmd);	

	while ((ret = GetMessage(&msg, NULL, 0, 0))) {
		if (ret == -1) {
			MessageBox(NULL, L"GetMessage() failed",
			    L"Spoon", MB_OK | MB_ICONEXCLAMATION);
			ExitProcess(1);
		}
	
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	return 0;
}


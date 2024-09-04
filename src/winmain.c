#include <windows.h>
#include <tchar.h>
#include "common.h"
#include "resource.h"

int WINAPI
#ifdef UNICODE
wWinMain(
    [[maybe_unused]] HINSTANCE inst,
    [[maybe_unused]] HINSTANCE prev,
    [[maybe_unused]] LPWSTR cmdline,
    int show_cmd)
#else
WinMain(
    [[maybe_unused]] HINSTANCE inst,
    [[maybe_unused]] HINSTANCE prev,
    [[maybe_unused]] LPSTR cmdline,
    int show_cmd)
#endif
{
	HACCEL accel;
	HWND wnd;
	BOOL ret;
	MSG msg;

	accel = LoadAccelerators(inst, MAKEINTRESOURCE(IDR_ACCELERATOR));
	if (!accel) {
		MessageBox(NULL, _T("Failed to load accelerators"),
		    _T("Spoon"), MB_OK | MB_ICONEXCLAMATION);
		ExitProcess(1);
	}

	register_main_wnd();

	wnd = create_main_wnd();
	ShowWindow(wnd, show_cmd);	

	while ((ret = GetMessage(&msg, NULL, 0, 0))) {
		if (ret == -1) {
			MessageBox(NULL, _T("GetMessage() failed"),
			    _T("Spoon"), MB_OK | MB_ICONEXCLAMATION);
			ExitProcess(1);
		}

		if (TranslateAccelerator(wnd, accel, &msg))
			continue;

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	return 0;
}

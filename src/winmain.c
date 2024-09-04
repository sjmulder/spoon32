#include <windows.h>
#include <curl/curl.h>
#include <sodium.h>
#include "common.h"
#include "resource.h"

int WINAPI
wWinMain(
    [[maybe_unused]] HINSTANCE inst,
    [[maybe_unused]] HINSTANCE prev,
    [[maybe_unused]] LPWSTR cmdline,
    int show_cmd)
{
	HACCEL accel;
	HWND wnd;
	BOOL ret;
	MSG msg;

	if (curl_global_init(CURL_GLOBAL_DEFAULT)) {
		MessageBox(NULL, L"Failed to initialize libcurl.",
		    L"Spoon", MB_OK | MB_ICONEXCLAMATION);
		ExitProcess(1);
	}

	if (sodium_init() == -1) {
		MessageBox(NULL, L"Failed to initialize libsodium.",
		    L"Spoon", MB_OK | MB_ICONEXCLAMATION);
		ExitProcess(1);
	}

	accel = LoadAccelerators(inst, MAKEINTRESOURCE(IDR_ACCELERATOR));
	if (!accel) {
		MessageBox(NULL, L"Failed to load accelerators",
		    L"Spoon", MB_OK | MB_ICONEXCLAMATION);
		ExitProcess(1);
	}

	register_main_wnd();

	wnd = create_main_wnd();
	ShowWindow(wnd, show_cmd);	

	while ((ret = GetMessage(&msg, NULL, 0, 0))) {
		if (ret == -1) {
			MessageBox(NULL, L"GetMessage() failed",
			    L"Spoon", MB_OK | MB_ICONEXCLAMATION);
			ExitProcess(1);
		}

		if (TranslateAccelerator(wnd, accel, &msg))
			continue;

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

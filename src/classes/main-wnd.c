#include <windows.h>
#include "classes.h"
#include "../resource.h"

static const wchar_t class_name[] = L"SpoonMainWnd";

static void
handle_command(HWND wnd, WORD cmd)
{
	switch (cmd) {
	case ID_FILE_CLOSE:
		DestroyWindow(wnd);
		break;
	}
}

static CALLBACK LRESULT
wndproc(
    HWND wnd,
    UINT msg,
    WPARAM wparam,
    LPARAM lparam)
{
	switch (msg) {
	case WM_COMMAND:
		handle_command(wnd, LOWORD(wparam));
		return 0;

	case WM_CLOSE:
		DestroyWindow(wnd);
		return 0;
	
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	
	return DefWindowProc(wnd, msg, wparam, lparam);
}

void
register_main_wnd(void)
{
	WNDCLASSEX wc;
	
	ZeroMemory(&wc, sizeof(wc));
	wc.cbSize = sizeof(wc);
	wc.lpfnWndProc = wndproc;
	wc.hInstance = GetModuleHandle(NULL);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_BTNFACE+1);
	wc.lpszClassName = class_name;
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MENU);

	if (!RegisterClassEx(&wc)) {
		MessageBox(NULL, L"Failed to register main window class",
		    L"Spoon", MB_ICONEXCLAMATION | MB_OK);
		ExitProcess(1);
	}
}

HWND
create_main_wnd(void)
{
	HWND wnd;
	
	wnd = CreateWindowEx(0, class_name, L"Spoon",
	    WS_OVERLAPPEDWINDOW,
	    CW_USEDEFAULT, CW_USEDEFAULT, 
	    CW_USEDEFAULT, CW_USEDEFAULT,
	    NULL, NULL, GetModuleHandle(NULL), NULL);
	
	if (!wnd) {
		MessageBox(NULL, L"Failed to create main window",
		    L"Spoon", MB_ICONEXCLAMATION | MB_OK);
		ExitProcess(1);
	}
	
	return wnd;
}


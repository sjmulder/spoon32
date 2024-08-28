#include <windows.h>
#include <commctrl.h>
#include "classes.h"
#include "../resource.h"

struct class_ctx {
	HWND wnd, tree;
};

static const wchar_t class_name[] = L"SpoonMainWnd";

static void
setup(struct class_ctx *ctx)
{
	ctx->tree = CreateWindowEx(
	    WS_EX_CLIENTEDGE,
	    WC_TREEVIEW, L"Index",
	    WS_VISIBLE | WS_CHILD,
	    0, 0, 100, 100,
	    ctx->wnd, NULL, GetModuleHandle(NULL), NULL);
}

static void
layout(struct class_ctx *ctx)
{
	RECT client;

	GetClientRect(ctx->wnd, &client);
	MoveWindow(ctx->tree, 0, 0, client.right/4, client.bottom, TRUE);
}

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
	struct class_ctx *ctx;

	switch (msg) {
	case WM_CREATE:
		ctx = HeapAlloc(GetProcessHeap(),
		    HEAP_GENERATE_EXCEPTIONS | HEAP_ZERO_MEMORY,
		    sizeof(*ctx));
		ctx->wnd = wnd;
		SetWindowLongPtr(wnd, 0, (LONG_PTR)ctx);
		setup(ctx);
		layout(ctx);
		return 0;

	case WM_SIZE:
		ctx = (struct class_ctx *)GetWindowLongPtr(wnd, 0);
		layout(ctx);
		return 0;

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
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = wndproc;
	wc.cbWndExtra = sizeof(void*);
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

#include <windows.h>
#include "common.h"

void
rect_to_client(HWND wnd, RECT *rect)
{
	POINT top_left, bottom_right;

	top_left.x = rect->left;
	top_left.y = rect->top;
	bottom_right.x = rect->right;
	bottom_right.y = rect->bottom;

	ScreenToClient(wnd, &top_left);
	ScreenToClient(wnd, &bottom_right);

	rect->left = top_left.x;
	rect->top = top_left.y;
	rect->right = bottom_right.x;
	rect->bottom = bottom_right.y;
}

// ANSI Program

#include <windows.h>

// window procedure prototype
LRESULT CALLBACK winProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {
	// create a window class
	WNDCLASSW wc = {0}; // declare window class named wc

	wc.hbrBackground = (HBRUSH)COLOR_WINDOW; // window background
	wc.hCursor = LoadCursor(NULL,IDC_CROSS); // set cursor type for the window
	wc.hInstance = hInst; // define the instance used
	wc.lpszClassName = L"windowClass"; // set a classname using the LPCWSTR char type
	wc.lpfnWndProc = winProc; //set window procedure; message loop involved

	// register the window class
	if (!RegisterClassW(&wc))
		return -1;

	// create a window
	CreateWindowW(L"windowClass", L"Test Window", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 500, 500, NULL, NULL, NULL, NULL);

	// message loop
	MSG msg = {0}; // define message structure

	while(GetMessage(&msg, NULL, NULL, NULL) ) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

// window procedure function
LRESULT CALLBACK winProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
	switch (msg) {
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProcW(hWnd, msg, wp, lp);
	}
}

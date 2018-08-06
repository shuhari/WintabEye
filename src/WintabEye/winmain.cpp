#include "stdafx.h"
#include "MainWindow.h"


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR szCmdLine, int nCmdShow) {
	
	MainWindow mainWin;
	if (!mainWin.Create())
		return -1;
	mainWin.ShowWindow(nCmdShow);
	mainWin.UpdateWindow();

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int) msg.wParam;
}

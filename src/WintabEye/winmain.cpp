#include "stdafx.h"
#include "MainWindow.h"


CAppModule _Module;


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR szCmdLine, int nCmdShow) {
	
	HRESULT hr = ::CoInitialize(NULL);
	ATLASSERT(SUCCEEDED(hr));
	AtlInitCommonControls(ICC_COOL_CLASSES | ICC_BAR_CLASSES);
	hr = _Module.Init(NULL, hInstance);
	ATLASSERT(SUCCEEDED(hr));
	CMessageLoop msgLoop;
	_Module.AddMessageLoop(&msgLoop);

	MainWindow mainWin;
	if (!mainWin.CreateEx())
		return -1;
	mainWin.ShowWindow(nCmdShow);
	mainWin.UpdateWindow();

	int nRet = msgLoop.Run();
	_Module.RemoveMessageLoop();

	_Module.Term();
	CoUninitialize();
	return nRet;
}

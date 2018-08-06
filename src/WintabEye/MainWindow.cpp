#include "stdafx.h"
#include "resource.h"
#include "MainWindow.h"
#include "AboutDialog.h"


MainWindow::MainWindow() {
}


MainWindow::~MainWindow() {
}


BOOL MainWindow::Create() {
	if (CWindowImpl::Create(NULL, rcDefault, _T("WintabEye")) == NULL)
		return FALSE;

	HMODULE hInstance = _AtlBaseModule.GetResourceInstance();
	HMENU hMenu = LoadMenu(hInstance, MAKEINTRESOURCE(IDR_MAINMENU));
	SetMenu(hMenu);
	SetIcon(LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APP)));
	return TRUE;
}

LRESULT MainWindow::onDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& handled) {
	PostQuitMessage(0);
	return 0;
}


LRESULT MainWindow::onFileExit(WORD wNotify, WORD wId, HWND hCtrl, BOOL& handled) {
	PostMessage(WM_CLOSE);
	return 0;
}


LRESULT MainWindow::onHelpAbout(WORD wNotify, WORD wId, HWND hCtrl, BOOL& handled) {
	AboutDialog dlg;
	dlg.DoModal(m_hWnd);
	return 0;
}


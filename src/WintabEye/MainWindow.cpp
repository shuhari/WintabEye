#include "stdafx.h"
#include "resource.h"
#include "MainWindow.h"
#include "AboutDialog.h"
#include "AdminMode.h"


MainWindow::MainWindow() {
}


MainWindow::~MainWindow() {
}


BOOL MainWindow::PreTranslateMessage(MSG* pMsg) {
	return FALSE;
}


BOOL MainWindow::OnIdle() {
	return FALSE;
}


int MainWindow::onCreate(LPCREATESTRUCT pCreateStruct) {
	m_hWndClient = _view.Create(m_hWnd, rcDefault, NULL,
		WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN, WS_EX_CLIENTEDGE);

	CMessageLoop* pLoop = _Module.GetMessageLoop();
	pLoop->AddMessageFilter(this);
	pLoop->AddIdleHandler(this);

	if (IsRunAsAdmin()) {
		UIEnable(IDM_FILE_RUNASADMIN, FALSE);
		SetWindowText(L"WintabEye (Administrator)");
	} else {
		UIEnable(IDM_FILE_RUNASADMIN, TRUE);
		SetWindowText(L"WintabEye");
	}

	SetMsgHandled(FALSE);
	return 0;
}


void MainWindow::onDestroy() {
	PostQuitMessage(0);
	SetMsgHandled(FALSE);
}


void MainWindow::onFileRunAsAdmin(UINT wNotify, int nId, CWindow wnd) {
	if (!IsRunAsAdmin()) {
		if (RestartAsAdmin()) {
			PostMessage(WM_CLOSE);
		}
	}
}


void MainWindow::onFileExit(UINT wNotify, int nId, CWindow wnd) {
	PostMessage(WM_CLOSE);
}


void MainWindow::onHelpAbout(UINT wNotify, int nId, CWindow wnd) {
	AboutDialog dlg;
	dlg.DoModal(m_hWnd);
}


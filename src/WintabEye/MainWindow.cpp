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
	if (CFrameWindowImpl<MainWindow>::PreTranslateMessage(pMsg))
		return TRUE;
	if (_view.m_hWnd && _view.PreTranslateMessage(pMsg))
		return TRUE;
	return FALSE;
}


BOOL MainWindow::OnIdle() {
	UIUpdateToolBar();
	UIUpdateStatusBar();
	return FALSE;
}


int MainWindow::onCreate(LPCREATESTRUCT pCreateStruct) {
	m_hWndClient = _view.Create(m_hWnd, rcDefault, NULL,
		WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN, WS_EX_CLIENTEDGE);

	CreateSimpleToolBar();
	UIAddToolBar(m_hWndToolBar);

	m_hWndStatusBar = _statusBar.Create(*this);
	int statusPanes[] = {
		ID_DEFAULT_PANE,
		ID_PANE_PEN,
		ID_PANE_CURSOR,
		ID_PANE_TILT,
	};
	_statusBar.SetPanes(statusPanes, _countof(statusPanes), false);
	UIAddStatusBar(m_hWndStatusBar);

	CMessageLoop* pLoop = _Module.GetMessageLoop();
	pLoop->AddMessageFilter(this);
	pLoop->AddIdleHandler(this);

	CToolTipCtrl wndTip = (HWND) ::SendMessage(m_hWndToolBar, TB_GETTOOLTIPS, 0, 0);
	wndTip.ModifyStyle(0, TTS_NOPREFIX);

	UISetCheck(ID_VIEW_TOOLBAR, TRUE);
	UISetCheck(ID_VIEW_STATUS_BAR, TRUE);
	if (IsRunAsAdmin()) {
		UIEnable(IDM_FILE_RUNASADMIN, FALSE);
		SetWindowText(L"WintabEye (Administrator)");
	} else {
		UIEnable(IDM_FILE_RUNASADMIN, TRUE);
		SetWindowText(L"WintabEye");
	}
	UISetText(1, L"");
	UISetText(2, L"");
	UISetText(3, L"");

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


void MainWindow::onViewToolBar(UINT wNotify, int nId, CWindow wnd) {
	BOOL visible = !::IsWindowVisible(m_hWndToolBar);
	::ShowWindow(m_hWndToolBar, visible ? SW_SHOWNOACTIVATE : SW_HIDE);
	UISetCheck(ID_VIEW_TOOLBAR, visible);
	UpdateLayout();
}


void MainWindow::onViewStatusBar(UINT wNotify, int nId, CWindow wnd) {
	BOOL visible = !::IsWindowVisible(m_hWndStatusBar);
	::ShowWindow(m_hWndStatusBar, visible ? SW_SHOWNOACTIVATE : SW_HIDE);
	UISetCheck(ID_VIEW_STATUS_BAR, visible);
	UpdateLayout();
}


void MainWindow::onHelpAbout(UINT wNotify, int nId, CWindow wnd) {
	AboutDialog dlg;
	dlg.DoModal(m_hWnd);
}


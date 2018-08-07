#pragma once


#include "resource.h"
#include "CanvasView.h"


class MainWindow : public CFrameWindowImpl<MainWindow, CWindow, CFrameWinTraits>,
	public CUpdateUI<MainWindow>,
	public CMessageFilter,
	public CIdleHandler {
public:
	DECLARE_FRAME_WND_CLASS(_T("WintabEye_MainWindow"), IDR_MAINFRAME)

	BEGIN_UPDATE_UI_MAP(CMainWindow)
		UPDATE_ELEMENT(IDM_FILE_RUNASADMIN, UPDUI_MENUPOPUP)
		UPDATE_ELEMENT(ID_VIEW_TOOLBAR, UPDUI_MENUPOPUP | UPDUI_TOOLBAR)
		UPDATE_ELEMENT(ID_VIEW_STATUS_BAR, UPDUI_MENUPOPUP | UPDUI_TOOLBAR)
		UPDATE_ELEMENT(1, UPDUI_STATUSBAR)
		UPDATE_ELEMENT(2, UPDUI_STATUSBAR)
	END_UPDATE_UI_MAP()

	BEGIN_MSG_MAP_EX(MainWindow)
		MSG_WM_CREATE(onCreate)
		MSG_WM_DESTROY(onDestroy)
		COMMAND_ID_HANDLER_EX(IDM_FILE_RUNASADMIN, onFileRunAsAdmin)
		COMMAND_ID_HANDLER_EX(IDM_FILE_EXIT, onFileExit)
		COMMAND_ID_HANDLER_EX(ID_VIEW_TOOLBAR, onViewToolBar)
		COMMAND_ID_HANDLER_EX(ID_VIEW_STATUS_BAR, onViewStatusBar)
		COMMAND_ID_HANDLER_EX(IDM_HELP_ABOUT, onHelpAbout)
		CHAIN_MSG_MAP(CUpdateUI<MainWindow>)
		CHAIN_MSG_MAP(CFrameWindowImpl<MainWindow>)
	END_MSG_MAP()

	MainWindow();
	~MainWindow();

	BOOL PreTranslateMessage(MSG* pMsg) override;
	BOOL OnIdle() override;

private:
	CanvasView				_view;
	CMultiPaneStatusBarCtrl	_statusBar;

	int onCreate(LPCREATESTRUCT pCreateStruct);
	void onDestroy();
	LRESULT onEraseBkgnd(HDC hdc);

	void onFileRunAsAdmin(UINT, int, CWindow);
	void onFileExit(UINT, int, CWindow);
	void onViewToolBar(UINT, int, CWindow);
	void onViewStatusBar(UINT, int, CWindow);
	void onHelpAbout(UINT, int, CWindow);
};
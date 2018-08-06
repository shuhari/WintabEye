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
	END_UPDATE_UI_MAP()

	BEGIN_MSG_MAP_EX(MainWindow)
		MSG_WM_CREATE(onCreate)
		MSG_WM_DESTROY(onDestroy)
		COMMAND_ID_HANDLER_EX(IDM_FILE_RUNASADMIN, onFileRunAsAdmin)
		COMMAND_ID_HANDLER_EX(IDM_FILE_EXIT, onFileExit)
		COMMAND_ID_HANDLER_EX(IDM_HELP_ABOUT, onHelpAbout)
		CHAIN_MSG_MAP(CUpdateUI<MainWindow>)
		CHAIN_MSG_MAP(CFrameWindowImpl<MainWindow>)
	END_MSG_MAP()

	MainWindow();
	~MainWindow();

	BOOL PreTranslateMessage(MSG* pMsg) override;
	BOOL OnIdle() override;

private:
	CanvasView		_view;

	int onCreate(LPCREATESTRUCT pCreateStruct);
	void onDestroy();
	LRESULT onEraseBkgnd(HDC hdc);

	void onFileRunAsAdmin(UINT, int, CWindow);
	void onFileExit(UINT, int, CWindow);
	void onHelpAbout(UINT, int, CWindow);
};
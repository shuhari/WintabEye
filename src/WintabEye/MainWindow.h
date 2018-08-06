#pragma once


#include "resource.h"


class MainWindow : public CWindowImpl<MainWindow, CWindow, CFrameWinTraits> {
public:
	DECLARE_WND_CLASS(_T("WintabEyeMainWindow"))

	BEGIN_MSG_MAP(MainWindow)
		MESSAGE_HANDLER(WM_DESTROY, onDestroy)
		COMMAND_ID_HANDLER(IDM_FILE_EXIT, onFileExit)
		COMMAND_ID_HANDLER(IDM_HELP_ABOUT, onHelpAbout)
	END_MSG_MAP()

	MainWindow();
	~MainWindow();

	BOOL Create();

private:
	LRESULT onDestroy(UINT, WPARAM, LPARAM, BOOL&);

	LRESULT onFileExit(WORD, WORD, HWND, BOOL&);
	LRESULT onHelpAbout(WORD, WORD, HWND, BOOL&);
};
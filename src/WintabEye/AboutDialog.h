#pragma once


#include "resource.h"


class AboutDialog : public CDialogImpl<AboutDialog>
{
public:
	AboutDialog();
	~AboutDialog();

	enum { IDD = IDD_ABOUT };

	BEGIN_MSG_MAP(AboutDialog)
		MESSAGE_HANDLER(WM_INITDIALOG, onInitDialog)
		MESSAGE_HANDLER(WM_CLOSE, onClose)
		COMMAND_ID_HANDLER(IDOK, onCancel)
		COMMAND_ID_HANDLER(IDCANCEL, onCancel)
	END_MSG_MAP()

private:
	LRESULT onInitDialog(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT onClose(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT onCancel(WORD, WORD, HWND, BOOL&);
};


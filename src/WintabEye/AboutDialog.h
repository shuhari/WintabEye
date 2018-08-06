#pragma once


#include "resource.h"


class AboutDialog : public CDialogImpl<AboutDialog>
{
public:
	AboutDialog();
	~AboutDialog();

	enum { IDD = IDD_ABOUT };

	BEGIN_MSG_MAP(AboutDialog)
		MSG_WM_INITDIALOG(onInitDialog)
		MSG_WM_CLOSE(onClose)
		COMMAND_ID_HANDLER_EX(IDOK, onCancel)
		COMMAND_ID_HANDLER_EX(IDCANCEL, onCancel)
	END_MSG_MAP()

private:
	BOOL onInitDialog(CWindow wnd, LPARAM lParam);
	void onClose();
	void onCancel(UINT, int, CWindow);
};


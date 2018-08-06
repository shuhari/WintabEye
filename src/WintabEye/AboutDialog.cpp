#include "stdafx.h"
#include "AboutDialog.h"


AboutDialog::AboutDialog() {
}


AboutDialog::~AboutDialog() {
}


LRESULT AboutDialog::onInitDialog(UINT, WPARAM, LPARAM, BOOL&) {
	CenterWindow();
	return TRUE;
}


LRESULT AboutDialog::onClose(UINT, WPARAM, LPARAM, BOOL&) {
	EndDialog(IDCANCEL);
	return 0;
}


LRESULT AboutDialog::onCancel(WORD wNotify, WORD wId, HWND hCtrl, BOOL& handled) {
	EndDialog(wId);
	return 0;
}


#include "stdafx.h"
#include "AboutDialog.h"


AboutDialog::AboutDialog() {
}


AboutDialog::~AboutDialog() {
}


BOOL AboutDialog::onInitDialog(CWindow wnd, LPARAM lParam) {
	CenterWindow();
	return TRUE;
}


void AboutDialog::onClose() {
	EndDialog(IDCANCEL);
}


void AboutDialog::onCancel(UINT wNotify, int nId, CWindow wnd) {
	EndDialog(nId);
}


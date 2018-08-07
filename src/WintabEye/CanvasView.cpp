#include "stdafx.h"
#include "CanvasView.h"


CanvasView::CanvasView()
{
}


CanvasView::~CanvasView()
{
}


BOOL CanvasView::PreTranslateMessage(MSG* pMsg) {
	return FALSE;
}


void CanvasView::onPaint(CDCHandle) {
	PAINTSTRUCT ps;
	CDCHandle dcPaint = BeginPaint(&ps);
	/*CRect rc;
	SYSTEMTIME st;
	CString sTime;

	GetClientRect(rc);
	GetLocalTime(&st);
	sTime.Format(L"The time is %d:%02d:%02d", st.wHour, st.wMinute, st.wSecond);
	dcPaint.SaveDC();
	dcPaint.SetBkColor(RGB(255, 153, 0));
	dcPaint.SetTextColor(RGB(0, 0, 0));
	dcPaint.ExtTextOut(0, 0, ETO_OPAQUE, rc, sTime, sTime.GetLength(), NULL);
	dcPaint.RestoreDC(-1);*/
	EndPaint(&ps);
}

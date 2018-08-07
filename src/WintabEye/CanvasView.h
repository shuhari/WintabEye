#pragma once


class CanvasView : public CWindowImpl<CanvasView>
{
public:
	DECLARE_WND_CLASS(L"WintabEye_CanvasView")

	BEGIN_MSG_MAP(CanvasView)
		MSG_WM_PAINT(onPaint)
	END_MSG_MAP()

	CanvasView();
	~CanvasView();

	BOOL PreTranslateMessage(MSG* pMsg);

private:
	void onPaint(CDCHandle dc);
};


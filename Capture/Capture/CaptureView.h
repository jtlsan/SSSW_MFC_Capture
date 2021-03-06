
// CaptureView.h : CCaptureView 클래스의 인터페이스
//

#pragma once
#include "CaptureBox.h"


class CCaptureView : public CView
{
protected: // serialization에서만 만들어집니다.
	CCaptureView();
	DECLARE_DYNCREATE(CCaptureView)

// 특성입니다.
public:
	CCaptureDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CCaptureView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	CCaptureBox m_dlgCapture;
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
//	afx_msg void OnMove(int x, int y);
//	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnCapture();
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // CaptureView.cpp의 디버그 버전
inline CCaptureDoc* CCaptureView::GetDocument() const
   { return reinterpret_cast<CCaptureDoc*>(m_pDocument); }
#endif


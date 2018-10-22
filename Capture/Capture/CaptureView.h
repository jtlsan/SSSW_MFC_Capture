
// CaptureView.h : CCaptureView Ŭ������ �������̽�
//

#pragma once
#include "CaptureBox.h"


class CCaptureView : public CView
{
protected: // serialization������ ��������ϴ�.
	CCaptureView();
	DECLARE_DYNCREATE(CCaptureView)

// Ư���Դϴ�.
public:
	CCaptureDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CCaptureView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
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
};

#ifndef _DEBUG  // CaptureView.cpp�� ����� ����
inline CCaptureDoc* CCaptureView::GetDocument() const
   { return reinterpret_cast<CCaptureDoc*>(m_pDocument); }
#endif


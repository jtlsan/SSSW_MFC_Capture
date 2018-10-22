
// CaptureView.cpp : CCaptureView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Capture.h"
#endif

#include "CaptureDoc.h"
#include "CaptureView.h"
#include "MainFrm.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCaptureView

IMPLEMENT_DYNCREATE(CCaptureView, CView)

BEGIN_MESSAGE_MAP(CCaptureView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_CREATE()
	ON_WM_ERASEBKGND()
//	ON_WM_MOVE()
//	ON_WM_SIZE()
ON_COMMAND(ID_CAPTURE, &CCaptureView::OnCapture)
END_MESSAGE_MAP()

// CCaptureView ����/�Ҹ�

CCaptureView::CCaptureView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CCaptureView::~CCaptureView()
{
}

BOOL CCaptureView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	//����ȭ
	

	return CView::PreCreateWindow(cs);
}

// CCaptureView �׸���

void CCaptureView::OnDraw(CDC* /*pDC*/)
{
	CCaptureDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CCaptureView �μ�

BOOL CCaptureView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CCaptureView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CCaptureView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CCaptureView ����

#ifdef _DEBUG
void CCaptureView::AssertValid() const
{
	CView::AssertValid();
}

void CCaptureView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCaptureDoc* CCaptureView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCaptureDoc)));
	return (CCaptureDoc*)m_pDocument;
}
#endif //_DEBUG


// CCaptureView �޽��� ó����


void CCaptureView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	

	/*
	CWnd* pWndDesktop = GetDesktopWindow();
	CWindowDC ScrDC(pWndDesktop);
	CClientDC dc(this);
	CRect Rect;
	GetClientRect(&Rect);
	CWnd::GetWindowRect(&Rect);
	CImage Image;
	int sx = Rect.left;
	int sy = Rect.top;
	int cx = Rect.Width();
	int cy = Rect.Height();
	Image.Create(cx, cy, ScrDC.GetDeviceCaps(BITSPIXEL));
	CDC* pDC = CDC::FromHandle(Image.GetDC())
	*/
	/*


	pDC->BitBlt(0, 0, cx, cy, &ScrDC, sx, sy, SRCCOPY);		//pDC->�ٲ�, &ScrDC�ٲ�
	Image.ReleaseDC();
	Image.Save(TEXT("Desktop.jpg"), Gdiplus::ImageFormatJPEG);
	::ShellExecute(NULL, TEXT("open"), TEXT("Desktop.jpg"), NULL, NULL, SW_SHOW);
	*/


	CDC memDC;
	CBitmap bitmap;

	
	int cx2, cy2;
	CRect rect;
	GetClientRect(&rect);
	CWnd::GetWindowRect(&rect);

	cx2 = GetSystemMetrics(SM_CXSCREEN);		//��ǻ���� �ػ� ũ��
	cy2 = GetSystemMetrics(SM_CYSCREEN);

	CClientDC dc(this);
	CClientDC ScreenDC(GetDesktopWindow());
	memDC.CreateCompatibleDC(&ScreenDC);
	bitmap.CreateCompatibleBitmap(&ScreenDC, cx2, cy2);
	CBitmap *pOldBitmap = memDC.SelectObject(&bitmap);
	memDC.StretchBlt(0, 0, cx2, cy2, &ScreenDC, 0, 0, cx2, cy2, SRCCOPY);

	dc.BitBlt(0, 0, rect.Width(), rect.Height(), &memDC, rect.left, rect.top, SRCCOPY);	

	memDC.SelectObject(pOldBitmap);
	

	CView::OnLButtonDblClk(nFlags, point);
}


int CCaptureView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	m_dlgCapture.Create(IDD_DIALOG_CAPTURE, this);
	m_dlgCapture.ShowWindow(SW_SHOW);


	//����ȭ �۾���

	return 0;
}


BOOL CCaptureView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	return false;
	//return CView::OnEraseBkgnd(pDC);
}


//void CCaptureView::OnMove(int x, int y)
//{
//	CView::OnMove(x, y);
//
//	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
//
//	RepaintView();
//}


//void CCaptureView::OnSize(UINT nType, int cx, int cy)
//{
//	CView::OnSize(nType, cx, cy);
//
//	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
//	RepaintView();
//}


void CCaptureView::OnCapture()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_dlgCapture.OnCapture();
}

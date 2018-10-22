
// CaptureView.cpp : CCaptureView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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
	// 표준 인쇄 명령입니다.
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

// CCaptureView 생성/소멸

CCaptureView::CCaptureView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CCaptureView::~CCaptureView()
{
}

BOOL CCaptureView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	//투명화
	

	return CView::PreCreateWindow(cs);
}

// CCaptureView 그리기

void CCaptureView::OnDraw(CDC* /*pDC*/)
{
	CCaptureDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CCaptureView 인쇄

BOOL CCaptureView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CCaptureView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CCaptureView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CCaptureView 진단

#ifdef _DEBUG
void CCaptureView::AssertValid() const
{
	CView::AssertValid();
}

void CCaptureView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCaptureDoc* CCaptureView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCaptureDoc)));
	return (CCaptureDoc*)m_pDocument;
}
#endif //_DEBUG


// CCaptureView 메시지 처리기


void CCaptureView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	

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


	pDC->BitBlt(0, 0, cx, cy, &ScrDC, sx, sy, SRCCOPY);		//pDC->바꿈, &ScrDC바꿈
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

	cx2 = GetSystemMetrics(SM_CXSCREEN);		//컴퓨터의 해상도 크기
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

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	m_dlgCapture.Create(IDD_DIALOG_CAPTURE, this);
	m_dlgCapture.ShowWindow(SW_SHOW);


	//투명화 작업중

	return 0;
}


BOOL CCaptureView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	return false;
	//return CView::OnEraseBkgnd(pDC);
}


//void CCaptureView::OnMove(int x, int y)
//{
//	CView::OnMove(x, y);
//
//	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
//
//	RepaintView();
//}


//void CCaptureView::OnSize(UINT nType, int cx, int cy)
//{
//	CView::OnSize(nType, cx, cy);
//
//	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
//	RepaintView();
//}


void CCaptureView::OnCapture()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_dlgCapture.OnCapture();
}

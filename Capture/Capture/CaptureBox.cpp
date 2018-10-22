// CaptureBox.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Capture.h"
#include "CaptureBox.h"
#include "afxdialogex.h"


// CCaptureBox 대화 상자입니다.

IMPLEMENT_DYNAMIC(CCaptureBox, CDialogEx)

CCaptureBox::CCaptureBox(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_CAPTURE, pParent)
{

}

CCaptureBox::~CCaptureBox()
{
}

void CCaptureBox::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCaptureBox, CDialogEx)
	ON_COMMAND(ID_CAPTURE, &CCaptureBox::OnCapture)
	ON_WM_KEYDOWN()
//	ON_COMMAND(ID_CAPTUREBOX, &CCaptureBox::OnCapturebox)
//ON_WM_CREATE()
END_MESSAGE_MAP()


// CCaptureBox 메시지 처리기입니다.


BOOL CCaptureBox::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	typedef BOOL(WINAPI *SLWA)(HWND, COLORREF, BYTE, DWORD);
	SLWA pSetLayeredWindowAttributes = NULL;
	HINSTANCE hmodUSER32 = LoadLibrary(_T("USER32.DLL"));

	pSetLayeredWindowAttributes = (SLWA)GetProcAddress(hmodUSER32, "SetLayeredWindowAttributes");

	HWND hwnd = this->m_hWnd;
	SetWindowLong(hwnd, GWL_EXSTYLE, GetWindowLong(hwnd, GWL_EXSTYLE) | WS_EX_LAYERED);
	BYTE byAlpha = 70;
	COLORREF cr = GetSysColor(COLOR_BTNFACE);
	SetLayeredWindowAttributes(cr, byAlpha, LWA_COLORKEY);

	m_hAccel = ::LoadAccelerators(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_MAINFRAME));

	/*
	LONG ExtendedStyle = GetWindowLong(GetSafeHwnd(), GWL_EXSTYLE);
	SetWindowLong(GetSafeHwnd(), GWL_EXSTYLE, ExtendedStyle | WS_EX_LAYERED);

	BYTE byAlphaValue = 128;
	::SetLayeredWindowAttributes(GetSafeHwnd(), 0, byAlphaValue, LWA_ALPHA);
	*/
	//SetWindowLong(this->GetSafeHwnd(), GWL_EXSTYLE, GetWindowLong(this->GetSafeHwnd(), GWL_EXSTYLE) | WS_EX_LAYERED);

	return FALSE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CCaptureBox::OnCapture()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CDC memDC;
	CBitmap bitmap;
	CImage imgae;

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

	dc.BitBlt(-8, -31, rect.Width(), rect.Height(), &memDC, rect.left, rect.top, SRCCOPY);

	memDC.SelectObject(pOldBitmap);

}


void CCaptureBox::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}


BOOL CCaptureBox::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (::TranslateAccelerator(this->m_hWnd, m_hAccel, pMsg))
		return TRUE;

	return CDialogEx::PreTranslateMessage(pMsg);
}


//void CCaptureBox::OnCapturebox()
//{
//	// TODO: 여기에 명령 처리기 코드를 추가합니다.
//	CDC memDC;
//	CBitmap bitmap;
//
//
//	int cx2, cy2;
//	CRect rect;
//	GetClientRect(&rect);
//	CWnd::GetWindowRect(&rect);
//
//	cx2 = GetSystemMetrics(SM_CXSCREEN);		//컴퓨터의 해상도 크기
//	cy2 = GetSystemMetrics(SM_CYSCREEN);
//
//	CClientDC dc(this);
//	CClientDC ScreenDC(GetDesktopWindow());
//	memDC.CreateCompatibleDC(&ScreenDC);
//	bitmap.CreateCompatibleBitmap(&ScreenDC, cx2, cy2);
//	CBitmap *pOldBitmap = memDC.SelectObject(&bitmap);
//	memDC.StretchBlt(0, 0, cx2, cy2, &ScreenDC, 0, 0, cx2, cy2, SRCCOPY);
//
//	dc.BitBlt(0, 0, rect.Width(), rect.Height(), &memDC, rect.left, rect.top, SRCCOPY);
//
//}


//int CCaptureBox::OnCreate(LPCREATESTRUCT lpCreateStruct)
//{
//	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
//		return -1;
//
//	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
//
//	return 0;
//}

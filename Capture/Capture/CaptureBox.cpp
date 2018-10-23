// CaptureBox.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Capture.h"
#include "CaptureBox.h"
#include "afxdialogex.h"


// CCaptureBox ��ȭ �����Դϴ�.

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


// CCaptureBox �޽��� ó�����Դϴ�.


BOOL CCaptureBox::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

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
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CCaptureBox::OnCapture()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CDC memDC;
	CBitmap bitmap;
	CImage image;

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

	//image�����õ�
	image.Create(rect.Width() - 15, rect.Height() - 38, memDC.GetDeviceCaps(BITSPIXEL));
	CDC* pDC = dc.FromHandle(image.GetDC());

	dc.BitBlt(-8, -31, rect.Width(), rect.Height(), &memDC, rect.left, rect.top, SRCCOPY);
	pDC->BitBlt(-8, -31, rect.Width()-2, rect.Height()-2, &memDC, rect.left, rect.top, SRCCOPY);
	image.ReleaseDC();

	image.Save(TEXT("test2.jpg"), Gdiplus::ImageFormatJPEG);

	memDC.SelectObject(pOldBitmap);

}


void CCaptureBox::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}


BOOL CCaptureBox::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (::TranslateAccelerator(this->m_hWnd, m_hAccel, pMsg))
		return TRUE;

	return CDialogEx::PreTranslateMessage(pMsg);
}


//void CCaptureBox::OnCapturebox()
//{
//	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
//	CDC memDC;
//	CBitmap bitmap;
//
//
//	int cx2, cy2;
//	CRect rect;
//	GetClientRect(&rect);
//	CWnd::GetWindowRect(&rect);
//
//	cx2 = GetSystemMetrics(SM_CXSCREEN);		//��ǻ���� �ػ� ũ��
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
//	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
//
//	return 0;
//}

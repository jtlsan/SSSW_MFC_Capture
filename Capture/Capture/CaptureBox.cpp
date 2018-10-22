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
END_MESSAGE_MAP()


// CCaptureBox 메시지 처리기입니다.


BOOL CCaptureBox::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	LONG ExtendedStyle = GetWindowLong(GetSafeHwnd(), GWL_EXSTYLE);
	SetWindowLong(GetSafeHwnd(), GWL_EXSTYLE, ExtendedStyle | WS_EX_LAYERED);

	BYTE byAlphaValue = 128;
	::SetLayeredWindowAttributes(GetSafeHwnd(), 0, byAlphaValue, LWA_ALPHA);
	//SetWindowLong(this->GetSafeHwnd(), GWL_EXSTYLE, GetWindowLong(this->GetSafeHwnd(), GWL_EXSTYLE) | WS_EX_LAYERED);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

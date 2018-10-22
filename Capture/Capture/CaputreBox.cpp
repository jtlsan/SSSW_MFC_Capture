// CaputreBox.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Capture.h"
#include "CaputreBox.h"
#include "afxdialogex.h"


// CCaputreBox 대화 상자입니다.

IMPLEMENT_DYNAMIC(ff, CDialogEx)

ff::ff(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

ff::~ff()
{
}

void ff::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ff, CDialogEx)
END_MESSAGE_MAP()


// CCaputreBox 메시지 처리기입니다.


BOOL ff::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	SetWindowLong(this->GetSafeHwnd(), GWL_EXSTYLE, GetWindowLong(this->GetSafeHwnd(), GWL_EXSTYLE) | WS_EX_LAYERED);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

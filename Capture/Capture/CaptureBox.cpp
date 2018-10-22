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
END_MESSAGE_MAP()


// CCaptureBox �޽��� ó�����Դϴ�.


BOOL CCaptureBox::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	LONG ExtendedStyle = GetWindowLong(GetSafeHwnd(), GWL_EXSTYLE);
	SetWindowLong(GetSafeHwnd(), GWL_EXSTYLE, ExtendedStyle | WS_EX_LAYERED);

	BYTE byAlphaValue = 128;
	::SetLayeredWindowAttributes(GetSafeHwnd(), 0, byAlphaValue, LWA_ALPHA);
	//SetWindowLong(this->GetSafeHwnd(), GWL_EXSTYLE, GetWindowLong(this->GetSafeHwnd(), GWL_EXSTYLE) | WS_EX_LAYERED);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

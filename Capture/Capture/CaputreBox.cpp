// CaputreBox.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Capture.h"
#include "CaputreBox.h"
#include "afxdialogex.h"


// CCaputreBox ��ȭ �����Դϴ�.

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


// CCaputreBox �޽��� ó�����Դϴ�.


BOOL ff::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	SetWindowLong(this->GetSafeHwnd(), GWL_EXSTYLE, GetWindowLong(this->GetSafeHwnd(), GWL_EXSTYLE) | WS_EX_LAYERED);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

#pragma once


// CCaputreBox ��ȭ �����Դϴ�.

class ff : public CDialogEx
{
	DECLARE_DYNAMIC(ff)

public:
	ff(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~ff();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};

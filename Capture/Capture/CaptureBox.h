#pragma once


// CCaptureBox ��ȭ �����Դϴ�.



class CCaptureBox : public CDialogEx
{
	DECLARE_DYNAMIC(CCaptureBox)

public:
	CCaptureBox(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CCaptureBox();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CAPTURE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnCapture();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	HACCEL m_hAccel;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
//	afx_msg void OnCapturebox();
};

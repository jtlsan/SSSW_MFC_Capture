#pragma once


// CCaptureBox 대화 상자입니다.



class CCaptureBox : public CDialogEx
{
	DECLARE_DYNAMIC(CCaptureBox)

public:
	CCaptureBox(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CCaptureBox();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CAPTURE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnCapture();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	HACCEL m_hAccel;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
//	afx_msg void OnCapturebox();
//	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

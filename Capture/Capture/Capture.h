
// Capture.h : Capture ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CCaptureApp:
// �� Ŭ������ ������ ���ؼ��� Capture.cpp�� �����Ͻʽÿ�.
//

class CCaptureApp : public CWinAppEx
{
public:
	CCaptureApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCaptureApp theApp;

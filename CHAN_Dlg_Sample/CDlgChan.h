#pragma once
#include "afxdialogex.h"


// CDlgChan 대화 상자

class CDlgChan : public CDialog
{
	DECLARE_DYNAMIC(CDlgChan)

public:
	CDlgChan(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgChan();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHAN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strName;
	CString m_strPwd;
	afx_msg void OnBnClickedOk();
	int m_nAge;
	CString m_strTest =_T("This is Test");
	virtual BOOL OnInitDialog();
	afx_msg void OnEnSetfocusName();
	afx_msg void OnEnKillfocusName();
};

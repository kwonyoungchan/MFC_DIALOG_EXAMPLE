// CDlgChan.cpp: 구현 파일
//

#include "pch.h"
#include "CHAN_Dlg_Sample.h"
#include "afxdialogex.h"
#include "CDlgChan.h"



// CDlgChan 대화 상자

IMPLEMENT_DYNAMIC(CDlgChan, CDialog)

CDlgChan::CDlgChan(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CHAN, pParent)
	, m_strName(_T(""))
	, m_strPwd(_T(""))
	, m_nAge(0)

{

}

CDlgChan::~CDlgChan()
{
}

void CDlgChan::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NAME, m_strName);
	DDV_MaxChars(pDX, m_strName, 10);
	DDX_Text(pDX, IDC_PASSWORD, m_strPwd);
	DDX_Text(pDX, IDC_AGE, m_nAge);
	DDV_MinMaxInt(pDX, m_nAge, 0, 999);
	DDX_Text(pDX, IDC_READONLY, m_strTest);
}


BEGIN_MESSAGE_MAP(CDlgChan, CDialog)
	ON_BN_CLICKED(IDOK, &CDlgChan::OnBnClickedOk)
	ON_EN_SETFOCUS(IDC_NAME, &CDlgChan::OnEnSetfocusName)
	ON_EN_KILLFOCUS(IDC_NAME, &CDlgChan::OnEnKillfocusName)
END_MESSAGE_MAP()


// CDlgChan 메시지 처리기


void CDlgChan::OnBnClickedOk()
{
	UpdateData();
	CDialog::OnOK();
}


BOOL CDlgChan::OnInitDialog()
{
	CDialog::OnInitDialog();

	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDlgChan::OnEnSetfocusName()
{
	m_strName = _T("이름을 입력해 주셔유~");
	UpdateData(FALSE);
}





void CDlgChan::OnEnKillfocusName()
{
	m_strName = _T("");
	UpdateData(FALSE);
}

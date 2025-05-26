// CDlgML.cpp: 구현 파일
//

#include "pch.h"
#include "CHAN_Dlg_Sample.h"
#include "afxdialogex.h"
#include "CDlgML.h"


// CDlgML 대화 상자

IMPLEMENT_DYNAMIC(CDlgML, CDialog)

CDlgML::CDlgML(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_MODALESS, pParent)
{

}

CDlgML::~CDlgML()
{
}

void CDlgML::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgML, CDialog)
END_MESSAGE_MAP()


// CDlgML 메시지 처리기



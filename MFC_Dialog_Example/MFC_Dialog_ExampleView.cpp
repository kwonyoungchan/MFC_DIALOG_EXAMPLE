﻿
// MFC_Dialog_ExampleView.cpp: CMFCDialogExampleView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFC_Dialog_Example.h"
#endif

#include "MFC_Dialog_ExampleDoc.h"
#include "MFC_Dialog_ExampleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCDialogExampleView

IMPLEMENT_DYNCREATE(CMFCDialogExampleView, CView)

BEGIN_MESSAGE_MAP(CMFCDialogExampleView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_TEST_TESTTEST, &CMFCDialogExampleView::OnTestTesttest)
	ON_WM_LBUTTONUP()
	ON_WM_CREATE()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// CMFCDialogExampleView 생성/소멸

CMFCDialogExampleView::CMFCDialogExampleView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMFCDialogExampleView::~CMFCDialogExampleView()
{
}

BOOL CMFCDialogExampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMFCDialogExampleView 그리기

void CMFCDialogExampleView::OnDraw(CDC* /*pDC*/)
{
	CMFCDialogExampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMFCDialogExampleView 인쇄

BOOL CMFCDialogExampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMFCDialogExampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMFCDialogExampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMFCDialogExampleView 진단

#ifdef _DEBUG
void CMFCDialogExampleView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCDialogExampleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCDialogExampleDoc* CMFCDialogExampleView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCDialogExampleDoc)));
	return (CMFCDialogExampleDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCDialogExampleView 메시지 처리기


void CMFCDialogExampleView::OnPaint()
{
	CPaintDC dc(this);
	if (m_bHover)
	{
		dc.SetTextColor(RGB(255, 255, 255));
		dc.FillSolidRect(&m_btn, RGB(192, 0, 0));

	}
	else
	{
		dc.SetTextColor(RGB(0, 0, 0));
		dc.FillSolidRect(&m_btn, RGB(192, 192, 192));
	}

	dc.DrawText(_T("TEST BTN"),&m_btn,
		DT_CENTER | DT_SINGLELINE|DT_VCENTER);


}


void CMFCDialogExampleView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_btn.PtInRect(point))
	{
		m_bHover = TRUE;
	}
	else
	{
		m_bHover = FALSE;
	}
	RedrawWindow();

	CView::OnMouseMove(nFlags, point);
}





void CMFCDialogExampleView::OnTestTesttest()
{
	AfxMessageBox(_T("와우"));
}


void CMFCDialogExampleView::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (m_btn.PtInRect(point))
	{
		this->PostMessage(WM_COMMAND, ID_TEST_TESTTEST);
	}
	CView::OnLButtonUp(nFlags, point);
}


int CMFCDialogExampleView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	BOOL result =m_wndName.Create(
		ES_LEFT | ES_MULTILINE | WS_CHILD | WS_TABSTOP,
		CRect(100, 100, 100, 40),this,1);
	

	return 0;
}


BOOL CMFCDialogExampleView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	return TRUE;
}

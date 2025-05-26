
// MFC_Dialog_ExampleView.h: CMFCDialogExampleView 클래스의 인터페이스
//

#pragma once


class CMFCDialogExampleView : public CView
{
protected: // serialization에서만 만들어집니다.
	CMFCDialogExampleView() noexcept;
	DECLARE_DYNCREATE(CMFCDialogExampleView)

// 특성입니다.
public:
	CMFCDialogExampleDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMFCDialogExampleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CRect m_btn = CRect(100, 100, 220, 150);
	BOOL m_bHover = false;

	CEdit m_wndName;
// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnTestTesttest();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

#ifndef _DEBUG  // MFC_Dialog_ExampleView.cpp의 디버그 버전
inline CMFCDialogExampleDoc* CMFCDialogExampleView::GetDocument() const
   { return reinterpret_cast<CMFCDialogExampleDoc*>(m_pDocument); }
#endif


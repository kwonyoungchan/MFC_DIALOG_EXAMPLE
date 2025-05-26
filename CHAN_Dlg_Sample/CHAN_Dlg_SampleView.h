
// CHAN_Dlg_SampleView.h: CCHANDlgSampleView 클래스의 인터페이스
//

#pragma once


class CCHANDlgSampleView : public CView
{
protected: // serialization에서만 만들어집니다.
	CCHANDlgSampleView() noexcept;
	DECLARE_DYNCREATE(CCHANDlgSampleView)

// 특성입니다.
public:
	CCHANDlgSampleDoc* GetDocument() const;

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
	virtual ~CCHANDlgSampleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTestTesttest();
	afx_msg void OnTestModaless();
};

#ifndef _DEBUG  // CHAN_Dlg_SampleView.cpp의 디버그 버전
inline CCHANDlgSampleDoc* CCHANDlgSampleView::GetDocument() const
   { return reinterpret_cast<CCHANDlgSampleDoc*>(m_pDocument); }
#endif



// NorvelEditView.h : CNorvelEditView 类的接口
//

#pragma once
#include "MainFrm.h"
#include "NorvelEditDoc.h"

class CNorvelEditView : public CRichEditView
{
protected: // 仅从序列化创建
	CNorvelEditView();
	DECLARE_DYNCREATE(CNorvelEditView)

// 特性
public:
	CNorvelEditDoc* GetDocument() const;

// 操作
public:
	bool			m_bChange;
	CFont			m_Font;
// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	void		 DisplayTextByTitle(CString strTitle);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CNorvelEditView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMenuFontSet();
	afx_msg void OnEditCut();
	afx_msg void OnEditCopy();
	afx_msg void OnEditPaste();
	afx_msg void OnEditSelectAll();
	afx_msg void OnPopMenuFirstID(UINT id);
	afx_msg void OnFileSave();
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // NorvelEditView.cpp 中的调试版本
inline CNorvelEditDoc* CNorvelEditView::GetDocument() const
   { return reinterpret_cast<CNorvelEditDoc*>(m_pDocument); }
#endif


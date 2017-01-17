
#pragma once
#include "DlgPanel.h"
/////////////////////////////////////////////////////////////////////////////
// COutputList 窗口

class COutputList : public CListBox
{
// 构造
	
public:
	COutputList();

// 实现
public:
	virtual ~COutputList();

protected:
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnEditCopy();
	afx_msg void OnEditClear();
	afx_msg void OnViewOutput();

	DECLARE_MESSAGE_MAP()
};

class COutputWnd : public CDockablePane
{
// 构造

public:
	COutputWnd();

	void UpdateFonts();

// 特性
protected:
	CMFCTabCtrl	m_wndTabs;

	//COutputList m_wndOutputBuild;
	CDlgPanel	m_wndOutputDebug;
	//COutputList m_wndOutputFind;

protected:
	void FillBuildWindow();
	void FillFindWindow();

	void AdjustHorzScroll(CListBox& wndListBox);

// 实现
public:
	virtual ~COutputWnd();

	void	SetScene();
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);

	DECLARE_MESSAGE_MAP()
};



#pragma once

#include "ViewTree.h"

class CFileViewToolBar : public CMFCToolBar
{
	virtual void OnUpdateCmdUI(CFrameWnd* /*pTarget*/, BOOL bDisableIfNoHndler)
	{
		CMFCToolBar::OnUpdateCmdUI((CFrameWnd*) GetOwner(), bDisableIfNoHndler);
	}

	virtual BOOL AllowShowOnList() const { return FALSE; }
};

class CRoleNameView : public CDockablePane
{
// 构造
public:
	CRoleNameView();

	void AdjustLayout();
	void OnChangeVisualStyle();
	void AddNameItem(CString strName);
	void ReadDataFromFile();
// 特性
protected:

	CListBox m_wndNameList;
	CFileViewToolBar m_wndToolBar;

protected:
	void FillFileView();

// 实现
public:
	virtual ~CRoleNameView();

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnProperties();

	afx_msg void OnPaint();
	afx_msg void OnSetFocus(CWnd* pOldWnd);

	afx_msg void OnClickList();
	DECLARE_MESSAGE_MAP()
};


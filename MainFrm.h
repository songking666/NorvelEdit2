
// MainFrm.h : CMainFrame 类的接口
//

#pragma once
#include "RoleNameView.h"
#include "CapterView.h"
#include "OutputWnd.h"
#include "FormatBar.h"

class CMainFrame : public CFrameWndEx
{
	
protected: // 仅从序列化创建
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 特性
public:
	CMFCToolBarComboBoxButton  *m_comboFont;
	CMFCToolBarComboBoxButton  *m_comboFontSize;
// 操作
public:
	
// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL LoadFrame(UINT nIDResource, DWORD dwDefaultStyle = WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, CWnd* pParentWnd = NULL, CCreateContext* pContext = NULL);

// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 控件条嵌入成员
	CMFCMenuBar       m_wndMenuBar;
	CMFCToolBar       m_wndToolBar;
	CMFCToolBar		  m_wndFormatBar;
	CMFCStatusBar     m_wndStatusBar;
	CMFCToolBarImages m_UserImages;
	CRoleNameView         m_wndRoleNameView;
	CCapterView        m_wndCapterView;
	COutputWnd        m_wndOutput;

	CMFCCaptionBar    m_wndCaptionBar;
	
// 生成的消息映射函数
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnViewCustomize();
	afx_msg LRESULT OnToolbarCreateNew(WPARAM wp, LPARAM lp);
	afx_msg void OnApplicationLook(UINT id);
	afx_msg void OnUpdateApplicationLook(CCmdUI* pCmdUI);
	afx_msg void OnSettingChange(UINT uFlags, LPCTSTR lpszSection);
	afx_msg LRESULT OnToolbarReset(WPARAM,LPARAM);

	afx_msg void OnFontNameSelChangeClick();
	afx_msg void OnFontNameClickComboBox();

	afx_msg void OnFontSizeSelChangeClick();
	afx_msg void OnFontSizeClickComboBox();

	afx_msg LRESULT OnTreeViewSelectChange(WPARAM wparam,LPARAM lparam);
	afx_msg LRESULT OnMsgReadFile(WPARAM wparam,LPARAM lparam);
	DECLARE_MESSAGE_MAP()

	BOOL CreateDockingWindows();
	void SetDockingWindowIcons(BOOL bHiColorIcons);
public:
	void SetBookName(CString strBookName);
	static int CALLBACK EnumFontFamProc(ENUMLOGFONT *lpelf, 
		NEWTEXTMETRIC *lpntm,
		int nFontType,
		LPARAM lParam);

public:
	afx_msg void OnMenuGetName();
	afx_msg void OnMenuAddress();
	afx_msg void OnMenuDatabaseNameEdit();
	afx_msg void OnMenuPlaceName();
	afx_msg void OnMenuSence();
	afx_msg void OnMenuPeople();
	afx_msg void OnMenuTotel();
	afx_msg void OnMenuCommWord();
	BOOL CreateCaptionBar();
	afx_msg void OnMenuMapEdit();
};



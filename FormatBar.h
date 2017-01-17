#if !defined(AFX_FORMATBAR_H__76705223_1E1F_11D1_830C_5CB0BB000000__INCLUDED_)
#define AFX_FORMATBAR_H__76705223_1E1F_11D1_830C_5CB0BB000000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// FormatBar.h : header file
//
#include "Resource.h"
//#include "SA3DToolBar.h"
//#include "FlatComboBox.h"
/////////////////////////////////////////////////////////////////////////////
// CFormatBar window

struct CHARNMHDR : public NMHDR
{
	CHARFORMAT cf;
	CHARNMHDR() {cf.cbSize = sizeof(CHARFORMAT);}
};

// Define format notifications constant
#define FN_SETFORMAT	0x1000
#define FN_GETFORMAT	0x1001


class CFormatBar : public CMFCToolBar
{
// Construction
public:
	enum { IDD = IDR_TOOLBAR_FONT };
	CFormatBar(UINT nID = IDD );

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFormatBar)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFormatBar();

protected:
	void FillFontName( CDC *pDC );
	virtual void OnUpdateCmdUI(CFrameWnd* pTarget, BOOL bDisableIfNoHndler);


protected:
	//CComboBox	m_cmbFontName;
	
	CMFCToolBarComboBoxButton  m_cmbFontName;
	CMFCToolBarComboBoxButton	m_cmbFontSize;

	// Generated message map functions
protected:
	afx_msg void OnSelectFontName();
	afx_msg void OnSelectFontSize();

	//{{AFX_MSG(CFormatBar)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

private:
	UINT nToolbarID;
	static int CALLBACK EnumFontFamProc(ENUMLOGFONT *lpelf, 
					NEWTEXTMETRIC *lpntm,
					int nFontType,
					LPARAM lParam);

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FORMATBAR_H__76705223_1E1F_11D1_830C_5CB0BB000000__INCLUDED_)

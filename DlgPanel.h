#pragma once
#include "Resource.h"

// CDlgPanel dialog
typedef struct tag_DrawRect
{
	int		nTrueID;
	CString strText;
	CRect	rcDraw;
	bool	bSelect;
}StructDrawRect;

class CDlgPanel : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgPanel)

public:
	CDlgPanel(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgPanel();

// Dialog Data
	enum { IDD = IDD_DIALOG_PANEL };
private:
	vector<StructDrawRect> m_vectorScene;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	void	UnSelectAll();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	void	SetSceneList();
};

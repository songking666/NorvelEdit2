#pragma once
#include "afxwin.h"
#include "DatabaseTableTheme.h"
#include "DatabaseTableDecade.h"

// CDlgStep1 dialog

class CDlgStep1 : public CPropertyPage
{
	DECLARE_DYNAMIC(CDlgStep1)

public:
	CDlgStep1();
	virtual ~CDlgStep1();

// Dialog Data
	enum { IDD = IDD_DIALOG_STEP1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	CString			m_strBookName;
	int				m_nDecadeType;
	int				m_nThemeType;

	CEdit			m_edtBookName;
	CComboBox		m_comboTheme;
	CComboBox		m_combDecade;
	CStatic			m_staticTheme;
	CStatic			m_staticDecade;
	vectorBase		m_vectorTheme;
	vectorBase		m_vectorDecade;
	CComboBox		m_combMark;
	DECLARE_MESSAGE_MAP()
public:
	int		GetDecade();
	int		GetTheme();

	virtual BOOL OnSetActive();

	CString GetBookName();
	
	virtual LRESULT OnWizardNext();
	virtual BOOL OnInitDialog();
	
	afx_msg void OnCbnSelchangeComboTheme();

	
	afx_msg void OnCbnSelchangeComboDecade();
	afx_msg void OnBnClickedButtonRandom();
	
};

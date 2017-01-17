#pragma once
#include "afxwin.h"
#include "DataBaseTableFirstName.h"
#include "DatabaseTableLastName.h"


// CDlgGetName dialog

class CDlgGetName : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgGetName)

public:
	CDlgGetName(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgGetName();

// Dialog Data
	enum { IDD = IDD_DIALOG_GET_NAME };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int m_nFirstName;
	int m_nSex;
	CEdit m_edtFirstname;
	CDataBaseTableFirstName		m_tableFirstname;
	CDatabaseTableLastName		m_tableLastName;
	CString m_strRetName;
	afx_msg void OnBnClickedRadioFirstname1();
	afx_msg void OnBnClickedRadioFirstname2();
	afx_msg void OnBnClickedRadioFirstname3();
	afx_msg void OnBnClickedRadioSexGirl();
	afx_msg void OnBnClickedRadioSexBoy();
	afx_msg void OnBnClickedRadioSexMid();
	afx_msg void OnBnClickedButtonCreate();
	CListBox m_lsName;
	afx_msg void OnBnClickedOk();

	CString GetName();
	int		GetSex();
	virtual BOOL OnInitDialog();
	int m_nCountry;
};

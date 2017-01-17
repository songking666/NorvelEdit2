#pragma once
#include "DatabaseTableGeography.h"
#include "afxwin.h"


// CDlgAddress dialog

class CDlgAddress : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgAddress)

public:
	CDlgAddress(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgAddress();

	CString GetAddrName();
// Dialog Data
	enum { IDD = IDD_DIALOG_ADDRESS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	CDatabaseTableGeography m_TableGeo;
	DECLARE_MESSAGE_MAP()
public:
	CString m_strRet;
	CEdit m_edtSpecial;
	afx_msg void OnBnClickedButton1();
	CListBox m_lsAddr;
	int m_nTarName;
	afx_msg void OnBnClickedRadioRandom();
	afx_msg void OnBnClickedRadioTarget();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};

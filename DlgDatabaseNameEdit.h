#pragma once
#include "afxwin.h"
#include "DataBaseTableFirstName.h"
#include "DatabaseTableLastName.h"

// CDlgDatabaseNameEdit dialog

class CDlgDatabaseNameEdit : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgDatabaseNameEdit)

public:
	CDlgDatabaseNameEdit(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgDatabaseNameEdit();

// Dialog Data
	enum { IDD = IDD_DIALOG_DATABASE_NAME_EDIT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	CDataBaseTableFirstName	m_tableFirstName;
	CDatabaseTableLastName	m_tableLastName;

	CEdit m_edtFirstName;
	CEdit m_edtLastName;

	int m_nFirstNameType;
	int m_nLastNameType;
	int m_nSex;

	
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonFirstName();
	virtual BOOL OnInitDialog();
	
	afx_msg void OnBnClickedButtonLastName();
	afx_msg void OnBnClickedButtonFirstNameImport();
	afx_msg void OnBnClickedButtonLastNameImport();

	void InsertNewFirstName(CString strFirstName);
	void InsertNewLastName(CString strLastName);
	afx_msg void OnBnClickedRadioFirstNameChina();
	afx_msg void OnBnClickedRadioFirstNameEng();
	afx_msg void OnBnClickedRadioFirstNameJan();
	afx_msg void OnBnClickedRadioLastNameCha();
	afx_msg void OnBnClickedRadioLastNameEng();
	afx_msg void OnBnClickedRadioLastNameJan();
	afx_msg void OnBnClickedRadioBoy();
	afx_msg void OnBnClickedRadioGirl();
	afx_msg void OnBnClickedRadioSexMid();
	afx_msg void OnBnClickedOk();
};

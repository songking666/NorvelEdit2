#pragma once
#include "afxwin.h"
#include "DatabaseTableCommonWord.h"


// CDlgDatabaseEditCommWord dialog

class CDlgDatabaseEditCommWord : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgDatabaseEditCommWord)

public:
	CDlgDatabaseEditCommWord(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgDatabaseEditCommWord();

// Dialog Data
	enum { IDD = IDD_DIALOG_DATABASE_WORD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edtWord;
	CDatabaseTableCommonWord m_tableWord;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButtonImport();
	void InsertCommWord(WCHAR OneWord);
};

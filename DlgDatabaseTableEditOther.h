#pragma once
#include "afxwin.h"


// CDlgDatabaseTableEditOther 对话框

class CDlgDatabaseTableEditOther : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgDatabaseTableEditOther)

public:
	CDlgDatabaseTableEditOther(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgDatabaseTableEditOther();

// 对话框数据
	enum { IDD = IDD_DIALOG_DATABASETABLE_TOTLE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_combTableName;
	CEdit m_edtKeyWord;
	CEdit m_edtContent;
	CListBox m_lsKeyWord;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnCbnSelchangeComboTable();
};

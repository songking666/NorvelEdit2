#pragma once
#include "afxwin.h"
#include "DatabaseTableWeather.h"
#include "DatabaseTableGeography.h"
// CDlgDatabaseWeather 对话框

class CDlgDatabaseWeather : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgDatabaseWeather)

public:
	CDlgDatabaseWeather(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgDatabaseWeather();

// 对话框数据
	enum { IDD = IDD_DIALOG_DATABASE_WEATHER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_listWeather;
	CListBox m_listGeo;
	CEdit m_edtWeather;
	CEdit m_edtGeo;
	CEdit m_edtContentWeather;
	CEdit m_edtContentGeo;

	CDatabaseTableWeather tableWeather;
	CDatabaseTableGeography tableGeo;

	VectorWeather		m_vectorWeather;
	VectorGeography		m_vectorGeography;

	afx_msg void OnBnClickedButtonWeather();
	afx_msg void OnBnClickedButtonDecade();
	virtual BOOL OnInitDialog();
};

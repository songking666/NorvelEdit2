#pragma once
#include "afxwin.h"
#include "SaveFormat.h"


// CDlgStep3 dialog

class CDlgStep3 : public CPropertyPage
{
	DECLARE_DYNAMIC(CDlgStep3)

public:
	CDlgStep3();   // standard constructor
	virtual ~CDlgStep3();

// Dialog Data
	enum { IDD = IDD_DIALOG_STEP3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
	afx_msg void OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult);
	CEdit m_edtTimeLen;
	CEdit m_edtSceneName;
	CComboBox m_combSceneType;
	CComboBox m_combAddr;
	CComboBox m_combTimeSegment;
	CComboBox m_combWeather;
	CComboBox m_combTimeUnit;

	SceneFormat		m_SceneFormat;
	afx_msg void OnBnClickedButtonCreateAddr();
	virtual BOOL OnInitDialog();
	virtual BOOL OnWizardFinish();
	SceneFormat		GetSceneData();
};

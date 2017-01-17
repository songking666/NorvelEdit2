#pragma once
#include "afxwin.h"
#include "SaveFormat.h"


// CDlgStep2 dialog

class CDlgStep2 : public CPropertyPage
{
	DECLARE_DYNAMIC(CDlgStep2)

public:
	CDlgStep2();
	virtual ~CDlgStep2();

// Dialog Data
	enum { IDD = IDD_DIALOG_STEP2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonAutoCreate();
	CEdit m_edtName;
	CEdit m_edtHowOld;
	CComboBox m_combProfession;
	// 0Ϊ�У�1ΪŮ
	CEdit m_edtContent;
	RoleProperties	m_roleProperties;

	afx_msg void OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedRadioBoy();
	afx_msg void OnBnClickedRadioGirl();
	virtual BOOL OnSetActive();
	int m_nSex;
	virtual LRESULT OnWizardNext();

	RoleProperties	GetRoleProper();
};

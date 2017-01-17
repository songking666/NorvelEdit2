#pragma once
#include "afxwin.h"
#include "afxdtctl.h"
#include "SaveFormat.h"


// CDlgRoleDesign dialog

class CDlgRoleDesign : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgRoleDesign)

public:
	CDlgRoleDesign(CWnd* pParent = NULL);   // standard constructor
	CDlgRoleDesign(int bModifyID = -1,CWnd* pParent = NULL);
	virtual ~CDlgRoleDesign();

// Dialog Data
	enum { IDD = IDD_DIALOG_ROLE_DESIGN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	bool	m_bModify;
	int		m_iModifyID;
	int m_nSex;
	CEdit m_edtName;
	CDateTimeCtrl m_brigthday;
	CComboBox m_combProfession;
	CComboBox m_combStartCapter;
	CEdit m_edtExplan;
	CEdit m_edtHowOld;
	CEdit m_edtConvertData;
	CComboBox m_combCloth;
	CComboBox m_combCharacter;
	CComboBox m_combRelationship;
	CEdit m_edtTheEnd;
	vector<CString> m_vectorCapter;

	RoleProperties	m_RoleProperties;

	RoleProperties GetRoleData();
	afx_msg void OnBnClickedButtonAutoName();
	afx_msg void OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult);
	
	virtual BOOL OnInitDialog();
	
	afx_msg void OnBnClickedButtonConvert();



	afx_msg void OnBnClickedOk();

	void SaveNewRoleToFile();

	void ReadDataFromDlgCtrl( RoleProperties &Temp_role ) ;


	afx_msg void OnBnClickedRadioBoy();
	afx_msg void OnBnClickedRadioGirl();
	
};

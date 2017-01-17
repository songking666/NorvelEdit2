// DlgStep2.cpp : implementation file
//

#include "stdafx.h"
#include "NorvelEdit.h"
#include "DlgStep2.h"
#include "afxdialogex.h"
#include "DlgDatabaseNameEdit.h"
#include "DlgGetName.h"
#include "DatabaseTableProfession.h"


// CDlgStep2 dialog

IMPLEMENT_DYNAMIC(CDlgStep2, CPropertyPage)

CDlgStep2::CDlgStep2()
	: CPropertyPage(CDlgStep2::IDD)
	, m_nSex(0)
{

}

CDlgStep2::~CDlgStep2()
{
}

void CDlgStep2::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_POLE_NAME, m_edtName);
	DDX_Control(pDX, IDC_EDIT_HOW_OLD, m_edtHowOld);
	DDX_Control(pDX, IDC_COMBO1_PROFESSION, m_combProfession);
	DDX_Control(pDX, IDC_EDIT_CONTENT, m_edtContent);
	DDX_Radio(pDX, IDC_RADIO_BOY, m_nSex);
}


BEGIN_MESSAGE_MAP(CDlgStep2, CPropertyPage)
	ON_BN_CLICKED(IDC_BUTTON_AUTO_CREATE, &CDlgStep2::OnBnClickedButtonAutoCreate)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, &CDlgStep2::OnDeltaposSpin1)
	ON_BN_CLICKED(IDC_RADIO_BOY, &CDlgStep2::OnBnClickedRadioBoy)
	ON_BN_CLICKED(IDC_RADIO_GIRL, &CDlgStep2::OnBnClickedRadioGirl)
END_MESSAGE_MAP()


// CDlgStep2 message handlers


void CDlgStep2::OnBnClickedButtonAutoCreate()
{
	// TODO: Add your control notification handler code here
	CDlgGetName dlg;
	if(dlg.DoModal() != IDOK)
		return;

	CString strName = dlg.GetName();
	m_edtName.SetWindowText(strName);


	m_nSex = dlg.GetSex();
	UpdateData();
}


void CDlgStep2::OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: Add your control notification handler code here
	if(pNMUpDown->iDelta == 1)        // 如果此值为1 , 说明点击了Spin的往下箭头
	{
		//对字符做相关处理 , 例如将"a" 变为 "b"
		CString strNum;
		m_edtHowOld.GetWindowText(strNum);
		int nNum = _ttoi(strNum);
		nNum++;
		TCHAR chrNum[MAX_PATH] = {0};
		_itot(nNum,chrNum,10);
		m_edtHowOld.SetWindowText(chrNum);
	}
	else if(pNMUpDown->iDelta == -1) // 如果此值为-1 , 说明点击了Spin的往上箭头
	{
		//对字符做相关处理 , 例如将"b" 变为 "a"
		CString strNum;
		m_edtHowOld.GetWindowText(strNum);
		int nNum = _ttoi(strNum);
		nNum--;
		TCHAR chrNum[MAX_PATH] = {0};
		_itot(nNum,chrNum,10);
		m_edtHowOld.SetWindowText(chrNum);
	}
	*pResult = 0;
}

BOOL CDlgStep2::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  Add extra initialization here
	m_edtHowOld.SetWindowText(_T("18"));

	CDatabaseTableProfession profession;
	vectorBase vectProf =  profession.GetData();
	for(int i=0;i<vectProf.size();i++)
	{
		m_combProfession.AddString(vectProf[i].strName);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CDlgStep2::OnBnClickedRadioBoy()
{
	// TODO: Add your control notification handler code here
	m_nSex = 0;
}


void CDlgStep2::OnBnClickedRadioGirl()
{
	// TODO: Add your control notification handler code here
	m_nSex = 1;
}


BOOL CDlgStep2::OnSetActive()
{
	// TODO: Add your specialized code here and/or call the base class
	CPropertySheet *pSheet=(CPropertySheet *)GetParent();
	ASSERT_KINDOF(CPropertySheet,pSheet);
	pSheet->SetWizardButtons(PSWIZB_NEXT|PSWIZB_BACK); 
	return CPropertyPage::OnSetActive();
}


LRESULT CDlgStep2::OnWizardNext()
{
	// TODO: 在此添加专用代码和/或调用基类
	m_edtName.GetWindowTextW(m_roleProperties.m_strName,24);
	CString strAge;
	m_edtHowOld.GetWindowTextW(strAge);
	m_roleProperties.m_nAge = _ttoi(strAge);
	m_roleProperties.m_nWorkType = m_combProfession.GetCurSel();
	m_roleProperties.m_nSex = m_nSex;
	m_edtContent.GetWindowTextW(m_roleProperties.m_strExplain,256);

	return CPropertyPage::OnWizardNext();
}

RoleProperties CDlgStep2::GetRoleProper()
{
	return m_roleProperties;
}

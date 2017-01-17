// DlgRoleDesign.cpp : implementation file
//

#include "stdafx.h"
#include "NorvelEdit.h"
#include "DlgRoleDesign.h"
#include "afxdialogex.h"
#include "DlgGetName.h"
#include "DatabaseTableProfession.h"
#include "DataConvert.h"
#include "DatabaseTableCloth.h"
#include "DatabaseTableCharacter.h"
#include "DatabaseTableRelationship.h"
#include "NorvelEditDoc.h"



// CDlgRoleDesign dialog

IMPLEMENT_DYNAMIC(CDlgRoleDesign, CDialogEx)

CDlgRoleDesign::CDlgRoleDesign(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgRoleDesign::IDD, pParent)

	, m_nSex(0)
{
	m_iModifyID = -1;

	m_bModify = false;
	memset(&m_RoleProperties,0,sizeof(RoleProperties));
	
}

CDlgRoleDesign::CDlgRoleDesign(int bModifyID,CWnd* pParent)
	: CDialogEx(CDlgRoleDesign::IDD, pParent)
	, m_nSex(0)
{
	m_iModifyID = bModifyID;
	if(bModifyID != -1)
	{
		m_bModify = true;
	}
	else
	{
		m_bModify = false;
		memset(&m_RoleProperties,0,sizeof(RoleProperties));
	}

}


CDlgRoleDesign::~CDlgRoleDesign()
{
	memset(&m_RoleProperties,0,sizeof(RoleProperties));
}

void CDlgRoleDesign::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edtName);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_brigthday);
	DDX_Control(pDX, IDC_COMBO14, m_combProfession);
	DDX_Control(pDX, IDC_COMBO4, m_combStartCapter);
	DDX_Control(pDX, IDC_EDIT_EXPLAN, m_edtExplan);
	DDX_Control(pDX, IDC_EDIT_HOW_OLD, m_edtHowOld);
	DDX_Radio(pDX, IDC_RADIO_BOY, m_nSex);
	DDX_Control(pDX, IDC_EDIT_CONVERT, m_edtConvertData);
	//DDX_Control(pDX, IDC_COMBO_CLOTH, m_combCloth);
	DDX_Control(pDX, IDC_COMBO_CHARACTER, m_combCharacter);
	DDX_Control(pDX, IDC_COMBO_RELATIONSHIP, m_combRelationship);
	DDX_Control(pDX, IDC_EDIT_THE_END, m_edtTheEnd);
}


BEGIN_MESSAGE_MAP(CDlgRoleDesign, CDialogEx)
	
	ON_BN_CLICKED(IDC_BUTTON_AUTO_NAME, &CDlgRoleDesign::OnBnClickedButtonAutoName)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, &CDlgRoleDesign::OnDeltaposSpin1)
	ON_BN_CLICKED(IDC_BUTTON_CONVERT, &CDlgRoleDesign::OnBnClickedButtonConvert)
	ON_BN_CLICKED(IDOK, &CDlgRoleDesign::OnBnClickedOk)
	ON_BN_CLICKED(IDC_RADIO_BOY, &CDlgRoleDesign::OnBnClickedRadioBoy)
	ON_BN_CLICKED(IDC_RADIO_GIRL, &CDlgRoleDesign::OnBnClickedRadioGirl)
END_MESSAGE_MAP()


// CDlgRoleDesign message handlers




void CDlgRoleDesign::OnBnClickedButtonAutoName()
{
	// TODO: 在此添加控件通知处理程序代码
	CDlgGetName dlg;
	if(dlg.DoModal() != IDOK)
		return;

	m_edtName.SetWindowTextW(dlg.GetName());

}

void CDlgRoleDesign::OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult)
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


BOOL CDlgRoleDesign::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CDatabaseTableProfession profession;
	vectorBase vectProf =  profession.GetData();
	for(int i=0;i<vectProf.size();i++)
	{
		m_combProfession.AddString(vectProf[i].strName);
	}

	if(g_Global.m_vectorChapter.size() == 0)
	{
		m_combStartCapter.AddString(_T("第一章"));
		m_combStartCapter.SetCurSel(m_combStartCapter.GetCount() - 1);
	}
	else
	{
		for(int i = 0;i<g_Global.m_vectorChapter.size();i++)
		{
			m_combStartCapter.AddString(g_Global.m_vectorChapter[i]);
		}
		m_combStartCapter.SetCurSel(0);
	}
	

	//CDatabaseTableCloth tableCloth;
	//vectorCloth vtCloth = tableCloth.GetData();
	//for(int i = 0;i<vtCloth.size();i++)
	//{
	//	m_combCloth.AddString(vtCloth[i].strName);
	//}
	
	CDatabaseTableCharacter tableCharacter;
	vectorBase vectorCharacter = tableCharacter.GetData();
	for(int i = 0;i<vectorCharacter.size();i++)
	{
		m_combCharacter.AddString(vectorCharacter[i].strName);
	}
	
	CDatabaseTableRelationship tableRelationship;
	vectorBase vectorRelationship = tableRelationship.GetData();
	for(int i = 0;i<vectorRelationship.size();i++)
	{
		m_combRelationship.AddString(vectorRelationship[i].strName);
	}

	m_edtHowOld.SetWindowText(_T("18"));

	if(m_bModify)
	{
		CNorvelEditDoc *pDoc = (CNorvelEditDoc*)((CFrameWndEx *)AfxGetMainWnd())->GetActiveDocument();

		m_RoleProperties = pDoc->m_SaveFormat.m_vectorRole[m_iModifyID];
		m_edtName.SetWindowTextW(m_RoleProperties.m_strName);
		m_combProfession.SetCurSel(m_RoleProperties.m_nWorkType);
		m_combStartCapter.SetCurSel(m_RoleProperties.m_nStartChapter);
		m_combRelationship.SetCurSel(m_RoleProperties.m_nReleation);
		m_combCharacter.SetCurSel(m_RoleProperties.m_nChara);

		m_brigthday.SetTime(m_RoleProperties.m_timeBirthday);

		TCHAR strAge[32] = {0};
		_itot(m_RoleProperties.m_nAge,strAge,10);
		m_edtHowOld.SetWindowText(strAge);

		m_edtExplan.SetWindowTextW(m_RoleProperties.m_strExplain);
		m_edtTheEnd.SetWindowTextW(m_RoleProperties.m_strTheEnd);

		m_nSex = m_RoleProperties.m_nSex;
	}
	


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CDlgRoleDesign::OnBnClickedButtonConvert()
{
	// TODO: 在此添加控件通知处理程序代码
	SYSTEMTIME settime;
	m_brigthday.GetTime(&settime);

	CDataConvert convert ;
	CString strData = convert.GetDayOf(&settime);
	m_edtConvertData.SetWindowText(strData);
}


void CDlgRoleDesign::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	ReadDataFromDlgCtrl(m_RoleProperties);

	if(m_RoleProperties.m_strName[0] == 0)
	{
		AfxMessageBox(_T("人名是一定要起地"));
		return;
	}

	if(m_bModify)
	{
		CNorvelEditDoc *pDoc = (CNorvelEditDoc*)((CFrameWndEx *)AfxGetMainWnd())->GetActiveDocument();
		pDoc->m_SaveFormat.m_vectorRole[m_iModifyID] = m_RoleProperties;
	}

	CDialogEx::OnOK();
}

void CDlgRoleDesign::SaveNewRoleToFile()
{
	RoleProperties Temp_role = {0};
	ReadDataFromDlgCtrl(Temp_role);

}


void CDlgRoleDesign::OnBnClickedRadioBoy()
{
	// TODO: 在此添加控件通知处理程序代码
	m_nSex = 0;
}


void CDlgRoleDesign::OnBnClickedRadioGirl()
{
	// TODO: 在此添加控件通知处理程序代码
	m_nSex = 1;
}

void CDlgRoleDesign::ReadDataFromDlgCtrl( RoleProperties &Temp_role )
{
	m_edtName.GetWindowTextW(Temp_role.m_strName,24);

	CString strAge;
	m_edtHowOld.GetWindowTextW(strAge);
	Temp_role.m_nAge = _ttoi(strAge);

	m_brigthday.GetTime(&Temp_role.m_timeBirthday);

	Temp_role.m_nSex = m_nSex;
	Temp_role.m_nStartChapter = m_combStartCapter.GetCurSel();

	Temp_role.m_nWorkType = m_combProfession.GetCurSel();
	Temp_role.m_nChara = m_combCharacter.GetCurSel();
	Temp_role.m_nReleation = m_combRelationship.GetCurSel();

	m_edtExplan.GetWindowTextW(Temp_role.m_strExplain,256);
	m_edtTheEnd.GetWindowTextW(Temp_role.m_strTheEnd,256);
}

RoleProperties CDlgRoleDesign::GetRoleData()
{
	return m_RoleProperties;
}

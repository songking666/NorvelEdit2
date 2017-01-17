// DlgStep3.cpp : implementation file
//

#include "stdafx.h"
#include "NorvelEdit.h"
#include "DlgStep3.h"
#include "afxdialogex.h"
#include "DlgAddress.h"
#include "DatabaseTableScene_Type.h"
#include "DatabaseTableWeather.h"
#include "DatabaseTableTimeLen.h"
#include "DatabaseTableTimeUnit.h"


// CDlgStep3 dialog

IMPLEMENT_DYNAMIC(CDlgStep3, CPropertyPage)

CDlgStep3::CDlgStep3()
: CPropertyPage(CDlgStep3::IDD)
{
}

CDlgStep3::~CDlgStep3()
{
}

void CDlgStep3::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_SCENE_TIME_LEN, m_edtTimeLen);
	DDX_Control(pDX, IDC_EDIT_SCENE_NAME, m_edtSceneName);
	DDX_Control(pDX, IDC_COMBO_SCENE_TYPE, m_combSceneType);
	DDX_Control(pDX, IDC_COMBO_SCENE_ADDR, m_combAddr);
	DDX_Control(pDX, IDC_COMBO_SCENE_TIME, m_combTimeSegment);
	DDX_Control(pDX, IDC_COMBO_SCENE_WEATHER, m_combWeather);
	DDX_Control(pDX, IDC_COMBO_TIME_UNIT, m_combTimeUnit);
}


BEGIN_MESSAGE_MAP(CDlgStep3, CPropertyPage)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, &CDlgStep3::OnDeltaposSpin1)
	ON_BN_CLICKED(IDC_BUTTON_CREATE_ADDR, &CDlgStep3::OnBnClickedButtonCreateAddr)
END_MESSAGE_MAP()


// CDlgStep3 message handlers


BOOL CDlgStep3::OnSetActive()
{
	// TODO: Add your specialized code here and/or call the base class
	CPropertySheet *pSheet=(CPropertySheet *)GetParent();
	ASSERT_KINDOF(CPropertySheet,pSheet);
	pSheet->SetWizardButtons(PSWIZB_FINISH|PSWIZB_BACK); 
	return CPropertyPage::OnSetActive();
}


void CDlgStep3::OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: Add your control notification handler code here
	if(pNMUpDown->iDelta == 1)        // 如果此值为1 , 说明点击了Spin的往下箭头
	{
		//对字符做相关处理 , 例如将"a" 变为 "b"
		CString strNum;
		m_edtTimeLen.GetWindowText(strNum);
		int nNum = _ttoi(strNum);
		nNum++;
		TCHAR chrNum[MAX_PATH] = {0};
		_itot(nNum,chrNum,10);
		m_edtTimeLen.SetWindowText(chrNum);
	}
	else if(pNMUpDown->iDelta == -1) // 如果此值为-1 , 说明点击了Spin的往上箭头
	{
		//对字符做相关处理 , 例如将"b" 变为 "a"
		CString strNum;
		m_edtTimeLen.GetWindowText(strNum);
		int nNum = _ttoi(strNum);
		nNum--;
		TCHAR chrNum[MAX_PATH] = {0};
		_itot(nNum,chrNum,10);
		m_edtTimeLen.SetWindowText(chrNum);
	}
	*pResult = 0;
}


void CDlgStep3::OnBnClickedButtonCreateAddr()
{
	// TODO: 在此添加控件通知处理程序代码
	CDlgAddress dlg;
	if(dlg.DoModal() != IDOK)
		return;

	m_combAddr.AddString(dlg.GetAddrName());
	m_combAddr.SetCurSel(m_combAddr.GetCount() - 1);
}


BOOL CDlgStep3::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CDatabaseTableScene_Type tableSceneType;
	vectorBase vectorScenetype = tableSceneType.GetData();
	for(int i = 0;i<vectorScenetype.size();i++)
	{
		m_combSceneType.AddString(vectorScenetype[i].strName);
	}

	CDatabaseTableWeather tableWeather;
	vectorBase vectorWeather = tableWeather.GetData();
	for(int i = 0;i<vectorWeather.size();i++)
	{
		m_combWeather.AddString(vectorWeather[i].strName);
	}

	CDatabaseTableTimeLen tableTimeLen;
	vectorBase vectorTimeLen = tableTimeLen.GetData();
	for(int i = 0;i<vectorTimeLen.size();i++)
	{
		m_combTimeSegment.AddString(vectorTimeLen[i].strName);
	}

	CDatabaseTableTimeUnit tableTimeUnit;
	vectorBase vectorTimeUnit = tableTimeUnit.GetData();
	for(int i = 0;i<vectorTimeUnit.size();i++)
	{
		m_combTimeUnit.AddString(vectorTimeUnit[i].strName);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


BOOL CDlgStep3::OnWizardFinish()
{
	// TODO: 在此添加专用代码和/或调用基类
	m_edtSceneName.GetWindowText(m_SceneFormat.m_strSceneName,24);
	m_SceneFormat.m_nSceneType = m_combSceneType.GetCurSel();
	m_SceneFormat.m_nChapterID = 0;
	m_combAddr.GetLBText(m_combAddr.GetCurSel(),m_SceneFormat.m_strAddress);

	m_SceneFormat.m_nTime = m_combTimeSegment.GetCurSel();

	CString strTimeLen;
	m_edtTimeLen.GetWindowTextW(strTimeLen);
	m_SceneFormat.m_nTimeLong = _ttoi(strTimeLen);
	m_SceneFormat.m_nTimeUnit = m_combTimeUnit.GetCurSel();

	m_SceneFormat.m_nWeather = m_combWeather.GetCurSel();
	return CPropertyPage::OnWizardFinish();
}

SceneFormat CDlgStep3::GetSceneData()
{
	return m_SceneFormat;
}

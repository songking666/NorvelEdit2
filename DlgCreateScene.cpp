// DlgCreateScene.cpp : implementation file
//

#include "stdafx.h"
#include "NorvelEdit.h"
#include "DlgCreateScene.h"
#include "afxdialogex.h"
#include "DatabaseTableScene_Type.h"
#include "DatabaseTableWeather.h"
#include "DlgAddress.h"
#include "DatabaseTableTimeLen.h"
#include "DatabaseTableTimeUnit.h"
#include "DatabaseTableCloth.h"
#include "DatabaseTableExpression.h"
#include "DatabaseTableMood.h"
#include "DatabaseTableRoleStatus.h"
#include "NorvelEditDoc.h"


// CDlgCreateScene dialog

IMPLEMENT_DYNAMIC(CDlgCreateScene, CDialogEx)

CDlgCreateScene::CDlgCreateScene(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgCreateScene::IDD, pParent)
{
	m_iModifyID = -1;
	m_bModify = false;
	memset(&m_SceneFormat,0,sizeof(SceneFormat));
}

CDlgCreateScene::CDlgCreateScene(int SceneID,CWnd* pParent)
	: CDialogEx(CDlgCreateScene::IDD, pParent)
{
	//m_vectorList = vectorCapter;
	m_iModifyID = SceneID;
	if(m_iModifyID != -1)
		m_bModify = true;
	else
		m_bModify = false;
	memset(&m_SceneFormat,0,sizeof(SceneFormat));
}

CDlgCreateScene::~CDlgCreateScene()
{
}

void CDlgCreateScene::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_SCENE_NAME, m_edtSceneName);
	DDX_Control(pDX, IDC_COMBO_CAPTER, m_combCapter);

	DDX_Control(pDX, IDC_COMBO_SCENE_TYPE, m_combSenceType);
	DDX_Control(pDX, IDC_COMBO_SCENE_ADDR, m_combAddress);
	DDX_Control(pDX, IDC_COMBO_SCENE_TIME, m_combTime);
	DDX_Control(pDX, IDC_EDIT_SCENE_TIME_LEN, m_edtTimeLen);

	DDX_Control(pDX, IDC_COMBO_SCENE_WEATHER, m_combWeather);
	DDX_Control(pDX, IDC_COMBO_TIME_UNIT, m_combTimeUnit);
	DDX_Control(pDX, IDC_COMBO_SCENE_ROLE, m_combMainRole);
	DDX_Control(pDX, IDC_COMBO_SCENE_FACE, m_combFace);
	DDX_Control(pDX, IDC_COMBO_SCENE_CLOTH_TYPE, m_combCloth);
	DDX_Control(pDX, IDC_COMBO_SCENE_ROLE_STATUS, m_combStatus);
	DDX_Control(pDX, IDC_COMBO_SCENE_HEART, m_combHeart);

	DDX_Control(pDX, IDC_EDIT_SCENE_EVENT_START, m_edtEventStart);
	DDX_Control(pDX, IDC_EDIT_SCENE_EVENT_PROGRESS, m_edtEventProgress);
	DDX_Control(pDX, IDC_EDIT_SCENE_EVENT_END, m_edtEventEnd);
	DDX_Control(pDX, IDC_COMBO_SCENE_OTHER_PEOPLE, m_combOtherRole);
	DDX_Control(pDX, IDC_LIST_OTHER_ROLE, m_lsOtherRole);
	DDX_Control(pDX, IDC_COMBO_GEO, m_comGeo);
}


BEGIN_MESSAGE_MAP(CDlgCreateScene, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SCENE_AUTO_INPUT, &CDlgCreateScene::OnBnClickedButtonSceneAutoInput)
	ON_BN_CLICKED(IDC_BUTTON_CREATE_ADDRESS, &CDlgCreateScene::OnBnClickedButtonCreateAddress)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, &CDlgCreateScene::OnDeltaposSpin1)
	ON_BN_CLICKED(IDOK, &CDlgCreateScene::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_SCENE_ADD_PEOPLE, &CDlgCreateScene::OnBnClickedButtonSceneAddPeople)
	ON_BN_CLICKED(IDC_BUTTON_CREATE_TEXT, &CDlgCreateScene::OnBnClickedButtonCreateText)
END_MESSAGE_MAP()


// CDlgCreateScene message handlers


BOOL CDlgCreateScene::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_edtTimeLen.SetWindowTextW(_T("1"));

	CDatabaseTableScene_Type sceneType;
	vectorBase vectorSceneType = sceneType.GetData();
	for(int i = 0;i<vectorSceneType.size();i++)
	{
		m_combSenceType.AddString(vectorSceneType[i].strName);
	}

	CDatabaseTableWeather tableWeather;
	vectorBase vectorWeather = tableWeather.GetData();
	for(int i = 0;i<vectorWeather.size();i++)
	{
		m_combWeather.AddString(vectorWeather[i].strName);
	}

	for(int i = 0;i<g_Global.m_vectorChapter.size();i++)
	{
		m_combCapter.AddString(g_Global.m_vectorChapter[i]);
		if(g_Global.m_strTreeSelectItem == g_Global.m_vectorChapter[i])
		{
			m_combCapter.SetCurSel(i);
		}
	}

	CDatabaseTableTimeLen tableTimeLen;
	vectorBase vectorTimeLen = tableTimeLen.GetData();
	for(int i = 0;i<vectorTimeLen.size();i++)
	{
		m_combTime.AddString(vectorTimeLen[i].strName);
	}

	CDatabaseTableTimeUnit tableTimeUnit;
	vectorBase vectorTimeUnit = tableTimeUnit.GetData();
	for(int i = 0;i<vectorTimeUnit.size();i++)
	{
		m_combTimeUnit.AddString(vectorTimeUnit[i].strName);
	}


	CDatabaseTableCloth	tableCloth;
	vectorBase vectorcloth = tableCloth.GetData();
	for(int i =0;i<vectorcloth.size();i++)
	{
		m_combCloth.AddString(vectorcloth[i].strName);
	}

	CDatabaseTableExpression	tableExpression;
	vectorBase vectorExpress = tableExpression.GetData();
	for(int i = 0;i<vectorExpress.size();i++)
	{
		m_combFace.AddString(vectorExpress[i].strName);
	}

	CDatabaseTableMood tableMood;
	vectorBase vectorMood = tableMood.GetData();
	for(int i = 0;i<vectorMood.size();i++)
	{
		m_combHeart.AddString(vectorMood[i].strName);
	}

	CDatabaseTableRoleStatus tableRoleStatus;
	vectorBase vectorRoleStatus = tableRoleStatus.GetData();
	for(int i = 0;i<vectorRoleStatus.size();i++)
	{
		m_combStatus.AddString(vectorRoleStatus[i].strName);
		//m_combOtherStatus.AddString(vectorRoleStatus[i].strName);
	}

	CNorvelEditDoc *pDoc = (CNorvelEditDoc*)((CFrameWndEx *)AfxGetMainWnd())->GetActiveDocument();
	for(int i = 0;i<pDoc->m_SaveFormat.m_vectorRole.size();i++)
	{
		m_combMainRole.AddString(pDoc->m_SaveFormat.m_vectorRole[i].m_strName);
	}

	for(int i = 0;i<pDoc->m_SaveFormat.m_vectorRole.size();i++)
	{
		m_combOtherRole.AddString(pDoc->m_SaveFormat.m_vectorRole[i].m_strName);
	}
	m_combOtherRole.AddString(_T("路人"));

	if(m_bModify)
	{
		
		m_SceneFormat = pDoc->m_SaveFormat.m_vectorScene[m_iModifyID];
		
		m_edtSceneName.SetWindowTextW(m_SceneFormat.m_strSceneName);
		
		TCHAR strTimeLen[24] = {0};
		_itot(m_SceneFormat.m_nTimeLong,strTimeLen,10);
		m_edtTimeLen.SetWindowTextW(strTimeLen);

		m_combSenceType.SetCurSel(m_SceneFormat.m_nSceneType);
		m_combWeather.SetCurSel(m_SceneFormat.m_nWeather);
		m_combCapter.SetCurSel(m_SceneFormat.m_nChapterID);
		m_combTime.SetCurSel(m_SceneFormat.m_nTime);
		m_combTimeUnit.SetCurSel(m_SceneFormat.m_nTimeUnit);
		m_combCloth.SetCurSel(m_SceneFormat.m_RoleStatus.m_nClothType);
		m_combFace.SetCurSel(m_SceneFormat.m_RoleStatus.m_nFaceExpression);
		m_combHeart.SetCurSel(m_SceneFormat.m_RoleStatus.m_nHeartExpression);
		m_combStatus.SetCurSel(m_SceneFormat.m_RoleStatus.m_nBodyStatus);
		m_combMainRole.SetCurSel(m_SceneFormat.m_nMainRoleID);

		for(int i = 0;i<32;i++)
		{
			if(m_SceneFormat.m_strOtherRole[i][0] != 0)
			{
				m_lsOtherRole.AddString(m_SceneFormat.m_strOtherRole[i]);
			}
			else
			{
				break;
			}
		}

		m_edtEventStart.SetWindowTextW(m_SceneFormat.m_strEventStart);
		m_edtEventProgress.SetWindowTextW(m_SceneFormat.m_strEventProgress);
		m_edtEventEnd.SetWindowTextW(m_SceneFormat.m_strEventEnd);

	}


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CDlgCreateScene::OnBnClickedButtonSceneAutoInput()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CDlgCreateScene::OnBnClickedButtonCreateAddress()
{
	// TODO: Add your control notification handler code here
	CDlgAddress dlg;
	if(dlg.DoModal() != IDOK)
	{
		return;
	}
	
	m_combAddress.AddString(dlg.GetAddrName());
	m_combAddress.SetCurSel(m_combAddress.GetCount() - 1);
}


void CDlgCreateScene::OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult)
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

SceneFormat CDlgCreateScene::GetSceneFormat()
{
	return m_SceneFormat;
}


void CDlgCreateScene::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	m_edtSceneName.GetWindowTextW(m_SceneFormat.m_strSceneName,24);
	m_SceneFormat.m_nChapterID = m_combCapter.GetCurSel();
	m_SceneFormat.m_nTime = m_combTime.GetCurSel();

	CString strTimeLen;
	m_edtTimeLen.GetWindowTextW(strTimeLen);
	m_SceneFormat.m_nTimeLong = _ttoi(strTimeLen);

	m_SceneFormat.m_nTimeUnit = m_combTimeUnit.GetCurSel();

	m_SceneFormat.m_nWeather = m_combWeather.GetCurSel();

	m_SceneFormat.m_nSceneType = m_combSenceType.GetCurSel();

	m_combAddress.GetWindowTextW(m_SceneFormat.m_strAddress,24);

	m_SceneFormat.m_nMainRoleID = m_combMainRole.GetCurSel();
	m_SceneFormat.m_RoleStatus.m_nBodyStatus = m_combStatus.GetCurSel();

	m_SceneFormat.m_RoleStatus.m_nClothType = m_combCloth.GetCurSel();
	m_SceneFormat.m_RoleStatus.m_nFaceExpression = m_combFace.GetCurSel();
	m_SceneFormat.m_RoleStatus.m_nHeartExpression = m_combHeart.GetCurSel();

	for(int i = 0;i<m_lsOtherRole.GetCount();i++)
	{
		CString strTemp;
		m_lsOtherRole.GetText(i,strTemp);
		_tcscpy(m_SceneFormat.m_strOtherRole[i],strTemp);
	}
	
	m_edtEventStart.GetWindowTextW(m_SceneFormat.m_strEventStart,256);
	m_edtEventProgress.GetWindowTextW(m_SceneFormat.m_strEventProgress,256);
	m_edtEventEnd.GetWindowTextW(m_SceneFormat.m_strEventEnd,256);

	if(m_bModify)
	{
		CNorvelEditDoc *pDoc = (CNorvelEditDoc*)((CFrameWndEx *)AfxGetMainWnd())->GetActiveDocument();
		pDoc->m_SaveFormat.m_vectorScene[m_iModifyID] = m_SceneFormat;
	}

	CDialogEx::OnOK();
}


void CDlgCreateScene::OnBnClickedButtonSceneAddPeople()
{
	// TODO: 在此添加控件通知处理程序代码
	int nRole = m_combOtherRole.GetCurSel();
	if(nRole == -1)
		return;

	CString strRoleName;
	m_combOtherRole.GetLBText(nRole,strRoleName);
	m_lsOtherRole.AddString(strRoleName);
}


void CDlgCreateScene::OnBnClickedButtonCreateText()
{
	// TODO: 在此添加控件通知处理程序代码
/*
	m_edtSceneName.GetWindowTextW(m_SceneFormat.m_strSceneName,24);
	m_SceneFormat.m_nChapterID = m_combCapter.GetCurSel();
	m_SceneFormat.m_nTime = m_combTime.GetCurSel();

	CString strTimeLen;
	m_edtTimeLen.GetWindowTextW(strTimeLen);
	m_SceneFormat.m_nTimeLong = _ttoi(strTimeLen);

	m_SceneFormat.m_nTimeUnit = m_combTimeUnit.GetCurSel();

	m_SceneFormat.m_nWeather = m_combWeather.GetCurSel();

	m_SceneFormat.m_nSceneType = m_combSenceType.GetCurSel();

	m_combAddress.GetWindowTextW(m_SceneFormat.m_strAddress,24);

	m_SceneFormat.m_RoleStatus.m_nBodyStatus = m_combStatus.GetCurSel();

	m_SceneFormat.m_RoleStatus.m_nClothType = m_combCloth.GetCurSel();
	m_SceneFormat.m_RoleStatus.m_nFaceExpression = m_combFace.GetCurSel();
	m_SceneFormat.m_RoleStatus.m_nHeartExpression = m_combHeart.GetCurSel();

	for(int i = 0;i<m_lsOtherRole.GetCount();i++)
	{
		CString strTemp;
		m_lsOtherRole.GetText(i,strTemp);
		_tcscpy(m_SceneFormat.m_strOtherRole[i],strTemp);
	}

	m_edtEventStart.GetWindowTextW(m_SceneFormat.m_strEventStart,256);
	m_edtEventProgress.GetWindowTextW(m_SceneFormat.m_strEventProgress,256);
	m_edtEventEnd.GetWindowTextW(m_SceneFormat.m_strEventEnd,256);
*/
	CDatabaseTableWeather tableWeather;
	AddTableDataToString(m_combWeather,tableWeather);

	CDatabaseTableScene_Type sceneType;
	AddTableDataToString(m_combSenceType,sceneType);
	
	CDatabaseTableTimeLen tableTimelen;
	AddTableDataToString(m_combTime,tableTimelen);
	
	CString strAddr;
	
	m_combAddress.GetWindowTextW(strAddr);
	strContentText += strAddr;


	CString strPeople;
	m_combMainRole.GetWindowText(strPeople);
	strContentText += strPeople;

	CDatabaseTableCloth tableCloth;
	AddTableDataToString(m_combCloth,tableCloth);

	CDatabaseTableRoleStatus tableStatus;
	AddTableDataToString(m_combStatus,tableStatus);

	CDatabaseTableExpression tableExpression;
	AddTableDataToString(m_combFace,tableExpression);

	CDatabaseTableMood tableMood;
	AddTableDataToString(m_combHeart,tableMood);

	CString strTempText;
	for(int i = 0;i<m_lsOtherRole.GetCount();i++)
	{
		
		m_lsOtherRole.GetText(i,strTempText);
		strContentText += strTempText;
		strContentText += _T("\r\n");
	}

	m_edtEventStart.GetWindowTextW(strTempText);
	strContentText += strTempText;

	m_edtEventProgress.GetWindowTextW(strTempText);
	strContentText += strTempText;

	m_edtEventEnd.GetWindowTextW(strTempText);
	strContentText += strTempText;

	AfxMessageBox(strContentText);
}

void CDlgCreateScene::AddTableDataToString( CComboBox& combBox,CDatabaseTableBase& table )
{
	CString strText;
	int cursel =combBox.GetCurSel();

	if(cursel != -1)
	{
		combBox.GetWindowText(strText);
		vectorBase vtBase = table.Find(strText);

		if(!vtBase.empty())
		{
			strContentText += vtBase[0].strContent;
		}
	}
}

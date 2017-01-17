// DlgDatabaseTableEditOther.cpp : 实现文件
//

#include "stdafx.h"
#include "NorvelEdit.h"
#include "DlgDatabaseTableEditOther.h"
#include "afxdialogex.h"
#include "DatabaseTableAnimation.h"
#include "DatabaseTableExpression.h"
#include "DatabaseTableMood.h"
#include "DatabaseTableScene_Type.h"
#include "DatabaseTableTimeUnit.h"
#include "DatabaseTableTitle.h"
#include "DatabaseTableRank.h"
#include "DatabaseTableWeapon.h"
#include "DatabaseTablePlane.h"
#include "DatabaseTableTimeLen.h"
#include "DatabaseTableCharacter.h"
#include "DatabaseTableRelationship.h"
#include "DatabaseTableRoleStatus.h"
#include "DatabaseTableTheme.h"
#include "DatabaseTableDecade.h"
#include "DatabaseTableWeather.h"
#include "DatabaseTableGeography.h"
#include "DatabaseTableCloth.h"
#include "DatabaseTableThings.h"
#include "DatabaseTableTechnology.h"
#include "DatabaseTableProfession.h"
#include "DatabaseTableCountry.h"
#include "DatabaseTableReligion.h"
#include "DatabaseTableGirl.h"
#include "DatabaseTableBoy.h"


// CDlgDatabaseTableEditOther 对话框

IMPLEMENT_DYNAMIC(CDlgDatabaseTableEditOther, CDialogEx)

CDlgDatabaseTableEditOther::CDlgDatabaseTableEditOther(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgDatabaseTableEditOther::IDD, pParent)
{

}

CDlgDatabaseTableEditOther::~CDlgDatabaseTableEditOther()
{
}

void CDlgDatabaseTableEditOther::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_TABLE, m_combTableName);
	DDX_Control(pDX, IDC_EDIT_KEY_WORD, m_edtKeyWord);
	DDX_Control(pDX, IDC_EDIT_CONTENT, m_edtContent);
	DDX_Control(pDX, IDC_LIST_KEY, m_lsKeyWord);
}


BEGIN_MESSAGE_MAP(CDlgDatabaseTableEditOther, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CDlgDatabaseTableEditOther::OnBnClickedButtonAdd)
	ON_CBN_SELCHANGE(IDC_COMBO_TABLE, &CDlgDatabaseTableEditOther::OnCbnSelchangeComboTable)
END_MESSAGE_MAP()


// CDlgDatabaseTableEditOther 消息处理程序


BOOL CDlgDatabaseTableEditOther::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	for(UINT i = 0;i<g_Global.m_vectorTable.size();i++)
	{
		m_combTableName.AddString(g_Global.m_vectorTable[i].strContent);
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CDlgDatabaseTableEditOther::OnBnClickedButtonAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	int cursel = m_combTableName.GetCurSel();
	CString strTableName;
	//m_combTableName.GetLBText(cursel,strTableName);
	strTableName = g_Global.m_vectorTable[cursel].strName;

	CString strKeyWord;
	m_edtKeyWord.GetWindowText(strKeyWord);
	if(strKeyWord.IsEmpty())
	{
		AfxMessageBox(_T("关键字不能为空"));
		return;
	}
	CString strContent;
	m_edtContent.GetWindowText(strContent);

	bool ret = false;

	CDatabaseTableBase* pTempTable = NULL;
	if(strTableName == GLOBAL_TABLE_ANIMA)
	{
		pTempTable = new CDatabaseTableAnimation();
	}
	else if(strTableName == GLOBAL_TABLE_PLANE)
	{
		pTempTable = new CDatabaseTablePlane();
	}
	else if(strTableName == GLOBAL_TABLE_WEAPON)
	{
		pTempTable = new CDatabaseTableWeapon();
	}
	else if(strTableName == GLOBAL_TABLE_RANK)
	{
		pTempTable = new CDatabaseTableRank();
	}
	else if(strTableName == GLOBAL_TABLE_TITLE)
	{
		pTempTable = new CDatabaseTableTitle();
	}
	else if(strTableName == GLOBAL_TABLE_TIME_UNIT)
	{
		pTempTable = new CDatabaseTableTimeUnit();
	}
	else if(strTableName == GLOBAL_TABLE_SCENE_TYPE)
	{
		pTempTable = new CDatabaseTableScene_Type();
	}
	else if(strTableName == GLOBAL_TABLE_MOOD)
	{
		pTempTable = new CDatabaseTableMood();
	}
	else if(strTableName == GLOBAL_TABLE_EXPRESSION)
	{
		pTempTable = new CDatabaseTableExpression();
	}
	else if(strTableName == GLOBAL_TABLE_COMM_TIME_LEN)
	{
		pTempTable = new CDatabaseTableTimeLen();
	}
	else if(strTableName == GLOBAL_TABLE_CHARACTER)
	{
		pTempTable = new CDatabaseTableCharacter();
	}
	else if(strTableName == GLOBAL_TABLE_RELACTIONSHIP)
	{
		pTempTable = new CDatabaseTableRelationship();
	}
	else if(strTableName == GLOBAL_TABLE_ROLE_STATUS)
	{
		pTempTable = new CDatabaseTableRoleStatus();
	}
	else if(strTableName == GLOBAL_TABLE_THEME)
	{
		pTempTable = new CDatabaseTableTheme();
		
	}
	else if(strTableName == GLOBAL_TABLE_DECADE)
	{
		pTempTable = new CDatabaseTableDecade();
		
	}
	else if(strTableName == GLOBAL_TABLE_WEATHER)
	{
		pTempTable = new CDatabaseTableWeather();

	}
	else if(strTableName == GLOBAL_TABLE_GEOGRAPHY)
	{
		pTempTable = new CDatabaseTableGeography();
	}
	else if(strTableName == GLOBAL_TABLE_CLOTH)
	{
		pTempTable = new CDatabaseTableCloth();
	}
	else if(strTableName == GLOBAL_TABLE_THINGS)
	{
		pTempTable = new CDatabaseTableThings();
	}
	else if(strTableName == GLOBAL_TABLE_TECHNOLOGY)
	{
		pTempTable = new CDatabaseTableTechnology();
	}
	else if(strTableName == GLOBAL_TABLE_PROFESSION)
	{
		pTempTable = new CDatabaseTableProfession();
	}
	else if(strTableName == GLOBAL_TABLE_COUNTRY)
	{
		pTempTable = new CDatabaseTableCountry();
	}
	else if(strTableName == GLOBAL_TABLE_RELIGION)
	{
		pTempTable = new CDatabaseTableReligion();
	}
	else if(strTableName ==GLOBAL_TABLE_GIRL)
	{
		pTempTable = new CDatabaseTableGirl();
	}
	else if(strTableName ==GLOBAL_TABLE_BOY)
	{
		pTempTable = new CDatabaseTableBoy();
	}

	if(pTempTable == NULL)
	{
		return;
	}
	if(pTempTable->Find(strKeyWord).size() > 0)
	{
		AfxMessageBox(_T("记录已经存在"));
		delete pTempTable;
		return;
	}
	ret = pTempTable->Insert(strKeyWord,strContent);
	if(!ret)
	{
		delete pTempTable;
		AfxMessageBox(_T("插入数据失败"));
		return;
	}
	delete pTempTable;
	m_lsKeyWord.AddString(strKeyWord);
	m_edtKeyWord.SetWindowText(NULL);
	m_edtContent.SetWindowText(NULL);
}


void CDlgDatabaseTableEditOther::OnCbnSelchangeComboTable()
{
	// TODO: 在此添加控件通知处理程序代码
	int cursel = m_combTableName.GetCurSel();
	CString strTableName;
	//m_combTableName.GetLBText(cursel,strTableName);
	strTableName = g_Global.m_vectorTable[cursel].strName;
	m_lsKeyWord.ResetContent();
	bool ret = false;
	vectorBase TempBase;
	if(strTableName == GLOBAL_TABLE_ANIMA)
	{
		CDatabaseTableAnimation temptable;
		TempBase = temptable.GetData();
	}
	else if(strTableName == GLOBAL_TABLE_PLANE)
	{
		CDatabaseTablePlane temptable;
		TempBase = temptable.GetData();
	}
	else if(strTableName == GLOBAL_TABLE_WEAPON)
	{
		CDatabaseTableWeapon temptable;
		TempBase = temptable.GetData();
	}
	else if(strTableName == GLOBAL_TABLE_RANK)
	{
		CDatabaseTableRank temptable;
		TempBase = temptable.GetData();
	}
	else if(strTableName == GLOBAL_TABLE_TITLE)
	{
		CDatabaseTableTitle temptable;
		TempBase = temptable.GetData();
	}
	else if(strTableName == GLOBAL_TABLE_TIME_UNIT)
	{
		CDatabaseTableTimeUnit temptable;
		TempBase = temptable.GetData();
	}
	else if(strTableName == GLOBAL_TABLE_SCENE_TYPE)
	{
		CDatabaseTableScene_Type temptable;
		TempBase = temptable.GetData();
	}
	else if(strTableName == GLOBAL_TABLE_MOOD)
	{
		CDatabaseTableMood temptable;
		TempBase = temptable.GetData();
	}
	else if(strTableName == GLOBAL_TABLE_EXPRESSION)
	{
		CDatabaseTableExpression temptable;
		TempBase = temptable.GetData();
	}
	else if(strTableName == GLOBAL_TABLE_COMM_TIME_LEN)
	{
		CDatabaseTableTimeLen temptable;
		TempBase = temptable.GetData();
	}
	else if(strTableName == GLOBAL_TABLE_CHARACTER)
	{
		CDatabaseTableCharacter temptable;
		TempBase = temptable.GetData();
	}
	else if(strTableName == GLOBAL_TABLE_RELACTIONSHIP)
	{
		CDatabaseTableRelationship temptable;
		TempBase = temptable.GetData();
	}
	else if(strTableName == GLOBAL_TABLE_ROLE_STATUS)
	{
		CDatabaseTableRoleStatus temptable;
		TempBase = temptable.GetData();
	}
	else if(strTableName == GLOBAL_TABLE_THEME)
	{
		CDatabaseTableTheme temptable;
		TempBase = temptable.GetData();
	}
	else if(strTableName == GLOBAL_TABLE_DECADE)
	{
		CDatabaseTableDecade temptable;
		TempBase = temptable.GetData();
	}
	else if(strTableName == GLOBAL_TABLE_WEATHER)
	{
		CDatabaseTableWeather temptable;
		TempBase = temptable.GetData();

	}
	else if(strTableName == GLOBAL_TABLE_GEOGRAPHY)
	{
		CDatabaseTableGeography temptable;
		TempBase = temptable.GetData();

	}
	else if(strTableName == GLOBAL_TABLE_CLOTH)
	{
		CDatabaseTableCloth temptable;
		TempBase = temptable.GetData();

	}
	else if(strTableName == GLOBAL_TABLE_THINGS)
	{
		CDatabaseTableThings temptable;
		TempBase = temptable.GetData();
	}
	else if(strTableName == GLOBAL_TABLE_TECHNOLOGY)
	{
		CDatabaseTableTechnology  temptable;
		TempBase = temptable.GetData();
	}
	else if(strTableName == GLOBAL_TABLE_PROFESSION)
	{
		CDatabaseTableProfession  temptable;
		TempBase = temptable.GetData();
	}
	else if(strTableName == GLOBAL_TABLE_COUNTRY)
	{
		CDatabaseTableCountry  temptable;
		TempBase = temptable.GetData();
	}
	else if(strTableName == GLOBAL_TABLE_RELIGION)
	{
		CDatabaseTableReligion  temptable;
		TempBase = temptable.GetData();
	}
	else if(strTableName ==GLOBAL_TABLE_GIRL)
	{
		CDatabaseTableGirl  temptable;
		TempBase = temptable.GetData();
	}
	else if(strTableName ==GLOBAL_TABLE_BOY)
	{
		CDatabaseTableBoy  temptable;
		TempBase = temptable.GetData();
	}
	
	for(int i = 0;i<TempBase.size();i++)
	{
		m_lsKeyWord.AddString(TempBase[i].strName);
	}
}

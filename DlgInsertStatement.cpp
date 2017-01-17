// DlgInsertStatement.cpp : 实现文件
//

#include "stdafx.h"
#include "NorvelEdit.h"
#include "DlgInsertStatement.h"
#include "afxdialogex.h"
#include "DatabaseTableAnimation.h"
#include "DatabaseTablePlane.h"
#include "DatabaseTableWeapon.h"
#include "DatabaseTableRank.h"
#include "DatabaseTableTitle.h"
#include "DatabaseTableTimeUnit.h"
#include "DatabaseTableScene_Type.h"
#include "DatabaseTableMood.h"
#include "DatabaseTableExpression.h"
#include "DatabaseTableTimeLen.h"
#include "DatabaseTableCharacter.h"
#include "DatabaseTableRelationship.h"
#include "DatabaseTableRoleStatus.h"
#include "DatabaseTableProfession.h"
#include "DatabaseTableTechnology.h"
#include "DatabaseTableCloth.h"
#include "DatabaseTableGirl.h"
#include "DatabaseTableBoy.h"


// CDlgInsertStatement 对话框

IMPLEMENT_DYNAMIC(CDlgInsertStatement, CDialogEx)

CDlgInsertStatement::CDlgInsertStatement(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgInsertStatement::IDD, pParent)
{

}

CDlgInsertStatement::CDlgInsertStatement( CString strKey,CWnd* pParent /*= NULL*/ )
	: CDialogEx(CDlgInsertStatement::IDD, pParent)
{
	m_strKeyWord = strKey;
}

CDlgInsertStatement::~CDlgInsertStatement()
{
}

void CDlgInsertStatement::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_TABLE, m_combTableName);
	DDX_Control(pDX, IDC_EDIT_SEARCH_KEY, m_edtSearchKey);
	DDX_Control(pDX, IDC_LIST_KEY_WORD, m_lsKey);
	DDX_Control(pDX, IDC_STATIC_KEY_WORD, m_staticContent);
}


BEGIN_MESSAGE_MAP(CDlgInsertStatement, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDlgInsertStatement::OnBnClickedOk)
	ON_CBN_SELCHANGE(IDC_COMBO_TABLE, &CDlgInsertStatement::OnCbnSelchangeComboTable)
	ON_LBN_SELCHANGE(IDC_LIST_KEY_WORD, &CDlgInsertStatement::OnLbnSelchangeListKeyWord)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, &CDlgInsertStatement::OnBnClickedButtonSearch)
END_MESSAGE_MAP()


// CDlgInsertStatement 消息处理程序


BOOL CDlgInsertStatement::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	for(int i = 0;i<g_Global.m_vectorTable.size();i++)
	{
		m_combTableName.AddString(g_Global.m_vectorTable[i].strContent);
		if(m_strKeyWord == g_Global.m_vectorTable[i].strName)
		{
			m_combTableName.SetCurSel(i);
		}
	}
	OnCbnSelchangeComboTable();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CDlgInsertStatement::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	m_staticContent.GetWindowTextW(m_strRetContent);
	CDialogEx::OnOK();
}


void CDlgInsertStatement::OnCbnSelchangeComboTable()
{
	// TODO: 在此添加控件通知处理程序代码
	m_lsKey.ResetContent();
	int cursel = m_combTableName.GetCurSel();
	CString strTableName;
	//m_combTableName.GetLBText(cursel,strTableName);
	strTableName = g_Global.m_vectorTable[cursel].strName;

	
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
	else if(strTableName == GLOBAL_TABLE_PROFESSION)
	{
		pTempTable = new CDatabaseTableProfession();
	}
	else if(strTableName == GLOBAL_TABLE_TECHNOLOGY)
	{
		pTempTable = new CDatabaseTableTechnology();
	}
	else if(strTableName ==GLOBAL_TABLE_CLOTH)
	{
		pTempTable = new CDatabaseTableCloth();
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
	
	m_vectorData = pTempTable->GetData();
	
	for(int i = 0;i<m_vectorData.size();i++)
	{
		m_lsKey.AddString(m_vectorData[i].strName);
	}

	delete pTempTable;
}


void CDlgInsertStatement::OnLbnSelchangeListKeyWord()
{
	// TODO: 在此添加控件通知处理程序代码
	int cursel = m_lsKey.GetCurSel();
	
	CString strSelectKey;
	m_lsKey.GetText(cursel,strSelectKey);
	
	for(int i = 0;i<m_vectorData.size();i++)
	{
		if(strSelectKey == m_vectorData[i].strName)
		{
			m_staticContent.SetWindowTextW(m_vectorData[i].strContent);
			return;
		}
		
	}
}

CString CDlgInsertStatement::GetString()
{
	return m_strRetContent;
}


void CDlgInsertStatement::OnBnClickedButtonSearch()
{
	// TODO: Add your control notification handler code here
}

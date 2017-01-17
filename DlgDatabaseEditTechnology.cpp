// DlgDatabaseEditTechnology.cpp : 实现文件
//

#include "stdafx.h"
#include "NorvelEdit.h"
#include "DlgDatabaseEditTechnology.h"
#include "afxdialogex.h"


// CDlgDatabaseEditTechnology 对话框

IMPLEMENT_DYNAMIC(CDlgDatabaseEditTechnology, CDialogEx)

CDlgDatabaseEditTechnology::CDlgDatabaseEditTechnology(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgDatabaseEditTechnology::IDD, pParent)
	, m_nType(0)
{

}

CDlgDatabaseEditTechnology::~CDlgDatabaseEditTechnology()
{
}

void CDlgDatabaseEditTechnology::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_TECHNOLOGY, m_lsTechnology);
	DDX_Control(pDX, IDC_LIST_PROFESSION, m_lsProfession);
	DDX_Control(pDX, IDC_EDIT_TECHNOLOGY, m_edtTech);
	DDX_Control(pDX, IDC_EDIT_TECHNOLOGY_CONTENT, m_edtContentTech);
	DDX_Control(pDX, IDC_EDIT_PROFESSION, m_edtProfession);
	DDX_Control(pDX, IDC_EDIT_PROFESSION_CONTENT, m_edtContentProfession);
	DDX_Radio(pDX, IDC_RADIO1, m_nType);
}


BEGIN_MESSAGE_MAP(CDlgDatabaseEditTechnology, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_TECHNOLOGY, &CDlgDatabaseEditTechnology::OnBnClickedButtonTechnology)
	ON_BN_CLICKED(IDC_BUTTON_PROFESSION, &CDlgDatabaseEditTechnology::OnBnClickedButtonProfession)
	ON_BN_CLICKED(IDC_RADIO1, &CDlgDatabaseEditTechnology::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CDlgDatabaseEditTechnology::OnBnClickedRadio2)
END_MESSAGE_MAP()


// CDlgDatabaseEditTechnology 消息处理程序


void CDlgDatabaseEditTechnology::OnBnClickedButtonTechnology()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strdata;
	m_edtTech.GetWindowText(strdata);
	if(strdata.IsEmpty())
	{
		AfxMessageBox(_T("数据不能为空！"));
		return;
	}
	if(m_tableTech.Find(_T("technology"),strdata).size() != 0)
	{
		AfxMessageBox(_T("数据已经存在！"));
		return;
	}
	CString strContent;
	m_edtContentTech.GetWindowText(strContent);
	if(!m_tableTech.Insert(strdata,strContent))
	{
		AfxMessageBox(_T("插入数据失败！"));
		return;
	}
	m_lsTechnology.AddString(strdata);
	m_edtTech.SetWindowTextW(NULL);
	m_edtContentTech.SetWindowTextW(NULL);
}


void CDlgDatabaseEditTechnology::OnBnClickedButtonProfession()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strdata;
	m_edtProfession.GetWindowText(strdata);
	if(strdata.IsEmpty())
	{
		AfxMessageBox(_T("数据不能为空！"));
		return;
	}
	if(m_tableProf.Find(_T("profession"),strdata).size() != 0)
	{
		AfxMessageBox(_T("数据已经存在！"));
		return;
	}
	CString strContent;
	m_edtContentProfession.GetWindowText(strContent);
	if(!m_tableProf.Insert(strdata,strContent,m_nType))
	{
		AfxMessageBox(_T("插入数据失败！"));
		return;
	}
	m_lsProfession.AddString(strdata);
	m_edtContentProfession.SetWindowTextW(NULL);
	m_edtProfession.SetWindowTextW(NULL);
}


BOOL CDlgDatabaseEditTechnology::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	VectorTechnology vtheme = m_tableTech.GetData();
	for(int i = 0;i<vtheme.size();i++)
	{
		m_lsTechnology.AddString(vtheme[i].strName);
	}

	vectorProfession vdecade = m_tableProf.GetData();
	for(int i = 0;i<vdecade.size();i++)
	{
		m_lsProfession.AddString(vdecade[i].strProfessionName);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CDlgDatabaseEditTechnology::OnBnClickedRadio1()
{
	// TODO: Add your control notification handler code here
	m_nType = 0;
}


void CDlgDatabaseEditTechnology::OnBnClickedRadio2()
{
	// TODO: Add your control notification handler code here
	m_nType  = 1;
}

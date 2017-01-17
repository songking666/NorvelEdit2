// DlgDatabaseEditCountry.cpp : 实现文件
//

#include "stdafx.h"
#include "NorvelEdit.h"
#include "DlgDatabaseEditCountry.h"
#include "afxdialogex.h"


// CDlgDatabaseEditCountry 对话框

IMPLEMENT_DYNAMIC(CDlgDatabaseEditCountry, CDialogEx)

CDlgDatabaseEditCountry::CDlgDatabaseEditCountry(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgDatabaseEditCountry::IDD, pParent)
	, m_nCountryType(0)
{

}

CDlgDatabaseEditCountry::~CDlgDatabaseEditCountry()
{
}

void CDlgDatabaseEditCountry::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_COUNTRY, m_lsCountry);
	DDX_Control(pDX, IDC_LIST_RELIGIOUS, m_lsReli);
	DDX_Control(pDX, IDC_EDIT_COUNTRY, m_edtCountry);
	DDX_Control(pDX, IDC_EDIT_COUNTRY_CONTENT, m_edtContentCountry);
	DDX_Control(pDX, IDC_EDIT_RELIGIOUS, m_edtReli);
	DDX_Control(pDX, IDC_EDIT_RELIGIOUS_CONTENT, m_ContentReli);
	DDX_Radio(pDX, IDC_RADIO1, m_nCountryType);
	DDV_MinMaxInt(pDX, m_nCountryType, 1, 2);
}


BEGIN_MESSAGE_MAP(CDlgDatabaseEditCountry, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_COUNTRY, &CDlgDatabaseEditCountry::OnBnClickedButtonCountry)
	ON_BN_CLICKED(IDC_BUTTON_RELIGIOUS, &CDlgDatabaseEditCountry::OnBnClickedButtonReligious)
END_MESSAGE_MAP()


// CDlgDatabaseEditCountry 消息处理程序


void CDlgDatabaseEditCountry::OnBnClickedButtonCountry()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strdata;
	m_edtCountry.GetWindowText(strdata);
	if(strdata.IsEmpty())
	{
		AfxMessageBox(_T("数据不能为空！"));
		return;
	}
	if(m_tableCountry.Find(_T("country"),strdata).size() != 0)
	{
		AfxMessageBox(_T("数据已经存在！"));
		return;
	}
	CString strContent;
	m_edtContentCountry.GetWindowText(strContent);
	if(!m_tableCountry.Insert(strdata,strContent,m_nCountryType))
		AfxMessageBox(_T("插入数据失败！"));
	m_lsCountry.AddString(strdata);
}


void CDlgDatabaseEditCountry::OnBnClickedButtonReligious()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strdata;
	m_edtReli.GetWindowText(strdata);
	if(strdata.IsEmpty())
	{
		AfxMessageBox(_T("数据不能为空！"));
		return;
	}
	if(m_tableReli.Find(_T("religion"),strdata).size() != 0)
	{
		AfxMessageBox(_T("数据已经存在！"));
		return;
	}
	CString strContent;
	m_ContentReli.GetWindowText(strContent);
	if(!m_tableReli.Insert(strdata,strContent))
		AfxMessageBox(_T("插入数据失败！"));
	m_lsReli.AddString(strdata);
}


BOOL CDlgDatabaseEditCountry::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	vectorCountry vtheme = m_tableCountry.GetData();
	for(int i = 0;i<vtheme.size();i++)
	{
		m_lsCountry.AddString(vtheme[i].strName);
	}

	vectorReligion vdecade = m_tableReli.GetData();
	for(int i = 0;i<vdecade.size();i++)
	{
		m_lsReli.AddString(vdecade[i].strName);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

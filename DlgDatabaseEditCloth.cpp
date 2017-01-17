// DlgDatabaseEditCloth.cpp : 实现文件
//

#include "stdafx.h"
#include "NorvelEdit.h"
#include "DlgDatabaseEditCloth.h"
#include "afxdialogex.h"


// CDlgDatabaseEditCloth 对话框

IMPLEMENT_DYNAMIC(CDlgDatabaseEditCloth, CDialogEx)

CDlgDatabaseEditCloth::CDlgDatabaseEditCloth(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgDatabaseEditCloth::IDD, pParent)
{

}

CDlgDatabaseEditCloth::~CDlgDatabaseEditCloth()
{
}

void CDlgDatabaseEditCloth::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_CLOTH, m_lsCloth);
	DDX_Control(pDX, IDC_LIST_THINGS, m_lsThings);
	DDX_Control(pDX, IDC_EDIT_CLOTH, m_edtCloth);
	DDX_Control(pDX, IDC_EDIT_CLOTH_CONTENT, m_edtContentCloth);
	DDX_Control(pDX, IDC_EDIT_THINGS, m_edtThings);
	DDX_Control(pDX, IDC_EDIT_THINGS_CONTENT, m_edtContentThings);
}


BEGIN_MESSAGE_MAP(CDlgDatabaseEditCloth, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_CLOTH, &CDlgDatabaseEditCloth::OnBnClickedButtonCloth)
	ON_BN_CLICKED(IDC_BUTTON_THINGS, &CDlgDatabaseEditCloth::OnBnClickedButtonThings)
END_MESSAGE_MAP()


// CDlgDatabaseEditCloth 消息处理程序


void CDlgDatabaseEditCloth::OnBnClickedButtonCloth()
{
	// TODO: 在此添加控件通知处理程序代码

	CString strdata;
	m_edtCloth.GetWindowText(strdata);
	if(strdata.IsEmpty())
	{
		AfxMessageBox(_T("数据不能为空！"));
		return;
	}
	if(m_tableCloth.Find(_T("cloth"),strdata).size() != 0)
	{
		AfxMessageBox(_T("数据已经存在！"));
		return;
	}
	CString strContent;
	m_edtContentCloth.GetWindowText(strContent);
	if(!m_tableCloth.Insert(strdata,strContent))
	{
		AfxMessageBox(_T("插入数据失败！"));
		return;
	}
	m_lsCloth.AddString(strdata);
	m_edtContentCloth.SetWindowTextW(NULL);
}


void CDlgDatabaseEditCloth::OnBnClickedButtonThings()
{
	// TODO: 在此添加控件通知处理程序代码

	CString strdata;
	m_edtThings.GetWindowText(strdata);
	if(strdata.IsEmpty())
	{
		AfxMessageBox(_T("数据不能为空！"));
		return;
	}
	if(m_tableThing.Find(_T("things"),strdata).size() != 0)
	{
		AfxMessageBox(_T("数据已经存在！"));
		return;
	}
	CString strContent;
	m_edtContentThings.GetWindowText(strContent);
	if(!m_tableThing.Insert(strdata,strContent))
	{
		AfxMessageBox(_T("插入数据失败！"));
		return;
	}
	m_lsThings.AddString(strdata);
	m_edtContentThings.Clear();
}


BOOL CDlgDatabaseEditCloth::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	vectorCloth vtheme = m_tableCloth.GetData();
	for(int i = 0;i<vtheme.size();i++)
	{
		m_lsCloth.AddString(vtheme[i].strName);
	}

	VectorThings vdecade = m_tableThing.GetData();
	for(int i = 0;i<vdecade.size();i++)
	{
		m_lsThings.AddString(vdecade[i].strName);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

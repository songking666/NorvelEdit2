// DlgDatabaseEdit.cpp : 实现文件
//

#include "stdafx.h"
#include "NorvelEdit.h"
#include "DlgDatabaseEdit.h"
#include "afxdialogex.h"



// CDlgDatabaseEdit 对话框

IMPLEMENT_DYNAMIC(CDlgDatabaseEdit, CDialogEx)

CDlgDatabaseEdit::CDlgDatabaseEdit(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgDatabaseEdit::IDD, pParent)
{

}

CDlgDatabaseEdit::~CDlgDatabaseEdit()
{
}

void CDlgDatabaseEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_THEME, m_edtTheme);
	DDX_Control(pDX, IDC_EDIT_THEME_CONTENT, m_edtThemeContent);
	DDX_Control(pDX, IDC_EDIT_DECADE, m_edtDecade);
	DDX_Control(pDX, IDC_EDIT_DECADE_CONTENT, m_edtDecadeContent);
	DDX_Control(pDX, IDC_LIST_THEME, m_lsTheme);
	DDX_Control(pDX, IDC_LIST_DECADE, m_lsDecade);
}


BEGIN_MESSAGE_MAP(CDlgDatabaseEdit, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_THEME, &CDlgDatabaseEdit::OnBnClickedButtonTheme)
	ON_BN_CLICKED(IDC_BUTTON_DECADE, &CDlgDatabaseEdit::OnBnClickedButtonDecade)
END_MESSAGE_MAP()


// CDlgDatabaseEdit 消息处理程序


void CDlgDatabaseEdit::OnBnClickedButtonTheme()
{
	// TODO: 在此添加控件通知处理程序代码
	
	CString strTheme;
	m_edtTheme.GetWindowText(strTheme);
	if(strTheme.IsEmpty())
	{
		AfxMessageBox(_T("数据不能为空！"));
		return;
	}
	if(table_theme.Find(_T("theme"),strTheme).size() != 0)
	{
		AfxMessageBox(_T("数据已经存在！"));
		return;
	}
	CString strContent;
	m_edtThemeContent.GetWindowText(strContent);
	if(!table_theme.Insert(strTheme,strContent))
		AfxMessageBox(_T("插入数据失败！"));
	m_lsTheme.AddString(strTheme);
}


void CDlgDatabaseEdit::OnBnClickedButtonDecade()
{
	// TODO: Add your control notification handler code here
	
	CString strDecade;
	m_edtDecade.GetWindowText(strDecade);
	if(strDecade.IsEmpty())
	{
		AfxMessageBox(_T("数据不能为空！"));
		return;
	}
	if(table_eDecade.Find(_T("Decade"),strDecade).size() != 0)
	{
		AfxMessageBox(_T("数据已经存在！"));
		return;
	}
	CString strContent;
	m_edtDecadeContent.GetWindowText(strContent);
	if(!table_eDecade.Insert(strDecade,strContent))
		AfxMessageBox(_T("插入数据失败！"));
	m_lsDecade.AddString(strDecade);
}


BOOL CDlgDatabaseEdit::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	VectorTheme vtheme = table_theme.GetData();
	for(int i = 0;i<vtheme.size();i++)
	{
		m_lsTheme.AddString(vtheme[i].strName);
	}

	vectorDecade vdecade = table_eDecade.GetData();
	for(int i = 0;i<vdecade.size();i++)
	{
		m_lsDecade.AddString(vdecade[i].strDate);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

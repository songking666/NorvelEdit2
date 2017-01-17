// DlgDatabaseWeather.cpp : 实现文件
//

#include "stdafx.h"
#include "NorvelEdit.h"
#include "DlgDatabaseWeather.h"
#include "afxdialogex.h"


// CDlgDatabaseWeather 对话框

IMPLEMENT_DYNAMIC(CDlgDatabaseWeather, CDialogEx)

CDlgDatabaseWeather::CDlgDatabaseWeather(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgDatabaseWeather::IDD, pParent)
{

}

CDlgDatabaseWeather::~CDlgDatabaseWeather()
{
}

void CDlgDatabaseWeather::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_WEATHER, m_listWeather);
	DDX_Control(pDX, IDC_LIST_GEO, m_listGeo);
	DDX_Control(pDX, IDC_EDIT_WEATHER, m_edtWeather);
	DDX_Control(pDX, IDC_EDIT_GEO, m_edtGeo);
	DDX_Control(pDX, IDC_EDIT_WEATHER_CONTENT, m_edtContentWeather);
	DDX_Control(pDX, IDC_EDIT_GEO_CONTENT, m_edtContentGeo);
}


BEGIN_MESSAGE_MAP(CDlgDatabaseWeather, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_WEATHER, &CDlgDatabaseWeather::OnBnClickedButtonWeather)
	ON_BN_CLICKED(IDC_BUTTON_DECADE, &CDlgDatabaseWeather::OnBnClickedButtonDecade)
END_MESSAGE_MAP()


// CDlgDatabaseWeather 消息处理程序


void CDlgDatabaseWeather::OnBnClickedButtonWeather()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strdata;
	m_edtWeather.GetWindowText(strdata);
	
	if(strdata.IsEmpty())
	{
		AfxMessageBox(_T("数据不能为空！"));
		return;
	}
	if(tableWeather.Find(_T("weather"),strdata).size() != 0)
	{
		AfxMessageBox(_T("数据已经存在！"));
		return;
	}
	CString strContent;
	m_edtContentWeather.GetWindowText(strContent);

	
	if(!tableWeather.Insert(strdata,strContent))
	{
		AfxMessageBox(_T("插入数据失败！"));
		return;
	}
	m_listWeather.AddString(strdata);
	m_edtWeather.SetWindowTextW(NULL);
	m_edtContentWeather.SetWindowText(NULL);
}


void CDlgDatabaseWeather::OnBnClickedButtonDecade()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strdata;
	m_edtGeo.GetWindowText(strdata);
	
	if(strdata.IsEmpty())
	{
		AfxMessageBox(_T("数据不能为空！"));
		return;
	}
	if(tableGeo.Find(_T("Geography"),strdata).size() != 0)
	{
		AfxMessageBox(_T("数据已经存在！"));
		return;
	}
	CString strContent;
	m_edtContentGeo.GetWindowText(strContent);

	
	if(!tableGeo.Insert(strdata,strContent))
	{
		AfxMessageBox(_T("插入数据失败！"));
		return;
	}
	m_listGeo.AddString(strdata);
	m_edtGeo.SetWindowTextW(NULL);
	m_edtContentGeo.SetWindowTextW(NULL);
}


BOOL CDlgDatabaseWeather::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	VectorWeather vtheme = tableWeather.GetData();
	for(int i = 0;i<vtheme.size();i++)
	{
		m_listWeather.AddString(vtheme[i].strName);
	}

	VectorGeography vdecade = tableGeo.GetData();
	for(int i = 0;i<vdecade.size();i++)
	{
		m_listGeo.AddString(vdecade[i].strGeographyName);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

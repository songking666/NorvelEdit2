// DlgAddress.cpp : implementation file
//

#include "stdafx.h"
#include "NorvelEdit.h"
#include "DlgAddress.h"
#include "afxdialogex.h"
#include "DatabaseTableCommonWord.h"


// CDlgAddress dialog

IMPLEMENT_DYNAMIC(CDlgAddress, CDialogEx)

CDlgAddress::CDlgAddress(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgAddress::IDD, pParent)
	, m_nTarName(0)
{

}

CDlgAddress::~CDlgAddress()
{
}

void CDlgAddress::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_SPECIAL, m_edtSpecial);
	DDX_Control(pDX, IDC_LIST_ADDRESS, m_lsAddr);
	DDX_Radio(pDX, IDC_RADIO_RANDOM, m_nTarName);
}


BEGIN_MESSAGE_MAP(CDlgAddress, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgAddress::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_RADIO_RANDOM, &CDlgAddress::OnBnClickedRadioRandom)
	ON_BN_CLICKED(IDC_RADIO_TARGET, &CDlgAddress::OnBnClickedRadioTarget)
	ON_BN_CLICKED(IDOK, &CDlgAddress::OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgAddress message handlers


void CDlgAddress::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	vectorBase vectorGeo = m_TableGeo.GetData();
	m_lsAddr.ResetContent();
	srand((unsigned)time(NULL)); 
	//rand()%
	int nfirstCount = vectorGeo.size();
	if(nfirstCount == 0)
		return;
	CString strSpecial;
	if(m_nTarName == 1)
	{
		m_edtSpecial.GetWindowTextW(strSpecial);
	}
	
	CDatabaseTableCommonWord commword;
	int nCount = commword.GetCount();
	
	
	for(int i=0;i<20;i++)
	{
		CString strFullName;
		
		for (int i=0;i<2;++i) 
		{
			int OneCharPos;
			OneCharPos = rand()%nCount ;
			vectorWord word = commword.Find(OneCharPos);
			if(word.size() != 0)
			{
				strFullName += word[0].strName;
			}
		}
		
		if(m_nTarName == 0)
		{
			int nRand2 = rand() % nfirstCount;
			strFullName += vectorGeo[nRand2].strName;
		}
		else
		{
			strFullName += strSpecial;
		}

		m_lsAddr.AddString(strFullName);
	}
}


void CDlgAddress::OnBnClickedRadioRandom()
{
	// TODO: 在此添加控件通知处理程序代码
	m_nTarName = 0;
	m_edtSpecial.EnableWindow(FALSE);
}


void CDlgAddress::OnBnClickedRadioTarget()
{
	// TODO: 在此添加控件通知处理程序代码
	m_nTarName = 1;
	m_edtSpecial.EnableWindow(TRUE);
}


BOOL CDlgAddress::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_edtSpecial.EnableWindow(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

CString CDlgAddress::GetAddrName()
{
	
	return m_strRet;
}


void CDlgAddress::OnBnClickedOk()
{
	int selectsel = m_lsAddr.GetCurSel();
	if(selectsel == -1)
	{
		AfxMessageBox(_T("请选择一个地名"));
		return;
	}

	m_lsAddr.GetText(selectsel,m_strRet);
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}

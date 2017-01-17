// DlgGetName.cpp : implementation file
//

#include "stdafx.h"
#include "NorvelEdit.h"
#include "DlgGetName.h"
#include "afxdialogex.h"


// CDlgGetName dialog

IMPLEMENT_DYNAMIC(CDlgGetName, CDialogEx)

CDlgGetName::CDlgGetName(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgGetName::IDD, pParent)
	, m_nFirstName(0)
	, m_nSex(0)
	, m_nCountry(0)
{

}

CDlgGetName::~CDlgGetName()
{
}

void CDlgGetName::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO_FIRSTNAME1, m_nFirstName);
	DDX_Radio(pDX, IDC_RADIO_SEX_BOY, m_nSex);
	DDX_Control(pDX, IDC_EDIT_FIRST_NAME, m_edtFirstname);
	DDX_Control(pDX, IDC_LIST_GET_NAME, m_lsName);
	DDX_Radio(pDX, IDC_RADIO1, m_nCountry);
}


BEGIN_MESSAGE_MAP(CDlgGetName, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO_FIRSTNAME1, &CDlgGetName::OnBnClickedRadioFirstname1)
	ON_BN_CLICKED(IDC_RADIO_FIRSTNAME2, &CDlgGetName::OnBnClickedRadioFirstname2)
	ON_BN_CLICKED(IDC_RADIO_FIRSTNAME3, &CDlgGetName::OnBnClickedRadioFirstname3)
	ON_BN_CLICKED(IDC_RADIO_SEX_GIRL, &CDlgGetName::OnBnClickedRadioSexGirl)
	ON_BN_CLICKED(IDC_RADIO_SEX_BOY, &CDlgGetName::OnBnClickedRadioSexBoy)
	ON_BN_CLICKED(IDC_RADIO_SEX_MID, &CDlgGetName::OnBnClickedRadioSexMid)
	ON_BN_CLICKED(IDC_BUTTON_CREATE, &CDlgGetName::OnBnClickedButtonCreate)
	ON_BN_CLICKED(IDOK, &CDlgGetName::OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgGetName message handlers


void CDlgGetName::OnBnClickedRadioFirstname1()
{
	// TODO: Add your control notification handler code here
	m_edtFirstname.EnableWindow(FALSE);
	m_nFirstName = 0;
}


void CDlgGetName::OnBnClickedRadioFirstname2()
{
	// TODO: Add your control notification handler code here
	m_edtFirstname.EnableWindow(FALSE);
	m_nFirstName = 1;
}


void CDlgGetName::OnBnClickedRadioFirstname3()
{
	// TODO: Add your control notification handler code here
	m_edtFirstname.EnableWindow(TRUE);
	m_nFirstName = 2;
}


void CDlgGetName::OnBnClickedRadioSexGirl()
{
	// TODO: Add your control notification handler code here
	m_nSex = 1;
}


void CDlgGetName::OnBnClickedRadioSexBoy()
{
	// TODO: Add your control notification handler code here
	m_nSex = 0;
}


void CDlgGetName::OnBnClickedRadioSexMid()
{
	// TODO: Add your control notification handler code here
	m_nSex = 2;
}


void CDlgGetName::OnBnClickedButtonCreate()
{
	// TODO: Add your control notification handler code here
	m_lsName.ResetContent();
	srand((unsigned)time(NULL)); 
	//rand()%
	int nfirstCount = m_tableFirstname.GetCount();
	
	VectorLastName vectorLastname=m_tableLastName.Find(_T("sex"),m_nSex);
	
	CString strSelectFirstName;
	m_edtFirstname.GetWindowTextW(strSelectFirstName);

	for(int i=0;i<20;i++)
	{
		CString strFullName;
		if(m_nFirstName == 0)
		{
			int nRand = rand()%nfirstCount;
			TableFirstName firstName = m_tableFirstname.GetFirstnameByID(nRand);
			strFullName += firstName.strFirstName;
		}
		else
		{
			if(strSelectFirstName.IsEmpty())
			{
				AfxMessageBox(_T("请指定一个姓!"));
				return;
			}
			strFullName += strSelectFirstName;
		}
		
		int nRand2 = rand() % vectorLastname.size();
		strFullName += vectorLastname[nRand2].strName;

		m_lsName.AddString(strFullName);
	}

	
}


void CDlgGetName::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	int selectsel = m_lsName.GetCurSel();
	if(selectsel == -1)
	{
		AfxMessageBox(_T("选择一个名字"));
		return;
	}
	m_lsName.GetText(selectsel,m_strRetName);
	CDialogEx::OnOK();
}

CString CDlgGetName::GetName()
{
	return m_strRetName;
}

int CDlgGetName::GetSex()
{
	return m_nSex;
}


BOOL CDlgGetName::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_edtFirstname.EnableWindow(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

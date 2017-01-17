// DlgDatabaseNameEdit.cpp : implementation file
//

#include "stdafx.h"
#include "NorvelEdit.h"
#include "DlgDatabaseNameEdit.h"
#include "afxdialogex.h"


// CDlgDatabaseNameEdit dialog

IMPLEMENT_DYNAMIC(CDlgDatabaseNameEdit, CDialogEx)

CDlgDatabaseNameEdit::CDlgDatabaseNameEdit(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgDatabaseNameEdit::IDD, pParent)
	, m_nFirstNameType(0)
	, m_nLastNameType(0)
	, m_nSex(0)
{

}

CDlgDatabaseNameEdit::~CDlgDatabaseNameEdit()
{
}

void CDlgDatabaseNameEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_FIRST_NAME, m_edtFirstName);
	DDX_Control(pDX, IDC_EDIT_LAST_NAME, m_edtLastName);
	DDX_Radio(pDX, IDC_RADIO_FIRST_NAME_CHINA, m_nFirstNameType);
	DDV_MinMaxInt(pDX, m_nFirstNameType, 0, 2);
	DDX_Radio(pDX, IDC_RADIO_LAST_NAME_CHA, m_nLastNameType);
	//DDV_MinMaxInt(pDX, m_nLastNameType, 0, 2);
	DDX_Radio(pDX, IDC_RADIO_BOY, m_nSex);
	//DDV_MinMaxInt(pDX, m_nSex, 0, 2);
}


BEGIN_MESSAGE_MAP(CDlgDatabaseNameEdit, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_FIRST_NAME, &CDlgDatabaseNameEdit::OnBnClickedButtonFirstName)
	ON_BN_CLICKED(IDC_BUTTON_LAST_NAME, &CDlgDatabaseNameEdit::OnBnClickedButtonLastName)
	ON_BN_CLICKED(IDC_BUTTON_FIRST_NAME_IMPORT, &CDlgDatabaseNameEdit::OnBnClickedButtonFirstNameImport)
	ON_BN_CLICKED(IDC_BUTTON_LAST_NAME_IMPORT, &CDlgDatabaseNameEdit::OnBnClickedButtonLastNameImport)
	ON_BN_CLICKED(IDC_RADIO_FIRST_NAME_CHINA, &CDlgDatabaseNameEdit::OnBnClickedRadioFirstNameChina)
	ON_BN_CLICKED(IDC_RADIO_FIRST_NAME_ENG, &CDlgDatabaseNameEdit::OnBnClickedRadioFirstNameEng)
	ON_BN_CLICKED(IDC_RADIO_FIRST_NAME_JAN, &CDlgDatabaseNameEdit::OnBnClickedRadioFirstNameJan)
	ON_BN_CLICKED(IDC_RADIO_LAST_NAME_CHA, &CDlgDatabaseNameEdit::OnBnClickedRadioLastNameCha)
	ON_BN_CLICKED(IDC_RADIO_LAST_NAME_ENG, &CDlgDatabaseNameEdit::OnBnClickedRadioLastNameEng)
	ON_BN_CLICKED(IDC_RADIO_LAST_NAME_JAN, &CDlgDatabaseNameEdit::OnBnClickedRadioLastNameJan)
	ON_BN_CLICKED(IDC_RADIO_BOY, &CDlgDatabaseNameEdit::OnBnClickedRadioBoy)
	ON_BN_CLICKED(IDC_RADIO_GIRL, &CDlgDatabaseNameEdit::OnBnClickedRadioGirl)
	ON_BN_CLICKED(IDC_RADIO_SEX_MID, &CDlgDatabaseNameEdit::OnBnClickedRadioSexMid)
END_MESSAGE_MAP()


// CDlgDatabaseNameEdit message handlers


void CDlgDatabaseNameEdit::OnBnClickedButtonFirstName()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strTheme;
	m_edtFirstName.GetWindowText(strTheme);
	if(strTheme.IsEmpty())
	{
		AfxMessageBox(_T("数据不能为空！"));
		return;
	}
	if(m_tableFirstName.Find(_T("FirstName"),strTheme).size() != 0)
	{
		AfxMessageBox(_T("数据已经存在！"));
		return;
	}

	if(!m_tableFirstName.Insert(strTheme,m_nFirstNameType))
		AfxMessageBox(_T("插入数据失败！"));
}


BOOL CDlgDatabaseNameEdit::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//m_tableFirstName.GetData()
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CDlgDatabaseNameEdit::OnBnClickedButtonLastName()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strTheme;
	m_edtLastName.GetWindowText(strTheme);
	if(strTheme.IsEmpty())
	{
		AfxMessageBox(_T("数据不能为空！"));
		return;
	}
	if(m_tableLastName.Find(_T("LastName"),strTheme).size() != 0)
	{
		AfxMessageBox(_T("数据已经存在！"));
		return;
	}

	if(!m_tableLastName.Insert(strTheme,m_nLastNameType,m_nSex))
	{
		AfxMessageBox(_T("插入数据失败！"));
		return;
	}

	m_edtLastName.SetWindowTextW(NULL);
}


void CDlgDatabaseNameEdit::OnBnClickedButtonFirstNameImport()
{
	// TODO: Add your control notification handler code here
	CString FilePathName;  
	CFileDialog dlg(TRUE, _T( "txt" ), _T( "*.txt" ), OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, _T("txt Files (*.txt)|*.txt||"));///TRUE为OPEN对话框，FALSE为SAVE AS对话框  
	if(dlg.DoModal()!=IDOK)  
		return;
	FilePathName=dlg.GetPathName();

	FILE* fp = _tfopen(FilePathName,_T("rb"));
	unsigned char szbuf[2] = {0};
	fread(szbuf,2,1,fp);
	if(szbuf[0] != 0xFF || szbuf[1] != 0xFE)
	{
		return;
	}
	fseek(fp,0,SEEK_END);
	ULONG fileSize = ftell(fp);
	fseek(fp,2,SEEK_SET);
	
	WCHAR* fileBuff = new WCHAR[fileSize/2];
	memset(fileBuff,0,fileSize);

	fread(fileBuff,fileSize - 2,1,fp);

	CString strFirstName;
	CDataBaseTableFirstName TablefirstName;
	for(int i = 0;i<(fileSize/2) - 1;i++)
	{
		if(fileBuff[i] == ' ' || fileBuff[i] == '、'
		|| fileBuff[i] == '\r' || fileBuff[i] == '\n')
		{
			if(!strFirstName.IsEmpty())
			{
				
				//AfxMessageBox(strFirstName);
				InsertNewFirstName(strFirstName);
			}
			strFirstName.Empty();

		}
		else
		{
			strFirstName += fileBuff[i];
		}
	}


	delete fileBuff;
}


void CDlgDatabaseNameEdit::OnBnClickedButtonLastNameImport()
{
	// TODO: Add your control notification handler code here
	CString FilePathName;  
	CFileDialog dlg(TRUE, _T( "txt" ), _T( "*.txt" ), OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, _T("txt Files (*.txt)|*.txt||"));///TRUE为OPEN对话框，FALSE为SAVE AS对话框  
	if(dlg.DoModal()!=IDOK)  
		return;
	FilePathName=dlg.GetPathName();

	FILE* fp = _tfopen(FilePathName,_T("rb"));
	unsigned char szbuf[2] = {0};
	fread(szbuf,2,1,fp);
	if(szbuf[0] != 0xFF || szbuf[1] != 0xFE)
	{
		return;
	}
	fseek(fp,0,SEEK_END);
	ULONG fileSize = ftell(fp);
	fseek(fp,2,SEEK_SET);

	WCHAR* fileBuff = new WCHAR[fileSize/2];
	memset(fileBuff,0,fileSize);

	fread(fileBuff,fileSize - 2,1,fp);

	CString strFirstName;
	CDatabaseTableLastName TableLastName;

	WCHAR maxChar = 0x9fa5;
	WCHAR minChar = 0x4e00;
	for(int i = 0;i<(fileSize/2) - 1;i++)
	{
		if(fileBuff[i] > maxChar || fileBuff[i] < minChar)
		{
			if(!strFirstName.IsEmpty())
			{
				//TableLastName.Insert(strFirstName,m_nLastNameType,m_nSex);
				InsertNewLastName(strFirstName);
				//AfxMessageBox(strFirstName);
			}
			strFirstName.Empty();

		}
		else
		{
			strFirstName += fileBuff[i];
		}
	}


	delete fileBuff;
}

void CDlgDatabaseNameEdit::InsertNewFirstName(CString strFirstName)
{
	if(m_tableFirstName.Find(_T("FirstName"),strFirstName).size() == 0)
		m_tableFirstName.Insert(strFirstName,m_nFirstNameType);
}

void CDlgDatabaseNameEdit::InsertNewLastName(CString strLastName)
{
	if(m_tableLastName.Find(_T("LastName"),strLastName).size() == 0)
		m_tableLastName.Insert(strLastName,m_nLastNameType,m_nSex);
}


void CDlgDatabaseNameEdit::OnBnClickedRadioFirstNameChina()
{
	// TODO: Add your control notification handler code here
	m_nFirstNameType = 0;
}


void CDlgDatabaseNameEdit::OnBnClickedRadioFirstNameEng()
{
	// TODO: Add your control notification handler code here
	m_nFirstNameType = 1;
}


void CDlgDatabaseNameEdit::OnBnClickedRadioFirstNameJan()
{
	// TODO: Add your control notification handler code here
	m_nFirstNameType = 2;
}


void CDlgDatabaseNameEdit::OnBnClickedRadioLastNameCha()
{
	// TODO: Add your control notification handler code here
	m_nLastNameType = 0;
}


void CDlgDatabaseNameEdit::OnBnClickedRadioLastNameEng()
{
	// TODO: Add your control notification handler code here
	m_nLastNameType = 1;
}


void CDlgDatabaseNameEdit::OnBnClickedRadioLastNameJan()
{
	// TODO: Add your control notification handler code here
	m_nLastNameType = 2;
}


void CDlgDatabaseNameEdit::OnBnClickedRadioBoy()
{
	// TODO: Add your control notification handler code here
	m_nSex = 0;
}


void CDlgDatabaseNameEdit::OnBnClickedRadioGirl()
{
	// TODO: Add your control notification handler code here
	m_nSex = 1;
}


void CDlgDatabaseNameEdit::OnBnClickedRadioSexMid()
{
	// TODO: Add your control notification handler code here
	m_nSex = 2;
}

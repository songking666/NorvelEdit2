// DlgDatabaseEditCommWord.cpp : implementation file
//

#include "stdafx.h"
#include "NorvelEdit.h"
#include "DlgDatabaseEditCommWord.h"
#include "afxdialogex.h"


// CDlgDatabaseEditCommWord dialog

IMPLEMENT_DYNAMIC(CDlgDatabaseEditCommWord, CDialogEx)

CDlgDatabaseEditCommWord::CDlgDatabaseEditCommWord(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgDatabaseEditCommWord::IDD, pParent)
{

}

CDlgDatabaseEditCommWord::~CDlgDatabaseEditCommWord()
{
}

void CDlgDatabaseEditCommWord::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_COMM_WORD, m_edtWord);
}


BEGIN_MESSAGE_MAP(CDlgDatabaseEditCommWord, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDlgDatabaseEditCommWord::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_IMPORT, &CDlgDatabaseEditCommWord::OnBnClickedButtonImport)
END_MESSAGE_MAP()


// CDlgDatabaseEditCommWord message handlers


void CDlgDatabaseEditCommWord::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//CDialogEx::OnOK();
	WCHAR strBuff[2] = {0};
	m_edtWord.GetWindowText(strBuff,2);
	if(strBuff[0] == 0)
	{
		AfxMessageBox(_T("数据不能为空！"));
		return;
	}
	if(!m_tableWord.Insert(strBuff[0]))
		AfxMessageBox(_T("插入数据失败！"));
}


void CDlgDatabaseEditCommWord::OnBnClickedButtonImport()
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
		AfxMessageBox(_T("不是unicode文件"));
		return;
	}
	fseek(fp,0,SEEK_END);
	ULONG fileSize = ftell(fp);
	fseek(fp,2,SEEK_SET);

	WCHAR* fileBuff = new WCHAR[fileSize/2];
	memset(fileBuff,0,fileSize);

	fread(fileBuff,fileSize - 2,1,fp);


	WCHAR maxChar = 0x9fa5;
	WCHAR minChar = 0x4e00;
	for(int i = 0;i<(fileSize/2) - 1;i++)
	{
		if(fileBuff[i] < maxChar || fileBuff[i] > minChar)
		{
			InsertCommWord(fileBuff[i]);
		}
	}


	delete fileBuff;
}

void CDlgDatabaseEditCommWord::InsertCommWord( WCHAR OneWord )
{
	if(!m_tableWord.Find(OneWord))
		m_tableWord.Insert(OneWord);
}

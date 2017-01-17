// DlgStep1.cpp : implementation file
//

#include "stdafx.h"
#include "NorvelEdit.h"
#include "DlgStep1.h"
#include "afxdialogex.h"
#include "DatabaseTableCommonWord.h"


// CDlgStep1 dialog

IMPLEMENT_DYNAMIC(CDlgStep1, CPropertyPage)

CDlgStep1::CDlgStep1()
	: CPropertyPage(CDlgStep1::IDD)
{

}

CDlgStep1::~CDlgStep1()
{
}

void CDlgStep1::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_BOOK_NAME, m_edtBookName);
	DDX_Control(pDX, IDC_COMBO_THEME, m_comboTheme);
	DDX_Control(pDX, IDC_STATIC_THEME_CONTENT, m_staticTheme);
	DDX_Control(pDX, IDC_STATIC_DECADE_CONTENT, m_staticDecade);
	DDX_Control(pDX, IDC_COMBO_DECADE, m_combDecade);
	DDX_Control(pDX, IDC_COMBO_MARK, m_combMark);
}


BEGIN_MESSAGE_MAP(CDlgStep1, CPropertyPage)
	ON_CBN_SELCHANGE(IDC_COMBO_THEME, &CDlgStep1::OnCbnSelchangeComboTheme)
	ON_CBN_SELCHANGE(IDC_COMBO_DECADE, &CDlgStep1::OnCbnSelchangeComboDecade)
	ON_BN_CLICKED(IDC_BUTTON_RANDOM, &CDlgStep1::OnBnClickedButtonRandom)
END_MESSAGE_MAP()


// CDlgStep1 message handlers


BOOL CDlgStep1::OnSetActive()
{
	// TODO: Add your specialized code here and/or call the base class
	CPropertySheet *pSheet=(CPropertySheet *)GetParent();
	ASSERT_KINDOF(CPropertySheet,pSheet);
	pSheet->SetWizardButtons(PSWIZB_NEXT|PSWIZB_BACK); 
	return CPropertyPage::OnSetActive();
}

CString CDlgStep1::GetBookName()
{
	
	
	return m_strBookName;
}


LRESULT CDlgStep1::OnWizardNext()
{
	// TODO: Add your specialized code here and/or call the base class
	m_edtBookName.GetWindowTextW(m_strBookName);
	if(m_strBookName.IsEmpty())
	{
		AfxMessageBox(_T("书名一定要写"));
		return 1;
	}
	m_nDecadeType = m_combDecade.GetCurSel();
	m_nThemeType = m_comboTheme.GetCurSel();

	return CPropertyPage::OnWizardNext();
}


BOOL CDlgStep1::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CDatabaseTableTheme table_theme;
	m_vectorTheme = table_theme.GetData();

	for(int i = 0;i<m_vectorTheme.size();i++)
	{
		m_comboTheme.AddString(m_vectorTheme[i].strName);
	}
	m_comboTheme.SetCurSel(0);
	if(!m_vectorTheme.empty())
		m_staticTheme.SetWindowText(m_vectorTheme[0].strContent);


	CDatabaseTableDecade table_decade;
	m_vectorDecade = table_decade.GetData();
	for(int i = 0;i<m_vectorDecade.size();i++)
	{
		m_combDecade.AddString(m_vectorDecade[i].strName);
	}
	m_combDecade.SetCurSel(0);
	if(!m_vectorDecade.empty())
		m_staticDecade.SetWindowText(m_vectorDecade[0].strContent);

	m_combMark.AddString(_T("NULL"));
	m_combMark.AddString(_T("传"));
	m_combMark.AddString(_T("记"));
	m_combMark.AddString(_T("传记"));
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CDlgStep1::OnCbnSelchangeComboTheme()
{
	// TODO: 在此添加控件通知处理程序代码
	int cursel = m_comboTheme.GetCurSel();
	if(cursel == -1)
		return ;
	if(m_vectorTheme.empty())
		return;
	m_staticTheme.SetWindowText(m_vectorTheme[cursel].strContent);
}


void CDlgStep1::OnCbnSelchangeComboDecade()
{
	// TODO: 在此添加控件通知处理程序代码
	int cursel = m_combDecade.GetCurSel();
	if(cursel == -1)
		return ;
	if(m_vectorDecade.empty())
		return;
	m_staticDecade.SetWindowText(m_vectorDecade[cursel].strContent);
}


void CDlgStep1::OnBnClickedButtonRandom()
{
	// TODO: Add your control notification handler code here
	srand((unsigned)time(NULL)); 

	CString strTitle = _T("《");
	CDatabaseTableCommonWord commword;
	int nCount = commword.GetCount();
	for (int i=0;i<2;++i) 
	{
		int OneCharPos;
		OneCharPos = rand()%nCount ;
		vectorWord word = commword.Find(OneCharPos);
		if(word.size() != 0)
		{
			strTitle += word[0].strName;
		}
	}
	CString strEndText;
	int ncursel = m_combMark.GetCurSel();
	if(ncursel != -1)
	{
		m_combMark.GetLBText(ncursel,strEndText);
		strTitle += strEndText;
	}
	strTitle += _T("》");
	m_edtBookName.SetWindowText(strTitle);
}

int CDlgStep1::GetDecade()
{
	return m_nDecadeType;
}

int CDlgStep1::GetTheme()
{
	return m_nThemeType;
}

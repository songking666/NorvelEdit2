// WizardSheet.cpp : implementation file
//

#include "stdafx.h"
#include "NorvelEdit.h"
#include "WizardSheet.h"


// CWizardSheet

IMPLEMENT_DYNAMIC(CWizardSheet, CPropertySheet)

CWizardSheet::CWizardSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{

	AddPage(&m_dlgStep1);
	AddPage(&m_dlgStep2);
	AddPage(&m_dlgStep3);
}

CWizardSheet::CWizardSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{

	AddPage(&m_dlgStep1);
	AddPage(&m_dlgStep2);
	AddPage(&m_dlgStep3);
}

CWizardSheet::~CWizardSheet()
{
}


BEGIN_MESSAGE_MAP(CWizardSheet, CPropertySheet)
END_MESSAGE_MAP()

CString CWizardSheet::GetBookName()
{
	CString strBookName = m_dlgStep1.GetBookName();
	return strBookName;
}

RoleProperties CWizardSheet::GetRolePropert()
{
	return m_dlgStep2.GetRoleProper();
}

SceneFormat CWizardSheet::GetSceneFormat()
{
	return m_dlgStep3.GetSceneData();
}

int CWizardSheet::GetTheme()
{
	return m_dlgStep1.GetTheme();
}

int CWizardSheet::GetDecade()
{
	return m_dlgStep1.GetDecade();
}

// CWizardSheet message handlers

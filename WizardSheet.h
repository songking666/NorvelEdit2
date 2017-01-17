#pragma once

#include "DlgStep1.h"
#include "DlgStep2.h"
#include "DlgStep3.h"

// CWizardSheet

class CWizardSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CWizardSheet)

public:
	CWizardSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CWizardSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	virtual ~CWizardSheet();

	CDlgStep1 m_dlgStep1;
	CDlgStep2 m_dlgStep2;
	CDlgStep3 m_dlgStep3;

public:
	CString			GetBookName();
	int				GetTheme();
	int				GetDecade();
	RoleProperties	GetRolePropert();
	SceneFormat		GetSceneFormat();
protected:
	DECLARE_MESSAGE_MAP()
};



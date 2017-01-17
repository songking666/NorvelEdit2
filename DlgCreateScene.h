#pragma once
#include "afxwin.h"
#include "SaveFormat.h"


// CDlgCreateScene dialog

class CDlgCreateScene : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgCreateScene)

public:
	CDlgCreateScene(CWnd* pParent = NULL);   // standard constructor
	CDlgCreateScene(int SceneID = -1,CWnd* pParent = NULL);
	virtual ~CDlgCreateScene();

// Dialog Data
	enum { IDD = IDD_DIALOG_SCENE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	//vector<CString> m_vectorList;
	bool	m_bModify;
	int		m_iModifyID;

	CComboBox m_combCapter;
	CComboBox m_combSenceID;
	CComboBox m_combSenceType;
	CComboBox m_combAddress;
	CComboBox m_combTime;
	
	CComboBox m_combEnviron;
	CComboBox m_combWeather;
	CComboBox m_combTimeUnit;
	CComboBox m_combMainRole;
	CComboBox m_combFace;
	CComboBox m_combCloth;

	CComboBox m_combStatus;
	CComboBox m_combHeart;
	//CComboBox m_combOtherStatus;
	CComboBox m_comGeo;

	CListBox m_listTools;
	CEdit m_edtSceneName;
	CEdit m_edtTimeLen;
	CEdit m_edtOtherPeople;
	CEdit m_edtOtherStatus;
	
	CEdit m_edtEventStart;
	CEdit m_edtEventProgress;
	CEdit m_edtEventEnd;
	
	CComboBox m_combOtherRole;
	
	CListBox m_lsOtherRole;
	SceneFormat	m_SceneFormat;
	

	CString strContentText;
	
	afx_msg void OnBnClickedButtonSceneAutoInput();
	afx_msg void OnBnClickedButtonCreateAddress();
	afx_msg void OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult);

	void AddTableDataToString(CComboBox& combBox,CDatabaseTableBase& table);

	SceneFormat GetSceneFormat();
	afx_msg void OnBnClickedOk();
	
	afx_msg void OnBnClickedButtonSceneAddPeople();
	
	afx_msg void OnBnClickedButtonCreateText();
	
};

/////////////////////////////////////////////////////////////////////////////
// FormatBar.cpp : implementation file
// Download by http://www.codefans.net

#include "stdafx.h"
#include "RichEdit.h"
#include "FormatBar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFormatBar

// Declare const array of font sizes
const static int nFontSizes[] = 
	{8, 9, 10, 11, 12, 14, 16, 18, 20, 22, 24, 26, 28, 36, 48, 72};


CFormatBar::CFormatBar(UINT nID )
{
	nToolbarID = nID;
}

CFormatBar::~CFormatBar()
{
}


BEGIN_MESSAGE_MAP(CFormatBar, CMFCToolBar)
	//{{AFX_MSG_MAP(CFormatBar)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
	ON_CBN_SELENDOK(ID_TOOLBAR_FONT_NAME, OnSelectFontName)
	ON_CBN_SELENDOK(ID_TOOLBAR_FONT_SIZE, OnSelectFontSize)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFormatBar message handlers

int CFormatBar::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CMFCToolBar::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// Load the toolbar

	if( !LoadToolBar( nToolbarID ) )
		return -1;

	// Get the average char width
	CClientDC dc(this);

	// Determine the size required by the font comboboxes
	// We will use the DEFAULT_GUI_FONT
	HGDIOBJ hFont = GetStockObject( DEFAULT_GUI_FONT );
	CFont font;
	font.Attach( hFont );
	dc.SelectObject( font );

	TEXTMETRIC tm;
	dc.GetTextMetrics( &tm );
	int cxChar = tm.tmAveCharWidth;
	int cyChar = tm.tmHeight + tm.tmExternalLeading;


	// Create the Font Name combo
	CRect rect1; 
	GetItemRect( CommandToIndex(ID_TOOLBAR_FONT_NAME), &rect1 );
	rect1.right = rect1.left + (32+2)*cxChar;
	rect1.bottom = rect1.top + 16*cyChar;

	m_cmbFontName.CreateCombo(this,rect1);
	ReplaceButton(ID_TOOLBAR_FONT_NAME,m_cmbFontName);

	//SetButtonInfo( CommandToIndex(ID_TOOLBAR_FONT_NAME), ID_TOOLBAR_FONT_NAME, 
	//	TBBS_SEPARATOR, rect1.Width() );

	CRect rect2;
	// Create Font Size combo
	GetItemRect( CommandToIndex(ID_TOOLBAR_FONT_SIZE), &rect2 );
	rect2.left = rect1.right + 32;
	rect2.right = rect2.left + 8*cxChar;
	rect2.bottom = rect2.top + 16*cyChar;

	SetButtonInfo( CommandToIndex(ID_TOOLBAR_FONT_SIZE), ID_TOOLBAR_FONT_SIZE, 
				TBBS_SEPARATOR, rect2.Width() );


	//if (!m_cmbFontSize.Create(nCreateStyle|CBS_DROPDOWN|WS_HSCROLL, 
	//	rect, this, ID_TOOLBAR_FONT_SIZE))
	//{
	//	TRACE0("Failed to create Font Size combo-box\n");
	//	return -1;
	//}
	m_cmbFontSize.CreateCombo(this,rect2);
	//m_cmbFontSize.GetComboBox()->LimitText(4);

	ReplaceButton(ID_TOOLBAR_FONT_SIZE,m_cmbFontSize);
	// Set the font for the combo boxes to DEFAULT_GUI_FONT
	//m_cmbFontName.GetComboBox()->SetFont(&font);
	//m_cmbFontSize.GetComboBox()->SetFont(&font);

	// Fill the Font names in the Font Name combo
	//::EnumFontFamilies( dc.m_hDC, NULL, (FONTENUMPROC)EnumFontFamProc, 
	//			(LPARAM) this );

	// Fill the Font Size combo
	//CString sSize;
	//int nSizeCount = sizeof(nFontSizes) / sizeof(nFontSizes[0]);
	//for( int i=0; i < nSizeCount; i++ )
	//{
	//	sSize.Format(_T("%d"), nFontSizes[i] );
	//	m_cmbFontSize.GetComboBox()->AddString( sSize );
	//}

	return 0;
}

int CALLBACK CFormatBar::EnumFontFamProc(ENUMLOGFONT *lpelf, NEWTEXTMETRIC *lpntm,
					int nFontType, LPARAM lParam)
{
	CFormatBar* pWnd = (CFormatBar*)lParam;

	// Add the font name to the combo
	//pWnd->m_cmbFontName.AddString(lpelf->elfLogFont.lfFaceName);
	pWnd->m_cmbFontName.GetComboBox()->AddString(lpelf->elfLogFont.lfFaceName);
	return 1;		// 1 to continue enumeration
}

void CFormatBar::OnSelectFontName()
{
	TCHAR szFontName[LF_FACESIZE];
	int nIndex = m_cmbFontName.GetComboBox()->GetCurSel();
	m_cmbFontName.GetComboBox()->GetLBText( nIndex, szFontName );
	;
	//_tcscpy(szFontName,m_cmbFontName.GetComboBox()->GetItem(nIndex));
	
	// If font name is empty - return
	if( szFontName[0] == 0 )
		return;

	CHARNMHDR fh;
	CHARFORMAT& cf=fh.cf;
	fh.hwndFrom = m_hWnd;
	fh.idFrom = GetDlgCtrlID();
	fh.code = FN_SETFORMAT;
	cf.dwMask = CFM_FACE;

	_tcsncpy(cf.szFaceName, szFontName, LF_FACESIZE);	//strncpy

	GetOwner()->SendMessage(WM_NOTIFY,fh.idFrom, (LPARAM)&fh);
}

void CFormatBar::OnSelectFontSize()
{
	TCHAR szSize[5];
	int index = m_cmbFontSize.GetCurSel();
	if( index != CB_ERR )
		m_cmbFontSize.GetComboBox()->GetLBText(index, szSize );
	else
		m_cmbFontSize.GetComboBox()->GetWindowText( szSize, 5 );

	// Get size in Twips
	int nSize = _ttoi( szSize ) * 20;			// atoi for tchar

	if( !nSize )
		return;

	CHARNMHDR fh;
	CHARFORMAT& cf = fh.cf;
	fh.hwndFrom = m_hWnd;
	fh.idFrom = GetDlgCtrlID();
	fh.code = FN_SETFORMAT;

	cf.dwMask = CFM_SIZE;
	cf.yHeight = nSize;

	GetOwner()->SendMessage(WM_NOTIFY, fh.idFrom, (LPARAM)&fh);
}

void CFormatBar::OnUpdateCmdUI(CFrameWnd* pTarget, BOOL bDisableIfNoHndler)
{
	// Take care of the regular toolbar buttons
	CMFCToolBar::OnUpdateCmdUI( pTarget, bDisableIfNoHndler);

	// Don't update the combo boxes if user changing font attribute
	CWnd *pWnd = GetFocus();
	//if( pWnd->m_hWnd == m_cmbFontName.GetComboBox()->GetSafeHwnd() || m_cmbFontSize.GetComboBox()->IsChild(pWnd) )
	//	return;

	// get the current font from the view and update
	CHARNMHDR fh;
	CHARFORMAT& cf = fh.cf;
	fh.hwndFrom = m_hWnd;
	fh.idFrom = GetDlgCtrlID();
	fh.code = FN_GETFORMAT;

	CWnd *pOwnerWnd = GetOwner();
	if( !GetOwner()->SendMessage(WM_NOTIFY, fh.idFrom, (LPARAM)&fh) )
	{
		//TRACE0("The Rich Edit View/Control has to handle the FN_GETFORMAT\n"/
		//	"notification for the Format Bar to work properly\n");
		return;
	}

	// Update the font only if the selection font is different
	TCHAR szName[LF_FACESIZE];
	//m_cmbFontName.GetWindowText( szName, LF_FACESIZE );
	_tcscpy(szName,m_cmbFontName.GetText());
	// the selection must be same font and charset to display correctly
	if ((cf.dwMask & (CFM_FACE|CFM_CHARSET)) != (CFM_FACE|CFM_CHARSET))
		//m_cmbFontName.SetCurSel( -1 );
		m_cmbFontName.GetComboBox()->SetCurSel(-1);
	else if( ::_tcscmp( szName, cf.szFaceName ) != 0 )
	{
		if( m_cmbFontName.GetComboBox()->SelectString( -1, cf.szFaceName ) == CB_ERR )
			m_cmbFontName.GetComboBox()->SetCurSel( -1 );
	}


	// Update the font size
	TCHAR szSize[5];
	m_cmbFontSize.GetComboBox()->GetWindowText( szSize, 5 );
	int nSize = _ttoi( szSize );				// atoi for tchar

	// Update the font size only if selection is different 
	int nSelSize = (cf.dwMask & CFM_SIZE) ? cf.yHeight/20 : 0;
	if( nSize != nSelSize )
	{
		if(cf.dwMask & CFM_SIZE)
		{
			CString strSize;
			strSize.Format(_T("%d"), nSelSize );
			m_cmbFontSize.GetComboBox()->SetWindowText( strSize );
		}
		else
			m_cmbFontSize.GetComboBox()->SetCurSel(-1);
	}
}

BOOL CFormatBar::PreTranslateMessage(MSG* pMsg) 
{
	if (pMsg->message == WM_KEYDOWN)
	{
		NMHDR nm;
		nm.hwndFrom = m_hWnd;
		nm.idFrom = GetDlgCtrlID();
		nm.code = NM_RETURN;
		switch (pMsg->wParam)
		{
		case VK_RETURN:
			// Send change notification
			if(m_cmbFontName.GetComboBox()->IsChild(GetFocus()) )
				OnSelectFontName();
			else if( m_cmbFontSize.GetComboBox()->IsChild(GetFocus()) )
				OnSelectFontSize();
			//Fall through
		case VK_ESCAPE:
			GetOwner()->SendMessage(WM_NOTIFY, nm.idFrom, (LPARAM)&nm);
			return TRUE;
		}
	}
	
	return CMFCToolBar::PreTranslateMessage(pMsg);
}

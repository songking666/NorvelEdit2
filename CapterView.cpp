
#include "stdafx.h"
#include "MainFrm.h"
#include "CapterView.h"
#include "Resource.h"
#include "NorvelEdit.h"
#include "DlgCreateScene.h"

class CClassViewMenuButton : public CMFCToolBarMenuButton
{
	friend class CCapterView;

	DECLARE_SERIAL(CClassViewMenuButton)

public:
	CClassViewMenuButton(HMENU hMenu = NULL) : CMFCToolBarMenuButton((UINT)-1, hMenu, -1)
	{
	}

	virtual void OnDraw(CDC* pDC, const CRect& rect, CMFCToolBarImages* pImages, BOOL bHorz = TRUE,
		BOOL bCustomizeMode = FALSE, BOOL bHighlight = FALSE, BOOL bDrawBorder = TRUE, BOOL bGrayDisabledButtons = TRUE)
	{
		pImages = CMFCToolBar::GetImages();

		CAfxDrawState ds;
		pImages->PrepareDrawImage(ds);

		CMFCToolBarMenuButton::OnDraw(pDC, rect, pImages, bHorz, bCustomizeMode, bHighlight, bDrawBorder, bGrayDisabledButtons);

		pImages->EndDrawImage(ds);
	}
};

IMPLEMENT_SERIAL(CClassViewMenuButton, CMFCToolBarMenuButton, 1)

//////////////////////////////////////////////////////////////////////
// 构造/析构
//////////////////////////////////////////////////////////////////////

CCapterView::CCapterView()
{
	m_hRoot = NULL;
	m_nCurrSort = ID_SORTING_GROUPBYTYPE;
}

CCapterView::~CCapterView()
{
}

BEGIN_MESSAGE_MAP(CCapterView, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_CLASS_ADD_MEMBER_FUNCTION, OnClassAddMemberFunction)
	ON_COMMAND(ID_CLASS_ADD_MEMBER_VARIABLE, OnClassAddMemberVariable)
	ON_COMMAND(ID_CLASS_DEFINITION, OnClassDefinition)
	ON_COMMAND(ID_CLASS_PROPERTIES, OnClassProperties)
	ON_COMMAND(ID_CREATE_NEW_CAPTER, OnCreateNewCapter)
	ON_WM_PAINT()
	ON_WM_SETFOCUS()
	ON_COMMAND_RANGE(ID_SORTING_GROUPBYTYPE, ID_SORTING_SORTBYACCESS, OnSort)
	ON_UPDATE_COMMAND_UI_RANGE(ID_SORTING_GROUPBYTYPE, ID_SORTING_SORTBYACCESS, OnUpdateSort)
	ON_COMMAND(ID_MENU_CHAPTER_NEW, &CCapterView::OnMenuChapterNew)
	ON_COMMAND(ID_MENU_CHAPTER_INSERT_SCENE, &CCapterView::OnMenuChapterInsertScene)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClassView 消息处理程序

int CCapterView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	CRect rectDummy;
	rectDummy.SetRectEmpty();

	// 创建视图:
	const DWORD dwViewStyle = WS_CHILD | WS_VISIBLE | TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS | WS_CLIPSIBLINGS | WS_CLIPCHILDREN |TVS_EDITLABELS;

	if (!m_wndChapterView.Create(dwViewStyle, rectDummy, this, 2))
	{
		TRACE0("未能创建类视图\n");
		return -1;      // 未能创建
	}

	// 加载图像:
	m_wndToolBar.Create(this, AFX_DEFAULT_TOOLBAR_STYLE, IDR_SORT);
	m_wndToolBar.LoadToolBar(IDR_SORT, 0, 0, TRUE /* 已锁定*/);

	OnChangeVisualStyle();

	m_wndToolBar.SetPaneStyle(m_wndToolBar.GetPaneStyle() | CBRS_TOOLTIPS | CBRS_FLYBY);
	m_wndToolBar.SetPaneStyle(m_wndToolBar.GetPaneStyle() & ~(CBRS_GRIPPER | CBRS_SIZE_DYNAMIC | CBRS_BORDER_TOP | CBRS_BORDER_BOTTOM | CBRS_BORDER_LEFT | CBRS_BORDER_RIGHT));

	m_wndToolBar.SetOwner(this);

	// 所有命令将通过此控件路由，而不是通过主框架路由:
	m_wndToolBar.SetRouteCommandsViaFrame(FALSE);

	CMenu menuSort;
	menuSort.LoadMenu(IDR_POPUP_SORT);

	m_wndToolBar.ReplaceButton(ID_SORT_MENU, CClassViewMenuButton(menuSort.GetSubMenu(0)->GetSafeHmenu()));

	CClassViewMenuButton* pButton =  DYNAMIC_DOWNCAST(CClassViewMenuButton, m_wndToolBar.GetButton(0));

	if (pButton != NULL)
	{
		pButton->m_bText = FALSE;
		pButton->m_bImage = TRUE;
		pButton->SetImage(GetCmdMgr()->GetCmdImage(m_nCurrSort));
		pButton->SetMessageWnd(this);
	}

	// 填入一些静态树视图数据(此处只需填入虚拟代码，而不是复杂的数据)
	//FillClassView();

	return 0;
}

void CCapterView::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);
	AdjustLayout();
}

void CCapterView::FillClassView()
{
	HTREEITEM hRoot = m_wndChapterView.InsertItem(_T("FakeApp 类"), 0, 0);
	m_wndChapterView.SetItemState(hRoot, TVIS_BOLD, TVIS_BOLD);

	HTREEITEM hClass = m_wndChapterView.InsertItem(_T("CFakeAboutDlg"), 1, 1, hRoot);
	m_wndChapterView.InsertItem(_T("CFakeAboutDlg()"), 3, 3, hClass);

	m_wndChapterView.Expand(hRoot, TVE_EXPAND);

	hClass = m_wndChapterView.InsertItem(_T("CFakeApp"), 1, 1, hRoot);
	m_wndChapterView.InsertItem(_T("CFakeApp()"), 3, 3, hClass);
	m_wndChapterView.InsertItem(_T("InitInstance()"), 3, 3, hClass);
	m_wndChapterView.InsertItem(_T("OnAppAbout()"), 3, 3, hClass);

	hClass = m_wndChapterView.InsertItem(_T("CFakeAppDoc"), 1, 1, hRoot);
	m_wndChapterView.InsertItem(_T("CFakeAppDoc()"), 4, 4, hClass);
	m_wndChapterView.InsertItem(_T("~CFakeAppDoc()"), 3, 3, hClass);
	m_wndChapterView.InsertItem(_T("OnNewDocument()"), 3, 3, hClass);

	hClass = m_wndChapterView.InsertItem(_T("CFakeAppView"), 1, 1, hRoot);
	m_wndChapterView.InsertItem(_T("CFakeAppView()"), 4, 4, hClass);
	m_wndChapterView.InsertItem(_T("~CFakeAppView()"), 3, 3, hClass);
	m_wndChapterView.InsertItem(_T("GetDocument()"), 3, 3, hClass);
	m_wndChapterView.Expand(hClass, TVE_EXPAND);

	hClass = m_wndChapterView.InsertItem(_T("CFakeAppFrame"), 1, 1, hRoot);
	m_wndChapterView.InsertItem(_T("CFakeAppFrame()"), 3, 3, hClass);
	m_wndChapterView.InsertItem(_T("~CFakeAppFrame()"), 3, 3, hClass);
	m_wndChapterView.InsertItem(_T("m_wndMenuBar"), 6, 6, hClass);
	m_wndChapterView.InsertItem(_T("m_wndToolBar"), 6, 6, hClass);
	m_wndChapterView.InsertItem(_T("m_wndStatusBar"), 6, 6, hClass);

	hClass = m_wndChapterView.InsertItem(_T("Globals"), 2, 2, hRoot);
	m_wndChapterView.InsertItem(_T("theFakeApp"), 5, 5, hClass);
	m_wndChapterView.Expand(hClass, TVE_EXPAND);
}

void CCapterView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	CTreeCtrl* pWndTree = (CTreeCtrl*) &m_wndChapterView;
	ASSERT_VALID(pWndTree);

	if (pWnd != pWndTree)
	{
		CDockablePane::OnContextMenu(pWnd, point);
		return;
	}

	if (point != CPoint(-1, -1))
	{
		// 选择已单击的项:
		CPoint ptTree = point;
		pWndTree->ScreenToClient(&ptTree);

		UINT flags = 0;
		HTREEITEM hTreeItem = pWndTree->HitTest(ptTree, &flags);
		if (hTreeItem != NULL)
		{
			pWndTree->SelectItem(hTreeItem);
		}
	}

	CPoint pt;
	GetCursorPos(&pt);

	CMenu m_NewMenu;
	m_NewMenu.LoadMenu(IDR_MENU_CHAPTER);//顶级菜单,事先在资源管理器中建好

	CMenu* pM = m_NewMenu.GetSubMenu(0);//一级下拉菜单

	//CMenu *pSubmenu=pM->GetSubMenu(pM->GetMenuItemCount()-1);//二级子菜单
	//ASSERT(pSubmenu);

	int SelectID = pM->TrackPopupMenu(TPM_LEFTALIGN|TPM_LEFTBUTTON|TPM_VERTICAL//|
		/*TPM_RETURNCMD*/, pt.x, pt.y, this);
}

void CCapterView::AdjustLayout()
{
	if (GetSafeHwnd() == NULL)
	{
		return;
	}

	CRect rectClient;
	GetClientRect(rectClient);

	int cyTlb = m_wndToolBar.CalcFixedLayout(FALSE, TRUE).cy;

	m_wndToolBar.SetWindowPos(NULL, rectClient.left, rectClient.top, rectClient.Width(), cyTlb, SWP_NOACTIVATE | SWP_NOZORDER);
	m_wndChapterView.SetWindowPos(NULL, rectClient.left + 1, rectClient.top + cyTlb + 1, rectClient.Width() - 2, rectClient.Height() - cyTlb - 2, SWP_NOACTIVATE | SWP_NOZORDER);
}

BOOL CCapterView::PreTranslateMessage(MSG* pMsg)
{
	return CDockablePane::PreTranslateMessage(pMsg);
}

void CCapterView::OnSort(UINT id)
{
	if (m_nCurrSort == id)
	{
		return;
	}

	m_nCurrSort = id;

	CClassViewMenuButton* pButton =  DYNAMIC_DOWNCAST(CClassViewMenuButton, m_wndToolBar.GetButton(0));

	if (pButton != NULL)
	{
		pButton->SetImage(GetCmdMgr()->GetCmdImage(id));
		m_wndToolBar.Invalidate();
		m_wndToolBar.UpdateWindow();
	}
}

void CCapterView::OnUpdateSort(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(pCmdUI->m_nID == m_nCurrSort);
}

void CCapterView::OnClassAddMemberFunction()
{
	AfxMessageBox(_T("添加成员函数..."));
	m_wndChapterView.InsertItem(_T("CFakeApp()"), 1, 1, m_hRoot);
	m_wndChapterView.InsertItem(_T("InitInstance()"), 1, 1, m_hRoot);
	m_wndChapterView.InsertItem(_T("OnAppAbout()"), 1, 1, m_hRoot);

}

void CCapterView::OnClassAddMemberVariable()
{
	// TODO: 在此处添加命令处理程序代码
}

void CCapterView::OnClassDefinition()
{
	// TODO: 在此处添加命令处理程序代码
}

void CCapterView::OnClassProperties()
{
	// TODO: 在此处添加命令处理程序代码
}

void CCapterView::OnCreateNewCapter()
{
	//AfxMessageBox(_T("新建文件夹..."));
	int a = m_wndChapterView.GetCount();

	CNorvelEditDoc *pDoc = (CNorvelEditDoc*)((CFrameWndEx *)AfxGetMainWnd())->GetActiveDocument();

	if(a == 0)
	{
		SetBookTitle(_T("未命名书籍"));
		pDoc->m_SaveFormat.m_strBookname = _T("未命名书籍");
	}
	else
	{
		CString strCapterCount;
		strCapterCount.Format(_T("第%d章"),a);
		m_wndChapterView.InsertItem(strCapterCount, 1, 1, m_hRoot);
		m_wndChapterView.Expand(m_hRoot,TVE_EXPAND);

		STRUCT_CHAPTER tempChapter;
		tempChapter.strName = strCapterCount;
		pDoc->m_SaveFormat.m_vectorCapter.push_back(tempChapter);
	}
	
}

void CCapterView::OnPaint()
{
	CPaintDC dc(this); // 用于绘制的设备上下文

	CRect rectTree;
	m_wndChapterView.GetWindowRect(rectTree);
	ScreenToClient(rectTree);

	rectTree.InflateRect(1, 1);
	dc.Draw3dRect(rectTree, ::GetSysColor(COLOR_3DSHADOW), ::GetSysColor(COLOR_3DSHADOW));
}

void CCapterView::OnSetFocus(CWnd* pOldWnd)
{
	CDockablePane::OnSetFocus(pOldWnd);

	m_wndChapterView.SetFocus();
}

void CCapterView::OnChangeVisualStyle()
{
	m_ClassViewImages.DeleteImageList();

	UINT uiBmpId = theApp.m_bHiColorIcons ? IDB_CLASS_VIEW_24 : IDB_CLASS_VIEW;

	CBitmap bmp;
	if (!bmp.LoadBitmap(uiBmpId))
	{
		TRACE(_T("无法加载位图: %x\n"), uiBmpId);
		ASSERT(FALSE);
		return;
	}

	BITMAP bmpObj;
	bmp.GetBitmap(&bmpObj);

	UINT nFlags = ILC_MASK;

	nFlags |= (theApp.m_bHiColorIcons) ? ILC_COLOR24 : ILC_COLOR4;

	m_ClassViewImages.Create(16, bmpObj.bmHeight, nFlags, 0, 0);
	m_ClassViewImages.Add(&bmp, RGB(255, 0, 0));

	m_wndChapterView.SetImageList(&m_ClassViewImages, TVSIL_NORMAL);

	m_wndToolBar.CleanUpLockedImages();
	m_wndToolBar.LoadBitmap(theApp.m_bHiColorIcons ? IDB_SORT_24 : IDR_SORT, 0, 0, TRUE /* 锁定*/);
}

void CCapterView::SetBookTitle( CString strBookName )
{
	if(m_hRoot != NULL)
	{
		m_wndChapterView.DeleteAllItems();
	}
	
	m_hRoot = m_wndChapterView.InsertItem(strBookName, 0, 0);
	m_wndChapterView.SetItemState(m_hRoot, TVIS_BOLD, TVIS_BOLD);

	m_wndChapterView.Expand(m_hRoot, TVE_EXPAND);
}

void CCapterView::GetTreeItemText( vector<CString>& vectorRet)
{
	  HTREEITEM hItem = m_wndChapterView.GetRootItem();  //遍历树查找edit1节点  
	  if(hItem == NULL)
		  return;

	  HTREEITEM hChildItem = m_wndChapterView.GetChildItem(hItem);
	  while (hChildItem != NULL)  
	  {   
		  CString tempText = m_wndChapterView.GetItemText(hChildItem);   
		  vectorRet.push_back(tempText);
		  hChildItem = m_wndChapterView.GetNextSiblingItem(hChildItem);  
	  }  //未找到eidt1节点  
	 
	
	//strRet = m_wndClassView.GetItemText(nID);
}

void CCapterView::ReadDataFromFile()
{
	if(m_hRoot != NULL)
	{
		m_wndChapterView.DeleteAllItems();
	}

	CNorvelEditDoc *pDoc = (CNorvelEditDoc*)((CFrameWndEx *)AfxGetMainWnd())->GetActiveDocument();

	SetBookTitle(pDoc->m_SaveFormat.m_strBookname);
	
	for(int i=0;i<pDoc->m_SaveFormat.m_vectorCapter.size();i++)
	{
		m_wndChapterView.InsertItem(pDoc->m_SaveFormat.m_vectorCapter[i].strName, 1, 1, m_hRoot);
		m_wndChapterView.Expand(m_hRoot,TVE_EXPAND);
	}
}


void CCapterView::OnMenuChapterNew()
{
	// TODO: Add your command handler code here
	OnCreateNewCapter();
}


void CCapterView::OnMenuChapterInsertScene()
{
	// TODO: Add your command handler code here
	//AfxMessageBox(_T("插入场景"));
	//CDlgCreateScene	dlg;
	//if(dlg.DoModal() == IDOK)
	//	return;
	SendMessage(WM_COMMAND,ID_MENU_SENCE);
}

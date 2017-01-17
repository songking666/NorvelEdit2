
// NorvelEditView.cpp : CNorvelEditView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "NorvelEdit.h"
#endif

#include "NorvelEditDoc.h"
#include "NorvelEditView.h"
#include "DlgInsertStatement.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNorvelEditView

IMPLEMENT_DYNCREATE(CNorvelEditView, CRichEditView)

BEGIN_MESSAGE_MAP(CNorvelEditView, CRichEditView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CNorvelEditView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_MENU_FONT_SET, &CNorvelEditView::OnMenuFontSet)

	ON_COMMAND(ID_EDIT_CUT, &CNorvelEditView::OnEditCut)
	ON_COMMAND(ID_EDIT_COPY, &CNorvelEditView::OnEditCopy)
	ON_COMMAND(ID_EDIT_PASTE, &CNorvelEditView::OnEditPaste)
	ON_COMMAND(ID_EDIT_SELECT_ALL, &CNorvelEditView::OnEditSelectAll)
	ON_COMMAND_RANGE(ID_MENU_FIRST,ID_MENU_FIRST+g_Global.m_vectorTable.size(),OnPopMenuFirstID)
	ON_COMMAND(ID_FILE_SAVE, &CNorvelEditView::OnFileSave)
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CNorvelEditView 构造/析构

CNorvelEditView::CNorvelEditView()
{
	// TODO: 在此处添加构造代码
	m_bChange = false;
}

CNorvelEditView::~CNorvelEditView()
{
}

BOOL CNorvelEditView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	BOOL bPreCreated = CRichEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// 启用换行

	return bPreCreated;
}


// CNorvelEditView 打印


void CNorvelEditView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CNorvelEditView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认 CRichEditView 准备
	return CRichEditView::OnPreparePrinting(pInfo);
}

void CNorvelEditView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// 默认 CRichEditView 开始打印
	CRichEditView::OnBeginPrinting(pDC, pInfo);
}

void CNorvelEditView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// 默认 CRichEditView 结束打印
	CRichEditView::OnEndPrinting(pDC, pInfo);
}

void CNorvelEditView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CNorvelEditView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	CPoint pt;
	GetCursorPos(&pt);

	CMenu m_NewMenu;
	m_NewMenu.LoadMenu(IDR_POPUP_EDIT);//顶级菜单,事先在资源管理器中建好

	CMenu* pM = m_NewMenu.GetSubMenu(0);//一级下拉菜单

	CMenu *pSubmenu=pM->GetSubMenu(pM->GetMenuItemCount()-1);//二级子菜单
	ASSERT(pSubmenu);

	UINT nEnable = MF_BYPOSITION|MF_STRING|MF_ENABLED;
	for(int i = 0;i<g_Global.m_vectorTable.size();i++)
	{
		pSubmenu->InsertMenu(pSubmenu->GetMenuItemCount()-1, nEnable,(UINT_PTR)(ID_MENU_FIRST+i),g_Global.m_vectorTable[i].strContent);
	}

	int SelectID = pM->TrackPopupMenu(TPM_LEFTALIGN|TPM_LEFTBUTTON|TPM_VERTICAL//|
		/*TPM_RETURNCMD*/, pt.x, pt.y, this);

	//theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CNorvelEditView 诊断

#ifdef _DEBUG
void CNorvelEditView::AssertValid() const
{
	CRichEditView::AssertValid();
}

void CNorvelEditView::Dump(CDumpContext& dc) const
{
	CRichEditView::Dump(dc);
}

CNorvelEditDoc* CNorvelEditView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNorvelEditDoc)));
	return (CNorvelEditDoc*)m_pDocument;
}
#endif //_DEBUG


// CNorvelEditView 消息处理程序


void CNorvelEditView::OnMenuFontSet()
{
	// TODO: Add your command handler code here
	CString strFontName;    // 字体名称   
	LOGFONT lf;             // LOGFONT变量   

	// 将lf所有字节清零   
	memset(&lf, 0, sizeof(LOGFONT));   

	// 将lf中的元素字体名设为“宋体”   
	_tcscpy_s(lf.lfFaceName, LF_FACESIZE, _T("宋体"));   

	
	// 构造字体对话框，初始选择字体名为“宋体”   
	CFontDialog fontDlg(&lf);   

	if (IDOK == fontDlg.DoModal())     // 显示字体对话框   
	{   
		// 如果m_font已经关联了一个字体资源对象，则释放它   
		if (m_Font.m_hObject)   
		{   
			m_Font.DeleteObject();   
		}   
		// 使用选定字体的LOGFONT创建新的字体   
		m_Font.CreateFontIndirect(fontDlg.m_cf.lpLogFont);   
		// 获取编辑框IDC_FONT_EDIT的CWnd指针，并设置其字体   
		SetFont(&m_Font);      
	}   
}



void CNorvelEditView::OnEditCut()
{
	// TODO: 在此添加命令处理程序代码
	CRichEditView::OnEditCut();
}


void CNorvelEditView::OnEditCopy()
{
	// TODO: 在此添加命令处理程序代码
	CRichEditView::OnEditCopy();
}


void CNorvelEditView::OnEditPaste()
{
	// TODO: 在此添加命令处理程序代码
	CRichEditView::OnEditPaste();
}


void CNorvelEditView::OnEditSelectAll()
{
	// TODO: 在此添加命令处理程序代码
	CRichEditView::OnEditSelectAll();
}

void CNorvelEditView::OnPopMenuFirstID(UINT id)
{
	int a = id - ID_MENU_FIRST;

	CDlgInsertStatement dlg(g_Global.m_vectorTable[a].strName);
	if(dlg.DoModal() != IDOK)
		return;
	
	GetRichEditCtrl().ReplaceSel(dlg.GetString(),TRUE);

	
	//AfxMessageBox(g_Global.m_vectorTable[a].strName);
}

void CNorvelEditView::DisplayTextByTitle( CString strTitle )
{
	
	//GetDocument()->OnSaveDocument(GetDocument()->m_SaveFormat.m_strBookname);
	if(strTitle.IsEmpty())
		return;

	CNorvelEditDoc* doc = GetDocument();
	if(g_Global.m_strTreeSelectItem.IsEmpty())
	{
		g_Global.m_strTreeSelectItem = strTitle;
	}
	else
	{
		if(m_bChange)
		{
			for(int i = 0;i<doc->m_SaveFormat.m_vectorCapter.size();i++)
			{
				if(doc->m_SaveFormat.m_vectorCapter[i].strName == g_Global.m_strTreeSelectItem)
				{
					GetWindowTextW(doc->m_SaveFormat.m_vectorCapter[i].strData);
					break;
				}
			}
		}
	}

	bool bfind = false;
	for(int i = 0;i<doc->m_SaveFormat.m_vectorCapter.size();i++)
	{
		if(doc->m_SaveFormat.m_vectorCapter[i].strName == strTitle)
		{
			bfind = true;
			SetWindowTextW(doc->m_SaveFormat.m_vectorCapter[i].strData);
			break;
		}
	}
	if(!bfind)
	{
		SetWindowTextW(NULL);
	}
	m_bChange = false;
	g_Global.m_strTreeSelectItem = strTitle;
}


void CNorvelEditView::OnFileSave()
{
	// TODO: 在此添加命令处理程序代码
	for(int i = 0;i<GetDocument()->m_SaveFormat.m_vectorCapter.size();i++)
	{
		if(GetDocument()->m_SaveFormat.m_vectorCapter[i].strName == g_Global.m_strTreeSelectItem)
		{
			GetWindowTextW(GetDocument()->m_SaveFormat.m_vectorCapter[i].strData);
			break;
		}
	}
	CString strFullPath = g_Global.GetExePath();
	
	if(GetDocument()->m_SaveFormat.m_strBookname.IsEmpty())
	{
		AfxMessageBox(_T("书名都没起，保存个毛啊！"));
		return;
	}

	strFullPath += GetDocument()->m_SaveFormat.m_strBookname;

	CreateDirectory(strFullPath,NULL);

	strFullPath += _T("\\");
	strFullPath += GetDocument()->m_SaveFormat.m_strBookname;
	strFullPath += _T(".nov");
	GetDocument()->OnSaveDocument(strFullPath);
}


void CNorvelEditView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	m_bChange = true;
	CRichEditView::OnChar(nChar, nRepCnt, nFlags);
}

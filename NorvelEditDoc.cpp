
// NorvelEditDoc.cpp : CNorvelEditDoc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "NorvelEdit.h"
#endif

#include "NorvelEditDoc.h"

#include <propkey.h>
#include "WizardSheet.h"

#include "MainFrm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CNorvelEditDoc

IMPLEMENT_DYNCREATE(CNorvelEditDoc, CDocument)

BEGIN_MESSAGE_MAP(CNorvelEditDoc, CDocument)
END_MESSAGE_MAP()


// CNorvelEditDoc 构造/析构

CNorvelEditDoc::CNorvelEditDoc()
{
	// TODO: 在此添加一次性构造代码

}

CNorvelEditDoc::~CNorvelEditDoc()
{
}

BOOL CNorvelEditDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	if (!m_viewList.IsEmpty())
	{
		reinterpret_cast<CEditView*>(m_viewList.GetHead())->SetWindowText(NULL);
	}

	m_SaveFormat.CreateNew();

	CWizardSheet wsheet(_T("向导"));
	wsheet.SetWizardMode();

	int ret = wsheet.DoModal() ;
	if(ret == 2)
		return TRUE;
	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	m_SaveFormat.m_strBookname = wsheet.GetBookName();
	m_SaveFormat.m_nTheme = wsheet.GetTheme();
	m_SaveFormat.m_nDecade = wsheet.GetDecade();

	CMainFrame * pMainFrm = (CMainFrame*)AfxGetMainWnd();

	pMainFrm->SetBookName(wsheet.GetBookName());
	return TRUE;
}




// CNorvelEditDoc 序列化

void CNorvelEditDoc::Serialize(CArchive& ar)
{
	// CEditView 包含一个处理所有序列化的编辑控件
	//if (!m_viewList.IsEmpty())
	//{
	//	reinterpret_cast<CEditView*>(m_viewList.GetHead())->SerializeRaw(ar);
	//}
	m_SaveFormat.Serialize(ar);

	AfxGetMainWnd()->SendMessage(GLOBAL_MSG_READ_FILE,0,0);
#ifdef SHARED_HANDLERS

	if (m_viewList.IsEmpty() && ar.IsLoading())
	{
		CFile* pFile = ar.GetFile();
		pFile->Seek(0, FILE_BEGIN);
		ULONGLONG nFileSizeBytes = pFile->GetLength();
		ULONGLONG nFileSizeChars = nFileSizeBytes/sizeof(TCHAR);
		LPTSTR lpszText = (LPTSTR)malloc(((size_t)nFileSizeChars + 1) * sizeof(TCHAR));
		if (lpszText != NULL)
		{
			ar.Read(lpszText, (UINT)nFileSizeBytes);
			lpszText[nFileSizeChars] = '\0';
			m_strThumbnailContent = lpszText;
			m_strSearchContent = lpszText;
		}
	}
#endif
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CNorvelEditDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(m_strThumbnailContent, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CNorvelEditDoc::InitializeSearchContent()
{
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 使用整个文本文件作为搜索内容。
	SetSearchContent(m_strSearchContent);
}

void CNorvelEditDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CNorvelEditDoc 诊断

#ifdef _DEBUG
void CNorvelEditDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CNorvelEditDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CNorvelEditDoc 命令

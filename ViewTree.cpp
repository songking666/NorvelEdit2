
#include "stdafx.h"
#include "ViewTree.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CViewTree

CViewTree::CViewTree()
{
}

CViewTree::~CViewTree()
{
}

BEGIN_MESSAGE_MAP(CViewTree, CTreeCtrl)
	ON_NOTIFY_REFLECT(TVN_BEGINLABELEDIT, &CViewTree::OnTvnBeginlabeledit)
	ON_NOTIFY_REFLECT(TVN_ENDLABELEDIT, &CViewTree::OnTvnEndlabeledit)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, &CViewTree::OnTvnSelchanged)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViewTree 消息处理程序

BOOL CViewTree::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
	BOOL bRes = CTreeCtrl::OnNotify(wParam, lParam, pResult);

	NMHDR* pNMHDR = (NMHDR*)lParam;
	ASSERT(pNMHDR != NULL);

	if (pNMHDR && pNMHDR->code == TTN_SHOW && GetToolTips() != NULL)
	{
		GetToolTips()->SetWindowPos(&wndTop, -1, -1, -1, -1, SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOSIZE);
	}

	return bRes;
}


void CViewTree::OnTvnBeginlabeledit(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTVDISPINFO pTVDispInfo = reinterpret_cast<LPNMTVDISPINFO>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void CViewTree::OnTvnEndlabeledit(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTVDISPINFO pTVDispInfo = reinterpret_cast<LPNMTVDISPINFO>(pNMHDR);
	// TODO: Add your control notification handler code here
	 //
	CNorvelEditDoc *pDoc = (CNorvelEditDoc*)((CFrameWndEx *)AfxGetMainWnd())->GetActiveDocument();
	
	CString strRet = pTVDispInfo->item.pszText;

	HTREEITEM selectItem = GetSelectedItem();
	CString strSelect = GetItemText(selectItem);

	if(pDoc->m_SaveFormat.m_strBookname == strSelect)
	{
		pDoc->m_SaveFormat.m_strBookname = strRet;
	}
	else
	{
		for(int i =0;i<pDoc->m_SaveFormat.m_vectorCapter.size();i++)
		{
			if(strSelect == pDoc->m_SaveFormat.m_vectorCapter[i].strName)
			{
				pDoc->m_SaveFormat.m_vectorCapter[i].strName=strRet;
				break;
			}
		}
	}
	
	


	*pResult = TRUE;
}


void CViewTree::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	HTREEITEM ht=GetSelectedItem();
	CString strSelect=GetItemText(ht);
	AfxGetMainWnd()->SendMessage(GLOBAL_MSG_TREE_SELECT_CHANGE,0,WPARAM(&strSelect));
	UpdateData(FALSE);
	*pResult = 0;
}

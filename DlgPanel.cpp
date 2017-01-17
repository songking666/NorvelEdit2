// DlgPanel.cpp : implementation file
//

#include "stdafx.h"
#include "NorvelEdit.h"
#include "DlgPanel.h"
#include "afxdialogex.h"
#include "NorvelEditDoc.h"
#include "DlgCreateScene.h"


// CDlgPanel dialog

IMPLEMENT_DYNAMIC(CDlgPanel, CDialogEx)

CDlgPanel::CDlgPanel(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgPanel::IDD, pParent)
{

}

CDlgPanel::~CDlgPanel()
{
}

void CDlgPanel::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgPanel, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgPanel::OnBnClickedButton1)
	ON_WM_PAINT()
	ON_WM_HSCROLL()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()


// CDlgPanel message handlers


void CDlgPanel::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	AfxMessageBox(_T("test"));
}




void CDlgPanel::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CDialogEx::OnPaint() for painting messages
	
	CRect bkRect;
	GetClientRect(&bkRect);
	//dc.Rectangle(bkRect);
	dc.FillRect(&bkRect,&CBrush(RGB(255,255,255)));
	
	int pos = GetScrollPos(SB_HORZ);
	bkRect.OffsetRect(CPoint(-pos,0));


	for(int i = 0;i<m_vectorScene.size();i++)
	{
		CRect tempRect = m_vectorScene[i].rcDraw;
		tempRect.OffsetRect(CPoint(-pos,0));

		if(tempRect.right < bkRect.left)
			continue;

		if(m_vectorScene[i].bSelect)
			dc.FillRect(tempRect,&CBrush(RGB(128,128,128)));
		else
			dc.Rectangle(tempRect);
		dc.TextOutW(tempRect.left+20,tempRect.top+20,m_vectorScene[i].strText,m_vectorScene[i].strText.GetLength());

		if(tempRect.left > bkRect.right)
			break;
	}
}


BOOL CDlgPanel::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CDlgPanel::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch(nSBCode)
	{
	case SB_ENDSCROLL:
		break;
	case SB_LINELEFT:
		SetScrollPos(SB_HORZ,GetScrollPos(SB_HORZ)-1,TRUE);
		break;
	case SB_LINERIGHT:
		SetScrollPos(SB_HORZ,GetScrollPos(SB_HORZ)+1,TRUE);
		break;
	case SB_PAGELEFT:
		SetScrollPos(SB_HORZ,GetScrollPos(SB_HORZ)-10,TRUE);
		break;
	case SB_PAGERIGHT:
		SetScrollPos(SB_HORZ,GetScrollPos(SB_HORZ)+10,TRUE);
		break;
	case SB_LEFT:
		SetScrollPos(SB_HORZ,GetScrollPos(SB_HORZ)-5,TRUE);
		break;
	case SB_RIGHT:
		SetScrollPos(SB_HORZ,GetScrollPos(SB_HORZ)+5,TRUE);
		break;
	case SB_THUMBPOSITION:
		SetScrollPos(SB_HORZ,nPos,TRUE);
		break;
	case SB_THUMBTRACK:
		SetScrollPos(SB_HORZ,nPos,TRUE);
		break;
	default:
		break;
	}
	Invalidate();
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CDlgPanel::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	UnSelectAll();
	int pos = GetScrollPos(SB_HORZ);

	for(int i = 0;i<m_vectorScene.size();i++)
	{
		CRect rcTemp = m_vectorScene[i].rcDraw;
		rcTemp.OffsetRect(CPoint(-pos,0));
		if(rcTemp.PtInRect(point))
		{
			m_vectorScene[i].bSelect = true;

			CDlgCreateScene dlg(m_vectorScene[i].nTrueID);

			dlg.DoModal();

			break;
		}
	}
	Invalidate();
	CDialogEx::OnLButtonUp(nFlags, point);
}

void CDlgPanel::UnSelectAll()
{
	for(int i = 0;i<m_vectorScene.size();i++)
	{
		if(m_vectorScene[i].bSelect)
		{
			m_vectorScene[i].bSelect = false;
			break;
		}
	}
}

void CDlgPanel::SetSceneList()
{
	m_vectorScene.clear();
	CRect rect;
	GetClientRect(rect);
	int startPosX = 20;
	int startPosY = 20;
	int tempX = startPosX;
	int maxX = 0;

	CNorvelEditDoc *pDoc = (CNorvelEditDoc*)((CFrameWndEx *)AfxGetMainWnd())->GetActiveDocument();

	int selectid = 0;
	for(int i = 0;i<g_Global.m_vectorChapter.size();i++)
	{
		if(g_Global.m_vectorChapter[i] == g_Global.m_strTreeSelectItem)
		{
			selectid = i;
			break;
		}
	}
	
	for(int i = 0;i<pDoc->m_SaveFormat.m_vectorScene.size();i++)
	{
		if(pDoc->m_SaveFormat.m_vectorScene[i].m_nChapterID == selectid)
		{
			StructDrawRect strTemp;
			strTemp.strText = pDoc->m_SaveFormat.m_vectorScene[i].m_strSceneName;
			strTemp.nTrueID = i;

			strTemp.rcDraw = CRect(tempX,startPosY,tempX + 100,startPosY + 100);
			m_vectorScene.push_back(strTemp);
			tempX +=  110;
			maxX = tempX;
			strTemp.bSelect = false;
		}
	}

	SetScrollRange(SB_HORZ,0,maxX);
	Invalidate();
}

// MapCanvas.cpp : 实现文件
//

#include "stdafx.h"
#include "NorvelEdit.h"
#include "MapCanvas.h"
#include "MapMountain.h"


// CMapCanvas

IMPLEMENT_DYNAMIC(CMapCanvas, CWnd)

CMapCanvas::CMapCanvas()
{
	m_nCurDrawType = -1;
	m_bMouseDown = false;
	m_bDispCoor = false;
	m_bDispGrid = false;
}

CMapCanvas::~CMapCanvas()
{
	for(int i = 0;i<m_vtMap.size();i++)
	{
		delete m_vtMap[i];
	}
}


BEGIN_MESSAGE_MAP(CMapCanvas, CWnd)
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_PAINT()
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
END_MESSAGE_MAP()



// CMapCanvas 消息处理程序




void CMapCanvas::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_bMouseDown = false;
	
	CWnd::OnLButtonUp(nFlags, point);
	Invalidate();
}


void CMapCanvas::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_bMouseDown = true;
	m_ptFirst = point;
	if(CheckSelectMap(point))
	{

	}
	else
	{
		switch(m_nCurDrawType)
		{
		case 0:
			{
				CMapMountain* tempMap = new CMapMountain();
				tempMap->Resize(CRect(point.x,point.y,point.x+100,point.y+100));
				m_vtMap.push_back(tempMap);
			}
			break;
		}
	}

	CWnd::OnLButtonDown(nFlags, point);
}


void CMapCanvas::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(m_bMouseDown)
	{
		int noffsetx = point.x - m_ptFirst.x;
		int noffsety = point.y - m_ptFirst.y;

		for(int i = 0;i<m_vtMap.size();i++)
		{
			if(m_vtMap[i]->IsSelected())
			{
				m_vtMap[i]->Move(CPoint(noffsetx,noffsety));
			}
		}
		Invalidate();
		m_ptFirst = point;
	}
	CWnd::OnMouseMove(nFlags, point);
}


void CMapCanvas::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CStatic::OnPaint()
	CRect rc;
	GetClientRect(rc);
	dc.FillRect(rc,&CBrush(RGB(255,255,255)));

	if(m_bDispCoor)
		DrawCoordinate(rc,&dc);

	if(m_bDispGrid)
		DrawGrid(rc,&dc);

	for(int i = 0;i<m_vtMap.size();i++)
	{
		m_vtMap[i]->Draw(&dc);
	}
}

void CMapCanvas::DrawCoordinate( CRect &rc,CDC* pdc )
{
	CPen tempPen;
	LOGPEN logPen = {0};
	logPen.lopnColor = RGB(255,0,0);
	logPen.lopnStyle = PS_SOLID ;
	POINT lineWidht = {3};
	logPen.lopnWidth = lineWidht;
	tempPen.CreatePenIndirect(&logPen);
	pdc->SelectObject(&tempPen);
	pdc->MoveTo(rc.right / 2,0);
	pdc->TextOutW(rc.right / 2,0,_T("北"));

	pdc->LineTo(rc.right / 2,rc.bottom);
	pdc->TextOutW(rc.right / 2,rc.bottom,_T("南"));

	pdc->MoveTo(0,rc.bottom/2);
	pdc->TextOutW(0,rc.bottom/2,_T("西"));
	pdc->LineTo(rc.right,rc.bottom/2);
	pdc->TextOutW(rc.right,rc.bottom/2,_T("东"));
}

void CMapCanvas::DrawGrid( CRect &rc,CDC* pDC )
{
	int width_segment = rc.Width() / 100;
	width_segment++;
	int height_segment = rc.Height() / 100;
	height_segment++;

	CPen tempPen;
	LOGPEN logPen = {0};
	logPen.lopnColor = RGB(0,255,0);
	logPen.lopnStyle = PS_DOT ;
	POINT lineWidht = {1};
	logPen.lopnWidth = lineWidht;

	tempPen.CreatePenIndirect(&logPen);
	pDC->SelectObject(&tempPen);

	for(int i = 0;i<width_segment;i++)
	{
		pDC->MoveTo(100 * i,0);
		pDC->LineTo(100* i,rc.bottom);
	}
	for(int i = 0;i<height_segment;i++)
	{
		pDC->MoveTo(0,100 * i);
		pDC->LineTo(rc.right,100* i);
	}
}

void CMapCanvas::SetDrawType( int nType )
{
	m_nCurDrawType = nType;
}

void CMapCanvas::SetDispCoor( bool bcoor )
{
	m_bDispCoor = bcoor;
}

void CMapCanvas::SetDispGrid( bool bgrid )
{
	m_bDispGrid = bgrid;
}

void CMapCanvas::UnSelectAll()
{
	for(int i = 0;i<m_vtMap.size();i++)
		m_vtMap[i]->SetSelect(false);
}

bool CMapCanvas::CheckSelectMap( CPoint point )
{
	UnSelectAll();
	for(int i = 0;i<m_vtMap.size();i++)
	{
		if(m_vtMap[i]->IsPress(point))
		{
			m_vtMap[i]->SetSelect(true);
			return true;
		}
	}
	return false;
}

void CMapCanvas::OnHScroll( UINT nSBCode, UINT nPos, CScrollBar* pScrollBar )
{
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
	CWnd::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CMapCanvas::OnVScroll( UINT nSBCode, UINT nPos, CScrollBar* pScrollBar )
{
	switch(nSBCode)
	{
	case SB_ENDSCROLL:
		break;
	case SB_LINELEFT:
		SetScrollPos(SB_VERT,GetScrollPos(SB_VERT)-1,TRUE);
		break;
	case SB_LINERIGHT:
		SetScrollPos(SB_VERT,GetScrollPos(SB_VERT)+1,TRUE);
		break;
	case SB_PAGELEFT:
		SetScrollPos(SB_VERT,GetScrollPos(SB_VERT)-10,TRUE);
		break;
	case SB_PAGERIGHT:
		SetScrollPos(SB_VERT,GetScrollPos(SB_VERT)+10,TRUE);
		break;
	case SB_LEFT:
		SetScrollPos(SB_VERT,GetScrollPos(SB_VERT)-5,TRUE);
		break;
	case SB_RIGHT:
		SetScrollPos(SB_VERT,GetScrollPos(SB_VERT)+5,TRUE);
		break;
	case SB_THUMBPOSITION:
		SetScrollPos(SB_VERT,nPos,TRUE);
		break;
	case SB_THUMBTRACK:
		SetScrollPos(SB_VERT,nPos,TRUE);
		break;
	default:
		break;
	}
	Invalidate();
	CWnd::OnVScroll(nSBCode, nPos, pScrollBar);
}

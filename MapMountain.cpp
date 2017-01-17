#include "StdAfx.h"
#include "MapMountain.h"


CMapMountain::CMapMountain(void)
{
	m_Color = 0;
	m_strName = _T("ɽ");
}


CMapMountain::~CMapMountain(void)
{
}

void CMapMountain::Draw( CDC* pDC )
{
	int widthSegment = m_Rc.Width() / 5;

	CPen tempPen;
	LOGPEN logPen = {0};
	logPen.lopnColor = m_Color;
	POINT tempPoint= {1};
	logPen.lopnWidth = tempPoint;
	logPen.lopnStyle = PS_SOLID ;

	tempPen.CreatePenIndirect(&logPen);
	pDC->SelectObject(&tempPen);

	pDC->MoveTo(m_Rc.left,m_Rc.bottom);
	pDC->LineTo(m_Rc.left + widthSegment,m_Rc.top);
	pDC->LineTo(m_Rc.left + (widthSegment * 2),m_Rc.bottom);
	pDC->LineTo(m_Rc.left + (m_Rc.Width() / 2),m_Rc.top);
	pDC->LineTo(m_Rc.left + (widthSegment * 3),m_Rc.bottom);


	pDC->LineTo(m_Rc.left + (widthSegment * 4),m_Rc.top);
	pDC->LineTo(m_Rc.right,m_Rc.bottom);
	pDC->LineTo(m_Rc.left,m_Rc.bottom);
	if(m_bIsSelected)
		CMapBase::DrawMiniRect(pDC);

	if(!m_strName.IsEmpty())
	{
		pDC->TextOutW(m_Rc.left,m_Rc.bottom + 5,m_strName);
	}
}

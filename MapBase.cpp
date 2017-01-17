#include "StdAfx.h"
#include "MapBase.h"


CMapBase::CMapBase(void)
{
	m_bIsSelected = false;
}


CMapBase::~CMapBase(void)
{
}

void CMapBase::DrawMiniRect(CDC* pDC)
{
	if(m_bIsSelected)
	{
		for(int i = 0;i<4;i++)
		{
			pDC->Rectangle(m_rcConner[i]);
		}
	}
	
}

void CMapBase::SetIsSelect( bool isSelect )
{
	m_bIsSelected = isSelect;
}

void CMapBase::Resize( CRect rect )
{
	m_Rc = rect;
	CalConner();
}

void CMapBase::Move( CPoint pos )
{
	m_Rc.OffsetRect(pos);
	CalConner();
}

void CMapBase::SetName( CString strName )
{
	m_strName = strName;
}

void CMapBase::SetColor( COLORREF color )
{
	m_Color = color;
}

void CMapBase::SetSelect( bool isSelect )
{
	m_bIsSelected = isSelect;
}

bool CMapBase::IsPress( CPoint pt )
{
	return m_Rc.PtInRect(pt);
}

bool CMapBase::IsSelected()
{
	return m_bIsSelected;
}

void CMapBase::CalConner()
{
	const int rectside = 10;
	m_rcConner[0] = CRect(m_Rc.left,m_Rc.top,m_Rc.left + rectside,m_Rc.top + rectside);
	m_rcConner[1] = CRect(m_Rc.right - rectside,m_Rc.top,m_Rc.right ,m_Rc.top + rectside);
	m_rcConner[2] = CRect(m_Rc.right - rectside,m_Rc.bottom - rectside,m_Rc.right,m_Rc.bottom);
	m_rcConner[3] = CRect(m_Rc.left,m_Rc.bottom - rectside,m_Rc.left + rectside,m_Rc.bottom);
}

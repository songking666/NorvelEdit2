#pragma once
#include "MapBase.h"


// CMapCanvas
typedef vector<CMapBase* > VectorMap;

class CMapCanvas : public CWnd
{
	DECLARE_DYNAMIC(CMapCanvas)

public:
	CMapCanvas();
	virtual ~CMapCanvas();

protected:
	DECLARE_MESSAGE_MAP()

	VectorMap	m_vtMap;
	int			m_nCurDrawType;
	bool		m_bMouseDown;
	bool		m_bDispCoor;
	bool		m_bDispGrid;

	CPoint		m_ptFirst;
public:


	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

	bool CheckSelectMap( CPoint point ) ;

	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnPaint();

	void DrawCoordinate( CRect &rc,CDC* pdc);
	void DrawGrid(CRect &rc,CDC* pDC);

	void SetDrawType(int nType);
	void SetDispCoor(bool bcoor);
	void SetDispGrid(bool bgrid);
	void UnSelectAll();
};



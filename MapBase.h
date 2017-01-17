#pragma once
class CMapBase
{
public:
	CMapBase(void);
	~CMapBase(void);
protected:
	CRect		m_Rc;
	CRect		m_rcConner[4];

	bool		m_bIsSelected;
	COLORREF	m_Color;
	CString		m_strName;

	void		DrawMiniRect(CDC* pDC);
	void		CalConner();
public:
	void		Resize(CRect rect);
	void		Move(CPoint pos);
	void		SetIsSelect(bool isSelect);
	void		SetName(CString strName);
	void		SetColor(COLORREF color);
	void		SetSelect(bool isSelect);

	bool		IsPress(CPoint pt);
	bool		IsSelected();
	virtual void Draw(CDC* pDC) = 0;
};


#pragma once
#include "mapbase.h"
class CMapMountain :
	public CMapBase
{
public:
	CMapMountain(void);
	~CMapMountain(void);
public:
	void Draw(CDC* pDC);
};


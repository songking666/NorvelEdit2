#include "StdAfx.h"
#include "DatabaseTablePlane.h"


CDatabaseTablePlane::CDatabaseTablePlane(void)
{
	m_strTableName = GLOBAL_TABLE_PLANE;
	CreateTable();
}


CDatabaseTablePlane::~CDatabaseTablePlane(void)
{
	close();
}

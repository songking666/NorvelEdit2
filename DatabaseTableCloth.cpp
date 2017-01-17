#include "StdAfx.h"
#include "DatabaseTableCloth.h"


CDatabaseTableCloth::CDatabaseTableCloth(void)
{
	m_strTableName = GLOBAL_TABLE_CLOTH;
	CreateTable();
}


CDatabaseTableCloth::~CDatabaseTableCloth(void)
{
}

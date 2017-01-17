#include "StdAfx.h"
#include "DatabaseTableThings.h"


CDatabaseTableThings::CDatabaseTableThings(void)
{
	m_strTableName = GLOBAL_TABLE_THINGS;
	CreateTable();
}


CDatabaseTableThings::~CDatabaseTableThings(void)
{
}

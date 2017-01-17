#include "StdAfx.h"
#include "DatabaseTableTimeUnit.h"


CDatabaseTableTimeUnit::CDatabaseTableTimeUnit(void)
{
	m_strTableName = GLOBAL_TABLE_TIME_UNIT;
	CreateTable();
}


CDatabaseTableTimeUnit::~CDatabaseTableTimeUnit(void)
{
}

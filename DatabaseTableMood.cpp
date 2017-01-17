#include "StdAfx.h"
#include "DatabaseTableMood.h"


CDatabaseTableMood::CDatabaseTableMood(void)
{
	m_strTableName = GLOBAL_TABLE_MOOD;
	CreateTable();
}


CDatabaseTableMood::~CDatabaseTableMood(void)
{
}

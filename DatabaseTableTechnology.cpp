#include "StdAfx.h"
#include "DatabaseTableTechnology.h"


CDatabaseTableTechnology::CDatabaseTableTechnology(void)
{
	m_strTableName = GLOBAL_TABLE_TECHNOLOGY;
	CreateTable();
}


CDatabaseTableTechnology::~CDatabaseTableTechnology(void)
{
}

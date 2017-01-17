#include "StdAfx.h"
#include "DatabaseTableGeography.h"


CDatabaseTableGeography::CDatabaseTableGeography(void)
{
	m_strTableName = GLOBAL_TABLE_GEOGRAPHY;
	CreateTable();
}


CDatabaseTableGeography::~CDatabaseTableGeography(void)
{
	close();
}

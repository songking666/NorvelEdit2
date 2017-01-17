#include "StdAfx.h"
#include "DatabaseTableCountry.h"


CDatabaseTableCountry::CDatabaseTableCountry(void)
{
	m_strTableName = GLOBAL_TABLE_COUNTRY;
	CreateTable();
}


CDatabaseTableCountry::~CDatabaseTableCountry(void)
{
}

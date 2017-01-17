#include "StdAfx.h"
#include "DatabaseTableDecade.h"


CDatabaseTableDecade::CDatabaseTableDecade(void)
{
	m_strTableName = GLOBAL_TABLE_DECADE;
	CreateTable();
}


CDatabaseTableDecade::~CDatabaseTableDecade(void)
{
}

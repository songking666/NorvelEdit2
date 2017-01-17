#include "StdAfx.h"
#include "DatabaseTableGirl.h"


CDatabaseTableGirl::CDatabaseTableGirl(void)
{
	m_strTableName = GLOBAL_TABLE_GIRL;
	CreateTable();
}


CDatabaseTableGirl::~CDatabaseTableGirl(void)
{
}

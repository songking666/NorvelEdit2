#include "StdAfx.h"
#include "DatabaseTableTimeLen.h"


CDatabaseTableTimeLen::CDatabaseTableTimeLen(void)
{
	m_strTableName = GLOBAL_TABLE_COMM_TIME_LEN;
	CreateTable();
}


CDatabaseTableTimeLen::~CDatabaseTableTimeLen(void)
{
}

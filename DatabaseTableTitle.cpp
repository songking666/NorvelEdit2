#include "StdAfx.h"
#include "DatabaseTableTitle.h"


CDatabaseTableTitle::CDatabaseTableTitle(void)
{
	m_strTableName = GLOBAL_TABLE_TITLE;
	CreateTable();
}


CDatabaseTableTitle::~CDatabaseTableTitle(void)
{
	close();
}

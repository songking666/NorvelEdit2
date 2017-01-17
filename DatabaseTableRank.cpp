#include "StdAfx.h"
#include "DatabaseTableRank.h"


CDatabaseTableRank::CDatabaseTableRank(void)
{
	m_strTableName = GLOBAL_TABLE_RANK;
	CreateTable();
}


CDatabaseTableRank::~CDatabaseTableRank(void)
{
	close();
}

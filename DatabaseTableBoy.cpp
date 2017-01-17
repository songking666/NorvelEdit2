#include "StdAfx.h"
#include "DatabaseTableBoy.h"


CDatabaseTableBoy::CDatabaseTableBoy(void)
{
	m_strTableName = GLOBAL_TABLE_BOY;
	CreateTable();
}


CDatabaseTableBoy::~CDatabaseTableBoy(void)
{
}

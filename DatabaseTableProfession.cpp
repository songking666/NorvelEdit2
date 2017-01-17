#include "StdAfx.h"
#include "DatabaseTableProfession.h"


CDatabaseTableProfession::CDatabaseTableProfession(void)
{
	m_strTableName = GLOBAL_TABLE_PROFESSION;
	CreateTable();
}


CDatabaseTableProfession::~CDatabaseTableProfession(void)
{
}

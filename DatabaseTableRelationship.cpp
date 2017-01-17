#include "StdAfx.h"
#include "DatabaseTableRelationship.h"


CDatabaseTableRelationship::CDatabaseTableRelationship(void)
{
	m_strTableName = GLOBAL_TABLE_RELACTIONSHIP;
	CreateTable();
}


CDatabaseTableRelationship::~CDatabaseTableRelationship(void)
{
}

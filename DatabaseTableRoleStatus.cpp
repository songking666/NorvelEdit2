#include "StdAfx.h"
#include "DatabaseTableRoleStatus.h"


CDatabaseTableRoleStatus::CDatabaseTableRoleStatus(void)
{
	m_strTableName = GLOBAL_TABLE_ROLE_STATUS;
	CreateTable();
}


CDatabaseTableRoleStatus::~CDatabaseTableRoleStatus(void)
{
}

#include "StdAfx.h"
#include "DatabaseTableCharacter.h"


CDatabaseTableCharacter::CDatabaseTableCharacter(void)
{
	m_strTableName = GLOBAL_TABLE_CHARACTER;
	CreateTable();
}


CDatabaseTableCharacter::~CDatabaseTableCharacter(void)
{
}

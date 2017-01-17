#include "StdAfx.h"
#include "DatabaseTableTheme.h"


CDatabaseTableTheme::CDatabaseTableTheme(void)
{
	m_strTableName = GLOBAL_TABLE_THEME;
	CreateTable();
}


CDatabaseTableTheme::~CDatabaseTableTheme(void)
{
}

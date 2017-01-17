#include "StdAfx.h"
#include "DatabaseTableExpression.h"


CDatabaseTableExpression::CDatabaseTableExpression(void)
{
	m_strTableName = GLOBAL_TABLE_EXPRESSION;
	CreateTable();
}


CDatabaseTableExpression::~CDatabaseTableExpression(void)
{
}

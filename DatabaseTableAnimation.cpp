#include "StdAfx.h"
#include "DatabaseTableAnimation.h"


CDatabaseTableAnimation::CDatabaseTableAnimation(void)
{
	m_strTableName = GLOBAL_TABLE_ANIMA;
	CreateTable();
}


CDatabaseTableAnimation::~CDatabaseTableAnimation(void)
{
}

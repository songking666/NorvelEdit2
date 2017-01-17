#include "StdAfx.h"
#include "DatabaseTableScene_Type.h"


CDatabaseTableScene_Type::CDatabaseTableScene_Type(void)
{
	m_strTableName = GLOBAL_TABLE_SCENE_TYPE;
	CreateTable();
}


CDatabaseTableScene_Type::~CDatabaseTableScene_Type(void)
{
}

#include "StdAfx.h"
#include "DatabaseTableReligion.h"


CDatabaseTableReligion::CDatabaseTableReligion(void)
{
	m_strTableName = GLOBAL_TABLE_RELIGION;
	CreateTable();
}


CDatabaseTableReligion::~CDatabaseTableReligion(void)
{

}

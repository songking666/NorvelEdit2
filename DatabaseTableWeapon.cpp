#include "StdAfx.h"
#include "DatabaseTableWeapon.h"


CDatabaseTableWeapon::CDatabaseTableWeapon(void)
{
	m_strTableName = GLOBAL_TABLE_WEAPON;
	CreateTable();
}


CDatabaseTableWeapon::~CDatabaseTableWeapon(void)
{
	close();
}

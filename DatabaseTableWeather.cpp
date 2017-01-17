#include "StdAfx.h"
#include "DatabaseTableWeather.h"


CDatabaseTableWeather::CDatabaseTableWeather(void)
{
	m_strTableName = GLOBAL_TABLE_WEATHER;
	CreateTable();
}


CDatabaseTableWeather::~CDatabaseTableWeather(void)
{
}

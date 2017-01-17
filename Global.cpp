#include "StdAfx.h"
#include "Global.h"


CGlobal::CGlobal(void)
{
	structTable tempTable;
	tempTable.strName = GLOBAL_TABLE_ANIMA;
	tempTable.strContent = _T("动物");
	m_vectorTable.push_back(tempTable);
	tempTable.strName = GLOBAL_TABLE_PLANE;
	tempTable.strContent = _T("植物");
	m_vectorTable.push_back(tempTable);

	tempTable.strName = GLOBAL_TABLE_WEAPON;
	tempTable.strContent = _T("武器");
	m_vectorTable.push_back(tempTable);	

	tempTable.strName = GLOBAL_TABLE_RANK;
	tempTable.strContent = _T("级别");
	m_vectorTable.push_back(tempTable);		

	tempTable.strName = GLOBAL_TABLE_TITLE;
	tempTable.strContent = _T("称呼");
	m_vectorTable.push_back(tempTable);		
	tempTable.strName = GLOBAL_TABLE_TIME_UNIT;
	tempTable.strContent = _T("时间单位");
	m_vectorTable.push_back(tempTable);
	tempTable.strName = GLOBAL_TABLE_SCENE_TYPE;
	tempTable.strContent = _T("场景类型");

	m_vectorTable.push_back(tempTable);

	tempTable.strName = GLOBAL_TABLE_MOOD;
	tempTable.strContent = _T("心情");
	m_vectorTable.push_back(tempTable);
	tempTable.strName = GLOBAL_TABLE_EXPRESSION;
	tempTable.strContent = _T("表情");
	m_vectorTable.push_back(tempTable);

	tempTable.strName = GLOBAL_TABLE_COMM_TIME_LEN;
	tempTable.strContent = _T("时段");
	m_vectorTable.push_back(tempTable);

	tempTable.strName = GLOBAL_TABLE_CHARACTER;
	tempTable.strContent = _T("性格");
	m_vectorTable.push_back(tempTable);

	tempTable.strName = GLOBAL_TABLE_RELACTIONSHIP;
	tempTable.strContent = _T("人际关系");
	m_vectorTable.push_back(tempTable);

	tempTable.strName = GLOBAL_TABLE_ROLE_STATUS;
	tempTable.strContent = _T("人物状态");
	m_vectorTable.push_back(tempTable);

	tempTable.strName = GLOBAL_TABLE_THEME;
	tempTable.strContent = _T("题材");
	m_vectorTable.push_back(tempTable);

	tempTable.strName = GLOBAL_TABLE_DECADE;
	tempTable.strContent = _T("年代");
	m_vectorTable.push_back(tempTable);

	tempTable.strName = GLOBAL_TABLE_WEATHER;
	tempTable.strContent = _T("天气");
	m_vectorTable.push_back(tempTable);

	tempTable.strName = GLOBAL_TABLE_GEOGRAPHY;
	tempTable.strContent = _T("地理");
	m_vectorTable.push_back(tempTable);

	tempTable.strName = GLOBAL_TABLE_CLOTH;
	tempTable.strContent = _T("服装");
	m_vectorTable.push_back(tempTable);

	tempTable.strName = GLOBAL_TABLE_THINGS;
	tempTable.strContent = _T("物品");
	m_vectorTable.push_back(tempTable);

	tempTable.strName = GLOBAL_TABLE_COUNTRY;
	tempTable.strContent = _T("国家");
	m_vectorTable.push_back(tempTable);

	tempTable.strName = GLOBAL_TABLE_RELIGION;
	tempTable.strContent = _T("宗教");
	m_vectorTable.push_back(tempTable);

	tempTable.strName = GLOBAL_TABLE_PROFESSION;
	tempTable.strContent = _T("职业");
	m_vectorTable.push_back(tempTable);

	tempTable.strName = GLOBAL_TABLE_TECHNOLOGY;
	tempTable.strContent = _T("技术");
	m_vectorTable.push_back(tempTable);

	tempTable.strName = GLOBAL_TABLE_GIRL;
	tempTable.strContent = _T("女性外貌");
	m_vectorTable.push_back(tempTable);

	tempTable.strName = GLOBAL_TABLE_BOY;
	tempTable.strContent = _T("男性外貌");
	m_vectorTable.push_back(tempTable);

}


CGlobal::~CGlobal(void)
{
}

CString CGlobal::GetExePath()
{
	static CString strPath;
	if(strPath.IsEmpty())
	{
		TCHAR buf[256] = {0};  
		GetModuleFileName(NULL, buf, sizeof(buf)/sizeof(TCHAR));  
		strPath = buf;         
		strPath = strPath.Left(strPath.ReverseFind('\\') + 1);  
	}
	return strPath;
}

CString CGlobal::GetDataBasePath()
{
	CString strExepath = GetExePath();
	strExepath += _T("Database\\");
	strExepath += GLOBAL_DATABASE_NAME;
	return strExepath;
}

CGlobal g_Global;
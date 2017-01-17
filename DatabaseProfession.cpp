#include "StdAfx.h"
#include "DatabaseProfession.h"


CDatabaseProfession::CDatabaseProfession(void)
{
	m_strTableName = GLOBAL_TABLE_PROFESSION;
	CreateTable();
}


CDatabaseProfession::~CDatabaseProfession(void)
{
	close();
}

bool CDatabaseProfession::CreateTable()
{
	CString strExePath = CGlobal::GetDataBasePath();

	try
	{
		open(strExePath);   
		// 判断表名是否已经存在 
		if(!tableExists(m_strTableName))   
		{
			// 不存在,新建表Customers
			CString strCmdCreateTable;
			strCmdCreateTable.Format(_T("CREATE TABLE %s([ID] integer PRIMARY KEY NOT NULL,[profession] varchar(24),[content] varchar(256)"),m_strTableName);
			if(execDML(strCmdCreateTable) == SQLITE_ERROR) 
				return false;
		}
		return true;
	}
	catch (CppSQLite3Exception* e)
	{
		CString errMsg = e->errorMessage();
		AfxMessageBox(errMsg);
	}

	return false;
}

vectorProfession CDatabaseProfession::GetData()
{
	CString strQuery;
	strQuery.Format(_T("SELECT * FROM %s;"),m_strTableName);
	CppSQLite3Query q = execQuery(strQuery); 

	m_vectorProfession.clear();

	while (!q.eof())  
	{  
		StructProfession tempTheme;
		tempTheme.nID = q.getIntField(0);
		tempTheme.strProfessionName = q.getStringField(1);
		tempTheme.strContent = q.getStringField(2);

		m_vectorProfession.push_back(tempTheme);
		q.nextRow();  
	}  

	// 销毁语句  
	q.finalize();  

	return m_vectorProfession;
}

bool CDatabaseProfession::Insert( CString strThemeName ,CString strContent)
{
	CString strCmd;
	strCmd.Format(_T("INSERT INTO %s(LastName,Type) values('%s','%s')"),m_strTableName,strThemeName,strContent);
	try
	{
		if(execDML(strCmd) != SQLITE_ERROR)
			return true;
	}
	catch (CppSQLite3Exception* e)
	{
		CString errMsg = e->errorMessage();
		AfxMessageBox(errMsg);
	}
	return false;
}

vectorProfession CDatabaseProfession::Find( CString strKey ,CString strValue)
{
	CString strCmd;
	strCmd.Format(_T("SELECT * FROM %s WHERE %s=%s"),m_strTableName,strKey,strValue);
	CppSQLite3Query q = execQuery(strCmd); 

	m_vectorProfession.clear();

	while (!q.eof())  
	{  
		StructProfession tempTheme;
		tempTheme.nID = q.getIntField(0);
		tempTheme.strProfessionName = q.getStringField(1);
		tempTheme.strContent = q.getStringField(2);

		m_vectorProfession.push_back(tempTheme);
		q.nextRow();  
	}  

	// 销毁语句  
	q.finalize();  

	return m_vectorProfession;
}

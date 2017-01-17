#include "StdAfx.h"
#include "DatabaseTableLastName.h"


CDatabaseTableLastName::CDatabaseTableLastName(void)
{
	m_strTableName = GLOBAL_TABLE_LAST_NAME;
	CreateTable();
}


CDatabaseTableLastName::~CDatabaseTableLastName(void)
{
	close();
}

bool CDatabaseTableLastName::CreateTable()
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
			strCmdCreateTable.Format(_T("CREATE TABLE %s([ID] integer PRIMARY KEY NOT NULL,[LastName] varchar(24),[country] integer,[sex] interger)"),m_strTableName);
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

VectorLastName CDatabaseTableLastName::GetData()
{
	CString strQuery;
	strQuery.Format(_T("SELECT * FROM %s;"),m_strTableName);
	CppSQLite3Query q = execQuery(strQuery); 

	m_vectorLastName.clear();

	while (!q.eof())  
	{  
		StructLastName tempTheme;
		tempTheme.nID = q.getIntField(0);
		tempTheme.strName = q.getStringField(1);
		tempTheme.nCountry = q.getIntField(2);
		tempTheme.nSex= q.getIntField(3);

		m_vectorLastName.push_back(tempTheme);
		q.nextRow();  
	}  

	// 销毁语句  
	q.finalize();  

	return m_vectorLastName;
}

bool CDatabaseTableLastName::Insert( CString strThemeName ,int nType,int nSex)
{
	CString strCmd;
	strCmd.Format(_T("INSERT INTO %s(LastName,country,sex) values('%s',%d,%d)"),m_strTableName,strThemeName,nType,nSex);
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

VectorLastName CDatabaseTableLastName::Find( CString strKey ,CString strValue)
{
	CString strCmd;
	strCmd.Format(_T("SELECT * FROM %s WHERE %s='%s'"),m_strTableName,strKey,strValue);
	CppSQLite3Query q = execQuery(strCmd); 

	m_vectorLastName.clear();

	while (!q.eof())  
	{  
		StructLastName tempTheme;
		tempTheme.nID = q.getIntField(0);
		tempTheme.strName = q.getStringField(1);
		tempTheme.nCountry = q.getIntField(2);
		tempTheme.nSex= q.getIntField(3);

		m_vectorLastName.push_back(tempTheme);
		q.nextRow();  
	}  

	// 销毁语句  
	q.finalize();  

	return m_vectorLastName;
}

VectorLastName CDatabaseTableLastName::Find( CString strKey,int nValue )
{
	CString strCmd;
	strCmd.Format(_T("SELECT * FROM %s WHERE %s=%d"),m_strTableName,strKey,nValue);
	CppSQLite3Query q = execQuery(strCmd); 

	m_vectorLastName.clear();

	while (!q.eof())  
	{  
		StructLastName tempTheme;
		tempTheme.nID = q.getIntField(0);
		tempTheme.strName = q.getStringField(1);
		tempTheme.nCountry = q.getIntField(2);
		tempTheme.nSex= q.getIntField(3);

		m_vectorLastName.push_back(tempTheme);
		q.nextRow();  
	}  

	// 销毁语句  
	q.finalize();  

	return m_vectorLastName;
}

int CDatabaseTableLastName::GetCount( CString strKey,int nValue )
{
	CString strCmd;
	strCmd.Format(_T("SELECT COUNT(1) from %s WHERE %s=%d"),m_strTableName,strKey,nValue);
	CppSQLite3Query q = execQuery(strCmd); 

	int nCount;
	while (!q.eof())  
	{  

		nCount = q.getIntField(0);
		q.nextRow();  
	}  

	// 销毁语句  
	q.finalize();  

	return nCount;
}

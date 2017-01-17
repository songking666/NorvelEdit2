#include "StdAfx.h"
#include "DatabaseTableBase.h"


CDatabaseTableBase::CDatabaseTableBase(void)
{
}


CDatabaseTableBase::~CDatabaseTableBase(void)
{
	close();
}


bool CDatabaseTableBase::CreateTable()
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
			strCmdCreateTable.Format(_T("CREATE TABLE %s([ID] integer PRIMARY KEY NOT NULL,[name] varchar(24),[Content] varchar[256])"),m_strTableName);
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

vectorBase CDatabaseTableBase::GetData()
{
	CString strQuery;
	strQuery.Format(_T("SELECT * FROM %s;"),m_strTableName);
	CppSQLite3Query q = execQuery(strQuery); 

	m_vectorBase.clear();

	while (!q.eof())  
	{  
		StructBase tempTheme;
		tempTheme.nID = q.getIntField(0);
		tempTheme.strName = q.getStringField(1);
		tempTheme.strContent = q.getStringField(2);

		m_vectorBase.push_back(tempTheme);
		q.nextRow();  
	}  

	// 销毁语句  
	q.finalize();  

	return m_vectorBase;
}

bool CDatabaseTableBase::Insert( CString strThemeName ,CString strContent)
{
	CString strCmd;
	strCmd.Format(_T("INSERT INTO %s(name,content) values('%s','%s')"),m_strTableName,strThemeName,strContent);
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

vectorBase CDatabaseTableBase::Find(CString strValue)
{
	CString strCmd;
	strCmd.Format(_T("SELECT * FROM %s WHERE name='%s'"),m_strTableName,strValue);
	CppSQLite3Query q = execQuery(strCmd); 

	m_vectorBase.clear();

	while (!q.eof())  
	{  
		StructBase tempTheme;
		tempTheme.nID = q.getIntField(0);
		tempTheme.strName = q.getStringField(1);
		tempTheme.strContent = q.getStringField(2);

		m_vectorBase.push_back(tempTheme);
		q.nextRow();  
	}  

	// 销毁语句  
	q.finalize();  

	return m_vectorBase;
}
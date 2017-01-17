#include "StdAfx.h"
#include "DataBaseTableFirstName.h"


CDataBaseTableFirstName::CDataBaseTableFirstName(void)
{
	m_strTableName = GLOBAL_TABLE_FIRST_NAME;
	CreateTable();
}


CDataBaseTableFirstName::~CDataBaseTableFirstName(void)
{
}

bool CDataBaseTableFirstName::CreateTable()
{
	CString strExePath = CGlobal::GetDataBasePath();

	try
	{
		open(strExePath);   
		// 判断表名是否已经存在 
		if(!tableExists(GLOBAL_TABLE_FIRST_NAME))   
		{
			// 不存在,新建表Customers
			CString strCmdCreateTable;
			strCmdCreateTable.Format(_T("CREATE TABLE %s([ID] integer PRIMARY KEY NOT NULL,[FirstName] varchar(24),[Type] integer)"),m_strTableName);
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

bool CDataBaseTableFirstName::Insert( CString strFirstName,int nType )
{
	CString strCmd;
	strCmd.Format(_T("INSERT INTO %s(FirstName,Type) values('%s', %d);"),GLOBAL_TABLE_FIRST_NAME,strFirstName,nType);
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

bool CDataBaseTableFirstName::GetData( vectorFirstNameList& firstNameList )
{
	CString strQuery;
	strQuery.Format(_T("SELECT * FROM %s;"),m_strTableName);
	CppSQLite3Query q = execQuery(strQuery); 

	m_vectorName.clear();

	while (!q.eof())  
	{  
		TableFirstName tempName;
		tempName.nid = q.getIntField(0);
		tempName.strFirstName = q.getStringField(1);
		tempName.ntype = q.getIntField(2);

		m_vectorName.push_back(tempName);
		q.nextRow();  
	}  
	firstNameList = m_vectorName;
	// 销毁语句  
	q.finalize();  
	return true;
}

vectorFirstNameList CDataBaseTableFirstName::Find( CString strFirstName,CString strValue )
{
	CString strCmd;
	strCmd.Format(_T("SELECT * FROM %s WHERE %s='%s'"),m_strTableName,strFirstName,strValue);
	CppSQLite3Query q = execQuery(strCmd); 

	m_vectorName.clear();

	while (!q.eof())  
	{  
		TableFirstName tempTheme;
		tempTheme.nid = q.getIntField(0);
		tempTheme.strFirstName = q.getStringField(1);
		tempTheme.ntype = q.getIntField(2);

		m_vectorName.push_back(tempTheme);
		q.nextRow();  
	}  

	// 销毁语句  
	q.finalize();  

	return m_vectorName;
}

TableFirstName CDataBaseTableFirstName::GetFirstnameByID( int nType )
{
	CString strCmd;
	strCmd.Format(_T("SELECT * FROM %s WHERE ID=%d"),m_strTableName,nType);
	CppSQLite3Query q = execQuery(strCmd); 

	m_vectorName.clear();

	TableFirstName tempTheme;
	while (!q.eof())  
	{  
		
		tempTheme.nid = q.getIntField(0);
		tempTheme.strFirstName = q.getStringField(1);
		tempTheme.ntype = q.getIntField(2);

	
		q.nextRow();  
	}  

	// 销毁语句  
	q.finalize();  

	return tempTheme;
}

int CDataBaseTableFirstName::GetCount()
{
	CString strCmd;
	strCmd.Format(_T("SELECT COUNT(1) from %s "),m_strTableName);
	CppSQLite3Query q = execQuery(strCmd); 

	m_vectorName.clear();

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

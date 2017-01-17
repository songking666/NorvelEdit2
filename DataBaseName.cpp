#include "StdAfx.h"
#include "DataBaseName.h"


CDataBaseName::CDataBaseName(void)
{
	CreateTable();
}


CDataBaseName::~CDataBaseName(void)
{
}

bool CDataBaseName::CreateTable()
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
			strCmdCreateTable.Format(_T("CREATE TABLE %s([ID] integer PRIMARY KEY NOT NULL,[FirstName] varchar(24),[Type] integer)"),GLOBAL_TABLE_FIRST_NAME);
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

bool CDataBaseName::Insert( CString strFirstName,int nType )
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

bool CDataBaseName::GetData( vectorFirstNameList& firstNameList )
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

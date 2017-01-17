#include "StdAfx.h"
#include "DatabaseTableCommonWord.h"


CDatabaseTableCommonWord::CDatabaseTableCommonWord(void)
{
	m_strTableName = GLOBAL_TABLE_COMMON_WORD;
	CreateTable();
}


CDatabaseTableCommonWord::~CDatabaseTableCommonWord(void)
{
	close();
}

bool CDatabaseTableCommonWord::CreateTable()
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
			strCmdCreateTable.Format(_T("CREATE TABLE %s([ID] integer PRIMARY KEY NOT NULL,[Word] varchar(2))"),m_strTableName);
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

vectorWord CDatabaseTableCommonWord::GetData()
{
	CString strQuery;
	strQuery.Format(_T("SELECT * FROM %s;"),m_strTableName);
	CppSQLite3Query q = execQuery(strQuery); 

	m_vectorWord.clear();

	while (!q.eof())  
	{  
		StructWord tempTheme;
		tempTheme.nID = q.getIntField(0);
		tempTheme.strName = q.getStringField(1);

		m_vectorWord.push_back(tempTheme);
		q.nextRow();  
	}  

	// 销毁语句  
	q.finalize();  

	return m_vectorWord;
}

bool CDatabaseTableCommonWord::Insert( WCHAR OneWord)
{
	CString strCmd;
	strCmd.Format(_T("INSERT INTO %s(Word) values('%c')"),m_strTableName,OneWord);
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

vectorWord CDatabaseTableCommonWord::Find(int nid)
{
	CString strCmd;
	strCmd.Format(_T("SELECT * FROM %s WHERE ID=%d"),m_strTableName,nid);
	CppSQLite3Query q = execQuery(strCmd); 

	m_vectorWord.clear();

	while (!q.eof())  
	{  
		StructWord tempTheme;
		tempTheme.nID = q.getIntField(0);
		tempTheme.strName = q.getStringField(1);

		m_vectorWord.push_back(tempTheme);
		q.nextRow();  
	}  

	// 销毁语句  
	q.finalize();  

	return m_vectorWord;
}

bool CDatabaseTableCommonWord::Find( WCHAR OneWord )
{
	CString strCmd;
	strCmd.Format(_T("SELECT * FROM %s WHERE Word='%c'"),m_strTableName,OneWord);
	CppSQLite3Query q = execQuery(strCmd); 

	m_vectorWord.clear();

	int i = 0;
	while (!q.eof())  
	{  
		i++;
		break;
		q.nextRow();  
	}  

	// 销毁语句  
	q.finalize();  

	return i;
}

int CDatabaseTableCommonWord::GetCount()
{
	CString strCmd;
	strCmd.Format(_T("SELECT COUNT(1) from %s "),m_strTableName);
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

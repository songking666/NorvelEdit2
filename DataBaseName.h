#pragma once

typedef struct Tag_TableFirstNameStruct
{
	int		nid;
	CString strFirstName;
	int     ntype;
}TableFirstName;

typedef vector<TableFirstName> vectorFirstNameList;

class CDataBaseName:public CppSQLite3DB
{
public:
	CDataBaseName(void);
	~CDataBaseName(void);
private:
	CString m_strTableName; 
	vectorFirstNameList m_vectorName;
public:

	bool CreateTable();
	bool Insert(CString strFirstName,int nType);
	bool GetData(vectorFirstNameList& firstNameList);
};


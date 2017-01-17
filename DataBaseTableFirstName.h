#pragma once
/************************************************************************/
/* пу                                                                     */
/************************************************************************/
typedef struct Tag_TableFirstNameStruct
{
	int		nid;
	CString strFirstName;
	int     ntype;
}TableFirstName;

typedef vector<TableFirstName> vectorFirstNameList;

class CDataBaseTableFirstName:public CppSQLite3DB
{
public:
	CDataBaseTableFirstName(void);
	~CDataBaseTableFirstName(void);
private:
	CString m_strTableName; 
	vectorFirstNameList m_vectorName;
public:

	bool CreateTable();
	bool Insert(CString strFirstName,int nType);
	bool GetData(vectorFirstNameList& firstNameList);
	vectorFirstNameList Find(CString strFirstName,CString strValue);
	TableFirstName	GetFirstnameByID(int nType);
	int GetCount();
};


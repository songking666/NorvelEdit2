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

class CDataBaseFirstName:public CppSQLite3DB
{
public:
	CDataBaseFirstName(void);
	~CDataBaseFirstName(void);
private:
	CString m_strTableName; 
	vectorFirstNameList m_vectorName;
public:

	bool CreateTable();
	bool Insert(CString strFirstName,int nType);
	bool GetData(vectorFirstNameList& firstNameList);
};


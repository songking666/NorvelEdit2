#pragma once
/************************************************************************/
/* Ãû                                                                     */
/************************************************************************/
typedef struct tag_LastName
{
	int nID;
	CString strName;
	int nCountry;
	int nSex;
}StructLastName;

typedef vector<StructLastName> VectorLastName;

class CDatabaseTableLastName:public CppSQLite3DB
{
public:
	CDatabaseTableLastName(void);
	~CDatabaseTableLastName(void);
protected:
	CString				m_strTableName;
	VectorLastName		m_vectorLastName;
public:

	bool CreateTable();
	bool Insert(CString strDate ,int nType,int nSex);
	VectorLastName GetData();
	VectorLastName Find(CString strKey,CString strValue);
	VectorLastName Find(CString strKey,int nValue);

	int GetCount(CString strKey,int nValue);
};


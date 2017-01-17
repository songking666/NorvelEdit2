#pragma once

typedef struct tag_StructBase
{
	int nID;
	CString strName;
	CString strContent;
	int ntype;
}StructBase;

typedef vector<StructBase> vectorBase;

class CDatabaseTableBase:public CppSQLite3DB
{
public:
	CDatabaseTableBase(void);
	~CDatabaseTableBase(void);
protected:
	CString			m_strTableName;
	vectorBase		m_vectorBase;
public:

	virtual bool CreateTable();
	virtual bool Insert(CString strName,CString strContent);
	virtual vectorBase GetData();
	virtual vectorBase Find(CString strValue);
};


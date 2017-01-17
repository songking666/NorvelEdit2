#pragma once
/************************************************************************/
/* Ö°Òµ±í                                                                     */
/************************************************************************/
typedef struct tag_Profession
{
	int nID;
	CString strProfessionName;
	CString strContent;
}StructProfession;

typedef vector<StructProfession> vectorProfession;

class CDatabaseProfession:public CppSQLite3DB
{
public:
	CDatabaseProfession(void);
	~CDatabaseProfession(void);
private:
	CString				m_strTableName;
	vectorProfession	m_vectorProfession;
public:
	bool CreateTable();
	bool Insert(CString strDate,CString strContent);
	vectorProfession GetData();
	vectorProfession Find(CString strKey,CString strValue);
};


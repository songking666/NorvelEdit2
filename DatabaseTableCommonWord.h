#pragma once

typedef struct tag_Word
{
	int nID;
	CString strName;
}StructWord;

typedef vector<StructWord> vectorWord;


class CDatabaseTableCommonWord:public CppSQLite3DB
{
public:
	CDatabaseTableCommonWord(void);
	~CDatabaseTableCommonWord(void);
protected:
	CString		m_strTableName;
	vectorWord	m_vectorWord;
public:
	bool CreateTable();
	bool Insert(WCHAR Word);
	vectorWord GetData();
	vectorWord Find(int nid);
	bool Find(WCHAR OneWord);
	int		GetCount();

	WCHAR	GetCharByID(int nid);
};


#pragma once
#include <vector>
#include <string>
using namespace std;
#include "CppSQLite3U.h"
#include "DatabaseTableBase.h"

#define GLOBAL_DATABASE_NAME				_T("MainBase.db")//主库名称
#define GLOBAL_TABLE_LAST_NAME				_T("lastName")		//名
#define GLOBAL_TABLE_FIRST_NAME				_T("firstName")		//姓
#define GLOBAL_TABLE_THEME					_T("theme")//小说题材
#define GLOBAL_TABLE_DECADE					_T("decade")//年代
#define GLOBAL_TABLE_PROFESSION				_T("profession")//职业
#define GLOBAL_TABLE_GEOGRAPHY				_T("geography")//地理
#define GLOBAL_TABLE_WEATHER				_T("weather")//天气
#define GLOBAL_TABLE_CLOTH					_T("cloth")//小说衣服
#define GLOBAL_TABLE_THINGS					_T("things")//小说物品
#define GLOBAL_TABLE_TECHNOLOGY				_T("technology")//技术 一些高科技术语以及解释

#define GLOBAL_TABLE_COMMON_WORD			_T("common_word")//常用汉字
#define GLOBAL_TABLE_COUNTRY				_T("country")//国家，省市县阵，
#define GLOBAL_TABLE_RELIGION				_T("religion")//宗教

#define GLOBAL_TABLE_ANIMA					_T("animation")//动物，现实，幻想，神话，科幻
#define GLOBAL_TABLE_PLANE					_T("plane")//植物
#define GLOBAL_TABLE_WEAPON					_T("weapon")//武器
#define GLOBAL_TABLE_RANK					_T("rank")//军衔，分古代，现代
#define GLOBAL_TABLE_TITLE					_T("title")//号称，例天王，
#define GLOBAL_TABLE_TIME_UNIT				_T("time_unit")//小说时间

#define GLOBAL_TABLE_SCENE_TYPE				_T("scene_type")//场景类型 说话，学习，研究，工作，打仗，战争，游戏
#define GLOBAL_TABLE_MOOD					_T("mood")//心情
#define GLOBAL_TABLE_EXPRESSION				_T("expression")//表情
#define GLOBAL_TABLE_COMM_TIME_LEN			_T("time_len")//常用时段

#define GLOBAL_TABLE_CHARACTER				_T("character")		//性格类型
#define GLOBAL_TABLE_RELACTIONSHIP			_T("relactionship")//人际关系
#define GLOBAL_TABLE_ROLE_STATUS			_T("role_status")//人物状态

#define GLOBAL_TABLE_GIRL					_T("girl")//人物外形
#define GLOBAL_TABLE_BOY					_T("boy")//男人描写
//#define GLOBAL_TABLE_LINK					_T("LIKE")//喜欢
//#define GLOBAL_TABLE_HATE					_T("HATE")//讨厌
#define GLOBAL_MSG_TREE_SELECT_CHANGE		WM_USER+0x01
#define GLOBAL_MSG_READ_FILE				WM_USER+0x02
typedef struct tag_structTable
{
	CString strName;
	CString strContent;
}structTable;
typedef vector<structTable> VectorTable;

class CGlobal
{
public:
	CGlobal(void);
	~CGlobal(void);
public:
	//CDataBaseName m_DataBase;
	CString			m_strTreeSelectItem;
	VectorTable		m_vectorTable;
	vector<CString>	m_vectorChapter;
	static CString GetExePath();
	static CString GetDataBasePath();
	
};

extern CGlobal g_Global;
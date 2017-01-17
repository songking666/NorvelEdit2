#pragma once
#include <vector>
using namespace std;
/*角色属性*/
typedef struct tag_RoleProperties
{
	TCHAR m_strName[24];		//人物名称
	SYSTEMTIME m_timeBirthday;	//生日
	int m_nAge;					//年龄
	int m_nWorkType;			//工作
	bool m_nSex;				//性别
	int m_nStartChapter;		//开始章
	//int m_nCloth;				//服装
	int m_nChara;				//性格
	int m_nReleation;			//与主角关系

	TCHAR m_strExplain[256];	//说明
	TCHAR m_strTheEnd[256];		//最终结局
}RoleProperties;
/*人物状态*/
typedef struct tag_RoleStatus
{
	int m_nClothType;		//人物服样式
	int m_nBodyStatus;		//人物身体状态
	int m_nFaceExpression;	//表情
	int m_nHeartExpression;	//心情
}RoleStatus;

/*场景属性*/
typedef struct tag_SceneFormat
{
	TCHAR	m_strSceneName[24];//场景名称
	int		m_nChapterID;		//章ID
	int		m_nSegment;			//节ID

	int		m_nSceneType; //场景类型
	TCHAR	m_strAddress[24];//场景地点
	int		m_nTime;//时间
	int		m_nTimeLong;//时长
	int		m_nGeographicalEnvironment;//地理环境
	int		m_nWeather;//天气状态
	int		m_nTimeUnit;//时间单位

	int				m_nMainRoleID;	//主要角色ID
	RoleStatus		m_RoleStatus;//主要角色状态

	TCHAR			m_strOtherRole[32][24];//其他角色ID
	RoleStatus		m_nOtherStatus[32];//其他角色状态

	TCHAR					m_strEventStart[255];//起因
	TCHAR					m_strEventProgress[255];//经过
	TCHAR					m_strEventEnd[255];//结果

}SceneFormat;

typedef struct tag_Chapter
{
	CString strName;
	CString	strData;
}STRUCT_CHAPTER;

typedef vector<STRUCT_CHAPTER> VectorCapter;

class CSaveFormat:public CObject
{
	DECLARE_SERIAL(CSaveFormat)
public:
	CSaveFormat(void);
	~CSaveFormat(void);
public:
	void			CreateNew();
	CString			m_strBookname;
	int				m_nTheme;
	int				m_nDecade;
	vector<RoleProperties>	m_vectorRole;
	vector<SceneFormat>		m_vectorScene;
	VectorCapter			m_vectorCapter;

	virtual void Serialize(CArchive&);

	void WriteRole( CString strFilePath ); 


	void WriteIni( CString strFilePath ) ;


	void ReadRole( CString strFilePath ) ;


	void ReadIni( CString strFilePath );

	void ReadScene(CString strFilePath);
	void WriteScene(CString strFilePath);
};


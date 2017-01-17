#include "StdAfx.h"
#include "SaveFormat.h"

IMPLEMENT_SERIAL(CSaveFormat,CObject,0);
CSaveFormat::CSaveFormat(void)
{
}


CSaveFormat::~CSaveFormat(void)
{
}

void CSaveFormat::Serialize( CArchive& ar)
{
	

	m_strBookname = ar.GetFile()->GetFileName();
	CString strFilePath = ar.GetFile()->GetFilePath();
	int pos = strFilePath.ReverseFind('\\');
	
	if(pos != -1)
	{
		strFilePath = strFilePath.Mid(0,pos + 1);
	}
	
	
	pos = m_strBookname.ReverseFind('.');
	if(pos != -1)
	{
		m_strBookname = m_strBookname.Mid(0,pos);
	}
	if(ar.IsStoring())
	{
		ar.WriteCount(m_vectorCapter.size());
		for(int i = 0;i<m_vectorCapter.size();i++)
		{
			ar << m_vectorCapter[i].strName;
			ar << m_vectorCapter[i].strData;
		}

		
		WriteIni(strFilePath);
		WriteRole(strFilePath);
		WriteScene(strFilePath);
	}
	else
	{
		m_vectorCapter.clear();
		int readcount = ar.ReadCount();
		
		for(int i = 0;i<readcount;i++)
		{
			STRUCT_CHAPTER tempChapter;
			ar >> tempChapter.strName;
			ar >> tempChapter.strData;
			m_vectorCapter.push_back(tempChapter);
			g_Global.m_vectorChapter.push_back(tempChapter.strName);
		}

		ReadIni(strFilePath);
		ReadRole(strFilePath);
		ReadScene(strFilePath);
	}
}

void CSaveFormat::CreateNew()
{
	m_vectorRole.clear();
	m_vectorScene.clear();
	m_vectorCapter.clear();
}

void CSaveFormat::ReadIni( CString strFilePath )
{

	CString strConfigName = strFilePath + _T("config.cfg");

	m_nTheme = GetPrivateProfileInt(_T("config"),_T("theme"),-1,strConfigName);
	m_nDecade = GetPrivateProfileInt(_T("config"),_T("decade"),-1,strConfigName);
}

void CSaveFormat::ReadRole( CString strFilePath )
{

	CString strPathRole = strFilePath + _T("rold.dat");
	FILE* fp = _tfopen(strPathRole,_T("rb"));

	while(!feof(fp))
	{
		RoleProperties tempRole = {0};
		size_t readsize = fread(&tempRole,sizeof(RoleProperties),1,fp);
		if(readsize != 1)
			break;
		m_vectorRole.push_back(tempRole);
	}

	fclose(fp);
}

void CSaveFormat::WriteIni( CString strFilePath )
{
	CString strConfigName = strFilePath + _T("config.cfg");
	TCHAR tempBuff[24] = {0};
	_itot(m_nTheme,tempBuff,10);
	WritePrivateProfileString(_T("config"),_T("theme"),tempBuff,strConfigName);

	TCHAR tempBuff2[24] = {0};
	_itot(m_nDecade,tempBuff2,10);
	WritePrivateProfileString(_T("config"),_T("decade"),tempBuff2,strConfigName);
}

void CSaveFormat::WriteRole( CString strFilePath )
{
	CString strPathRole = strFilePath + _T("rold.dat");
	if(_taccess(strPathRole,0) != -1)
		DeleteFile(strPathRole);
	FILE* fp = _tfopen(strPathRole,_T("wb"));
	for(int i =0;i<m_vectorRole.size();i++)
	{
		fwrite(&(m_vectorRole[i]),sizeof(RoleProperties),1,fp);
	}
	fclose(fp);
}

void CSaveFormat::ReadScene( CString strFilePath )
{
	CString strPathRole = strFilePath + _T("scene.dat");
	FILE* fp = _tfopen(strPathRole,_T("rb"));

	while(!feof(fp))
	{
		SceneFormat tempRole = {0};
		size_t readsize = fread(&tempRole,sizeof(SceneFormat),1,fp);
		if(readsize != 1)
			break;
		m_vectorScene.push_back(tempRole);
	}

	fclose(fp);
}

void CSaveFormat::WriteScene( CString strFilePath )
{
	CString strPathRole = strFilePath + _T("scene.dat");
	if(_taccess(strPathRole,0) != -1)
		DeleteFile(strPathRole);
	FILE* fp = _tfopen(strPathRole,_T("wb"));
	for(int i =0;i<m_vectorScene.size();i++)
	{
		fwrite(&(m_vectorScene[i]),sizeof(SceneFormat),1,fp);
	}
	fclose(fp);
}

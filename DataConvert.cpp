#include "StdAfx.h"
#include "DataConvert.h"

StructLunarcal lunarcal[] = { 
	{ 23, 3, 2, 17, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0 }, /* 1936 */ 
	{ 41, 0, 4, 23, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1 }, 
	{ 30, 7, 5, 28, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1 }, 
	{ 49, 0, 6, 33, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1 }, 
	{ 38, 0, 0, 38, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1 }, /* 1940 */ 
	{ 26, 6, 2, 44, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0 }, 
	{ 45, 0, 3, 49, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 }, 
	{ 35, 0, 4, 54, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1 }, 
	{ 24, 4, 5, 59, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1 }, /* 1944 */ 
	{ 43, 0, 0, 5, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1 }, 
	{ 32, 0, 1, 10, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1 }, 
	{ 21, 2, 2, 15, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1 }, 
	{ 40, 0, 3, 20, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1 }, /* 1948 */ 
	{ 28, 7, 5, 26, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1 }, 
	{ 47, 0, 6, 31, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1 }, 
	{ 36, 0, 0, 36, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 }, 
	{ 26, 5, 1, 41, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1 }, /* 1952 */ 
	{ 44, 0, 3, 47, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1 }, 
	{ 33, 0, 4, 52, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0 }, 
	{ 23, 3, 5, 57, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1 }, 
	{ 42, 0, 6, 2, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1 }, /* 1956 */ 
	{ 30, 8, 1, 8, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0 }, 
	{ 48, 0, 2, 13, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0 }, 
	{ 38, 0, 3, 18, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 }, 
	{ 27, 6, 4, 23, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0 }, /* 1960 */ 
	{ 45, 0, 6, 29, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0 }, 
	{ 35, 0, 0, 34, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1 }, 
	{ 24, 4, 1, 39, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0 }, 
	{ 43, 0, 2, 44, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0 }, /* 1964 */ 
	{ 32, 0, 4, 50, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1 }, 
	{ 20, 3, 5, 55, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0 }, 
	{ 39, 0, 6, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0 }, 
	{ 29, 7, 0, 5, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1 }, /* 1968 */ 
	{ 47, 0, 2, 11, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1 }, 
	{ 36, 0, 3, 16, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0 }, 
	{ 26, 5, 4, 21, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1 }, 
	{ 45, 0, 5, 26, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1 }, /* 1972 */ 
	{ 33, 0, 0, 32, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1 }, 
	{ 22, 4, 1, 37, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1 }, 
	{ 41, 0, 2, 42, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1 }, 
	{ 30, 8, 3, 47, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1 }, /* 1976 */ 
	{ 48, 0, 5, 53, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1 }, 
	{ 37, 0, 6, 58, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1 }, 
	{ 27, 6, 0, 3, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0 }, 
	{ 46, 0, 1, 8, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0 }, /* 1980 */ 
	{ 35, 0, 3, 14, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1 }, 
	{ 24, 4, 4, 19, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1 }, 
	{ 43, 0, 5, 24, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1 }, 
	{ 32, 10, 6, 29, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1 }, /* 1984 */ 
	{ 50, 0, 1, 35, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0 }, 
	{ 39, 0, 2, 40, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1 }, 
	{ 28, 6, 3, 45, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0 }, 
	{ 47, 0, 4, 50, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1 }, /* 1988 */ 
	{ 36, 0, 6, 56, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0 }, 
	{ 26, 5, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1 }, 
	{ 45, 0, 1, 6, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0 }, 
	{ 34, 0, 2, 11, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0 }, /* 1992 */ 
	{ 22, 3, 4, 17, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0 }, 
	{ 40, 0, 5, 22, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0 }, 
	{ 30, 8, 6, 27, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1 }, 
	{ 49, 0, 0, 32, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1 }, /* 1996 */ 
	{ 37, 0, 2, 38, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1 }, 
	{ 27, 5, 3, 43, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1 }, 
	{ 46, 0, 4, 48, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1 }, 
	{ 35, 0, 5, 53, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1 }, /* 2000 */ 
	{ 23, 4, 0, 59, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1 }, 
	{ 42, 0, 1, 4, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1 }, 
	{ 31, 0, 2, 9, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0 }, 
	{ 21, 2, 3, 14, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1 }, /* 2004 */ 
	{ 39, 0, 5, 20, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1 }, 
	{ 28, 7, 6, 25, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1 }, 
	{ 48, 0, 0, 30, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1 }, 
	{ 37, 0, 1, 35, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1 }, /* 2008 */ 
	{ 25, 5, 3, 41, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1 }, 
	{ 44, 0, 4, 46, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1 }, 
	{ 33, 0, 5, 51, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1 }, 
	{ 22, 4, 6, 56, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 }, /* 2012 */ 
	{ 40, 0, 1, 2, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 }, 
	{ 30, 9, 2, 7, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1 }, 
	{ 49, 0, 3, 12, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1 }, 
	{ 38, 0, 4, 17, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0 }, /* 2016 */ 
	{ 27, 6, 6, 23, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1 }, 
	{ 46, 0, 0, 28, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0 }, 
	{ 35, 0, 1, 33, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0 }, 
	{ 24, 4, 2, 38, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1 }, /* 2020 */ 
	{ 42, 0, 4, 44, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 }, 
	{ 31, 0, 5, 49, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0 }, 
	{ 21, 2, 6, 54, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1 }, 
	{ 40, 0, 0, 59, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1 }, /* 2024 */ 
	{ 28, 6, 2, 5, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0 }, 
	{ 47, 0, 3, 10, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1 }, 
	{ 36, 0, 4, 15, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1 }, 
	{ 25, 5, 5, 20, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0 }, /* 2028 */ 
	{ 43, 0, 0, 26, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1 }, 
	{ 32, 0, 1, 31, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0 }, 
	{ 22, 3, 2, 36, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0 } }; 
#define LAST_YEAR (FIRST_YEAR+sizeof(lunarcal)/sizeof(StructLunarcal)-1) 
	/* ������ÿ��֮���� */ 
	int solarcal[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; 
	/* ������ÿ��֮�ۻ�����, ƽ�������� */ 
	int solardays[2][14] = { 
		{ 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365, 396 }, 
		{ 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366, 397 } }; 



CDataConvert::CDataConvert(void)
{
}


CDataConvert::~CDataConvert(void)
{
}

int CDataConvert::getleap( int year )
{
	if ( year % 400 == 0 ) 
		return 1; 
	else if ( year % 100 == 0 ) 
		return 0; 
	else if ( year % 4 == 0 ) 
		return 1; 
	else 
		return 0; 
}

int CDataConvert::calconv( struct convdate *cd )
{
	int leap, d, sm, y, im, l1, l2, acc, i, lm, kc; 
	if ( cd->source == 0 ) /* solar */ 
	{ 
		if ( cd->solaryear <= FIRST_YEAR || cd->solaryear > LAST_YEAR ) 
			return 1; 
		sm = cd->solarmonth - 1; 
		if ( sm < 0 || sm > 11 ) 
			return 2; 
		leap = getleap( cd->solaryear ); 
		if ( sm == 1 ) 
			d = leap + 28; 
		else 
			d = solarcal[sm]; 
		if ( cd->solardate < 1 || cd->solardate > d ) 
			return 3; 
		y = cd->solaryear - FIRST_YEAR; 
		acc = solardays[leap][sm] + cd->solardate; 
		cd->weekday = ( acc + lunarcal[y].baseweekday ) % 7; 
		kc = acc + lunarcal[y].basekanchih; 
		cd->kan = kc % 10; 
		cd->chih = kc % 12; 
		if ( acc <= lunarcal[y].basedays ) 
		{ 
			y--; 
			cd->lunaryear = cd->solaryear - 1; 
			leap = getleap( cd->lunaryear ); 
			sm += 12; 
			acc = solardays[leap][sm] + cd->solardate; 
		} 
		else 
			cd->lunaryear = cd->solaryear; 
		l1 = lunarcal[y].basedays; 
		for ( i=0; i<13; i++ ) 
		{ 
			l2 = l1 + lunarcal[y].monthdays[i] + 29; 
			if ( acc <= l2 ) 
				break; 
			l1 = l2; 
		} 
		cd->lunarmonth = i + 1; 
		cd->lunardate = acc - l1; 
		im = lunarcal[y].intercalation; 
		if ( im != 0 && cd->lunarmonth > im ) 
		{ 
			cd->lunarmonth--; 
			if ( cd->lunarmonth == im ) 
				cd->lunarmonth = -im; 
		} 
		if ( cd->lunarmonth > 12 ) 
			cd->lunarmonth -= 12; 
	} 
	else /* lunar */ 
	{ 
		if ( cd->lunaryear < FIRST_YEAR || cd->lunaryear >= LAST_YEAR ) 
			return 1; 
		y = cd->lunaryear - FIRST_YEAR; 
		im = lunarcal[y].intercalation; 
		lm = cd->lunarmonth; 
		if ( lm < 0 ) 
		{ 
			if ( lm != -im ) 
				return 2; 
		} 
		else if ( lm < 1 || lm > 12 ) 
			return 2; 
		if ( im != 0 ) 
		{ 
			if ( lm > im ) 
				lm++; 
			else if ( lm == -im ) 
				lm = im + 1; 
		} 
		lm--; 
		if ( cd->lunardate > lunarcal[y].monthdays[lm] + 29 ) 
			return 3; 
		acc = lunarcal[y].basedays; 
		for ( i=0; i < 13;i++)
			acc += lunarcal[y].monthdays[i] + 29;
		acc += cd->lunardate; 
		leap = getleap( cd->lunaryear ); 
		for ( i=13; i>=0; i-- ) 
			if ( acc > solardays[leap][i] ) 
				break; 
		cd->solardate = acc - solardays[leap][i]; 
		if ( i <= 11 ) 
		{ 
			cd->solaryear = cd->lunaryear; 
			cd->solarmonth = i + 1; 
		} 
		else 
		{ 
			cd->solaryear = cd->lunaryear + 1; 
			cd->solarmonth = i - 11; 
		} 
		leap = getleap( cd->solaryear ); 
		y = cd->solaryear - FIRST_YEAR; 
		acc = solardays[leap][cd->solarmonth-1] + cd->solardate; 
		cd->weekday = ( acc + lunarcal[y].baseweekday ) % 7; 
		kc = acc + lunarcal[y].basekanchih; 
		cd->kan = kc % 10; 
		cd->chih = kc % 12; 
	} 
	return 0; 
}

CString CDataConvert::GetDayOf( PSYSTEMTIME pSt )
{
	/*�������*/
	const TCHAR *cTianGan[] = {_T("��"),_T("��"),_T("��"),_T("��"),_T("��"),_T("��"),_T("��"),_T("��"),_T("��"),_T("��")};
	/*��֧����*/
	const TCHAR *cDiZhi[] = {_T("��"),_T("��"),_T("��"),_T("î"),_T("��"),_T("��"),_T("��"),
		_T("δ"),_T("��"),_T("��"),_T("��"),_T("��")};
	/*��������*/
	const TCHAR *cShuXiang[] = {_T("��"),_T("ţ"),_T("��"),_T("��"),_T("��"),_T("��"),
		_T("��"),_T("��"),_T("��"),_T("��"),_T("��"),_T("��")};
	/*ũ��������*/
	const TCHAR *cDayName[] = {_T("*"),_T("��һ"),_T("����"),_T("����"),_T("����"),_T("����"),
		_T("����"),_T("����"),_T("����"),_T("����"),_T("��ʮ"),
		_T("ʮһ"),_T("ʮ��"),_T("ʮ��"),_T("ʮ��"),_T("ʮ��"),
		_T("ʮ��"),_T("ʮ��"),_T("ʮ��"),_T("ʮ��"),_T("��ʮ"),
		_T("إһ"),_T("إ��"),_T("إ��"),_T("إ��"),_T("إ��"),       
		_T("إ��"),_T("إ��"),_T("إ��"),_T("إ��"),_T("��ʮ")};
	/*ũ���·���*/
	const TCHAR *cMonName[] = {_T("*"),_T("��"),_T("��"),_T("��"),_T("��"),_T("��"),_T("��"),
		_T("��"),_T("��"),_T("��"),_T("ʮ"),_T("ʮһ"),_T("��")};
	/*����ÿ��ǰ�������*/
	const int wMonthAdd[12] = {0,31,59,90,120,151,181,212,243,273,304,334};
	/*ũ������*/
	const int wNongliData[100] = {2635,333387,1701,1748,267701,694,2391,133423,1175,396438
		,3402,3749,331177,1453,694,201326,2350,465197,3221,3402
		,400202,2901,1386,267611,605,2349,137515,2709,464533,1738
		,2901,330421,1242,2651,199255,1323,529706,3733,1706,398762
		,2741,1206,267438,2647,1318,204070,3477,461653,1386,2413
		,330077,1197,2637,268877,3365,531109,2900,2922,398042,2395
		,1179,267415,2635,661067,1701,1748,398772,2742,2391,330031
		,1175,1611,200010,3749,527717,1452,2742,332397,2350,3222
		,268949,3402,3493,133973,1386,464219,605,2349,334123,2709
		,2890,267946,2773,592565,1210,2651,395863,1323,2707,265877};
	static int wCurYear,wCurMonth,wCurDay;
	static int nTheDate,nIsEnd,m,k,n,i,nBit;
	TCHAR szNongli[30] = {0}, szNongliDay[10] = {0},szShuXiang[10] = {0};
	/*---ȡ��ǰ�����ꡢ�¡���---*/
	wCurYear = pSt->wYear;
	wCurMonth = pSt->wMonth;
	wCurDay = pSt->wDay;
	/*---���㵽��ʼʱ��1921��2��8�յ�������1921-2-8(���³�һ)---*/
	nTheDate = (wCurYear - 1921) * 365 + (wCurYear - 1921) / 4 + wCurDay + wMonthAdd[wCurMonth - 1] - 38;
	if((!(wCurYear % 4)) && (wCurMonth > 2))
		nTheDate = nTheDate + 1;
	/*--����ũ����ɡ���֧���¡���---*/
	nIsEnd = 0;
	m = 0;
	while(nIsEnd != 1)
	{
		if(wNongliData[m] < 4095)
			k = 11;
		else
			k = 12;
		n = k;
		while(n>=0)
		{
			//��ȡwNongliData(m)�ĵ�n��������λ��ֵ
			nBit = wNongliData[m];
			for(i=1;i<n+1;i++)
				nBit = nBit/2;
			nBit = nBit % 2;
			if (nTheDate <= (29 + nBit))
			{
				nIsEnd = 1;
				break;
			}
			nTheDate = nTheDate - 29 - nBit;
			n = n - 1;
		}
		if(nIsEnd)
			break;
		m = m + 1;
	}
	wCurYear = 1921 + m;
	wCurMonth = k - n + 1;
	wCurDay = nTheDate;
	if (k == 12)
	{
		if (wCurMonth == wNongliData[m] / 65536 + 1)
			wCurMonth = 1 - wCurMonth;
		else if (wCurMonth > wNongliData[m] / 65536 + 1)
			wCurMonth = wCurMonth - 1;
	}
	/*--����ũ����ɡ���֧������ ==> wNongli--*/
	int curPos = ((wCurYear - 4) % 60) % 12;
	wsprintf(szShuXiang,_T("%s"),cShuXiang[curPos]);
	wsprintf(szNongli,_T("%s(%s%s)��"),szShuXiang,cTianGan[((wCurYear - 4) % 60) % 10],cDiZhi[((wCurYear - 4) % 60) % 12]);
	/*--����ũ���¡��� ==> wNongliDay--*/
	if (wCurMonth < 1)
		wsprintf(szNongliDay,_T("��%s"),cMonName[-1 * wCurMonth]);
	else
		_tcscat(szNongliDay,cMonName[wCurMonth]);
	_tcscat(szNongliDay,_T("��"));
	_tcscat(szNongliDay,cDayName[wCurDay]);

	CString strRet = szNongli;
	strRet += szNongliDay;
	return strRet;
}
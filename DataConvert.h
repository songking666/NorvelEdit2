#pragma once

#define FIRST_YEAR 1936 /* the first year in lunarcal[] */ 

struct convdate 
{ 
	int source; 
	int solaryear; 
	int solarmonth; 
	int solardate; 
	int lunaryear; 
	int lunarmonth; 
	int lunardate; 
	int weekday; 
	int kan; 
	int chih; 
}; 

typedef struct tag_lunarcal 
{ 
	int basedays; /* 到西历 1 月 1 日到农历正月初一的累积日数 */ 
	int intercalation; /* 闰月月份. 0==此年没有闰月 */ 
	int baseweekday; /* 此年西历 1 月 1 日为星期几再减 1 */ 
	int basekanchih; /* 此年西历 1 月 1 日之干支序号减 1 */ 
	int monthdays[13]; /* 此农历年每月之大小, 0==小月(29日), 1==大月(30日)*/ 
}StructLunarcal; 

class CDataConvert
{
public:
	CDataConvert(void);
	~CDataConvert(void);
public:
	int getleap( int year );
	int calconv( struct convdate *cd );
	CString GetDayOf(PSYSTEMTIME pSt);
};


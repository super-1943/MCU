//======================================================
// 文件名称：	Clock_Speech.c
// 功能描述：	语音播报日期和时间的函数集
// 维护记录：	2006-08-30	v1.0
//======================================================

#include "Clock.h"
#include "Sound.h"

//=============================================================
// 语法格式：	void PlayNum(unsigned int Num);
// 实现功能：	播放100以内的数字
// 参数：		Num - 待播报的数字
// 返回值：		无
//=============================================================
void PlayNum(unsigned int Num)
{
	unsigned int TempNum = Num;
	
	if(TempNum==0)									// 数字为0则直接播报0
		PlaySnd(S_0);
	else
	{
		if(TempNum>=20) PlaySnd(TempNum/10);		// 十位
		if(TempNum>=10) PlaySnd(S_10);				// "十"
		TempNum = TempNum % 10;
		if(TempNum>0) PlaySnd(TempNum);				// 个位
	}
}

//=============================================================
// 语法格式：	void PlayYear(unsigned int Year);
// 实现功能：	播报年
// 参数：		Year - 待播报的年
// 返回值：		无
//=============================================================
void PlayYear(unsigned int Year)
{
	unsigned int TempYear = Year;
	
	PlaySnd(TempYear/1000);							// 千位
	TempYear = TempYear % 1000;
	PlaySnd(TempYear/100);							// 百位
	TempYear = TempYear % 100;
	PlaySnd(TempYear/10);							// 十位
	TempYear = TempYear % 10;
	PlaySnd(TempYear);								// 个位
	PlaySnd(S_Nian);								// "年"
}

//=============================================================
// 语法格式：	void PlayMon(unsigned int Mon);
// 实现功能：	播报月
// 参数：		Mon - 待播报的月
// 返回值：		无
//=============================================================
void PlayMon(unsigned int Mon)
{
	PlaySnd(Mon);
	PlaySnd(S_Yue);
}

//=============================================================
// 语法格式：	void PlayDay(unsigned int Day);
// 实现功能：	播报日
// 参数：		Day - 待播报的日
// 返回值：		无
//=============================================================
void PlayDay(unsigned int Day)
{
	PlayNum(Day);
	PlaySnd(S_Ri);
}

//=============================================================
// 语法格式：	void PlayHour(unsigned int Hour);
// 实现功能：	播报小时
// 参数：		Hour - 待播报的时
// 返回值：		无
//=============================================================
void PlayHour(unsigned int Hour)
{
	if(Hour<=5) PlaySnd(S_LC);						// 凌晨(0~5点)
	else if(Hour<=11) PlaySnd(S_SW);				// 上午(6~11点)
	else if(Hour<=17) PlaySnd(S_XW);				// 下午(12~17点)
	else PlaySnd(S_WS);								// 晚上(18~23点)
	
	if(Hour==2 || Hour==14) PlaySnd(S_Liang);		// 2点和14点播报"两"
	else if(Hour>12) PlaySnd(Hour-12);				// 12小时制
	else PlaySnd(Hour);
	PlaySnd(S_Dian);								// "点"
}

//=============================================================
// 语法格式：	void PlayMin(unsigned int Min);
// 实现功能：	播报分
// 参数：		Min - 待播报的分
// 返回值：		无
//=============================================================
void PlayMin(unsigned int Min)
{
	if(Min==0)PlaySnd(S_Zheng);						// 00分播报"整"
	else
	{
		PlayNum(Min);								// 播报数字
		PlaySnd(S_Fen);								// "分"
	}
}

//=============================================================
// 语法格式：	void PlaySec(unsigned int Sec);
// 实现功能：	播报秒
// 参数：		Sec - 待播报的秒
// 返回值：		无
//=============================================================
void PlaySec(unsigned int Sec)
{
	PlayNum(Sec);
	PlaySnd(S_Miao);
}

//=============================================================
// 语法格式：	void PlayTime();
// 实现功能：	播报当前时间
// 参数：		无
// 返回值：		无
//=============================================================
void PlayTime()
{
	unsigned int TempHour, TempMin;
	
	TempHour = Clock_GetHour();
	TempMin = Clock_GetMin();
	
	PlaySnd(S_DING);
	PlaySnd(S_XZSK);
	PlayHour(TempHour);
	PlayMin(TempMin);
}

//=============================================================
// 语法格式：	void PlayDate();
// 实现功能：	播报当前日期
// 参数：		无
// 返回值：		无
//=============================================================
void PlayDate()
{
	unsigned int TempYear, TempMon, TempDay;
	
	TempYear = Clock_GetYear();
	TempMon = Clock_GetMon();
	TempDay = Clock_GetDay();
	
	PlayYear(TempYear);
	PlayMon(TempMon);
	PlayDay(TempDay);
}

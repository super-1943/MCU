//======================================================
// 文件名称：	Clock_Adjust.c
// 功能描述：	调整日期和时间的函数集
// 维护记录：	2006-08-30	v1.0
//======================================================

#include "spce061a.h"
#include "Sound.h"
#include "Clock.h"
#include "Clock_Speech.h"
#include "Key.h"

//=============================================================
// 语法格式：	unsigned int AdjustYear(unsigned int Year);
// 实现功能：	调整年
// 参数：		Year - 调整前的年
// 返回值：		调整后的年
//=============================================================
unsigned int AdjustYear(unsigned int Year)
{
	unsigned int KeyCode;
	unsigned int TempYear = Year;
	
	PlayYear(TempYear);								// 播放当前年
	while(1)
	{
		*P_Watchdog_Clear = 0x01;
		KeyCode = Key_Get();						// 获取按键
		switch(KeyCode)
		{
			case KEY_1:
				return TempYear;					// 按Key1键返回调整后的年
			case KEY_2:
				TempYear++;							// 按Key2键，年数加1
				PlayYear(TempYear);
				break;
			case KEY_3:
				TempYear--;							// 按Key3键，年数减1
				PlayYear(TempYear);
				break;
			default:
				break;
		}
	}
}

//=============================================================
// 语法格式：	unsigned int AdjustMon(unsigned int Mon);
// 实现功能：	调整月
// 参数：		Mon - 调整前的月
// 返回值：		调整后的月
//=============================================================
unsigned int AdjustMon(unsigned int Mon)
{
	unsigned int KeyCode;
	unsigned int TempMon = Mon;
	
	PlayMon(TempMon);								// 播报调整前的月
	while(1)
	{
		*P_Watchdog_Clear = 0x01;
		KeyCode = Key_Get();
		switch(KeyCode)
		{
			case KEY_1:								// Key1，返回调整后的月
				return TempMon;
			case KEY_2:
				TempMon++;							// Key2，月数加1，到12后回复为1
				if(TempMon>12) TempMon = 1;	
				PlayMon(TempMon);
				break;
			case KEY_3:
				TempMon--;							// Key3，月数减1，到1后变为12
				if(TempMon<1) TempMon = 12;
				PlayMon(TempMon);
				break;
			default:
				break;
		}
	}	
}

//=============================================================
// 语法格式：	unsigned int AdjustDay(unsigned int Year, unsigned int Mon, unsigned int Day);
// 实现功能：	调整日
// 参数：		Year - 调整后的年
//				Mon - 调整后的月
//				Day - 调整前的日
// 返回值：		调整后的日
//=============================================================
unsigned int AdjustDay(unsigned int Year, unsigned int Mon, unsigned int Day)
{
	unsigned int KeyCode;
	unsigned int TempDay = Day;
	
	if(TempDay > Month_Day[Mon-1])					// 如果当前的日期已经超过调整后月的最大天数则日期置为1
	{
		if(TempDay==29)								// 处理闰年
		{
			if((Year&0x03)!=0) TempDay = 1;
		}
		else TempDay = 1;
	}
		
	PlayDay(TempDay);								// 播放调整前日
	while(1)
	{
		*P_Watchdog_Clear = 0x01;
		KeyCode = Key_Get();
		switch(KeyCode)
		{
			case KEY_1:
				return TempDay;						// Key1，返回调整后日
			case KEY_2:
				TempDay++;							// Key2，日数加1，达到当月最大日之后回复为1
				if(TempDay > Month_Day[Mon-1])
				{
					if(TempDay==29)					// 处理闰年
					{
						if((Year&0x03)!=0) TempDay = 1;
					}
					else TempDay = 1;
				}
				PlayDay(TempDay);
				break;
			case KEY_3:
				TempDay--;							// Key3，日数减1，减到0时转为当月最大日
				if(TempDay<1)
				{
					 if(Mon==2 && (Year&0x03)==0) TempDay = 29;					 	
					 else TempDay = Month_Day[Mon-1];
				}
				PlayDay(TempDay);
				break;
			default:
				break;
		}
	}	
}

//=============================================================
// 语法格式：	unsigned int AdjustHour(unsigned int Hour);
// 实现功能：	调整小时
// 参数：		Hour - 调整前的时
// 返回值：		调整后的时
//=============================================================
unsigned int AdjustHour(unsigned int Hour)
{
	unsigned int KeyCode;
	unsigned int TempHour = Hour;
	
	PlayHour(TempHour);								// 播报整前小时数
	while(1)
	{
		*P_Watchdog_Clear = 0x01;
		KeyCode = Key_Get();
		switch(KeyCode)
		{
			case KEY_1:
				return TempHour;					// Key1，返回调整后的小时
			case KEY_2:
				TempHour++;							// Key2，时数加1，到23后回复为0
				if(TempHour>23) TempHour = 0;
				PlayHour(TempHour);
				break;
			case KEY_3:
				if(TempHour==0) TempHour = 23;		// Key3，时数减1，到0后回复为23
				else TempHour--;
				PlayHour(TempHour);
				break;
			default:
				break;
		}
	}	
}

//=============================================================
// 语法格式：	unsigned int AdjustMin(unsigned int Min);
// 实现功能：	调整分
// 参数：		Min - 调整前的分
// 返回值：		调整后的分
//=============================================================
unsigned int AdjustMin(unsigned int Min)
{
	unsigned int KeyCode;
	unsigned int TempMin = Min;
	
	PlayNum(TempMin);								// 播报调整前的分钟数
	PlaySnd(S_Fen);
	while(1)
	{
		*P_Watchdog_Clear = 0x01;
		KeyCode = Key_Get();
		switch(KeyCode)
		{
			case KEY_1:
				return TempMin;						// Key1，返回调整后的分
			case KEY_2:
				TempMin++;							// Key2，分钟数加1，到59后变为0
				if(TempMin>59) TempMin = 0;
				PlayNum(TempMin);
				PlaySnd(S_Fen);
				break;
			case KEY_3:
				if(TempMin==0) TempMin = 59;		// Key3，分钟数减1，到0后变为59
				else TempMin--;
				PlayNum(TempMin);
				PlaySnd(S_Fen);
				break;
			default:
				break;
		}
	}	
}

//=============================================================
// 语法格式：	unsigned int AdjustSec(unsigned int Sec);
// 实现功能：	调整秒
// 参数：		Sec - 调整前的秒
// 返回值：		调整后的秒
//=============================================================
unsigned int AdjustSec(unsigned int Sec)
{
	unsigned int KeyCode;
	unsigned int TempSec = Sec;
	
	PlaySec(TempSec);								// 播报调整前的秒数
	while(1)
	{
		*P_Watchdog_Clear = 0x01;
		KeyCode = Key_Get();
		switch(KeyCode)
		{
			case KEY_1:
				return TempSec;						// Key1，返回调整后的秒
			case KEY_2:
				TempSec++;							// Key2，秒加1，到59后变为0
				if(TempSec>59) TempSec = 0;
				PlaySec(TempSec);
				break;
			case KEY_3:
				if(TempSec==0) TempSec = 59;		// Key3，秒减1，到0后变为59
				else TempSec--;
				PlaySec(TempSec);
				break;
			default:
				break;
		}
	}	
}

//=============================================================
// 语法格式：	void Adjust(void);
// 实现功能：	调整日期时间
// 参数：		无
// 返回值：		无
//=============================================================
void Adjust()
{
	unsigned int TempYear, TempMon, TempDay, TempHour, TempMin, TempSec;
	
	TempYear = AdjustYear(Clock_GetYear());			// 调整年
	TempMon = AdjustMon(Clock_GetMon());			// 调整月
	TempDay = AdjustDay(TempYear, TempMon, Clock_GetDay());	// 调整日
	TempHour = AdjustHour(Clock_GetHour());			// 调整时
	TempMin = AdjustMin(Clock_GetMin());			// 调整分
	TempSec = AdjustSec(Clock_GetSec());			// 调整秒
	
	Clock_SetYear(TempYear);						// 保存调整后的日期时间
	Clock_SetMon(TempMon);
	Clock_SetDay(TempDay);
	Clock_SetHour(TempHour);
	Clock_SetMin(TempMin);
	Clock_SetSec(TempSec);

	PlaySnd(S_DING);								// 播报调整后的日期时间
	PlayYear(TempYear);
	PlayMon(TempMon);
	PlayDay(TempDay);
	PlayHour(TempHour);
	PlayMin(TempMin);	
}

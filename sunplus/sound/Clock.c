//======================================================
// 文件名称：	Clock.c
// 功能描述：	计时模块，使用2Hz时基中断
// 维护记录：	2006-08-30	v1.0
//======================================================

#include "spce061a.h"

typedef struct STR_CLOCK							// 定义时钟结构体
{
	unsigned int Year;
	unsigned int Mon;
	unsigned int Day;
	unsigned int Hour;
	unsigned int Min;
	unsigned int Sec;
	unsigned int HalfSec;
}CLOCK;

CLOCK Clock = {2006, 1, 1, 0, 0, 0, 0};				// 时钟初始值2006年1月1日0点0分

const unsigned int Month_Day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
													// 每月包含的天数

//=============================================================
// 语法格式：	void Clock_ISR(void);
// 实现功能：	计时模块的2Hz中断服务程序，应在IRQ5_2Hz中断中调用
// 参数：		无
// 返回值：		无
//=============================================================
void Clock_ISR()
{
	if(Clock.HalfSec==0)							// 0.5秒
		Clock.HalfSec = 1;
	else
	{
		Clock.HalfSec = 0;
		Clock.Sec += 1;
		if(Clock.Sec==60)							// 处理秒进位
		{
			Clock.Sec = 0;
			Clock.Min += 1;
			if(Clock.Min==60)						// 处理分进位
			{
				Clock.Min = 0;
				Clock.Hour += 1;
				if(Clock.Hour==24)					// 处理小时进位
				{
					Clock.Hour = 0;
					Clock.Day += 1;					// 处理天进位
					if(Clock.Day > Month_Day[Clock.Mon-1])
					{
						if(Clock.Mon!=2 || (Clock.Year&0x03)!=0 || Clock.Day>29)
						{							// 如果是闰年则2月29日不进位
							Clock.Day = 1;
							Clock.Mon += 1;
							if(Clock.Mon > 12)		// 处理月进位
							{
								Clock.Mon = 1;
								Clock.Year += 1;
							}
						}
					}
				}
			}
		}
	}
}

//=============================================================
// 语法格式：	void Clock_Start(void);
// 实现功能：	开始计时
// 参数：		无
// 返回值：		无
//=============================================================
void Clock_Start()
{
	*P_INT_Ctrl_New |= C_IRQ5_2Hz;
	__asm("IRQ ON");
}


//=============================================================
// 语法格式：	unsigned int Clock_GetYear();
// 实现功能：	查询当前年
// 参数：		无
// 返回值：		当前年
//=============================================================
unsigned int Clock_GetYear()
{
	return Clock.Year;
}

//=============================================================
// 语法格式：	unsigned int Clock_GetMon(void);
// 实现功能：	查询当前月
// 参数：		无
// 返回值：		当前月
//=============================================================
unsigned int Clock_GetMon()
{
	return Clock.Mon;
}

//=============================================================
// 语法格式：	unsigned int Clock_GetDay(void);
// 实现功能：	查询当前日
// 参数：		无
// 返回值：		当前日
//=============================================================
unsigned int Clock_GetDay()
{
	return Clock.Day;
}

//=============================================================
// 语法格式：	unsigned int Clock_GetHour(void);
// 实现功能：	查询当前小时
// 参数：		无
// 返回值：		当前时
//=============================================================
unsigned int Clock_GetHour()
{
	return Clock.Hour;
}

//=============================================================
// 语法格式：	unsigned int Clock_GetMin(void);
// 实现功能：	查询当前分
// 参数：		无
// 返回值：		当前分
//=============================================================
unsigned int Clock_GetMin()
{
	return Clock.Min;
}

//=============================================================
// 语法格式：	unsigned int Clock_GetSec(void);
// 实现功能：	查询当前秒
// 参数：		无
// 返回值：		当前秒
//=============================================================
unsigned int Clock_GetSec()
{
	return Clock.Sec;
}

//=============================================================
// 语法格式：	void Clock_SetYear(unsigned int Year);
// 实现功能：	设置年
// 参数：		Year - 年
// 返回值：		无
//=============================================================
void Clock_SetYear(unsigned int Year)
{
	Clock.Year = Year;
}

//=============================================================
// 语法格式：	void Clock_SetMon(unsigned int Mon);
// 实现功能：	设置月
// 参数：		Mon - 月
// 返回值：		无
//=============================================================
void Clock_SetMon(unsigned int Mon)
{
	Clock.Mon = Mon;
}

//=============================================================
// 语法格式：	void Clock_SetDay(unsigned int Day);
// 实现功能：	设置日
// 参数：		Day - 日
// 返回值：		无
//=============================================================
void Clock_SetDay(unsigned int Day)
{
	Clock.Day = Day;
}

//=============================================================
// 语法格式：	void Clock_SetHour(unsigned int Hour);
// 实现功能：	设置小时
// 参数：		Hour - 时
// 返回值：		无
//=============================================================
void Clock_SetHour(unsigned int Hour)
{
	Clock.Hour = Hour;
}

//=============================================================
// 语法格式：	void Clock_SetMin(unsigned int Min);
// 实现功能：	设置分
// 参数：		Min - 分
// 返回值：		无
//=============================================================
void Clock_SetMin(unsigned int Min)
{
	Clock.Min = Min;
}

//=============================================================
// 语法格式：	void Clock_SetSec(unsigned int Sec);
// 实现功能：	设置秒
// 参数：		Sec - 秒
// 返回值：		无
//=============================================================
void Clock_SetSec(unsigned int Sec)
{
	*P_TimeBase_Clear = 0x01;						// 时基计数器清零
	Clock.Sec = Sec;			
	Clock.HalfSec = 0;								// 半秒计数清零
}

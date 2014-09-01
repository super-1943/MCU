//======================================================
//  The information contained herein is the exclusive property of
//  Sunnnorth Technology Co. And shall not be distributed, reproduced,
//  or disclosed in whole in part without prior written permission.
//             (C) COPYRIGHT 2003  SUNNORTH TECHNOLOGY CO.
//                          ALL RIGHTS RESERVED
//  The entire notice above must be reproduced on all authorized copies.
//========================================================

//============================================================
//  工程名称：	61_SpeechClock
//  功能描述：	61板程序示例--具有语音播报功能的电子钟
//				使用61板上的三个按键控制报时和时间调整：
//					Key1 - 按一下播报年、月、日，再按一下播报时、分
//						   长按Key1键达到1.5秒，则进入日期时间调整模式
//					Key2 - 在调整模式下，使年、月、日、时、分、秒增加
//					Key3 - 在调整模式下，使年、月、日、时、分、秒减小
//  涉及的库：	CMacro1016.lib
//            	SacmV26e.lib
//  组成文件：	main.c, Sound.c, Clock.c, Clock_Speech.c, Clock_Adjust.c
//				Key.asm, hardware.asm, ISR.asm
//				A2000.h, Sound.h, Clock.h, Clock_Speech.h, Clock_Adjust.h, Key.h, SPCE061A.h, 
//	硬件连接：	61板自带的三个按键已经连接在IOA0~IOA2上
//	维护记录：	2006-8-30 v1.0
//===============================================

//======================================================
// 文件名称：	main.c
// 功能描述：	主程序
// 维护记录：	2006-08-30	v1.0
//======================================================
#include "spce061a.h"
#include "Sound.h"
#include "Key.h"
#include "Clock.h"
#include "Clock_Speech.h"
#include "Clock_Adjust.h"

//=============================================================
// 语法格式：	int main(void);
// 实现功能：	主函数
// 参数：		无
// 返回值：		无
//=============================================================
int main()
{
	unsigned int KeyCode;
	unsigned int Flag = 0;
	
	Key_Init();										// 初始化按键扫描程序
	Clock_Start();									// 初始化计时程序

	while(1)
	{
		KeyCode = Key_Get();						// 获取按键值
		switch(KeyCode)
		{
			case KEY_1:								// Key1键，播放日期/时间
				if(Flag==0)
				{
					PlayDate();
					Flag = 1;
				}
				else
				{
					PlayTime();
					Flag = 0;
				}
				break;
			case KEY_LONG_1:						// Key1键长按，调整日期和时间
				Adjust();
				break;
			default:
				break;
		}
		*P_Watchdog_Clear = 0x01;					// 清看门狗
		*P_SystemClock = 0x001F;					// 进入睡眠模式
	}
}


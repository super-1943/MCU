//======================================================================
//	工程名称：	Send.spj
//	功能描述：	nRF2401 无线模组配套演示程序发送端程序，
//				运行程序后，按任意键，接收端将语音播报键值
//
//  IDE环境：   SUNPLUS u'nSPTM  IDE 2.0.0（or later）
//	涉及的库：	CMacro1016.lib
//	组成文件：	main.c, nRF2401.c
//				SPCE061A.h, nRF2401.h
//				SPCE061A.inc
//	硬件连接：	IOA0 - Key1(61板)
//				IOA1 - Key2(61板)
//				IOA2 - Key3(61板)
//
//				IOB0 - PWR(无线模组)
//				IOB1 - CE(无线模组)
//				IOB2 - CS(无线模组)
//				IOB3 - DR1(无线模组)
//				IOB4 - CLK1(无线模组)
//				IOB5 - DATA1(无线模组)

//	维护记录：	2006-10-20	v1.0
//======================================================================

//====================================================================================
//文 件 名: main.c
//功能描述: 实现键值的扫描和发送
//维护记录: 2006年10月20
//====================================================================================
#include "nRF2401.h"
#include "SPCE061A.h"

unsigned int Address[5] = {0x00,0x00,0x00,0x00,0x01};
										// 接收端地址:00 00 00 00 01

int main()
{
	unsigned int i,key;
	nRF2401_Initial();					// 初始化nRF2401A
	nRF2401_Mode(1);					// 设置nRF2401A工作方式:发送
	nRF2401_SetAddress(Address,5);		// 设置接收端地址 00 00 00 00 01
	while(1)
	{
		*P_Watchdog_Clear = 0x1;
		key = *P_IOA_Data;
		key &= 0x0007;
		if(key != 0)
		{
			switch(key)
			{
				case 1:
					nRF2401_SendByte(0x01);			// 发送键号"1"
					Delay_Us(100);
					break;
				case 2:
					nRF2401_SendByte(0x02);			// 发送键号"2"
					Delay_Us(100);
					break;
				case 4:
					nRF2401_SendByte(0x03);			// 发送键号"3"
					Delay_Us(100);
					break;
				default:
					break;
			}
			for(i=0; i<10; i++)						// 延时一定时间
			{
				Delay_Us(60000);
			}
		}
	}
}

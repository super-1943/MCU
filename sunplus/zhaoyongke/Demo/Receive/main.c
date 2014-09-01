//======================================================================
//	工程名称：	Receive.spj
//	功能描述：	nRF2401 无线模组配套演示程序接收端程序，
//				运行程序后，如果发送端有键按下，则语音播报键值
//
//  IDE环境：   SUNPLUS u'nSPTM  IDE 2.0.0（or later）
//	涉及的库：	CMacro1016.lib
//              SACMv41dx_061A.lib
//	组成文件：	main.c, nRF2401.c, SACM_A1600_User_C.c, Snd.c
//				SACM_A1600.asm
//				SPCE061A.h, nRF2401.h, A1600.h, Snd.h
//				SPCE061A.inc, A1600.inc
//	硬件连接：
//				J3  -- 喇叭(61板)
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
//功能描述: 实现键值接收和语音播报
//维护记录: 2006年10月20
//====================================================================================
#include "spce061a.h"
#include "nRF2401.h"
#include "Snd.h"
#include "led.h"
unsigned int RxBuf[25];									// 接收缓冲,保存接收到的数据
extern void getkey(void);

int main()
{
	nRF2401_Initial();									// nRF2401A初始化
	nRF2401_Mode(0);									// 设置nRF2401A工作方式:接收
	*P_IOA_Dir=0xff00;
	*P_IOA_Attrib=0xff00;
	*P_IOA_Data=0xff00;
	*P_IOB_Dir|=0xff00;
	*P_IOB_Attrib|=0xff00;
	*P_IOB_Data|=0xff00;
	while(1)
	{
		*P_Watchdog_Clear = 0x0001;
		getkey();
		show(RxBuf,8);
		if((nRF2401_RxStatus()) == 1)					// nRF2401A有数据请求
		{
			nRF2401_ReceiveByte(RxBuf);					// 接收数据
			switch(RxBuf[0])
			{
				case 1:
					PlaySnd(0);							// 播放语音"Key1"
					break;
				case 2:
					PlaySnd(1);							// 播放语音"Key3"
					break;
				case 3:
					PlaySnd(2);							// 播放语音"Key2"
					break;
				default:
					break;
			}
		}
	}
}

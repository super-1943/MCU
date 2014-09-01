#include "spce061a.h"
#include "A1600.h"

//========================================================================
//	语音播放函数，参数SndIdx为待播放的语音序号，起始序号为0
//========================================================================
void PlaySnd(unsigned int SndIdx)
{
	SACM_A1600_Initial();					// A1600初始化
	SACM_A1600_Play(SndIdx, DAC_1+DAC_2, RAMP_UP_DN);
											// 播放第SndIdx段语音，由DAC1和DAC2输出
	while(SACM_A1600_Status()&STATUS_PLAY)	// 检测播放是否完成
	{
		*P_Watchdog_Clear = 0x01;			// 清看门狗
		SACM_A1600_ServiceLoop();			// 执行语音解码
	}
}

//========================================================================
//	中断服务程序
//========================================================================
void FIQ(void)__attribute__((ISR));

void FIQ()
{
	*P_INT_Clear = C_FIQ_TMA;				// 清中断请求标志
	SACM_A1600_ISR();						// 调用中断服务子程序
}

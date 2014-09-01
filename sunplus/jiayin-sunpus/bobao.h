#ifndef	__BOBAO_h__
#define	__BOBAO_h__
//	write your header here
//========================================================
//	语法格式：	void PlaySnd_Auto(unsigned int uiSndIndex,
//								unsigned int uiDAC_Channel)
//	实现功能：	通过自动方式播放语音资源
//	参数：		1.uiSndIndex：语音资源序号 
//				2.uiDAC_Channel：语音播放通道
//	返回值：	无
//========================================================

void PlaySnd_Auto(unsigned int uiSndIndex,unsigned int uiDAC_Channel)
{
	SACM_S480_Initial(1);						//初始化为自动播放方式
	SACM_S480_Play(uiSndIndex,uiDAC_Channel,3);	//播放
	while((SACM_S480_Status() & 0x0001) != 0)
	{											//判断播放状态，如还在播放则继续循环
		SACM_S480_ServiceLoop();				//播放系统服务程序
		*P_Watchdog_Clear = 0x0001;			
	}	
	SACM_S480_Stop();							//停止播放
}
#endif

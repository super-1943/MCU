//======================================================
//  The information contained herein is the exclusive property of
//  Sunnnorth Technology Co. And shall not be distributed, reproduced,
//  or disclosed in whole in part without prior written permission.
//  (C) COPYRIGHT 2003  SUNNORTH TECHNOLOGY CO.
//  ALL RIGHTS RESERVED
//  The entire notice above must be reproduced on all authorized copies.
//========================================================

//========================================================
//  工程名称：	Car_Demo
//  功能描述：	实现小车的语音控制
//  涉及的库：	CMacro.lib
//            	bsrsd.lib
//  组成文件：	main.c
//				Flash.asm, hardware.asm,ISR.asm 
//     			hardware.h,s480.h, hardware.inc
//	硬件连接：	见新版语音控制小车说明书
//	维护记录：	2005-9-11 v1.0
//========================================================

#include "s480.h"
#include "bsrsd.h"

#define	P_IOA_Data 			(volatile unsigned int *)0x7000   
#define P_IOA_Dir 			(volatile unsigned int *)0x7002
#define P_IOA_Attrib 		(volatile unsigned int *)0x7003
#define P_IOB_Data			(volatile unsigned int *)0x7005  
#define P_IOB_Dir			(volatile unsigned int *)0x7007   
#define P_IOB_Attrib		(volatile unsigned int *)0x7008   
#define P_TimerA_Data		(volatile unsigned int *)0x700A   
#define P_TimerA_Ctrl		(volatile unsigned int *)0x700B   
#define P_TimerB_Data		(volatile unsigned int *)0x700C   
#define P_TimerB_Ctrl		(volatile unsigned int *)0x700D   
#define P_Watchdog_Clear	(volatile unsigned int *)0x7012   

#define NAME_ID 			0x100
#define COMMAND_GO_ID 		0x101
#define COMMAND_BACK_ID 	0x102
#define COMMAND_LEFT_ID 	0x103
#define COMMAND_RIGHT_ID 	0x104

#define S_NAME				0							//给我取个名字吧
#define S_ACT1				1							//前进
#define S_ACT2				2							//倒车，请注意
#define S_ACT3				3							//左拐
#define S_ACT4				4							//右拐	
#define S_RDY				5							//Yeah
#define S_AGAIN				6							//请再说一遍
#define S_NOVOICE			7							//没有听到任何声音
#define S_CMDDIFF			8							//说什么暗语呀
#define S_NOISY				8							//说什么暗语呀
#define S_START				9							//准备就绪，开始辨识	
#define S_GJG				10							//拐就拐

extern  unsigned int BSR_SDModel[100];					//外部变量BSR_SDModel[100]，辨识器自带
extern void F_FlashWrite1Word(unsigned int addr,unsigned int Value);
extern void F_FlashErase(unsigned int sector);

//=============================================================
// 语法格式：	void Delay();
// 实现功能：	延时
// 参数：		无
// 返回值：		无
//=============================================================
void Delay()							
{
	unsigned int i;
	for(i=0;i<0x3Fff;i++)
	{
		*P_Watchdog_Clear=0x0001;
	}
}

//=============================================================
// 语法格式：	void PlaySnd(unsigned SndIndex,unsigned DAC_Channel);
// 实现功能：	语音播放函数
// 参数：		SndIndex-播放语音资源索引号
//				DAC_Channel-播放声道选择
// 返回值：		无
//=============================================================
void PlaySnd(unsigned SndIndex,unsigned DAC_Channel)
{
	BSR_StopRecognizer();								//停止识别器
	SACM_S480_Initial(1);								//初始化为自动播放
	SACM_S480_Play(SndIndex, DAC_Channel, 3);			//开始播放一段语音
	while((SACM_S480_Status()&0x0001)!= 0)				//是否播放完毕？
	{
		SACM_S480_ServiceLoop();						//解码并填充队列
		*P_Watchdog_Clear=0x0001;						//清看门狗
	}
	SACM_S480_Stop();									//停止播放
	BSR_InitRecognizer(BSR_MIC);						//初始化识别器
}

//=============================================================
// 语法格式：	int TrainWord(int WordID,int SndID);
// 实现功能：	训练一条指令
// 参数：		WordID-指令编码
//				SndID-指令提示音索引号
// 返回值：		无
//=============================================================
int TrainWord(unsigned int WordID,unsigned int SndID)
{
	int Result;
	PlaySnd(SndID,3);									//引导训练，播放指令对应动作
	while(1)
	{
		Result = BSR_Train(WordID,BSR_TRAIN_TWICE);		//训练两次，获得训练结果
										
		if(Result==0)break;
		switch(Result)
		{
		case -1:										//没有检测出声音
			PlaySnd(S_NOVOICE,3);
			return -1;
		case -2: 										//需要训练第二次
			PlaySnd(S_AGAIN,3);
			break;
		case -3:										//环境太吵
			PlaySnd(S_NOISY,3);
			return -3;	
		case -4:										//数据库满
	 		return -4;	
		case -5: 			            				//检测出声音不同
			PlaySnd(S_CMDDIFF,3);
			return -5;
		case -6: 			            				//序号错误
			return -6;
		default:
			break;
		}
	}
	return 0;
}

//=============================================================
// 语法格式：	void TrainSD();
// 实现功能：	训练函数
// 参数：		无
// 返回值：		无
//=============================================================
void TrainSD()
{
	while(TrainWord(NAME_ID,S_NAME) != 0) ;  			//训练名称
	while(TrainWord(COMMAND_GO_ID,S_ACT1) != 0) ;  		//训练第1个动作
//	while(TrainWord(COMMAND_BACK_ID,S_ACT2) != 0) ;  	//训练第2个动作
//	while(TrainWord(COMMAND_LEFT_ID,S_ACT3) != 0) ;  	//训练第3个动作
//	while(TrainWord(COMMAND_RIGHT_ID,S_ACT4) != 0) ;	//训练第4个动作
}

//=============================================================
// 语法格式：	void StoreSD();
// 实现功能：	存储语音模型函数
// 参数：		无
// 返回值：		无
//=============================================================
void StoreSD()                           			
{	unsigned int ulAddr,i,commandID,g_Ret;
 	F_FlashErase(0xe000);
   	F_FlashErase(0xe100);
   	ulAddr=0xe000;//********
	for(commandID=0x100;commandID<0x102;commandID++)
	{
		g_Ret=BSR_ExportSDWord(commandID);			
		while(g_Ret!=0)									//模型导出成功？
		g_Ret=BSR_ExportSDWord(commandID);		
		for(i=0;i<100;i++)								//保存语音模型SD1(0xe000---0xe063)
		{
		    F_FlashWrite1Word(ulAddr,BSR_SDModel[i]);
			ulAddr+=1;												
		}
	}
}

//=============================================================
// 语法格式：	void StoreSD();
// 实现功能：	装载语音模型函数
// 参数：		无
// 返回值：		无
//=============================================================
void LoadSD()                           			
{	unsigned int *p,k,jk,Ret,g_Ret;
	p=(int *)0xe000;																					
	for(jk=0;jk<2;jk++)
	{
		for(k=0;k<100;k++)
		{
			Ret=*p;							
			BSR_SDModel[k]=Ret;							//装载语音模型			
			p+=1;													
		}					
		g_Ret=BSR_ImportSDWord();					
		while(g_Ret!=0)									//模型装载成功？
		g_Ret=BSR_ImportSDWord();								
	}
}

//=============================================================
// 语法格式：	void GoAhead();
// 实现功能：	前进子函数
// 参数：		无
// 返回值：		无
//=============================================================
void GoAhead()                     						//前进
{  
	unsigned int j;
	PlaySnd(S_ACT1,3);		
	*P_IOB_Data=0x2800;	
	for(j=0;j<40;j++)									//延时
	Delay();
	*P_IOB_Data=0x0000;
}
//=============================================================
// 语法格式：	void BackUp();
// 实现功能：	后退子函数
// 参数：		无
// 返回值：		无
//=============================================================
void BackUp()                        					//倒退
{	
	unsigned int j;
	PlaySnd(S_ACT2,3);		
	*P_IOB_Data=0x1400;									//延时
	for(j=0;j<40;j++)
	Delay();
	*P_IOB_Data=0x0000;
}

//=============================================================
// 语法格式：	void TurnLeft();
// 实现功能：	左转子函数
// 参数：		无
// 返回值：		无
//=============================================================
void TurnLeft()                       					//左转
{
	unsigned int j;
	PlaySnd(S_GJG,3);	
	for(j=0;j<30;j++)									//延时
	{	
		*P_IOB_Data=0x2400;
		Delay();
		Delay();
		*P_IOB_Data=0x2800;	
		Delay();
	}
	*P_IOB_Data=0x0000;
}
//=============================================================
// 语法格式：	void TurnRight();
// 实现功能：	右转子函数
// 参数：		无
// 返回值：		无
//=============================================================
void TurnRight()                           		 		//右转
{
	unsigned int j;
	PlaySnd(S_GJG,3);									//延时
	for(j=0;j<30;j++)	
	{	
		*P_IOB_Data=0x1800;
		Delay();
		Delay();
		*P_IOB_Data=0x2800;
		Delay();
	}
	*P_IOB_Data=0x0000;
}
//=============================================================
// 语法格式：	int main(void);
// 实现功能：	主函数
// 参数：		无
// 返回值：		无
//=============================================================
void led_on()
{
	*P_IOB_Data=0x0000;
}
int main(void)
{	int Result;									 		//辨识结果寄存
	unsigned int Ready=0;								//待命标志位
	unsigned int BS_Flag;								//Train标志位
	
	*P_IOA_Dir=0xff00;									//初始化IOA,IOA0~7下拉输入
	*P_IOA_Attrib=0xff00;
	*P_IOA_Data=0x0000;
	
//	*P_IOB_Dir=0x0f00;									//初始化IOB,IOB8~11同向输出
//	*P_IOB_Attrib=0x0f00;
//	*P_IOB_Data=0x0000;

	*P_IOB_Dir=0xffff;
	*P_IOB_Attrib=0xffff;
	*P_IOB_Data=0xffff;
	
	BSR_DeleteSDGroup(0);								//初始化存储器RAM
	BS_Flag=*(unsigned int *)0xe000;					//读存储单元0xe000
	if(BS_Flag==0xffff)									//没有经过训练（0xe000内容为0xffff）
	{
		TrainSD();										//训练
		StoreSD();										//存储训练结果（语音模型）
	}
	else 												//经过训练（0xe000内容为0x0055）
	{
		LoadSD();										//语音模型载入识别器
	}
	
	PlaySnd(S_START,3);									//开始识别提示
	BSR_InitRecognizer(BSR_MIC);						//初始化识别器

	while(1)
	{	
		Result = BSR_GetResult();						//获得识别结果
		
		if(Result>0)									//有识别结果？
		{	
			if(Result==NAME_ID) 						//名称
			{
				PlaySnd(S_RDY,3);						//播放待命提示音
				Ready=1;								//进入待命状态
			}
			
			if(Ready==1)								//待命状态？
			{
				switch(Result)
				{
				case COMMAND_GO_ID:						//识别出第一条命令
					led_on();
//					GoAhead();							//执行动作一：直走
					Ready=0;
					break;
				case COMMAND_BACK_ID:					//识别出第二条命令
					BackUp();							//执行动作二：倒车
					Ready=0;	
					break;
				case COMMAND_LEFT_ID:					//识别出第三条命令
					TurnLeft();							//执行动作三：左转
					Ready=0;	
					break;
				case COMMAND_RIGHT_ID:					//识别出第四条命令
					TurnRight();						//执行动作四：右转
					Ready=0;	
					break;
				default:
					break;
				}
			}
		}

		if((*P_IOA_Data)&0x0004)						//是否重新训练
		{
			F_FlashErase(0xe000);
			while(1)									//等待中断
			{
				*P_Watchdog_Clear=0x0001;			
			}			
		}
	}
}
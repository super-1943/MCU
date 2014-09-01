//=================================================================================================
//
//        The information contained herein is the exclusive property of
//      Sunplus Technology Co. And shall not be distributed, reproduced,
//      or disclosed in whole in part without prior written permission.
//
//            (C) COPYRIGHT 2001   SUNPLUS TECHNOLOGY CO.
//                           ALL RIGHTS RESERVED
//
//    The entire notice above must be reproduced on all authorized copies.
//
//=================================================================================================
//  工程名称： Guard_SD.spj
//  功能描述:   该程序是特定人辨识的一个范例：
//				在程序中我们通过三条语句的训练演示特定人连续音识别，其中第一条语句为触发命令。
//				在程序一开始为训练名称，即触发命令，然后提示训练两条命令，训练完毕开始辨识当识别
//				出触发名称后，发布命令则会听到应答，具体命令如下：
//****************训练******************************************
//    提示音                          输入语音
//--------------------------------------------------------
//	"请输入触发名称"                      "警卫"
//	"请输入第一条命令"                    "红灯亮"
//	"请输入第二条命令"                    "红灯灭"
//  “请输入第三条命令”                   “绿灯亮”
//   "请输入第四条命令"                   "绿灯灭"
//	"请再说一遍"（以上提示音每说完一遍出现此命令）
//	"没有听到任何声音"  （当没有检测到声音时出现此命令）
//	"两次输入名称不相同"（当两次输入的名称不同时出现此命令）
//	"两次输入命令不相同"（当两次输入的命令有差异时出现此命令）
//	"准备就绪，请开始辨识"（以上五条语句全部训练成功时，进入识别）
//*****************识别*****************************************
//     发布命令                           应答	
//---------------------------------------------------------
//	"警卫"                                  "在"
//	"红灯亮"                                IOB0口灯被点亮
//  "红灯灭"                                IOB0口灯被熄灭
//  “绿灯亮”                                IOB1口灯被点亮
//  "绿灯灭"                                IOB1口灯被熄灭
//	注意：  在每次提示音结束后2-3秒再输入命令或当上次应答结束2-3秒后再发布命令
//  
//  IDE环境：  	SUNPLUS u'nSPTM  IDE 2.0.0（or later）
//
//  涉及的库：	CMacro.lib/sacmv26e.lib/bsrv222SDL.lib
//
//  组成文件:	main.c
//    	 		FIQ.asm/hardware.asm/key.asm/InitIO.asm
//	            hardware.inc
//     	
//  日期:       2003-7-11
//========================================================================================================
#include "bsrsd.h"

#define NAME_ID 		0x100
#define COMMAND_ONE_ID 	0x101
#define COMMAND_TWO_ID 	0x102
#define COMMAND_THREE_ID 	0x103
#define COMMAND_FOUR_ID 	0x104
#define RSP_INTR		0
#define RSP_NAME		0
#define RSP_FIRE		1
#define RSP_GUARD		2
#define RSP_AGAIN		3
#define RSP_NOVOICE		4
#define RSP_NAMEDIFF	5
#define RSP_CMDDIFF		6
#define RSP_STAR	    7
#define RSP_MASTER		8
#define RSP_HERE		9
#define RSP_GUNSHOT		0
#define RSP_PATROL		11
#define RSP_READY		12
#define RSP_COPY		13
#define RSP_NOISY		14

//..................全程变量....................
int gActivated = 0;	//该变量用于检测是否有触发命令，当有识别出语句
                    //为触发名称则该位置1 
					 
int gTriggerRespond[] = {RSP_MASTER, RSP_HERE, RSP_MASTER};
int gComm2Respond[] = {RSP_PATROL, RSP_READY, RSP_COPY};
extern void ClearWatchDog();
int PlayFlag = 0;


void PlayRespond(int Result)
{
	BSR_StopRecognizer();                            //停止辩识，来自bsrv222SDL.lib
	SACM_S480_Initial(1);                            //S480格式语音播放初始化，来自sacmv26e.lib
	SACM_S480_Play(Result, 3, 3);                    //播放S480格式语音，来自sacmv26e.lib
	while((SACM_S480_Status()&0x0001) != 0)
	{
		SACM_S480_ServiceLoop();                     //来自sacmv26e.lib
		ClearWatchDog();
	}
	SACM_S480_Stop();                                //停止播放S480格式语音，来自sacmv26e.lib
	BSR_InitRecognizer(BSR_MIC);                     //辩识器初始化，来自bsrv222SDL.lib
	BSR_EnableCPUIndicator();	                     //
}

int TrainWord(int WordID, int RespondID)
{
	int res;
	PlayRespond(RespondID);
	while(1)
	{
		res = BSR_Train(WordID,BSR_TRAIN_TWICE);   //训练函数，来自bsrv222SDL.lib
		if(res == 0) break;
		switch(res)
		{
		case -1: 									//没有检测出声音
			PlayRespond(RSP_NOVOICE);
			return -1;
		case -2: 									//需要重新训练一遍
			PlayRespond(RSP_AGAIN);
			break;
		case -3: 									//环境太吵
			PlayRespond(RSP_NOISY);
			return -1;		
		case -4: 									//数据库满
		 	return -1;
		case -5: 									//检测出声音不同
			if(WordID == NAME_ID)	PlayRespond(RSP_NAMEDIFF);//两次输入名称不同
			else					PlayRespond(RSP_CMDDIFF);//两次输入命令不同
			return -1;
		case -6: 									//序号错误
			return -1;
		}
	}
	return 0;
}

int main()
{
	int res, timeCnt = 0, random_no = 0;
	
	InitIO();
	BSR_DeleteSDGroup(0);							// 初始化存储器RAM，来自bsrv222SDL.lib

//	PlayRespond(RSP_INTR);				    	// 播放开始训练的提示音"请输入触发名称"
	//..........训练名称..............................
	while(TrainWord(NAME_ID,0) != 0) ;          
	//..........训练第一条命令.......................
	while(TrainWord(COMMAND_ONE_ID,1) != 0) ;
	//..........训练第二条命令.......................
	while(TrainWord(COMMAND_TWO_ID,2) != 0) ;
	//..........训练第三条命令.......................
	while(TrainWord(COMMAND_THREE_ID,12) != 0) ;
	//..........训练第四条命令.......................
	while(TrainWord(COMMAND_FOUR_ID,13) != 0) ;

	//..........开始识别命令.........................
	BSR_InitRecognizer(BSR_MIC);		    		//辨识器初始化，来自bsrv222SDL.lib
	BSR_EnableCPUIndicator();                       //启动实时监控
	PlayRespond(RSP_STAR);			    			//播放开始辨识的提示音
	
	while(1)
	{
		random_no ++;
		if(random_no >= 3) random_no = 0;
		res = BSR_GetResult();               //取辩识结果，来自bsrv222SDL.lib
		
		if(res > 0)							  //识别出命令
		{
			if(gActivated)
			{
				timeCnt = 0;
				switch(res)
				{
				case NAME_ID:                 //触发命令响应
					PlayRespond(gTriggerRespond[random_no]);
					break;
				case COMMAND_ONE_ID:          //识别第一个命令
					PlayFlag = 1;
					LED_RED_ON();		      //点亮二极管		
					PlayFlag = 0;
					gActivated = 0;
					break;
				case COMMAND_TWO_ID:          //识别到第二条命令
					LED_RED_OFF();            //响应第二条命令“我在巡逻”	
					gActivated = 0;
					break;
				case COMMAND_THREE_ID:        //识别第三条命令
				    LED_GRE_ON();
				    gActivated = 0;
				    break;	   
				    
				case COMMAND_FOUR_ID:         //识别第四条命令
				   LED_GRE_OFF();
				   gActivated = 0;
				    break;
				
				                       
				}				
			}
			else
			{
				if(res == NAME_ID)
				{
					PlayRespond(gTriggerRespond[random_no]);
					gActivated = 1;
					timeCnt = 0;
				}
			}	
		}
		else if (gActivated)
		{
			if (++timeCnt > 450)					//超出定时
			{
				PlayRespond(RSP_NOVOICE); 			//在设定时间内没有检测出声音					
				gActivated = 0;
				timeCnt = 0;
			}
		}
	}
}
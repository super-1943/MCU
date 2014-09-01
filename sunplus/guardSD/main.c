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
//  �������ƣ� Guard_SD.spj
//  ��������:   �ó������ض��˱�ʶ��һ��������
//				�ڳ���������ͨ����������ѵ����ʾ�ض���������ʶ�����е�һ�����Ϊ�������
//				�ڳ���һ��ʼΪѵ�����ƣ����������Ȼ����ʾѵ���������ѵ����Ͽ�ʼ��ʶ��ʶ��
//				���������ƺ󣬷��������������Ӧ�𣬾����������£�
//****************ѵ��******************************************
//    ��ʾ��                          ��������
//--------------------------------------------------------
//	"�����봥������"                      "����"
//	"�������һ������"                    "�����"
//	"������ڶ�������"                    "�����"
//  ����������������                   ���̵�����
//   "���������������"                   "�̵���"
//	"����˵һ��"��������ʾ��ÿ˵��һ����ִ����
//	"û�������κ�����"  ����û�м�⵽����ʱ���ִ����
//	"�����������Ʋ���ͬ"����������������Ʋ�ͬʱ���ִ����
//	"�������������ͬ"������������������в���ʱ���ִ����
//	"׼���������뿪ʼ��ʶ"�������������ȫ��ѵ���ɹ�ʱ������ʶ��
//*****************ʶ��*****************************************
//     ��������                           Ӧ��	
//---------------------------------------------------------
//	"����"                                  "��"
//	"�����"                                IOB0�ڵƱ�����
//  "�����"                                IOB0�ڵƱ�Ϩ��
//  ���̵�����                                IOB1�ڵƱ�����
//  "�̵���"                                IOB1�ڵƱ�Ϩ��
//	ע�⣺  ��ÿ����ʾ��������2-3��������������ϴ�Ӧ�����2-3����ٷ�������
//  
//  IDE������  	SUNPLUS u'nSPTM  IDE 2.0.0��or later��
//
//  �漰�Ŀ⣺	CMacro.lib/sacmv26e.lib/bsrv222SDL.lib
//
//  ����ļ�:	main.c
//    	 		FIQ.asm/hardware.asm/key.asm/InitIO.asm
//	            hardware.inc
//     	
//  ����:       2003-7-11
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

//..................ȫ�̱���....................
int gActivated = 0;	//�ñ������ڼ���Ƿ��д����������ʶ������
                    //Ϊ�����������λ��1 
					 
int gTriggerRespond[] = {RSP_MASTER, RSP_HERE, RSP_MASTER};
int gComm2Respond[] = {RSP_PATROL, RSP_READY, RSP_COPY};
extern void ClearWatchDog();
int PlayFlag = 0;


void PlayRespond(int Result)
{
	BSR_StopRecognizer();                            //ֹͣ��ʶ������bsrv222SDL.lib
	SACM_S480_Initial(1);                            //S480��ʽ�������ų�ʼ��������sacmv26e.lib
	SACM_S480_Play(Result, 3, 3);                    //����S480��ʽ����������sacmv26e.lib
	while((SACM_S480_Status()&0x0001) != 0)
	{
		SACM_S480_ServiceLoop();                     //����sacmv26e.lib
		ClearWatchDog();
	}
	SACM_S480_Stop();                                //ֹͣ����S480��ʽ����������sacmv26e.lib
	BSR_InitRecognizer(BSR_MIC);                     //��ʶ����ʼ��������bsrv222SDL.lib
	BSR_EnableCPUIndicator();	                     //
}

int TrainWord(int WordID, int RespondID)
{
	int res;
	PlayRespond(RespondID);
	while(1)
	{
		res = BSR_Train(WordID,BSR_TRAIN_TWICE);   //ѵ������������bsrv222SDL.lib
		if(res == 0) break;
		switch(res)
		{
		case -1: 									//û�м�������
			PlayRespond(RSP_NOVOICE);
			return -1;
		case -2: 									//��Ҫ����ѵ��һ��
			PlayRespond(RSP_AGAIN);
			break;
		case -3: 									//����̫��
			PlayRespond(RSP_NOISY);
			return -1;		
		case -4: 									//���ݿ���
		 	return -1;
		case -5: 									//����������ͬ
			if(WordID == NAME_ID)	PlayRespond(RSP_NAMEDIFF);//�����������Ʋ�ͬ
			else					PlayRespond(RSP_CMDDIFF);//�����������ͬ
			return -1;
		case -6: 									//��Ŵ���
			return -1;
		}
	}
	return 0;
}

int main()
{
	int res, timeCnt = 0, random_no = 0;
	
	InitIO();
	BSR_DeleteSDGroup(0);							// ��ʼ���洢��RAM������bsrv222SDL.lib

//	PlayRespond(RSP_INTR);				    	// ���ſ�ʼѵ������ʾ��"�����봥������"
	//..........ѵ������..............................
	while(TrainWord(NAME_ID,0) != 0) ;          
	//..........ѵ����һ������.......................
	while(TrainWord(COMMAND_ONE_ID,1) != 0) ;
	//..........ѵ���ڶ�������.......................
	while(TrainWord(COMMAND_TWO_ID,2) != 0) ;
	//..........ѵ������������.......................
	while(TrainWord(COMMAND_THREE_ID,12) != 0) ;
	//..........ѵ������������.......................
	while(TrainWord(COMMAND_FOUR_ID,13) != 0) ;

	//..........��ʼʶ������.........................
	BSR_InitRecognizer(BSR_MIC);		    		//��ʶ����ʼ��������bsrv222SDL.lib
	BSR_EnableCPUIndicator();                       //����ʵʱ���
	PlayRespond(RSP_STAR);			    			//���ſ�ʼ��ʶ����ʾ��
	
	while(1)
	{
		random_no ++;
		if(random_no >= 3) random_no = 0;
		res = BSR_GetResult();               //ȡ��ʶ���������bsrv222SDL.lib
		
		if(res > 0)							  //ʶ�������
		{
			if(gActivated)
			{
				timeCnt = 0;
				switch(res)
				{
				case NAME_ID:                 //����������Ӧ
					PlayRespond(gTriggerRespond[random_no]);
					break;
				case COMMAND_ONE_ID:          //ʶ���һ������
					PlayFlag = 1;
					LED_RED_ON();		      //����������		
					PlayFlag = 0;
					gActivated = 0;
					break;
				case COMMAND_TWO_ID:          //ʶ�𵽵ڶ�������
					LED_RED_OFF();            //��Ӧ�ڶ����������Ѳ�ߡ�	
					gActivated = 0;
					break;
				case COMMAND_THREE_ID:        //ʶ�����������
				    LED_GRE_ON();
				    gActivated = 0;
				    break;	   
				    
				case COMMAND_FOUR_ID:         //ʶ�����������
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
			if (++timeCnt > 450)					//������ʱ
			{
				PlayRespond(RSP_NOVOICE); 			//���趨ʱ����û�м�������					
				gActivated = 0;
				timeCnt = 0;
			}
		}
	}
}
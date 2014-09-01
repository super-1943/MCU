//======================================================
//  The information contained herein is the exclusive property of
//  Sunnnorth Technology Co. And shall not be distributed, reproduced,
//  or disclosed in whole in part without prior written permission.
//  (C) COPYRIGHT 2003  SUNNORTH TECHNOLOGY CO.
//  ALL RIGHTS RESERVED
//  The entire notice above must be reproduced on all authorized copies.
//========================================================

//========================================================
//  �������ƣ�	Car_Demo
//  ����������	ʵ��С������������
//  �漰�Ŀ⣺	CMacro.lib
//            	bsrsd.lib
//  ����ļ���	main.c
//				Flash.asm, hardware.asm,ISR.asm 
//     			hardware.h,s480.h, hardware.inc
//	Ӳ�����ӣ�	���°���������С��˵����
//	ά����¼��	2005-9-11 v1.0
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

#define S_NAME				0							//����ȡ�����ְ�
#define S_ACT1				1							//ǰ��
#define S_ACT2				2							//��������ע��
#define S_ACT3				3							//���
#define S_ACT4				4							//�ҹ�	
#define S_RDY				5							//Yeah
#define S_AGAIN				6							//����˵һ��
#define S_NOVOICE			7							//û�������κ�����
#define S_CMDDIFF			8							//˵ʲô����ѽ
#define S_NOISY				8							//˵ʲô����ѽ
#define S_START				9							//׼����������ʼ��ʶ	
#define S_GJG				10							//�վ͹�

extern  unsigned int BSR_SDModel[100];					//�ⲿ����BSR_SDModel[100]����ʶ���Դ�
extern void F_FlashWrite1Word(unsigned int addr,unsigned int Value);
extern void F_FlashErase(unsigned int sector);

//=============================================================
// �﷨��ʽ��	void Delay();
// ʵ�ֹ��ܣ�	��ʱ
// ������		��
// ����ֵ��		��
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
// �﷨��ʽ��	void PlaySnd(unsigned SndIndex,unsigned DAC_Channel);
// ʵ�ֹ��ܣ�	�������ź���
// ������		SndIndex-����������Դ������
//				DAC_Channel-��������ѡ��
// ����ֵ��		��
//=============================================================
void PlaySnd(unsigned SndIndex,unsigned DAC_Channel)
{
	BSR_StopRecognizer();								//ֹͣʶ����
	SACM_S480_Initial(1);								//��ʼ��Ϊ�Զ�����
	SACM_S480_Play(SndIndex, DAC_Channel, 3);			//��ʼ����һ������
	while((SACM_S480_Status()&0x0001)!= 0)				//�Ƿ񲥷���ϣ�
	{
		SACM_S480_ServiceLoop();						//���벢������
		*P_Watchdog_Clear=0x0001;						//�忴�Ź�
	}
	SACM_S480_Stop();									//ֹͣ����
	BSR_InitRecognizer(BSR_MIC);						//��ʼ��ʶ����
}

//=============================================================
// �﷨��ʽ��	int TrainWord(int WordID,int SndID);
// ʵ�ֹ��ܣ�	ѵ��һ��ָ��
// ������		WordID-ָ�����
//				SndID-ָ����ʾ��������
// ����ֵ��		��
//=============================================================
int TrainWord(unsigned int WordID,unsigned int SndID)
{
	int Result;
	PlaySnd(SndID,3);									//����ѵ��������ָ���Ӧ����
	while(1)
	{
		Result = BSR_Train(WordID,BSR_TRAIN_TWICE);		//ѵ�����Σ����ѵ�����
										
		if(Result==0)break;
		switch(Result)
		{
		case -1:										//û�м�������
			PlaySnd(S_NOVOICE,3);
			return -1;
		case -2: 										//��Ҫѵ���ڶ���
			PlaySnd(S_AGAIN,3);
			break;
		case -3:										//����̫��
			PlaySnd(S_NOISY,3);
			return -3;	
		case -4:										//���ݿ���
	 		return -4;	
		case -5: 			            				//����������ͬ
			PlaySnd(S_CMDDIFF,3);
			return -5;
		case -6: 			            				//��Ŵ���
			return -6;
		default:
			break;
		}
	}
	return 0;
}

//=============================================================
// �﷨��ʽ��	void TrainSD();
// ʵ�ֹ��ܣ�	ѵ������
// ������		��
// ����ֵ��		��
//=============================================================
void TrainSD()
{
	while(TrainWord(NAME_ID,S_NAME) != 0) ;  			//ѵ������
	while(TrainWord(COMMAND_GO_ID,S_ACT1) != 0) ;  		//ѵ����1������
//	while(TrainWord(COMMAND_BACK_ID,S_ACT2) != 0) ;  	//ѵ����2������
//	while(TrainWord(COMMAND_LEFT_ID,S_ACT3) != 0) ;  	//ѵ����3������
//	while(TrainWord(COMMAND_RIGHT_ID,S_ACT4) != 0) ;	//ѵ����4������
}

//=============================================================
// �﷨��ʽ��	void StoreSD();
// ʵ�ֹ��ܣ�	�洢����ģ�ͺ���
// ������		��
// ����ֵ��		��
//=============================================================
void StoreSD()                           			
{	unsigned int ulAddr,i,commandID,g_Ret;
 	F_FlashErase(0xe000);
   	F_FlashErase(0xe100);
   	ulAddr=0xe000;//********
	for(commandID=0x100;commandID<0x102;commandID++)
	{
		g_Ret=BSR_ExportSDWord(commandID);			
		while(g_Ret!=0)									//ģ�͵����ɹ���
		g_Ret=BSR_ExportSDWord(commandID);		
		for(i=0;i<100;i++)								//��������ģ��SD1(0xe000---0xe063)
		{
		    F_FlashWrite1Word(ulAddr,BSR_SDModel[i]);
			ulAddr+=1;												
		}
	}
}

//=============================================================
// �﷨��ʽ��	void StoreSD();
// ʵ�ֹ��ܣ�	װ������ģ�ͺ���
// ������		��
// ����ֵ��		��
//=============================================================
void LoadSD()                           			
{	unsigned int *p,k,jk,Ret,g_Ret;
	p=(int *)0xe000;																					
	for(jk=0;jk<2;jk++)
	{
		for(k=0;k<100;k++)
		{
			Ret=*p;							
			BSR_SDModel[k]=Ret;							//װ������ģ��			
			p+=1;													
		}					
		g_Ret=BSR_ImportSDWord();					
		while(g_Ret!=0)									//ģ��װ�سɹ���
		g_Ret=BSR_ImportSDWord();								
	}
}

//=============================================================
// �﷨��ʽ��	void GoAhead();
// ʵ�ֹ��ܣ�	ǰ���Ӻ���
// ������		��
// ����ֵ��		��
//=============================================================
void GoAhead()                     						//ǰ��
{  
	unsigned int j;
	PlaySnd(S_ACT1,3);		
	*P_IOB_Data=0x2800;	
	for(j=0;j<40;j++)									//��ʱ
	Delay();
	*P_IOB_Data=0x0000;
}
//=============================================================
// �﷨��ʽ��	void BackUp();
// ʵ�ֹ��ܣ�	�����Ӻ���
// ������		��
// ����ֵ��		��
//=============================================================
void BackUp()                        					//����
{	
	unsigned int j;
	PlaySnd(S_ACT2,3);		
	*P_IOB_Data=0x1400;									//��ʱ
	for(j=0;j<40;j++)
	Delay();
	*P_IOB_Data=0x0000;
}

//=============================================================
// �﷨��ʽ��	void TurnLeft();
// ʵ�ֹ��ܣ�	��ת�Ӻ���
// ������		��
// ����ֵ��		��
//=============================================================
void TurnLeft()                       					//��ת
{
	unsigned int j;
	PlaySnd(S_GJG,3);	
	for(j=0;j<30;j++)									//��ʱ
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
// �﷨��ʽ��	void TurnRight();
// ʵ�ֹ��ܣ�	��ת�Ӻ���
// ������		��
// ����ֵ��		��
//=============================================================
void TurnRight()                           		 		//��ת
{
	unsigned int j;
	PlaySnd(S_GJG,3);									//��ʱ
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
// �﷨��ʽ��	int main(void);
// ʵ�ֹ��ܣ�	������
// ������		��
// ����ֵ��		��
//=============================================================
void led_on()
{
	*P_IOB_Data=0x0000;
}
int main(void)
{	int Result;									 		//��ʶ����Ĵ�
	unsigned int Ready=0;								//������־λ
	unsigned int BS_Flag;								//Train��־λ
	
	*P_IOA_Dir=0xff00;									//��ʼ��IOA,IOA0~7��������
	*P_IOA_Attrib=0xff00;
	*P_IOA_Data=0x0000;
	
//	*P_IOB_Dir=0x0f00;									//��ʼ��IOB,IOB8~11ͬ�����
//	*P_IOB_Attrib=0x0f00;
//	*P_IOB_Data=0x0000;

	*P_IOB_Dir=0xffff;
	*P_IOB_Attrib=0xffff;
	*P_IOB_Data=0xffff;
	
	BSR_DeleteSDGroup(0);								//��ʼ���洢��RAM
	BS_Flag=*(unsigned int *)0xe000;					//���洢��Ԫ0xe000
	if(BS_Flag==0xffff)									//û�о���ѵ����0xe000����Ϊ0xffff��
	{
		TrainSD();										//ѵ��
		StoreSD();										//�洢ѵ�����������ģ�ͣ�
	}
	else 												//����ѵ����0xe000����Ϊ0x0055��
	{
		LoadSD();										//����ģ������ʶ����
	}
	
	PlaySnd(S_START,3);									//��ʼʶ����ʾ
	BSR_InitRecognizer(BSR_MIC);						//��ʼ��ʶ����

	while(1)
	{	
		Result = BSR_GetResult();						//���ʶ����
		
		if(Result>0)									//��ʶ������
		{	
			if(Result==NAME_ID) 						//����
			{
				PlaySnd(S_RDY,3);						//���Ŵ�����ʾ��
				Ready=1;								//�������״̬
			}
			
			if(Ready==1)								//����״̬��
			{
				switch(Result)
				{
				case COMMAND_GO_ID:						//ʶ�����һ������
					led_on();
//					GoAhead();							//ִ�ж���һ��ֱ��
					Ready=0;
					break;
				case COMMAND_BACK_ID:					//ʶ����ڶ�������
					BackUp();							//ִ�ж�����������
					Ready=0;	
					break;
				case COMMAND_LEFT_ID:					//ʶ�������������
					TurnLeft();							//ִ�ж���������ת
					Ready=0;	
					break;
				case COMMAND_RIGHT_ID:					//ʶ�������������
					TurnRight();						//ִ�ж����ģ���ת
					Ready=0;	
					break;
				default:
					break;
				}
			}
		}

		if((*P_IOA_Data)&0x0004)						//�Ƿ�����ѵ��
		{	
			F_FlashErase(0xe000);
			while(1)									//�ȴ��ж�
			{
				*P_Watchdog_Clear=0x0001;			
			}			
		}
	}
}
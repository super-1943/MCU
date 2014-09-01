//===============================================================
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
//==============================================================
//  �������ƣ�   Record.scs  "������"
//  ��������:    ���"61��"�������������¼����ֹͣ�Ͳ��Ź���:
//		1��KEY1����¼����I/O��A0��
//		2��KEY2����ֹͣ��I/O��A1��
//		3��KEY3�������ţ�I/O��A3��
//		�¼20��
//  �ļ���Դ��   61��˵����
//  IDE������   SUNPLUS u'nSPTM  IDE 1.8.0��or later��
//
//  �漰�Ŀ⣺	(a) C-Lib:  (CMacro.lib);
//            	(b) SACM-Lib: SacmV25.lib
//  Ӳ�����ӣ�  ������SPCE061A���򿪷���ʹ��
//  ����ļ�:
//    	main.c
//		isr.asm/key.asm/sram.asm/Flash.asm/system.asm
//     	hardware.asm/Resource.asm
//		Resource.h/Resource.inc
//  ����:          	2003-5-22��������
//					2003-6-16����Ӱ汾˵������Ȩ������
//					2003-7-16�������׼����
//===============================================================

#include "hardware.h"
#include "dvr.h"
#define C_flashSize    	0xf000
#define sector 			0xa000				//����FLASHд����ʼ��ַ

#define	Stop			0
#define	Record			1
#define Play			2	

#define	Full			1			
#define	Empty			2

#define	DAC1			1		
#define DAC2			2

#define	RceMonitorOff	0
#define	RceMonitorOn	1

#define Manual			0
#define	Auto			1

unsigned int Status;
unsigned int Ret;
unsigned int Key;
unsigned int Addr, Save_Addr;
//*********************************************************//
//������main()
//������������
//*********************************************************//
int main()
{	
	System_Initial();
	SACM_DVR_Initial(Manual);
	Status = Stop;
	while(1)
		{				
			Key = SP_GetCh();					//��ȡ��ֵ
			switch(Key)
			{
				case 0x0001:					//KEY1
//**********************¼��(record)***********************//
//*********************************************************//					
			    	for(Addr=sector;Addr<0xf000;Addr+=256)							
			      { 
				    Clear_WatchDog();
					F_FlashErase(Addr); 				
		          }	
					Status = Record;
					Addr=sector;	            	
		            // DVR��ʼ��
					SACM_DVR_InitQueue();
					SACM_DVR_InitEncoder(RceMonitorOn);
					break;

				case 0x0002:					//	KEY2 
//**********************ֹͣ(stop)*************************//
//*********************************************************//
					switch(Status)
					{
						case Record:    		// ����¼��
							SACM_DVR_Stop();
							while(SACM_DVR_TestQueue() != Empty )
								{  
									Ret = SACM_DVR_FetchQueue();// �Ӷ�����ȡ��
									F_FlashWrite1Word(Addr,Ret);									
									Addr += 1;
								}			    	
							break;
						case Play:
							SACM_DVR_Stop();
							break;
						default:			
							break;
					}									
						Status = Stop;
						break;		
			
			case 0x0004:						//KEY3 
//************************�ط�(playback)*******************//
//*********************************************************//
				SACM_DVR_Stop();			
				if(Status == Record)
					{
						while(SACM_DVR_TestQueue() != Empty)
							{	
								Ret = SACM_DVR_FetchQueue();// Put remain dat to Queue
								F_FlashWrite1Word(Addr,Ret);// save to User Storage								 
								Addr+= 1;
							}
		    		 }				
			//	Save_Addr=Addr;
				Status = Play;				
				Addr = sector; 								//���ŵ��׵�ַ
				SACM_DVR_InitQueue();
				while(SACM_DVR_TestQueue() != Full)			//������в����������
					{	
                   		Ret=F_FlashRead(Addr);	     		//��flash�ж�������						
						SACM_DVR_FillQueue(Ret);			//�����
						Addr+= 1;							 
					}
				SACM_DVR_InitDecoder(DAC1+DAC2);
				break;
					default:
					break;		
		   }
//************************״̬�жϴ���*********************//
//*********************************************************//		
	  switch(Status)
		{	
			case Record:
//**********************ֹͣ(stop)*************************//
//*********************************************************//
				if(Addr< C_flashSize)
					{					
						SACM_DVR_Encode();				    // ȡ���ݲ�����						
						if(SACM_DVR_TestQueue() != Empty)	//�������û�������ݱ���
							{	
								Ret = SACM_DVR_FetchQueue();//�Ӷ�����ȡ��								
								F_FlashWrite1Word(Addr,Ret);//������д��flash 
											
								Addr+= 1;
							}	
					}			
				else
					{
			    		SACM_DVR_Stop();
						while(SACM_DVR_TestQueue() != Empty )
							{
								Ret = SACM_DVR_FetchQueue();
	   							F_FlashWrite1Word(Addr,Ret);							
								Addr+= 1;
							}
	   					Status = Stop;					
				    }
				break;
				
			case Play:
//************************�ط�(playback)*******************//
//*********************************************************//		    
				if(SACM_DVR_Status()&0x01)              	//�Ƿ����ڲ���
					{
						if(SACM_DVR_TestQueue() != Full)
							{                          			
	                    	   Ret=F_FlashRead(Addr);		//����flash�е�����                       
							   SACM_DVR_FillQueue(Ret);		// �����
							   Addr += 1;
							}						
					}
				else
					{
						SACM_DVR_Stop();
						Status = Stop;						
					//	SP_RampDnDAC1();
					//	SP_RampDnDAC2();
					}	
	    		SACM_DVR_Decode();							//����
				break;
						
			case Stop:
				break;
			default:
				break;	
		}		   	
		 	System_ServiceLoop();							//����ɨ��		 
	}			 
}

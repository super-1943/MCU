//======================================================
//  The information contained herein is the exclusive property of
//  Sunnnorth Technology Co. And shall not be distributed, reproduced,
//  or disclosed in whole in part without prior written permission.
//             (C) COPYRIGHT 2003  SUNNORTH TECHNOLOGY CO.
//                          ALL RIGHTS RESERVED
//  The entire notice above must be reproduced on all authorized copies.
//========================================================

//============================================================
//  �������ƣ�	61_SpeechClock
//  ����������	61�����ʾ��--���������������ܵĵ�����
//				ʹ��61���ϵ������������Ʊ�ʱ��ʱ�������
//					Key1 - ��һ�²����ꡢ�¡��գ��ٰ�һ�²���ʱ����
//						   ����Key1���ﵽ1.5�룬���������ʱ�����ģʽ
//					Key2 - �ڵ���ģʽ�£�ʹ�ꡢ�¡��ա�ʱ���֡�������
//					Key3 - �ڵ���ģʽ�£�ʹ�ꡢ�¡��ա�ʱ���֡����С
//  �漰�Ŀ⣺	CMacro1016.lib
//            	SacmV26e.lib
//  ����ļ���	main.c, Sound.c, Clock.c, Clock_Speech.c, Clock_Adjust.c
//				Key.asm, hardware.asm, ISR.asm
//				A2000.h, Sound.h, Clock.h, Clock_Speech.h, Clock_Adjust.h, Key.h, SPCE061A.h, 
//	Ӳ�����ӣ�	61���Դ������������Ѿ�������IOA0~IOA2��
//	ά����¼��	2006-8-30 v1.0
//===============================================

//======================================================
// �ļ����ƣ�	main.c
// ����������	������
// ά����¼��	2006-08-30	v1.0
//======================================================
#include "spce061a.h"
#include "Sound.h"
#include "Key.h"
#include "Clock.h"
#include "Clock_Speech.h"
#include "Clock_Adjust.h"

//=============================================================
// �﷨��ʽ��	int main(void);
// ʵ�ֹ��ܣ�	������
// ������		��
// ����ֵ��		��
//=============================================================
int main()
{
	unsigned int KeyCode;
	unsigned int Flag = 0;
	
	Key_Init();										// ��ʼ������ɨ�����
	Clock_Start();									// ��ʼ����ʱ����

	while(1)
	{
		KeyCode = Key_Get();						// ��ȡ����ֵ
		switch(KeyCode)
		{
			case KEY_1:								// Key1������������/ʱ��
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
			case KEY_LONG_1:						// Key1���������������ں�ʱ��
				Adjust();
				break;
			default:
				break;
		}
		*P_Watchdog_Clear = 0x01;					// �忴�Ź�
		*P_SystemClock = 0x001F;					// ����˯��ģʽ
	}
}


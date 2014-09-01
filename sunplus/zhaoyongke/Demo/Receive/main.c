//======================================================================
//	�������ƣ�	Receive.spj
//	����������	nRF2401 ����ģ��������ʾ������ն˳���
//				���г����������Ͷ��м����£�������������ֵ
//
//  IDE������   SUNPLUS u'nSPTM  IDE 2.0.0��or later��
//	�漰�Ŀ⣺	CMacro1016.lib
//              SACMv41dx_061A.lib
//	����ļ���	main.c, nRF2401.c, SACM_A1600_User_C.c, Snd.c
//				SACM_A1600.asm
//				SPCE061A.h, nRF2401.h, A1600.h, Snd.h
//				SPCE061A.inc, A1600.inc
//	Ӳ�����ӣ�
//				J3  -- ����(61��)
//
//				IOB0 - PWR(����ģ��)
//				IOB1 - CE(����ģ��)
//				IOB2 - CS(����ģ��)
//				IOB3 - DR1(����ģ��)
//				IOB4 - CLK1(����ģ��)
//				IOB5 - DATA1(����ģ��)

//	ά����¼��	2006-10-20	v1.0
//======================================================================

//====================================================================================
//�� �� ��: main.c
//��������: ʵ�ּ�ֵ���պ���������
//ά����¼: 2006��10��20
//====================================================================================
#include "spce061a.h"
#include "nRF2401.h"
#include "Snd.h"
#include "led.h"
unsigned int RxBuf[25];									// ���ջ���,������յ�������
extern void getkey(void);

int main()
{
	nRF2401_Initial();									// nRF2401A��ʼ��
	nRF2401_Mode(0);									// ����nRF2401A������ʽ:����
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
		if((nRF2401_RxStatus()) == 1)					// nRF2401A����������
		{
			nRF2401_ReceiveByte(RxBuf);					// ��������
			switch(RxBuf[0])
			{
				case 1:
					PlaySnd(0);							// ��������"Key1"
					break;
				case 2:
					PlaySnd(1);							// ��������"Key3"
					break;
				case 3:
					PlaySnd(2);							// ��������"Key2"
					break;
				default:
					break;
			}
		}
	}
}

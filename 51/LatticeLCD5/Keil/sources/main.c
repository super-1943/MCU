//*************************************************************************************************
//*************************************************************************************************
//**<������>������˹������Ϸ																 	 **
//**<�汾˵��>���˰��ǵ�һ�棬��LCD1608��4������ϸĽ�������Ŀǰֻ���Ի�����Ϸ����ı߿�		 **
//**<���ʱ��>��2007��8��28��																	 **
//**<����>��LastRitter																			 **
//**<��ϵ��ʽ>��E-mail:superyongzhe@163.com;QQ:314665354��										 **
//*************************************************************************************************
//*************************************************************************************************

//*************************************************************************************************
//*																								  *
//*			 ******************************ͷ�ļ����궨��**************************				  *
//*																								  *
//*************************************************************************************************
#include "includes.h"


#define TIME1H 0x3C
#define TIME1L 0xB0		//��ʱ��1���ʱ�䣺50ms

#define SCANPORT P1


//*************************************************************************************************
//*																								  *
//*			 ******************************ȫ�ֱ���************************************			  *
//*																								  *
//*************************************************************************************************

//unsigned char code uca_TEST[]={0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xF0,0xF0,0xF0,0xF0};
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<��������־>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
bit b_KeyShock=0;	  				//���̷�������־λ��
									//�������жϲ���ʱ�������жϴ�λ��
									//0--ִ�м���ɨ�輰���봦������1--��ִ�С�

bit b_KillShock=0;					//������־���λ��0--�������1--�����

unsigned char uc_KillCount=0;		//������־���������ʹ�ö�ʱ��1��


//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<����ɨ�迪����־>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
bit b_KeyScan=0;					//0--��ɨ�裻
									//1--ɨ�衣


//*************************************************************************************************
//*																								  *
//*			  ********************************������******************************				  *
//*																								  *
//*************************************************************************************************


/*********************** main ************************/
void main(void)
{

	vLCDInitialize();

	vShowOneChin(0,0,uca_QING);
	vShowOneChin(2,0,uca_SHU);
	vShowOneChin(4,0,uca_RU);
	vShowOneChin(6,0,uca_MAOHAO);

	vShowGraph(2,60,32,4,uca_Pig);
	vShowFrame();

	SCANPORT=0x0F;
	
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<�ⲿ�ж�0�����ڿ�������ɨ�輰���봦����־>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	IT0=1;			 //	�жϷ�ʽ���½��ء�
	EX0=1;			 //	�����ⲿ�жϡ�


//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<��ʱ��1�����ڷ�������־��� >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	TH1=TIME1H;
	TL1=TIME1L;
	TR1=1;			 //������ʱ��1
	ET1=1;			 //����ʱ��1�ж�

	EA=1;

	while(1)
	{
	if(b_KeyScan==1)		   //����а������£�����а���ɨ��ͼ��봦����
		{
		b_KeyScan=0;
		vKeyProcess(ucKeyScan());
		}
	}
}



//*************************************************************************************************
//*																								  *
//*		******************************�ⲿ�ж�0�����ڿ�������ɨ�輰���봦��******************	  *
//*																								  *
//*************************************************************************************************
void vINT0(void) interrupt 0
{
	if(b_KeyShock==0)
		{
			b_KeyScan=1;			//��������ɨ���־��
			b_KeyShock=1;			//���÷�������־��
		}
	else b_KeyShock=0;				//����ж�����ִ�м�ɨ�裬�ָ���������־��

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<���÷����������־λ >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>	
	if(b_KeyShock==1)
		b_KillShock=1;				//�����������־λ����������������־���λ��
									//300ms�������������־��

}


//*************************************************************************************************
//*																								  *
//*		****************��ʱ��1�жϣ����ڼ�ʱ���ܺͷ�������־���***************************	  *
//*																								  *
//*************************************************************************************************
void vTimer1(void) interrupt 3
{
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<��������־���>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	if(b_KillShock==1)
		{
		if(uc_KillCount==5)			 //����������־λΪ1ʱ����ʱ300ms�����������־λ��
			{
			b_KeyShock=0;
			b_KillShock=0;
			uc_KillCount=0;
			}
		else uc_KillCount++;
		}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<�ָ���ʱ��1���ʱ��>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	TH1=TIME1H;
	TL1=TIME1L;
} 
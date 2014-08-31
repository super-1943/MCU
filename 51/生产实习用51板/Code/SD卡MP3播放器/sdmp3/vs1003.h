#ifndef __VS1003_H__
#define __VS1003_H__

/*******************************************************

        +------------------------------------+
        |  ���ϵ��� �߼�����ģ�� VS1003B ����|
        +------------------------------------+

  ��Դ���Ȩ�� ���� ȫȨ���У��������ã�������������֪
        �Ͻ�����������ҵĿ�ģ�Υ�߱ؾ�������Ը�
         ���ϵ��� 
             ->��Ʒ��վ http://www.znmcu.cn/
             ->��Ʒ��̳ http://bbs.znmcu.cn/
             ->��Ʒ���� http://shop.znmcu.cn/
             ->��Ʒ��ѯ QQ:987582714 MSN:yzn07@126.com
	                WW:yzn07				  
********************************************************/

#include <reg51.h>

//��IO������ ���ϵ� �����Ǿ����� ���Ǻ�

//sbit VS_SO     =P1^6; //���������������Ƭ����VS1003�ж�ȡ����
//sbit VS_SI     =P1^5;  //�����������룬�ɵ�Ƭ��д�뵽VS1003
//sbit VS_SCK    =P1^7;  //����ʱ�ӣ��ɵ�Ƭ������
sbit VS_XDCS   =P1^5;  //����Ƭѡ
sbit VS_XCS    =P1^4;  //Ƭѡ�ź�
sbit VS_XRESET =P1^7;  //��λ�ź�
sbit VS_DREQ   =P1^6;  //��������

void VS_Reset(); //VS1003��λ����ʼ��
void VS_Write_Reg(unsigned char addr,unsigned char hdat,unsigned char ldat); //��VS1003�Ĺ��ܼĴ���д��һ����
unsigned int VS_Read_Reg(unsigned char addr); //��VS1003�Ĺ��ܼĴ�����ȡһ����
void VS_Send_Dat(unsigned char dat); //��VS1003������Ƶ����
void VS_Flush_Buffer(); //���VS1003�����ݻ�����
void VS_sin_test(unsigned char x); //���Ҳ���
void LoadPatch(); //ΪVS1003�򲹶�
#endif

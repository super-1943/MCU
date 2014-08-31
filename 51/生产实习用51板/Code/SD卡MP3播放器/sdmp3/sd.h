#ifndef __SD_H__
#define __SD_H__

#include <reg51.h>

/*******************************************************

        +------------------------------------+
        |  ���ϵ���   ��������ģ��   SD������|
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

sbit SD_SCL=P1^2; //SD��ͬ��ʱ��  ���
sbit SD_SI =P1^1; //SD��ͬ������  ����
sbit SD_CS =P1^0; //SD��Ƭѡ 	  ����
sbit SD_SO =P1^3; //SD��ͬ������  ���

#define DELAY_TIME 2000 //SD���ĸ�λ���ʼ��ʱSPI����ʱ����������ʵ�������޸���ֵ����������SD����λ���ʼ��ʧ��
#define TRY_TIME 200    //��SD��д������֮�󣬶�ȡSD���Ļ�Ӧ����������TRY_TIME�Σ������TRY_TIME���ж�������Ӧ��������ʱ��������д��ʧ��

//�����붨��
//-------------------------------------------------------------
#define INIT_CMD0_ERROR     0x01 //CMD0����
#define INIT_CMD1_ERROR     0x02 //CMD1����
#define WRITE_BLOCK_ERROR   0x03 //д�����
#define READ_BLOCK_ERROR    0x04 //�������
//-------------------------------------------------------------

//��������
unsigned char SD_Reset();
unsigned char SD_Init();
unsigned char SD_Write_Sector(unsigned long addr,unsigned char *buffer);
unsigned char SD_Read_Sector(unsigned long addr,unsigned char *buffer);

#endif
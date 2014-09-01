#ifndef _kkk_ziku_12864_h
#define _kkk_ziku_12864_h

#include "msp430x15x.h"

#define DataDir_12864     P4DIR
#define DataOut_12864     P4OUT
#define DataIn_12864      P4IN
#define IsData_12864      P5OUT|= 0x08
#define IsComd_12864      P5OUT&=~0x08
#define IsRead_12864      P5OUT|= 0x04
#define IsWrite_12864     P5OUT&=~0x04
#define E_1_12864         P5OUT|= 0x02
#define E_0_12864         P5OUT&=~0x02



void init_12864(void);

void delay_12864(unsigned int t);

void write_cmd_12864(unsigned char cmd);

void write_data_12864(unsigned char d);

unsigned char read_stat_12864(void);

unsigned char read_data_12864(void);

/***********************************************************************************
�ֽڵ�����
Ŀ���ǽ�һ���ֽڸߵ�λ˳��ߵ���d0~d7��Ϊd7~d0
��ڲ�����
unsigned char d;-----------��ת��������

***********************************************************************************/
unsigned char byte_reverse(unsigned char d);

/************************************************************************************
д���ֺ���
��ڲ�����
unsigned char * str;--------���������׵�ַ

unsigned char first_addr;    --------��ʾ�׵�ַ��������Ļ�ϵڼ�������λ�ô���ʼ��ʾ

unsigned char first_hanzi;    --------�ӵڼ������ֿ�ʼ��ʾ

unsigned char length;    --------ϣ����ʾ�ĺ��ָ���
*************************************************************************************/
void write_Chinese_12864(
                         unsigned char *str,
                         unsigned char first_addr,
                         unsigned char first_hanzi,
                         unsigned char length
                           );
/************************************************************************************
����ת��Ϊ�ַ�������
��ڲ�����
unsigned int myint;----------��Ҫת��������
unsigned char *str;----------ת���������ڸ�������
************************************************************************************/
void IntToStr(unsigned int myint, unsigned char *str) ;


#endif
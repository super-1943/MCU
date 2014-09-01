#ifndef _kkk_ziku_12864_h
#define _kkk_ziku_12864_h



//����ĺ꣬0�����з�ʽ��1�����з�ʽ
#define _kkk_p_or_s    0



#include "msp430x14x.h"


#if _kkk_p_or_s==0
//���з�ʽ
/***********************************
Ӳ�����ߣ�
PSB=0
P1.7---------------RS(CS)
P1.6---------------RW(SID)
P1.5---------------E(SCLK)
***********************************/
#define DataOut_12864   P1DIR|= 0x40
#define DataIn_12864    P1DIR&=~0x40
#define CS_1_12864      P1OUT|= 0x80
#define CS_0_12864      P1OUT&=~0x80
#define SID_1_12864     P1OUT|= 0x40
#define SID_0_12864     P1OUT&=~0x40
#define SCLK_1_12864    P1OUT|= 0x20
#define SCLK_0_12864    P1OUT&=~0x20
#define SID_IN          P1IN&0x40


#else
//���з�ʽ
/***********************************
Ӳ�����ߣ�
PSB=1
P5.3---------------RS(CS)
P5.2---------------RW(SID)
P5.1---------------E(SCLK)
P4.0~P4.7----------DB0~DB7
***********************************/
#define DataDir_12864     P4DIR
#define DataOut_12864     P4OUT
#define DataIn_12864      P4IN
#define IsData_12864      P5OUT|= 0x08
#define IsComd_12864      P5OUT&=~0x08
#define IsRead_12864      P5OUT|= 0x04
#define IsWrite_12864     P5OUT&=~0x04
#define E_1_12864         P5OUT|= 0x02
#define E_0_12864         P5OUT&=~0x02

#endif

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
#ifndef _kkk_pga113_h
#define _kkk_pga113_h
#include "msp430x16x.h"
/*********************************************************
���ߣ�kkk
���ڣ�2009-8-20
���ܣ�ʵ��PGA113��SPI����
Ӳ�����ӣ�
  P5.1============CS
  P5.3============SCLK
  P5.5============SDATA
���˵������ֲʱֻ��ı䱾ͷ�ļ�Ӳ�����Ӳ��ּ���
*********************************************************/
/***Ӳ�����Ӳ���***/
#define DIR_IN_pga113  P5DIR&=~0x20
#define DIR_OUT_pga113 P5DIR|= 0x20
#define DATA_IN_pga113 P5IN&0x20
#define SDATA_0_pga113 P5OUT&=~0x20
#define SDATA_1_pga113 P5OUT|= 0x20
#define SCLK_0_pga113  P5OUT&=~0x08
#define SCLK_1_pga113  P5OUT|= 0x08
#define CS_0_pga113    P5OUT&=~0x02
#define CS_1_pga113    P5OUT|= 0x02
#define INIT_pga113    P5DIR|=0x2a

/***һЩ��������***/
#define READMODE   0x6a00

#define WRITEMODE  0x2a00
#define Gain(x)  ((x)<<4)
#define CH(x)     (x)


#define SHUTDOWN    0xe1f1
#define NORMAL      0xe100


void delay_pga113(unsigned int i);
void send_data_pga113(unsigned int d);
unsigned int read_data_pga113(void);
void init_pga113(void);

#endif
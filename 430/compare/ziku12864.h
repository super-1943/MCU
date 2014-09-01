#ifndef _kkk_ziku_12864_h
#define _kkk_ziku_12864_h



//下面的宏，0代表串行方式，1代表并行方式
#define _kkk_p_or_s    0



#include "msp430x16x.h"


#if _kkk_p_or_s==0
//串行方式
/***********************************
硬件连线：
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
//并行方式
/***********************************
硬件连线：
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

void graph_clear(void);

void graph(unsigned char * table);

void delay_12864(unsigned int t);

void write_cmd_12864(unsigned char cmd);

void write_data_12864(unsigned char d);

unsigned char read_stat_12864(void);

unsigned char read_data_12864(void);

/***********************************************************************************
字节倒序函数
目的是将一个字节高低位顺序颠倒，d0~d7变为d7~d0
入口参数：
unsigned char d;-----------待转换的数据

***********************************************************************************/
unsigned char byte_reverse(unsigned char d);

/************************************************************************************
写汉字函数
入口参数：
unsigned char * str;--------汉字数组首地址

unsigned char first_addr;    --------显示首地址，即在屏幕上第几个汉字位置处开始显示

unsigned char first_hanzi;    --------从第几个汉字开始显示

unsigned char length;    --------希望显示的汉字个数
*************************************************************************************/
void write_Chinese_12864(
                         unsigned char *str,
                         unsigned char first_addr,
                         unsigned char first_hanzi,
                         unsigned char length
                           );
/************************************************************************************
整数转换为字符串函数
入口参数：
unsigned int myint;----------需要转换的整数
unsigned char *str;----------转换结果存放在该数组中
************************************************************************************/
void IntToStr(unsigned int myint, unsigned char *str) ;


#endif
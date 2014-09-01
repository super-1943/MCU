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
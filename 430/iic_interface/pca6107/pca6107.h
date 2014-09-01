#ifndef _kkk_pca6107_h
#define _kkk_pca6107_h
#include "msp430x14x.h"
#define ADDR_pca6107 0x30


/********************************
为了方便操作，写了三个常用宏
DDR(x)  和AVR一样，对应位为1代表输出，为0代表输入
PIN     得到引脚输入
POUT(x) 和AVR一样，对应位为1代表高电平输出，为0代表低电平输出
*********************************/
#define DDR(x) set_reg_6107(3,~(x))
#define PIN     get_reg_6107(0)
#define POUT(x) set_reg_6107(1,(x))
void set_reg_6107(unsigned char reg,unsigned char da);
unsigned char get_reg_6107(unsigned char reg);

#endif
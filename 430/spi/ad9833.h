#ifndef _kkk_ad9833_h
#define _kkk_ad9833_h

#define hard_ware_en 0
/*记得修改这里，0代表使用软件模拟SPI，1代表使用硬件SPI*/




#include "msp430x16x.h"
//Registers of AD9833
#define Control_Reg_9833  0x0000
#define Freq0_Reg_9833    0x4000
#define Freq1_Reg_9833    0x8000
#define Phase0_Reg_9833   0xc000
#define Phase1_Reg_9833   0xe000

//bits of Control_Reg
#define B28_9833          0x2000
#define HLB_9833          0x1000
#define FS_9833           0x0800
#define PS_9833           0x0400
#define RST_9833     0x0100
#define SLEEP1_9833       0x0080
#define SLEEP2_9833       0x0040
#define OPT_9833     0x0020
#define DIV2_9833         0x0008
#define MODE_9833         0x0002


#if hard_ware_en < 1

#define SDATA_0_9833 P5OUT&=~0x20
#define SDATA_1_9833 P5OUT|= 0x20
#define SCLK_0_9833  P5OUT&=~0x08
#define SCLK_1_9833  P5OUT|= 0x08

#endif

#define CS_0_9833    P5OUT&=~0x02
#define CS_1_9833    P5OUT|= 0x02




void init_ad9833(void);
void delay_ad9833(unsigned int i);
void send_ad9833(unsigned int d);
void autoset(unsigned char bo,unsigned int freq);
void wave_select(unsigned char i);
void select_freq(unsigned int freq);
void MCLK_sleep(void);
void DA_sleep(void);
void send_phase(unsigned int ph);
void send_freq_14(unsigned char hl,unsigned int d);
void send_freq_28(unsigned int low,unsigned int high);
void autoset_test(unsigned char bo,unsigned int freq);
void scan_freq(unsigned int start_freq,unsigned int end_freq,unsigned int step,unsigned char bo);
#endif
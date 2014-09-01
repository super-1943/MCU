#ifndef _kkk_ad9833_h
#define _kkk_ad9833_h
#include "msp430x15x.h"
//Registers of AD9833
#define Control_Reg  0x0000
#define Freq0_Reg    0x4000
#define Freq1_Reg    0x8000
#define Phase0_Reg   0xc000
#define Phase1_Reg   0xe000

//bits of Control_Reg
#define B28          0x2000
#define HLB          0x1000
#define FS           0x0800
#define PS           0x0400
#define RST_9833     0x0100
#define SLEEP1       0x0080
#define SLEEP2       0x0040
#define OPT_9833     0x0020
#define DIV2         0x0008
#define MODE         0x0002

#define SDATA_0 P5OUT&=~0x20
#define SDATA_1 P5OUT|= 0x20
#define SCLK_0 P5OUT&=~0x08
#define SCLK_1 P5OUT|= 0x08
#define CS_0 P5OUT&=~0x02
#define CS_1 P5OUT|= 0x02



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
#endif
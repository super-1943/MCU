#ifndef _kkk_FSTN_h
#define _kkk_FSTN_h
#include <msp430x16x.h>
/**************************************
P1.0--->P1.7:DB0---->DB7
P2.0:CS
P2.1:RST
P2.2:RS
P2.3:WR
P2.4:RD
8080ģʽ
**************************************/
#define DATADIR		P1DIR
#define DATAOUT		P1OUT
#define DATAIN		P1IN

#define CTRLDIR		P2DIR
#define CTRLOUT		P2OUT
#define CTRLIN		P2IN

#define DATA_DIR_OUT()		(DATADIR=0xff)
#define DATA_DIR_IN()		(DATADIR=0x00)
#define CTRL_DIR_OUT()		(CTRLDIR=0xff)
#define CTRL_DIR_IN()		(CTRLDIR=0x00)

#define CS_0	CTRLOUT&=~0x01
#define CS_1	CTRLOUT|= 0x01
#define RST_0	CTRLOUT&=~0x02
#define RST_1	CTRLOUT|= 0x02
#define RS_0	CTRLOUT&=~0x04
#define RS_1	CTRLOUT|= 0x04
#define WR_0	CTRLOUT&=~0x08
#define WR_1	CTRLOUT|= 0x08
#define RD_0	CTRLOUT&=~0x10
#define RD_1	CTRLOUT|= 0x10

void fstn_delay(unsigned int t);
void w_data(unsigned char d);
unsigned char r_data(void);
void w_comd(unsigned char c);
unsigned char r_comd(void);
void init_fstn(void);
#endif
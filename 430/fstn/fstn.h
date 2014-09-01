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
8080模式
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






//fstn液晶屏特殊命令
#define ICON_EN		0xa3
#define ICON_DIS	0xa2
#define SET_PAGE_ADDR	0xb0/*+page*/
#define SET_COL_ADDR_765	0x10/*+addr*/
#define SET_COL_ADDR_4321	0x00/*+addr*/
#define SET_MODIFY_READ		0xe0
#define RESET_MODIFY_READ	0xee
#define DISPLAY_ON			0xaf
#define DISPLAY_OFF			0xae
#define REVERSE_ON			0xa7
#define REVERSE_OFF			0xa6
#define ENTIRE_ON			0xa5
#define ENTIRE_OFF			0xa4
#define NOP					0xe3
#define SOFT_RESET			0xe2






void fstn_delay(unsigned int t);
void w_data(unsigned char d);
unsigned char r_data(void);
void w_comd(unsigned char c);
unsigned char r_comd(void);
void init_fstn(void);

void show_hanzi(
				const unsigned char *p,//汉字库的起始地址
				unsigned char page,//第几页，范围0~11
				unsigned char col//第几列，范围0~127
			   );

void show_char(
			   unsigned char it,//ASCII字符
			   unsigned char page,//参数page取值为0~11，从上到下
			   unsigned char col,//参数col取值为0~127从左到右
			   unsigned char isReverse//是否反显呢？1是0否
			   );
void show_str(	
			   unsigned char *it,//ASCII字符串，默认结束符为0x00即NULL
			   unsigned char page,//参数page取值为0~11，从上到下
			   unsigned char col,//参数col取值为0~127从左到右
			   unsigned char isReverse//是否反显呢？1是0否
			   );
void clear_all(void);
#endif
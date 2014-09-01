#ifndef _19264_h_
#define _19264_h_
#include "msp430x14x.h"

/********需要根据实际修改的部分*****************************/
//实际的模拟值与存储数字值之比
#define RATIO 0.5
/***********************************************************/

#define _delay_us(x) delay(x);
#define DataDir		P1DIR
#define DataBus		P1OUT
#define DataPin		P1IN

#define ComBus		P2OUT
#define ComDir		P2DIR

#define RS			0x01
#define RW			0x02
#define EN			0x04
#define ChipCS1		0x08
#define ChipCS2		0x10
#define ChipCS3		0x20
#define RST			0x40
extern void delay(int x);
extern void InitLCM();
extern void WriteCom(unsigned char com,unsigned char chipselect);

extern void WriteData(unsigned char dat,unsigned char chipselect);

extern unsigned char Readstatus(unsigned char chipselect);

extern unsigned char ReadBusy(unsigned char chipselect);

extern unsigned char ReadData(unsigned char chipselect);

extern void WriteBmp(const unsigned char *ptr);
//extern void WriteChar(unsigned char *ptr,unsigned char page,unsigned char row,unsigned char chipselect);
extern void WriteChinese(const unsigned char *p,unsigned char page,unsigned char row,unsigned char chipselect);
extern void WriteChar(const unsigned char *str,unsigned char line,unsigned char row,unsigned char chipselect);
extern void WriteChar_RVS(const unsigned char *str,unsigned char line,unsigned char row,unsigned char chipselect);
extern void ClearLCM();
extern void kkk_19264_show(unsigned char page,unsigned char offset);
#endif

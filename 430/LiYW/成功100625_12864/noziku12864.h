#ifndef _NOZIKU12864_h_
#define _NOZIKU12864_h_
#include "msp430x14x.h"

/********��Ҫ����ʵ���޸ĵĲ���*****************************/
//ʵ�ʵ�ģ��ֵ��洢����ֵ֮��
#define RATIO 0.61
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
extern void kkk_12864_show(unsigned char page,unsigned char offset);
#endif

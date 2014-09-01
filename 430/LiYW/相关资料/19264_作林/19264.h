#ifndef _19264_h_
#define _19264_h_


#define DataDir		DDRB
#define DataBus		PORTB
#define DataPin		PINB

#define ComBus		PORTD
#define ComDir		DDRD

#define RS			0x01
#define RW			0x02
#define EN			0x04
#define ChipCS1		0x08
#define RST			0x10
#define ChipCS2		0x20
#define ChipCS3		0x40


extern void InitLCM();
extern void WriteCom(unsigned char com,unsigned char chipselect);

extern void WriteData(unsigned char dat,unsigned char chipselect);

extern unsigned char Readstatus(unsigned char chipselect);

extern unsigned char ReadBusy(unsigned char chipselect);

extern unsigned char ReadData(unsigned char chipselect);

extern void WriteBmp(unsigned char *ptr);
//extern void WriteChar(unsigned char *ptr,unsigned char page,unsigned char row,unsigned char chipselect);
extern void WriteChinese(unsigned char *p,unsigned char page,unsigned char row,unsigned char chipselect);
extern void WriteChar(unsigned char *str,unsigned char line,unsigned char row,unsigned char chipselect);
extern void ClearLCM();

#endif

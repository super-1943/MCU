#include <avr/io.h>
#include <avr/pgmspace.h>

#define databus_w PORTB
#define databus_r PINB
#define xtal_0 (PORTC&=~0x01)
#define xtal_1 (PORTC|=0x01)

#define PROG_1 (PORTC|=0x02)
#define PROG_0 (PORTC&=~0x02)

// somedata_for_portc

#define WriteCodeData 0x38
#define ReadCodeData 0x18
#define ChipErase 0x04
#define ReadSignatureByte 0x00

#define lengthofcode 20
const unsigned char dataforprogram[20]PROGMEM={
0x74,0x01,0xF5,0x90,0x11,0x0B,0x03,0x80,0xF9,0x80,
0xF5,0x79,0xFF,0x7A,0xFF,0xDA,0xFE,0xD9,0xFA,0x22};








void initport(void)
{
	asm("NOP");
	DDRB=0xff;
	DDRC=0xff;
	PORTB=0x00;
	PORTC=0x00;
	asm("NOP");
}

void delay(unsigned int i)
{
	unsigned int a,b;
	while(i--)
	{
		for(a=200;a;a--)
		for(b=10;b;b--)
		asm("NOP");
	}
}

void erasechip(void)
{
	initport();
	PORTC=ChipErase;
	PROG_1;
	delay(1);
	PROG_0;
	delay(10);
	PROG_1;
}

void writecode(unsigned char c)
{
	PORTC=WriteCodeData;
	databus_w=c;
	PROG_1;
	delay(1);
	PROG_0;
	delay(1);
	PROG_1;
	databus_w=0x00;
	xtal_0;delay(1);
	xtal_1;delay(1);
	xtal_0;
}
/*
unsigned char readcode(void)
{
	unsigned char a;
	DDRB=0x00;
	PORTB=0x00;
	PORTC=ReadCodeData;

	PROG_1;
	delay(10);
	a=PINB;
	DDRB=0xff;
	return a;
}
unsigned char readmark(void)
{
	unsigned char a;
	DDRB=0x00;
	PORTC=ReadSignatureByte;

	PROG_1;
	delay(10);
	a=PINB;
	DDRB=0xff;
	return a;
}
	
*/
int main(void)
{
	unsigned char *p=dataforprogram,count=0;
	initport();
	erasechip();
	while(count<lengthofcode)
	{
		writecode(pgm_read_byte(p));
		p++;
		count++;
	}
	
	while(1)
	;
}

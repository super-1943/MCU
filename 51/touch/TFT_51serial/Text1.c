#include <reg51.h>
#include "tusb2136.h"
#include <string.h>
#include "font.h"
#include "tft.h"
#include "serial.h"


void serial_int(void)interrupt 4 using 1
{
	if(RI)
	{
		P0=SBUF;
		RI=0;
	}
	if(TI)
	{
		TI=0;
	}
}




void delay_ms(uint16 t)
{
	uint16 a;
	while(t--)
	{
		for(a=0;a<255;a++);
	}
}
void main(void)
{
	rs232_init();
	LCD_RESET = 1;
	Delay(50);
	LCD_RESET = 0;
	Delay(200);
	LCD_RESET = 1;
	Delay(50);
	SPFD5408A_CPT24_Initial();
	Blue();
	rs232_printstr("Hello world!\r\n");
	drawline(0,0x00ef,0,0x018f,0xffff);
	while(1)
	{
		delay_ms(10);
	}
}
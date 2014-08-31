//---------------------------------------------------------------------------
/**************************
KGM701A9: 16bit interface
VDD : 2.8~3.3V
DB7-DB0 : P1
DB15-DB8 : P2
RS : P3.2
WR: P3.3
RD  : P3.4
RESET : P3.5
CS : Connect to GND
FMARK : Not Connect
***************************/
#include "reg52.h"
#include "font.h"
#include "string.h"
#include "tft.h"
void main(void)
{
	SPFD5420A_CPT30W_Initial();
	Clear();
//	juxing(0,0,239,40,0x07e0);
//	Blue(1,238,1,39);
//	ShowString(1,1,"Hello ,world!!!");
//	ShowString(1,17,"My name is KKK!!!");
//	Delay(1000);
	Clear();
	juxing(0,0,239,20,0x07e0);
	Blue(1,238,1,19);
	ShowString(1,1,"Now let's have a look!");
	Delay(1000);
//	show_pic(pic_1,0,0,50,39);
	while(1)
	{
//		blue_dark_zong();
//		red_dark_heng();
//		green_dark_zong();
//		blue_dark_heng();
//		red_dark_zong();
//		green_dark_heng();	
//		Clear();
//		drawline(0,0x00ef,0,0x018f,0xffff);
//		drawline(0,0x00ef,0,0x018f,0xffff);
//		drawline(0,0,0,399,0xffff);
//		drawline(239,239,0,399,0xffff);
//		drawline(0,239,0,0,0xffff);
//		drawline(0,239,399,399,0xffff);
//		Delay(1000);
//		Clear();
		sin();
		Delay(1000);
		Clear();
//		show_pic(gImage_1,40,40,60,40);
	}
}

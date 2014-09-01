#include "flash.h"
extern unsigned int Analog[26];
void flash_clr(unsigned int *ptr)
{
	FCTL3 = 0x0A500;              //* Lock = 0 ¿ªËø
	FCTL1 = 0x0A502;              //* Erase = 1 Ê¹ÄÜ²Á³ý
	*((unsigned int *) ptr) = 0;           //* ²Á³ý¶Î
}
// ×ÖÐ´Èë
void flash_write_int16(unsigned int *ptr, unsigned int value)
{
	FCTL3 = 0x0A500;              /* Lock = 0 */
	FCTL1 = 0x0A540;              /* Write = 1 */
	*((unsigned int *) ptr) = value;       /* Program the flash */
}

void checkflash(void)
{
	unsigned int *p=(unsigned int *)SEG_A;
	unsigned char i;
	if(*p==0x55)
	{
		p++;
		for(i=0;i<25;i++)
		{
			Analog[i]=*p++;
		}
	}
	else
	{
		flash_clr(p);
		flash_write_int16(p++,0x55);
		for(i=0;i<25;i++)
		{
			flash_write_int16(p++,Analog[i]);
		}
	}
}
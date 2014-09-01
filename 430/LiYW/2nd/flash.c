#include "flash.h"
extern unsigned int Analog[25];
void flash_clr(unsigned int *ptr)
{
	FCTL3 = 0x0A500;              //* Lock = 0 开锁
	FCTL1 = 0x0A502;              //* Erase = 1 使能擦除
	*((unsigned int *) ptr) = 0;           //* 擦除段
}
// 字写入
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
		{//这里有错！2010-6-13
			Analog[i-1]=*p++;
		}
	}
	else
	{
		flash_clr(p);
		flash_write_int16(p++,0x55);
		for(i=0;i<25;i++)
		{//这里有错！2010-6-13
			flash_write_int16(p++,Analog[i-1]);
		}
	}
}
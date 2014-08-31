#include <reg52.h>



unsigned char i,j;
code unsigned char table[]=
{
/*--囧  调入了一幅图像：这是您新建的图像  --*/
/*--  宽度x高度=16x8  --*/
0xFF,0xA1,0xA1,0xAF,0xEF,0xC9,0xC9,0x89,0x89,0xC9,0xCF,0xEF,0xA1,0xA1,0xA1,0xFF,

};
void delay_ms(unsigned int k)
{
	unsigned char i,j;
	for(;k;k--)
	for(i=20;i;i--)
	for(j=100;j;j--);
}
void main(void)
{
	P3=0xff;
	
	EA=0;
	P0=0x00;
	delay_ms(1000);
	i=0;
	while(1)
	{
			for(i=0;i<16;i++)
			{
				P0=~table[i];
				delay_ms(10);
			}
	}

}
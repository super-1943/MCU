#include <reg51.h>
#include <intrins.h>
sbit data_240=P1^0;
sbit clk_240=P1^1;
sbit clk_320=P1^2;
void delay(void)
{
	unsigned char i,j;
	for(i=0;i<100;i++)
	for(j=200;j;j++);
}
void main(void)
{
	unsigned char i,j;
	P1=0x00;
	P2=0x00;
	while(1)
	{
		for(j=0;j<240;j++)
		{
			data_240=1;
			clk_240=1;
			for(i=0;i<80;i++)
			{
				clk_320=1;
				P2=0x55;
				clk_320=0;
				_nop_();
			}
			clk_240=0;
			_nop_();
		}
		delay();
	}
}

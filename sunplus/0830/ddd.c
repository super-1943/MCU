#include <spce061a.h>
unsigned int table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x00,0xff};
//						0   1   2     3    4    5    6    7    8    9  
void delay()
{
	int i,j;
	for(i=5;i;i--)
		for(j=15;j;j--);
	*P_Watchdog_Clear=0x01;
}
int main()
{
	int a,b,i;
	*P_IOA_Dir=0xffff;
	*P_IOA_Data=0xffff;
	*P_IOA_Attrib=0xffff;
	delay();
	while(1)
	{
		b=0x0100;
		for(i=0;i<8;i++)
		{
			a=table[i];
			
			*P_IOA_Data=a|b;
			delay();	
			b<<=1;
		}
		
		delay();

	
	}
}
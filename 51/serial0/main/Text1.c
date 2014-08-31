#include <at89x51.h>
sbit str=P3^2;

unsigned char number[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
unsigned char bits[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
unsigned char buffer[8]={0,2,4,6,8,7,5,1};
void delay(unsigned char x)
{
	unsigned char i,j;
	while(x--)
	for(i=48;i;i--)
	for(j=88;j;j--);
}

void senddata(unsigned char i,unsigned char j)
{
	SCON=0x00;
	str=0;
	SBUF=i;
	while(TI==0);
	TI=0;
	str=1;
	str=0;
	SBUF=j;
	while(TI==0);
	TI=0; 
	str=1;
}

void showbuffer(void)
{
	unsigned char i,t;
	for(i=0;i<8;i++)
	{
		
		senddata(bits[i],number[buffer[i]]);
		delay(30);
	}
}
void main(void)
{
	 while(1)
	 {
		showbuffer();
	 }

}
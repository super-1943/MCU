#include <reg51.h>
sbit oe=P1^0;
sbit addrl=P2^0;
sbit addrh=P2^1;
sbit ckl=P2^3;
sbit sck=P2^4;
sbit red=P2^5;
sbit green=P2^6;
#define addr(a) (addrl=a&0x01,addrh=a&0x02)
unsigned char code table[]={
0x00,0x60,
0x00,0x30,
0x00,0x18,
0xFF,0xFC,
0xFF,0xFE,
0x00,0x1C,
0x00,0x30,
0x00,0x60
};
unsigned char code heart[]={
0x00,0x00,0x31,0x80,0x4A,0x40,0x44,0x40,0x20,0xB6,0x11,0x49,0x0A,0x22,0x04,0x1C};
#ifdef GREEN_ON

#endif
void delay(void)
{
	unsigned char i,j;
	for(i=200;i;i--)
	for(j=20;j;j--);
}
void sendbyte(unsigned char t)
{
	unsigned char i;
	oe=1;
	ckl=0;
	sck=0;
	green=0;
	for(i=0;i<8;i++)
	{
		red=t&0x01;
		ckl=0;
		ckl=1;
		t>>=1;
	}	
}
void sendline(unsigned char line,unsigned char *t)
{
//	oe=1;
	sck=0;
	addr(line);
	sendbyte(t[1]);
	sendbyte(t[9]);
	sendbyte(t[0]);
	sendbyte(t[8]);
	sck=1;
	oe=0;
}
void show(void)
{
	sendline(3,table);
	delay();
	sendline(2,table+2);
	delay();
	sendline(1,table+4);
	delay();
	sendline(0,table+6);
	delay();
}
void show1(void)
{
	sendline(3,heart);
	delay();
	sendline(2,heart+2);
	delay();
	sendline(1,heart+4);
	delay();
	sendline(0,heart+6);
	delay();
}
void main(void)
{
	unsigned char i,j;
	while(1)
	{
		for(i=100;i;i--)
		show1();
		for(j=100;j;j--)
		show();		
	}
}
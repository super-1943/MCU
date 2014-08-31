#include <reg51.h>
sbit rs=P3^1;
sbit rw=P3^2;
sbit e=P3^3;
#define dataport P2

void readbusy(void);
void delay(unsigned int ms)
{
	unsigned char i,j;
	while(ms--)
	for(i=100;i;i--)
	for(j=7;j;j--);
}
void writecmd(unsigned char d)
{
	readbusy();
	rs=0;
	rw=0;
	dataport=d;
	e=1;
	delay(0);
	e=0;
}
void writedata(unsigned char d)
{
	readbusy();
	rs=1;
	rw=0;
	dataport=d;///////////////////////////////////ÓÐ¸Ä¶¯
	e=1;
	delay(0);
	e=0;
}
void readbusy(void)
{
	unsigned char i,j=2;
	rs=0;
	rw=1;
	e=1;
	dataport=0xff;
	i=dataport;
	while((i&0x80)&&(j++))
	{
		dataport=0xff;
		i=dataport;	
	}
}
unsigned char read_dat(void)
{
	rs=1;
	rw=1;
	e=1;
	return dataport;
}
void print_str(unsigned char *dat)
{
	while(*dat)
	{
		if(*dat=='\n')
		{
			writecmd(0xc0);
			dat++;
			
		}
		writedata(*dat);
		dat++;
	}
}
unsigned char key()
{
	unsigned char i;
	P1=0xff;
	if(P1==0xff)
	{
		return 0;
	}
	for(i=0;i<8;i++)
	{
		if((P1&(0x01<<i))==0)
		{
			return (i+1);
		}
	}
}
void initlcd(void)
{
	delay(300);
	writecmd(0x38);
	delay(15);
	writecmd(0x38);
	delay(1);
	writecmd(0x0e);
	delay(1);
	writecmd(0x06);
	delay(1);
	writecmd(0x01);
	delay(1);
}
int main(void)
{
	unsigned char i;
	initlcd();
	print_str("KKK is NO.1!!!");
	while(1)
	{
		i=key();
		switch(i)
		{
			case 1:
				writedata('a');
				break;
			case 2:
				writedata('b');
				break;
			case 3:
				writedata('1');
				break;
			case 4:
				writedata('2');
				break;
			case 5:
				writedata('3');
				break;
			case 6:
				writecmd(0x18);
				break;
			case 7:
				writecmd(0x01);
				break;
			case 8:
				writecmd(0x1c);
				break;
		}
		delay(300);
	}
}





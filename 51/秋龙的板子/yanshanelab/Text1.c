/*
P0----a/d
P2.0----rs
P2.1----rw
P2.2----e
P2.3
P2.4
P2.5----backlight
*/
#include <reg51.h>
#include <stdio.h>

sbit buzzer=P3^6;
sbit backlight=P2^5;
sbit key1=P3^2;
sbit key2=P3^4;

sbit rs=P2^0;
sbit rw=P2^1;
sbit e=P2^2;
#define dataport P0
unsigned char code table[]={0x09,0x06,0x04,0x05,0x04,0x04,0x04,0x05};
void delay(unsigned int ms);
void changebacklight(void);
void writecmd(unsigned char cmd);
void writedata(unsigned char dat);
void print_str(unsigned char *dat);
void setpos(unsigned char x,unsigned char y);
void initlcd(void);
void initserial(void);
void send_char(unsigned char txd);
void send_str(unsigned char *str);
void generate(void);
void readbusy(void);

void main(void)
{
	unsigned char tmp;
	initlcd();
	initserial();
	generate();
	send_char('a');
	while(1)
	{
		key1=1;
		key2=1;
		if(key1==0)
		{
			writedata(0x00);
			delay(100);
		}
		if(key2==0)
		{
			writecmd(0x01);
			delay(100);
		}
		if(RI)						// �Ƿ������ݵ���
		{
			RI = 0;
			tmp = SBUF;				// �ݴ���յ�������
			switch(tmp)
			{
				case 0x00:
					writecmd(0x1c);
					break;
				case 0x01:
					writecmd(0x18);
					break;
				case  '\n':
					writecmd(0xc0);
					break;
				case '\\':
					backlight=~backlight;
					break;
				case '<':
//					left();
					break;
				case '>':
//					right();
					break;
				case 0x02:
					writecmd(0x01);
					break;
				case '$':
					writecmd(0x02);
					break;
				case '{':
					writecmd(0x0f);
					break;
				case '}':
					writecmd(0x08);
					break;
				case '[':
//					showdate();
					break;
				case ']':
//					showtime();
					break;
				default:
					writedata(tmp);
			}
		}
	}
}


void delay(unsigned int ms)
{
	unsigned char i,j;
	while(ms--)
	for(i=100;i;i--)
	for(j=7;j;j--);
}
void changebacklight(void)
{
	backlight=~backlight;
	delay(1);
}
void readbusy(void)
{
	rs=0;
	rw=1;
	e=1;
	dataport&0x80;
}
	
void writecmd(unsigned char cmd)
{
	readbusy();
	rs=0;
	rw=0;
	dataport=cmd;
	e=1;
	delay(0);
	e=0;
}
void writedata(unsigned char dat)
{
	readbusy();
	rs=1;
	rw=0;
	dataport=dat&~0x80;///////////////////////////////////�иĶ�
	e=1;
	delay(0);
	e=0;
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
void setpos(unsigned char x,unsigned char y)
{
	unsigned char temp;
	temp=0x80;
	if(y==1)
	{
		temp+=x-1;
	}
	if(y==2)
	{
		temp+=(0x40+x-1);
	}
	writecmd(temp);
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
void initserial(void)
{
	TMOD = 0x20;			// ��ʱ��1������8λ�Զ�����ģʽ, ���ڲ���������
	TH1 = 0xFD;				// ������9600
	TL1 = 0xFD;
	
	SCON = 0x50;			// �趨���пڹ�����ʽ
	PCON &= 0xef;			// �����ʲ�����
		
	TR1 = 1;				// ������ʱ��1
	IE = 0x0;				// ��ֹ�κ��ж�
}
void send_char(unsigned char txd)// ����һ���ַ�
{
	SBUF = txd;
	while(!TI);				// �������ݴ���
	TI = 0;					// ������ݴ��ͱ�־
}

void send_str(unsigned char *str)// �����ִ�
{
	unsigned char i = 0;
	while(str[i] != '\0')
	{
		SBUF = str[i];
		while(!TI);				// �������ݴ���
		TI = 0;					// ������ݴ��ͱ�־
		i++;					// ��һ���ַ�
	}	
}

void showdate(void)
{
	writecmd(0x02);
	print_str("   2009-06-04  ");
}

void showtime(void)
{
	writecmd(0xc0);
	print_str("  17:25:29  ");
}
void left(void)
{
	unsigned char i;
	writecmd(0x05);
	for(i=39;i>0;i--)
	{
		writecmd(0x80+i);
		delay(100);
	}
	writecmd(0x06);
}
void right(void)
{
	unsigned char i;
	writecmd(0x07);
	for(i=0;i<40;i++)
	{
		writecmd(0x80+i);
		delay(100);
	}
	writecmd(0x06);
}
void generate(void)
{
	unsigned char i;
	writecmd(0x80);
	writecmd(0x40);
	for(i=0;i<8;i++)
	{
		writedata(table[i]);
	}
	writecmd(0x80);
}
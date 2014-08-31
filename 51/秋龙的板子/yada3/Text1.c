#include <reg51.h>

sbit rst=P2^0;
sbit io=P2^1;
sbit sck=P2^2;
unsigned char buffer[10];
void delay(unsigned char i)
{
	unsigned char j;
	while(i--)
	{
		for(j=200;j;j--);
	}
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
	EA=1;
	ES=1;
}
void serialint(void)interrupt 4 using 2
{
	if(RI)
	{
		RI=0;
		SBUF=SBUF;
	}
}
void send_byte(unsigned char d)
{
	ES=0;
	SBUF=d;
	while(!TI);
	TI=0;
	ES=1;
}
void send_str(unsigned char *str)// �����ִ�
{
	unsigned char i = 0;
	ES=0;
	while(str[i] != '\0')
	{
		SBUF = str[i];
		while(!TI);				// �������ݴ���
		TI = 0;					// ������ݴ��ͱ�־
		i++;					// ��һ���ַ�
	}
	ES=1;
}

void send1302(unsigned char d)
{
	unsigned char i;
	sck=0;
	for(i=0;i<8;i++)
	{
		if(d&0x01)
		{
			io=1;
		}
		else
		{
			io=0;
		}
		sck=0;
		sck=1;
		d>>=1;
	}
}

unsigned char read1302(void)
{
	unsigned char d=0,i;

	for(i=0;i<8;i++)
	{
		d>>=1;
		sck=1;
		io=1;
		sck=0;		
		if(io)
		{
			d|=0x80;
		}
	}
	return d;
}
void write1comd(unsigned char addr,unsigned char mydata)
{
	sck=0;
	rst=0;
	rst=1;
	send1302(addr);
	send1302(mydata);
	rst=0;
}
unsigned char read1byte(unsigned char addr)
{
	unsigned char ret;
	sck=0;
	rst=1;
	send1302(addr);
	ret=read1302();
	rst=0;
	return ret;
}
void main(void)
{
	initserial();
	write1comd(0x8e,0x00);
	write1comd(0x80,0x00);
	while(1)
	{

		buffer[0]=read1byte(0x81);
		
		send_byte(buffer[0]);
		delay(200);
	}
}
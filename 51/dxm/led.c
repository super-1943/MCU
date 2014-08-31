#include<reg52.h>
char a,b;
void delay(int i);
code char table[] = "0123456789ABCDEFXYZ";
void main()
{
/*	TMOD=0x01;
	TR0=1;
	ET0=1;
	EA=1;
	TH0=0xD8;
	TL0=0xf0;
	a=0;
	P1=0x55;*/
	
	
	TMOD = 0x20;			// 定时器1工作于8位自动重载模式, 用于产生波特率
	TH1 = 0xFD;				// 波特率9600
	TL1 = 0xFD;
	
	SCON = 0x50;			// 设定串行口工作方式
	PCON &= 0xef;			// 波特率不倍增
		
	TR1 = 1;				// 启动定时器1
	IE = 0x0;				// 禁止任何中断	
	a=0;
	b=0;
	
	SBUF = 'H';
	while(!TI);				// 等特数据传送
	TI = 0;					// 清除数据传送标志	
	
 	while(1)
	{
		P2=0xfe;
		{
			if((P2&0x10)==0)
			a=1;
			else if((P2&0x20)==0)
			a=2;
			else if((P2&0x40)==0)
			a=3;
			else if((P2&0x80)==0)
			a=4;
			else
			a=a;		
		}
		P2=0xfd;
		{
			if((P2&0x10)==0)
			a=5;
			else if((P2&0x20)==0)
			a=6;
			else if((P2&0x40)==0)
			a=7;
			else if((P2&0x80)==0)
			a=8;
			else
			a=a;
		}
		P2=0xfb;
		{
			if((P2&0x10)==0)
			a=9;
			else if((P2&0x20)==0)
			a=10;
			else if((P2&0x40)==0)
			a=11;
			else if((P2&0x80)==0)
			a=12;
			else
			a=a;
		}
		P2=0xf7;
		{
			if((P2&0x10)==0)
			a=13;
			else if((P2&0x20)==0)
			a=14;
			else if((P2&0x40)==0)
			a=15;
			else if((P2&0x80)==0)
			a=16;
			else
			a=a;
		}
		P1=a^0xff;
		if(a!=b)
		{
			SBUF = table[a];
			while(!TI);				// 等特数据传送
			TI = 0;					// 清除数据传送标志	
			b=a;
		}
		delay(10);
	}
}
void delay(int i)
{
	int j;
	
	while(i--)
	{
		j=400;
		while(j--);
	}
}
/*timer0() interrupt 1
{
	a++;
	TH0=0xD8;
	TL0=0xf0;
}*/
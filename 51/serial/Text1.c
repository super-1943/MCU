/*
*         单片机接收主机的数据,然后将数据传送到P0口, 并传回给主机;             *
*         当按下K1=P3.2 时, 单片机发送字www.hificat.com" 给主机       *                                                   *
*                                                                              *
*/   

#include <reg51.h>
#include <intrins.h>

unsigned char key_s, key_v, tmp;

char code str[] = "www.hificat.com";


void send_str();
bit	scan_key();
void proc_key();
void delayms(unsigned char ms);
void send_char(unsigned char txd);

sbit	K1 = P3^2;

main()
{
	TMOD = 0x20;			// 定时器1工作于8位自动重载模式, 用于产生波特率
	TH1 = 0xFD;				// 波特率9600
	TL1 = 0xFD;
	
	SCON = 0x50;			// 设定串行口工作方式
	PCON &= 0xef;			// 波特率不倍增
		
	TR1 = 1;				// 启动定时器1
	IE = 0x0;				// 禁止任何中断
	send_str();
	while(1)
	{
		if(RI)						// 是否有数据到来
		{
			RI = 0;
			tmp = SBUF;				// 暂存接收到的数据
			P0 = tmp;				// 数据传送到P0口
			send_char(tmp);			// 回传接收到的数据
		}		
	}
}

bit scan_key()	
// 扫描按键
{
	key_s = 0x00;
	key_s |= K1;
	return(key_s ^ key_v);	
}

void proc_key()
// 键处理
{
	if((key_v & 0x01) == 0)
	{			// K1按下
		send_str();				// 传送字串"welcome!...
	}
}

void send_char(unsigned char txd)
// 传送一个字符
{
	SBUF = txd;
	while(!TI);				// 等特数据传送
	TI = 0;					// 清除数据传送标志
}

void send_str()
// 传送字串
{
	unsigned char i = 0;
	while(str[i] != '\0')
	{
		SBUF = str[i];
		while(!TI);				// 等特数据传送
		TI = 0;					// 清除数据传送标志
		i++;					// 下一个字符
	}	
}

void delayms(unsigned char ms)	
// 延时子程序
{						
	unsigned char i;
	while(ms--)
	{
		for(i = 0; i < 120; i++);
	}
}
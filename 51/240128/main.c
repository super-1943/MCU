/*
240128��21�ţ�����˵����

Pin NO. Symbol Description(Function) Remark
1 FG Module Frame Ground
2 VSS Ground
3 VDD Supply voltage for logic and LCE(+)
4 V0 Operating voltage for LCD variable
5 WR Data Write into T6963C
6 RD Chip enable Signal
7 CE Command/Data Selection
8 C/D Command/Data Selection
9 Reset Reset signal
10 DB0 Data bit 0
11 DB1 Data bit 1
12 DB2 Data bit 2
13 DB3 Data bit 3
14 DB4 Data bit 4
15 DB5 Data bit 5
16 DB6 Data bit 6
17 DB7 Data bit 7
18 FS Font Selection
19 VEE LCD ��������ѹ
20 LED(+) LED or EL Backlight
21 LED(-) LED or EL Backlight

#include <at89x51.h>
#include <intrins.h>
void delay_us(unsigned char i)
{
	while(i--)
	{
		_nop_();
	}
}

void delay_ms(unsigned char i)
{
	unsigned char j;
	while(i--)
	{
		for(j=4;j;j--)
		{
			delay_us(100);
		}
	}
}
void delay_s(unsigned char i)
{
	unsigned char j;
	while(i--)
	{
		for(j=4;j;j--)
		{
			delay_ms(100);
		}
	}
}
void main(void)
{
	while(1)
	{

	}
}
*/
#include <at89x51.h>
#define uchar unsigned char
#define uint unsigned int
unsigned char ACC0;
#define bf0_fg (bit)(ACC0&0x01)
#define bf1_fg (bit)(ACC0&0x02)
#define bf3_fg (bit)(ACC0&0x04)

sbit lcd_wr = P3^6;
sbit lcd_rd = P3^7;
sbit lcd_cd = P2^0;
unsigned char code zimow[]=
{
/*--  ����:  ��  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=16x16   --*/
0x08,0x00,0x08,0x00,0x08,0x04,0x7E,0x84,0x08,0x48,0x08,0x28,0xFF,0x10,0x08,0x10,
0x28,0x28,0x2F,0x28,0x28,0x44,0x28,0x84,0x58,0x00,0x48,0x00,0x87,0xFE,0x00,0x00,
/*--  ������һ��ͼ���������½���ͼ��  --*/
/*--  ���x�߶�=16x16  --*/
0x00,0x00,0x10,0x08,0x00,0x00,0x10,0x00,0x00,0x40,0x10,0x00,0x02,0x00,0x00,0x50,
0x12,0x00,0x00,0x00,0x00,0x00,0x10,0x88,0x00,0x28,0x04,0x80,0x80,0x08,0x00,0x00
};
unsigned char zimoc[];
void lcd_read(void) /*Һ��������*/
{
	EA=0;
	P0 = 0xff;
	lcd_cd = 1;
	lcd_wr = 1;
	lcd_rd = 0;
	ACC0 = P0;
	lcd_rd = 1;
	EA=1;
}

void lcd_bf01(void) /*Һ�����ֽڶ�д��æ����*/
{
	do
	lcd_read();
	while (!(bf0_fg && bf1_fg));
}

void lcd_bf3(void) /*Һ��������д��æ����*/
{
	do
	lcd_read();
	while (!bf3_fg);
}

void lcd_stric(uchar datax) /*Һ�����ֽ�д�����*/
{
	lcd_bf01();
	EA=0;
	lcd_cd = 1;
	lcd_rd = 1;
	lcd_wr = 0;
	P0 = datax;
	lcd_wr = 1;
	EA=1;
}

void lcd_data(uchar datax) /*Һ�����ֽ�д���ݺ���*/
{
	EA=0;
	lcd_cd = 0;
	lcd_rd = 1;
	lcd_wr = 0;
	P0 = datax;
	lcd_wr = 1;
	EA=1;
}

void lcd_wt2(uchar data2,uchar comm) /*Һ��˫�ֽ�д����*/
{
	lcd_bf01();
	lcd_data(data2);
	lcd_stric(comm);
}

void lcd_wt3(uchar data1,uchar data2,uchar comm) /*Һ�����ֽ�д����*/
{
	lcd_bf01();
	lcd_data(data1);
	lcd_bf01();
	lcd_data(data2);
	lcd_stric(comm);
}

void lcd_clr(void) /*Һ����������*/
{
	uchar i,j=128;
	lcd_wt3(0,0,0x24);
	lcd_stric(0xb0);
	do
	{
		i=30;
		do
		{
			lcd_bf3();
			lcd_data(0);
			i--;
		}
		while (i);
		j--;
	}
	while (j);
	lcd_stric(0xb2);
}

void lcd_init(void) /*Һ����ʼ������*/
{
	P2=0x90;
	lcd_wt3(0,0,0x40);
	lcd_wt3(30,0,0x41);
	lcd_wt3(0,0,0x42);
	lcd_wt3(30,0,0x43);
	lcd_stric(0xa4);
	lcd_stric(0x80);
	lcd_stric(0x9c);
}

void lcd_word(uchar o_x,uchar o_y,uchar zm_code) /*�� ��o_x,0_y) λ����ʾ16*16����ĺ���*/
{
	uint xx,yy;
	uchar i=16;
	xx=o_y*30;
	xx+=o_x;
	yy=zm_code*0x20;
	do
	{
		lcd_wt3(xx,xx/256,0x24);
		lcd_wt2(zimow[yy],0xc0);
		yy++;
		lcd_wt2(zimow[yy],0xc0);
		yy++;
		xx+=30;
		i--;
	}
	while (i);
}

void lcd_fwd(uchar o_x,uchar o_y,uchar zm_code)
{
	uint xx,yy;
	uchar i=16;
	xx=o_y*30;
	xx+=o_x;
	yy=zm_code*0x20;
	do
	{
		lcd_wt3(xx,xx/256,0x24);
		lcd_wt2(~zimow[yy],0xc0);
		yy++;
		lcd_wt2(~zimow[yy],0xc0);
		yy++;
		xx+=30;
		i--;
	}
	while (i);
}

void lcd_fbt(uchar o_x,uchar o_y,uchar zm_code)/*�� ��o_x,0_y) λ����ʾ8*16����ĺ���*/

{
	uint xx,yy;
	uchar i=16;
	xx=o_y*30;
	xx+=o_x;
	yy=zm_code*0x10;
	do
	{
		lcd_wt3(xx,xx/256,0x24);
		lcd_wt2(~zimoc[yy],0xc0);
		yy++;
		xx+=30;
		i--;
	}
	while (i);
}

void lcd_byte(uchar o_x,uchar o_y,uchar zm_code)
{
	uint xx,yy;
	uchar i=16;
	xx=o_y*30;
	xx+=o_x;
	yy=zm_code*0x10;
	do
	{
		lcd_wt3(xx,xx/256,0x24);
		lcd_wt2(zimoc[yy],0xc0);
		yy++;
		xx+=30;
		i--;
	}
	while (i);
}

void main(void)
{
	lcd_init();
	while(1)
	{
		lcd_word(0,0,0);
	}
}




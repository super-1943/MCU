#define uchar unsigned char	//头文件 在程序中用uchar代替unsigned char
#define uint unsigned int
#include<reg51.h>  //源文件 源文件包含了变量以及函数的实体
#include<absacc.h>
#include <stdio.h> 
sbit E=P1^2; //液晶屏使能信号
sbit CS1=P1^3; //液晶屏左屏选通信号
sbit CS2=P1^4; //液晶屏右屏选通信号
sbit DI=P1^0;
uchar code chinese[ ]={   //定义数组
0x00,0x20,0x3F,0xF0,0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x08,0x7F,0xFC,0x02,0x80,  //无
0x02,0x80,0x04,0x80,0x04,0x80,0x08,0x80,0x08,0x82,0x10,0x82,0x20,0x7E,0x40,0x00,
0x08,0x40,0x08,0x50,0x10,0x48,0x10,0x40,0x22,0x7C,0x7F,0xC0,0x08,0x44,0x10,0x7E,  //线
0x23,0xC0,0x7C,0x48,0x00,0x50,0x00,0x20,0x1C,0x60,0xE0,0x92,0x43,0x0A,0x00,0x06,
0x02,0x00,0x02,0x00,0x02,0x10,0x7F,0xF8,0x42,0x10,0x42,0x10,0x7F,0xF0,0x42,0x10,   //电
0x42,0x10,0x7F,0xF0,0x42,0x10,0x02,0x00,0x02,0x04,0x02,0x04,0x01,0xFC,0x00,0x00,
};
uchar code start[ ]={0,1,2};
void send_command_l(uchar d) //左屏控制信号//
{uchar data i;
DI=0; CS1=1; CS2=0;
P0=d; E=1;
for(i=5;i!=0;i--); E=0;
for(i=5;i!=0;i--); E=1; }
void send_data_l(uchar d) //左屏数据信号//
{uchar data i;
DI=1; CS1=1; CS2=0;
for(i=10;i!=0;i--); P0=d;
for(i=10;i!=0;i--); E=1;
for(i=10;i!=0;i--); E=0;
for(i=5; i!=0;i--); E=1; }
void send_command_r(uchar d) //右屏控制信号//
{uchar data i;
DI=0; CS1=0; CS2=1;P0=d; E=1;
for(i=5;i!=0;i--); E=0;
for(i=5;i!=0;i--); E=1; }
void send_data_r(uchar d)  //右屏数据信号//
{uchar data i;
DI=1; CS1=0; CS2=1;P0=d; E=1;
for(i=5;i!=0;i--); E=0; 
for(i=5;i!=0;i--); E=1; }
void display_output_word(uchar x,uchar y,uchar *p1,uchar lth,bit sign)
{uchar *p2;  //指向字库中某个字的地址
uchar idata i,j,k;  //字记录，用于设定下一个字的起始列,便于换行。
k=0;
for(j=0;j<lth;j++)
{if(*p1==255)  //回车换行
{x=x+2;  //移动到下一行
k=0;}  //字记录初始化
else  //无回车换行
{p2=&chinese;  //取字库首地址;保存在word.h中数组chinese
 p2=p2+(*p1*32);  //移动到相应字所对应的地址
    if((y+k*16)>63)  //右半屏
	 {send_command_r(x+184);
	  send_command_r(y+k*16);
	  	for(i=0;i<16;i++)  //显示上半字
		{if(sign==1)
		 {send_data_r(*p2); p2++;}
		 else
		 { send_data_r(*p2^0xff);  //反色显示
		  p2++; }}
	  send_command_r(x+184+1);
	  send_command_r(y+k*16);
		for(i=0;i<16;i++)  //显示下半字
		{if(sign==1)
		 {send_data_r(*p2); p2++; }
	     else
		 {send_data_r(*p2^0xff); p2++; } }
        k++; }  //字记录增一
	else  //左半屏
	  {send_command_l(x+184);
	   send_command_l(y+64+k*16);
		 for(i=0;i<16;i++)  //显示上半字
		 {if(sign==1)
		  {send_data_l(*p2);  p2++; }
		  else
		  {send_data_l(*p2^0xff); 	p2++; }}
	   send_command_l(x+184+1);
	   send_command_l(y+64+k*16);
		 for(i=0;i<16;i++)  //显示下半字
		 {if(sign==1)
		  {send_data_l(*p2); p2++; }
		  else
		  {send_data_l(*p2^0xff); p2++; }}
		k++; } }    //字记录增一
	p1++; } }   //数组指针后移向下一个字
void main(void)
{ display_output_word(0,0,start,14,1);  //调用显示函数
while(1){;} 
}
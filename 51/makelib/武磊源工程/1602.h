#ifndef  __wl_lcd1602_H__
#define	 __wl_lcd1602_H__	
#include<reg52.h>       //包含单片机寄存器的头文件

/*************************************************/
sbit RS=P2^0;            //寄存器选择位，将RS位定义为P2.0引脚
sbit RW=P2^1;            //读写选择位，将RW位定义为P2.1引脚
sbit E=P2^2;             //使能信号位，将E位定义为P2.2引脚
sbit BF=P0^7;           //忙碌标志位，，将BF位定义为P0.7引脚	
#define Lcd_Data    P0 
                        //P0口并行数据传输

/***************************************************/					

void Lcd_delay1ms();		                   //函数功能：延时1ms    注：不同单片机不同晶振需要对此函数进行修改
void Lcd_delay(unsigned int n);	               //函数功能：延时若干毫秒	  
bit Lcd_BusyTest();		                   //函数功能：判断液晶模块的忙碌状态	  
void Lcd_WriteCom (unsigned char dictate);      //函数功能：将模式设置指令或显示地址写入液晶模块	   
void Lcd_WriteAddress(unsigned char x);	       //函数功能：指定字符显示的实际地址	
void Lcd_WriteData(unsigned char y);            //函数功能：将数据(字符的标准ASCII码)写入液晶模块
void Lcd_Int();                             //函数功能：对LCD的显示模式进行初始化设置
 void hanying_show(void);     //欢迎动画
#endif
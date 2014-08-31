#ifndef   __wl_18B20_H__
#define   __wl_18B20_H__

#define uchar unsigned char
#define uint unsigned int
#include<reg52.h>       //包含单片机寄存器的头文件

 /****************************************************/
sbit DQ=P1^3;			//18B20引脚
//sbit BEEP=P3^7;			//蜂鸣器引脚
/*****************************************************/
void Ds18B20_Delay(uint num);//延时函数
bit DS18B20_Init(); //初始化ds1820		延时30晶振
void Ds18B20_beep();		//蜂鸣器响一声函数
DS18B20_ReadOneByte();//读一个字节		 随着晶振调整延时
DS18B20_WriteOneByte(uchar dat);//写一个字节  随着晶振调整延时
void DS18B20_display_error();	  //函数功能：显示没有检测到DS18B20  
void DS18B20_display_explain(); //函数功能：显示说明信息
void DS18B20_display_symbol();	//函数功能：显示温度符号  
void DS18B20_display_dot(); //函数功能：显示温度的小数点  
void DS18B20_display_cent();	 //函数功能：显示温度的单位(Cent)
void DS18B20_display_temp1(unsigned char x);//函数功能：显示温度的整数部分
void DS18B20_display_temp2(unsigned char x);  //函数功能：显示温度的小数数部分
Ds18B20_GetTemperture();		   //读取温度
void Ds18B20_TempConv();		   //转换成适合在LCD上显示的数字
void Ds18B20_Display();			   //LCD显示
#endif
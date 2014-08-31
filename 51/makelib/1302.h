/***************************************************
按K1键时间停止，进入调时模式，同时屏幕右下角显示year，按K2键在year，month，day，hour，minute之间切换，
按K3键进行调时，调时完毕后按K4键时间开始
**********************************************************************************************/


#ifndef  __wl_ds1302_H__
#define  __wl_ds1302_H__

/****************************************************/
sbit SCLK=P1^0;   //位定义1302芯片的接口，时钟输出端口定义在P1.0引脚
sbit DATA=P1^1;   //位定义1302芯片的接口，数据输出端定义在P1.1引脚
sbit RST=P1^2;    //位定义1302芯片的接口，复位端口定义在P1.2引脚

sbit	K1 = P3^2;			//定义K1键
sbit	K2 = P3^3;			//定义K2键
sbit	K3 = P3^4;			//定义K3键
sbit	K4 = P3^5;			//定义K4键

sbit BEEP=P3^7 ;

/*******************************************************/
void Ds1302_delaynus(unsigned char n);  //函数功能：延时若干微秒
void Ds1302_delay1ms();
void Ds1302_beep();		//蜂鸣器响一声函数
void Ds1302_Write(unsigned char dat);   //函数功能：向1302写一个字节数据
void Ds1302_WriteSet(unsigned char Cmd,unsigned char dat);  //函数功能：根据命令字，向1302写一个字节数据
unsigned char Ds1302_Read();	//函数功能：从1302读一个字节数据
unsigned char  Ds1302_ReadSet(unsigned char Cmd); //函数功能：根据命令字，从1302读取一个字节数据
void Ds1302_Int();	//函数功能： 1302进行初始化设置
void Ds1302_DisplaySecond(unsigned char x);  //以下是1302数据的显示程序
void Ds1302_DisplayMinute(unsigned char x); //函数功能：显示分钟
void Ds1302_DisplayHour(unsigned char x); //函数功能：显示小时
void Ds1302_DisplayDay(unsigned char x); //函数功能：显示日
void Ds1302_DisplayMonth(unsigned char x);	  //函数功能：显示月
void Ds1302_DisplayYear(unsigned char x);  //函数功能：显示年
void Ds1302_QLShow();//在对应位置显示date ——
void time_get_show(); //获取时间
void KeyProcess();	 //按键处理函数
#endif
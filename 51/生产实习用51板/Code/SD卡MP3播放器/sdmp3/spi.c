#include "spi.h"

/*******************************************************

        +----------------------------------------+
        | 振南电子 驱动程序模块 软件模拟SPI 部分 |
        +----------------------------------------+

  此源码版权属 振南 全权享有，如欲引用，敬请署名并告知
        严禁随意用于商业目的，违者必究，后果自负
         振南电子 
             ->产品网站 http://www.znmcu.cn/
             ->产品网店 http://shop.znmcu.cn/
             ->产品咨询 QQ:987582714 
			            MSN:yzn07@126.com
	                    WW:yzn07	
									  
********************************************************/

unsigned char bdata dat; //dat是可位寻址的变量

sbit dat7=dat^7;
sbit dat6=dat^6;
sbit dat5=dat^5;
sbit dat4=dat^4;
sbit dat3=dat^3;
sbit dat2=dat^2;
sbit dat1=dat^1;
sbit dat0=dat^0; //取出dat的各个位

/******************************************************************
 - 功能描述：IO模拟SPI，发送一个字节
 - 隶属模块：SPI模块
 - 函数属性：外部，供用户调用
 - 参数说明：x:要发送的字节
 - 返回说明：无返回
 - 注：很多情况下，SPI是需要有较高的速度的，此函数中不使用任何循环
       结构，如for(;;) while等等，并且使用了位寻址就是为了提高速度
 ******************************************************************/

void SPI_WriteByte(unsigned char x) 
{
 /*----这种使用循环与位运算的实现方式，速度要比直接用位寻址与顺序执行方式实现慢得多
   ----因为它把大部分的时间花在了循环因子的递增、比较与位运行上了
  unsigned char i=0;
  for(i=0;i<8;i++)
  {
   SPI_SI=x&(0x80>>i);
   SPI_SCL=0; 
   SPI_SCL=1;
  }
 ----------------------------------*/

 dat=x;	//将x的值赋给可位寻址的变量dat，以便取出各个位
 
 SPI_SI=dat7; //取出第7个位，写到数据线上
 SPI_SCL=0; 
 SPI_SCL=1;	  //时钟线产生上升沿，数据被写入

 SPI_SI=dat6;
 SPI_SCL=0; 
 SPI_SCL=1;

 SPI_SI=dat5;
 SPI_SCL=0;
 SPI_SCL=1;

 SPI_SI=dat4;
 SPI_SCL=0;
 SPI_SCL=1;

 SPI_SI=dat3;
 SPI_SCL=0; 
 SPI_SCL=1;

 SPI_SI=dat2;
 SPI_SCL=0;
 SPI_SCL=1;

 SPI_SI=dat1;
 SPI_SCL=0; 
 SPI_SCL=1;

 SPI_SI=dat0;
 SPI_SCL=0;
 SPI_SCL=1;
}

/******************************************************************
 - 功能描述：IO模拟SPI，读取一个字节
 - 隶属模块：SPI模块
 - 函数属性：外部，供用户调用
 - 参数说明：无
 - 返回说明：读到的字节
 - 注：很多情况下，SPI是需要有较高的速度的，此函数中不使用任何循环
       结构，如for(;;) while等等，并且使用了位寻址就是为了提高速度
 ******************************************************************/

unsigned char SPI_ReadByte() 
{  
 SPI_SO=1;

 SPI_SCL=1;
 SPI_SCL=0;
 dat7=SPI_SO; 

 SPI_SCL=1;
 SPI_SCL=0;
 dat6=SPI_SO; 

 SPI_SCL=1;
 SPI_SCL=0;
 dat5=SPI_SO; 

 SPI_SCL=1;
 SPI_SCL=0;
 dat4=SPI_SO; 

 SPI_SCL=1;
 SPI_SCL=0;
 dat3=SPI_SO; 

 SPI_SCL=1;
 SPI_SCL=0;
 dat2=SPI_SO; 

 SPI_SCL=1;
 SPI_SCL=0;
 dat1=SPI_SO;

 SPI_SCL=1;
 SPI_SCL=0;
 dat0=SPI_SO; 
 
 return (dat);
}

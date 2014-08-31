 /*************************************************************************
文件名称：I2C2.H 
作 者：   徐修亮
版 本：   2008 7 25
说 明：   此头文件主要用于对I2C器件的各种操作.(可对其进行按字节,按地址,单个,边续,读
          写操作.十分好用.
修改记录：
  注意:注意: 函数是采用软件延时的方法产生SCL脉冲,固对高晶振频率要作 
一定的修改....(本例是1us机器周期,即晶振频率要小于12MHZ).

**************************************************************************/

/**************************************************************************
修改1:对接收函数做了修改,原文件时序写错.
日期:    2008-7-27
  bit IRecByte(uchar sla,uchar *ch)
{
  Start_I2c();
  SendByte(sla);
  if(ACK==0)    return 0;
  *ch=RecByte();
  Ack_I2c(1);
  Stop_I2c();
                return 1;
}
 bit IRecStr(uchar sla,uchar suba,uchar *ch,uchar n)
 {	uchar i;
    Start_I2c();
 	SendByte(sla);
       if(ACK==0)    return 0;
 	SendByte(suba);
        if(ACK==0)    return 0;
 	for(i=0;i<n;i++)
	{
	  *ch=RecByte();
	      Ack_I2c(1);
	   ch++;
     }
      Stop_I2c();
                return 1;
   }


****************************************************************************/
#ifndef __I2C2_H__
#define __I2C2_H__
/*************************************************************************/
#include "xuxiuliang.h"
/*************************************************************/
#define  _NOP _nop_()

sbit SCL=P1^6 ;
sbit SDA=P1^7 ;

bit  ACK      ;
/************************************************************
 函数名称：void Start_I2c(void) 
 函数功能： 起动I2c总线
 入口参数：  无
 出口参数：  无
 备 注： 

*************************************************************/
 void Start_I2c(void)
{
  SDA=1;
   _NOP;
  SCL=1;
  _NOP;             //起始信号建立时间Tsu:sta>=4.7us
  _NOP;			    
  _NOP;
  _NOP;
  _NOP;
  SDA=0;		    //发送起始信号
  _NOP;			    //起始信号保持时间Thd:dat>=4us
  _NOP;
  _NOP;
  _NOP;
  SCL=0; 		    //钳住I2C总线准备发送或接收数据
  _NOP;
  _NOP;        
}
/***************************************************************
函数名称：void Stop_I2c(void) 
函数功能：停止I2c总线 
入口参数： 无
出口参数： 无
备 注： 


***************************************************************/
 void Stop_I2c(void)
{ 
 SDA=0;
 _NOP;
 SCL=1;
 _NOP;           //停止信号建立时间Thd:sto>=4us
 _NOP;
 _NOP;
 _NOP;  
 SDA=1;			//发送停止信号
 _NOP;			//新的数据开始前总线空余时间Tbuf>=4.7us
 _NOP;
 _NOP;
 _NOP;
 _NOP;
 _NOP;
 }

 /***************************************************************
函数名称： 	void SendByte(uchar ch)
函数功能： 	发送一字节数据(数据或地址,指令均可)
入口参数： 	uchar ch     要发送的1字节数据
出口参数： 	无.  
备 注： 	 但函数对ACK 应答位有影响,若有应答则为1,无则为0


 *****************************************************************/
  void SendByte(uchar ch)
{
   uchar BitShift;        //移位数据
   for(BitShift=0;BitShift<8;BitShift++)
   {
     if((ch<<BitShift)&0x80)	  //判断数据位
	     SDA=1;
	 else SDA=0;			  //Thd:dat数据输入保持时间0ns
	 SCL=1;					  //时钟高电平时间Thigh >4us
	 _NOP;
	 _NOP;
	 _NOP;
	 _NOP;
	 SCL=0;					  //时钟低电平时间Tlow >4.7us
	}
	 _NOP;
	 _NOP;  
  	 SDA=1;                   //释放数据总线 接收应答信号
	 _NOP;
	 _NOP;
	 SCL=1;
	 _NOP;
	 _NOP;
	 _NOP;
	 if(SDA==0) 
	          ACK=1;		 //有应答则为1
	 else     ACK=0;		 //无应答或器件损坏则为0 
	 SCL=0;
	 _NOP;
	 _NOP;
}
/************************************************************
函数名称： uchar RecByte(void) 
函数功能： 接收I2c从机器件数据
入口参数： 无
出口参数： uchar RecByte()      函数返回读出的数据
备 注： 
*************************************************************/
  uchar RecByte(void)
{
 uchar rec;					//存接收数据
 uchar BitShift;
 rec=0;
 SDA=1;						//释放数据总线
 for(BitShift=0;BitShift<8;BitShift++)
 { _NOP;
   SCL=0;					//时钟低电平周期Tlow>4.7us
   _NOP;
   _NOP;
   _NOP;
   _NOP;
   SCL=1;				    //等待接收信号
   _NOP;				   //时钟高电平周期Thigh>4us
   _NOP;
   rec=rec<<1;
   if(SDA==1) rec++;
   _NOP;
   _NOP;
  }
   SCL=0;
   _NOP;
   _NOP;
   return rec;
}
  /**********************************************
函数名称： void Ack_I2c(bit a)
函数功能： 主机应答函数(在主机接收从机数据后的必要应答)
入口参数： bit a
出口参数： 无
备 注： 

  ************************************************/
  void Ack_I2c(bit a)
{
  if(a==0) SDA=0;
       else     SDA=1;  
  _NOP;
  _NOP;
  _NOP;
  SCL=1;
  _NOP;						 //时钟高电平周期>4us
  _NOP;
  _NOP;
  _NOP;
  _NOP;
  SCL=0;					//清时钟线,钳住时钟,以便继续接收
   _NOP;
   _NOP;
}
/************************************************************
               向无子地址器件发送一字节数据函数
函数名称： bit ISendByte(uchar sla,uchar ch)
函数功能： 从器件的启动,到发送器件地址sla,数据ch的全过程.发送成功返回1,否则返回0 
入口参数：  uchar sla 器件地址.uchar ch 待发送数据
出口参数： 	bit ISendByte
备 注： 	使用前必须已结束总线

***************************************************************/
bit ISendByte(uchar sla,uchar ch)
{
 Start_I2c();
 SendByte(sla);
 if(ACK==0) return 0;        // 无应答,结束发送,返回0
 SendByte(ch);
 if(ACK==0) return 0;
 Stop_I2c();
            return 1;        //发送成功返回1 
}
/********************************************************************
				  向有子地址器件发送多字节数据函数  

函数名称：bit ISendStr(uchar sla,uchar suba,uchar *ch,uchar n)
函数功能： 向有子地址I2C从机的子地址为suba的存储单元发送n个数据
入口参数：uchar sla 器件地址      uchar *ch 待发送的数据首地址     
          uchar suba 器件从地址	  uchar n	待发送的数据的个数
出口参数：bit ISendStr(uchar sla,uchar suba,uchar *ch,uchar n) 
备 注：    发送成功返回 1,不成功返回0
*********************************************************************/
 bit ISendStr(uchar sla,uchar suba,uchar *ch,uchar n)
{
  uchar i;
  Start_I2c();
  SendByte(sla);
  if(ACK==0)     return 0;
  SendByte(suba); 
   if(ACK==0)    return 0;
  for(i=0;i<n;i++)
  {
   SendByte(*ch);
   if(ACK==0)    return 0;
   ch++;
   }
   Stop_I2c();
   return 1;
}
/********************************************************************
			 向无子地址器件读字节数据函数
函数名称： 	bit IRecByte(uchar sla,uchar *ch)
函数功能： 	向没有子地址的从机读取数据,放入指针ch指向的地址空间
入口参数： 	uchar sla  从机地址 uchar *ch 读出的数据占时存放的地方
出口参数：   bit IRecByte(uchar sla,uchar *ch)  函数返回1则表时操作成功,0为失败
备 注： 
*******************************************************************/
  bit IRecByte(uchar sla,uchar *ch)
{
  Start_I2c();
     SendByte(sla+1);
  if(ACK==0)    return 0;
  *ch=RecByte();
  Ack_I2c(1);
  Stop_I2c();
                return 1;
}
/*******************************************************************************
         	 向有子地址器件读取多字节数据函数
函数名称： bit IRecStr(uchar sla,uchar suba,uchar *ch,uchar n)
函数功能： 向有地址器件读取
入口参数： uchar sla 从机地址 	   uchar *ch  指针指向读取数据
           uchar suba 从机子机址   uchar n    读取数据的个数
出口参数：  bit IRecByte(uchar sla,uchar *ch)  函数返回1则表时操作成功,0为失败
备 注： 


******************************************************************************/
 bit IRecStr(uchar sla,uchar suba,uchar *ch,uchar n)
 {	uchar i;
    Start_I2c();
 	SendByte(sla);
       if(ACK==0)    return 0;
 	SendByte(suba);
        if(ACK==0)    return 0;
	Start_I2c();			  // 再重新启动,发送地址,读数据.
	SendByte(sla+1);
	       if(ACK==0)    return 0;
 	for(i=0;i<n-1;i++)
	{
	  *ch=RecByte();
	      Ack_I2c(0);
	   ch++;
     }
	  *ch=RecByte();
            Ack_I2c(1);    
      Stop_I2c();
                return 1;
   }


 /* *****************************************************************************/
 #endif 
//声明:武磊  2009.7.19
//名称:四乘四按键函数
#ifndef _44T_module_h
#define _44T_module_h
#include<msp430x15x.h>
//***********************************************************
//名称:延时函数
//功能:延时
//参数:ms(毫秒)
//注意:此延时函数没有经过测试,可能会有较大误差
//***********************************************************
void delay_44T(uint ms)
{
        uint i,j;
	for(i=0;i<ms;i++)
	   {
	   for(j=0;j<1141;j++);
       }
}
//************************************************************
//名称:按键检测函数
//功能:判断是否有键被按下
//参数:无
//************************************************************
uchar key_press_44T()
{
         uchar i;
         P5DIR=0XFF;
	 P5OUT=0X0F;
	 P5DIR=0XF0;
	 i=P5IN;
	 if(i==0X0F)//判断引脚的值是否有变化，有就是有键被按下
	 { 
	   return 0;
	 }
	 else
	 {
	   return 1;
	 }
}
//***************************************************************
//名称:按键扫描函数
//功能:检测哪一个键被按下
//参数:无
//*****************************************************************
uchar key_scan_44T()
{
     uchar key,i=0,j;
     delay_44T(2);//一定要由按键去抖,但也不能时间太长，否则就检测不到了
	 if(key_press_44T())
               {
                  do
                      {
                       
                       P5OUT=~(1<<i);
                       P5DIR=0X0F;
                       key=P5IN;
                       j=key&0XF0;
                       i++;
                  }while(j==0XF0);//循环检测，直到检测到
                      
                 while(key_press_44T());//等待按键松开
                 switch(key)
                      {
                 case 0xEE:
                              key=0x0;
                              break;
                 case 0xDE:
                              key=0x1;
                              break; 
                 case 0xBE:
                              key=0x2;
                              break;
                 case 0x7E:
                              key=0x3;
                              break;
                 case 0xED:
                              key=0x4;
                              break;
                 case 0xDD:
                              key=0x5;
                              break;
                 case 0xBD:
                              key=0x6;
                              break;
                 case 0x7D:
                              key=0x7;
                              break;
                 case 0xEB:
                              key=0x8;
                              break;
                 case 0xDB:
                              key=0x9;
                              break;
                 case 0xBB:
                              key=0xA;
                              break;
                 case 0x7B:
                              key=0xB;
                              break;
                 case 0xE7:
                              key=0xC;
                              break;
                 case 0xD7:
                              key=0xD;
                              break;
                 case 0xB7:
                              key=0xE;
                              break;
                 case 0x77:
                              key=0xF;
                              break;
                 default:
                      key=16;		
                      }
               }
	 else //再次检测时没有键被按下，即第一次按键检测到的按键可能是抖动
	 {
	    key=17;
	 }
	 return key;
}
#endif
#ifndef __VS1003_H__
#define __VS1003_H__

/*******************************************************

        +------------------------------------+
        |  振南电子 高级外设模块 VS1003B 部分|
        +------------------------------------+

  此源码版权属 振南 全权享有，如欲引用，敬请署名并告知
        严禁随意用于商业目的，违者必究，后果自负
         振南电子 
             ->产品网站 http://www.znmcu.cn/
             ->产品论坛 http://bbs.znmcu.cn/
             ->产品网店 http://shop.znmcu.cn/
             ->产品咨询 QQ:987582714 MSN:yzn07@126.com
	                WW:yzn07				  
********************************************************/

#include <reg51.h>

//此IO定义与 振南的 天狼星精华板 相吻合

//sbit VS_SO     =P1^6; //串行数据输出，单片机从VS1003中读取数据
//sbit VS_SI     =P1^5;  //串行数据输入，由单片机写入到VS1003
//sbit VS_SCK    =P1^7;  //串行时钟，由单片机产生
sbit VS_XDCS   =P1^5;  //数据片选
sbit VS_XCS    =P1^4;  //片选信号
sbit VS_XRESET =P1^7;  //复位信号
sbit VS_DREQ   =P1^6;  //数据请求

void VS_Reset(); //VS1003软复位及初始化
void VS_Write_Reg(unsigned char addr,unsigned char hdat,unsigned char ldat); //向VS1003的功能寄存器写入一个字
unsigned int VS_Read_Reg(unsigned char addr); //从VS1003的功能寄存器读取一个字
void VS_Send_Dat(unsigned char dat); //向VS1003发送音频数据
void VS_Flush_Buffer(); //清空VS1003的数据缓冲区
void VS_sin_test(unsigned char x); //正弦测试
void LoadPatch(); //为VS1003打补丁
#endif

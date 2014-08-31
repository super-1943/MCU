#ifndef  _SPI_H_
#define  _SPI_H_

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

#include "reg51.h"

sbit SPI_SCL=P1^2;  //SPI同步时钟  输出
sbit SPI_SI =P1^1;  //SPI同步数据  输出
sbit SPI_SO =P1^3;  //SPI同步数据  输入

void SPI_WriteByte(unsigned char x);
unsigned char SPI_ReadByte();

#endif
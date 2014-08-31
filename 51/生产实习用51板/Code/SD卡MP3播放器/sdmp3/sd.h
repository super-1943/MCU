#ifndef __SD_H__
#define __SD_H__

#include <reg51.h>

/*******************************************************

        +------------------------------------+
        |  振南电子   驱动程序模块   SD卡部分|
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

sbit SD_SCL=P1^2; //SD卡同步时钟  输出
sbit SD_SI =P1^1; //SD卡同步数据  输入
sbit SD_CS =P1^0; //SD卡片选 	  输入
sbit SD_SO =P1^3; //SD卡同步数据  输出

#define DELAY_TIME 2000 //SD卡的复位与初始化时SPI的延时参数，根据实际速率修改其值，否则会造成SD卡复位或初始化失败
#define TRY_TIME 200    //向SD卡写入命令之后，读取SD卡的回应次数，即读TRY_TIME次，如果在TRY_TIME次中读不到回应，产生超时错误，命令写入失败

//错误码定义
//-------------------------------------------------------------
#define INIT_CMD0_ERROR     0x01 //CMD0错误
#define INIT_CMD1_ERROR     0x02 //CMD1错误
#define WRITE_BLOCK_ERROR   0x03 //写块错误
#define READ_BLOCK_ERROR    0x04 //读块错误
//-------------------------------------------------------------

//函数声明
unsigned char SD_Reset();
unsigned char SD_Init();
unsigned char SD_Write_Sector(unsigned long addr,unsigned char *buffer);
unsigned char SD_Read_Sector(unsigned long addr,unsigned char *buffer);

#endif
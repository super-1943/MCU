#ifndef  _MYFUN_H_
#define  _MYFUN_H_

/*******************************************************

        +------------------------------------+
        |振南电子 原创程序模块 公共函数部分  |
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

void delay(unsigned int time); //延时函数
void u32tostr(unsigned long dat,char *str);	//将一个32位的变量dat转为字符串
unsigned long strtou32(char *str); //将一个字符串转为32位的变量

#endif
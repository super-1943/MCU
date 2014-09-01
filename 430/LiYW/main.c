#include "msp430x14x.h"
#define Uchar unsigned char
#include "ziku.h"



/***********液晶显示器接口引脚定义***************/



#define Dilcm_0 P2OUT&=~0x01
#define Dilcm_1	P2OUT|=0x01
#define Rwlcm_0 P2OUT&=~0x02
#define Rwlcm_1 P2OUT|=0x02
#define Elcm_0  P2OUT&=~0x04
#define Elcm_1	P2OUT|=0x04
#define CS1LCM_0	P2OUT&=~0x08
#define CS1LCM_1	P2OUT|=0x08
#define CS2LCM_0	P2OUT&=~0x10
#define CS2LCM_1	P2OUT|=0x10
#define CS3LCM_0	P2OUT&=~0x20/*这个连接只是做实验的临时接法。*/
#define CS3LCM_1	P2OUT|=0x20
#define RSTLCM_0	P2OUT&=~0x40
#define RSTLCM_1	P2OUT|=0x40
#define DATADIRO	P1DIR=0xff
#define DATADIRI	P1DIR=0x00
#define Datalcm_o P1OUT //数据口
#define Datalcm_i P1IN	//


/********************************/

/****************全局变量定义*******************/
Uchar col,row,cbyte;  /*列x,行(页)y,输出数据 */
Uchar xy;    /*画线方向标志：1水平 */

/***********常用操作命令和参数定义***************/
#define  DISPON  0x3f /*显示on  */
#define  DISPOFF 0x3e /*显示off  */
#define  DISPFIRST 0xc0 /*显示起始行定义 */
#define  SETX  0x40 /*X定位设定指令（页） */
#define  SETY  0xb8 /*Y定位设定指令（列） */
#define  Lcdbusy 0x80 /*LCM忙判断位  */

/**************显示分区边界位置*****************/
#define  MODL  0x00 /*左区   */
#define  MODM  0x40 /*左区和中区分界 */
#define  MODR  0x80 /*中区和右区分界 */
#define LCMLIMIT 0xC0 /*显示区的右边界 */

/*****************函数列表**********************/
void Lcminit(void);  /*液晶模块初始化 */
void Delay(Uchar);  /*延时，入口数为Ms */
void lcdbusyL(void);  /*busy判断、等待(左区) */
void lcdbusyM(void);  /*busy判断、等待(中区) */
void lcdbusyR(void);  /*busy判断、等待(右区) */
void Putedot(Uchar);  /*半角字符输出  */
void Putcdot(Uchar);  /*全角(汉字)输出 */
void Wrdata(Uchar);  /*数据输出给LCM  */
void Lcmcls( void );  /*LCM全屏幕清零(填充0) */
void wtcom(void);  /*公用busy等待  */
void Locatexy(void);  /*光标定位  */
void WrcmdL(Uchar);  /*左区命令输出  */
void WrcmdM(Uchar);  /*中区命令输出  */
void WrcmdR(Uchar);  /*右区命令输出  */
void Putstr(Uchar *puts,Uchar i); /*中英文字符串输出 */
void Rddata(void);  /*  从液晶片上读数据 */
void point(void);  /*打点   */


Uchar STR2[]="Our friend over the wold";

int main( void )
{
    // Stop watchdog timer to prevent time out reset
    WDTCTL = WDTPW + WDTHOLD;
	DATADIRI;
	P2OUT=0x00;
	P2DIR=0xff;
	Delay(40);
	RSTLCM_1;

	col=0;
	row=0;
	Delay(40);  /*延时大约40Ms,等待外设准备好 */
	Lcminit();  /*液晶模块初始化，包括全屏幕清屏*/
	col=0;
	row=2;
	Putstr(STR2,12); /*第二行字符输出，12字节 */
    while(1)
    {
		
    	
    }
}



/****************************************/
/* 一个字串的输出   */
/****************************************/
void Putstr(Uchar *puts,Uchar i)
 {
  Uchar j,X;
  for (j=0;j<i;j++)
  {
  X = puts[j];
   if (X&0x80)
    {
     Putcdot(X&0x7f); /*只保留低7位*/
    }
   else Putedot(X-0x20);  /*ascii码表从0x20开始*/
  }
 }

/****************************************/
/*   半角字符点阵码数据输出  */
/****************************************/
void Putedot(Uchar Order)
{
	Uchar i,bakerx,bakery;/*共定义4个局部变量   */
	int x;/*偏移量，字符量少的可以定义为UCHAR */
	bakerx = col;/*暂存x,y坐标，已备下半个字符使用 */
	bakery = row;
	x=Order * 0x10;/*半角字符，每个字符16字节 */
/*上半个字符输出，8列 */
	for(i=0;i<8;i++)
	{
		cbyte = Ezk[x];    /*取点阵码，rom数组 */
		Wrdata(cbyte);    /*写输出一字节  */
		x++;
		col++;
		if (col==LCMLIMIT)
		{
			col=0;
			row++;
			row++;
		}/*下一列，如果列越界换行*/
		if (row>7) row=0;  /*如果行越界，返回首行 */
	}/*上半个字符输出结束 */
	
	col = bakerx;     /*列对齐  */
	row = bakery+1;     /*指向下半个字符行 */
/*下半个字符输出，8列 */
	for(i=0;i<8;i++)
	{
		cbyte = Ezk[x];    /*取点阵码  */
		Wrdata(cbyte);    /*写输出一字节  */
		x++;
		col++;
		if (col==LCMLIMIT)
		{
			col=0;
			row=row+2;
		}/*下一列，如果列越界换行*/
		if (row>7) row=1;  /*如果行越界，返回首行 */
	}     /*下半个字符输出结束 */
	row=bakery;
}/*整个字符输出结束 */


/****************************************/
/*  全角字符点阵码数据输出  */
/****************************************/
void Putcdot(Uchar Order)
{
	Uchar i,bakerx,bakery;/*共定义3个局部变量  */
	int x;/*偏移量，字符量少的可以定义为UCHAR */
	bakerx = col;/*暂存x,y坐标，已备下半个字符使用 */
	bakery = row;
	x=Order * 0x20;/*每个字符32字节 */
/*上半个字符输出，16列 */
	for(i=0;i<16;i++)
	{
		Wrdata(Hzk[x]);    /*写输出一字节  */
		x++;
		col++;
		if (col==LCMLIMIT){ col=0;row++;row++;} /*下一列，如果列越界换行*/
		if (row>6) row=0;  /*如果行越界，返回首行 */
	}     /*上半个字符输出结束 */
  
/*下半个字符输出，16列 */
	col = bakerx;
	row = bakery+1;
	for(i=0;i<16;i++)    /*下半部分*/
	{
		Wrdata(Hzk[x]);
		x++;
		col++;
		if (col==LCMLIMIT)
		{
			col=0;
			row++;
			row++;
		} /*下一列，如果列越界换行*/
		if (row>7) row=1;  /*如果行越界，返回首行 */
	}     /*下半个字符输出结束 */
	row = bakery;
}      /*整个字符输出结束 */

/****************************************/
/* 清屏，全屏幕清零  */
/****************************************/
void Lcmcls( void )
 {
 for(row=0;row<8;row++)
     for(col=0;col<LCMLIMIT;col++) Wrdata(0);
 }

/****************************************/
/*  从液晶片上读数据，保留在全局变量中 */
/****************************************/
#define _nop_() _NOP()
#define _kkk_430_program
void Rddata(void)
 {
 Locatexy();  /*坐标定位，返回时保留分区状态不变 */
  Datalcm_o=0xFF;
#ifdef _kkk_430_program
  DATADIRI;
#endif
  Dilcm_1; /*数据*/
  Rwlcm_1; /*读数据*/
  Elcm_1; /*读入到LCM*/
  _nop_();
  cbyte = Datalcm_i; /*虚读一次 */
  Elcm_0;
 Locatexy();  /*坐标定位，返回时保留分区状态不变 */

  _nop_();
  Dilcm_1; /*数据*/
  Rwlcm_1; /*读数据*/
  Elcm_1; /*读入到LCM*/
  _nop_();
  cbyte = Datalcm_i; /*从数据口读数据，真读 */
  Elcm_0;
 }

/****************************************/
/* 数据写输出   */
/****************************************/

void Wrdata(Uchar X)
 {
 Locatexy();  /*坐标定位，返回时保留分区状态不变 */

  Dilcm_1; /*数据输出*/
  Rwlcm_0; /*写输出  */
  _nop_();
#ifdef _kkk_430_program
  DATADIRO;
#endif
  Datalcm_o = X; /*数据输出到数据口 */
  Elcm_1; 
  _nop_();
  Elcm_0;
 }



/********************************/
/* 命令输出到左区控制口  */
/********************************/

void WrcmdL(Uchar X)
 {
  lcdbusyL();  /*确定分区，返回时保留分区状态不变*/
  Dilcm_0;   /*命令操作 */
  Rwlcm_0;   /*写输出   */
#ifdef _kkk_430_program
  DATADIRO;
#endif
  Datalcm_o = X;   /*数据输出到数据口 */
  Elcm_1;
  _nop_();
  Elcm_0; /*读入到LCM*/
 }

/********************************/
/* 命令输出到中区控制口  */
/********************************/

void WrcmdM(Uchar X)
 {
  lcdbusyM();  /*确定分区，返回时保留分区状态不变*/
  Dilcm_0;   /*命令操作 */
  Rwlcm_0;   /*写输出   */
#ifdef _kkk_430_program
  DATADIRO;
#endif
  Datalcm_o = X;   /*数据输出到数据口 */
  Elcm_1;
  _nop_();
  Elcm_0; /*读入到LCM*/
 }

/********************************/
/* 命令输出到右区控制口  */
/********************************/

void WrcmdR(Uchar X)
 {
  lcdbusyR(); /*确定分区，返回时保留分区状态不变 */
  Dilcm_0;   /*命令操作 */
  Rwlcm_0;   /*写输出   */
#ifdef _kkk_430_program
  DATADIRO;
#endif
  Datalcm_o = X;   /*数据输出到数据口 */
  Elcm_1;
  _nop_();
  Elcm_0; /*读入到LCM*/
 }

/********************************************************/
/* 分区操作允许等待,返回时保留分区选择状态  */
/********************************************************/
void lcdbusyL(void)
 {
        CS1LCM_0;  /*CLR CS1  */
        CS2LCM_1;  /*SETB CS2  */
        CS3LCM_1;  /*SETB CS3  */
 wtcom();  /* waitting for enable */
 }

void lcdbusyM(void)
 {
        CS1LCM_1;  /*SETB CS1  */
        CS2LCM_0;  /*CLR CS2  */
        CS3LCM_1;  /*SETB CS3  */
 wtcom();  /* waitting for enable */
 }

void lcdbusyR(void)
 {
        CS1LCM_1;  /*SETB CS1  */
        CS2LCM_1;  /*SETB CS2  */
        CS3LCM_0;  /*CLR CS3  */
 wtcom();  /* waitting for enable */
 }

void wtcom(void)
{
#ifdef _kkk_430_program
  DATADIRI;
#endif
 Dilcm_0;  /*CLR DI  */
 Rwlcm_1;  /*SETB RW  */
 Elcm_1;
 _nop_();  
 while(Datalcm_i& Lcdbusy);
 Elcm_0;
}

/********************************************************/
/*根据设定的坐标数据，定位LCM上的下一个操作单元位置 */
/********************************************************/
void Locatexy(void)
 {
 unsigned char  x,y;
 switch (col&0xc0)  /*  col.and.0xC0 */
  {   /*条件分支执行  */
  case 0:  {lcdbusyL();break;} /*左区 */
  case 0x40: {lcdbusyM();break;} /*中区 */
  case 0x80: {lcdbusyR();break;} /*右区 */
  }
 x = col&0x3F|SETX;  /*  col.and.0x3f.or.setx */
 y = row&0x07|SETY;  /*  row.and.0x07.or.sety */
  wtcom();  /*  waitting for enable  */
  Dilcm_0;   /*CLR DI */
  Rwlcm_0;   /*CLR RW */
#ifdef _kkk_430_program
  DATADIRO;
#endif
  Datalcm_o = y;   /*MOV P0,Y */
  Elcm_1;
  _nop_();
  Elcm_0;
  wtcom();  /*  waitting for enable  */
  Dilcm_0;   /*CLR DI */
  Rwlcm_0;   /*CLR RW */
  Datalcm_o= x;   /*MOV P0,X */
  Elcm_1;
  _nop_();
  Elcm_0;
 }

/********************************/
/*液晶屏初始化   */
/********************************/

void Lcminit(void)
 {
  cbyte = DISPOFF; /*关闭显示屏 */
  WrcmdL(cbyte);
  WrcmdM(cbyte);
  WrcmdR(cbyte);
  cbyte = DISPON;  /*打开显示屏 */
  WrcmdL(cbyte);
  WrcmdM(cbyte);
  WrcmdR(cbyte);
  cbyte = DISPFIRST; /*定义显示起始行为零 */
  WrcmdL(cbyte);
  WrcmdM(cbyte);
  WrcmdR(cbyte);
  Lcmcls();
  col=0;  /*清屏  */
  row=0;
  Locatexy();
 }
/********************************/
/* 延时    */
/********************************/
void Delay(Uchar MS)
{
  Uchar us,usn;
  while(MS!=0)
   { usn = 4;
    while(usn!=0)
     {
      us=0xf0;
      while (us!=0){us--;};
      usn--;
     }
    MS--;
   }
}
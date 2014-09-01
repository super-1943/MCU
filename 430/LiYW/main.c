#include "msp430x14x.h"
#define Uchar unsigned char
#include "ziku.h"



/***********Һ����ʾ���ӿ����Ŷ���***************/



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
#define CS3LCM_0	P2OUT&=~0x20/*�������ֻ����ʵ�����ʱ�ӷ���*/
#define CS3LCM_1	P2OUT|=0x20
#define RSTLCM_0	P2OUT&=~0x40
#define RSTLCM_1	P2OUT|=0x40
#define DATADIRO	P1DIR=0xff
#define DATADIRI	P1DIR=0x00
#define Datalcm_o P1OUT //���ݿ�
#define Datalcm_i P1IN	//


/********************************/

/****************ȫ�ֱ�������*******************/
Uchar col,row,cbyte;  /*��x,��(ҳ)y,������� */
Uchar xy;    /*���߷����־��1ˮƽ */

/***********���ò�������Ͳ�������***************/
#define  DISPON  0x3f /*��ʾon  */
#define  DISPOFF 0x3e /*��ʾoff  */
#define  DISPFIRST 0xc0 /*��ʾ��ʼ�ж��� */
#define  SETX  0x40 /*X��λ�趨ָ�ҳ�� */
#define  SETY  0xb8 /*Y��λ�趨ָ��У� */
#define  Lcdbusy 0x80 /*LCMæ�ж�λ  */

/**************��ʾ�����߽�λ��*****************/
#define  MODL  0x00 /*����   */
#define  MODM  0x40 /*�����������ֽ� */
#define  MODR  0x80 /*�����������ֽ� */
#define LCMLIMIT 0xC0 /*��ʾ�����ұ߽� */

/*****************�����б�**********************/
void Lcminit(void);  /*Һ��ģ���ʼ�� */
void Delay(Uchar);  /*��ʱ�������ΪMs */
void lcdbusyL(void);  /*busy�жϡ��ȴ�(����) */
void lcdbusyM(void);  /*busy�жϡ��ȴ�(����) */
void lcdbusyR(void);  /*busy�жϡ��ȴ�(����) */
void Putedot(Uchar);  /*����ַ����  */
void Putcdot(Uchar);  /*ȫ��(����)��� */
void Wrdata(Uchar);  /*���������LCM  */
void Lcmcls( void );  /*LCMȫ��Ļ����(���0) */
void wtcom(void);  /*����busy�ȴ�  */
void Locatexy(void);  /*��궨λ  */
void WrcmdL(Uchar);  /*�����������  */
void WrcmdM(Uchar);  /*�����������  */
void WrcmdR(Uchar);  /*�����������  */
void Putstr(Uchar *puts,Uchar i); /*��Ӣ���ַ������ */
void Rddata(void);  /*  ��Һ��Ƭ�϶����� */
void point(void);  /*���   */


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
	Delay(40);  /*��ʱ��Լ40Ms,�ȴ�����׼���� */
	Lcminit();  /*Һ��ģ���ʼ��������ȫ��Ļ����*/
	col=0;
	row=2;
	Putstr(STR2,12); /*�ڶ����ַ������12�ֽ� */
    while(1)
    {
		
    	
    }
}



/****************************************/
/* һ���ִ������   */
/****************************************/
void Putstr(Uchar *puts,Uchar i)
 {
  Uchar j,X;
  for (j=0;j<i;j++)
  {
  X = puts[j];
   if (X&0x80)
    {
     Putcdot(X&0x7f); /*ֻ������7λ*/
    }
   else Putedot(X-0x20);  /*ascii����0x20��ʼ*/
  }
 }

/****************************************/
/*   ����ַ��������������  */
/****************************************/
void Putedot(Uchar Order)
{
	Uchar i,bakerx,bakery;/*������4���ֲ�����   */
	int x;/*ƫ�������ַ����ٵĿ��Զ���ΪUCHAR */
	bakerx = col;/*�ݴ�x,y���꣬�ѱ��°���ַ�ʹ�� */
	bakery = row;
	x=Order * 0x10;/*����ַ���ÿ���ַ�16�ֽ� */
/*�ϰ���ַ������8�� */
	for(i=0;i<8;i++)
	{
		cbyte = Ezk[x];    /*ȡ�����룬rom���� */
		Wrdata(cbyte);    /*д���һ�ֽ�  */
		x++;
		col++;
		if (col==LCMLIMIT)
		{
			col=0;
			row++;
			row++;
		}/*��һ�У������Խ�绻��*/
		if (row>7) row=0;  /*�����Խ�磬�������� */
	}/*�ϰ���ַ�������� */
	
	col = bakerx;     /*�ж���  */
	row = bakery+1;     /*ָ���°���ַ��� */
/*�°���ַ������8�� */
	for(i=0;i<8;i++)
	{
		cbyte = Ezk[x];    /*ȡ������  */
		Wrdata(cbyte);    /*д���һ�ֽ�  */
		x++;
		col++;
		if (col==LCMLIMIT)
		{
			col=0;
			row=row+2;
		}/*��һ�У������Խ�绻��*/
		if (row>7) row=1;  /*�����Խ�磬�������� */
	}     /*�°���ַ�������� */
	row=bakery;
}/*�����ַ�������� */


/****************************************/
/*  ȫ���ַ��������������  */
/****************************************/
void Putcdot(Uchar Order)
{
	Uchar i,bakerx,bakery;/*������3���ֲ�����  */
	int x;/*ƫ�������ַ����ٵĿ��Զ���ΪUCHAR */
	bakerx = col;/*�ݴ�x,y���꣬�ѱ��°���ַ�ʹ�� */
	bakery = row;
	x=Order * 0x20;/*ÿ���ַ�32�ֽ� */
/*�ϰ���ַ������16�� */
	for(i=0;i<16;i++)
	{
		Wrdata(Hzk[x]);    /*д���һ�ֽ�  */
		x++;
		col++;
		if (col==LCMLIMIT){ col=0;row++;row++;} /*��һ�У������Խ�绻��*/
		if (row>6) row=0;  /*�����Խ�磬�������� */
	}     /*�ϰ���ַ�������� */
  
/*�°���ַ������16�� */
	col = bakerx;
	row = bakery+1;
	for(i=0;i<16;i++)    /*�°벿��*/
	{
		Wrdata(Hzk[x]);
		x++;
		col++;
		if (col==LCMLIMIT)
		{
			col=0;
			row++;
			row++;
		} /*��һ�У������Խ�绻��*/
		if (row>7) row=1;  /*�����Խ�磬�������� */
	}     /*�°���ַ�������� */
	row = bakery;
}      /*�����ַ�������� */

/****************************************/
/* ������ȫ��Ļ����  */
/****************************************/
void Lcmcls( void )
 {
 for(row=0;row<8;row++)
     for(col=0;col<LCMLIMIT;col++) Wrdata(0);
 }

/****************************************/
/*  ��Һ��Ƭ�϶����ݣ�������ȫ�ֱ����� */
/****************************************/
#define _nop_() _NOP()
#define _kkk_430_program
void Rddata(void)
 {
 Locatexy();  /*���궨λ������ʱ��������״̬���� */
  Datalcm_o=0xFF;
#ifdef _kkk_430_program
  DATADIRI;
#endif
  Dilcm_1; /*����*/
  Rwlcm_1; /*������*/
  Elcm_1; /*���뵽LCM*/
  _nop_();
  cbyte = Datalcm_i; /*���һ�� */
  Elcm_0;
 Locatexy();  /*���궨λ������ʱ��������״̬���� */

  _nop_();
  Dilcm_1; /*����*/
  Rwlcm_1; /*������*/
  Elcm_1; /*���뵽LCM*/
  _nop_();
  cbyte = Datalcm_i; /*�����ݿڶ����ݣ���� */
  Elcm_0;
 }

/****************************************/
/* ����д���   */
/****************************************/

void Wrdata(Uchar X)
 {
 Locatexy();  /*���궨λ������ʱ��������״̬���� */

  Dilcm_1; /*�������*/
  Rwlcm_0; /*д���  */
  _nop_();
#ifdef _kkk_430_program
  DATADIRO;
#endif
  Datalcm_o = X; /*������������ݿ� */
  Elcm_1; 
  _nop_();
  Elcm_0;
 }



/********************************/
/* ����������������ƿ�  */
/********************************/

void WrcmdL(Uchar X)
 {
  lcdbusyL();  /*ȷ������������ʱ��������״̬����*/
  Dilcm_0;   /*������� */
  Rwlcm_0;   /*д���   */
#ifdef _kkk_430_program
  DATADIRO;
#endif
  Datalcm_o = X;   /*������������ݿ� */
  Elcm_1;
  _nop_();
  Elcm_0; /*���뵽LCM*/
 }

/********************************/
/* ����������������ƿ�  */
/********************************/

void WrcmdM(Uchar X)
 {
  lcdbusyM();  /*ȷ������������ʱ��������״̬����*/
  Dilcm_0;   /*������� */
  Rwlcm_0;   /*д���   */
#ifdef _kkk_430_program
  DATADIRO;
#endif
  Datalcm_o = X;   /*������������ݿ� */
  Elcm_1;
  _nop_();
  Elcm_0; /*���뵽LCM*/
 }

/********************************/
/* ����������������ƿ�  */
/********************************/

void WrcmdR(Uchar X)
 {
  lcdbusyR(); /*ȷ������������ʱ��������״̬���� */
  Dilcm_0;   /*������� */
  Rwlcm_0;   /*д���   */
#ifdef _kkk_430_program
  DATADIRO;
#endif
  Datalcm_o = X;   /*������������ݿ� */
  Elcm_1;
  _nop_();
  Elcm_0; /*���뵽LCM*/
 }

/********************************************************/
/* ������������ȴ�,����ʱ��������ѡ��״̬  */
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
/*�����趨���������ݣ���λLCM�ϵ���һ��������Ԫλ�� */
/********************************************************/
void Locatexy(void)
 {
 unsigned char  x,y;
 switch (col&0xc0)  /*  col.and.0xC0 */
  {   /*������ִ֧��  */
  case 0:  {lcdbusyL();break;} /*���� */
  case 0x40: {lcdbusyM();break;} /*���� */
  case 0x80: {lcdbusyR();break;} /*���� */
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
/*Һ������ʼ��   */
/********************************/

void Lcminit(void)
 {
  cbyte = DISPOFF; /*�ر���ʾ�� */
  WrcmdL(cbyte);
  WrcmdM(cbyte);
  WrcmdR(cbyte);
  cbyte = DISPON;  /*����ʾ�� */
  WrcmdL(cbyte);
  WrcmdM(cbyte);
  WrcmdR(cbyte);
  cbyte = DISPFIRST; /*������ʾ��ʼ��Ϊ�� */
  WrcmdL(cbyte);
  WrcmdM(cbyte);
  WrcmdR(cbyte);
  Lcmcls();
  col=0;  /*����  */
  row=0;
  Locatexy();
 }
/********************************/
/* ��ʱ    */
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
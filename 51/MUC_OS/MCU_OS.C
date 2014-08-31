 /*********************************************************************************
 移植在MCU8051 LARGE MODE 下的UCOS实时操作系统，可以建立多个任务，完全可以应运于
 产品开发中，每个任务均拥有自己的堆栈
 DEVELOP BY LUNHUI ZHANG
 DATE 04/24/2007
 QQ 33380451
 http://mcu_os.21ic.org/
 NOTE:已通过10多分钟的软件模拟调试测试，系统运行正常
**********************************************************************************/
#include "includes.h"
/*********************************************************************************/
#define N_TASKS              3
OS_STK xdata TaskStack1[CPU_MAX_STK_SIZE];
OS_STK xdata TaskStack2[CPU_MAX_STK_SIZE];
OS_STK xdata TaskStack3[CPU_MAX_STK_SIZE];

OS_EVENT xdata    *AckMbox;                    //Message mailboxes for Tasks #2 and #3
OS_EVENT xdata    *TxMbox;
/*********************************************************************************/
typedef unsigned char uchar;
typedef unsigned  int  uint;
typedef unsigned long ulong;
//uchar x,y,z;
/*********************************************************************************/
void SerialInitial(void)
     {
       PCON=0x80;         //备频
	   T2CON=0x30;        //设置T2为波特率发生器
	   RCAP2H=0x0FF; 	  //57600 @ 24MHz: 24000000/(32*(65536-(RCAP2H,RCAP2L)))
	   RCAP2L=0x0FB;
	   TH2=0xFf;          //32.768M的晶振，250000的波特率。32.768M=fch;24M=fdh;16M=feh
	   TL2=0xFB;         
	   RI=0;			
	   TI=0;
	   TR2=1;
       SCON = 0x52;      
       PCON = 0x80;
       TCON = 0x40;     
                                                                 }
/*********************************************************************************/
void InterruptInitial(void)
     {
      TMOD |= 0x11;
      TH0 = 0x70;
      TL0 = 0x00;          //T0用于做时针节拍中断
      /* TR0 is set in OSStart() */
      ET0 = 1;
      /*T1TIME*/
      TH1=0x00;
      TL1=0x00;           //用于模拟软中断，实现任务切换
      ET1=1;
      PT0=1;              //提升优先级至最高
                                                 }
/*********************************************************************************/
void task1(void *ppdata)reentrant
     {
      uchar txmsg;
      INT8U err;
      ppdata=ppdata;
      
      txmsg='A';
      for(;;)
         {
          //OSTimeDly(1);
          //OSTimeDlyHMSM(0,0,1,0);
          OSMboxPost(TxMbox, (void xdata*)&txmsg);      /* Send message to Task #5                            */
          OSMboxPend(AckMbox, 0, &err);        
          //printf("%c",x);
          printf("Hello,welcome!\n");
                                        }
                                          }
/*********************************************************************************/
void task2(void *ppdata)reentrant
     {
      uchar *rxmsg; 
      char y;
      INT8U err;
      ppdata=ppdata;
      //y='B';
      for(;;)
         {
          rxmsg = (char *)OSMboxPend(TxMbox, 0, &err); 
          y=*rxmsg;
          printf("%c",y);
          printf("This is my first RTOS,very good!\n");
          OSMboxPost(AckMbox, (void xdata*)1);
          OSTimeDlyHMSM(0,0,2,0);     

                                                        }
                                                          }
/*********************************************************************************/
void task3(void *ppdata)reentrant
     {
      uchar z;
      ppdata=ppdata;
      z='C';
      for(;;)
         {
          //OSTimeDly(5);
          OSTimeDlyHMSM(0,0,1,0);
          printf("%c",z);
          printf("If you feel very good,welcome to http:\/\/mcu_os.21ic.org.\n");
                                                                 }
                                                                    }
/*********************************************************************************/
void main(void)
    {
      SerialInitial();
      InterruptInitial();
      OSInit();
      AckMbox = OSMboxCreate((void *)0);                     /* Create 2 message mailboxes               */
      TxMbox  = OSMboxCreate((void *)0);
      OSTaskCreate(task1,(void xdata*)0,&TaskStack1[0],3);
      OSTaskCreate(task2,(void xdata*)0,&TaskStack2[0],4);
      OSTaskCreate(task3,(void xdata*)0,&TaskStack3[0],5);
      OSStart();
                                        }
/*********************************************************************************/

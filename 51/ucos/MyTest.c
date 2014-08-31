//******************************************************************
//* mytest fuction
#include <includes.h>

//******************************************************************
//* mytest system timer initial
#define   TIME_10mS     (OS_TICKS_PER_SEC /100)
#define   TIME_50mS     (OS_TICKS_PER_SEC /20 )
#define   TIME_100mS    (OS_TICKS_PER_SEC /10 )
#define   TIME_200mS    (OS_TICKS_PER_SEC /5  )
#define   TIME_500mS    (OS_TICKS_PER_SEC /2  )
#define   TIME_1S       (OS_TICKS_PER_SEC)
#define   TIME_2S       (OS_TICKS_PER_SEC * 2)
#define   TIME_3S       (OS_TICKS_PER_SEC * 3)
#define   TIME_4S       (OS_TICKS_PER_SEC * 4)
#define   TIME_5S       (OS_TICKS_PER_SEC * 5)

//******************************************************************
//* mytest system crystalloid
#define   XA_CRYSTAL_FREQ   (INT32U)(22118400L)

//******************************************************************
//* SCR crystalloid
#define	  CFG_SCR_4	SCR&0x03 
#define	  CFG_SCR_16	SCR&0x07
#define	  CFG_SCR_64	SCR&0x0B

#define	  OS_CFG_SCR	CFG_SCR_4

//******************************************************************
//* mytest system 
#define   TASK_STK_SIZE   128 //* 128 word
#define   NUMBER_TASKS    20   

//******************************************************************
//* mytest task stack define
OS_STK  xdata   AnPrintfStk[TASK_STK_SIZE];
OS_STK  xdata   BnPrintfStk[TASK_STK_SIZE];

//******************************************************************
//* OS_EVENT
OS_EVENT xdata * AnPrintfWait;
OS_EVENT xdata * BnPrintfWait;



//******************************************************************

INT8U  xdata   OSCtxSwCtrMax; 
INT8U  xdata   AnPrintfData[]   = {0xC4,0xE3,0xBA,0xC3,0xA3,0xAC,0xCE,0xD2,
                           0xCA,0xC7,0xC8,0xCE,0xCE,0xF1,0x41,0x6E,
                           0x5C,0x6E};
INT8U xdata BnPrintfData[]   = {0xC4,0xE3,0xBA,0xC3,0xA3,0xAC,0xCE,0xD2,
                           0xCA,0xC7,0xC8,0xCE,0xCE,0xF1,0x42,0x6E,
                           0x5C,0x6E};

//-------------------------------------------------------------------
void  TimeTickInitial(void);
void  AnPrintf(void *dataptr);   //* Startup Task          
void  BnPrintf(void *dataptr);   //* 8 Identical Tasks 
void  Serial_initialize(void);
//static void XAInit (void);
//static void TimerInit (INT8U tmr, INT16U freq, INT8U prio);
//static void SeryComm0Init (INT16U baud);
//******************************************************************

//******************************************************************
void main (void)
{
    //XAInit(); //* XA Configuration                           
    OSInit(); //* Initialize uC/OS-II, The Real-Time Kernel 
    
    BnPrintfWait = OSSemCreate(0);
    
    
    
    OSTaskCreate( AnPrintf, 
                  (void *)0, 
                  (void *)&AnPrintfStk[TASK_STK_SIZE-1], 
                  0x01);

    OSTaskCreate( BnPrintf, 
                  (void *)0, 
                  (void *)&BnPrintfStk[TASK_STK_SIZE-1], 
                  0x02);
 
    TimeTickConfig();
    Serial_initialize();
    OSStart();           
} 

void  AnPrintf(void *dataptr)
{   
    
    INT8U i;
    INT8U err;
    dataptr = dataptr;
    while(1)
    {

        for(i=0;i<18;)
        {   
            if(TI)
            {
            	TI= 0;
            	SBUF = AnPrintfData[i];
	        i++;    
	    }
          
        }
        OSSemPend(BnPrintfWait,10,&err);
	
    }
    
}

//******************************************************************
void  BnPrintf(void *dataptr)
{
    
    INT8U i;
    dataptr = dataptr;
    EA =1;
    while(1)
    {

    	TI = 1;
        for(i=0;i<18;)
        {   if(TI)
            {
            	TI = 0;
            	SBUF = BnPrintfData[i];
            	i++;
	     }
        
        }
        
	OSSemPost(BnPrintfWait);
	
    }
   
}
void SeryInt(void)
{
	
}
void Serial_initialize()
{
    SCON  = 0x50;  //* SCON: mode 1, 8-bit UART, enable rcvr */
    TMOD |= 0x20;  //* TMOD: timer 1, mode 2, 8-bit reload */
    TH1   = 0xfd;  //* TH1:  reload value for 1200 baud @ 16MHz */
    TR1   = 1;     //* TR1:  timer 1 run */
    TI    = 1;     //* TI:   set TI to send first char of UART */
}
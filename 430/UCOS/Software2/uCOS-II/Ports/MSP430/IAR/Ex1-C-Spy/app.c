/*
*********************************************************************************************************
*                                                uC/OS-II
*                                          The Real-Time Kernel
*
*                              (c) Copyright 2002, Micrium, Inc., Weston, FL
*                                           All Rights Reserved
*
*                                                TI MSP430
*********************************************************************************************************
*/

#include "includes.h"

/*
*********************************************************************************************************
*                                               CONSTANTS
*********************************************************************************************************
*/

#define  TASK_STK_SIZE                  64       /* Size of each task's stacks (# of OS_STK entries)   */

/*
*********************************************************************************************************
*                                               VARIABLES
*********************************************************************************************************
*/

OS_STK   TaskStartStk[TASK_STK_SIZE];
OS_STK   Task1Stk[TASK_STK_SIZE];

/*
*********************************************************************************************************
*                                           FUNCTION PROTOTYPES
*********************************************************************************************************
*/

void   TaskStart(void *data);                    /* Function prototypes of Startup task                */
void   Task1(void *data);
/*$PAGE*/
/*
*********************************************************************************************************
*                                                MAIN
*********************************************************************************************************
*/

void  main (void)
{
    WDTCTL = WDTPW + WDTHOLD;

    OSInit();                                              /* Initialize uC/OS-II                      */
    OSTaskCreate(TaskStart, (void *)0, &TaskStartStk[TASK_STK_SIZE - 1], 0);
    OSStart();                                             /* Start multitasking                       */
}

/*
*********************************************************************************************************
*                                            STARTUP TASK
*********************************************************************************************************
*/

void  TaskStart (void *pdata)
{
    pdata  = pdata;                                        /* Prevent compiler warning                 */

    WDTCTL = WDT_MDLY_32;                                  /* Set time tick 32 mS                      */
    IE1   |= 0x01;                                         /* Enable Watchdog timer interrupts         */
    P2DIR=0xff;
    P2OUT=0x00;
    /* Application specific initialization */

    while (1) {
        /* Task specific code */
        OSTaskCreate(Task1, (void *)0, &Task1Stk[TASK_STK_SIZE - 1], 3);
        OSTimeDly(1);   
    }
}
void Task1(void *pdata)
{
  while(1)
  {
     P2OUT^=0xff;
     OSTimeDly(4); 
  }
}
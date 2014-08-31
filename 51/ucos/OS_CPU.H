/*
*********************************************************************************************************
*                                               uC/OS-II
*                                        The Real-Time Kernel
*
*                         (c) Copyright 1992-2000, Jean J. Labrosse, Weston, FL
*                                          All Rights Reserved
*
*                                       Philips XA Specific code
*                                          LARGE MEMORY MODEL
*
* File : OS_CPU.H
* By   : Jean J. Labrosse
*********************************************************************************************************
*/

#ifdef  OS_CPU_GLOBALS
#define OS_CPU_EXT
#else
#define OS_CPU_EXT  extern
#endif

/*
*********************************************************************************************************
*                                              DATA TYPES
*                                         (Compiler Specific)
*********************************************************************************************************
*/

typedef unsigned char  BOOLEAN;
typedef unsigned char  INT8U;                    /* Unsigned  8 bit quantity                           */
typedef signed   char  INT8S;                    /* Signed    8 bit quantity                           */
typedef unsigned int   INT16U;                   /* Unsigned 16 bit quantity                           */
typedef signed   int   INT16S;                   /* Signed   16 bit quantity                           */
typedef unsigned long  INT32U;                   /* Unsigned 32 bit quantity                           */
typedef signed   long  INT32S;                   /* Signed   32 bit quantity                           */
typedef float          FP32;                     /* Single precision floating point                    */
typedef double         FP64;                     /* Double precision floating point                    */

typedef unsigned char   OS_STK;                   /* Each stack entry is 16-bit wide                    */

#define BYTE           INT8S                     /* Define data types for backward compatibility ...   */
#define UBYTE          INT8U                     /* ... to uC/OS V1.xx.  Not actually needed for ...   */
#define WORD           INT16S                    /* ... uC/OS-II.                                      */
#define UWORD          INT16U
#define LONG           INT32S
#define ULONG          INT32U

/* 
*********************************************************************************************************
*                                        CRITICAL SECTION CONTROL
*
* Method #1:  Disable/Enable interrupts using simple instructions.  After critical section, interrupts
*             will be enabled even if they were disabled before entering the critical section.  
*
* Method #2:  Disable/Enable interrupts by preserving the state of interrupts.  In other words, if 
*             interrupts were disabled before entering the critical section, they will be disabled when
*             leaving the critical section.  
*             The XA port doesn't currently support this method.
*********************************************************************************************************
*/
#define  OS_CRITICAL_METHOD    1


#if      OS_CRITICAL_METHOD == 1
#define  OS_ENTER_CRITICAL()  EA = 0             /* Disable interrupts                                 */
#define  OS_EXIT_CRITICAL()   EA = 1             /* Enable  interrupts                                 */
#endif

/*
*********************************************************************************************************
*                                           MISCELLANEOUS
*********************************************************************************************************
*/

#define  OS_STK_GROWTH        1           /* Stack grows from HIGH to LOW memory on XA            */

#define  OS_TASK_SW()        _intxa(31)        /* Trap #15, (Interrupt 31) invokes OSCtxSw()           */


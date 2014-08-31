/*
*********************************************************************************************************
*                                               uC/OS-II
*                                        The Real-Time Kernel
*
*                         (c) Copyright 1992-2002, Jean J. Labrosse, Weston, FL
*                                          All Rights Reserved
*
*                                       80x86/80x88 Specific code
*                                          LARGE MEMORY MODEL
*
*                                          Borland C/C++ V4.51
*
* File         : OS_CPU.H
* By           : Jean J. Labrosse
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
/*instead boolean*/
typedef unsigned char  BOOLEAN;   
typedef unsigned char  INT8U;                    /* Unsigned  8 bit quantity                           */
typedef signed   char  INT8S;                    /* Signed    8 bit quantity                           */
typedef unsigned int   INT16U;                   /* Unsigned 16 bit quantity                           */
typedef signed   int   INT16S;                   /* Signed   16 bit quantity                           */
typedef unsigned long  INT32U;                   /* Unsigned 32 bit quantity                           */
typedef signed   long  INT32S;                   /* Signed   32 bit quantity                           */
/*stack entry is 8bit wide*/
typedef unsigned char  OS_STK;                   /* Each stack entry is 8-bit wide                    */
/*PSW of mcu8051 is 8bit*/
typedef unsigned char  OS_CPU_SR;                /* Define size of CPU status register (PSW = 16 bits) */

#define BYTE           INT8S                     /* Define data types for backward compatibility ...   */
#define UBYTE          INT8U                     /* ... to uC/OS V1.xx.  Not actually needed for ...   */
#define WORD           INT16S                    /* ... uC/OS-II.                                      */
#define UWORD          INT16U
#define LONG           INT32S
#define ULONG          INT32U

/* 
*********************************************************************************************************
*                                 mcu8051 (Real-Mode, Large Model)
*
* Method #1:  Disable/Enable interrupts using simple instructions.  After critical section, interrupts
*             will be enabled even if they were disabled before entering the critical section.
*
* Method #2:  Disable/Enable interrupts by preserving the state of interrupts.  In other words, if 
*             interrupts were disabled before entering the critical section, they will be disabled when
*             leaving the critical section.
*
* Method #3:  Disable/Enable interrupts by preserving the state of interrupts.  Generally speaking you
*             would store the state of the interrupt disable flag in the local variable 'cpu_sr' and then
*             disable interrupts.  'cpu_sr' is allocated in all of uC/OS-II's functions that need to 
*             disable interrupts.  You would restore the interrupt disable state by copying back 'cpu_sr'
*             into the CPU's status register.
*********************************************************************************************************
*/
#define  OS_CRITICAL_METHOD    1

#if      OS_CRITICAL_METHOD == 1
/*8051 disable or enable interrupts is controled by EA*/
#define  OS_ENTER_CRITICAL()  EA=0;                       /* Disable interrupts                        */
#define  OS_EXIT_CRITICAL()   EA=1;                       /* Enable  interrupts                        */
#endif

#if      OS_CRITICAL_METHOD == 2
#define  OS_ENTER_CRITICAL()  asm {PUSHF; CLI}            /* Disable interrupts                        */
#define  OS_EXIT_CRITICAL()   asm  POPF                   /* Enable  interrupts                        */
#endif

#if      OS_CRITICAL_METHOD == 3
#define  OS_ENTER_CRITICAL()  (cpu_sr = OSCPUSaveSR())    /* Disable interrupts                        */
#define  OS_EXIT_CRITICAL()   (OSCPURestoreSR(cpu_sr))    /* Enable  interrupts                        */
#endif

/*
*********************************************************************************************************
*                                8051( Big Model) Miscellaneous
*********************************************************************************************************
*/
/*stack grows from low to high memory on 8051 core*/
#define  OS_STK_GROWTH        0                       /* Stack grows from HIGH to LOW memory on 80x86  */
/*SET BIT TF1,then t1 timer will interrupt*/
#define  OS_TASK_SW()         OSCtxSw()

/*
*********************************************************************************************************
*                                            GLOBAL VARIABLES
*********************************************************************************************************
*/
#define CPU_MAX_STK_SIZE	0xF8
OS_CPU_EXT  INT8U  OSTickDOSCtr;       /* Counter used to invoke DOS's tick handler every 'n' ticks    */
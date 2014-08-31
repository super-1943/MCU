#define  OS_CPU_GLOBALS

//=======================================================================
// header file
#include "includes.h"
//=======================================================================
// system SP Start address
INT8U data   STKStart;
INT8U data   TickTimeInit;
//=======================================================================
OS_STK *OSTaskStkInit
	(	
	void   (*task)(void *pd)reentrant, // point to function
	void   *pdato, 
	OS_STK *ptos, 
	INT16U opt
	)reentrant
{
    OS_STK *stk;        
    OS_STK *temp_sp;

    opt = opt;
    stk  = ptos;
    //*-----------------------------------------------------------------
    *stk     = ((INT16U)pdato & 0xFF);	//* TaskSTK[STK_SIZE-1]
    *--stk   = ((INT16U)pdato >> 8 );	//* TaskSTK[STK_SIZE-2]
    *--stk   = 0xff;			//* TaskSTK[STK_SIZE-3]
    temp_sp  = --stk;                   
    //*------------------------------------------------------------------
    *stk     = ((INT16U)temp_sp >> 8 );	   //* User_SP high
    *--stk   = ((INT16U)temp_sp & 0xFF);   //* User_SP low
    *--stk   = 0x07;			   //* R7 
    *--stk   = 0x06;			   //* R6
    *--stk   = 0x05;			   //* R5
    *--stk   = 0x04;			   //* R4
    *--stk   = 0x03;			   //* R3
    *--stk   = 0x02;			   //* R2
    *--stk   = 0x01;			   //* R1
    *--stk   = 0x00;			   //* R0
    *--stk   = 0x00;                       //* DPL
    *--stk   = 0x00;                       //* DPH
    *--stk   = 0x0b;			   //* B
    *--stk   = 0x0a;			   //* ACC
    *--stk   = 0x00;			   //* PSW
    *--stk   = ((INT16U)task >> 8);	   //* PCH
    *--stk   = ((INT16U)task & 0x00FF);	   //* PCL
    *--stk   = 0x12;			   //* SIZE_SP
    --stk;                                 //* NULL			
    return stk;
}
//=======================================================================
void TimeTickConfig(void)
{
    TickTimeInit = OS_TICK_TIME;
    TMOD &= 0xf0;
    TMOD |= 0x01;
    TH0 = 0x3c;
    TH0 = 0xb0;
    TR0 = 1;
    ET0 = 1;
}
//-----------------------------------------------------------------------
void TickTime(void)
{
   TickTimeInit = OS_TICK_TIME; 
} 
//-----------------------------------------------------------------------
//=======================================================================
#if USE_Pre_ExternInt0
void ExternInt0(void)
{

}
#endif
//-----------------------------------------------------------------------
#if USE_Pre_ExternInt1
void ExternInt1(void)
{

}
#endif
//-----------------------------------------------------------------------
#if USE_Pre_TimeInt1
void Time1Int(void)
{

}
#endif
//-----------------------------------------------------------------------
#if USE_Pre_SeryInt
void SeryInt(void)
{

}
#endif
//=======================================================================
void OSTCBSWHook(void)
{
     OSTCBCur  = OSTCBHighRdy;
     OSPrioCur = OSPrioHighRdy;
}
//-----------------------------------------------------------------------
void OSTickISRHook(void)
{
	
}
//-----------------------------------------------------------------------
void OSTaskSwHook (void)
{
;
}
//-----------------------------------------------------------------------
void OSTimeTickHook (void)reentrant
{
}
//-----------------------------------------------------------------------
void OSTaskCreateHook (OS_TCB *ptcb)reentrant
{
    ptcb = ptcb; 
}

//=======================================================================
#if OS_CPU_HOOKS_EN
    
    //--------------------------------------------
    void OSInitHookBegin (void)
    {
    }

    //--------------------------------------------
    void OSInitHookEnd (void)
    {
    }
    
    //--------------------------------------------
    void OSTaskDelHook (OS_TCB *ptcb)
    {
        ptcb = ptcb;  
    }
    
    //--------------------------------------------
    void OSTaskStatHook (void)
    {
    }
    
    //--------------------------------------------
    void OSTCBInitHook (OS_TCB *ptcb)
    {
        ptcb = ptcb;
    }
    
    //--------------------------------------------
    void OSRunningTrue(void)
    {
      OSRunning=TRUE;
    }
#endif
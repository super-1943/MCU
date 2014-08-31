/***********************************************************************
                                   OS-II
                            The Real-Time Kernel
DEVELOP BY LUNHUI ZHANG
QQ 33380451
DATE 05/15/2007
HTTP://mcu_os.21ic.org
************************************************************************/
/*file name*/
 NAME	OS_CPU_A
/***********************************************************************/
;  STACK                        NOTE
;  REENTRANT_STACK              REENTRANT FUNCTION STACK CONTENTS             
;  ?C_XBP+1                     REENTRANT_STACK POINT LOW
;  ?C_XBP                       REENTRANT_STACK POINT HIGH
;  SYSTEM STACK                 SYSTEM  STACK CONTENT
;  LENG                         SYSYTEM STACK LONG
;  ?OSSTKSTART                      *        ;CONTENT NO IMPORTANT
/***********************************************************************/
/*sub program of asm*/
 ?PR?OSStartHighRdy?OS_CPU_A	        SEGMENT CODE
 ?PR?OSCtxSw?OS_CPU_A		        SEGMENT CODE
 ?PR?OSIntCtxSw?OS_CPU_A		SEGMENT	CODE
/***********************************************************************/
/*exern variable*/
 EXTRN XDATA	(OSTCBHighRdy)
 EXTRN XDATA	(OSTCBCur)
 EXTRN XDATA	(OSPrioCur)
 EXTRN XDATA	(OSPrioHighRdy)
 EXTRN XDATA	(OSRunning)
 EXTRN CODE	(_?OSTaskSwHook)
 EXTRN DATA     (?C_XBP)          /*FUNCTION REENTRANT STACK*/
/*others program can call these program*/
 PUBLIC	OSStartHighRdy
 PUBLIC	OSCtxSw
 PUBLIC	OSIntCtxSw
 XBPSTACKTOP EQU 07FFFH+1
/*The SEGMENT ?STACK will combined will stack defined in startup.asm*/
	?STACK SEGMENT IDATA
        RSEG ?STACK
OSStkBottom:
OSStkStart IDATA OSStkBottom-1         ;sysytem sp start address,store contents first sp add 1 
/*function*/
	RSEG ?PR?OSStartHighRdy?OS_CPU_A
OSStartHighRdy:
        LCALL _?OSTaskSwHook         ;lcall void ostaskswhook(*ppdata)
        MOV DPH,#HIGH(OSRunning)
        MOV DPL,#LOW(OSRunning)      ;get osrunning's dptr
        MOV A,#1
        MOVX @DPTR,A                 ;SET osrunning=1 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
        SETB TR0      ;TICK TIME
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;GET (OSTCKHIGHRDY->OSTCBSTKPTR) TO DPTR
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; 
;FIRST GET OSTCKHIGHRDY'S ADDRESS TO DPTR
RESTORE_STACK_CONTENT:
        MOV DPH,#HIGH(OSTCBHighRdy)
        MOV DPL,#LOW(OSTCBHighRdy)
        MOVX A,@DPTR
        MOV B,A
        INC DPTR
        MOVX A,@DPTR
        MOV DPH,B
        MOV DPL,A
;SECOND GET OSTCBSTKPTR'S ADDRESS TO DPTR
        MOVX A,@DPTR
        MOV B,A
        INC DPTR
        MOVX A,@DPTR
        MOV DPH,B
        MOV DPL,A 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;restore new task stack contents
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
        MOVX A,@DPTR         ;GET NEW TASK STACK'SIZE
        MOV R7,A
        MOV R0,#OSStkStart   ;sysytem stack start address,is decided by keil
RESTORE_STACK_CONTENTS:
        INC R0
        INC DPTR
        MOVX A,@DPTR
        MOV @R0,A
        DJNZ R7,RESTORE_STACK_CONTENTS
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;calculate sp address sp=osstkstart+size
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
        MOV SP,R0
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;RESTORE REENTRANT FUNCTION STACK CONTENTS
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
RESTORE_REENTRANT_STACK_SIZE:
        INC DPTR
        MOVX A,@DPTR
        MOV ?C_XBP,A
        INC DPTR
        MOVX A,@DPTR
        MOV ?C_XBP+1,A   ;RESTORE REENTRANT FUNCTION STACK POINT
        INC DPTR
        MOV R1,DPH
        MOV R0,DPL
        MOV R3,?C_XBP
        MOV R2,?C_XBP+1
RESTORE_REENTRANT_STACK:
        MOV A,R3
        CJNE A,#80H,NEXT_RESTACK
        MOV A,R2
        CJNE A,#00H,NEXT_RESTACK    ;REENTRANT FUNCTION STACK TOP
        LJMP EXIT_RESTORE
NEXT_RESTACK:
        MOV DPH,R1
        MOV DPL,R0
        MOVX A,@DPTR
        INC DPTR
        MOV R1,DPH
        MOV R0,DPL

        MOV DPH,R3
        MOV DPL,R2
        MOVX @DPTR,A
        INC DPTR
        MOV R3,DPH
        MOV R2,DPL
        LJMP RESTORE_REENTRANT_STACK
EXIT_RESTORE:        
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
        POP	07
	POP	06
	POP	05
	POP	04
	POP	03
	POP	02
	POP	01
	POP	00
	POP	PSW
	POP	DPL
	POP	DPH
	POP	B
	POP	ACC
        SETB    EA
        RETI
;***************************************************
        CSEG AT 001BH
        ljmp OSCtxSw
        RSEG ?PR?OSCtxSw?OS_CPU_A
OSCtxSw:
        USING 00H
        CLR TF1
        CLR EA
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; push registers
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	PUSH	ACC
	PUSH	B
	PUSH	DPH
	PUSH	DPL
	PUSH	PSW
	PUSH	00
	PUSH	01
	PUSH	02
	PUSH	03
	PUSH	04
	PUSH	05
	PUSH	06
	PUSH	07 
OSIntCtxSw_enter:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;GET OSTCBCUR->OSTCBSTKPTR TO DPTR
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
        MOV DPH,#HIGH(OSTCBCur)
        MOV DPL,#LOW(OSTCBCur)
        MOVX A,@DPTR
        MOV B,A
        INC DPTR
        MOVX A,@DPTR
        MOV DPH,B
        MOV DPL,A
        MOVX A,@DPTR
        MOV B,A
        INC DPTR
        MOVX A,@DPTR
        MOV DPH,B
        MOV DPL,A
;CALCULATE STACK SIZE
        MOV A,SP
        CLR C
        SUBB A,#OSStkStart
        MOV R7,A
;STORE STACK SIZE
        MOVX @DPTR,A
;STORE SYSTEM STACK CONTENTS TO USER STACK
        MOV R0,#OSStkStart
STORE_STACK_CURRENT:
        INC DPTR
        INC R0
        MOV A,@R0 
        MOVX @DPTR,A
        DJNZ R7,STORE_STACK_CURRENT
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;STORE REENTRANT FUNCTION STACK CONTENTS
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
STORE_REENTRANT_STACK_SIZE:
        INC DPTR
        MOV A,?C_XBP
        MOVX @DPTR,A
        INC DPTR
        MOV A,?C_XBP+1
        MOVX @DPTR,A
        INC DPTR
        MOV R1,DPH
        MOV R0,DPL
        MOV R3,?C_XBP
        MOV R2,?C_XBP+1
STORE_REENTRANT_STACK:
        MOV A,R3
        CJNE A,#80H,NEXT_STACK
        MOV A,R2
        CJNE A,#00H,NEXT_STACK
        LJMP EXIT_STORE
NEXT_STACK:
        MOV DPH,R3
        MOV DPL,R2
        MOVX A,@DPTR
        INC DPTR
        MOV R3,DPH
        MOV R2,DPL

        MOV DPH,R1
        MOV DPL,R0
        MOVX @DPTR,A
        INC DPTR
        MOV R1,DPH
        MOV R0,DPL
        LJMP STORE_REENTRANT_STACK
EXIT_STORE:        
;**************************************       
        LCALL _?OSTaskSwHook 
;OSTCBCur=OSTCBHighRdy
        MOV DPH,#HIGH(OSTCBHighRdy)
        MOV DPL,#LOW(OSTCBHighRdy)
        MOVX A,@DPTR
        MOV B,A
        INC DPTR
        MOVX A,@DPTR
        MOV R0,A
        
        MOV DPH,#HIGH(OSTCBCur)
        MOV DPL,#LOW(OSTCBCur)
        MOV A,B
        MOVX @DPTR,A
        MOV A,R0
        INC DPTR
        MOVX @DPTR,A
; OSPrioCur = OSPrioHighRdy	
	MOV	DPH,#HIGH (OSPrioHighRdy)
	MOV	DPL,#LOW  (OSPrioHighRdy)
	MOVX	A,@DPTR

	MOV	DPH,#HIGH (OSPrioCur)
	MOV	DPL,#LOW  (OSPrioCur)
	MOVX	@DPTR,A 
        LJMP    RESTORE_STACK_CONTENT
;***************************************************
        RSEG ?PR?OSIntCtxSw?OS_CPU_A
OSIntCtxSw:
        MOV A,SP
        ADD A,#13  ;此最好SP加4就可
        MOV SP,A   ;从空闲任务进入时,堆栈少于15,应进行调整
        LJMP    OSIntCtxSw_enter
        END
;***************************************************                             

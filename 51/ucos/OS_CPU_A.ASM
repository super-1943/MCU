;//----------------------------------------------------------------
        $NOMOD51
        NAME	OS_CPU_A
;//----------------------------------------------------------------
P0	DATA	080H
P1	DATA	090H
P2	DATA	0A0H
P3	DATA	0B0H
T0	BIT	0B0H.4
AC	BIT	0D0H.6
T1	BIT	0B0H.5
T2	BIT	090H.0
EA	BIT	0A8H.7
IE	DATA	0A8H
EXF2	BIT	0C8H.6
RD	BIT	0B0H.7
ES	BIT	0A8H.4
IP	DATA	0B8H
RI	BIT	098H.0
INT0	BIT	0B0H.2
CY	BIT	0D0H.7
TI	BIT	098H.1
INT1	BIT	0B0H.3
RCAP2H	DATA	0CBH
PS	BIT	0B8H.4
SP	DATA	081H
T2EX	BIT	090H.1
OV	BIT	0D0H.2
RCAP2L	DATA	0CAH
C_T2	BIT	0C8H.1
WR	BIT	0B0H.6
RCLK	BIT	0C8H.5
TCLK	BIT	0C8H.4
SBUF	DATA	099H
PCON	DATA	087H
SCON	DATA	098H
TMOD	DATA	089H
TCON	DATA	088H
IE0	BIT	088H.1
IE1	BIT	088H.3
B	DATA	0F0H
CP_RL2	BIT	0C8H.0
ACC	DATA	0E0H
ET0	BIT	0A8H.1
ET1	BIT	0A8H.3
TF0	BIT	088H.5
ET2	BIT	0A8H.5
TF1	BIT	088H.7
TF2	BIT	0C8H.7
RB8	BIT	098H.2
TH0	DATA	08CH
EX0	BIT	0A8H.0
IT0	BIT	088H.0
TH1	DATA	08DH
TB8	BIT	098H.3
EX1	BIT	0A8H.2
IT1	BIT	088H.2
TH2	DATA	0CDH
P	BIT	0D0H.0
SM0	BIT	098H.7
TL0	DATA	08AH
SM1	BIT	098H.6
TL1	DATA	08BH
SM2	BIT	098H.5
TL2	DATA	0CCH
PT0	BIT	0B8H.1
PT1	BIT	0B8H.3
RS0	BIT	0D0H.3
PT2	BIT	0B8H.5
TR0	BIT	088H.4
RS1	BIT	0D0H.4
TR1	BIT	088H.6
TR2	BIT	0C8H.2
PX0	BIT	0B8H.0
PX1	BIT	0B8H.2
DPH	DATA	083H
DPL	DATA	082H
EXEN2	BIT	0C8H.3
REN	BIT	098H.4
T2CON	DATA	0C8H
RXD	BIT	0B0H.0
TXD	BIT	0B0H.1
F0	BIT	0D0H.5
PSW	DATA	0D0H

;//----------------------------------------------------------------
?PR?OSStartHighRdy?OS_CPU_A        SEGMENT CODE 
?PR?OSCtxSw?OS_CPU_A               SEGMENT CODE 
?PR?OSIntCtxSw?OS_CPU_A            SEGMENT CODE 
?PR?OSTickISR?OS_CPU_A             SEGMENT CODE 
;//----------------------------------------------------------------
?PR?_EXTERN_0_ISR_?OS_CPU_A        SEGMENT CODE 
?PR?_EXTERN_1_ISR_?OS_CPU_A        SEGMENT CODE 
?PR?_TIME_1_ISR_?OS_CPU_A          SEGMENT CODE 
?PR?_SERY_ISR_?OS_CPU_A            SEGMENT CODE 
;//----------------------------------------------------------------

;//----------------------------------------------------------------        
        ;//--------------------------------------------------------
	EXTRN	DATA (STKStart)
	EXTRN	DATA (OSIntNesting)
	EXTRN	DATA (User_SP)
	EXTRN	DATA (TickTimeInit)
	;//--------------------------------------------------------
	EXTRN	IDATA (OSTCBCur)
	EXTRN	IDATA (OSTCBHighRdy)
	EXTRN	IDATA (OSRunning)
	EXTRN	IDATA (OSPrioCur)
	EXTRN	IDATA (OSPrioHighRdy)
	;//--------------------------------------------------------
	EXTRN	CODE (OSTimeTick)
	EXTRN	CODE (OSTaskSwHook)
	EXTRN	CODE (OSIntExit)
	EXTRN	CODE (OSTCBSWHook)
	EXTRN	CODE (OSIntEnter)
	EXTRN	CODE (TickTime)
	;//--------------------------------------------------------
	EXTRN	CODE (ExternInt0)
	EXTRN	CODE (ExternInt1)
	EXTRN	CODE (Time1Int)
	EXTRN	CODE (SeryInt)
	;//--------------------------------------------------------
	PUBLIC  Extern_0_ISR 
        PUBLIC  Extern_1_ISR
        PUBLIC  Time_1_ISR
        PUBLIC  Sery_ISR
	;//--------------------------------------------------------
	EXTRN	CODE (OSTickISRHook)
        ;//--------------------------------------------------------
	PUBLIC	OSTickISR
	PUBLIC	OSIntCtxSw
	PUBLIC	OSCtxSw
	PUBLIC	OSStartHighRdy
	;//--------------------------------------------------------

;//----------------------------------------------------------------
PushAll MACRO
        USING 0
        PUSH   PSW		
	PUSH   ACC
	PUSH   B
	PUSH   DPL
	PUSH   DPH
	MOV    A,R0
	PUSH   ACC
	MOV    A,R1
	PUSH   ACC
	MOV    A,R2
	PUSH   ACC
	MOV    A,R3
	PUSH   ACC
	MOV    A,R4
	PUSH   ACC
	MOV    A,R5
	PUSH   ACC
	MOV    A,R6
	PUSH   ACC
	MOV    A,R7
	PUSH   ACC
	PUSH   User_SP+1
	PUSH   User_SP
	PUSH   SP
	ENDM
;//----------------------------------------------------------------       
;//----------------------------------------------------------------
PopAll  MACRO
	POP   ACC
	POP   User_SP	;// high byte
	POP   User_SP+1	;// low byte
	POP   ACC
	MOV   R7,A
	POP   ACC
	MOV   R6,A
	POP   ACC
	MOV   R5,A
	POP   ACC
	MOV   R4,A
	POP   ACC
	MOV   R3,A
	POP   ACC
	MOV   R2,A
	POP   ACC
	MOV   R1,A
	POP   ACC
	MOV   R0,A
	POP   DPL
	POP   DPH
	POP   B
	POP   ACC
	POP   PSW
	ENDM 
;//----------------------------------------------------------------
	RSEG  ?PR?OSStartHighRdy?OS_CPU_A
OSStartHighRdy:
	USING	0
	CLR   EA
	LCALL	OSTaskSwHook
	MOV   STKStart,SP
_OSStartHighRdyGet:	
	;//------------------------------------------
	;// load the low byte of address of (name)
	;// and load the TCB of OSTCBHighRdy to DPTR
        MOV   R0,#LOW  (OSTCBCur)
        INC   R0
        MOV   DPH,@R0
        INC   R0
        MOV   DPL,@R0
        
        ;//------------------------------------------
	;// get the STK of OSTCBCur task TCB
	INC   DPTR
        MOVX  A, @DPTR
	MOV   R1,A
	INC   DPTR
	MOVX  A, @DPTR
	MOV   R0,A
	MOV   DPH, R1
	MOV   DPL, R0
	
	;//------------------------------------------
	;// DPTR --> STK of task
	INC   DPTR
	MOVX  A, @DPTR
	MOV   R5,A

	;//------------------------------------------
	;// copy user to system
	MOV   R1, STKStart
	DEC   R1
        MOV   A, R5
        MOV   R4, A
COPY_STK:
	INC   DPTR
	INC   R1
	MOVX  A, @DPTR
	MOV   @R1, A
	DJNZ  R4, COPY_STK
	
	;//------------------------------------------
	;// OSRunning = 1; multitask start
	MOV  R0, #LOW(OSRunning)
	MOV  @R0,#01
	
	;//------------------------------------------
	;// Now R1 is the new task SP	
	MOV  SP, R1
        PopAll
	SETB  EA
	RETI 	


;//----------------------------------------------------------------	

;//----------------------------------------------------------------
	RSEG  ?PR?OSCtxSw?OS_CPU_A
OSCtxSw:
        CLR  EA
        PushAll	
OSCtxSw2:	
	;//------------------------------------------
	;// SP - STKStart ===> R5
	MOV   A, SP
	CLR   C
	SUBB  A, STKStart
	MOV   R5,A
	MOV   R1,STKStart 
	MOV   A, R5
	ADD   A, #01
	MOV   R5,A
	
	;//------------------------------------------
	MOV   DPH, User_SP
	MOV   DPL, User_SP+1
	
	;//------------------------------------------
	;// DPTR - R5
	MOV   A, DPL	; Adjust the xstack pointer
	CLR   C
	SUBB  A, R5
	MOV   DPL,A
	MOV   A,  DPH
	SUBB  A,  #00H
	MOV   DPH,A
        
	;//------------------------------------------
	;// User_SP ===> DPTR
	MOV User_SP,   DPH
	MOV User_SP+1, DPL

        INC   DPTR
	
	;//------------------------------------------
	;// Save the number of bytes saved
	MOV  A, R5	
	MOVX @DPTR,A
	
	;//------------------------------------------
	;// Save to user stk
	MOV A, R5
	MOV R4,A
	DEC R1
SAVE_STK:
	INC   DPTR
	INC   R1
	MOV   A, @R1
	MOVX  @DPTR, A
	DJNZ  R4, SAVE_STK
        
        ;//------------------------------------------
        MOV   R0,#LOW(OSTCBCur)
        INC   R0
        MOV   DPH,@R0
        INC   R0
        MOV   DPL,@R0
	
	INC   DPTR
	MOV   A,User_SP
	MOVX  @DPTR,A
	INC   DPTR
	MOV   A,User_SP+1
	MOVX  @DPTR,A
	
	;//------------------------------------------	
	LCALL OSTaskSwHook
	LCALL OSTCBSWHook
	LJMP _OSStartHighRdyGet
	;//------------------------------------------
	
;//----------------------------------------------------------------

;//----------------------------------------------------------------
        RSEG  ?PR?OSIntCtxSw?OS_CPU_A
OSIntCtxSw:
        ;//------------------------------------------
	;// Adjust the stack pointer to remove call to:
	;//   - call to OSIntExit  (2 bytes)
	;//   - call to OSIntCtxSw (2 bytes)
	;//   - locals		   (0 bytes)
	CLR     EA
	MOV	A, SP
	CLR	C
	SUBB	A, #4
	MOV	SP,A
	LJMP    OSCtxSw2
;//----------------------------------------------------------------

;//----------------------------------------------------------------
CSEG	AT	0000BH
	LJMP	OSTickISR

        RSEG  ?PR?OSTickISR?OS_CPU_A
OSTickISR:
        USING 0
        PushAll
        CLR    EA       
        CLR    TR0
        MOV    TH0,#3CH
        MOV    TL0,#0B0H
        SETB   TR0
        
        DJNZ   TickTimeInit,OSTI_1
        LCALL  TickTime
        LCALL  OSTickISRHook
        LCALL  OSIntEnter
        LCALL  OSTimeTick
        LCALL  OSIntExit
    
OSTI_1:	
        PopAll
	SETB  EA
	RETI 
;//----------------------------------------------------------------
;//---------------------------------------------------------------- 
CSEG	AT	00003H
	LJMP	Extern_0_ISR
        RSEG    ?PR?_EXTERN_0_ISR_?OS_CPU_A 
Extern_0_ISR:
	USING   0
	CLR     EA 
	PushAll
	LCALL   OSIntEnter
	LCALL   ExternInt0
	PopAll
	SETB    EA
	RETI
;//---------------------------------------------------------------- 
;//---------------------------------------------------------------- 
CSEG	AT	00013H
	LJMP	Extern_1_ISR
	RSEG    ?PR?_EXTERN_1_ISR_?OS_CPU_A 
Extern_1_ISR:
	USING   0
	CLR     EA 
	PushAll
	LCALL   OSIntEnter
	LCALL   ExternInt1
	LCALL   OSIntExit
	PopAll
	SETB    EA
	RETI
;//----------------------------------------------------------------
;//---------------------------------------------------------------- 
CSEG	AT	0001BH
	LJMP	Time_1_ISR
	RSEG    ?PR?_TIME_1_ISR_?OS_CPU_A 
Time_1_ISR:
	USING   0
	CLR     EA 
	PushAll
	LCALL   OSIntEnter
	LCALL   Time1Int
	LCALL   OSIntExit
	PopAll
	SETB    EA
	RETI
;//----------------------------------------------------------------
;//---------------------------------------------------------------- 
CSEG	AT	00023H
	LJMP	Sery_ISR
	RSEG    ?PR?_SERY_ISR_?OS_CPU_A 
Sery_ISR:
	USING   0
	CLR     EA 
	PushAll
	LCALL   OSIntEnter
	LCALL   SeryInt
	LCALL   OSIntExit
	PopAll
	SETB    EA
	RETI
;//----------------------------------------------------------------
;//---------------------------------------------------------------- 
        END
        
        
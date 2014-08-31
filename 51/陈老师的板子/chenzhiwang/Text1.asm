PORTA 	EQU   8FFFH			;8255A口地址
PORTB 	EQU   9FFFH			;8255B口地址
PORTC 	EQU   0AFFFH		;8255C口地址
CADDR  	EQU   0BFFFH		;8255控制字地址

ADDR_A  EQU   08FFFH        ;8255A口地址为8FFFH
ADDR_B  EQU   09FFFH        ;8255B口地址为9FFFH
ADDR_C  EQU   0AFFFH        ;8255C口地址为0AFFFH
ADDR_K  EQU   0BFFFH
_ST		EQU	  P3.6
_OE		EQU	  P3.7
_EOC	EQU	  P3.3

SHOW1   EQU   70H           ;数码管1位数存放内存位置
SHOW2   EQU   71H           ;数码管2位数存放内存位置
SHOW3   EQU   72H           ;数码管3位数存放内存位置
SHOW4   EQU   73H           ;数码管4位数存放内存位置
SHOW5   EQU   74H           ;数码管5位数存放内存位置
SHOW6   EQU   75H           ;数码管6位数存放内存位置
SHOW7   EQU   76H           ;数码管7位数存放内存位置
SHOW8   EQU   77H           ;数码管8位数存放内存位置

KEYNUM  EQU   78H   		;键盘码
KEYCNT  EQU   79H           ;键盘计数器

KEYPRES BIT   71H           ;按键监视位

buttonA equ p3.2
buttonB equ p3.5

org 0000h
ajmp Processes1
org   001bh
ljmp  st1

;实验板上的7段数码管0～9数字的共阴显示代码
NUMLAB: DB      3FH,06H,5BH,4FH,66H,6DH,7DH,07H,7FH,6FH,77H,7CH,39H,5EH,79H,71H	

org 0100h
clr ea
Processes1:;数码管与发光二极管全亮
mov dptr,#CADDR
mov a,#80h
movx @dptr,a
mov dptr,#PORTA
mov a,#0FFH
movx @dptr,a
mov dptr,#PORTB
mov a,#0FFH
movx @dptr,a
mov p1,#07h
mov a,#81h
mov dptr,#CADDR
movx @dptr,a
mov dptr,#PORTC
mov a,#00h
movx @dptr,a
movx a,@dptr
anl a,#0fh
cjne a,#0fh,next1
jmp Processes1
next1:


MOV     A,#81H			;设置8255工作方式
MOV     DPTR,#CADDR
MOVX    @DPTR,A		
MOV     DPTR,#PORTC	
MOV     A,#00H	
MOVX    @DPTR ,A

MOV     SHOW1,#00H		;初始化数码管数组
MOV     SHOW2,#00H
MOV     SHOW3,#00H
MOV     SHOW4,#00H
MOV     SHOW5,#00H
MOV     SHOW6,#00H
MOV     SHOW7,#00H
MOV     SHOW8,#00H
CLR     KEYPRES

Processes2:;显示键盘按键
MOV     KEYNUM,#00H		  ;键盘扫描

ACALL   SCAN
MOV     A,KEYNUM
MOV     C,KEYPRES
JNC		DISP
MOV     DPTR,#NUMLAB
MOVC    A,@A+DPTR
MOV     SHOW1,A
CLR     KEYPRES
DISP:
ACALL	PLAY
jb buttonA,Processes2
JMP next2

/********************************************/
/*          键盘扫描程序                    */ 
/* 说明:   使用键盘时，要将跳线跳至右端 	*/
/********************************************/
SCAN:   MOV     R0,#04H 
        MOV  	R1,#80H
SCLOP:  MOV 	A,R1
        CPL     A
        MOV     DPTR,#PORTC		  ;输出高四位屏蔽码
        MOVX    @DPTR,A
		ANL     A,#0F0H
		MOV     R2,A
		MOVX    A,@DPTR			  ;读回扫描结果
		ANL     A,#0FH
		CJNE    A,#0FH,STORE	  ;判断是否有按键按下
		JMP     NEXT

STORE:  MOV     KEYNUM,A		  ;保存按键位图值
        MOV     A,R2
		ORL     A,KEYNUM
		MOV     KEYNUM,A

		ACALL   D1MS

		MOVX    A,@DPTR
		ANL     A,#0FH
		CJNE    A,#0FH,STORE	  ;等待按键释放

		MOV     A,KEYCNT
		INC     A
		MOV     KEYCNT,A
		SETB    KEYPRES

		JMP     HANDLE

NEXT:	MOV     A,R1
        RR      A
		MOV     R1,A
        DJNZ    R0,SCLOP
		MOV     KEYNUM,#00H
		JMP     EXIT

HANDLE:	MOV     A,KEYNUM		  ;按键位图码转换为按键值
        MOV     KEYNUM,#00H
IF1:    CJNE    A,#0EEH,IF2
        MOV     KEYNUM,#01H
		JMP     EXIT
IF2:    CJNE    A,#0EDH,IF3
        MOV     KEYNUM,#02H
		JMP     EXIT
IF3:    CJNE    A,#0EBH,IF4
        MOV     KEYNUM,#03H
		JMP     EXIT
IF4:    CJNE    A,#0E7H,IF5
        MOV     KEYNUM,#04H
		JMP     EXIT
IF5:    CJNE    A,#0DEH,IF6
        MOV     KEYNUM,#05H
		JMP     EXIT
IF6:    CJNE    A,#0DDH,IF7
        MOV     KEYNUM,#06H
		JMP     EXIT
IF7:    CJNE    A,#0DBH,IF8
        MOV     KEYNUM,#07H
		JMP     EXIT
IF8:    CJNE    A,#0D7H,IF9
        MOV     KEYNUM,#08H
		JMP     EXIT
IF9:    CJNE    A,#0BEH,IF0
        MOV     KEYNUM,#09H
		JMP     EXIT
IF0:    CJNE    A,#0BDH,IFA
        MOV     KEYNUM,#00H
		JMP     EXIT
IFA:    CJNE    A,#0BBH,IFB
        MOV     KEYNUM,#0AH
		JMP     EXIT
IFB:    CJNE    A,#0B7H,IFC
        MOV     KEYNUM,#0BH
		JMP     EXIT
IFC:    CJNE    A,#7EH,IFD
        MOV     KEYNUM,#0CH
		JMP     EXIT
IFD:    CJNE    A,#7DH,IFE
        MOV     KEYNUM,#0DH
		JMP     EXIT
IFE:    CJNE    A,#7BH,IFF
        MOV     KEYNUM,#0EH
		JMP     EXIT
IFF:    CJNE    A,#77H,EXIT
        MOV     KEYNUM,#0FH
EXIT:   RET   

/********************************************/
/*            显示子程序                    */ 
/* 说明:          无			        	*/
/********************************************/
PLAY:   MOV     R0,#08H
        MOV     R1,#SHOW1		  ;取显示码
		MOV     R2,#0ffH
DPLOP:  MOV     A,@R1
        MOV     DPTR,#PORTA             
        MOVX    @DPTR,A           ;送出个位的7段代码
        MOV     DPTR,#PORTB	
	    MOV     A,R2	
	    MOVX    @DPTR ,A          ;开相应的位显示
        ACALL   D1MS              ;显示162微秒
        MOV     DPTR,#PORTB	
	    MOV     A,#0
	    MOVX    @DPTR ,A          ;关闭十位显示,防止鬼影

		MOV     A,R2
		RR      A
		MOV     R2,A
		INC     R1

        DJNZ    R0,DPLOP          ;循环执行8次
        RET 
/********************************************/
/*              延时程序                    */ 
/* 说明:      用于数码管显示延时    		*/
/********************************************/
D1MS:   MOV     R6,#150 
        DJNZ    R6,$
        RET

next2:

MOV         DPTR,#ADDR_K
MOV         A,#80H
MOVX        @DPTR,A
MOV		  DPTR,#ADDR_C
MOV		  A,#0FFH
MOVX		  @DPTR,A
SETB	_OE  ;初始化时使_ST与_OE全为低电平
SETB	_ST
ANL		P2,#0F0H;P2.3为低选中0809,P2.2P2.1P2.0送通道号00

Processes3:
	
;CLR	_ST  ;给_ST正脉冲,启动转换
;SETB	_ST
MOV DPTR,#0f0FFH
MOVX @DPTR,A
ACALL DLY1;延时转换结束
READ:
MOVX A,@DPTR
TRANS:	
MOV		B,#51;近似转换得电压整数值
DIV		AB
MOV		R3,A
XCH		A,B
MOV		B,#5
DIV		AB
MOV		R2,A;近似得电压0.1V数值
MOV		R1,B;近似得电压0.01V数值
DISPLAY:
MOV		DPTR,#ADDR_B
MOV 	A,#80H	 ;选中显示0.01V的LED   
MOVX 	@DPTR,A
MOV		A,R1
MOV		DPTR,#NUMLAB
MOVC	A,@A+DPTR
MOV 	DPTR,#ADDR_A
MOVX	@DPTR,A
ACALL	DELAY
mov a,#0
mov dptr, #ADDR_A
movx @dptr,a
MOV		DPTR,#ADDR_B
MOV 	A,#40H	  ;选中显示0.1V的LED 
MOVX 	@DPTR,A
MOV		A,R2
MOV		DPTR,#NUMLAB
MOVC	A,@A+DPTR
MOV 	DPTR,#ADDR_A
MOVX	@DPTR,A
CALL	DELAY
mov a,#0
mov dptr, #ADDR_A
movx @dptr,a
MOV		DPTR,#ADDR_B
MOV 	A,#20H	  ;选中显示1V的LED  
MOVX 	@DPTR,A
MOV		A,R3
ADD		A,#11;加上小数点
MOV		DPTR,#NUMLAB
MOVC	A,@A+DPTR
MOV 	DPTR,#ADDR_A
MOVX	@DPTR,A
ACALL	DELAY
mov a,#0
mov dptr, #ADDR_A
movx @dptr,a
jb buttonB,Processes3
jmp next3

DLY1:MOV R6,#05
DLY2:NOP
     DJNZ R6,DLY2
     RET
DELAY:	
		MOV		R5,#02H
L1:		MOV		R6,#0E0H
L2:		DJNZ	R6,L2
		DJNZ	R5,L1
		RET

next3:

MOV     A,#80H			;方式0
MOV     DPTR,#CADDR
MOVX    @DPTR,A		;设置8255工作方式
SETB	P2.6		
mov  tl0,#0
mov  th0,#0
mov  tl1,#0b0h
mov  th1,#3ch           ;t1溢出率为50ms
mov  tmod,#15h
setb ea
setb et1
setb tr0
setb tr1
mov  r7,#20

Processes4:
MOV A,R3
MOV B,#100
DIV AB
MOV R2,A          ;r2为第百位
MOV A,B
MOV B,#10
DIV AB
MOV R1,A         ;r1为第十位
MOV R0,B         ;r0为最个位
MOV     A,#80H
MOV   	DPTR,#PORTB             
MOVX    @DPTR,A 		;置个位数码管有效         	
MOV 	DPTR,#NUMLAB
MOV	A,R0
MOVC 	A,@A+DPTR  ;设置个位显示码  
MOV   	DPTR,#PORTA             
MOVX    @DPTR,A 				
CALL    DELAY1
mov a,#0
mov dptr, #ADDR_A
movx @dptr,a		
MOV 	DPTR,#NUMLAB
MOV		A,R1
MOVC 	A,@A+DPTR  ;设置十位显示码  

MOV   	DPTR,#PORTA             
MOVX    @DPTR,A 		

MOV     A,#040H        ;置十位数码管有效
MOV   	DPTR,#PORTB             
MOVX    @DPTR,A 		
CALL    DELAY1	
mov a,#0
mov dptr, #ADDR_A
movx @dptr,a		
MOV 	DPTR,#NUMLAB
MOV	A,R2
MOVC 	A,@A+DPTR  ;设置百位显示码  

MOV   	DPTR,#PORTA             
MOVX    @DPTR,A 		

MOV     A,#020H        ;置百位数码管有效
MOV   	DPTR,#PORTB             
MOVX    @DPTR,A 		
CALL    DELAY1
mov a,#0
mov dptr, #ADDR_A
movx @dptr,a
jb buttonA,Processes4
clr ea
jmp next4

DELAY1:	MOV     R6,#10           ;延时子程序     
LOOP1:  MOV     R5,#10
     
		DJNZ    R5,$
		DJNZ    R6,LOOP1
		RET

st1:  PUSH ACC
      mov  tl1,#0b0h             ;中断子程序
      mov  th1,#3ch
      djnz r7,jies               ;50*20=1000MS
      mov  r7,#20
      MOV R3,TL0     
      MOV  TL0,#0
JIES: POP ACC
      RETI

next4:
Processes5:
setb p1.3
call DELAY
clr p1.3
call DELAY
jb buttonB,Processes5
jmp Processes1

ajmp $

end


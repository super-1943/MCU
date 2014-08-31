PORTA 	EQU   8FFFH			;8255A�ڵ�ַ
PORTB 	EQU   9FFFH			;8255B�ڵ�ַ
PORTC 	EQU   0AFFFH		;8255C�ڵ�ַ
CADDR  	EQU   0BFFFH		;8255�����ֵ�ַ

ADDR_A  EQU   08FFFH        ;8255A�ڵ�ַΪ8FFFH
ADDR_B  EQU   09FFFH        ;8255B�ڵ�ַΪ9FFFH
ADDR_C  EQU   0AFFFH        ;8255C�ڵ�ַΪ0AFFFH
ADDR_K  EQU   0BFFFH
_ST		EQU	  P3.6
_OE		EQU	  P3.7
_EOC	EQU	  P3.3

SHOW1   EQU   70H           ;�����1λ������ڴ�λ��
SHOW2   EQU   71H           ;�����2λ������ڴ�λ��
SHOW3   EQU   72H           ;�����3λ������ڴ�λ��
SHOW4   EQU   73H           ;�����4λ������ڴ�λ��
SHOW5   EQU   74H           ;�����5λ������ڴ�λ��
SHOW6   EQU   75H           ;�����6λ������ڴ�λ��
SHOW7   EQU   76H           ;�����7λ������ڴ�λ��
SHOW8   EQU   77H           ;�����8λ������ڴ�λ��

KEYNUM  EQU   78H   		;������
KEYCNT  EQU   79H           ;���̼�����

KEYPRES BIT   71H           ;��������λ

buttonA equ p3.2
buttonB equ p3.5

org 0000h
ajmp Processes1
org   001bh
ljmp  st1

;ʵ����ϵ�7�������0��9���ֵĹ�����ʾ����
NUMLAB: DB      3FH,06H,5BH,4FH,66H,6DH,7DH,07H,7FH,6FH,77H,7CH,39H,5EH,79H,71H	

org 0100h
clr ea
Processes1:;������뷢�������ȫ��
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


MOV     A,#81H			;����8255������ʽ
MOV     DPTR,#CADDR
MOVX    @DPTR,A		
MOV     DPTR,#PORTC	
MOV     A,#00H	
MOVX    @DPTR ,A

MOV     SHOW1,#00H		;��ʼ�����������
MOV     SHOW2,#00H
MOV     SHOW3,#00H
MOV     SHOW4,#00H
MOV     SHOW5,#00H
MOV     SHOW6,#00H
MOV     SHOW7,#00H
MOV     SHOW8,#00H
CLR     KEYPRES

Processes2:;��ʾ���̰���
MOV     KEYNUM,#00H		  ;����ɨ��

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
/*          ����ɨ�����                    */ 
/* ˵��:   ʹ�ü���ʱ��Ҫ�����������Ҷ� 	*/
/********************************************/
SCAN:   MOV     R0,#04H 
        MOV  	R1,#80H
SCLOP:  MOV 	A,R1
        CPL     A
        MOV     DPTR,#PORTC		  ;�������λ������
        MOVX    @DPTR,A
		ANL     A,#0F0H
		MOV     R2,A
		MOVX    A,@DPTR			  ;����ɨ����
		ANL     A,#0FH
		CJNE    A,#0FH,STORE	  ;�ж��Ƿ��а�������
		JMP     NEXT

STORE:  MOV     KEYNUM,A		  ;���水��λͼֵ
        MOV     A,R2
		ORL     A,KEYNUM
		MOV     KEYNUM,A

		ACALL   D1MS

		MOVX    A,@DPTR
		ANL     A,#0FH
		CJNE    A,#0FH,STORE	  ;�ȴ������ͷ�

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

HANDLE:	MOV     A,KEYNUM		  ;����λͼ��ת��Ϊ����ֵ
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
/*            ��ʾ�ӳ���                    */ 
/* ˵��:          ��			        	*/
/********************************************/
PLAY:   MOV     R0,#08H
        MOV     R1,#SHOW1		  ;ȡ��ʾ��
		MOV     R2,#0ffH
DPLOP:  MOV     A,@R1
        MOV     DPTR,#PORTA             
        MOVX    @DPTR,A           ;�ͳ���λ��7�δ���
        MOV     DPTR,#PORTB	
	    MOV     A,R2	
	    MOVX    @DPTR ,A          ;����Ӧ��λ��ʾ
        ACALL   D1MS              ;��ʾ162΢��
        MOV     DPTR,#PORTB	
	    MOV     A,#0
	    MOVX    @DPTR ,A          ;�ر�ʮλ��ʾ,��ֹ��Ӱ

		MOV     A,R2
		RR      A
		MOV     R2,A
		INC     R1

        DJNZ    R0,DPLOP          ;ѭ��ִ��8��
        RET 
/********************************************/
/*              ��ʱ����                    */ 
/* ˵��:      �����������ʾ��ʱ    		*/
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
SETB	_OE  ;��ʼ��ʱʹ_ST��_OEȫΪ�͵�ƽ
SETB	_ST
ANL		P2,#0F0H;P2.3Ϊ��ѡ��0809,P2.2P2.1P2.0��ͨ����00

Processes3:
	
;CLR	_ST  ;��_ST������,����ת��
;SETB	_ST
MOV DPTR,#0f0FFH
MOVX @DPTR,A
ACALL DLY1;��ʱת������
READ:
MOVX A,@DPTR
TRANS:	
MOV		B,#51;����ת���õ�ѹ����ֵ
DIV		AB
MOV		R3,A
XCH		A,B
MOV		B,#5
DIV		AB
MOV		R2,A;���Ƶõ�ѹ0.1V��ֵ
MOV		R1,B;���Ƶõ�ѹ0.01V��ֵ
DISPLAY:
MOV		DPTR,#ADDR_B
MOV 	A,#80H	 ;ѡ����ʾ0.01V��LED   
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
MOV 	A,#40H	  ;ѡ����ʾ0.1V��LED 
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
MOV 	A,#20H	  ;ѡ����ʾ1V��LED  
MOVX 	@DPTR,A
MOV		A,R3
ADD		A,#11;����С����
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

MOV     A,#80H			;��ʽ0
MOV     DPTR,#CADDR
MOVX    @DPTR,A		;����8255������ʽ
SETB	P2.6		
mov  tl0,#0
mov  th0,#0
mov  tl1,#0b0h
mov  th1,#3ch           ;t1�����Ϊ50ms
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
MOV R2,A          ;r2Ϊ�ڰ�λ
MOV A,B
MOV B,#10
DIV AB
MOV R1,A         ;r1Ϊ��ʮλ
MOV R0,B         ;r0Ϊ���λ
MOV     A,#80H
MOV   	DPTR,#PORTB             
MOVX    @DPTR,A 		;�ø�λ�������Ч         	
MOV 	DPTR,#NUMLAB
MOV	A,R0
MOVC 	A,@A+DPTR  ;���ø�λ��ʾ��  
MOV   	DPTR,#PORTA             
MOVX    @DPTR,A 				
CALL    DELAY1
mov a,#0
mov dptr, #ADDR_A
movx @dptr,a		
MOV 	DPTR,#NUMLAB
MOV		A,R1
MOVC 	A,@A+DPTR  ;����ʮλ��ʾ��  

MOV   	DPTR,#PORTA             
MOVX    @DPTR,A 		

MOV     A,#040H        ;��ʮλ�������Ч
MOV   	DPTR,#PORTB             
MOVX    @DPTR,A 		
CALL    DELAY1	
mov a,#0
mov dptr, #ADDR_A
movx @dptr,a		
MOV 	DPTR,#NUMLAB
MOV	A,R2
MOVC 	A,@A+DPTR  ;���ð�λ��ʾ��  

MOV   	DPTR,#PORTA             
MOVX    @DPTR,A 		

MOV     A,#020H        ;�ð�λ�������Ч
MOV   	DPTR,#PORTB             
MOVX    @DPTR,A 		
CALL    DELAY1
mov a,#0
mov dptr, #ADDR_A
movx @dptr,a
jb buttonA,Processes4
clr ea
jmp next4

DELAY1:	MOV     R6,#10           ;��ʱ�ӳ���     
LOOP1:  MOV     R5,#10
     
		DJNZ    R5,$
		DJNZ    R6,LOOP1
		RET

st1:  PUSH ACC
      mov  tl1,#0b0h             ;�ж��ӳ���
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


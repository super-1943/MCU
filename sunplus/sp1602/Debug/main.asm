// GCC for SUNPLUS u'nSP version 1.0.21-3
// Command: D:\PROGRA~1\SunPlus\UNSPID~1.0\cc1.exe C:\DOCUME~1\a\LOCALS~1\Temp\ccG0caaa.i -fkeep-inline-functions -quiet -dumpbase main.c -mglobal-var-iram -gstabs -Wall -o .\Debug/main.asm
	.external __sn_func_ptr_sec

// gcc2_compiled.:

.debug
	.dw '.stabs "E:/¸öÈË¹¤³ÌÎÄ¼þ¼Ð/ÕÔÓÀ¿Æ/sp1602/",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
.code
.debug
	.dw '.stabs "E:/¸/366È/313¹/244³/314Î/304¼/376¼/320/Õ/324Ó/300¿/306/sp1602/main.c",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
.code
.code
Ltext0:
.debug
	.dw '.stabs "int:t1=r1;-32768;32767;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "char:t2=r2;0;127;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "long int:t3=r3;-2147483648;2147483647;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "unsigned int:t4=r4;0;65535;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "long unsigned int:t5=r5;0;4294967295;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "long long int:t6=r6;-2147483648;2147483647;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "long long unsigned int:t7=r7;0;4294967295;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "short int:t8=r8;-32768;32767;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "short unsigned int:t9=r9;0;65535;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "signed char:t10=r10;-32768;32767;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "unsigned char:t11=r11;0;65535;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "float:t12=r1;2;0;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "double:t13=r1;2;0;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "long double:t14=r1;2;0;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "complex int:t15=s2real:1,0,16;imag:1,16,16;;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "complex float:t16=r16;2;0;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "complex double:t17=r17;2;0;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "complex long double:t18=r18;2;0;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "void:t19=19",128,0,0,0',0x0d,0x0a
.CODE
.code
.debug
	.dw '.stabs "delay:F19",36,0,0,',0,0,offset _delay,seg _delay,0x0d,0x0a
.CODE
.public _delay
_delay:	.proc
.debug
	.dw '.stabn 0x44,0,13,',0,0
	.dd LM1-_delay
	.dw 0x0d,0x0a
.code
LM1:
	// total=3, vars=3
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=3
	bp=sp+1

	R1=BP+6
.debug
	.dw '.stabn 0x44,0,14,',0,0
	.dd LM2-_delay
	.dw 0x0d,0x0a
.code
LM2:
LBB2:
.debug
	.dw '.stabn 0x44,0,15,',0,0
	.dd LM3-_delay
	.dw 0x0d,0x0a
.code
LM3:
L3:
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	CMP R2,0	// QImode test
	NSJNZ L6	//QImode NE
	pc=L4	// Indirect jump
L6:
.debug
	.dw '.stabn 0x44,0,16,',0,0
	.dd LM4-_delay
	.dw 0x0d,0x0a
.code
LM4:
	R2=200	// QImode move
	[BP]=R2	// QImode move
L7:
	R2=[BP]	// QImode move
	CMP R2,0	// QImode test
	NSJNZ L10	//QImode NE
	pc=L5	// Indirect jump
L10:
.debug
	.dw '.stabn 0x44,0,17,',0,0
	.dd LM5-_delay
	.dw 0x0d,0x0a
.code
LM5:
	R2=BP	// QImode move
	R3=BP+1
	R2=100	// QImode move
	R4=R3	// QImode move
	[R4]=R2	// QImode move
L11:
	R2=BP	// QImode move
	R3=BP+1
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	CMP R2,0	// QImode test
	NSJNZ L14	//QImode NE
	pc=L9	// Indirect jump
L14:
.debug
	.dw '.stabn 0x44,0,18,',0,0
	.dd LM6-_delay
	.dw 0x0d,0x0a
.code
LM6:
	R2=1	// QImode move
	[28690]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,17,',0,0
	.dd LM7-_delay
	.dw 0x0d,0x0a
.code
LM7:
L13:
	R2=BP	// QImode move
	R3=BP+1
	R4=BP	// QImode move
	R2=BP+1
	R3=BP	// QImode move
	R3=BP+1
	[bp+2]=R3	// QImode move
	R4=[bp+2]	// QImode move
	R3=[R4]	// QImode move
	R4=R3+(-1)
	R3=R2	// QImode move
	[R3]=R4	// QImode move
	pc=L11	// Indirect jump
L12:
.debug
	.dw '.stabn 0x44,0,16,',0,0
	.dd LM8-_delay
	.dw 0x0d,0x0a
.code
LM8:
L9:
	R2=[BP]	// QImode move
	R3=R2+(-1)
	[BP]=R3	// QImode move
	pc=L7	// Indirect jump
L8:
.debug
	.dw '.stabn 0x44,0,15,',0,0
	.dd LM9-_delay
	.dw 0x0d,0x0a
.code
LM9:
L5:
	R4=R1	// QImode move
	R2=[R4]	// QImode move
	R3=R2+(-1)
	R2=R1	// QImode move
	[R2]=R3	// QImode move
	pc=L3	// Indirect jump
L4:
.debug
	.dw '.stabn 0x44,0,19,',0,0
	.dd LM10-_delay
	.dw 0x0d,0x0a
.code
LM10:
LBE2:
.debug
	.dw '.stabn 0x44,0,19,',0,0
	.dd LM11-_delay
	.dw 0x0d,0x0a
.code
LM11:
L2:

	sp+=3
	pop bp from [sp]
	retf
	.endp	// end of delay

.debug
	.dw '.stabs "i:p4",160,0,0,6',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB2-_delay
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "x:4",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "y:4",128,0,0,1',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE2-_delay
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME1-_delay
	.dw 0x0d,0x0a
.code
LME1:
.code
.debug
	.dw '.stabs "send1602:F19",36,0,0,',0,0,offset _send1602,seg _send1602,0x0d,0x0a
.CODE
.public _send1602
_send1602:	.proc
.debug
	.dw '.stabn 0x44,0,22,',0,0
	.dd LM12-_send1602
	.dw 0x0d,0x0a
.code
LM12:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,24,',0,0
	.dd LM13-_send1602
	.dw 0x0d,0x0a
.code
LM13:
L18:

	pop bp from [sp]
	retf
	.endp	// end of send1602

.debug
	.dw '.stabs "c:p11",160,0,0,3',0x0d,0x0a
.CODE
.debug
	.dw '.stabf ',0,0
	.dd LME2-_send1602
	.dw 0x0d,0x0a
.code
LME2:
.code
.debug
	.dw '.stabs "main:F1",36,0,0,',0,0,offset _main,seg _main,0x0d,0x0a
.CODE
.public _main
_main:	.proc
.debug
	.dw '.stabn 0x44,0,26,',0,0
	.dd LM14-_main
	.dw 0x0d,0x0a
.code
LM14:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,27,',0,0
	.dd LM15-_main
	.dw 0x0d,0x0a
.code
LM15:
L19:

	pop bp from [sp]
	retf
	.endp	// end of main

.debug
	.dw '.stabf ',0,0
	.dd LME3-_main
	.dw 0x0d,0x0a
.code
LME3:
	.end

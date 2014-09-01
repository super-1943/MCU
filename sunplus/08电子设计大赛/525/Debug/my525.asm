// GCC for SUNPLUS u'nSP version 1.0.21-3
// Command: D:\PROGRA~1\Sunplus\UNSPID~1.0\cc1.exe C:\DOCUME~1\a\LOCALS~1\Temp\cco9aaaa.i -fkeep-inline-functions -quiet -dumpbase my525.c -mglobal-var-iram -gstabs -Wall -o .\Debug/my525.asm
	.external __sn_func_ptr_sec

// gcc2_compiled.:

.debug
	.dw '.stabs "H:/525/",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
.code
.debug
	.dw '.stabs "H:/525/my525.c",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
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
.public _table
.iram
_table:
	.dw 0
	.dw 12
	.dw 25
	.dw 37
	.dw 48
	.dw 59
	.dw 68
	.dw 77
	.dw 84
	.dw 90
	.dw 95
	.dw 98
	.dw 100
	.dw 100
	.dw 98
	.dw 95
	.dw 90
	.dw 84
	.dw 77
	.dw 68
	.dw 59
	.dw 48
	.dw 37
	.dw 25
	.dw 12
	.dw 0
.debug
	.dw '.stabs "table:G20=ar1;0;25;4",32,0,0,',0,0,offset _table,seg _table,0x0d,0x0a
.CODE
.code
.debug
	.dw '.stabs "send525:F19",36,0,0,',0,0,offset _send525,seg _send525,0x0d,0x0a
.CODE
.public _send525
_send525:	.proc
.debug
	.dw '.stabn 0x44,0,29,',0,0
	.dd LM1-_send525
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
	.dw '.stabn 0x44,0,30,',0,0
	.dd LM2-_send525
	.dw 0x0d,0x0a
.code
LM2:
LBB2:
.debug
	.dw '.stabn 0x44,0,31,',0,0
	.dd LM3-_send525
	.dw 0x0d,0x0a
.code
LM3:
	R2=[28672]	// QImode move
	R3=R2&(-5)
	[28672]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,32,',0,0
	.dd LM4-_send525
	.dw 0x0d,0x0a
.code
LM4:
	R2=[28672]	// QImode move
	R3=R2&(-2)
	[28672]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,33,',0,0
	.dd LM5-_send525
	.dw 0x0d,0x0a
.code
LM5:
	R2=R1	// QImode move
	R3=[R2]	// QImode move
	R3=R3&4092
	[R2]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,34,',0,0
	.dd LM6-_send525
	.dw 0x0d,0x0a
.code
LM6:
	R4=R1	// QImode move
	R2=[R4]	// QImode move
	R2=R2|(-32768)
	[R4]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,35,',0,0
	.dd LM7-_send525
	.dw 0x0d,0x0a
.code
LM7:
	R2=1	// QImode move
	[28690]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,36,',0,0
	.dd LM8-_send525
	.dw 0x0d,0x0a
.code
LM8:
	R2=BP	// QImode move
	R3=BP+1
	R2=0	// QImode move
	R4=R3	// QImode move
	[R4]=R2	// QImode move
L3:
	R2=BP	// QImode move
	R3=BP+1
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	CMP R2,15	// QImode compare
	NSJNG L6	//QImode LE
	pc=L4	// Indirect jump
L6:
.debug
	.dw '.stabn 0x44,0,38,',0,0
	.dd LM9-_send525
	.dw 0x0d,0x0a
.code
LM9:
	R2=R1	// QImode move
	R2=[R2]	// QImode move
	R2=R2&(-32768)
	[BP]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,39,',0,0
	.dd LM10-_send525
	.dw 0x0d,0x0a
.code
LM10:
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	R3=R2 lsl 1
	R4=R1	// QImode move
	[R4]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,40,',0,0
	.dd LM11-_send525
	.dw 0x0d,0x0a
.code
LM11:
	R2=[BP]	// QImode move
	CMP R2,0	// QImode test
	NSJZ L7	//QImode EQ
.debug
	.dw '.stabn 0x44,0,42,',0,0
	.dd LM12-_send525
	.dw 0x0d,0x0a
.code
LM12:
	R2=[28672]	// QImode move
	R3=R2|2
	[28672]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,43,',0,0
	.dd LM13-_send525
	.dw 0x0d,0x0a
.code
LM13:
	R2=[28672]	// QImode move
	R3=R2&(-2)
	[28672]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,44,',0,0
	.dd LM14-_send525
	.dw 0x0d,0x0a
.code
LM14:
	R2=[28672]	// QImode move
	R3=R2|1
	[28672]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,45,',0,0
	.dd LM15-_send525
	.dw 0x0d,0x0a
.code
LM15:
	pc=L5	// Indirect jump
L7:
.debug
	.dw '.stabn 0x44,0,48,',0,0
	.dd LM16-_send525
	.dw 0x0d,0x0a
.code
LM16:
	R2=[28672]	// QImode move
	R3=R2&(-3)
	[28672]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,49,',0,0
	.dd LM17-_send525
	.dw 0x0d,0x0a
.code
LM17:
	R2=[28672]	// QImode move
	R3=R2&(-2)
	[28672]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,50,',0,0
	.dd LM18-_send525
	.dw 0x0d,0x0a
.code
LM18:
	R2=[28672]	// QImode move
	R3=R2|1
	[28672]=R3	// QImode move
L8:
.debug
	.dw '.stabn 0x44,0,36,',0,0
	.dd LM19-_send525
	.dw 0x0d,0x0a
.code
LM19:
L5:
	R2=BP	// QImode move
	R3=BP+1
	R4=BP	// QImode move
	R2=BP+1
	R3=BP	// QImode move
	R3=BP+1
	[bp+2]=R3	// QImode move
	R4=[bp+2]	// QImode move
	R3=[R4]	// QImode move
	R4=R3+1
	R3=R2	// QImode move
	[R3]=R4	// QImode move
	pc=L3	// Indirect jump
L4:
.debug
	.dw '.stabn 0x44,0,53,',0,0
	.dd LM20-_send525
	.dw 0x0d,0x0a
.code
LM20:
	R2=[28672]	// QImode move
	R3=R2|4
	[28672]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,54,',0,0
	.dd LM21-_send525
	.dw 0x0d,0x0a
.code
LM21:
LBE2:
.debug
	.dw '.stabn 0x44,0,54,',0,0
	.dd LM22-_send525
	.dw 0x0d,0x0a
.code
LM22:
L2:

	sp+=3
	pop bp from [sp]
	retf
	.endp	// end of send525

.debug
	.dw '.stabs "data:p1",160,0,0,6',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB2-_send525
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "temp:1",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "i:1",128,0,0,1',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE2-_send525
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME1-_send525
	.dw 0x0d,0x0a
.code
LME1:
.code
.debug
	.dw '.stabs "init525:F19",36,0,0,',0,0,offset _init525,seg _init525,0x0d,0x0a
.CODE
.public _init525
_init525:	.proc
.debug
	.dw '.stabn 0x44,0,58,',0,0
	.dd LM23-_init525
	.dw 0x0d,0x0a
.code
LM23:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,59,',0,0
	.dd LM24-_init525
	.dw 0x0d,0x0a
.code
LM24:
	R1=[28674]	// QImode move
	R2=R1|15
	[28674]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,60,',0,0
	.dd LM25-_init525
	.dw 0x0d,0x0a
.code
LM25:
	R1=[28675]	// QImode move
	R2=R1|15
	[28675]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,61,',0,0
	.dd LM26-_init525
	.dw 0x0d,0x0a
.code
LM26:
	R1=[28672]	// QImode move
	R2=R1&(-16)
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,62,',0,0
	.dd LM27-_init525
	.dw 0x0d,0x0a
.code
LM27:
	R1=[28672]	// QImode move
	R2=R1&(-9)
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,63,',0,0
	.dd LM28-_init525
	.dw 0x0d,0x0a
.code
LM28:
	R1=[28672]	// QImode move
	R2=R1|8
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,64,',0,0
	.dd LM29-_init525
	.dw 0x0d,0x0a
.code
LM29:
	R1=(-32513)	// QImode move
	[SP--]=R1	// QImode move
	call _send525	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,65,',0,0
	.dd LM30-_init525
	.dw 0x0d,0x0a
.code
LM30:
.debug
	.dw '.stabn 0x44,0,65,',0,0
	.dd LM31-_init525
	.dw 0x0d,0x0a
.code
LM31:
L11:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of init525

.debug
	.dw '.stabf ',0,0
	.dd LME2-_init525
	.dw 0x0d,0x0a
.code
LME2:
.code
.debug
	.dw '.stabs "delay:F19",36,0,0,',0,0,offset _delay,seg _delay,0x0d,0x0a
.CODE
.public _delay
_delay:	.proc
.debug
	.dw '.stabn 0x44,0,68,',0,0
	.dd LM32-_delay
	.dw 0x0d,0x0a
.code
LM32:
	// total=3, vars=3
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=3
	bp=sp+1

	R1=BP+6
.debug
	.dw '.stabn 0x44,0,69,',0,0
	.dd LM33-_delay
	.dw 0x0d,0x0a
.code
LM33:
LBB3:
.debug
	.dw '.stabn 0x44,0,70,',0,0
	.dd LM34-_delay
	.dw 0x0d,0x0a
.code
LM34:
	R2=0	// QImode move
	[BP]=R2	// QImode move
L13:
	R2=[BP]	// QImode move
	CMP R2,9	// QImode compare
	NSJNG L16	//QImode LE
	pc=L14	// Indirect jump
L16:
.debug
	.dw '.stabn 0x44,0,71,',0,0
	.dd LM35-_delay
	.dw 0x0d,0x0a
.code
LM35:
	R2=BP	// QImode move
	R3=BP+1
	R2=0	// QImode move
	R4=R3	// QImode move
	[R4]=R2	// QImode move
L17:
	R2=BP	// QImode move
	R3=BP+1
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	CMP R2,9	// QImode compare
	NSJNG L20	//QImode LE
	pc=L15	// Indirect jump
L20:
.debug
	.dw '.stabn 0x44,0,72,',0,0
	.dd LM36-_delay
	.dw 0x0d,0x0a
.code
LM36:
	R2=1	// QImode move
	[28690]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,71,',0,0
	.dd LM37-_delay
	.dw 0x0d,0x0a
.code
LM37:
L19:
	R2=BP	// QImode move
	R3=BP+1
	R4=BP	// QImode move
	R2=BP+1
	R3=BP	// QImode move
	R3=BP+1
	[bp+2]=R3	// QImode move
	R4=[bp+2]	// QImode move
	R3=[R4]	// QImode move
	R4=R3+1
	R3=R2	// QImode move
	[R3]=R4	// QImode move
	pc=L17	// Indirect jump
L18:
.debug
	.dw '.stabn 0x44,0,70,',0,0
	.dd LM38-_delay
	.dw 0x0d,0x0a
.code
LM38:
L15:
	R2=[BP]	// QImode move
	R3=R2+1
	[BP]=R3	// QImode move
	pc=L13	// Indirect jump
L14:
.debug
	.dw '.stabn 0x44,0,73,',0,0
	.dd LM39-_delay
	.dw 0x0d,0x0a
.code
LM39:
LBE3:
.debug
	.dw '.stabn 0x44,0,73,',0,0
	.dd LM40-_delay
	.dw 0x0d,0x0a
.code
LM40:
L12:

	sp+=3
	pop bp from [sp]
	retf
	.endp	// end of delay

.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB3-_delay
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "i:1",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "j:1",128,0,0,1',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE3-_delay
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME3-_delay
	.dw 0x0d,0x0a
.code
LME3:
.code
.debug
	.dw '.stabs "main:F1",36,0,0,',0,0,offset _main,seg _main,0x0d,0x0a
.CODE
.public _main
_main:	.proc
.debug
	.dw '.stabn 0x44,0,75,',0,0
	.dd LM41-_main
	.dw 0x0d,0x0a
.code
LM41:
	// total=2, vars=2
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=2
	bp=sp+1

	R1=BP+5
	[bp+1]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,76,',0,0
	.dd LM42-_main
	.dw 0x0d,0x0a
.code
LM42:
LBB4:
.debug
	.dw '.stabn 0x44,0,77,',0,0
	.dd LM43-_main
	.dw 0x0d,0x0a
.code
LM43:
	call _init525	// call without return value
.debug
	.dw '.stabn 0x44,0,79,',0,0
	.dd LM44-_main
	.dw 0x0d,0x0a
.code
LM44:
L24:
	pc=L26	// Indirect jump
	pc=L25	// Indirect jump
L26:
.debug
	.dw '.stabn 0x44,0,81,',0,0
	.dd LM45-_main
	.dw 0x0d,0x0a
.code
LM45:
	R1=0	// QImode move
	[BP]=R1	// QImode move
L27:
	R1=[BP]	// QImode move
	CMP R1,24	// QImode compare
	NSJNG L30	//QImode LE
	pc=L28	// Indirect jump
L30:
.debug
	.dw '.stabn 0x44,0,83,',0,0
	.dd LM46-_main
	.dw 0x0d,0x0a
.code
LM46:
	R1=_table	// QImode move
	R2=[BP]	// QImode move
	R1 = R1 + R2	//addqi3
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	R1=10	// QImode move
	mr=R2*R1	// r3=R2*R1 16bit=16bit*16bit
	[SP--]=R3	// QImode move
	call _send525	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,85,',0,0
	.dd LM47-_main
	.dw 0x0d,0x0a
.code
LM47:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,81,',0,0
	.dd LM48-_main
	.dw 0x0d,0x0a
.code
LM48:
L29:
	R1=[BP]	// QImode move
	R2=R1+1
	[BP]=R2	// QImode move
	pc=L27	// Indirect jump
L28:
.debug
	.dw '.stabn 0x44,0,88,',0,0
	.dd LM49-_main
	.dw 0x0d,0x0a
.code
LM49:
	pc=L24	// Indirect jump
L25:
.debug
	.dw '.stabn 0x44,0,89,',0,0
	.dd LM50-_main
	.dw 0x0d,0x0a
.code
LM50:
LBE4:
.debug
	.dw '.stabn 0x44,0,89,',0,0
	.dd LM51-_main
	.dw 0x0d,0x0a
.code
LM51:
L23:

	sp+=2
	pop bp from [sp]
	retf
	.endp	// end of main

.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB4-_main
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "i:1",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE4-_main
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME4-_main
	.dw 0x0d,0x0a
.code
LME4:
	.end

// GCC for SUNPLUS u'nSP version 1.0.21-3
// Command: D:\PROGRA~1\Sunplus\cc1.exe C:\DOCUME~1\GAODEB~1\LOCALS~1\Temp\ccKudaaa.i -fkeep-inline-functions -quiet -dumpbase mian.c -mglobal-var-iram -gstabs -Wall -o .\Debug/mian.asm
	.external __sn_func_ptr_sec

// gcc2_compiled.:

.debug
	.dw '.stabs "F:/gao/dingshiqi/",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
.code
.debug
	.dw '.stabs "F:/gao/dingshiqi/mian.c",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
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
	.dw '.stabs "sendword:F19",36,0,0,',0,0,offset _sendword,seg _sendword,0x0d,0x0a
.CODE
.public _sendword
_sendword:	.proc
.debug
	.dw '.stabs "F:/gao/dingshiqi/my7219.h",0x84,0,0,',0,0,offset Ltext1, seg Ltext1,0x0d,0x0a
.code
.code
Ltext1:
.debug
	.dw '.stabn 0x44,0,36,',0,0
	.dd LM1-_sendword
	.dw 0x0d,0x0a
.code
LM1:
	// total=2, vars=2
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=2
	bp=sp+1

	R1=BP+5
.debug
	.dw '.stabn 0x44,0,37,',0,0
	.dd LM2-_sendword
	.dw 0x0d,0x0a
.code
LM2:
LBB2:
.debug
	.dw '.stabn 0x44,0,38,',0,0
	.dd LM3-_sendword
	.dw 0x0d,0x0a
.code
LM3:
	R2=[28677]	// QImode move
	R3=R2&(-8193)
	[28677]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,39,',0,0
	.dd LM4-_sendword
	.dw 0x0d,0x0a
.code
LM4:
	R2=0	// QImode move
	[BP]=R2	// QImode move
L3:
	R2=[BP]	// QImode move
	CMP R2,15	// QImode compare
	NSJNG L6	//QImode LE
	pc=L4	// Indirect jump
L6:
.debug
	.dw '.stabn 0x44,0,41,',0,0
	.dd LM5-_sendword
	.dw 0x0d,0x0a
.code
LM5:
	R2=1	// QImode move
	[28690]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,42,',0,0
	.dd LM6-_sendword
	.dw 0x0d,0x0a
.code
LM6:
	R2=BP	// QImode move
	R3=BP+1
	R2=R1	// QImode move
	R2=[R2]	// QImode move
	R4=R2&(-32768)
	R2=R3	// QImode move
	[R2]=R4	// QImode move
.debug
	.dw '.stabn 0x44,0,43,',0,0
	.dd LM7-_sendword
	.dw 0x0d,0x0a
.code
LM7:
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	R3=R2 lsl 1
	R4=R1	// QImode move
	[R4]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,44,',0,0
	.dd LM8-_sendword
	.dw 0x0d,0x0a
.code
LM8:
	R2=BP	// QImode move
	R3=BP+1
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	CMP R2,0	// QImode test
	NSJZ L7	//QImode EQ
.debug
	.dw '.stabn 0x44,0,46,',0,0
	.dd LM9-_sendword
	.dw 0x0d,0x0a
.code
LM9:
	R2=[28677]	// QImode move
	R3=R2|16384
	[28677]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,47,',0,0
	.dd LM10-_sendword
	.dw 0x0d,0x0a
.code
LM10:
	R2=[28677]	// QImode move
	R3=R2&32767
	[28677]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,48,',0,0
	.dd LM11-_sendword
	.dw 0x0d,0x0a
.code
LM11:
	R2=[28677]	// QImode move
	R3=R2|(-32768)
	[28677]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,49,',0,0
	.dd LM12-_sendword
	.dw 0x0d,0x0a
.code
LM12:
	pc=L5	// Indirect jump
L7:
.debug
	.dw '.stabn 0x44,0,52,',0,0
	.dd LM13-_sendword
	.dw 0x0d,0x0a
.code
LM13:
	R2=[28677]	// QImode move
	R3=R2&(-16385)
	[28677]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,53,',0,0
	.dd LM14-_sendword
	.dw 0x0d,0x0a
.code
LM14:
	R2=[28677]	// QImode move
	R3=R2&32767
	[28677]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,54,',0,0
	.dd LM15-_sendword
	.dw 0x0d,0x0a
.code
LM15:
	R2=[28677]	// QImode move
	R3=R2|(-32768)
	[28677]=R3	// QImode move
L8:
.debug
	.dw '.stabn 0x44,0,39,',0,0
	.dd LM16-_sendword
	.dw 0x0d,0x0a
.code
LM16:
L5:
	R2=[BP]	// QImode move
	R3=R2+1
	[BP]=R3	// QImode move
	pc=L3	// Indirect jump
L4:
.debug
	.dw '.stabn 0x44,0,57,',0,0
	.dd LM17-_sendword
	.dw 0x0d,0x0a
.code
LM17:
	R2=[28677]	// QImode move
	R3=R2|8192
	[28677]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,58,',0,0
	.dd LM18-_sendword
	.dw 0x0d,0x0a
.code
LM18:
	R2=1	// QImode move
	[28690]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,59,',0,0
	.dd LM19-_sendword
	.dw 0x0d,0x0a
.code
LM19:
LBE2:
.debug
	.dw '.stabn 0x44,0,59,',0,0
	.dd LM20-_sendword
	.dw 0x0d,0x0a
.code
LM20:
L2:

	sp+=2
	pop bp from [sp]
	retf
	.endp	// end of sendword

.debug
	.dw '.stabs "word:p4",160,0,0,5',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB2-_sendword
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "i:1",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "temp:1",128,0,0,1',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE2-_sendword
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME1-_sendword
	.dw 0x0d,0x0a
.code
LME1:
.code
.debug
	.dw '.stabs "init7219:F19",36,0,0,',0,0,offset _init7219,seg _init7219,0x0d,0x0a
.CODE
.public _init7219
_init7219:	.proc
.debug
	.dw '.stabn 0x44,0,61,',0,0
	.dd LM21-_init7219
	.dw 0x0d,0x0a
.code
LM21:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,62,',0,0
	.dd LM22-_init7219
	.dw 0x0d,0x0a
.code
LM22:
	R1=[28679]	// QImode move
	R2=R1|(-4096)
	[28679]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,63,',0,0
	.dd LM23-_init7219
	.dw 0x0d,0x0a
.code
LM23:
	R1=[28680]	// QImode move
	R2=R1|(-4096)
	[28680]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,64,',0,0
	.dd LM24-_init7219
	.dw 0x0d,0x0a
.code
LM24:
	R1=[28677]	// QImode move
	R2=R1&4095
	[28677]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,65,',0,0
	.dd LM25-_init7219
	.dw 0x0d,0x0a
.code
LM25:
	R1=2823	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,66,',0,0
	.dd LM26-_init7219
	.dw 0x0d,0x0a
.code
LM26:
	R1=2559	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,67,',0,0
	.dd LM27-_init7219
	.dw 0x0d,0x0a
.code
LM27:
	R1=2570	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,68,',0,0
	.dd LM28-_init7219
	.dw 0x0d,0x0a
.code
LM28:
	R1=3073	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,69,',0,0
	.dd LM29-_init7219
	.dw 0x0d,0x0a
.code
LM29:
	R1=3841	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,70,',0,0
	.dd LM30-_init7219
	.dw 0x0d,0x0a
.code
LM30:
	R1=3840	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,71,',0,0
	.dd LM31-_init7219
	.dw 0x0d,0x0a
.code
LM31:
.debug
	.dw '.stabn 0x44,0,71,',0,0
	.dd LM32-_init7219
	.dw 0x0d,0x0a
.code
LM32:
L11:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of init7219

.debug
	.dw '.stabf ',0,0
	.dd LME2-_init7219
	.dw 0x0d,0x0a
.code
LME2:
.code
.debug
	.dw '.stabs "show:F19",36,0,0,',0,0,offset _show,seg _show,0x0d,0x0a
.CODE
.public _show
_show:	.proc
.debug
	.dw '.stabn 0x44,0,80,',0,0
	.dd LM33-_show
	.dw 0x0d,0x0a
.code
LM33:
	// total=14, vars=14
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=14
	bp=sp+1

	R1=BP+17
	[bp+8]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,81,',0,0
	.dd LM34-_show
	.dw 0x0d,0x0a
.code
LM34:
LBB3:
.debug
	.dw '.stabn 0x44,0,83,',0,0
	.dd LM35-_show
	.dw 0x0d,0x0a
.code
LM35:
	R1=[28679]	// QImode move
	R2=R1|(-4096)
	[28679]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,84,',0,0
	.dd LM36-_show
	.dw 0x0d,0x0a
.code
LM36:
	R1=[28680]	// QImode move
	R2=R1|(-4096)
	[28680]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,85,',0,0
	.dd LM37-_show
	.dw 0x0d,0x0a
.code
LM37:
	R1=[28677]	// QImode move
	R2=R1&4095
	[28677]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,86,',0,0
	.dd LM38-_show
	.dw 0x0d,0x0a
.code
LM38:
	R1=2823	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,87,',0,0
	.dd LM39-_show
	.dw 0x0d,0x0a
.code
LM39:
	R1=2559	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,88,',0,0
	.dd LM40-_show
	.dw 0x0d,0x0a
.code
LM40:
	R1=2570	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,89,',0,0
	.dd LM41-_show
	.dw 0x0d,0x0a
.code
LM41:
	R1=3073	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,91,',0,0
	.dd LM42-_show
	.dw 0x0d,0x0a
.code
LM42:
	R2=[bp+8]	// QImode move
	R1=[R2]	// QImode move
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,92,',0,0
	.dd LM43-_show
	.dw 0x0d,0x0a
.code
LM43:
	R1=BP	// QImode move
	R3=BP+2
	[bp+9]=R3	// QImode move
	R1=[bp+8]	// QImode move
	R4=[bp+8]	// QImode move
	R2=R4+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	R2=10000	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __divi1	// call with return value
	SP = SP + 2	//SP
	R4=[bp+9]	// QImode move
	[R4]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,93,',0,0
	.dd LM44-_show
	.dw 0x0d,0x0a
.code
LM44:
	R1=BP	// QImode move
	R1=BP+3
	[bp+10]=R1	// QImode move
	R1=[bp+8]	// QImode move
	R3=[bp+8]	// QImode move
	R2=R3+1
	R4=R2	// QImode move
	R1=[R4]	// QImode move
	R2=10000	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __modi1	// call with return value
	SP = SP + 2	//SP
	R2=1000	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __divi1	// call with return value
	SP = SP + 2	//SP
	R2=[bp+10]	// QImode move
	[R2]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,94,',0,0
	.dd LM45-_show
	.dw 0x0d,0x0a
.code
LM45:
	R2=BP	// QImode move
	R1=BP+3
	R2=BP	// QImode move
	R3=BP+3
	R4=R3	// QImode move
	R4=[R4]	// QImode move
	R2=R4|128
	R4=R1	// QImode move
	[R4]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,95,',0,0
	.dd LM46-_show
	.dw 0x0d,0x0a
.code
LM46:
	R1=BP	// QImode move
	R1=BP+4
	[bp+11]=R1	// QImode move
	R1=[bp+8]	// QImode move
	R3=[bp+8]	// QImode move
	R2=R3+1
	R4=R2	// QImode move
	R1=[R4]	// QImode move
	R2=100	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __divi1	// call with return value
	SP = SP + 2	//SP
	R2=10	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __modi1	// call with return value
	SP = SP + 2	//SP
	R2=[bp+11]	// QImode move
	[R2]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,96,',0,0
	.dd LM47-_show
	.dw 0x0d,0x0a
.code
LM47:
	R1=BP	// QImode move
	R3=BP+6
	[bp+12]=R3	// QImode move
	R1=[bp+8]	// QImode move
	R4=[bp+8]	// QImode move
	R2=R4+2
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	R2=10	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __divi1	// call with return value
	SP = SP + 2	//SP
	R2=R1|128
	R4=[bp+12]	// QImode move
	[R4]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,97,',0,0
	.dd LM48-_show
	.dw 0x0d,0x0a
.code
LM48:
	R1=BP	// QImode move
	R3=BP+7
	[bp+13]=R3	// QImode move
	R1=[bp+8]	// QImode move
	R4=[bp+8]	// QImode move
	R2=R4+2
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	R2=10	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __modi1	// call with return value
	SP = SP + 2	//SP
	R4=[bp+13]	// QImode move
	[R4]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,98,',0,0
	.dd LM49-_show
	.dw 0x0d,0x0a
.code
LM49:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,99,',0,0
	.dd LM50-_show
	.dw 0x0d,0x0a
.code
LM50:
	R2=[BP]	// QImode move
	R1=R2|2048
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,100,',0,0
	.dd LM51-_show
	.dw 0x0d,0x0a
.code
LM51:
	R1=1807	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,101,',0,0
	.dd LM52-_show
	.dw 0x0d,0x0a
.code
LM52:
	R1=BP	// QImode move
	R2=BP+2
	R3=R2	// QImode move
	R3=[R3]	// QImode move
	R1=R3|1536
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,102,',0,0
	.dd LM53-_show
	.dw 0x0d,0x0a
.code
LM53:
	R1=BP	// QImode move
	R2=BP+3
	R4=R2	// QImode move
	R4=[R4]	// QImode move
	R1=R4|1280
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,103,',0,0
	.dd LM54-_show
	.dw 0x0d,0x0a
.code
LM54:
	R1=BP	// QImode move
	R2=BP+4
	R3=R2	// QImode move
	R3=[R3]	// QImode move
	R1=R3|1024
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,104,',0,0
	.dd LM55-_show
	.dw 0x0d,0x0a
.code
LM55:
	R1=783	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,105,',0,0
	.dd LM56-_show
	.dw 0x0d,0x0a
.code
LM56:
	R1=BP	// QImode move
	R2=BP+6
	R4=R2	// QImode move
	R4=[R4]	// QImode move
	R1=R4|512
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,106,',0,0
	.dd LM57-_show
	.dw 0x0d,0x0a
.code
LM57:
	R1=BP	// QImode move
	R2=BP+7
	R3=R2	// QImode move
	R3=[R3]	// QImode move
	R1=R3|256
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,107,',0,0
	.dd LM58-_show
	.dw 0x0d,0x0a
.code
LM58:
LBE3:
.debug
	.dw '.stabn 0x44,0,107,',0,0
	.dd LM59-_show
	.dw 0x0d,0x0a
.code
LM59:
L12:

	sp+=14
	pop bp from [sp]
	retf
	.endp	// end of show

.debug
	.dw '.stabs "mode:p1",160,0,0,17',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "freq:p1",160,0,0,18',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "mvol:p1",160,0,0,19',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB3-_show
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "tmp:20=ar1;0;7;1",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE3-_show
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME3-_show
	.dw 0x0d,0x0a
.code
LME3:
.public _buffer
.iram
_buffer:
	.dw 1
	.dw 1000
	.dw 50
	.dw 1
	.dw 0
	.dw 0
	.dw 2 dup(0)
.debug
	.dw '.stabs "buffer:G21=ar1;0;7;4",32,0,0,',0,0,offset _buffer,seg _buffer,0x0d,0x0a
.CODE
.public _ZX
.iram
_ZX:
	.dw 512
	.dw 528
	.dw 544
	.dw 560
	.dw 576
	.dw 592
	.dw 607
	.dw 623
	.dw 639
	.dw 654
	.dw 670
	.dw 685
	.dw 700
	.dw 715
	.dw 729
	.dw 744
	.dw 758
	.dw 772
	.dw 786
	.dw 799
	.dw 812
	.dw 825
	.dw 838
	.dw 850
	.dw 862
	.dw 873
	.dw 885
	.dw 895
	.dw 906
	.dw 916
	.dw 926
	.dw 935
	.dw 944
	.dw 952
	.dw 960
	.dw 968
	.dw 975
	.dw 981
	.dw 987
	.dw 993
	.dw 998
	.dw 1003
	.dw 1007
	.dw 1011
	.dw 1014
	.dw 1017
	.dw 1019
	.dw 1021
	.dw 1022
	.dw 1023
	.dw 1023
	.dw 1023
	.dw 1023
	.dw 1021
	.dw 1020
	.dw 1017
	.dw 1015
	.dw 1011
	.dw 1008
	.dw 1003
	.dw 999
	.dw 993
	.dw 988
	.dw 982
	.dw 975
	.dw 968
	.dw 960
	.dw 952
	.dw 944
	.dw 935
	.dw 926
	.dw 916
	.dw 906
	.dw 896
	.dw 885
	.dw 874
	.dw 862
	.dw 851
	.dw 838
	.dw 826
	.dw 813
	.dw 800
	.dw 786
	.dw 773
	.dw 759
	.dw 745
	.dw 730
	.dw 715
	.dw 701
	.dw 686
	.dw 670
	.dw 655
	.dw 640
	.dw 624
	.dw 608
	.dw 592
	.dw 576
	.dw 560
	.dw 544
	.dw 528
	.dw 512
	.dw 496
	.dw 480
	.dw 464
	.dw 448
	.dw 432
	.dw 416
	.dw 401
	.dw 385
	.dw 370
	.dw 354
	.dw 339
	.dw 324
	.dw 309
	.dw 294
	.dw 280
	.dw 266
	.dw 252
	.dw 238
	.dw 225
	.dw 211
	.dw 198
	.dw 186
	.dw 174
	.dw 162
	.dw 150
	.dw 139
	.dw 128
	.dw 118
	.dw 108
	.dw 98
	.dw 89
	.dw 80
	.dw 71
	.dw 63
	.dw 56
	.dw 49
	.dw 42
	.dw 36
	.dw 30
	.dw 25
	.dw 20
	.dw 16
	.dw 12
	.dw 9
	.dw 6
	.dw 4
	.dw 2
	.dw 1
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 2
	.dw 3
	.dw 6
	.dw 8
	.dw 12
	.dw 15
	.dw 19
	.dw 24
	.dw 29
	.dw 35
	.dw 41
	.dw 48
	.dw 55
	.dw 62
	.dw 70
	.dw 78
	.dw 87
	.dw 96
	.dw 106
	.dw 116
	.dw 127
	.dw 137
	.dw 148
	.dw 160
	.dw 172
	.dw 184
	.dw 197
	.dw 209
	.dw 222
	.dw 236
	.dw 250
	.dw 264
	.dw 278
	.dw 292
	.dw 307
	.dw 322
	.dw 337
	.dw 352
	.dw 367
	.dw 383
	.dw 398
	.dw 414
	.dw 430
	.dw 446
	.dw 462
	.dw 478
	.dw 494
.debug
	.dw '.stabs "ZX:G22=ar1;0;199;4",32,0,0,',0,0,offset _ZX,seg _ZX,0x0d,0x0a
.CODE
.public _SJ
.iram
_SJ:
	.dw 0
	.dw 10
	.dw 20
	.dw 30
	.dw 40
	.dw 50
	.dw 60
	.dw 70
	.dw 80
	.dw 90
	.dw 100
	.dw 110
	.dw 120
	.dw 130
	.dw 140
	.dw 150
	.dw 160
	.dw 170
	.dw 180
	.dw 190
	.dw 200
	.dw 210
	.dw 220
	.dw 230
	.dw 240
	.dw 250
	.dw 260
	.dw 270
	.dw 280
	.dw 290
	.dw 300
	.dw 310
	.dw 320
	.dw 330
	.dw 340
	.dw 350
	.dw 360
	.dw 370
	.dw 380
	.dw 390
	.dw 400
	.dw 410
	.dw 420
	.dw 430
	.dw 440
	.dw 450
	.dw 460
	.dw 470
	.dw 480
	.dw 490
	.dw 500
	.dw 510
	.dw 520
	.dw 530
	.dw 540
	.dw 550
	.dw 560
	.dw 570
	.dw 580
	.dw 590
	.dw 600
	.dw 610
	.dw 620
	.dw 630
	.dw 640
	.dw 650
	.dw 660
	.dw 670
	.dw 680
	.dw 690
	.dw 700
	.dw 710
	.dw 720
	.dw 730
	.dw 740
	.dw 750
	.dw 760
	.dw 770
	.dw 780
	.dw 790
	.dw 800
	.dw 810
	.dw 820
	.dw 830
	.dw 840
	.dw 850
	.dw 860
	.dw 870
	.dw 880
	.dw 890
	.dw 900
	.dw 910
	.dw 920
	.dw 930
	.dw 940
	.dw 950
	.dw 960
	.dw 970
	.dw 980
	.dw 990
	.dw 1000
	.dw 1000
	.dw 990
	.dw 980
	.dw 970
	.dw 960
	.dw 950
	.dw 940
	.dw 930
	.dw 920
	.dw 910
	.dw 900
	.dw 890
	.dw 880
	.dw 870
	.dw 860
	.dw 850
	.dw 840
	.dw 830
	.dw 820
	.dw 810
	.dw 800
	.dw 790
	.dw 780
	.dw 770
	.dw 760
	.dw 750
	.dw 740
	.dw 730
	.dw 720
	.dw 710
	.dw 700
	.dw 690
	.dw 680
	.dw 670
	.dw 660
	.dw 650
	.dw 640
	.dw 630
	.dw 620
	.dw 610
	.dw 600
	.dw 590
	.dw 580
	.dw 570
	.dw 560
	.dw 550
	.dw 540
	.dw 530
	.dw 520
	.dw 510
	.dw 500
	.dw 490
	.dw 480
	.dw 470
	.dw 460
	.dw 450
	.dw 440
	.dw 430
	.dw 420
	.dw 410
	.dw 400
	.dw 390
	.dw 380
	.dw 370
	.dw 360
	.dw 350
	.dw 340
	.dw 330
	.dw 320
	.dw 310
	.dw 300
	.dw 290
	.dw 280
	.dw 270
	.dw 260
	.dw 250
	.dw 240
	.dw 230
	.dw 220
	.dw 210
	.dw 200
	.dw 190
	.dw 180
	.dw 170
	.dw 160
	.dw 150
	.dw 140
	.dw 130
	.dw 120
	.dw 110
	.dw 100
	.dw 90
	.dw 80
	.dw 70
	.dw 60
	.dw 50
	.dw 40
	.dw 30
	.dw 20
	.dw 10
	.dw 0
.debug
	.dw '.stabs "SJ:G23=ar1;0;201;4",32,0,0,',0,0,offset _SJ,seg _SJ,0x0d,0x0a
.CODE
.public _JX
.iram
_JX:
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 1000
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
.debug
	.dw '.stabs "JX:G24=ar1;0;199;4",32,0,0,',0,0,offset _JX,seg _JX,0x0d,0x0a
.CODE
.public _JU
.iram
_JU:
	.dw 1000
	.dw 0
.debug
	.dw '.stabs "JU:G25=ar1;0;1;4",32,0,0,',0,0,offset _JU,seg _JU,0x0d,0x0a
.CODE
.code
.debug
	.dw '.stabs "delay:F19",36,0,0,',0,0,offset _delay,seg _delay,0x0d,0x0a
.CODE
.public _delay
_delay:	.proc
.debug
	.dw '.stabs "F:/gao/dingshiqi/mian.c",0x84,0,0,',0,0,offset Ltext2, seg Ltext2,0x0d,0x0a
.code
.code
Ltext2:
.debug
	.dw '.stabn 0x44,0,28,',0,0
	.dd LM60-_delay
	.dw 0x0d,0x0a
.code
LM60:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
.debug
	.dw '.stabn 0x44,0,29,',0,0
	.dd LM61-_delay
	.dw 0x0d,0x0a
.code
LM61:
LBB4:
	R2=3840	// QImode move
	[BP]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,30,',0,0
	.dd LM62-_delay
	.dw 0x0d,0x0a
.code
LM62:
L14:
	R3=[BP]	// QImode move
	R2=R3+(-1)
	R3=R2	// QImode move
	[BP]=R3	// QImode move
	CMP R3,(-1)	// QImode compare
	NSJNZ L16	//QImode NE
	pc=L15	// Indirect jump
L16:
.debug
	.dw '.stabn 0x44,0,31,',0,0
	.dd LM63-_delay
	.dw 0x0d,0x0a
.code
LM63:
	R2=1	// QImode move
	[28690]=R2	// QImode move
	pc=L14	// Indirect jump
L15:
.debug
	.dw '.stabn 0x44,0,32,',0,0
	.dd LM64-_delay
	.dw 0x0d,0x0a
.code
LM64:
LBE4:
.debug
	.dw '.stabn 0x44,0,32,',0,0
	.dd LM65-_delay
	.dw 0x0d,0x0a
.code
LM65:
L13:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of delay

.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB4-_delay
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "x:4",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE4-_delay
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME4-_delay
	.dw 0x0d,0x0a
.code
LME4:
.code
.debug
	.dw '.stabs "shortdelay:F19",36,0,0,',0,0,offset _shortdelay,seg _shortdelay,0x0d,0x0a
.CODE
.public _shortdelay
_shortdelay:	.proc
.debug
	.dw '.stabn 0x44,0,34,',0,0
	.dd LM66-_shortdelay
	.dw 0x0d,0x0a
.code
LM66:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
.debug
	.dw '.stabn 0x44,0,35,',0,0
	.dd LM67-_shortdelay
	.dw 0x0d,0x0a
.code
LM67:
LBB5:
L19:
	R2=R1	// QImode move
	R3=[R2]	// QImode move
	R2=R3+(-1)
	R3=R2	// QImode move
	R2=R1	// QImode move
	[R2]=R3	// QImode move
	CMP R3,(-1)	// QImode compare
	NSJNZ L21	//QImode NE
	pc=L20	// Indirect jump
L21:
.debug
	.dw '.stabn 0x44,0,37,',0,0
	.dd LM68-_shortdelay
	.dw 0x0d,0x0a
.code
LM68:
LBB6:
.debug
	.dw '.stabn 0x44,0,38,',0,0
	.dd LM69-_shortdelay
	.dw 0x0d,0x0a
.code
LM69:
	R2=20	// QImode move
	[BP]=R2	// QImode move
L22:
	R2=[BP]	// QImode move
	CMP R2,0	// QImode test
	NSJNZ L24	//QImode NE
	pc=L23	// Indirect jump
L25:
L24:
	R2=[BP]	// QImode move
	R3=R2+(-1)
	[BP]=R3	// QImode move
	pc=L22	// Indirect jump
L23:
.debug
	.dw '.stabn 0x44,0,39,',0,0
	.dd LM70-_shortdelay
	.dw 0x0d,0x0a
.code
LM70:
LBE6:
	pc=L19	// Indirect jump
L20:
.debug
	.dw '.stabn 0x44,0,40,',0,0
	.dd LM71-_shortdelay
	.dw 0x0d,0x0a
.code
LM71:
	R2=1	// QImode move
	[28690]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,41,',0,0
	.dd LM72-_shortdelay
	.dw 0x0d,0x0a
.code
LM72:
LBE5:
.debug
	.dw '.stabn 0x44,0,41,',0,0
	.dd LM73-_shortdelay
	.dw 0x0d,0x0a
.code
LM73:
L18:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of shortdelay

.debug
	.dw '.stabs "x:p1",160,0,0,4',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB5-_shortdelay
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB6-_shortdelay
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "i:2",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE6-_shortdelay
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE5-_shortdelay
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME5-_shortdelay
	.dw 0x0d,0x0a
.code
LME5:
// ISR ATTRIBUTE FUNCTION, LOCATE in .text SECTION
.text
.debug
	.dw '.stabs "IRQ1:F19",36,0,0,',0,0,offset _IRQ1,seg _IRQ1,0x0d,0x0a
.TEXT
.public _IRQ1
_IRQ1:	.proc
.debug
	.dw '.stabn 0x44,0,44,',0,0
	.dd LM74-_IRQ1
	.dw 0x0d,0x0a
.text
LM74:
	// ISR ATTRIBUTE FUNCTION, PUSH r1,bp
	push r1,bp to [sp]

	// total=1, vars=1
	// frame_pointer_needed: 1
	sp-=1
	bp=sp+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,45,',0,0
	.dd LM75-_IRQ1
	.dw 0x0d,0x0a
.text
LM75:
	R1=[_buffer+6]	// QImode move
	R2=1	// QImode move
	[_buffer+6]=R1+R2  //addqi3_Qrr
.debug
	.dw '.stabn 0x44,0,47,',0,0
	.dd LM76-_IRQ1
	.dw 0x0d,0x0a
.text
LM76:
	R1=[_buffer+6]	// QImode move
	CMP R1,200	// QImode compare
	NSJNZ L29	//QImode NE
.debug
	.dw '.stabn 0x44,0,49,',0,0
	.dd LM77-_IRQ1
	.dw 0x0d,0x0a
.text
LM77:
	R1=0	// QImode move
	[_buffer+6]=R1	// QImode move
L29:
.debug
	.dw '.stabn 0x44,0,51,',0,0
	.dd LM78-_IRQ1
	.dw 0x0d,0x0a
.text
LM78:
	R2=[_buffer]	// QImode move
	R1=R2	// QImode move
	CMP R1,6	// QImode compare
	NSJA L38	//QImode GTU
	R2=L39	// QImode move
	R1 = R1 + R2	//addqi3
	R2=R1	// QImode move
	R1=[R2]	// QImode move
	pc=R1	// tablejump
.text
L39:
	.dw L31
	.dw L32
	.dw L33
	.dw L34
	.dw L35
	.dw L36
	.dw L37
// ISR ATTRIBUTE FUNCTION, LOCATE in .text SECTION
.text
.debug
	.dw '.stabn 0x44,0,53,',0,0
	.dd LM79-_IRQ1
	.dw 0x0d,0x0a
.text
LM79:
	R1=1	// QImode move
	[28690]=R1	// QImode move
L31:
.debug
	.dw '.stabn 0x44,0,55,',0,0
	.dd LM80-_IRQ1
	.dw 0x0d,0x0a
.text
LM80:
	R1=_JX	// QImode move
	R2=[_buffer+6]	// QImode move
	R1 = R1 + R2	//addqi3
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	R1=[_buffer+2]	// QImode move
	mr=R2*R1	// r3=R2*R1 16bit=16bit*16bit
	[_buffer+4]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,56,',0,0
	.dd LM81-_IRQ1
	.dw 0x0d,0x0a
.text
LM81:
	pc=L30	// Indirect jump
L32:
.debug
	.dw '.stabn 0x44,0,58,',0,0
	.dd LM82-_IRQ1
	.dw 0x0d,0x0a
.text
LM82:
	R1=_SJ	// QImode move
	R2=[_buffer+6]	// QImode move
	R1 = R1 + R2	//addqi3
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	R1=[_buffer+2]	// QImode move
	mr=R2*R1	// r3=R2*R1 16bit=16bit*16bit
	[_buffer+4]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,59,',0,0
	.dd LM83-_IRQ1
	.dw 0x0d,0x0a
.text
LM83:
	pc=L30	// Indirect jump
L33:
.debug
	.dw '.stabn 0x44,0,61,',0,0
	.dd LM84-_IRQ1
	.dw 0x0d,0x0a
.text
LM84:
	R1=_ZX	// QImode move
	R2=[_buffer+6]	// QImode move
	R1 = R1 + R2	//addqi3
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	R1=[_buffer+2]	// QImode move
	mr=R2*R1	// r3=R2*R1 16bit=16bit*16bit
	[_buffer+4]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,62,',0,0
	.dd LM85-_IRQ1
	.dw 0x0d,0x0a
.text
LM85:
	pc=L30	// Indirect jump
L34:
.debug
	.dw '.stabn 0x44,0,64,',0,0
	.dd LM86-_IRQ1
	.dw 0x0d,0x0a
.text
LM86:
	R1=_SJ	// QImode move
	R2=[_buffer+6]	// QImode move
	R1 = R1 + R2	//addqi3
	R2=_JX	// QImode move
	R3=[_buffer+6]	// QImode move
	R2 = R2 + R3	//addqi3
	R4=R1	// QImode move
	R3=[R4]	// QImode move
	R1=R3	// QImode move
	R3=R2	// QImode move
	R1 = R1 + [R3]	//addqi3
	R2=R1 lsr 1
	R1=[_buffer+2]	// QImode move
	mr=R2*R1	// r3=R2*R1 16bit=16bit*16bit
	[_buffer+4]=R3	// QImode move
L35:
.debug
	.dw '.stabn 0x44,0,66,',0,0
	.dd LM87-_IRQ1
	.dw 0x0d,0x0a
.text
LM87:
	R1=_ZX	// QImode move
	R2=[_buffer+6]	// QImode move
	R1 = R1 + R2	//addqi3
	R2=_JX	// QImode move
	R3=[_buffer+6]	// QImode move
	R2 = R2 + R3	//addqi3
	R4=R1	// QImode move
	R3=[R4]	// QImode move
	R1=R3	// QImode move
	R3=R2	// QImode move
	R1 = R1 + [R3]	//addqi3
	R2=R1 lsr 1
	R1=[_buffer+2]	// QImode move
	mr=R2*R1	// r3=R2*R1 16bit=16bit*16bit
	[_buffer+4]=R3	// QImode move
L36:
.debug
	.dw '.stabn 0x44,0,68,',0,0
	.dd LM88-_IRQ1
	.dw 0x0d,0x0a
.text
LM88:
	R1=_ZX	// QImode move
	R2=[_buffer+6]	// QImode move
	R1 = R1 + R2	//addqi3
	R2=_SJ	// QImode move
	R3=[_buffer+6]	// QImode move
	R2 = R2 + R3	//addqi3
	R4=R1	// QImode move
	R3=[R4]	// QImode move
	R1=R3	// QImode move
	R3=R2	// QImode move
	R1 = R1 + [R3]	//addqi3
	R2=R1 lsr 1
	R1=[_buffer+2]	// QImode move
	mr=R2*R1	// r3=R2*R1 16bit=16bit*16bit
	[_buffer+4]=R3	// QImode move
L37:
.debug
	.dw '.stabn 0x44,0,70,',0,0
	.dd LM89-_IRQ1
	.dw 0x0d,0x0a
.text
LM89:
	R1=_ZX	// QImode move
	R2=[_buffer+6]	// QImode move
	R1 = R1 + R2	//addqi3
	R2=_SJ	// QImode move
	R3=[_buffer+6]	// QImode move
	R2 = R2 + R3	//addqi3
	R4=R1	// QImode move
	R3=[R4]	// QImode move
	R1=R3	// QImode move
	R3=R2	// QImode move
	R1 = R1 + [R3]	//addqi3
	R2=_JX	// QImode move
	R3=[_buffer+6]	// QImode move
	R2 = R2 + R3	//addqi3
	R4=R2	// QImode move
	R1 = R1 + [R4]	//addqi3
	R2=3	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __divu1	// call with return value
	SP = SP + 2	//SP
	R2=[_buffer+2]	// QImode move
	mr=R1*R2	// r3=R1*R2 16bit=16bit*16bit
	[_buffer+4]=R3	// QImode move
L38:
.debug
	.dw '.stabn 0x44,0,72,',0,0
	.dd LM90-_IRQ1
	.dw 0x0d,0x0a
.text
LM90:
	pc=L30	// Indirect jump
L30:
.debug
	.dw '.stabn 0x44,0,78,',0,0
	.dd LM91-_IRQ1
	.dw 0x0d,0x0a
.text
LM91:
	R1=4096	// QImode move
	[28689]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,80,',0,0
	.dd LM92-_IRQ1
	.dw 0x0d,0x0a
.text
LM92:
.debug
	.dw '.stabn 0x44,0,80,',0,0
	.dd LM93-_IRQ1
	.dw 0x0d,0x0a
.text
LM93:
L28:

	sp+=1
	// ISR ATTRIBUTE FUNCTION, POP r1,bp
	pop r1,bp from [sp]
	reti
	.endp	// end of IRQ1

.debug
	.dw '.stabf ',0,0
	.dd LME6-_IRQ1
	.dw 0x0d,0x0a
.text
LME6:
.code
.debug
	.dw '.stabs "KeyScan:F19",36,0,0,',0,0,offset _KeyScan,seg _KeyScan,0x0d,0x0a
.CODE
.public _KeyScan
_KeyScan:	.proc
.debug
	.dw '.stabn 0x44,0,83,',0,0
	.dd LM94-_KeyScan
	.dw 0x0d,0x0a
.code
LM94:
	// total=3, vars=3
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=3
	bp=sp+1

	R1=BP+6
.debug
	.dw '.stabn 0x44,0,84,',0,0
	.dd LM95-_KeyScan
	.dw 0x0d,0x0a
.code
LM95:
LBB7:
.debug
	.dw '.stabn 0x44,0,86,',0,0
	.dd LM96-_KeyScan
	.dw 0x0d,0x0a
.code
LM96:
	R2=1	// QImode move
	[28690]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,87,',0,0
	.dd LM97-_KeyScan
	.dw 0x0d,0x0a
.code
LM97:
	R2=[28679]	// QImode move
	R3=R2&(-256)
	[28679]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,88,',0,0
	.dd LM98-_KeyScan
	.dw 0x0d,0x0a
.code
LM98:
	R2=[28680]	// QImode move
	R3=R2&(-256)
	[28680]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,89,',0,0
	.dd LM99-_KeyScan
	.dw 0x0d,0x0a
.code
LM99:
	R2=[28672]	// QImode move
	R3=R2&(-256)
	[28672]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,90,',0,0
	.dd LM100-_KeyScan
	.dw 0x0d,0x0a
.code
LM100:
	R2=[28677]	// QImode move
	[BP]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,92,',0,0
	.dd LM101-_KeyScan
	.dw 0x0d,0x0a
.code
LM101:
	R3=BP	// QImode move
	R2=BP+1
	R3=[BP]	// QImode move
	R4=R3^0xffff	// one_cmplqi2
	R3=R2	// QImode move
	[R3]=R4	// QImode move
.debug
	.dw '.stabn 0x44,0,93,',0,0
	.dd LM102-_KeyScan
	.dw 0x0d,0x0a
.code
LM102:
	R3=BP	// QImode move
	R2=BP+1
	R3=BP	// QImode move
	R4=BP+1
	[bp+2]=R4	// QImode move
	R3=[bp+2]	// QImode move
	R3=[R3]	// QImode move
	R4=R3&255
	R3=R2	// QImode move
	[R3]=R4	// QImode move
.debug
	.dw '.stabn 0x44,0,94,',0,0
	.dd LM103-_KeyScan
	.dw 0x0d,0x0a
.code
LM103:
	R2=BP	// QImode move
	R3=BP+1
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	CMP R2,0	// QImode test
	NSJZ L43	//QImode EQ
.debug
	.dw '.stabn 0x44,0,96,',0,0
	.dd LM104-_KeyScan
	.dw 0x0d,0x0a
.code
LM104:
	R2=BP	// QImode move
	R3=BP+1
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	CMP R2,8	// QImode compare
	NSJZ L51	//QImode EQ
	CMP R2,8	// QImode compare
	NSJG L60	//QImode GT
	CMP R2,2	// QImode compare
	NSJZ L55	//QImode EQ
	CMP R2,2	// QImode compare
	NSJG L61	//QImode GT
	CMP R2,1	// QImode compare
	NSJZ L57	//QImode EQ
	pc=L58	// Indirect jump
L61:
	CMP R2,4	// QImode compare
	NSJZ L53	//QImode EQ
	pc=L58	// Indirect jump
L60:
	CMP R2,32	// QImode compare
	NSJZ L48	//QImode EQ
	CMP R2,32	// QImode compare
	NSJG L62	//QImode GT
	CMP R2,16	// QImode compare
	NSJZ L50	//QImode EQ
	pc=L58	// Indirect jump
L62:
	CMP R2,64	// QImode compare
	NSJZ L47	//QImode EQ
	CMP R2,128	// QImode compare
	NSJZ L45	//QImode EQ
	pc=L58	// Indirect jump
L45:
.debug
	.dw '.stabn 0x44,0,99,',0,0
	.dd LM105-_KeyScan
	.dw 0x0d,0x0a
.code
LM105:
	R2=[_buffer]	// QImode move
	R3=1	// QImode move
	[_buffer]=R2+R3  //addqi3_Qrr
.debug
	.dw '.stabn 0x44,0,100,',0,0
	.dd LM106-_KeyScan
	.dw 0x0d,0x0a
.code
LM106:
	R2=[_buffer]	// QImode move
	CMP R2,7	// QImode compare
	NSJNZ L46	//QImode NE
.debug
	.dw '.stabn 0x44,0,101,',0,0
	.dd LM107-_KeyScan
	.dw 0x0d,0x0a
.code
LM107:
	R2=0	// QImode move
	[_buffer]=R2	// QImode move
L46:
.debug
	.dw '.stabn 0x44,0,102,',0,0
	.dd LM108-_KeyScan
	.dw 0x0d,0x0a
.code
LM108:
	pc=L43	// Indirect jump
L47:
.debug
	.dw '.stabn 0x44,0,104,',0,0
	.dd LM109-_KeyScan
	.dw 0x0d,0x0a
.code
LM109:
	R2=[_buffer+1]	// QImode move
	R3=1000	// QImode move
	[_buffer+1]=R2+R3  //addqi3_Qrr
.debug
	.dw '.stabn 0x44,0,105,',0,0
	.dd LM110-_KeyScan
	.dw 0x0d,0x0a
.code
LM110:
	pc=L43	// Indirect jump
L48:
.debug
	.dw '.stabn 0x44,0,107,',0,0
	.dd LM111-_KeyScan
	.dw 0x0d,0x0a
.code
LM111:
	R2=[_buffer+1]	// QImode move
	R3=(-1000)	// QImode move
	[_buffer+1]=R2+R3  //addqi3_Qrr
.debug
	.dw '.stabn 0x44,0,108,',0,0
	.dd LM112-_KeyScan
	.dw 0x0d,0x0a
.code
LM112:
	R2=[_buffer+1]	// QImode move
	CMP R2,0	// QImode test
	NSJNZ L49	//QImode NE
.debug
	.dw '.stabn 0x44,0,109,',0,0
	.dd LM113-_KeyScan
	.dw 0x0d,0x0a
.code
LM113:
	R2=0	// QImode move
	[_buffer+1]=R2	// QImode move
L49:
.debug
	.dw '.stabn 0x44,0,110,',0,0
	.dd LM114-_KeyScan
	.dw 0x0d,0x0a
.code
LM114:
	pc=L43	// Indirect jump
L50:
.debug
	.dw '.stabn 0x44,0,112,',0,0
	.dd LM115-_KeyScan
	.dw 0x0d,0x0a
.code
LM115:
	R2=[_buffer+1]	// QImode move
	R3=100	// QImode move
	[_buffer+1]=R2+R3  //addqi3_Qrr
.debug
	.dw '.stabn 0x44,0,113,',0,0
	.dd LM116-_KeyScan
	.dw 0x0d,0x0a
.code
LM116:
	pc=L43	// Indirect jump
L51:
.debug
	.dw '.stabn 0x44,0,115,',0,0
	.dd LM117-_KeyScan
	.dw 0x0d,0x0a
.code
LM117:
	R2=[_buffer+1]	// QImode move
	R3=(-100)	// QImode move
	[_buffer+1]=R2+R3  //addqi3_Qrr
.debug
	.dw '.stabn 0x44,0,116,',0,0
	.dd LM118-_KeyScan
	.dw 0x0d,0x0a
.code
LM118:
	R2=[_buffer+1]	// QImode move
	CMP R2,0	// QImode test
	NSJNZ L52	//QImode NE
.debug
	.dw '.stabn 0x44,0,117,',0,0
	.dd LM119-_KeyScan
	.dw 0x0d,0x0a
.code
LM119:
	R2=0	// QImode move
	[_buffer+1]=R2	// QImode move
L52:
.debug
	.dw '.stabn 0x44,0,118,',0,0
	.dd LM120-_KeyScan
	.dw 0x0d,0x0a
.code
LM120:
	pc=L43	// Indirect jump
L53:
.debug
	.dw '.stabn 0x44,0,120,',0,0
	.dd LM121-_KeyScan
	.dw 0x0d,0x0a
.code
LM121:
	R2=[_buffer+2]	// QImode move
	CMP R2,50	// QImode compare
	NSJNZ L54	//QImode NE
.debug
	.dw '.stabn 0x44,0,122,',0,0
	.dd LM122-_KeyScan
	.dw 0x0d,0x0a
.code
LM122:
	R2=0	// QImode move
	[_buffer+2]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,123,',0,0
	.dd LM123-_KeyScan
	.dw 0x0d,0x0a
.code
LM123:
	pc=L43	// Indirect jump
L54:
.debug
	.dw '.stabn 0x44,0,125,',0,0
	.dd LM124-_KeyScan
	.dw 0x0d,0x0a
.code
LM124:
	R2=[_buffer+2]	// QImode move
	R3=1	// QImode move
	[_buffer+2]=R2+R3  //addqi3_Qrr
.debug
	.dw '.stabn 0x44,0,126,',0,0
	.dd LM125-_KeyScan
	.dw 0x0d,0x0a
.code
LM125:
	pc=L43	// Indirect jump
L55:
.debug
	.dw '.stabn 0x44,0,128,',0,0
	.dd LM126-_KeyScan
	.dw 0x0d,0x0a
.code
LM126:
	R2=[_buffer+2]	// QImode move
	CMP R2,0	// QImode test
	NSJNZ L56	//QImode NE
.debug
	.dw '.stabn 0x44,0,130,',0,0
	.dd LM127-_KeyScan
	.dw 0x0d,0x0a
.code
LM127:
	R2=50	// QImode move
	[_buffer+2]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,131,',0,0
	.dd LM128-_KeyScan
	.dw 0x0d,0x0a
.code
LM128:
	pc=L43	// Indirect jump
L56:
.debug
	.dw '.stabn 0x44,0,133,',0,0
	.dd LM129-_KeyScan
	.dw 0x0d,0x0a
.code
LM129:
	R2=[_buffer+2]	// QImode move
	R3=(-1)	// QImode move
	[_buffer+2]=R2+R3  //addqi3_Qrr
.debug
	.dw '.stabn 0x44,0,134,',0,0
	.dd LM130-_KeyScan
	.dw 0x0d,0x0a
.code
LM130:
	pc=L43	// Indirect jump
L57:
.debug
	.dw '.stabn 0x44,0,136,',0,0
	.dd LM131-_KeyScan
	.dw 0x0d,0x0a
.code
LM131:
	R2=[_buffer+3]	// QImode move
	R3=1	// QImode move
	[_buffer+3]=R2+R3  //addqi3_Qrr
L58:
.debug
	.dw '.stabn 0x44,0,138,',0,0
	.dd LM132-_KeyScan
	.dw 0x0d,0x0a
.code
LM132:
	pc=L43	// Indirect jump
L44:
L43:
.debug
	.dw '.stabn 0x44,0,142,',0,0
	.dd LM133-_KeyScan
	.dw 0x0d,0x0a
.code
LM133:
LBE7:
.debug
	.dw '.stabn 0x44,0,142,',0,0
	.dd LM134-_KeyScan
	.dw 0x0d,0x0a
.code
LM134:
L42:

	sp+=3
	pop bp from [sp]
	retf
	.endp	// end of KeyScan

.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB7-_KeyScan
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "KeyTemp:1",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "Value:1",128,0,0,1',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE7-_KeyScan
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME7-_KeyScan
	.dw 0x0d,0x0a
.code
LME7:
.code
.debug
	.dw '.stabs "UNDO:F19",36,0,0,',0,0,offset _UNDO,seg _UNDO,0x0d,0x0a
.CODE
.public _UNDO
_UNDO:	.proc
.debug
	.dw '.stabn 0x44,0,144,',0,0
	.dd LM135-_UNDO
	.dw 0x0d,0x0a
.code
LM135:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,145,',0,0
	.dd LM136-_UNDO
	.dw 0x0d,0x0a
.code
LM136:
	call _KeyScan	// call without return value
.debug
	.dw '.stabn 0x44,0,146,',0,0
	.dd LM137-_UNDO
	.dw 0x0d,0x0a
.code
LM137:
	call _delay	// call without return value
.debug
	.dw '.stabn 0x44,0,147,',0,0
	.dd LM138-_UNDO
	.dw 0x0d,0x0a
.code
LM138:
	R1=[_buffer+2]	// QImode move
	[SP--]=R1	// QImode move
	R1=[_buffer+1]	// QImode move
	[SP--]=R1	// QImode move
	R1=[_buffer]	// QImode move
	[SP--]=R1	// QImode move
	call _show	// call without return value
	SP = SP + 3	//SP
.debug
	.dw '.stabn 0x44,0,150,',0,0
	.dd LM139-_UNDO
	.dw 0x0d,0x0a
.code
LM139:
	R1=[_buffer+1]	// QImode move
	CMP R1,200	// QImode compare
	NSJZ L83	//QImode EQ
	CMP R1,200	// QImode compare
	NSJA L88	//QImode GTU
	CMP R1,100	// QImode compare
	NSJZ L82	//QImode EQ
	pc=L86	// Indirect jump
L88:
	CMP R1,300	// QImode compare
	NSJZ L84	//QImode EQ
	CMP R1,500	// QImode compare
	NSJZ L85	//QImode EQ
	pc=L86	// Indirect jump
.debug
	.dw '.stabn 0x44,0,152,',0,0
	.dd LM140-_UNDO
	.dw 0x0d,0x0a
.code
LM140:
	R1=1	// QImode move
	[28690]=R1	// QImode move
L82:
.debug
	.dw '.stabn 0x44,0,154,',0,0
	.dd LM141-_UNDO
	.dw 0x0d,0x0a
.code
LM141:
	R1=(-5)	// QImode move
	[28682]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,155,',0,0
	.dd LM142-_UNDO
	.dw 0x0d,0x0a
.code
LM142:
	pc=L81	// Indirect jump
L83:
.debug
	.dw '.stabn 0x44,0,158,',0,0
	.dd LM143-_UNDO
	.dw 0x0d,0x0a
.code
LM143:
	R1=(-4)	// QImode move
	[28682]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,159,',0,0
	.dd LM144-_UNDO
	.dw 0x0d,0x0a
.code
LM144:
	pc=L81	// Indirect jump
L84:
.debug
	.dw '.stabn 0x44,0,161,',0,0
	.dd LM145-_UNDO
	.dw 0x0d,0x0a
.code
LM145:
	R1=(-3)	// QImode move
	[28682]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,162,',0,0
	.dd LM146-_UNDO
	.dw 0x0d,0x0a
.code
LM146:
	pc=L81	// Indirect jump
L85:
.debug
	.dw '.stabn 0x44,0,164,',0,0
	.dd LM147-_UNDO
	.dw 0x0d,0x0a
.code
LM147:
	R1=(-2)	// QImode move
	[28682]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,165,',0,0
	.dd LM148-_UNDO
	.dw 0x0d,0x0a
.code
LM148:
	pc=L81	// Indirect jump
L86:
.debug
	.dw '.stabn 0x44,0,167,',0,0
	.dd LM149-_UNDO
	.dw 0x0d,0x0a
.code
LM149:
	R1=(-1)	// QImode move
	[28682]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,168,',0,0
	.dd LM150-_UNDO
	.dw 0x0d,0x0a
.code
LM150:
	pc=L81	// Indirect jump
L81:
.debug
	.dw '.stabn 0x44,0,170,',0,0
	.dd LM151-_UNDO
	.dw 0x0d,0x0a
.code
LM151:
.debug
	.dw '.stabn 0x44,0,170,',0,0
	.dd LM152-_UNDO
	.dw 0x0d,0x0a
.code
LM152:
L80:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of UNDO

.debug
	.dw '.stabf ',0,0
	.dd LME8-_UNDO
	.dw 0x0d,0x0a
.code
LME8:
.code
.debug
	.dw '.stabs "Juxing:F19",36,0,0,',0,0,offset _Juxing,seg _Juxing,0x0d,0x0a
.CODE
.public _Juxing
_Juxing:	.proc
.debug
	.dw '.stabn 0x44,0,172,',0,0
	.dd LM153-_Juxing
	.dw 0x0d,0x0a
.code
LM153:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,174,',0,0
	.dd LM154-_Juxing
	.dw 0x0d,0x0a
.code
LM154:
	R2=[_buffer+5]	// QImode move
	R3=1	// QImode move
	[_buffer+5]=R2+R3  //addqi3_Qrr
.debug
	.dw '.stabn 0x44,0,175,',0,0
	.dd LM155-_Juxing
	.dw 0x0d,0x0a
.code
LM155:
// GCC inline ASM start
	INT IRQ
// GCC inline ASM end
.debug
	.dw '.stabn 0x44,0,178,',0,0
	.dd LM156-_Juxing
	.dw 0x0d,0x0a
.code
LM156:
.debug
	.dw '.stabn 0x44,0,178,',0,0
	.dd LM157-_Juxing
	.dw 0x0d,0x0a
.code
LM157:
L94:

	pop bp from [sp]
	retf
	.endp	// end of Juxing

.debug
	.dw '.stabf ',0,0
	.dd LME9-_Juxing
	.dw 0x0d,0x0a
.code
LME9:
.code
.debug
	.dw '.stabs "Sanjiao:F19",36,0,0,',0,0,offset _Sanjiao,seg _Sanjiao,0x0d,0x0a
.CODE
.public _Sanjiao
_Sanjiao:	.proc
.debug
	.dw '.stabn 0x44,0,180,',0,0
	.dd LM158-_Sanjiao
	.dw 0x0d,0x0a
.code
LM158:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,181,',0,0
	.dd LM159-_Sanjiao
	.dw 0x0d,0x0a
.code
LM159:
	R2=[_buffer+5]	// QImode move
	R3=1	// QImode move
	[_buffer+5]=R2+R3  //addqi3_Qrr
.debug
	.dw '.stabn 0x44,0,182,',0,0
	.dd LM160-_Sanjiao
	.dw 0x0d,0x0a
.code
LM160:
// GCC inline ASM start
	INT IRQ
// GCC inline ASM end
.debug
	.dw '.stabn 0x44,0,184,',0,0
	.dd LM161-_Sanjiao
	.dw 0x0d,0x0a
.code
LM161:
.debug
	.dw '.stabn 0x44,0,184,',0,0
	.dd LM162-_Sanjiao
	.dw 0x0d,0x0a
.code
LM162:
L95:

	pop bp from [sp]
	retf
	.endp	// end of Sanjiao

.debug
	.dw '.stabf ',0,0
	.dd LME10-_Sanjiao
	.dw 0x0d,0x0a
.code
LME10:
.code
.debug
	.dw '.stabs "Zhengxian:F19",36,0,0,',0,0,offset _Zhengxian,seg _Zhengxian,0x0d,0x0a
.CODE
.public _Zhengxian
_Zhengxian:	.proc
.debug
	.dw '.stabn 0x44,0,186,',0,0
	.dd LM163-_Zhengxian
	.dw 0x0d,0x0a
.code
LM163:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,186,',0,0
	.dd LM164-_Zhengxian
	.dw 0x0d,0x0a
.code
LM164:
	R2=[_buffer+5]	// QImode move
	R3=1	// QImode move
	[_buffer+5]=R2+R3  //addqi3_Qrr
.debug
	.dw '.stabn 0x44,0,187,',0,0
	.dd LM165-_Zhengxian
	.dw 0x0d,0x0a
.code
LM165:
// GCC inline ASM start
	INT IRQ
// GCC inline ASM end
.debug
	.dw '.stabn 0x44,0,189,',0,0
	.dd LM166-_Zhengxian
	.dw 0x0d,0x0a
.code
LM166:
.debug
	.dw '.stabn 0x44,0,189,',0,0
	.dd LM167-_Zhengxian
	.dw 0x0d,0x0a
.code
LM167:
L96:

	pop bp from [sp]
	retf
	.endp	// end of Zhengxian

.debug
	.dw '.stabf ',0,0
	.dd LME11-_Zhengxian
	.dw 0x0d,0x0a
.code
LME11:
.code
.debug
	.dw '.stabs "Tiejia:F19",36,0,0,',0,0,offset _Tiejia,seg _Tiejia,0x0d,0x0a
.CODE
.public _Tiejia
_Tiejia:	.proc
.debug
	.dw '.stabn 0x44,0,191,',0,0
	.dd LM168-_Tiejia
	.dw 0x0d,0x0a
.code
LM168:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,192,',0,0
	.dd LM169-_Tiejia
	.dw 0x0d,0x0a
.code
LM169:
// GCC inline ASM start
	INT IRQ
// GCC inline ASM end
.debug
	.dw '.stabn 0x44,0,193,',0,0
	.dd LM170-_Tiejia
	.dw 0x0d,0x0a
.code
LM170:
.debug
	.dw '.stabn 0x44,0,193,',0,0
	.dd LM171-_Tiejia
	.dw 0x0d,0x0a
.code
LM171:
L97:

	pop bp from [sp]
	retf
	.endp	// end of Tiejia

.debug
	.dw '.stabf ',0,0
	.dd LME12-_Tiejia
	.dw 0x0d,0x0a
.code
LME12:
.code
.debug
	.dw '.stabs "Boxing:F19",36,0,0,',0,0,offset _Boxing,seg _Boxing,0x0d,0x0a
.CODE
.public _Boxing
_Boxing:	.proc
.debug
	.dw '.stabn 0x44,0,209,',0,0
	.dd LM172-_Boxing
	.dw 0x0d,0x0a
.code
LM172:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,210,',0,0
	.dd LM173-_Boxing
	.dw 0x0d,0x0a
.code
LM173:
	R1=[_buffer]	// QImode move
	CMP R1,1	// QImode compare
	NSJZ L101	//QImode EQ
	CMP R1,1	// QImode compare
	NSJB L100	//QImode LTU
	CMP R1,2	// QImode compare
	NSJZ L102	//QImode EQ
	pc=L103	// Indirect jump
.debug
	.dw '.stabn 0x44,0,212,',0,0
	.dd LM174-_Boxing
	.dw 0x0d,0x0a
.code
LM174:
	R1=1	// QImode move
	[28690]=R1	// QImode move
L100:
.debug
	.dw '.stabn 0x44,0,214,',0,0
	.dd LM175-_Boxing
	.dw 0x0d,0x0a
.code
LM175:
	call _Juxing	// call without return value
.debug
	.dw '.stabn 0x44,0,215,',0,0
	.dd LM176-_Boxing
	.dw 0x0d,0x0a
.code
LM176:
	pc=L99	// Indirect jump
L101:
.debug
	.dw '.stabn 0x44,0,217,',0,0
	.dd LM177-_Boxing
	.dw 0x0d,0x0a
.code
LM177:
	call _Sanjiao	// call without return value
.debug
	.dw '.stabn 0x44,0,218,',0,0
	.dd LM178-_Boxing
	.dw 0x0d,0x0a
.code
LM178:
	pc=L99	// Indirect jump
L102:
.debug
	.dw '.stabn 0x44,0,220,',0,0
	.dd LM179-_Boxing
	.dw 0x0d,0x0a
.code
LM179:
	call _Zhengxian	// call without return value
.debug
	.dw '.stabn 0x44,0,221,',0,0
	.dd LM180-_Boxing
	.dw 0x0d,0x0a
.code
LM180:
	pc=L99	// Indirect jump
L103:
.debug
	.dw '.stabn 0x44,0,224,',0,0
	.dd LM181-_Boxing
	.dw 0x0d,0x0a
.code
LM181:
	call _Tiejia	// call without return value
.debug
	.dw '.stabn 0x44,0,225,',0,0
	.dd LM182-_Boxing
	.dw 0x0d,0x0a
.code
LM182:
	pc=L99	// Indirect jump
L99:
.debug
	.dw '.stabn 0x44,0,227,',0,0
	.dd LM183-_Boxing
	.dw 0x0d,0x0a
.code
LM183:
.debug
	.dw '.stabn 0x44,0,227,',0,0
	.dd LM184-_Boxing
	.dw 0x0d,0x0a
.code
LM184:
L98:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of Boxing

.debug
	.dw '.stabf ',0,0
	.dd LME13-_Boxing
	.dw 0x0d,0x0a
.code
LME13:
.code
.debug
	.dw '.stabs "main:F1",36,0,0,',0,0,offset _main,seg _main,0x0d,0x0a
.CODE
.public _main
_main:	.proc
.debug
	.dw '.stabn 0x44,0,230,',0,0
	.dd LM185-_main
	.dw 0x0d,0x0a
.code
LM185:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,232,',0,0
	.dd LM186-_main
	.dw 0x0d,0x0a
.code
LM186:
// GCC inline ASM start
	INT OFF
// GCC inline ASM end
.debug
	.dw '.stabn 0x44,0,235,',0,0
	.dd LM187-_main
	.dw 0x0d,0x0a
.code
LM187:
	R1=4096	// QImode move
	[28688]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,236,',0,0
	.dd LM188-_main
	.dw 0x0d,0x0a
.code
LM188:
	R1=49	// QImode move
	[28683]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,238,',0,0
	.dd LM189-_main
	.dw 0x0d,0x0a
.code
LM189:
	call _init7219	// call without return value
.debug
	.dw '.stabn 0x44,0,239,',0,0
	.dd LM190-_main
	.dw 0x0d,0x0a
.code
LM190:
	R1=0	// QImode move
	[28714]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,241,',0,0
	.dd LM191-_main
	.dw 0x0d,0x0a
.code
LM191:
L109:
	pc=L111	// Indirect jump
	pc=L110	// Indirect jump
L111:
.debug
	.dw '.stabn 0x44,0,244,',0,0
	.dd LM192-_main
	.dw 0x0d,0x0a
.code
LM192:
	R1=[_buffer+3]	// QImode move
	R2=R1&1
	CMP R2,0	// QImode test
	NSJZ L112	//QImode EQ
.debug
	.dw '.stabn 0x44,0,246,',0,0
	.dd LM193-_main
	.dw 0x0d,0x0a
.code
LM193:
	R1=6	// QImode move
	[28691]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,247,',0,0
	.dd LM194-_main
	.dw 0x0d,0x0a
.code
LM194:
	call _UNDO	// call without return value
.debug
	.dw '.stabn 0x44,0,248,',0,0
	.dd LM195-_main
	.dw 0x0d,0x0a
.code
LM195:
	pc=L113	// Indirect jump
L112:
.debug
	.dw '.stabn 0x44,0,251,',0,0
	.dd LM196-_main
	.dw 0x0d,0x0a
.code
LM196:
	R1=128	// QImode move
	[28691]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,252,',0,0
	.dd LM197-_main
	.dw 0x0d,0x0a
.code
LM197:
	call _Boxing	// call without return value
.debug
	.dw '.stabn 0x44,0,255,',0,0
	.dd LM198-_main
	.dw 0x0d,0x0a
.code
LM198:
	R1=[_buffer+4]	// QImode move
	[28695]=R1	// QImode move
L113:
.debug
	.dw '.stabn 0x44,0,258,',0,0
	.dd LM199-_main
	.dw 0x0d,0x0a
.code
LM199:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,260,',0,0
	.dd LM200-_main
	.dw 0x0d,0x0a
.code
LM200:
	pc=L109	// Indirect jump
L110:
.debug
	.dw '.stabn 0x44,0,261,',0,0
	.dd LM201-_main
	.dw 0x0d,0x0a
.code
LM201:
.debug
	.dw '.stabn 0x44,0,261,',0,0
	.dd LM202-_main
	.dw 0x0d,0x0a
.code
LM202:
L108:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of main

.debug
	.dw '.stabf ',0,0
	.dd LME14-_main
	.dw 0x0d,0x0a
.code
LME14:
.external __divu1
.external __modi1
.external __divi1
	.end

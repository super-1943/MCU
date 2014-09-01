// GCC for SUNPLUS u'nSP version 1.0.21-3
// Command: C:\PROGRA~1\Sunplus\UNSPID~1.0\cc1.exe C:\DOCUME~1\ADMINI~1\LOCALS~1\Temp\ccGcbaaa.i -fkeep-inline-functions -quiet -dumpbase main.c -mglobal-var-iram -gstabs -Wall -o .\Debug/main.asm
	.external __sn_func_ptr_sec

// gcc2_compiled.:

.debug
	.dw '.stabs "E:/zhaoyongke/Demo/Receive/",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
.code
.debug
	.dw '.stabs "E:/zhaoyongke/Demo/Receive/main.c",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
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
.debug
	.dw '.stabs "RxBuf:G20=ar1;0;24;4",32,0,0,',0,0,offset _RxBuf,seg _RxBuf,0x0d,0x0a
.CODE
.code
.debug
	.dw '.stabs "main:F1",36,0,0,',0,0,offset _main,seg _main,0x0d,0x0a
.CODE
.public _main
_main:	.proc
.debug
	.dw '.stabn 0x44,0,39,',0,0
	.dd LM1-_main
	.dw 0x0d,0x0a
.code
LM1:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,40,',0,0
	.dd LM2-_main
	.dw 0x0d,0x0a
.code
LM2:
	call _nRF2401_Initial	// call without return value
.debug
	.dw '.stabn 0x44,0,41,',0,0
	.dd LM3-_main
	.dw 0x0d,0x0a
.code
LM3:
	R1=0	// QImode move
	[SP--]=R1	// QImode move
	call _nRF2401_Mode	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,42,',0,0
	.dd LM4-_main
	.dw 0x0d,0x0a
.code
LM4:
	R1=(-256)	// QImode move
	[28674]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,43,',0,0
	.dd LM5-_main
	.dw 0x0d,0x0a
.code
LM5:
	R1=(-256)	// QImode move
	[28675]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,44,',0,0
	.dd LM6-_main
	.dw 0x0d,0x0a
.code
LM6:
	R1=(-256)	// QImode move
	[28672]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,45,',0,0
	.dd LM7-_main
	.dw 0x0d,0x0a
.code
LM7:
	R1=[28679]	// QImode move
	R2=R1|(-256)
	[28679]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,46,',0,0
	.dd LM8-_main
	.dw 0x0d,0x0a
.code
LM8:
	R1=[28680]	// QImode move
	R2=R1|(-256)
	[28680]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,47,',0,0
	.dd LM9-_main
	.dw 0x0d,0x0a
.code
LM9:
	R1=[28677]	// QImode move
	R2=R1|(-256)
	[28677]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,48,',0,0
	.dd LM10-_main
	.dw 0x0d,0x0a
.code
LM10:
L3:
	pc=L5	// Indirect jump
	pc=L4	// Indirect jump
L5:
.debug
	.dw '.stabn 0x44,0,50,',0,0
	.dd LM11-_main
	.dw 0x0d,0x0a
.code
LM11:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,51,',0,0
	.dd LM12-_main
	.dw 0x0d,0x0a
.code
LM12:
	call _getkey	// call without return value
.debug
	.dw '.stabn 0x44,0,52,',0,0
	.dd LM13-_main
	.dw 0x0d,0x0a
.code
LM13:
	R1=8	// QImode move
	[SP--]=R1	// QImode move
	R1=_RxBuf	// QImode move
	[SP--]=R1	// QImode move
	call _show	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,53,',0,0
	.dd LM14-_main
	.dw 0x0d,0x0a
.code
LM14:
	call _nRF2401_RxStatus	// call with return value
	CMP R1,1	// QImode compare
	NSJNZ L6	//QImode NE
.debug
	.dw '.stabn 0x44,0,55,',0,0
	.dd LM15-_main
	.dw 0x0d,0x0a
.code
LM15:
	R1=_RxBuf	// QImode move
	[SP--]=R1	// QImode move
	call _nRF2401_ReceiveByte	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,56,',0,0
	.dd LM16-_main
	.dw 0x0d,0x0a
.code
LM16:
	R1=[_RxBuf]	// QImode move
	CMP R1,2	// QImode compare
	NSJZ L9	//QImode EQ
	CMP R1,2	// QImode compare
	NSJA L13	//QImode GTU
	CMP R1,1	// QImode compare
	NSJZ L8	//QImode EQ
	pc=L11	// Indirect jump
L13:
	CMP R1,3	// QImode compare
	NSJZ L10	//QImode EQ
	pc=L11	// Indirect jump
L8:
.debug
	.dw '.stabn 0x44,0,59,',0,0
	.dd LM17-_main
	.dw 0x0d,0x0a
.code
LM17:
	R1=0	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,60,',0,0
	.dd LM18-_main
	.dw 0x0d,0x0a
.code
LM18:
	pc=L6	// Indirect jump
L9:
.debug
	.dw '.stabn 0x44,0,62,',0,0
	.dd LM19-_main
	.dw 0x0d,0x0a
.code
LM19:
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,63,',0,0
	.dd LM20-_main
	.dw 0x0d,0x0a
.code
LM20:
	pc=L6	// Indirect jump
L10:
.debug
	.dw '.stabn 0x44,0,65,',0,0
	.dd LM21-_main
	.dw 0x0d,0x0a
.code
LM21:
	R1=2	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,66,',0,0
	.dd LM22-_main
	.dw 0x0d,0x0a
.code
LM22:
	pc=L6	// Indirect jump
L11:
.debug
	.dw '.stabn 0x44,0,68,',0,0
	.dd LM23-_main
	.dw 0x0d,0x0a
.code
LM23:
	pc=L6	// Indirect jump
L7:
L6:
.debug
	.dw '.stabn 0x44,0,71,',0,0
	.dd LM24-_main
	.dw 0x0d,0x0a
.code
LM24:
	pc=L3	// Indirect jump
L4:
.debug
	.dw '.stabn 0x44,0,72,',0,0
	.dd LM25-_main
	.dw 0x0d,0x0a
.code
LM25:
.debug
	.dw '.stabn 0x44,0,72,',0,0
	.dd LM26-_main
	.dw 0x0d,0x0a
.code
LM26:
L2:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of main

.debug
	.dw '.stabf ',0,0
	.dd LME1-_main
	.dw 0x0d,0x0a
.code
LME1:
.iram
.public _RxBuf
_RxBuf:
	.dw 25 dup(0)
.external _PlaySnd
.external _nRF2401_ReceiveByte
.external _nRF2401_RxStatus
.external _show
.external _getkey
.external _nRF2401_Mode
.external _nRF2401_Initial
	.end

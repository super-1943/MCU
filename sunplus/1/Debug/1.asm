// GCC for SUNPLUS u'nSP version 1.0.21-3
// Command: C:\Elecs\Sunplus\UNSPID~1.0\cc1.exe C:\DOCUME~1\ZHAOYO~1\LOCALS~1\Temp\ccYvaaaa.i -fkeep-inline-functions -quiet -dumpbase 1.c -mglobal-var-iram -gstabs -Wall -o .\Debug/1.asm
	.external __sn_func_ptr_sec

// gcc2_compiled.:

.debug
	.dw '.stabs "C:/Documents and Settings/zhaoyongke/My Documents/myproject/Sunplus/1/",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
.code
.debug
	.dw '.stabs "C:/Documents and Settings/zhaoyongke/My Documents/myproject/Sunplus/1/1.c",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
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
	.dw '.stabs "main:F1",36,0,0,',0,0,offset _main,seg _main,0x0d,0x0a
.CODE
.public _main
_main:	.proc
.debug
	.dw '.stabn 0x44,0,3,',0,0
	.dd LM1-_main
	.dw 0x0d,0x0a
.code
LM1:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,4,',0,0
	.dd LM2-_main
	.dw 0x0d,0x0a
.code
LM2:
	R2=(-1)	// QImode move
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,5,',0,0
	.dd LM3-_main
	.dw 0x0d,0x0a
.code
LM3:
	R2=0	// QImode move
	[28675]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,6,',0,0
	.dd LM4-_main
	.dw 0x0d,0x0a
.code
LM4:
	R2=(-1)	// QImode move
	[28674]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,7,',0,0
	.dd LM5-_main
	.dw 0x0d,0x0a
.code
LM5:
L3:
	pc=L5	// Indirect jump
	pc=L4	// Indirect jump
L5:
.debug
	.dw '.stabn 0x44,0,8,',0,0
	.dd LM6-_main
	.dw 0x0d,0x0a
.code
LM6:
	R2=1	// QImode move
	[28690]=R2	// QImode move
	pc=L3	// Indirect jump
L4:
.debug
	.dw '.stabn 0x44,0,9,',0,0
	.dd LM7-_main
	.dw 0x0d,0x0a
.code
LM7:
.debug
	.dw '.stabn 0x44,0,9,',0,0
	.dd LM8-_main
	.dw 0x0d,0x0a
.code
LM8:
L2:

	pop bp from [sp]
	retf
	.endp	// end of main

.debug
	.dw '.stabf ',0,0
	.dd LME1-_main
	.dw 0x0d,0x0a
.code
LME1:
	.end

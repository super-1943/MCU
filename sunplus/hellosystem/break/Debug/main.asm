// GCC for SUNPLUS u'nSP version 1.0.21-3
// Command: C:\PROGRA~1\Sunplus\UNSPID~1.0\cc1.exe C:\DOCUME~1\ADMINI~1\LOCALS~1\Temp\ccSIaaaa.i -fkeep-inline-functions -quiet -dumpbase main.c -mglobal-var-iram -gstabs -Wall -o .\Debug/main.asm
	.external __sn_func_ptr_sec

// gcc2_compiled.:

.debug
	.dw '.stabs "D:/break/",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
.code
.debug
	.dw '.stabs "D:/break/main.c",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
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
.public _flag
.iram
_flag:
	.dw 1
.debug
	.dw '.stabs "flag:G11",32,0,0,',0,0,offset _flag,seg _flag,0x0d,0x0a
.CODE
.code
.debug
	.dw '.stabs "fun:F19",36,0,0,',0,0,offset _fun,seg _fun,0x0d,0x0a
.CODE
.public _fun
_fun:	.proc
.debug
	.dw '.stabn 0x44,0,7,',0,0
	.dd LM1-_fun
	.dw 0x0d,0x0a
.code
LM1:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,8,',0,0
	.dd LM2-_fun
	.dw 0x0d,0x0a
.code
LM2:
L3:
	pc=L5	// Indirect jump
	pc=L4	// Indirect jump
L5:
.debug
	.dw '.stabn 0x44,0,10,',0,0
	.dd LM3-_fun
	.dw 0x0d,0x0a
.code
LM3:
	R2=1	// QImode move
	[28690]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,11,',0,0
	.dd LM4-_fun
	.dw 0x0d,0x0a
.code
LM4:
	R2=1	// QImode move
	[_flag]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,12,',0,0
	.dd LM5-_fun
	.dw 0x0d,0x0a
.code
LM5:
// GCC inline ASM start
	break
// GCC inline ASM end
.debug
	.dw '.stabn 0x44,0,13,',0,0
	.dd LM6-_fun
	.dw 0x0d,0x0a
.code
LM6:
	pc=L3	// Indirect jump
L4:
.debug
	.dw '.stabn 0x44,0,14,',0,0
	.dd LM7-_fun
	.dw 0x0d,0x0a
.code
LM7:
.debug
	.dw '.stabn 0x44,0,14,',0,0
	.dd LM8-_fun
	.dw 0x0d,0x0a
.code
LM8:
L2:

	pop bp from [sp]
	retf
	.endp	// end of fun

.debug
	.dw '.stabf ',0,0
	.dd LME1-_fun
	.dw 0x0d,0x0a
.code
LME1:
.code
.debug
	.dw '.stabs "fun2:F19",36,0,0,',0,0,offset _fun2,seg _fun2,0x0d,0x0a
.CODE
.public _fun2
_fun2:	.proc
.debug
	.dw '.stabn 0x44,0,16,',0,0
	.dd LM9-_fun2
	.dw 0x0d,0x0a
.code
LM9:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,17,',0,0
	.dd LM10-_fun2
	.dw 0x0d,0x0a
.code
LM10:
L7:
	pc=L9	// Indirect jump
	pc=L8	// Indirect jump
L9:
.debug
	.dw '.stabn 0x44,0,19,',0,0
	.dd LM11-_fun2
	.dw 0x0d,0x0a
.code
LM11:
	R2=1	// QImode move
	[28690]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,20,',0,0
	.dd LM12-_fun2
	.dw 0x0d,0x0a
.code
LM12:
	R2=2	// QImode move
	[_flag]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,21,',0,0
	.dd LM13-_fun2
	.dw 0x0d,0x0a
.code
LM13:
// GCC inline ASM start
	break
// GCC inline ASM end
.debug
	.dw '.stabn 0x44,0,22,',0,0
	.dd LM14-_fun2
	.dw 0x0d,0x0a
.code
LM14:
	pc=L7	// Indirect jump
L8:
.debug
	.dw '.stabn 0x44,0,23,',0,0
	.dd LM15-_fun2
	.dw 0x0d,0x0a
.code
LM15:
.debug
	.dw '.stabn 0x44,0,23,',0,0
	.dd LM16-_fun2
	.dw 0x0d,0x0a
.code
LM16:
L6:

	pop bp from [sp]
	retf
	.endp	// end of fun2

.debug
	.dw '.stabf ',0,0
	.dd LME2-_fun2
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
	.dw '.stabn 0x44,0,25,',0,0
	.dd LM17-_main
	.dw 0x0d,0x0a
.code
LM17:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,26,',0,0
	.dd LM18-_main
	.dw 0x0d,0x0a
.code
LM18:
	call _fun	// call without return value
.debug
	.dw '.stabn 0x44,0,27,',0,0
	.dd LM19-_main
	.dw 0x0d,0x0a
.code
LM19:
.debug
	.dw '.stabn 0x44,0,27,',0,0
	.dd LM20-_main
	.dw 0x0d,0x0a
.code
LM20:
L10:

	sp+=1
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

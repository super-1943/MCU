// GCC for SUNPLUS u'nSP version 1.0.21-3
// Command: C:\PROGRA~1\Sunplus\UNSPID~1.0\cc1.exe C:\DOCUME~1\ADMINI~1\LOCALS~1\Temp\ccs3aaaa.i -fkeep-inline-functions -quiet -dumpbase nzj.c -mglobal-var-iram -gstabs -Wall -o .\Debug/nzj.asm
	.external __sn_func_ptr_sec

// gcc2_compiled.:

.debug
	.dw '.stabs "G:/hellosystem/",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
.code
.debug
	.dw '.stabs "G:/hellosystem/nzj.c",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
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
	.dw '.stabs "stack1:G20=ar1;0;19;11",32,0,0,',0,0,offset _stack1,seg _stack1,0x0d,0x0a
.CODE
.debug
	.dw '.stabs "stack2:G20",32,0,0,',0,0,offset _stack2,seg _stack2,0x0d,0x0a
.CODE
.debug
	.dw '.stabs "pstack:G21=*11",32,0,0,',0,0,offset _pstack,seg _pstack,0x0d,0x0a
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
	.dw '.stabs "taskcreate:F19",36,0,0,',0,0,offset _taskcreate,seg _taskcreate,0x0d,0x0a
.CODE
.public _taskcreate
_taskcreate:	.proc
.debug
	.dw '.stabn 0x44,0,9,',0,0
	.dd LM1-_taskcreate
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
	.dw '.stabn 0x44,0,10,',0,0
	.dd LM2-_taskcreate
	.dw 0x0d,0x0a
.code
LM2:
	R2=_pstack	// QImode move
	[bp+1]=R2	// QImode move
	R4=[bp+1]	// QImode move
	R3=[R4]	// QImode move
	R2=R1	// QImode move
	R2=[R2]	// QImode move
	[BP]=R2	// QImode move
	R4=[BP]	// QImode move
	R2=R3	// QImode move
	[R2]=R4	// QImode move
	R3=R3+(-1)
	R4=[bp+1]	// QImode move
	[R4]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,11,',0,0
	.dd LM3-_taskcreate
	.dw 0x0d,0x0a
.code
LM3:
	R2=_pstack	// QImode move
	[bp+1]=R2	// QImode move
	R4=[bp+1]	// QImode move
	R3=[R4]	// QImode move
	R2=0	// QImode move
	[BP]=R2	// QImode move
	R4=[BP]	// QImode move
	R2=R3	// QImode move
	[R2]=R4	// QImode move
	R3=R3+(-1)
	R4=[bp+1]	// QImode move
	[R4]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,12,',0,0
	.dd LM4-_taskcreate
	.dw 0x0d,0x0a
.code
LM4:
// GCC inline ASM start
	sp=_pstack
// GCC inline ASM end
.debug
	.dw '.stabn 0x44,0,13,',0,0
	.dd LM5-_taskcreate
	.dw 0x0d,0x0a
.code
LM5:
.debug
	.dw '.stabn 0x44,0,13,',0,0
	.dd LM6-_taskcreate
	.dw 0x0d,0x0a
.code
LM6:
L2:

	sp+=2
	pop bp from [sp]
	retf
	.endp	// end of taskcreate

.debug
	.dw '.stabs "fun:p22=*23=f19",160,0,0,5',0x0d,0x0a
.CODE
.debug
	.dw '.stabf ',0,0
	.dd LME1-_taskcreate
	.dw 0x0d,0x0a
.code
LME1:
.code
.debug
	.dw '.stabs "fun1:F19",36,0,0,',0,0,offset _fun1,seg _fun1,0x0d,0x0a
.CODE
.public _fun1
_fun1:	.proc
.debug
	.dw '.stabn 0x44,0,16,',0,0
	.dd LM7-_fun1
	.dw 0x0d,0x0a
.code
LM7:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,17,',0,0
	.dd LM8-_fun1
	.dw 0x0d,0x0a
.code
LM8:
L4:
	pc=L6	// Indirect jump
	pc=L5	// Indirect jump
L6:
.debug
	.dw '.stabn 0x44,0,19,',0,0
	.dd LM9-_fun1
	.dw 0x0d,0x0a
.code
LM9:
	R2=1	// QImode move
	[28690]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,20,',0,0
	.dd LM10-_fun1
	.dw 0x0d,0x0a
.code
LM10:
	R2=1	// QImode move
	[_flag]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,21,',0,0
	.dd LM11-_fun1
	.dw 0x0d,0x0a
.code
LM11:
// GCC inline ASM start
	break
// GCC inline ASM end
.debug
	.dw '.stabn 0x44,0,22,',0,0
	.dd LM12-_fun1
	.dw 0x0d,0x0a
.code
LM12:
	pc=L4	// Indirect jump
L5:
.debug
	.dw '.stabn 0x44,0,23,',0,0
	.dd LM13-_fun1
	.dw 0x0d,0x0a
.code
LM13:
.debug
	.dw '.stabn 0x44,0,23,',0,0
	.dd LM14-_fun1
	.dw 0x0d,0x0a
.code
LM14:
L3:

	pop bp from [sp]
	retf
	.endp	// end of fun1

.debug
	.dw '.stabf ',0,0
	.dd LME2-_fun1
	.dw 0x0d,0x0a
.code
LME2:
.code
.debug
	.dw '.stabs "fun2:F19",36,0,0,',0,0,offset _fun2,seg _fun2,0x0d,0x0a
.CODE
.public _fun2
_fun2:	.proc
.debug
	.dw '.stabn 0x44,0,25,',0,0
	.dd LM15-_fun2
	.dw 0x0d,0x0a
.code
LM15:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,26,',0,0
	.dd LM16-_fun2
	.dw 0x0d,0x0a
.code
LM16:
L8:
	pc=L10	// Indirect jump
	pc=L9	// Indirect jump
L10:
.debug
	.dw '.stabn 0x44,0,28,',0,0
	.dd LM17-_fun2
	.dw 0x0d,0x0a
.code
LM17:
	R2=1	// QImode move
	[28690]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,29,',0,0
	.dd LM18-_fun2
	.dw 0x0d,0x0a
.code
LM18:
	R2=2	// QImode move
	[_flag]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,30,',0,0
	.dd LM19-_fun2
	.dw 0x0d,0x0a
.code
LM19:
// GCC inline ASM start
	break
// GCC inline ASM end
.debug
	.dw '.stabn 0x44,0,31,',0,0
	.dd LM20-_fun2
	.dw 0x0d,0x0a
.code
LM20:
	pc=L8	// Indirect jump
L9:
.debug
	.dw '.stabn 0x44,0,32,',0,0
	.dd LM21-_fun2
	.dw 0x0d,0x0a
.code
LM21:
.debug
	.dw '.stabn 0x44,0,32,',0,0
	.dd LM22-_fun2
	.dw 0x0d,0x0a
.code
LM22:
L7:

	pop bp from [sp]
	retf
	.endp	// end of fun2

.debug
	.dw '.stabf ',0,0
	.dd LME3-_fun2
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
	.dw '.stabn 0x44,0,34,',0,0
	.dd LM23-_main
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
	.dw '.stabn 0x44,0,35,',0,0
	.dd LM24-_main
	.dw 0x0d,0x0a
.code
LM24:
	R1=_stack1+19	// QImode move
	[_pstack]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,36,',0,0
	.dd LM25-_main
	.dw 0x0d,0x0a
.code
LM25:
	R1=fun1_entry	// QImode move, function pointer
	[SP--]=R1	// QImode move
	call _taskcreate	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,37,',0,0
	.dd LM26-_main
	.dw 0x0d,0x0a
.code
LM26:
.debug
	.dw '.stabn 0x44,0,37,',0,0
	.dd LM27-_main
	.dw 0x0d,0x0a
.code
LM27:
L11:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of main

.debug
	.dw '.stabf ',0,0
	.dd LME4-_main
	.dw 0x0d,0x0a
.code
LME4:
.iram
.public _stack1
_stack1:
	.dw 20 dup(0)
.iram
.public _stack2
_stack2:
	.dw 20 dup(0)
.iram
.public _pstack
_pstack:
	.dw 0

// far pointer entry table:
fun1_ptsec: .section .vtbl
fun1_entry:	.dw seg _fun1, offset _fun1

	.end

// GCC for SUNPLUS u'nSP version 1.0.21-3
// Command: D:\PROGRA~1\Sunplus\UNSPID~1.0\cc1.exe C:\DOCUME~1\ZHANGZ~1.YSU\LOCALS~1\Temp\ccs5aaaa.i -fkeep-inline-functions -quiet -dumpbase main.c -mglobal-var-iram -gstabs -Wall -o .\Debug/main.asm
	.external __sn_func_ptr_sec

// gcc2_compiled.:

.debug
	.dw '.stabs "F:/abc/cbasetime/",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
.code
.debug
	.dw '.stabs "F:/abc/cbasetime/main.c",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
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
.public _Flag
.iram
_Flag:
	.dw 0
.debug
	.dw '.stabs "Flag:G4",32,0,0,',0,0,offset _Flag,seg _Flag,0x0d,0x0a
.CODE
// ISR ATTRIBUTE FUNCTION, LOCATE in .text SECTION
.text
.debug
	.dw '.stabs "IRQ5:F19",36,0,0,',0,0,offset _IRQ5,seg _IRQ5,0x0d,0x0a
.TEXT
.public _IRQ5
_IRQ5:	.proc
.debug
	.dw '.stabn 0x44,0,5,',0,0
	.dd LM1-_IRQ5
	.dw 0x0d,0x0a
.text
LM1:
	// ISR ATTRIBUTE FUNCTION, PUSH r1,bp
	push r1,bp to [sp]

	// total=0, vars=0
	// frame_pointer_needed: 1
	bp=sp+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,6,',0,0
	.dd LM2-_IRQ5
	.dw 0x0d,0x0a
.text
LM2:
	R2=8	// QImode move
	[28689]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,7,',0,0
	.dd LM3-_IRQ5
	.dw 0x0d,0x0a
.text
LM3:
	R2=[_Flag]	// QImode move
	CMP R2,0	// QImode test
	NSJNZ L3	//QImode NE
.debug
	.dw '.stabn 0x44,0,9,',0,0
	.dd LM4-_IRQ5
	.dw 0x0d,0x0a
.text
LM4:
	R2=1	// QImode move
	[_Flag]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,10,',0,0
	.dd LM5-_IRQ5
	.dw 0x0d,0x0a
.text
LM5:
	R2=0	// QImode move
	[28677]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,11,',0,0
	.dd LM6-_IRQ5
	.dw 0x0d,0x0a
.text
LM6:
	pc=L4	// Indirect jump
L3:
.debug
	.dw '.stabn 0x44,0,14,',0,0
	.dd LM7-_IRQ5
	.dw 0x0d,0x0a
.text
LM7:
	R2=0	// QImode move
	[_Flag]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,15,',0,0
	.dd LM8-_IRQ5
	.dw 0x0d,0x0a
.text
LM8:
	R2=(-1)	// QImode move
	[28677]=R2	// QImode move
L4:
.debug
	.dw '.stabn 0x44,0,17,',0,0
	.dd LM9-_IRQ5
	.dw 0x0d,0x0a
.text
LM9:
.debug
	.dw '.stabn 0x44,0,17,',0,0
	.dd LM10-_IRQ5
	.dw 0x0d,0x0a
.text
LM10:
L2:

	// ISR ATTRIBUTE FUNCTION, POP r1,bp
	pop r1,bp from [sp]
	reti
	.endp	// end of IRQ5

.debug
	.dw '.stabf ',0,0
	.dd LME1-_IRQ5
	.dw 0x0d,0x0a
.text
LME1:
.code
.debug
	.dw '.stabs "main:F1",36,0,0,',0,0,offset _main,seg _main,0x0d,0x0a
.CODE
.public _main
_main:	.proc
.debug
	.dw '.stabn 0x44,0,20,',0,0
	.dd LM11-_main
	.dw 0x0d,0x0a
.code
LM11:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,21,',0,0
	.dd LM12-_main
	.dw 0x0d,0x0a
.code
LM12:
	R2=(-1)	// QImode move
	[28674]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,22,',0,0
	.dd LM13-_main
	.dw 0x0d,0x0a
.code
LM13:
	R2=(-1)	// QImode move
	[28675]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,23,',0,0
	.dd LM14-_main
	.dw 0x0d,0x0a
.code
LM14:
	R2=(-1)	// QImode move
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,24,',0,0
	.dd LM15-_main
	.dw 0x0d,0x0a
.code
LM15:
	R2=(-1)	// QImode move
	[28679]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,25,',0,0
	.dd LM16-_main
	.dw 0x0d,0x0a
.code
LM16:
	R2=(-1)	// QImode move
	[28680]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,26,',0,0
	.dd LM17-_main
	.dw 0x0d,0x0a
.code
LM17:
	R2=(-1)	// QImode move
	[28677]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,27,',0,0
	.dd LM18-_main
	.dw 0x0d,0x0a
.code
LM18:
	R2=8	// QImode move
	[28688]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,28,',0,0
	.dd LM19-_main
	.dw 0x0d,0x0a
.code
LM19:
	R2=8	// QImode move
	[28717]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,30,',0,0
	.dd LM20-_main
	.dw 0x0d,0x0a
.code
LM20:
// GCC inline ASM start
	INT IRQ
// GCC inline ASM end
.debug
	.dw '.stabn 0x44,0,33,',0,0
	.dd LM21-_main
	.dw 0x0d,0x0a
.code
LM21:
L7:
	pc=L9	// Indirect jump
	pc=L8	// Indirect jump
L9:
.debug
	.dw '.stabn 0x44,0,35,',0,0
	.dd LM22-_main
	.dw 0x0d,0x0a
.code
LM22:
	R2=1	// QImode move
	[28690]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,36,',0,0
	.dd LM23-_main
	.dw 0x0d,0x0a
.code
LM23:
	pc=L7	// Indirect jump
L8:
.debug
	.dw '.stabn 0x44,0,37,',0,0
	.dd LM24-_main
	.dw 0x0d,0x0a
.code
LM24:
.debug
	.dw '.stabn 0x44,0,37,',0,0
	.dd LM25-_main
	.dw 0x0d,0x0a
.code
LM25:
L6:

	pop bp from [sp]
	retf
	.endp	// end of main

.debug
	.dw '.stabf ',0,0
	.dd LME2-_main
	.dw 0x0d,0x0a
.code
LME2:
	.end

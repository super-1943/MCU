// GCC for SUNPLUS u'nSP version 1.0.21-3
// Command: D:\PROGRA~1\Sunplus\UNSPID~1.0\cc1.exe C:\DOCUME~1\ZHANGZ~1.YSU\LOCALS~1\Temp\ccGYaaaa.i -fkeep-inline-functions -quiet -dumpbase main.c -mglobal-var-iram -gstabs -Wall -o .\Debug/main.asm
	.external __sn_func_ptr_sec

// gcc2_compiled.:

.debug
	.dw '.stabs "F:/abc/exinterrupt/",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
.code
.debug
	.dw '.stabs "F:/abc/exinterrupt/main.c",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
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
// ISR ATTRIBUTE FUNCTION, LOCATE in .text SECTION
.text
.debug
	.dw '.stabs "IRQ3:F19",36,0,0,',0,0,offset _IRQ3,seg _IRQ3,0x0d,0x0a
.TEXT
.public _IRQ3
_IRQ3:	.proc
.debug
	.dw '.stabn 0x44,0,4,',0,0
	.dd LM1-_IRQ3
	.dw 0x0d,0x0a
.text
LM1:
	// ISR ATTRIBUTE FUNCTION, PUSH r1,bp
	push r1,bp to [sp]

	// total=1, vars=1
	// frame_pointer_needed: 1
	sp-=1
	bp=sp+1

	R1=BP+4
.debug
	.dw '.stabn 0x44,0,5,',0,0
	.dd LM2-_IRQ3
	.dw 0x0d,0x0a
.text
LM2:
LBB2:
	R2=0	// QImode move
	[BP]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,7,',0,0
	.dd LM3-_IRQ3
	.dw 0x0d,0x0a
.text
LM3:
	R2=256	// QImode move
	[28689]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,8,',0,0
	.dd LM4-_IRQ3
	.dw 0x0d,0x0a
.text
LM4:
	R2=[28677]	// QImode move
	[BP]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,9,',0,0
	.dd LM5-_IRQ3
	.dw 0x0d,0x0a
.text
LM5:
	R2=[BP]	// QImode move
	R2=R2&240
	[BP]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,10,',0,0
	.dd LM6-_IRQ3
	.dw 0x0d,0x0a
.text
LM6:
	R2=[BP]	// QImode move
	CMP R2,240	// QImode compare
	NSJNZ L3	//QImode NE
.debug
	.dw '.stabn 0x44,0,12,',0,0
	.dd LM7-_IRQ3
	.dw 0x0d,0x0a
.text
LM7:
	R2=(-241)	// QImode move
	[BP]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,13,',0,0
	.dd LM8-_IRQ3
	.dw 0x0d,0x0a
.text
LM8:
	R2=[28677]	// QImode move
	R3=R2	// QImode move
	R3&=[BP]	// andqi3_r0R
	[28677]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,14,',0,0
	.dd LM9-_IRQ3
	.dw 0x0d,0x0a
.text
LM9:
	pc=L4	// Indirect jump
L3:
.debug
	.dw '.stabn 0x44,0,17,',0,0
	.dd LM10-_IRQ3
	.dw 0x0d,0x0a
.text
LM10:
	R2=[28677]	// QImode move
	R3=R2|240
	[28677]=R3	// QImode move
L4:
.debug
	.dw '.stabn 0x44,0,19,',0,0
	.dd LM11-_IRQ3
	.dw 0x0d,0x0a
.text
LM11:
LBE2:
.debug
	.dw '.stabn 0x44,0,19,',0,0
	.dd LM12-_IRQ3
	.dw 0x0d,0x0a
.text
LM12:
L2:

	sp+=1
	// ISR ATTRIBUTE FUNCTION, POP r1,bp
	pop r1,bp from [sp]
	reti
	.endp	// end of IRQ3

.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB2-_IRQ3
	.dw 0x0d,0x0a
.text
.debug
	.dw '.stabs "i:4",128,0,0,0',0x0d,0x0a
.TEXT
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE2-_IRQ3
	.dw 0x0d,0x0a
.text
.debug
	.dw '.stabf ',0,0
	.dd LME1-_IRQ3
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
	.dw '.stabn 0x44,0,21,',0,0
	.dd LM13-_main
	.dw 0x0d,0x0a
.code
LM13:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,22,',0,0
	.dd LM14-_main
	.dw 0x0d,0x0a
.code
LM14:
// GCC inline ASM start
	INT OFF
// GCC inline ASM end
.debug
	.dw '.stabn 0x44,0,23,',0,0
	.dd LM15-_main
	.dw 0x0d,0x0a
.code
LM15:
	R2=0	// QImode move
	[28681]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,24,',0,0
	.dd LM16-_main
	.dw 0x0d,0x0a
.code
LM16:
	R2=240	// QImode move
	[28679]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,25,',0,0
	.dd LM17-_main
	.dw 0x0d,0x0a
.code
LM17:
	R2=240	// QImode move
	[28680]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,26,',0,0
	.dd LM18-_main
	.dw 0x0d,0x0a
.code
LM18:
	R2=15	// QImode move
	[28677]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,27,',0,0
	.dd LM19-_main
	.dw 0x0d,0x0a
.code
LM19:
	R2=256	// QImode move
	[28688]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,28,',0,0
	.dd LM20-_main
	.dw 0x0d,0x0a
.code
LM20:
	R2=256	// QImode move
	[28717]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,29,',0,0
	.dd LM21-_main
	.dw 0x0d,0x0a
.code
LM21:
// GCC inline ASM start
	INT IRQ
// GCC inline ASM end
.debug
	.dw '.stabn 0x44,0,30,',0,0
	.dd LM22-_main
	.dw 0x0d,0x0a
.code
LM22:
L7:
	pc=L9	// Indirect jump
	pc=L8	// Indirect jump
L9:
.debug
	.dw '.stabn 0x44,0,32,',0,0
	.dd LM23-_main
	.dw 0x0d,0x0a
.code
LM23:
	R2=1	// QImode move
	[28690]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,33,',0,0
	.dd LM24-_main
	.dw 0x0d,0x0a
.code
LM24:
	pc=L7	// Indirect jump
L8:
.debug
	.dw '.stabn 0x44,0,34,',0,0
	.dd LM25-_main
	.dw 0x0d,0x0a
.code
LM25:
.debug
	.dw '.stabn 0x44,0,34,',0,0
	.dd LM26-_main
	.dw 0x0d,0x0a
.code
LM26:
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

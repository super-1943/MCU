// GCC for SUNPLUS u'nSP version 1.0.21-3
// Command: D:\PROGRA~1\SunPlus\UNSPID~1.0\cc1.exe C:\DOCUME~1\a\LOCALS~1\Temp\ccIHaaaa.i -fkeep-inline-functions -quiet -dumpbase ddd.c -mglobal-var-iram -gstabs -Wall -o .\Debug/ddd.asm
	.external __sn_func_ptr_sec

// gcc2_compiled.:

.debug
	.dw '.stabs "G:/neike/",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
.code
.debug
	.dw '.stabs "G:/neike/ddd.c",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
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
.public _i
.iram
_i:
	.dw 0
.debug
	.dw '.stabs "i:G4",32,0,0,',0,0,offset _i,seg _i,0x0d,0x0a
.CODE
// ISR ATTRIBUTE FUNCTION, LOCATE in .text SECTION
.text
.debug
	.dw '.stabs "IRQ1:F19",36,0,0,',0,0,offset _IRQ1,seg _IRQ1,0x0d,0x0a
.TEXT
.public _IRQ1
_IRQ1:	.proc
.debug
	.dw '.stabn 0x44,0,5,',0,0
	.dd LM1-_IRQ1
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
	.dd LM2-_IRQ1
	.dw 0x0d,0x0a
.text
LM2:
	R2=[_i]	// QImode move
	R3=10	// QImode move
	[_i]=R2+R3  //addqi3_Qrr
.debug
	.dw '.stabn 0x44,0,7,',0,0
	.dd LM3-_IRQ1
	.dw 0x0d,0x0a
.text
LM3:
	R2=[_i]	// QImode move
	R3=R2 lsl 2
	R3=R3 lsl 4
	[28695]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,8,',0,0
	.dd LM4-_IRQ1
	.dw 0x0d,0x0a
.text
LM4:
	R2=[_i]	// QImode move
	CMP R2,800	// QImode compare
	NSJNZ L3	//QImode NE
.debug
	.dw '.stabn 0x44,0,9,',0,0
	.dd LM5-_IRQ1
	.dw 0x0d,0x0a
.text
LM5:
	R2=0	// QImode move
	[_i]=R2	// QImode move
L3:
.debug
	.dw '.stabn 0x44,0,10,',0,0
	.dd LM6-_IRQ1
	.dw 0x0d,0x0a
.text
LM6:
	R2=1	// QImode move
	[28689]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,11,',0,0
	.dd LM7-_IRQ1
	.dw 0x0d,0x0a
.text
LM7:
.debug
	.dw '.stabn 0x44,0,11,',0,0
	.dd LM8-_IRQ1
	.dw 0x0d,0x0a
.text
LM8:
L2:

	// ISR ATTRIBUTE FUNCTION, POP r1,bp
	pop r1,bp from [sp]
	reti
	.endp	// end of IRQ1

.debug
	.dw '.stabf ',0,0
	.dd LME1-_IRQ1
	.dw 0x0d,0x0a
.text
LME1:
.code
.debug
	.dw '.stabs "delay:F19",36,0,0,',0,0,offset _delay,seg _delay,0x0d,0x0a
.CODE
.public _delay
_delay:	.proc
.debug
	.dw '.stabn 0x44,0,13,',0,0
	.dd LM9-_delay
	.dw 0x0d,0x0a
.code
LM9:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,15,',0,0
	.dd LM10-_delay
	.dw 0x0d,0x0a
.code
LM10:
L6:
	R2=R1	// QImode move
	R3=[R2]	// QImode move
	R2=R3+(-1)
	R3=R2	// QImode move
	R2=R1	// QImode move
	[R2]=R3	// QImode move
	CMP R3,(-1)	// QImode compare
	NSJNZ L8	//QImode NE
	pc=L7	// Indirect jump
L8:
.debug
	.dw '.stabn 0x44,0,17,',0,0
	.dd LM11-_delay
	.dw 0x0d,0x0a
.code
LM11:
	R2=1	// QImode move
	[28690]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,18,',0,0
	.dd LM12-_delay
	.dw 0x0d,0x0a
.code
LM12:
	pc=L6	// Indirect jump
L7:
.debug
	.dw '.stabn 0x44,0,19,',0,0
	.dd LM13-_delay
	.dw 0x0d,0x0a
.code
LM13:
.debug
	.dw '.stabn 0x44,0,19,',0,0
	.dd LM14-_delay
	.dw 0x0d,0x0a
.code
LM14:
L5:

	pop bp from [sp]
	retf
	.endp	// end of delay

.debug
	.dw '.stabs "i:p1",160,0,0,3',0x0d,0x0a
.CODE
.debug
	.dw '.stabf ',0,0
	.dd LME2-_delay
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
	.dw '.stabn 0x44,0,21,',0,0
	.dd LM15-_main
	.dw 0x0d,0x0a
.code
LM15:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,22,',0,0
	.dd LM16-_main
	.dw 0x0d,0x0a
.code
LM16:
	R2=128	// QImode move
	[28691]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,23,',0,0
	.dd LM17-_main
	.dw 0x0d,0x0a
.code
LM17:
	R2=4096	// QImode move
	[28688]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,24,',0,0
	.dd LM18-_main
	.dw 0x0d,0x0a
.code
LM18:
	R2=48	// QImode move
	[28683]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,25,',0,0
	.dd LM19-_main
	.dw 0x0d,0x0a
.code
LM19:
	R2=(-1)	// QImode move
	[28682]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,26,',0,0
	.dd LM20-_main
	.dw 0x0d,0x0a
.code
LM20:
	R2=0	// QImode move
	[28714]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,27,',0,0
	.dd LM21-_main
	.dw 0x0d,0x0a
.code
LM21:
	R2=(-1)	// QImode move
	[28674]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,28,',0,0
	.dd LM22-_main
	.dw 0x0d,0x0a
.code
LM22:
	R2=(-1)	// QImode move
	[28675]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,29,',0,0
	.dd LM23-_main
	.dw 0x0d,0x0a
.code
LM23:
	R2=(-1)	// QImode move
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,31,',0,0
	.dd LM24-_main
	.dw 0x0d,0x0a
.code
LM24:
L11:
	pc=L13	// Indirect jump
	pc=L12	// Indirect jump
L13:
.debug
	.dw '.stabn 0x44,0,33,',0,0
	.dd LM25-_main
	.dw 0x0d,0x0a
.code
LM25:
	R2=(-1)	// QImode move
	[28695]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,35,',0,0
	.dd LM26-_main
	.dw 0x0d,0x0a
.code
LM26:
	R2=0	// QImode move
	[28695]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,37,',0,0
	.dd LM27-_main
	.dw 0x0d,0x0a
.code
LM27:
	R2=1	// QImode move
	[28690]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,38,',0,0
	.dd LM28-_main
	.dw 0x0d,0x0a
.code
LM28:
	pc=L11	// Indirect jump
L12:
.debug
	.dw '.stabn 0x44,0,39,',0,0
	.dd LM29-_main
	.dw 0x0d,0x0a
.code
LM29:
.debug
	.dw '.stabn 0x44,0,39,',0,0
	.dd LM30-_main
	.dw 0x0d,0x0a
.code
LM30:
L10:

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

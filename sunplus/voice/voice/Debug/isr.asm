// GCC for SUNPLUS u'nSP version 1.0.21-3
// Command: D:\PROGRA~1\Sunplus\UNSPID~1.0\cc1.exe C:\DOCUME~1\ADMINI~1\LOCALS~1\Temp\ccqgaaaa.i -fkeep-inline-functions -quiet -dumpbase isr.c -mglobal-var-iram -gstabs -Wall -o .\Debug/isr.asm
	.external __sn_func_ptr_sec

// gcc2_compiled.:

.debug
	.dw '.stabs "C:/Documents and Settings/Administrator/×ÀÃæ/voice/voice/",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
.code
.debug
	.dw '.stabs "C:/Documents and Settings/Administrator/×/300Ã/346/voice/voice/isr.c",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
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
// GCC inline ASM start
	.external F_FIQ_Service_SACM_S480
// GCC inline ASM end
// ISR ATTRIBUTE FUNCTION, LOCATE in .text SECTION
.text
.debug
	.dw '.stabs "FIQ:F19",36,0,0,',0,0,offset _FIQ,seg _FIQ,0x0d,0x0a
.TEXT
.public _FIQ
_FIQ:	.proc
.debug
	.dw '.stabn 0x44,0,17,',0,0
	.dd LM1-_FIQ
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
	.dw '.stabn 0x44,0,18,',0,0
	.dd LM2-_FIQ
	.dw 0x0d,0x0a
.text
LM2:
	R3=[28688]	// QImode move
	R2=R3&8192
	CMP R2,0	// QImode test
	NSJZ L3	//QImode EQ
.debug
	.dw '.stabn 0x44,0,20,',0,0
	.dd LM3-_FIQ
	.dw 0x0d,0x0a
.text
LM3:
	R2=8192	// QImode move
	[28689]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,21,',0,0
	.dd LM4-_FIQ
	.dw 0x0d,0x0a
.text
LM4:
// GCC inline ASM start
	call F_FIQ_Service_SACM_S480
// GCC inline ASM end
.debug
	.dw '.stabn 0x44,0,22,',0,0
	.dd LM5-_FIQ
	.dw 0x0d,0x0a
.text
LM5:
	pc=L4	// Indirect jump
L3:
.debug
	.dw '.stabn 0x44,0,23,',0,0
	.dd LM6-_FIQ
	.dw 0x0d,0x0a
.text
LM6:
	R3=[28688]	// QImode move
	R2=R3&2048
	CMP R2,0	// QImode test
	NSJZ L5	//QImode EQ
.debug
	.dw '.stabn 0x44,0,24,',0,0
	.dd LM7-_FIQ
	.dw 0x0d,0x0a
.text
LM7:
	R2=2048	// QImode move
	[28689]=R2	// QImode move
	pc=L4	// Indirect jump
L5:
.debug
	.dw '.stabn 0x44,0,26,',0,0
	.dd LM8-_FIQ
	.dw 0x0d,0x0a
.text
LM8:
	R2=(-32768)	// QImode move
	[28689]=R2	// QImode move
L6:
L4:
.debug
	.dw '.stabn 0x44,0,27,',0,0
	.dd LM9-_FIQ
	.dw 0x0d,0x0a
.text
LM9:
.debug
	.dw '.stabn 0x44,0,27,',0,0
	.dd LM10-_FIQ
	.dw 0x0d,0x0a
.text
LM10:
L2:

	// ISR ATTRIBUTE FUNCTION, POP r1,bp
	pop r1,bp from [sp]
	reti
	.endp	// end of FIQ

.debug
	.dw '.stabf ',0,0
	.dd LME1-_FIQ
	.dw 0x0d,0x0a
.text
LME1:
// ISR ATTRIBUTE FUNCTION, LOCATE in .text SECTION
.text
.debug
	.dw '.stabs "IRQ5:F19",36,0,0,',0,0,offset _IRQ5,seg _IRQ5,0x0d,0x0a
.TEXT
.public _IRQ5
_IRQ5:	.proc
.debug
	.dw '.stabn 0x44,0,32,',0,0
	.dd LM11-_IRQ5
	.dw 0x0d,0x0a
.text
LM11:
	// ISR ATTRIBUTE FUNCTION, PUSH r1,bp
	push r1,bp to [sp]

	// total=0, vars=0
	// frame_pointer_needed: 1
	bp=sp+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,33,',0,0
	.dd LM12-_IRQ5
	.dw 0x0d,0x0a
.text
LM12:
	R3=[28688]	// QImode move
	R2=R3&4
	CMP R2,0	// QImode test
	NSJZ L10	//QImode EQ
.debug
	.dw '.stabn 0x44,0,35,',0,0
	.dd LM13-_IRQ5
	.dw 0x0d,0x0a
.text
LM13:
	R2=[_num]	// QImode move
	R3=1	// QImode move
	[_num]=R2+R3  //addqi3_Qrr
.debug
	.dw '.stabn 0x44,0,36,',0,0
	.dd LM14-_IRQ5
	.dw 0x0d,0x0a
.text
LM14:
	R2=[_num]	// QImode move
	CMP R2,2	// QImode compare
	NSJNA L11	//QImode LEU
.debug
	.dw '.stabn 0x44,0,37,',0,0
	.dd LM15-_IRQ5
	.dw 0x0d,0x0a
.text
LM15:
	R2=0	// QImode move
	[_num]=R2	// QImode move
L11:
.debug
	.dw '.stabn 0x44,0,38,',0,0
	.dd LM16-_IRQ5
	.dw 0x0d,0x0a
.text
LM16:
	R2=[_dian]	// QImode move
	R3=R2^0xffff	// one_cmplqi2
	[_dian]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,39,',0,0
	.dd LM17-_IRQ5
	.dw 0x0d,0x0a
.text
LM17:
	R2=[_temperatureflag]	// QImode move
	R3=1	// QImode move
	[_temperatureflag]=R2+R3  //addqi3_Qrr
.debug
	.dw '.stabn 0x44,0,40,',0,0
	.dd LM18-_IRQ5
	.dw 0x0d,0x0a
.text
LM18:
	R2=[_temperatureflag]	// QImode move
	CMP R2,2	// QImode compare
	NSJNA L12	//QImode LEU
.debug
	.dw '.stabn 0x44,0,41,',0,0
	.dd LM19-_IRQ5
	.dw 0x0d,0x0a
.text
LM19:
	R2=0	// QImode move
	[_temperatureflag]=R2	// QImode move
L12:
.debug
	.dw '.stabn 0x44,0,42,',0,0
	.dd LM20-_IRQ5
	.dw 0x0d,0x0a
.text
LM20:
	R2=4	// QImode move
	[28689]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,43,',0,0
	.dd LM21-_IRQ5
	.dw 0x0d,0x0a
.text
LM21:
	pc=L13	// Indirect jump
L10:
.debug
	.dw '.stabn 0x44,0,46,',0,0
	.dd LM22-_IRQ5
	.dw 0x0d,0x0a
.text
LM22:
	R2=8	// QImode move
	[28689]=R2	// QImode move
L13:
.debug
	.dw '.stabn 0x44,0,48,',0,0
	.dd LM23-_IRQ5
	.dw 0x0d,0x0a
.text
LM23:
.debug
	.dw '.stabn 0x44,0,48,',0,0
	.dd LM24-_IRQ5
	.dw 0x0d,0x0a
.text
LM24:
L9:

	// ISR ATTRIBUTE FUNCTION, POP r1,bp
	pop r1,bp from [sp]
	reti
	.endp	// end of IRQ5

.debug
	.dw '.stabf ',0,0
	.dd LME2-_IRQ5
	.dw 0x0d,0x0a
.text
LME2:
.external _temperatureflag
.external _dian
.external _num
	.end

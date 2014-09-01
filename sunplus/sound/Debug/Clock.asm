// GCC for SUNPLUS u'nSP version 1.0.21-3
// Command: C:\PROGRA~1\Sunplus\UNSPID~1.0\cc1.exe C:\DOCUME~1\ADMINI~1\LOCALS~1\Temp\ccovaaaa.i -fkeep-inline-functions -quiet -dumpbase Clock.c -mglobal-var-iram -gstabs -Wall -o .\Debug/Clock.asm
	.external __sn_func_ptr_sec

// gcc2_compiled.:

.debug
	.dw '.stabs "F:/myproject/lingyang/sound/",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
.code
.debug
	.dw '.stabs "F:/myproject/lingyang/sound/Clock.c",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
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
	.dw '.stabs "STR_CLOCK:T20=s7Year:4,0,16;Mon:4,16,16;\\",128,0,0,0',0x0d,0x0a
	.DW '.stabs "Day:4,32,16;Hour:4,48,16;Min:4,64,16;\\",128,0,0,0',0x0d,0x0a
	.DW '.stabs "Sec:4,80,16;HalfSec:4,96,16;;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "CLOCK:t21=20",128,0,0,0',0x0d,0x0a
.CODE
.public _Clock
.iram
_Clock:
	.dw 2006
	.dw 1
	.dw 1
	.dw 0
	.dw 0
	.dw 0
	.dw 0
.debug
	.dw '.stabs "Clock:G21",32,0,0,',0,0,offset _Clock,seg _Clock,0x0d,0x0a
.CODE
.public _Month_Day
.text
_Month_Day:
	.dw 31
	.dw 28
	.dw 31
	.dw 30
	.dw 31
	.dw 30
	.dw 31
	.dw 31
	.dw 30
	.dw 31
	.dw 30
	.dw 31
.debug
	.dw '.stabs "Month_Day:G22=ar1;0;11;4",32,0,0,',0,0,offset _Month_Day,seg _Month_Day,0x0d,0x0a
.CODE
.code
.debug
	.dw '.stabs "Clock_ISR:F19",36,0,0,',0,0,offset _Clock_ISR,seg _Clock_ISR,0x0d,0x0a
.CODE
.public _Clock_ISR
_Clock_ISR:	.proc
.debug
	.dw '.stabn 0x44,0,32,',0,0
	.dd LM1-_Clock_ISR
	.dw 0x0d,0x0a
.code
LM1:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,33,',0,0
	.dd LM2-_Clock_ISR
	.dw 0x0d,0x0a
.code
LM2:
	R2=[_Clock+6]	// QImode move
	CMP R2,0	// QImode test
	NSJNZ L3	//QImode NE
.debug
	.dw '.stabn 0x44,0,34,',0,0
	.dd LM3-_Clock_ISR
	.dw 0x0d,0x0a
.code
LM3:
	R2=1	// QImode move
	[_Clock+6]=R2	// QImode move
	pc=L4	// Indirect jump
L3:
.debug
	.dw '.stabn 0x44,0,37,',0,0
	.dd LM4-_Clock_ISR
	.dw 0x0d,0x0a
.code
LM4:
	R2=0	// QImode move
	[_Clock+6]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,38,',0,0
	.dd LM5-_Clock_ISR
	.dw 0x0d,0x0a
.code
LM5:
	R2=[_Clock+5]	// QImode move
	R3=1	// QImode move
	[_Clock+5]=R2+R3  //addqi3_Qrr
.debug
	.dw '.stabn 0x44,0,39,',0,0
	.dd LM6-_Clock_ISR
	.dw 0x0d,0x0a
.code
LM6:
	R2=[_Clock+5]	// QImode move
	CMP R2,60	// QImode compare
	NSJNZ L4	//QImode NE
.debug
	.dw '.stabn 0x44,0,41,',0,0
	.dd LM7-_Clock_ISR
	.dw 0x0d,0x0a
.code
LM7:
	R2=0	// QImode move
	[_Clock+5]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,42,',0,0
	.dd LM8-_Clock_ISR
	.dw 0x0d,0x0a
.code
LM8:
	R2=[_Clock+4]	// QImode move
	R3=1	// QImode move
	[_Clock+4]=R2+R3  //addqi3_Qrr
.debug
	.dw '.stabn 0x44,0,43,',0,0
	.dd LM9-_Clock_ISR
	.dw 0x0d,0x0a
.code
LM9:
	R2=[_Clock+4]	// QImode move
	CMP R2,60	// QImode compare
	NSJNZ L4	//QImode NE
.debug
	.dw '.stabn 0x44,0,45,',0,0
	.dd LM10-_Clock_ISR
	.dw 0x0d,0x0a
.code
LM10:
	R2=0	// QImode move
	[_Clock+4]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,46,',0,0
	.dd LM11-_Clock_ISR
	.dw 0x0d,0x0a
.code
LM11:
	R2=[_Clock+3]	// QImode move
	R3=1	// QImode move
	[_Clock+3]=R2+R3  //addqi3_Qrr
.debug
	.dw '.stabn 0x44,0,47,',0,0
	.dd LM12-_Clock_ISR
	.dw 0x0d,0x0a
.code
LM12:
	R2=[_Clock+3]	// QImode move
	CMP R2,24	// QImode compare
	NSJNZ L4	//QImode NE
.debug
	.dw '.stabn 0x44,0,49,',0,0
	.dd LM13-_Clock_ISR
	.dw 0x0d,0x0a
.code
LM13:
	R2=0	// QImode move
	[_Clock+3]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,50,',0,0
	.dd LM14-_Clock_ISR
	.dw 0x0d,0x0a
.code
LM14:
	R2=[_Clock+2]	// QImode move
	R3=1	// QImode move
	[_Clock+2]=R2+R3  //addqi3_Qrr
.debug
	.dw '.stabn 0x44,0,51,',0,0
	.dd LM15-_Clock_ISR
	.dw 0x0d,0x0a
.code
LM15:
	R3=[_Clock+1]	// QImode move
	R2=R3+(-1)
	R4=_Month_Day	// QImode move
	R3=R4	// QImode move
	R3 = R3 + R2	//addqi3
	R2=[_Clock+2]	// QImode move
	R4=R3	// QImode move
	CMP R2,[R4]	// QImode compare
	NSJNA L4	//QImode LEU
.debug
	.dw '.stabn 0x44,0,53,',0,0
	.dd LM16-_Clock_ISR
	.dw 0x0d,0x0a
.code
LM16:
	R2=[_Clock+1]	// QImode move
	CMP R2,2	// QImode compare
	NSJNZ L10	//QImode NE
	R3=[_Clock]	// QImode move
	R2=R3&3
	CMP R2,0	// QImode test
	NSJNZ L10	//QImode NE
	R2=[_Clock+2]	// QImode move
	CMP R2,29	// QImode compare
	NSJA L10	//QImode GTU
	pc=L4	// Indirect jump
L10:
.debug
	.dw '.stabn 0x44,0,55,',0,0
	.dd LM17-_Clock_ISR
	.dw 0x0d,0x0a
.code
LM17:
	R2=1	// QImode move
	[_Clock+2]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,56,',0,0
	.dd LM18-_Clock_ISR
	.dw 0x0d,0x0a
.code
LM18:
	R2=[_Clock+1]	// QImode move
	R3=1	// QImode move
	[_Clock+1]=R2+R3  //addqi3_Qrr
.debug
	.dw '.stabn 0x44,0,57,',0,0
	.dd LM19-_Clock_ISR
	.dw 0x0d,0x0a
.code
LM19:
	R2=[_Clock+1]	// QImode move
	CMP R2,12	// QImode compare
	NSJNA L4	//QImode LEU
.debug
	.dw '.stabn 0x44,0,59,',0,0
	.dd LM20-_Clock_ISR
	.dw 0x0d,0x0a
.code
LM20:
	R2=1	// QImode move
	[_Clock+1]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,60,',0,0
	.dd LM21-_Clock_ISR
	.dw 0x0d,0x0a
.code
LM21:
	R2=[_Clock]	// QImode move
	R3=1	// QImode move
	[_Clock]=R2+R3  //addqi3_Qrr
L11:
L9:
L8:
L7:
L6:
L5:
L4:
.debug
	.dw '.stabn 0x44,0,68,',0,0
	.dd LM22-_Clock_ISR
	.dw 0x0d,0x0a
.code
LM22:
.debug
	.dw '.stabn 0x44,0,68,',0,0
	.dd LM23-_Clock_ISR
	.dw 0x0d,0x0a
.code
LM23:
L2:

	pop bp from [sp]
	retf
	.endp	// end of Clock_ISR

.debug
	.dw '.stabf ',0,0
	.dd LME1-_Clock_ISR
	.dw 0x0d,0x0a
.code
LME1:
.code
.debug
	.dw '.stabs "Clock_Start:F19",36,0,0,',0,0,offset _Clock_Start,seg _Clock_Start,0x0d,0x0a
.CODE
.public _Clock_Start
_Clock_Start:	.proc
.debug
	.dw '.stabn 0x44,0,77,',0,0
	.dd LM24-_Clock_Start
	.dw 0x0d,0x0a
.code
LM24:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,78,',0,0
	.dd LM25-_Clock_Start
	.dw 0x0d,0x0a
.code
LM25:
	R2=[28717]	// QImode move
	R3=R2|4
	[28717]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,79,',0,0
	.dd LM26-_Clock_Start
	.dw 0x0d,0x0a
.code
LM26:
// GCC inline ASM start
	IRQ ON
// GCC inline ASM end
.debug
	.dw '.stabn 0x44,0,80,',0,0
	.dd LM27-_Clock_Start
	.dw 0x0d,0x0a
.code
LM27:
.debug
	.dw '.stabn 0x44,0,80,',0,0
	.dd LM28-_Clock_Start
	.dw 0x0d,0x0a
.code
LM28:
L21:

	pop bp from [sp]
	retf
	.endp	// end of Clock_Start

.debug
	.dw '.stabf ',0,0
	.dd LME2-_Clock_Start
	.dw 0x0d,0x0a
.code
LME2:
.code
.debug
	.dw '.stabs "Clock_GetYear:F4",36,0,0,',0,0,offset _Clock_GetYear,seg _Clock_GetYear,0x0d,0x0a
.CODE
.public _Clock_GetYear
_Clock_GetYear:	.proc
.debug
	.dw '.stabn 0x44,0,90,',0,0
	.dd LM29-_Clock_GetYear
	.dw 0x0d,0x0a
.code
LM29:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R2=BP+3
.debug
	.dw '.stabn 0x44,0,91,',0,0
	.dd LM30-_Clock_GetYear
	.dw 0x0d,0x0a
.code
LM30:
	R3=[_Clock]	// QImode move
	R1=R3	// QImode move
	pc=L22	// Indirect jump
.debug
	.dw '.stabn 0x44,0,92,',0,0
	.dd LM31-_Clock_GetYear
	.dw 0x0d,0x0a
.code
LM31:
.debug
	.dw '.stabn 0x44,0,92,',0,0
	.dd LM32-_Clock_GetYear
	.dw 0x0d,0x0a
.code
LM32:
L22:

	pop bp from [sp]
	retf
	.endp	// end of Clock_GetYear

.debug
	.dw '.stabf ',0,0
	.dd LME3-_Clock_GetYear
	.dw 0x0d,0x0a
.code
LME3:
.code
.debug
	.dw '.stabs "Clock_GetMon:F4",36,0,0,',0,0,offset _Clock_GetMon,seg _Clock_GetMon,0x0d,0x0a
.CODE
.public _Clock_GetMon
_Clock_GetMon:	.proc
.debug
	.dw '.stabn 0x44,0,101,',0,0
	.dd LM33-_Clock_GetMon
	.dw 0x0d,0x0a
.code
LM33:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R2=BP+3
.debug
	.dw '.stabn 0x44,0,102,',0,0
	.dd LM34-_Clock_GetMon
	.dw 0x0d,0x0a
.code
LM34:
	R3=[_Clock+1]	// QImode move
	R1=R3	// QImode move
	pc=L23	// Indirect jump
.debug
	.dw '.stabn 0x44,0,103,',0,0
	.dd LM35-_Clock_GetMon
	.dw 0x0d,0x0a
.code
LM35:
.debug
	.dw '.stabn 0x44,0,103,',0,0
	.dd LM36-_Clock_GetMon
	.dw 0x0d,0x0a
.code
LM36:
L23:

	pop bp from [sp]
	retf
	.endp	// end of Clock_GetMon

.debug
	.dw '.stabf ',0,0
	.dd LME4-_Clock_GetMon
	.dw 0x0d,0x0a
.code
LME4:
.code
.debug
	.dw '.stabs "Clock_GetDay:F4",36,0,0,',0,0,offset _Clock_GetDay,seg _Clock_GetDay,0x0d,0x0a
.CODE
.public _Clock_GetDay
_Clock_GetDay:	.proc
.debug
	.dw '.stabn 0x44,0,112,',0,0
	.dd LM37-_Clock_GetDay
	.dw 0x0d,0x0a
.code
LM37:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R2=BP+3
.debug
	.dw '.stabn 0x44,0,113,',0,0
	.dd LM38-_Clock_GetDay
	.dw 0x0d,0x0a
.code
LM38:
	R3=[_Clock+2]	// QImode move
	R1=R3	// QImode move
	pc=L24	// Indirect jump
.debug
	.dw '.stabn 0x44,0,114,',0,0
	.dd LM39-_Clock_GetDay
	.dw 0x0d,0x0a
.code
LM39:
.debug
	.dw '.stabn 0x44,0,114,',0,0
	.dd LM40-_Clock_GetDay
	.dw 0x0d,0x0a
.code
LM40:
L24:

	pop bp from [sp]
	retf
	.endp	// end of Clock_GetDay

.debug
	.dw '.stabf ',0,0
	.dd LME5-_Clock_GetDay
	.dw 0x0d,0x0a
.code
LME5:
.code
.debug
	.dw '.stabs "Clock_GetHour:F4",36,0,0,',0,0,offset _Clock_GetHour,seg _Clock_GetHour,0x0d,0x0a
.CODE
.public _Clock_GetHour
_Clock_GetHour:	.proc
.debug
	.dw '.stabn 0x44,0,123,',0,0
	.dd LM41-_Clock_GetHour
	.dw 0x0d,0x0a
.code
LM41:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R2=BP+3
.debug
	.dw '.stabn 0x44,0,124,',0,0
	.dd LM42-_Clock_GetHour
	.dw 0x0d,0x0a
.code
LM42:
	R3=[_Clock+3]	// QImode move
	R1=R3	// QImode move
	pc=L25	// Indirect jump
.debug
	.dw '.stabn 0x44,0,125,',0,0
	.dd LM43-_Clock_GetHour
	.dw 0x0d,0x0a
.code
LM43:
.debug
	.dw '.stabn 0x44,0,125,',0,0
	.dd LM44-_Clock_GetHour
	.dw 0x0d,0x0a
.code
LM44:
L25:

	pop bp from [sp]
	retf
	.endp	// end of Clock_GetHour

.debug
	.dw '.stabf ',0,0
	.dd LME6-_Clock_GetHour
	.dw 0x0d,0x0a
.code
LME6:
.code
.debug
	.dw '.stabs "Clock_GetMin:F4",36,0,0,',0,0,offset _Clock_GetMin,seg _Clock_GetMin,0x0d,0x0a
.CODE
.public _Clock_GetMin
_Clock_GetMin:	.proc
.debug
	.dw '.stabn 0x44,0,134,',0,0
	.dd LM45-_Clock_GetMin
	.dw 0x0d,0x0a
.code
LM45:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R2=BP+3
.debug
	.dw '.stabn 0x44,0,135,',0,0
	.dd LM46-_Clock_GetMin
	.dw 0x0d,0x0a
.code
LM46:
	R3=[_Clock+4]	// QImode move
	R1=R3	// QImode move
	pc=L26	// Indirect jump
.debug
	.dw '.stabn 0x44,0,136,',0,0
	.dd LM47-_Clock_GetMin
	.dw 0x0d,0x0a
.code
LM47:
.debug
	.dw '.stabn 0x44,0,136,',0,0
	.dd LM48-_Clock_GetMin
	.dw 0x0d,0x0a
.code
LM48:
L26:

	pop bp from [sp]
	retf
	.endp	// end of Clock_GetMin

.debug
	.dw '.stabf ',0,0
	.dd LME7-_Clock_GetMin
	.dw 0x0d,0x0a
.code
LME7:
.code
.debug
	.dw '.stabs "Clock_GetSec:F4",36,0,0,',0,0,offset _Clock_GetSec,seg _Clock_GetSec,0x0d,0x0a
.CODE
.public _Clock_GetSec
_Clock_GetSec:	.proc
.debug
	.dw '.stabn 0x44,0,145,',0,0
	.dd LM49-_Clock_GetSec
	.dw 0x0d,0x0a
.code
LM49:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R2=BP+3
.debug
	.dw '.stabn 0x44,0,146,',0,0
	.dd LM50-_Clock_GetSec
	.dw 0x0d,0x0a
.code
LM50:
	R3=[_Clock+5]	// QImode move
	R1=R3	// QImode move
	pc=L27	// Indirect jump
.debug
	.dw '.stabn 0x44,0,147,',0,0
	.dd LM51-_Clock_GetSec
	.dw 0x0d,0x0a
.code
LM51:
.debug
	.dw '.stabn 0x44,0,147,',0,0
	.dd LM52-_Clock_GetSec
	.dw 0x0d,0x0a
.code
LM52:
L27:

	pop bp from [sp]
	retf
	.endp	// end of Clock_GetSec

.debug
	.dw '.stabf ',0,0
	.dd LME8-_Clock_GetSec
	.dw 0x0d,0x0a
.code
LME8:
.code
.debug
	.dw '.stabs "Clock_SetYear:F19",36,0,0,',0,0,offset _Clock_SetYear,seg _Clock_SetYear,0x0d,0x0a
.CODE
.public _Clock_SetYear
_Clock_SetYear:	.proc
.debug
	.dw '.stabn 0x44,0,156,',0,0
	.dd LM53-_Clock_SetYear
	.dw 0x0d,0x0a
.code
LM53:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,157,',0,0
	.dd LM54-_Clock_SetYear
	.dw 0x0d,0x0a
.code
LM54:
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	[_Clock]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,158,',0,0
	.dd LM55-_Clock_SetYear
	.dw 0x0d,0x0a
.code
LM55:
.debug
	.dw '.stabn 0x44,0,158,',0,0
	.dd LM56-_Clock_SetYear
	.dw 0x0d,0x0a
.code
LM56:
L28:

	pop bp from [sp]
	retf
	.endp	// end of Clock_SetYear

.debug
	.dw '.stabs "Year:p4",160,0,0,3',0x0d,0x0a
.CODE
.debug
	.dw '.stabf ',0,0
	.dd LME9-_Clock_SetYear
	.dw 0x0d,0x0a
.code
LME9:
.code
.debug
	.dw '.stabs "Clock_SetMon:F19",36,0,0,',0,0,offset _Clock_SetMon,seg _Clock_SetMon,0x0d,0x0a
.CODE
.public _Clock_SetMon
_Clock_SetMon:	.proc
.debug
	.dw '.stabn 0x44,0,167,',0,0
	.dd LM57-_Clock_SetMon
	.dw 0x0d,0x0a
.code
LM57:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,168,',0,0
	.dd LM58-_Clock_SetMon
	.dw 0x0d,0x0a
.code
LM58:
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	[_Clock+1]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,169,',0,0
	.dd LM59-_Clock_SetMon
	.dw 0x0d,0x0a
.code
LM59:
.debug
	.dw '.stabn 0x44,0,169,',0,0
	.dd LM60-_Clock_SetMon
	.dw 0x0d,0x0a
.code
LM60:
L29:

	pop bp from [sp]
	retf
	.endp	// end of Clock_SetMon

.debug
	.dw '.stabs "Mon:p4",160,0,0,3',0x0d,0x0a
.CODE
.debug
	.dw '.stabf ',0,0
	.dd LME10-_Clock_SetMon
	.dw 0x0d,0x0a
.code
LME10:
.code
.debug
	.dw '.stabs "Clock_SetDay:F19",36,0,0,',0,0,offset _Clock_SetDay,seg _Clock_SetDay,0x0d,0x0a
.CODE
.public _Clock_SetDay
_Clock_SetDay:	.proc
.debug
	.dw '.stabn 0x44,0,178,',0,0
	.dd LM61-_Clock_SetDay
	.dw 0x0d,0x0a
.code
LM61:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,179,',0,0
	.dd LM62-_Clock_SetDay
	.dw 0x0d,0x0a
.code
LM62:
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	[_Clock+2]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,180,',0,0
	.dd LM63-_Clock_SetDay
	.dw 0x0d,0x0a
.code
LM63:
.debug
	.dw '.stabn 0x44,0,180,',0,0
	.dd LM64-_Clock_SetDay
	.dw 0x0d,0x0a
.code
LM64:
L30:

	pop bp from [sp]
	retf
	.endp	// end of Clock_SetDay

.debug
	.dw '.stabs "Day:p4",160,0,0,3',0x0d,0x0a
.CODE
.debug
	.dw '.stabf ',0,0
	.dd LME11-_Clock_SetDay
	.dw 0x0d,0x0a
.code
LME11:
.code
.debug
	.dw '.stabs "Clock_SetHour:F19",36,0,0,',0,0,offset _Clock_SetHour,seg _Clock_SetHour,0x0d,0x0a
.CODE
.public _Clock_SetHour
_Clock_SetHour:	.proc
.debug
	.dw '.stabn 0x44,0,189,',0,0
	.dd LM65-_Clock_SetHour
	.dw 0x0d,0x0a
.code
LM65:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,190,',0,0
	.dd LM66-_Clock_SetHour
	.dw 0x0d,0x0a
.code
LM66:
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	[_Clock+3]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,191,',0,0
	.dd LM67-_Clock_SetHour
	.dw 0x0d,0x0a
.code
LM67:
.debug
	.dw '.stabn 0x44,0,191,',0,0
	.dd LM68-_Clock_SetHour
	.dw 0x0d,0x0a
.code
LM68:
L31:

	pop bp from [sp]
	retf
	.endp	// end of Clock_SetHour

.debug
	.dw '.stabs "Hour:p4",160,0,0,3',0x0d,0x0a
.CODE
.debug
	.dw '.stabf ',0,0
	.dd LME12-_Clock_SetHour
	.dw 0x0d,0x0a
.code
LME12:
.code
.debug
	.dw '.stabs "Clock_SetMin:F19",36,0,0,',0,0,offset _Clock_SetMin,seg _Clock_SetMin,0x0d,0x0a
.CODE
.public _Clock_SetMin
_Clock_SetMin:	.proc
.debug
	.dw '.stabn 0x44,0,200,',0,0
	.dd LM69-_Clock_SetMin
	.dw 0x0d,0x0a
.code
LM69:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,201,',0,0
	.dd LM70-_Clock_SetMin
	.dw 0x0d,0x0a
.code
LM70:
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	[_Clock+4]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,202,',0,0
	.dd LM71-_Clock_SetMin
	.dw 0x0d,0x0a
.code
LM71:
.debug
	.dw '.stabn 0x44,0,202,',0,0
	.dd LM72-_Clock_SetMin
	.dw 0x0d,0x0a
.code
LM72:
L32:

	pop bp from [sp]
	retf
	.endp	// end of Clock_SetMin

.debug
	.dw '.stabs "Min:p4",160,0,0,3',0x0d,0x0a
.CODE
.debug
	.dw '.stabf ',0,0
	.dd LME13-_Clock_SetMin
	.dw 0x0d,0x0a
.code
LME13:
.code
.debug
	.dw '.stabs "Clock_SetSec:F19",36,0,0,',0,0,offset _Clock_SetSec,seg _Clock_SetSec,0x0d,0x0a
.CODE
.public _Clock_SetSec
_Clock_SetSec:	.proc
.debug
	.dw '.stabn 0x44,0,211,',0,0
	.dd LM73-_Clock_SetSec
	.dw 0x0d,0x0a
.code
LM73:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,212,',0,0
	.dd LM74-_Clock_SetSec
	.dw 0x0d,0x0a
.code
LM74:
	R2=1	// QImode move
	[28687]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,213,',0,0
	.dd LM75-_Clock_SetSec
	.dw 0x0d,0x0a
.code
LM75:
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	[_Clock+5]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,214,',0,0
	.dd LM76-_Clock_SetSec
	.dw 0x0d,0x0a
.code
LM76:
	R2=0	// QImode move
	[_Clock+6]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,215,',0,0
	.dd LM77-_Clock_SetSec
	.dw 0x0d,0x0a
.code
LM77:
.debug
	.dw '.stabn 0x44,0,215,',0,0
	.dd LM78-_Clock_SetSec
	.dw 0x0d,0x0a
.code
LM78:
L33:

	pop bp from [sp]
	retf
	.endp	// end of Clock_SetSec

.debug
	.dw '.stabs "Sec:p4",160,0,0,3',0x0d,0x0a
.CODE
.debug
	.dw '.stabf ',0,0
	.dd LME14-_Clock_SetSec
	.dw 0x0d,0x0a
.code
LME14:
	.end

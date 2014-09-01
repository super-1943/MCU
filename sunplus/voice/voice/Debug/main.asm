// GCC for SUNPLUS u'nSP version 1.0.21-3
// Command: D:\PROGRA~1\Sunplus\UNSPID~1.0\cc1.exe C:\DOCUME~1\ADMINI~1\LOCALS~1\Temp\ccWWaaaa.i -fkeep-inline-functions -quiet -dumpbase main.c -mglobal-var-iram -gstabs -Wall -o .\Debug/main.asm
	.external __sn_func_ptr_sec

// gcc2_compiled.:

.debug
	.dw '.stabs "C:/Documents and Settings/Administrator/×ÀÃæ/voice/voice/",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
.code
.debug
	.dw '.stabs "C:/Documents and Settings/Administrator/×/300Ã/346/voice/voice/main.c",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
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
.public _hour
.iram
_hour:
	.dw 11
.debug
	.dw '.stabs "hour:G4",32,0,0,',0,0,offset _hour,seg _hour,0x0d,0x0a
.CODE
.public _min
.iram
_min:
	.dw 59
.debug
	.dw '.stabs "min:G1",32,0,0,',0,0,offset _min,seg _min,0x0d,0x0a
.CODE
.public _sec
.iram
_sec:
	.dw 55
.debug
	.dw '.stabs "sec:G4",32,0,0,',0,0,offset _sec,seg _sec,0x0d,0x0a
.CODE
.public _nhour
.iram
_nhour:
	.dw 12
.debug
	.dw '.stabs "nhour:G4",32,0,0,',0,0,offset _nhour,seg _nhour,0x0d,0x0a
.CODE
.public _nmin
.iram
_nmin:
	.dw 0
.debug
	.dw '.stabs "nmin:G1",32,0,0,',0,0,offset _nmin,seg _nmin,0x0d,0x0a
.CODE
.public _is_nao
.iram
_is_nao:
	.dw 0
.debug
	.dw '.stabs "is_nao:G11",32,0,0,',0,0,offset _is_nao,seg _is_nao,0x0d,0x0a
.CODE
.public _tep
.iram
_tep:
	.dw 0
.debug
	.dw '.stabs "tep:G1",32,0,0,',0,0,offset _tep,seg _tep,0x0d,0x0a
.CODE
.public _temperatureflag
.iram
_temperatureflag:
	.dw 0
.debug
	.dw '.stabs "temperatureflag:G11",32,0,0,',0,0,offset _temperatureflag,seg _temperatureflag,0x0d,0x0a
.CODE
.code
.debug
	.dw '.stabs "isrInit:F19",36,0,0,',0,0,offset _isrInit,seg _isrInit,0x0d,0x0a
.CODE
.public _isrInit
_isrInit:	.proc
.debug
	.dw '.stabn 0x44,0,21,',0,0
	.dd LM1-_isrInit
	.dw 0x0d,0x0a
.code
LM1:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,22,',0,0
	.dd LM2-_isrInit
	.dw 0x0d,0x0a
.code
LM2:
// GCC inline ASM start
	IRQ OFF
// GCC inline ASM end
.debug
	.dw '.stabn 0x44,0,23,',0,0
	.dd LM3-_isrInit
	.dw 0x0d,0x0a
.code
LM3:
	R2=[28688]	// QImode move
	R3=R2|4
	[28688]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,25,',0,0
	.dd LM4-_isrInit
	.dw 0x0d,0x0a
.code
LM4:
// GCC inline ASM start
	INT IRQ
// GCC inline ASM end
.debug
	.dw '.stabn 0x44,0,26,',0,0
	.dd LM5-_isrInit
	.dw 0x0d,0x0a
.code
LM5:
.debug
	.dw '.stabn 0x44,0,26,',0,0
	.dd LM6-_isrInit
	.dw 0x0d,0x0a
.code
LM6:
L2:

	pop bp from [sp]
	retf
	.endp	// end of isrInit

.debug
	.dw '.stabf ',0,0
	.dd LME1-_isrInit
	.dw 0x0d,0x0a
.code
LME1:
.code
.debug
	.dw '.stabs "MeatureTemp:F19",36,0,0,',0,0,offset _MeatureTemp,seg _MeatureTemp,0x0d,0x0a
.CODE
.public _MeatureTemp
_MeatureTemp:	.proc
.debug
	.dw '.stabn 0x44,0,29,',0,0
	.dd LM7-_MeatureTemp
	.dw 0x0d,0x0a
.code
LM7:
	// total=5, vars=5
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=5
	bp=sp+1

	R1=BP+8
	[bp+3]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,30,',0,0
	.dd LM8-_MeatureTemp
	.dw 0x0d,0x0a
.code
LM8:
LBB2:
	R1=[_temperatureflag]	// QImode move
	CMP R1,2	// QImode compare
	NSJNZ L4	//QImode NE
.debug
	.dw '.stabn 0x44,0,32,',0,0
	.dd LM9-_MeatureTemp
	.dw 0x0d,0x0a
.code
LM9:
LBB3:
	R1=0	// HFmode immediate to register move
	R2=0
	[BP++]=R1	// [RD]=RS HFmode, RD!=RS+1
	[BP--]=R2
.debug
	.dw '.stabn 0x44,0,33,',0,0
	.dd LM10-_MeatureTemp
	.dw 0x0d,0x0a
.code
LM10:
	R1=BP	// QImode move
	R2=BP+2
	R1=0	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,34,',0,0
	.dd LM11-_MeatureTemp
	.dw 0x0d,0x0a
.code
LM11:
	R1=0	// QImode move
	[_temperatureflag]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,35,',0,0
	.dd LM12-_MeatureTemp
	.dw 0x0d,0x0a
.code
LM12:
	call _ADtoVoltage	// call with return value
	[BP++]=R1	// [RD]=RS HFmode, RD!=RS+1
	[BP--]=R2
.debug
	.dw '.stabn 0x44,0,36,',0,0
	.dd LM13-_MeatureTemp
	.dw 0x0d,0x0a
.code
LM13:
	R1=[BP++]	// RD=[RS] HFmode, RD!=RS
	R2=[BP--]
	R3=0	// HFmode immediate to register move
	R4=17096
	push R3,R4 to [sp]	// pushhf
	push R1,R2 to [sp]	// pushhf
	call __mulf2	// call with return value
	SP = SP + 4	//SP
	[BP++]=R1	// [RD]=RS HFmode, RD!=RS+1
	[BP--]=R2
.debug
	.dw '.stabn 0x44,0,37,',0,0
	.dd LM14-_MeatureTemp
	.dw 0x0d,0x0a
.code
LM14:
	R1=BP	// QImode move
	R1=BP+2
	[bp+4]=R1	// QImode move
	R1=0	// HFmode immediate to register move
	R2=17164
	R3=[BP++]	// RD=[RS] HFmode, RD!=RS
	R4=[BP--]
	push R3,R4 to [sp]	// pushhf
	push R1,R2 to [sp]	// pushhf
	call __subf2	// call with return value
	SP = SP + 4	//SP
	R3=0	// HFmode immediate to register move
	R4=16384
	push R3,R4 to [sp]	// pushhf
	push R1,R2 to [sp]	// pushhf
	call __divf2	// call with return value
	SP = SP + 4	//SP
	push R1,R2 to [sp]	// pushhf
	call __cvf2i1	// call with return value
	SP = SP + 2	//SP
	R2=[bp+4]	// QImode move
	[R2]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,38,',0,0
	.dd LM15-_MeatureTemp
	.dw 0x0d,0x0a
.code
LM15:
	R1=BP	// QImode move
	R2=BP+2
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[_tep]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,39,',0,0
	.dd LM16-_MeatureTemp
	.dw 0x0d,0x0a
.code
LM16:
LBE3:
L4:
.debug
	.dw '.stabn 0x44,0,40,',0,0
	.dd LM17-_MeatureTemp
	.dw 0x0d,0x0a
.code
LM17:
LBE2:
.debug
	.dw '.stabn 0x44,0,40,',0,0
	.dd LM18-_MeatureTemp
	.dw 0x0d,0x0a
.code
LM18:
L3:

	sp+=5
	pop bp from [sp]
	retf
	.endp	// end of MeatureTemp

.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB2-_MeatureTemp
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB3-_MeatureTemp
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "temperature:12",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "shownum:1",128,0,0,2',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE3-_MeatureTemp
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE2-_MeatureTemp
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME2-_MeatureTemp
	.dw 0x0d,0x0a
.code
LME2:
.code
.debug
	.dw '.stabs "main:F19",36,0,0,',0,0,offset _main,seg _main,0x0d,0x0a
.CODE
.public _main
_main:	.proc
.debug
	.dw '.stabn 0x44,0,42,',0,0
	.dd LM19-_main
	.dw 0x0d,0x0a
.code
LM19:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,43,',0,0
	.dd LM20-_main
	.dw 0x0d,0x0a
.code
LM20:
	R1=152	// QImode move
	[28691]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,44,',0,0
	.dd LM21-_main
	.dw 0x0d,0x0a
.code
LM21:
	R1=100	// QImode move
	[SP--]=R1	// QImode move
	call _DelayTime	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,46,',0,0
	.dd LM22-_main
	.dw 0x0d,0x0a
.code
LM22:
	call _isrInit	// call without return value
.debug
	.dw '.stabn 0x44,0,47,',0,0
	.dd LM23-_main
	.dw 0x0d,0x0a
.code
LM23:
	call _disp_Init	// call without return value
.debug
	.dw '.stabn 0x44,0,48,',0,0
	.dd LM24-_main
	.dw 0x0d,0x0a
.code
LM24:
	call _ADInit	// call without return value
.debug
	.dw '.stabn 0x44,0,49,',0,0
	.dd LM25-_main
	.dw 0x0d,0x0a
.code
LM25:
L7:
	R2=[28672]	// QImode move
	R1=R2&15
	CMP R1,15	// QImode compare
	NSJZ L9	//QImode EQ
	pc=L8	// Indirect jump
L9:
.debug
	.dw '.stabn 0x44,0,51,',0,0
	.dd LM26-_main
	.dw 0x0d,0x0a
.code
LM26:
	call _disp_ID	// call without return value
.debug
	.dw '.stabn 0x44,0,52,',0,0
	.dd LM27-_main
	.dw 0x0d,0x0a
.code
LM27:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,53,',0,0
	.dd LM28-_main
	.dw 0x0d,0x0a
.code
LM28:
	pc=L7	// Indirect jump
L8:
.debug
	.dw '.stabn 0x44,0,54,',0,0
	.dd LM29-_main
	.dw 0x0d,0x0a
.code
LM29:
	R1=100	// QImode move
	[SP--]=R1	// QImode move
	call _DelayTime	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,55,',0,0
	.dd LM30-_main
	.dw 0x0d,0x0a
.code
LM30:
L10:
	R2=[28672]	// QImode move
	R1=R2&15
	CMP R1,15	// QImode compare
	NSJNZ L12	//QImode NE
	pc=L11	// Indirect jump
L12:
.debug
	.dw '.stabn 0x44,0,56,',0,0
	.dd LM31-_main
	.dw 0x0d,0x0a
.code
LM31:
	R1=1	// QImode move
	[28690]=R1	// QImode move
	pc=L10	// Indirect jump
L11:
.debug
	.dw '.stabn 0x44,0,57,',0,0
	.dd LM32-_main
	.dw 0x0d,0x0a
.code
LM32:
L13:
	pc=L15	// Indirect jump
	pc=L14	// Indirect jump
L15:
.debug
	.dw '.stabn 0x44,0,59,',0,0
	.dd LM33-_main
	.dw 0x0d,0x0a
.code
LM33:
	call _ModeSel	// call without return value
.debug
	.dw '.stabn 0x44,0,60,',0,0
	.dd LM34-_main
	.dw 0x0d,0x0a
.code
LM34:
	call _clock	// call without return value
.debug
	.dw '.stabn 0x44,0,61,',0,0
	.dd LM35-_main
	.dw 0x0d,0x0a
.code
LM35:
	call _MeatureTemp	// call without return value
.debug
	.dw '.stabn 0x44,0,62,',0,0
	.dd LM36-_main
	.dw 0x0d,0x0a
.code
LM36:
	R1=[_nflag]	// QImode move
	CMP R1,0	// QImode test
	NSJNZ L16	//QImode NE
.debug
	.dw '.stabn 0x44,0,63,',0,0
	.dd LM37-_main
	.dw 0x0d,0x0a
.code
LM37:
	R1=[_sec]	// QImode move
	[SP--]=R1	// QImode move
	R1=[_min]	// QImode move
	[SP--]=R1	// QImode move
	R1=[_hour]	// QImode move
	[SP--]=R1	// QImode move
	R1=[_tep]	// QImode move
	[SP--]=R1	// QImode move
	call _disp	// call without return value
	SP = SP + 4	//SP
	pc=L17	// Indirect jump
L16:
.debug
	.dw '.stabn 0x44,0,66,',0,0
	.dd LM38-_main
	.dw 0x0d,0x0a
.code
LM38:
	R1=[_sec]	// QImode move
	[SP--]=R1	// QImode move
	R1=[_nmin]	// QImode move
	[SP--]=R1	// QImode move
	R1=[_nhour]	// QImode move
	[SP--]=R1	// QImode move
	R1=[_tep]	// QImode move
	[SP--]=R1	// QImode move
	call _disp	// call without return value
	SP = SP + 4	//SP
L17:
.debug
	.dw '.stabn 0x44,0,68,',0,0
	.dd LM39-_main
	.dw 0x0d,0x0a
.code
LM39:
	call _nclock	// call without return value
.debug
	.dw '.stabn 0x44,0,69,',0,0
	.dd LM40-_main
	.dw 0x0d,0x0a
.code
LM40:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,70,',0,0
	.dd LM41-_main
	.dw 0x0d,0x0a
.code
LM41:
	pc=L13	// Indirect jump
L14:
.debug
	.dw '.stabn 0x44,0,73,',0,0
	.dd LM42-_main
	.dw 0x0d,0x0a
.code
LM42:
.debug
	.dw '.stabn 0x44,0,73,',0,0
	.dd LM43-_main
	.dw 0x0d,0x0a
.code
LM43:
L6:

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
.external _nclock
.external _disp
.external _nflag
.external _clock
.external _ModeSel
.external _disp_ID
.external _ADInit
.external _disp_Init
.external _DelayTime
.external _ADtoVoltage
.external __cvf2i1
.external __divf2
.external __subf2
.external __mulf2
	.end

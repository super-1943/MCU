// GCC for SUNPLUS u'nSP version 1.0.21-3
// Command: C:\PROGRA~1\Sunplus\UNSPID~1.0\cc1.exe C:\DOCUME~1\ADMINI~1\LOCALS~1\Temp\cc0qaaaa.i -fkeep-inline-functions -quiet -dumpbase Clock_Speech.c -mglobal-var-iram -gstabs -Wall -o .\Debug/Clock_Speech.asm
	.external __sn_func_ptr_sec

// gcc2_compiled.:

.debug
	.dw '.stabs "F:/myproject/lingyang/sound/",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
.code
.debug
	.dw '.stabs "F:/myproject/lingyang/sound/Clock_Speech.c",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
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
	.dw '.stabs "SndIndex:T20=eS_0:0,S_1:1,S_2:2,\\",128,0,0,0',0x0d,0x0a
	.DW '.stabs "S_3:3,S_4:4,S_5:5,S_6:6,\\",128,0,0,0',0x0d,0x0a
	.DW '.stabs "S_7:7,S_8:8,S_9:9,S_10:10,\\",128,0,0,0',0x0d,0x0a
	.DW '.stabs "S_11:11,S_12:12,S_Liang:13,S_DING:14,\\",128,0,0,0',0x0d,0x0a
	.DW '.stabs "S_XZSK:15,S_LC:16,S_SW:17,S_XW:18,\\",128,0,0,0',0x0d,0x0a
	.DW '.stabs "S_WS:19,S_Nian:20,S_Yue:21,S_Ri:22,\\",128,0,0,0',0x0d,0x0a
	.DW '.stabs "S_Dian:23,S_Fen:24,S_Miao:25,S_Zheng:26,;",128,0,0,0',0x0d,0x0a
.CODE
.code
.debug
	.dw '.stabs "PlayNum:F19",36,0,0,',0,0,offset _PlayNum,seg _PlayNum,0x0d,0x0a
.CODE
.public _PlayNum
_PlayNum:	.proc
.debug
	.dw '.stabn 0x44,0,17,',0,0
	.dd LM1-_PlayNum
	.dw 0x0d,0x0a
.code
LM1:
	// total=2, vars=2
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=2
	bp=sp+1

	R1=BP+5
	[bp+1]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,18,',0,0
	.dd LM2-_PlayNum
	.dw 0x0d,0x0a
.code
LM2:
LBB2:
	R2=[bp+1]	// QImode move
	R1=[R2]	// QImode move
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,20,',0,0
	.dd LM3-_PlayNum
	.dw 0x0d,0x0a
.code
LM3:
	R1=[BP]	// QImode move
	CMP R1,0	// QImode test
	NSJNZ L3	//QImode NE
.debug
	.dw '.stabn 0x44,0,21,',0,0
	.dd LM4-_PlayNum
	.dw 0x0d,0x0a
.code
LM4:
	R1=0	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd	// call without return value
	SP = SP + 1	//SP
	pc=L4	// Indirect jump
L3:
.debug
	.dw '.stabn 0x44,0,24,',0,0
	.dd LM5-_PlayNum
	.dw 0x0d,0x0a
.code
LM5:
	R1=[BP]	// QImode move
	CMP R1,19	// QImode compare
	NSJNA L5	//QImode LEU
	R1=[BP]	// QImode move
	R2=10	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __divu1	// call with return value
	SP = SP + 2	//SP
	[SP--]=R1	// QImode move
	call _PlaySnd	// call without return value
	SP = SP + 1	//SP
L5:
.debug
	.dw '.stabn 0x44,0,25,',0,0
	.dd LM6-_PlayNum
	.dw 0x0d,0x0a
.code
LM6:
	R1=[BP]	// QImode move
	CMP R1,9	// QImode compare
	NSJNA L6	//QImode LEU
	R1=10	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd	// call without return value
	SP = SP + 1	//SP
L6:
.debug
	.dw '.stabn 0x44,0,26,',0,0
	.dd LM7-_PlayNum
	.dw 0x0d,0x0a
.code
LM7:
	R1=[BP]	// QImode move
	R2=10	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __modu1	// call with return value
	SP = SP + 2	//SP
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,27,',0,0
	.dd LM8-_PlayNum
	.dw 0x0d,0x0a
.code
LM8:
	R1=[BP]	// QImode move
	CMP R1,0	// QImode test
	NSJZ L4	//QImode EQ
	R1=[BP]	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd	// call without return value
	SP = SP + 1	//SP
L7:
L4:
.debug
	.dw '.stabn 0x44,0,29,',0,0
	.dd LM9-_PlayNum
	.dw 0x0d,0x0a
.code
LM9:
LBE2:
.debug
	.dw '.stabn 0x44,0,29,',0,0
	.dd LM10-_PlayNum
	.dw 0x0d,0x0a
.code
LM10:
L2:

	sp+=2
	pop bp from [sp]
	retf
	.endp	// end of PlayNum

.debug
	.dw '.stabs "Num:p4",160,0,0,5',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB2-_PlayNum
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "TempNum:4",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE2-_PlayNum
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME1-_PlayNum
	.dw 0x0d,0x0a
.code
LME1:
.code
.debug
	.dw '.stabs "PlayYear:F19",36,0,0,',0,0,offset _PlayYear,seg _PlayYear,0x0d,0x0a
.CODE
.public _PlayYear
_PlayYear:	.proc
.debug
	.dw '.stabn 0x44,0,38,',0,0
	.dd LM11-_PlayYear
	.dw 0x0d,0x0a
.code
LM11:
	// total=2, vars=2
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=2
	bp=sp+1

	R1=BP+5
	[bp+1]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,39,',0,0
	.dd LM12-_PlayYear
	.dw 0x0d,0x0a
.code
LM12:
LBB3:
	R2=[bp+1]	// QImode move
	R1=[R2]	// QImode move
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,41,',0,0
	.dd LM13-_PlayYear
	.dw 0x0d,0x0a
.code
LM13:
	R1=[BP]	// QImode move
	R2=1000	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __divu1	// call with return value
	SP = SP + 2	//SP
	[SP--]=R1	// QImode move
	call _PlaySnd	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,42,',0,0
	.dd LM14-_PlayYear
	.dw 0x0d,0x0a
.code
LM14:
	R1=[BP]	// QImode move
	R2=1000	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __modu1	// call with return value
	SP = SP + 2	//SP
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,43,',0,0
	.dd LM15-_PlayYear
	.dw 0x0d,0x0a
.code
LM15:
	R1=[BP]	// QImode move
	R2=100	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __divu1	// call with return value
	SP = SP + 2	//SP
	[SP--]=R1	// QImode move
	call _PlaySnd	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,44,',0,0
	.dd LM16-_PlayYear
	.dw 0x0d,0x0a
.code
LM16:
	R1=[BP]	// QImode move
	R2=100	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __modu1	// call with return value
	SP = SP + 2	//SP
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,45,',0,0
	.dd LM17-_PlayYear
	.dw 0x0d,0x0a
.code
LM17:
	R1=[BP]	// QImode move
	R2=10	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __divu1	// call with return value
	SP = SP + 2	//SP
	[SP--]=R1	// QImode move
	call _PlaySnd	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,46,',0,0
	.dd LM18-_PlayYear
	.dw 0x0d,0x0a
.code
LM18:
	R1=[BP]	// QImode move
	R2=10	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __modu1	// call with return value
	SP = SP + 2	//SP
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,47,',0,0
	.dd LM19-_PlayYear
	.dw 0x0d,0x0a
.code
LM19:
	R1=[BP]	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,48,',0,0
	.dd LM20-_PlayYear
	.dw 0x0d,0x0a
.code
LM20:
	R1=20	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,49,',0,0
	.dd LM21-_PlayYear
	.dw 0x0d,0x0a
.code
LM21:
LBE3:
.debug
	.dw '.stabn 0x44,0,49,',0,0
	.dd LM22-_PlayYear
	.dw 0x0d,0x0a
.code
LM22:
L12:

	sp+=2
	pop bp from [sp]
	retf
	.endp	// end of PlayYear

.debug
	.dw '.stabs "Year:p4",160,0,0,5',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB3-_PlayYear
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "TempYear:4",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE3-_PlayYear
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME2-_PlayYear
	.dw 0x0d,0x0a
.code
LME2:
.code
.debug
	.dw '.stabs "PlayMon:F19",36,0,0,',0,0,offset _PlayMon,seg _PlayMon,0x0d,0x0a
.CODE
.public _PlayMon
_PlayMon:	.proc
.debug
	.dw '.stabn 0x44,0,58,',0,0
	.dd LM23-_PlayMon
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
	.dw '.stabn 0x44,0,59,',0,0
	.dd LM24-_PlayMon
	.dw 0x0d,0x0a
.code
LM24:
	R2=[BP]	// QImode move
	R1=[R2]	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,60,',0,0
	.dd LM25-_PlayMon
	.dw 0x0d,0x0a
.code
LM25:
	R1=21	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,61,',0,0
	.dd LM26-_PlayMon
	.dw 0x0d,0x0a
.code
LM26:
.debug
	.dw '.stabn 0x44,0,61,',0,0
	.dd LM27-_PlayMon
	.dw 0x0d,0x0a
.code
LM27:
L13:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of PlayMon

.debug
	.dw '.stabs "Mon:p4",160,0,0,4',0x0d,0x0a
.CODE
.debug
	.dw '.stabf ',0,0
	.dd LME3-_PlayMon
	.dw 0x0d,0x0a
.code
LME3:
.code
.debug
	.dw '.stabs "PlayDay:F19",36,0,0,',0,0,offset _PlayDay,seg _PlayDay,0x0d,0x0a
.CODE
.public _PlayDay
_PlayDay:	.proc
.debug
	.dw '.stabn 0x44,0,70,',0,0
	.dd LM28-_PlayDay
	.dw 0x0d,0x0a
.code
LM28:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,71,',0,0
	.dd LM29-_PlayDay
	.dw 0x0d,0x0a
.code
LM29:
	R2=[BP]	// QImode move
	R1=[R2]	// QImode move
	[SP--]=R1	// QImode move
	call _PlayNum	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,72,',0,0
	.dd LM30-_PlayDay
	.dw 0x0d,0x0a
.code
LM30:
	R1=22	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,73,',0,0
	.dd LM31-_PlayDay
	.dw 0x0d,0x0a
.code
LM31:
.debug
	.dw '.stabn 0x44,0,73,',0,0
	.dd LM32-_PlayDay
	.dw 0x0d,0x0a
.code
LM32:
L14:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of PlayDay

.debug
	.dw '.stabs "Day:p4",160,0,0,4',0x0d,0x0a
.CODE
.debug
	.dw '.stabf ',0,0
	.dd LME4-_PlayDay
	.dw 0x0d,0x0a
.code
LME4:
.code
.debug
	.dw '.stabs "PlayHour:F19",36,0,0,',0,0,offset _PlayHour,seg _PlayHour,0x0d,0x0a
.CODE
.public _PlayHour
_PlayHour:	.proc
.debug
	.dw '.stabn 0x44,0,82,',0,0
	.dd LM33-_PlayHour
	.dw 0x0d,0x0a
.code
LM33:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,83,',0,0
	.dd LM34-_PlayHour
	.dw 0x0d,0x0a
.code
LM34:
	R2=[BP]	// QImode move
	R1=[R2]	// QImode move
	CMP R1,5	// QImode compare
	NSJA L16	//QImode GTU
	R1=16	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd	// call without return value
	SP = SP + 1	//SP
	pc=L17	// Indirect jump
L16:
.debug
	.dw '.stabn 0x44,0,84,',0,0
	.dd LM35-_PlayHour
	.dw 0x0d,0x0a
.code
LM35:
	R2=[BP]	// QImode move
	R1=[R2]	// QImode move
	CMP R1,11	// QImode compare
	NSJA L18	//QImode GTU
	R1=17	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd	// call without return value
	SP = SP + 1	//SP
	pc=L17	// Indirect jump
L18:
.debug
	.dw '.stabn 0x44,0,85,',0,0
	.dd LM36-_PlayHour
	.dw 0x0d,0x0a
.code
LM36:
	R2=[BP]	// QImode move
	R1=[R2]	// QImode move
	CMP R1,17	// QImode compare
	NSJA L20	//QImode GTU
	R1=18	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd	// call without return value
	SP = SP + 1	//SP
	pc=L17	// Indirect jump
L20:
.debug
	.dw '.stabn 0x44,0,86,',0,0
	.dd LM37-_PlayHour
	.dw 0x0d,0x0a
.code
LM37:
	R1=19	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd	// call without return value
	SP = SP + 1	//SP
L21:
L19:
L17:
.debug
	.dw '.stabn 0x44,0,88,',0,0
	.dd LM38-_PlayHour
	.dw 0x0d,0x0a
.code
LM38:
	R2=[BP]	// QImode move
	R1=[R2]	// QImode move
	CMP R1,2	// QImode compare
	NSJZ L23	//QImode EQ
	R2=[BP]	// QImode move
	R1=[R2]	// QImode move
	CMP R1,14	// QImode compare
	NSJZ L23	//QImode EQ
	pc=L22	// Indirect jump
L23:
	R1=13	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd	// call without return value
	SP = SP + 1	//SP
	pc=L24	// Indirect jump
L22:
.debug
	.dw '.stabn 0x44,0,89,',0,0
	.dd LM39-_PlayHour
	.dw 0x0d,0x0a
.code
LM39:
	R2=[BP]	// QImode move
	R1=[R2]	// QImode move
	CMP R1,12	// QImode compare
	NSJNA L25	//QImode LEU
	R1=[BP]	// QImode move
	R2=[R1]	// QImode move
	R1=R2+(-12)
	[SP--]=R1	// QImode move
	call _PlaySnd	// call without return value
	SP = SP + 1	//SP
	pc=L24	// Indirect jump
L25:
.debug
	.dw '.stabn 0x44,0,90,',0,0
	.dd LM40-_PlayHour
	.dw 0x0d,0x0a
.code
LM40:
	R2=[BP]	// QImode move
	R1=[R2]	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd	// call without return value
	SP = SP + 1	//SP
L26:
L24:
.debug
	.dw '.stabn 0x44,0,91,',0,0
	.dd LM41-_PlayHour
	.dw 0x0d,0x0a
.code
LM41:
	R1=23	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,92,',0,0
	.dd LM42-_PlayHour
	.dw 0x0d,0x0a
.code
LM42:
.debug
	.dw '.stabn 0x44,0,92,',0,0
	.dd LM43-_PlayHour
	.dw 0x0d,0x0a
.code
LM43:
L15:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of PlayHour

.debug
	.dw '.stabs "Hour:p4",160,0,0,4',0x0d,0x0a
.CODE
.debug
	.dw '.stabf ',0,0
	.dd LME5-_PlayHour
	.dw 0x0d,0x0a
.code
LME5:
.code
.debug
	.dw '.stabs "PlayMin:F19",36,0,0,',0,0,offset _PlayMin,seg _PlayMin,0x0d,0x0a
.CODE
.public _PlayMin
_PlayMin:	.proc
.debug
	.dw '.stabn 0x44,0,101,',0,0
	.dd LM44-_PlayMin
	.dw 0x0d,0x0a
.code
LM44:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,102,',0,0
	.dd LM45-_PlayMin
	.dw 0x0d,0x0a
.code
LM45:
	R2=[BP]	// QImode move
	R1=[R2]	// QImode move
	CMP R1,0	// QImode test
	NSJNZ L34	//QImode NE
	R1=26	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd	// call without return value
	SP = SP + 1	//SP
	pc=L35	// Indirect jump
L34:
.debug
	.dw '.stabn 0x44,0,105,',0,0
	.dd LM46-_PlayMin
	.dw 0x0d,0x0a
.code
LM46:
	R2=[BP]	// QImode move
	R1=[R2]	// QImode move
	[SP--]=R1	// QImode move
	call _PlayNum	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,106,',0,0
	.dd LM47-_PlayMin
	.dw 0x0d,0x0a
.code
LM47:
	R1=24	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd	// call without return value
	SP = SP + 1	//SP
L35:
.debug
	.dw '.stabn 0x44,0,108,',0,0
	.dd LM48-_PlayMin
	.dw 0x0d,0x0a
.code
LM48:
.debug
	.dw '.stabn 0x44,0,108,',0,0
	.dd LM49-_PlayMin
	.dw 0x0d,0x0a
.code
LM49:
L33:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of PlayMin

.debug
	.dw '.stabs "Min:p4",160,0,0,4',0x0d,0x0a
.CODE
.debug
	.dw '.stabf ',0,0
	.dd LME6-_PlayMin
	.dw 0x0d,0x0a
.code
LME6:
.code
.debug
	.dw '.stabs "PlaySec:F19",36,0,0,',0,0,offset _PlaySec,seg _PlaySec,0x0d,0x0a
.CODE
.public _PlaySec
_PlaySec:	.proc
.debug
	.dw '.stabn 0x44,0,117,',0,0
	.dd LM50-_PlaySec
	.dw 0x0d,0x0a
.code
LM50:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,118,',0,0
	.dd LM51-_PlaySec
	.dw 0x0d,0x0a
.code
LM51:
	R2=[BP]	// QImode move
	R1=[R2]	// QImode move
	[SP--]=R1	// QImode move
	call _PlayNum	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,119,',0,0
	.dd LM52-_PlaySec
	.dw 0x0d,0x0a
.code
LM52:
	R1=25	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,120,',0,0
	.dd LM53-_PlaySec
	.dw 0x0d,0x0a
.code
LM53:
.debug
	.dw '.stabn 0x44,0,120,',0,0
	.dd LM54-_PlaySec
	.dw 0x0d,0x0a
.code
LM54:
L37:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of PlaySec

.debug
	.dw '.stabs "Sec:p4",160,0,0,4',0x0d,0x0a
.CODE
.debug
	.dw '.stabf ',0,0
	.dd LME7-_PlaySec
	.dw 0x0d,0x0a
.code
LME7:
.code
.debug
	.dw '.stabs "PlayTime:F19",36,0,0,',0,0,offset _PlayTime,seg _PlayTime,0x0d,0x0a
.CODE
.public _PlayTime
_PlayTime:	.proc
.debug
	.dw '.stabn 0x44,0,129,',0,0
	.dd LM55-_PlayTime
	.dw 0x0d,0x0a
.code
LM55:
	// total=3, vars=3
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=3
	bp=sp+1

	R1=BP+6
	[bp+2]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,130,',0,0
	.dd LM56-_PlayTime
	.dw 0x0d,0x0a
.code
LM56:
LBB4:
.debug
	.dw '.stabn 0x44,0,132,',0,0
	.dd LM57-_PlayTime
	.dw 0x0d,0x0a
.code
LM57:
	call _Clock_GetHour	// call with return value
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,133,',0,0
	.dd LM58-_PlayTime
	.dw 0x0d,0x0a
.code
LM58:
	call _Clock_GetMin	// call with return value
	R2=BP	// QImode move
	R3=BP+1
	R2=R3	// QImode move
	[R2]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,135,',0,0
	.dd LM59-_PlayTime
	.dw 0x0d,0x0a
.code
LM59:
	R1=14	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,136,',0,0
	.dd LM60-_PlayTime
	.dw 0x0d,0x0a
.code
LM60:
	R1=15	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,137,',0,0
	.dd LM61-_PlayTime
	.dw 0x0d,0x0a
.code
LM61:
	R1=[BP]	// QImode move
	[SP--]=R1	// QImode move
	call _PlayHour	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,138,',0,0
	.dd LM62-_PlayTime
	.dw 0x0d,0x0a
.code
LM62:
	R1=BP	// QImode move
	R2=BP+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	call _PlayMin	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,139,',0,0
	.dd LM63-_PlayTime
	.dw 0x0d,0x0a
.code
LM63:
LBE4:
.debug
	.dw '.stabn 0x44,0,139,',0,0
	.dd LM64-_PlayTime
	.dw 0x0d,0x0a
.code
LM64:
L38:

	sp+=3
	pop bp from [sp]
	retf
	.endp	// end of PlayTime

.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB4-_PlayTime
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "TempHour:4",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "TempMin:4",128,0,0,1',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE4-_PlayTime
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME8-_PlayTime
	.dw 0x0d,0x0a
.code
LME8:
.code
.debug
	.dw '.stabs "PlayDate:F19",36,0,0,',0,0,offset _PlayDate,seg _PlayDate,0x0d,0x0a
.CODE
.public _PlayDate
_PlayDate:	.proc
.debug
	.dw '.stabn 0x44,0,148,',0,0
	.dd LM65-_PlayDate
	.dw 0x0d,0x0a
.code
LM65:
	// total=4, vars=4
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=4
	bp=sp+1

	R1=BP+7
	[bp+3]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,149,',0,0
	.dd LM66-_PlayDate
	.dw 0x0d,0x0a
.code
LM66:
LBB5:
.debug
	.dw '.stabn 0x44,0,151,',0,0
	.dd LM67-_PlayDate
	.dw 0x0d,0x0a
.code
LM67:
	call _Clock_GetYear	// call with return value
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,152,',0,0
	.dd LM68-_PlayDate
	.dw 0x0d,0x0a
.code
LM68:
	call _Clock_GetMon	// call with return value
	R2=BP	// QImode move
	R3=BP+1
	R2=R3	// QImode move
	[R2]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,153,',0,0
	.dd LM69-_PlayDate
	.dw 0x0d,0x0a
.code
LM69:
	call _Clock_GetDay	// call with return value
	R2=BP	// QImode move
	R3=BP+2
	R2=R3	// QImode move
	[R2]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,155,',0,0
	.dd LM70-_PlayDate
	.dw 0x0d,0x0a
.code
LM70:
	R1=[BP]	// QImode move
	[SP--]=R1	// QImode move
	call _PlayYear	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,156,',0,0
	.dd LM71-_PlayDate
	.dw 0x0d,0x0a
.code
LM71:
	R1=BP	// QImode move
	R2=BP+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	call _PlayMon	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,157,',0,0
	.dd LM72-_PlayDate
	.dw 0x0d,0x0a
.code
LM72:
	R1=BP	// QImode move
	R2=BP+2
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	call _PlayDay	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,158,',0,0
	.dd LM73-_PlayDate
	.dw 0x0d,0x0a
.code
LM73:
LBE5:
.debug
	.dw '.stabn 0x44,0,158,',0,0
	.dd LM74-_PlayDate
	.dw 0x0d,0x0a
.code
LM74:
L39:

	sp+=4
	pop bp from [sp]
	retf
	.endp	// end of PlayDate

.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB5-_PlayDate
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "TempYear:4",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "TempMon:4",128,0,0,1',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "TempDay:4",128,0,0,2',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE5-_PlayDate
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME9-_PlayDate
	.dw 0x0d,0x0a
.code
LME9:
.external _Clock_GetDay
.external _Clock_GetMon
.external _Clock_GetYear
.external _Clock_GetMin
.external _Clock_GetHour
.external _PlaySnd
.external __modu1
.external __divu1
	.end

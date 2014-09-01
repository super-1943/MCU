// GCC for SUNPLUS u'nSP version 1.0.21-3
// Command: C:\PROGRA~1\Sunplus\UNSPID~1.0\cc1.exe C:\DOCUME~1\ADMINI~1\LOCALS~1\Temp\ccclaaaa.i -fkeep-inline-functions -quiet -dumpbase Clock_Adjust.c -mglobal-var-iram -gstabs -Wall -o .\Debug/Clock_Adjust.asm
	.external __sn_func_ptr_sec

// gcc2_compiled.:

.debug
	.dw '.stabs "F:/myproject/lingyang/sound/",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
.code
.debug
	.dw '.stabs "F:/myproject/lingyang/sound/Clock_Adjust.c",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
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
	.dw '.stabs "AdjustYear:F4",36,0,0,',0,0,offset _AdjustYear,seg _AdjustYear,0x0d,0x0a
.CODE
.public _AdjustYear
_AdjustYear:	.proc
.debug
	.dw '.stabn 0x44,0,20,',0,0
	.dd LM1-_AdjustYear
	.dw 0x0d,0x0a
.code
LM1:
	// total=3, vars=3
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=3
	bp=sp+1

	R1=BP+6
	[bp+2]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,21,',0,0
	.dd LM2-_AdjustYear
	.dw 0x0d,0x0a
.code
LM2:
LBB2:
.debug
	.dw '.stabn 0x44,0,22,',0,0
	.dd LM3-_AdjustYear
	.dw 0x0d,0x0a
.code
LM3:
	R1=BP	// QImode move
	R2=BP+1
	R3=[bp+2]	// QImode move
	R1=[R3]	// QImode move
	R4=R2	// QImode move
	[R4]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,24,',0,0
	.dd LM4-_AdjustYear
	.dw 0x0d,0x0a
.code
LM4:
	R1=BP	// QImode move
	R2=BP+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	call _PlayYear	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,25,',0,0
	.dd LM5-_AdjustYear
	.dw 0x0d,0x0a
.code
LM5:
L3:
	pc=L5	// Indirect jump
	pc=L4	// Indirect jump
L5:
.debug
	.dw '.stabn 0x44,0,27,',0,0
	.dd LM6-_AdjustYear
	.dw 0x0d,0x0a
.code
LM6:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,28,',0,0
	.dd LM7-_AdjustYear
	.dw 0x0d,0x0a
.code
LM7:
	call _Key_Get	// call with return value
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,29,',0,0
	.dd LM8-_AdjustYear
	.dw 0x0d,0x0a
.code
LM8:
	R1=[BP]	// QImode move
	CMP R1,2	// QImode compare
	NSJZ L8	//QImode EQ
	CMP R1,2	// QImode compare
	NSJA L12	//QImode GTU
	CMP R1,1	// QImode compare
	NSJZ L7	//QImode EQ
	pc=L10	// Indirect jump
L12:
	CMP R1,4	// QImode compare
	NSJZ L9	//QImode EQ
	pc=L10	// Indirect jump
L7:
.debug
	.dw '.stabn 0x44,0,32,',0,0
	.dd LM9-_AdjustYear
	.dw 0x0d,0x0a
.code
LM9:
	R1=BP	// QImode move
	R2=BP+1
	R4=R2	// QImode move
	R3=[R4]	// QImode move
	R1=R3	// QImode move
	pc=L2	// Indirect jump
L8:
.debug
	.dw '.stabn 0x44,0,34,',0,0
	.dd LM10-_AdjustYear
	.dw 0x0d,0x0a
.code
LM10:
	R1=BP	// QImode move
	R2=BP+1
	R3=BP	// QImode move
	R1=BP+1
	R2=BP	// QImode move
	R3=BP+1
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R3=R2+1
	R2=R1	// QImode move
	[R2]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,35,',0,0
	.dd LM11-_AdjustYear
	.dw 0x0d,0x0a
.code
LM11:
	R1=BP	// QImode move
	R2=BP+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	call _PlayYear	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,36,',0,0
	.dd LM12-_AdjustYear
	.dw 0x0d,0x0a
.code
LM12:
	pc=L6	// Indirect jump
L9:
.debug
	.dw '.stabn 0x44,0,38,',0,0
	.dd LM13-_AdjustYear
	.dw 0x0d,0x0a
.code
LM13:
	R1=BP	// QImode move
	R2=BP+1
	R3=BP	// QImode move
	R1=BP+1
	R2=BP	// QImode move
	R3=BP+1
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R3=R2+(-1)
	R2=R1	// QImode move
	[R2]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,39,',0,0
	.dd LM14-_AdjustYear
	.dw 0x0d,0x0a
.code
LM14:
	R1=BP	// QImode move
	R2=BP+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	call _PlayYear	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,40,',0,0
	.dd LM15-_AdjustYear
	.dw 0x0d,0x0a
.code
LM15:
	pc=L6	// Indirect jump
L10:
.debug
	.dw '.stabn 0x44,0,42,',0,0
	.dd LM16-_AdjustYear
	.dw 0x0d,0x0a
.code
LM16:
	pc=L6	// Indirect jump
L6:
.debug
	.dw '.stabn 0x44,0,44,',0,0
	.dd LM17-_AdjustYear
	.dw 0x0d,0x0a
.code
LM17:
	pc=L3	// Indirect jump
L4:
.debug
	.dw '.stabn 0x44,0,45,',0,0
	.dd LM18-_AdjustYear
	.dw 0x0d,0x0a
.code
LM18:
LBE2:
.debug
	.dw '.stabn 0x44,0,45,',0,0
	.dd LM19-_AdjustYear
	.dw 0x0d,0x0a
.code
LM19:
L2:

	sp+=3
	pop bp from [sp]
	retf
	.endp	// end of AdjustYear

.debug
	.dw '.stabs "Year:p4",160,0,0,6',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB2-_AdjustYear
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "KeyCode:4",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "TempYear:4",128,0,0,1',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE2-_AdjustYear
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME1-_AdjustYear
	.dw 0x0d,0x0a
.code
LME1:
.code
.debug
	.dw '.stabs "AdjustMon:F4",36,0,0,',0,0,offset _AdjustMon,seg _AdjustMon,0x0d,0x0a
.CODE
.public _AdjustMon
_AdjustMon:	.proc
.debug
	.dw '.stabn 0x44,0,54,',0,0
	.dd LM20-_AdjustMon
	.dw 0x0d,0x0a
.code
LM20:
	// total=3, vars=3
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=3
	bp=sp+1

	R1=BP+6
	[bp+2]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,55,',0,0
	.dd LM21-_AdjustMon
	.dw 0x0d,0x0a
.code
LM21:
LBB3:
.debug
	.dw '.stabn 0x44,0,56,',0,0
	.dd LM22-_AdjustMon
	.dw 0x0d,0x0a
.code
LM22:
	R1=BP	// QImode move
	R2=BP+1
	R3=[bp+2]	// QImode move
	R1=[R3]	// QImode move
	R4=R2	// QImode move
	[R4]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,58,',0,0
	.dd LM23-_AdjustMon
	.dw 0x0d,0x0a
.code
LM23:
	R1=BP	// QImode move
	R2=BP+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	call _PlayMon	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,59,',0,0
	.dd LM24-_AdjustMon
	.dw 0x0d,0x0a
.code
LM24:
L18:
	pc=L20	// Indirect jump
	pc=L19	// Indirect jump
L20:
.debug
	.dw '.stabn 0x44,0,61,',0,0
	.dd LM25-_AdjustMon
	.dw 0x0d,0x0a
.code
LM25:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,62,',0,0
	.dd LM26-_AdjustMon
	.dw 0x0d,0x0a
.code
LM26:
	call _Key_Get	// call with return value
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,63,',0,0
	.dd LM27-_AdjustMon
	.dw 0x0d,0x0a
.code
LM27:
	R1=[BP]	// QImode move
	CMP R1,2	// QImode compare
	NSJZ L23	//QImode EQ
	CMP R1,2	// QImode compare
	NSJA L29	//QImode GTU
	CMP R1,1	// QImode compare
	NSJZ L22	//QImode EQ
	pc=L27	// Indirect jump
L29:
	CMP R1,4	// QImode compare
	NSJZ L25	//QImode EQ
	pc=L27	// Indirect jump
L22:
.debug
	.dw '.stabn 0x44,0,66,',0,0
	.dd LM28-_AdjustMon
	.dw 0x0d,0x0a
.code
LM28:
	R1=BP	// QImode move
	R2=BP+1
	R4=R2	// QImode move
	R3=[R4]	// QImode move
	R1=R3	// QImode move
	pc=L17	// Indirect jump
L23:
.debug
	.dw '.stabn 0x44,0,68,',0,0
	.dd LM29-_AdjustMon
	.dw 0x0d,0x0a
.code
LM29:
	R1=BP	// QImode move
	R2=BP+1
	R3=BP	// QImode move
	R1=BP+1
	R2=BP	// QImode move
	R3=BP+1
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R3=R2+1
	R2=R1	// QImode move
	[R2]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,69,',0,0
	.dd LM30-_AdjustMon
	.dw 0x0d,0x0a
.code
LM30:
	R1=BP	// QImode move
	R2=BP+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	CMP R1,12	// QImode compare
	NSJNA L24	//QImode LEU
	R1=BP	// QImode move
	R2=BP+1
	R1=1	// QImode move
	R4=R2	// QImode move
	[R4]=R1	// QImode move
L24:
.debug
	.dw '.stabn 0x44,0,70,',0,0
	.dd LM31-_AdjustMon
	.dw 0x0d,0x0a
.code
LM31:
	R1=BP	// QImode move
	R2=BP+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	call _PlayMon	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,71,',0,0
	.dd LM32-_AdjustMon
	.dw 0x0d,0x0a
.code
LM32:
	pc=L21	// Indirect jump
L25:
.debug
	.dw '.stabn 0x44,0,73,',0,0
	.dd LM33-_AdjustMon
	.dw 0x0d,0x0a
.code
LM33:
	R1=BP	// QImode move
	R2=BP+1
	R3=BP	// QImode move
	R1=BP+1
	R2=BP	// QImode move
	R3=BP+1
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R3=R2+(-1)
	R2=R1	// QImode move
	[R2]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,74,',0,0
	.dd LM34-_AdjustMon
	.dw 0x0d,0x0a
.code
LM34:
	R1=BP	// QImode move
	R2=BP+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	CMP R1,0	// QImode test
	NSJNZ L26	//QImode NE
	R1=BP	// QImode move
	R2=BP+1
	R1=12	// QImode move
	R4=R2	// QImode move
	[R4]=R1	// QImode move
L26:
.debug
	.dw '.stabn 0x44,0,75,',0,0
	.dd LM35-_AdjustMon
	.dw 0x0d,0x0a
.code
LM35:
	R1=BP	// QImode move
	R2=BP+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	call _PlayMon	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,76,',0,0
	.dd LM36-_AdjustMon
	.dw 0x0d,0x0a
.code
LM36:
	pc=L21	// Indirect jump
L27:
.debug
	.dw '.stabn 0x44,0,78,',0,0
	.dd LM37-_AdjustMon
	.dw 0x0d,0x0a
.code
LM37:
	pc=L21	// Indirect jump
L21:
.debug
	.dw '.stabn 0x44,0,80,',0,0
	.dd LM38-_AdjustMon
	.dw 0x0d,0x0a
.code
LM38:
	pc=L18	// Indirect jump
L19:
.debug
	.dw '.stabn 0x44,0,81,',0,0
	.dd LM39-_AdjustMon
	.dw 0x0d,0x0a
.code
LM39:
LBE3:
.debug
	.dw '.stabn 0x44,0,81,',0,0
	.dd LM40-_AdjustMon
	.dw 0x0d,0x0a
.code
LM40:
L17:

	sp+=3
	pop bp from [sp]
	retf
	.endp	// end of AdjustMon

.debug
	.dw '.stabs "Mon:p4",160,0,0,6',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB3-_AdjustMon
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "KeyCode:4",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "TempMon:4",128,0,0,1',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE3-_AdjustMon
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME2-_AdjustMon
	.dw 0x0d,0x0a
.code
LME2:
.code
.debug
	.dw '.stabs "AdjustDay:F4",36,0,0,',0,0,offset _AdjustDay,seg _AdjustDay,0x0d,0x0a
.CODE
.public _AdjustDay
_AdjustDay:	.proc
.debug
	.dw '.stabn 0x44,0,92,',0,0
	.dd LM41-_AdjustDay
	.dw 0x0d,0x0a
.code
LM41:
	// total=3, vars=3
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=3
	bp=sp+1

	R1=BP+6
	[bp+2]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,93,',0,0
	.dd LM42-_AdjustDay
	.dw 0x0d,0x0a
.code
LM42:
LBB4:
.debug
	.dw '.stabn 0x44,0,94,',0,0
	.dd LM43-_AdjustDay
	.dw 0x0d,0x0a
.code
LM43:
	R2=BP	// QImode move
	R1=BP+1
	R2=[bp+2]	// QImode move
	R2=[bp+2]	// QImode move
	R3=R2+2
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R3=R1	// QImode move
	[R3]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,96,',0,0
	.dd LM44-_AdjustDay
	.dw 0x0d,0x0a
.code
LM44:
	R2=BP	// QImode move
	R1=BP+1
	R2=[bp+2]	// QImode move
	R4=[bp+2]	// QImode move
	R3=R4+1
	R2=R3	// QImode move
	R4=[R2]	// QImode move
	R2=R4+(-1)
	R4=_Month_Day	// QImode move
	R3=R4	// QImode move
	R3 = R3 + R2	//addqi3
	R4=R1	// QImode move
	R1=[R4]	// QImode move
	R2=R3	// QImode move
	CMP R1,[R2]	// QImode compare
	NSJNA L37	//QImode LEU
.debug
	.dw '.stabn 0x44,0,98,',0,0
	.dd LM45-_AdjustDay
	.dw 0x0d,0x0a
.code
LM45:
	R1=BP	// QImode move
	R2=BP+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	CMP R1,29	// QImode compare
	NSJNZ L38	//QImode NE
.debug
	.dw '.stabn 0x44,0,100,',0,0
	.dd LM46-_AdjustDay
	.dw 0x0d,0x0a
.code
LM46:
	R4=[bp+2]	// QImode move
	R4=[R4]	// QImode move
	R1=R4&3
	CMP R1,0	// QImode test
	NSJZ L39	//QImode EQ
	R1=BP	// QImode move
	R2=BP+1
	R1=1	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
L39:
.debug
	.dw '.stabn 0x44,0,101,',0,0
	.dd LM47-_AdjustDay
	.dw 0x0d,0x0a
.code
LM47:
	pc=L37	// Indirect jump
L38:
.debug
	.dw '.stabn 0x44,0,102,',0,0
	.dd LM48-_AdjustDay
	.dw 0x0d,0x0a
.code
LM48:
	R1=BP	// QImode move
	R2=BP+1
	R1=1	// QImode move
	R4=R2	// QImode move
	[R4]=R1	// QImode move
L40:
L37:
.debug
	.dw '.stabn 0x44,0,105,',0,0
	.dd LM49-_AdjustDay
	.dw 0x0d,0x0a
.code
LM49:
	R1=BP	// QImode move
	R2=BP+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	call _PlayDay	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,106,',0,0
	.dd LM50-_AdjustDay
	.dw 0x0d,0x0a
.code
LM50:
L41:
	pc=L43	// Indirect jump
	pc=L42	// Indirect jump
L43:
.debug
	.dw '.stabn 0x44,0,108,',0,0
	.dd LM51-_AdjustDay
	.dw 0x0d,0x0a
.code
LM51:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,109,',0,0
	.dd LM52-_AdjustDay
	.dw 0x0d,0x0a
.code
LM52:
	call _Key_Get	// call with return value
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,110,',0,0
	.dd LM53-_AdjustDay
	.dw 0x0d,0x0a
.code
LM53:
	R1=[BP]	// QImode move
	CMP R1,2	// QImode compare
	NSJZ L46	//QImode EQ
	CMP R1,2	// QImode compare
	NSJA L57	//QImode GTU
	CMP R1,1	// QImode compare
	NSJZ L45	//QImode EQ
	pc=L55	// Indirect jump
L57:
	CMP R1,4	// QImode compare
	NSJZ L51	//QImode EQ
	pc=L55	// Indirect jump
L45:
.debug
	.dw '.stabn 0x44,0,113,',0,0
	.dd LM54-_AdjustDay
	.dw 0x0d,0x0a
.code
LM54:
	R1=BP	// QImode move
	R2=BP+1
	R4=R2	// QImode move
	R3=[R4]	// QImode move
	R1=R3	// QImode move
	pc=L36	// Indirect jump
L46:
.debug
	.dw '.stabn 0x44,0,115,',0,0
	.dd LM55-_AdjustDay
	.dw 0x0d,0x0a
.code
LM55:
	R1=BP	// QImode move
	R2=BP+1
	R3=BP	// QImode move
	R1=BP+1
	R2=BP	// QImode move
	R3=BP+1
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R3=R2+1
	R2=R1	// QImode move
	[R2]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,116,',0,0
	.dd LM56-_AdjustDay
	.dw 0x0d,0x0a
.code
LM56:
	R2=BP	// QImode move
	R1=BP+1
	R2=[bp+2]	// QImode move
	R4=[bp+2]	// QImode move
	R3=R4+1
	R2=R3	// QImode move
	R4=[R2]	// QImode move
	R2=R4+(-1)
	R4=_Month_Day	// QImode move
	R3=R4	// QImode move
	R3 = R3 + R2	//addqi3
	R4=R1	// QImode move
	R1=[R4]	// QImode move
	R2=R3	// QImode move
	CMP R1,[R2]	// QImode compare
	NSJNA L47	//QImode LEU
.debug
	.dw '.stabn 0x44,0,118,',0,0
	.dd LM57-_AdjustDay
	.dw 0x0d,0x0a
.code
LM57:
	R1=BP	// QImode move
	R2=BP+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	CMP R1,29	// QImode compare
	NSJNZ L48	//QImode NE
.debug
	.dw '.stabn 0x44,0,120,',0,0
	.dd LM58-_AdjustDay
	.dw 0x0d,0x0a
.code
LM58:
	R4=[bp+2]	// QImode move
	R4=[R4]	// QImode move
	R1=R4&3
	CMP R1,0	// QImode test
	NSJZ L49	//QImode EQ
	R1=BP	// QImode move
	R2=BP+1
	R1=1	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
L49:
.debug
	.dw '.stabn 0x44,0,121,',0,0
	.dd LM59-_AdjustDay
	.dw 0x0d,0x0a
.code
LM59:
	pc=L47	// Indirect jump
L48:
.debug
	.dw '.stabn 0x44,0,122,',0,0
	.dd LM60-_AdjustDay
	.dw 0x0d,0x0a
.code
LM60:
	R1=BP	// QImode move
	R2=BP+1
	R1=1	// QImode move
	R4=R2	// QImode move
	[R4]=R1	// QImode move
L50:
L47:
.debug
	.dw '.stabn 0x44,0,124,',0,0
	.dd LM61-_AdjustDay
	.dw 0x0d,0x0a
.code
LM61:
	R1=BP	// QImode move
	R2=BP+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	call _PlayDay	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,125,',0,0
	.dd LM62-_AdjustDay
	.dw 0x0d,0x0a
.code
LM62:
	pc=L44	// Indirect jump
L51:
.debug
	.dw '.stabn 0x44,0,127,',0,0
	.dd LM63-_AdjustDay
	.dw 0x0d,0x0a
.code
LM63:
	R1=BP	// QImode move
	R2=BP+1
	R3=BP	// QImode move
	R1=BP+1
	R2=BP	// QImode move
	R3=BP+1
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R3=R2+(-1)
	R2=R1	// QImode move
	[R2]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,128,',0,0
	.dd LM64-_AdjustDay
	.dw 0x0d,0x0a
.code
LM64:
	R1=BP	// QImode move
	R2=BP+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	CMP R1,0	// QImode test
	NSJNZ L52	//QImode NE
.debug
	.dw '.stabn 0x44,0,130,',0,0
	.dd LM65-_AdjustDay
	.dw 0x0d,0x0a
.code
LM65:
	R1=[bp+2]	// QImode move
	R4=[bp+2]	// QImode move
	R2=R4+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	CMP R1,2	// QImode compare
	NSJNZ L53	//QImode NE
	R4=[bp+2]	// QImode move
	R4=[R4]	// QImode move
	R1=R4&3
	CMP R1,0	// QImode test
	NSJNZ L53	//QImode NE
	R1=BP	// QImode move
	R2=BP+1
	R1=29	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
	pc=L52	// Indirect jump
L53:
.debug
	.dw '.stabn 0x44,0,131,',0,0
	.dd LM66-_AdjustDay
	.dw 0x0d,0x0a
.code
LM66:
	R2=BP	// QImode move
	R1=BP+1
	R2=[bp+2]	// QImode move
	R4=[bp+2]	// QImode move
	R3=R4+1
	R2=R3	// QImode move
	R4=[R2]	// QImode move
	R2=R4+(-1)
	R4=_Month_Day	// QImode move
	R3=R4	// QImode move
	R3 = R3 + R2	//addqi3
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R3=R1	// QImode move
	[R3]=R2	// QImode move
L54:
L52:
.debug
	.dw '.stabn 0x44,0,133,',0,0
	.dd LM67-_AdjustDay
	.dw 0x0d,0x0a
.code
LM67:
	R1=BP	// QImode move
	R2=BP+1
	R4=R2	// QImode move
	R1=[R4]	// QImode move
	[SP--]=R1	// QImode move
	call _PlayDay	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,134,',0,0
	.dd LM68-_AdjustDay
	.dw 0x0d,0x0a
.code
LM68:
	pc=L44	// Indirect jump
L55:
.debug
	.dw '.stabn 0x44,0,136,',0,0
	.dd LM69-_AdjustDay
	.dw 0x0d,0x0a
.code
LM69:
	pc=L44	// Indirect jump
L44:
.debug
	.dw '.stabn 0x44,0,138,',0,0
	.dd LM70-_AdjustDay
	.dw 0x0d,0x0a
.code
LM70:
	pc=L41	// Indirect jump
L42:
.debug
	.dw '.stabn 0x44,0,139,',0,0
	.dd LM71-_AdjustDay
	.dw 0x0d,0x0a
.code
LM71:
LBE4:
.debug
	.dw '.stabn 0x44,0,139,',0,0
	.dd LM72-_AdjustDay
	.dw 0x0d,0x0a
.code
LM72:
L36:

	sp+=3
	pop bp from [sp]
	retf
	.endp	// end of AdjustDay

.debug
	.dw '.stabs "Year:p4",160,0,0,6',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "Mon:p4",160,0,0,7',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "Day:p4",160,0,0,8',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB4-_AdjustDay
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "KeyCode:4",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "TempDay:4",128,0,0,1',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE4-_AdjustDay
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME3-_AdjustDay
	.dw 0x0d,0x0a
.code
LME3:
.code
.debug
	.dw '.stabs "AdjustHour:F4",36,0,0,',0,0,offset _AdjustHour,seg _AdjustHour,0x0d,0x0a
.CODE
.public _AdjustHour
_AdjustHour:	.proc
.debug
	.dw '.stabn 0x44,0,148,',0,0
	.dd LM73-_AdjustHour
	.dw 0x0d,0x0a
.code
LM73:
	// total=3, vars=3
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=3
	bp=sp+1

	R1=BP+6
	[bp+2]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,149,',0,0
	.dd LM74-_AdjustHour
	.dw 0x0d,0x0a
.code
LM74:
LBB5:
.debug
	.dw '.stabn 0x44,0,150,',0,0
	.dd LM75-_AdjustHour
	.dw 0x0d,0x0a
.code
LM75:
	R1=BP	// QImode move
	R2=BP+1
	R3=[bp+2]	// QImode move
	R1=[R3]	// QImode move
	R4=R2	// QImode move
	[R4]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,152,',0,0
	.dd LM76-_AdjustHour
	.dw 0x0d,0x0a
.code
LM76:
	R1=BP	// QImode move
	R2=BP+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	call _PlayHour	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,153,',0,0
	.dd LM77-_AdjustHour
	.dw 0x0d,0x0a
.code
LM77:
L72:
	pc=L74	// Indirect jump
	pc=L73	// Indirect jump
L74:
.debug
	.dw '.stabn 0x44,0,155,',0,0
	.dd LM78-_AdjustHour
	.dw 0x0d,0x0a
.code
LM78:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,156,',0,0
	.dd LM79-_AdjustHour
	.dw 0x0d,0x0a
.code
LM79:
	call _Key_Get	// call with return value
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,157,',0,0
	.dd LM80-_AdjustHour
	.dw 0x0d,0x0a
.code
LM80:
	R1=[BP]	// QImode move
	CMP R1,2	// QImode compare
	NSJZ L77	//QImode EQ
	CMP R1,2	// QImode compare
	NSJA L84	//QImode GTU
	CMP R1,1	// QImode compare
	NSJZ L76	//QImode EQ
	pc=L82	// Indirect jump
L84:
	CMP R1,4	// QImode compare
	NSJZ L79	//QImode EQ
	pc=L82	// Indirect jump
L76:
.debug
	.dw '.stabn 0x44,0,160,',0,0
	.dd LM81-_AdjustHour
	.dw 0x0d,0x0a
.code
LM81:
	R1=BP	// QImode move
	R2=BP+1
	R4=R2	// QImode move
	R3=[R4]	// QImode move
	R1=R3	// QImode move
	pc=L71	// Indirect jump
L77:
.debug
	.dw '.stabn 0x44,0,162,',0,0
	.dd LM82-_AdjustHour
	.dw 0x0d,0x0a
.code
LM82:
	R1=BP	// QImode move
	R2=BP+1
	R3=BP	// QImode move
	R1=BP+1
	R2=BP	// QImode move
	R3=BP+1
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R3=R2+1
	R2=R1	// QImode move
	[R2]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,163,',0,0
	.dd LM83-_AdjustHour
	.dw 0x0d,0x0a
.code
LM83:
	R1=BP	// QImode move
	R2=BP+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	CMP R1,23	// QImode compare
	NSJNA L78	//QImode LEU
	R1=BP	// QImode move
	R2=BP+1
	R1=0	// QImode move
	R4=R2	// QImode move
	[R4]=R1	// QImode move
L78:
.debug
	.dw '.stabn 0x44,0,164,',0,0
	.dd LM84-_AdjustHour
	.dw 0x0d,0x0a
.code
LM84:
	R1=BP	// QImode move
	R2=BP+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	call _PlayHour	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,165,',0,0
	.dd LM85-_AdjustHour
	.dw 0x0d,0x0a
.code
LM85:
	pc=L75	// Indirect jump
L79:
.debug
	.dw '.stabn 0x44,0,167,',0,0
	.dd LM86-_AdjustHour
	.dw 0x0d,0x0a
.code
LM86:
	R1=BP	// QImode move
	R2=BP+1
	R4=R2	// QImode move
	R1=[R4]	// QImode move
	CMP R1,0	// QImode test
	NSJNZ L80	//QImode NE
	R1=BP	// QImode move
	R2=BP+1
	R1=23	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
	pc=L81	// Indirect jump
L80:
.debug
	.dw '.stabn 0x44,0,168,',0,0
	.dd LM87-_AdjustHour
	.dw 0x0d,0x0a
.code
LM87:
	R1=BP	// QImode move
	R2=BP+1
	R3=BP	// QImode move
	R1=BP+1
	R2=BP	// QImode move
	R3=BP+1
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R3=R2+(-1)
	R2=R1	// QImode move
	[R2]=R3	// QImode move
L81:
.debug
	.dw '.stabn 0x44,0,169,',0,0
	.dd LM88-_AdjustHour
	.dw 0x0d,0x0a
.code
LM88:
	R1=BP	// QImode move
	R2=BP+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	call _PlayHour	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,170,',0,0
	.dd LM89-_AdjustHour
	.dw 0x0d,0x0a
.code
LM89:
	pc=L75	// Indirect jump
L82:
.debug
	.dw '.stabn 0x44,0,172,',0,0
	.dd LM90-_AdjustHour
	.dw 0x0d,0x0a
.code
LM90:
	pc=L75	// Indirect jump
L75:
.debug
	.dw '.stabn 0x44,0,174,',0,0
	.dd LM91-_AdjustHour
	.dw 0x0d,0x0a
.code
LM91:
	pc=L72	// Indirect jump
L73:
.debug
	.dw '.stabn 0x44,0,175,',0,0
	.dd LM92-_AdjustHour
	.dw 0x0d,0x0a
.code
LM92:
LBE5:
.debug
	.dw '.stabn 0x44,0,175,',0,0
	.dd LM93-_AdjustHour
	.dw 0x0d,0x0a
.code
LM93:
L71:

	sp+=3
	pop bp from [sp]
	retf
	.endp	// end of AdjustHour

.debug
	.dw '.stabs "Hour:p4",160,0,0,6',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB5-_AdjustHour
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "KeyCode:4",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "TempHour:4",128,0,0,1',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE5-_AdjustHour
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME4-_AdjustHour
	.dw 0x0d,0x0a
.code
LME4:
.code
.debug
	.dw '.stabs "AdjustMin:F4",36,0,0,',0,0,offset _AdjustMin,seg _AdjustMin,0x0d,0x0a
.CODE
.public _AdjustMin
_AdjustMin:	.proc
.debug
	.dw '.stabn 0x44,0,184,',0,0
	.dd LM94-_AdjustMin
	.dw 0x0d,0x0a
.code
LM94:
	// total=3, vars=3
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=3
	bp=sp+1

	R1=BP+6
	[bp+2]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,185,',0,0
	.dd LM95-_AdjustMin
	.dw 0x0d,0x0a
.code
LM95:
LBB6:
.debug
	.dw '.stabn 0x44,0,186,',0,0
	.dd LM96-_AdjustMin
	.dw 0x0d,0x0a
.code
LM96:
	R1=BP	// QImode move
	R2=BP+1
	R3=[bp+2]	// QImode move
	R1=[R3]	// QImode move
	R4=R2	// QImode move
	[R4]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,188,',0,0
	.dd LM97-_AdjustMin
	.dw 0x0d,0x0a
.code
LM97:
	R1=BP	// QImode move
	R2=BP+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	call _PlayNum	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,189,',0,0
	.dd LM98-_AdjustMin
	.dw 0x0d,0x0a
.code
LM98:
	R1=24	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,190,',0,0
	.dd LM99-_AdjustMin
	.dw 0x0d,0x0a
.code
LM99:
L92:
	pc=L94	// Indirect jump
	pc=L93	// Indirect jump
L94:
.debug
	.dw '.stabn 0x44,0,192,',0,0
	.dd LM100-_AdjustMin
	.dw 0x0d,0x0a
.code
LM100:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,193,',0,0
	.dd LM101-_AdjustMin
	.dw 0x0d,0x0a
.code
LM101:
	call _Key_Get	// call with return value
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,194,',0,0
	.dd LM102-_AdjustMin
	.dw 0x0d,0x0a
.code
LM102:
	R1=[BP]	// QImode move
	CMP R1,2	// QImode compare
	NSJZ L97	//QImode EQ
	CMP R1,2	// QImode compare
	NSJA L104	//QImode GTU
	CMP R1,1	// QImode compare
	NSJZ L96	//QImode EQ
	pc=L102	// Indirect jump
L104:
	CMP R1,4	// QImode compare
	NSJZ L99	//QImode EQ
	pc=L102	// Indirect jump
L96:
.debug
	.dw '.stabn 0x44,0,197,',0,0
	.dd LM103-_AdjustMin
	.dw 0x0d,0x0a
.code
LM103:
	R1=BP	// QImode move
	R2=BP+1
	R4=R2	// QImode move
	R3=[R4]	// QImode move
	R1=R3	// QImode move
	pc=L91	// Indirect jump
L97:
.debug
	.dw '.stabn 0x44,0,199,',0,0
	.dd LM104-_AdjustMin
	.dw 0x0d,0x0a
.code
LM104:
	R1=BP	// QImode move
	R2=BP+1
	R3=BP	// QImode move
	R1=BP+1
	R2=BP	// QImode move
	R3=BP+1
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R3=R2+1
	R2=R1	// QImode move
	[R2]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,200,',0,0
	.dd LM105-_AdjustMin
	.dw 0x0d,0x0a
.code
LM105:
	R1=BP	// QImode move
	R2=BP+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	CMP R1,59	// QImode compare
	NSJNA L98	//QImode LEU
	R1=BP	// QImode move
	R2=BP+1
	R1=0	// QImode move
	R4=R2	// QImode move
	[R4]=R1	// QImode move
L98:
.debug
	.dw '.stabn 0x44,0,201,',0,0
	.dd LM106-_AdjustMin
	.dw 0x0d,0x0a
.code
LM106:
	R1=BP	// QImode move
	R2=BP+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	call _PlayNum	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,202,',0,0
	.dd LM107-_AdjustMin
	.dw 0x0d,0x0a
.code
LM107:
	R1=24	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,203,',0,0
	.dd LM108-_AdjustMin
	.dw 0x0d,0x0a
.code
LM108:
	pc=L95	// Indirect jump
L99:
.debug
	.dw '.stabn 0x44,0,205,',0,0
	.dd LM109-_AdjustMin
	.dw 0x0d,0x0a
.code
LM109:
	R1=BP	// QImode move
	R2=BP+1
	R4=R2	// QImode move
	R1=[R4]	// QImode move
	CMP R1,0	// QImode test
	NSJNZ L100	//QImode NE
	R1=BP	// QImode move
	R2=BP+1
	R1=59	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
	pc=L101	// Indirect jump
L100:
.debug
	.dw '.stabn 0x44,0,206,',0,0
	.dd LM110-_AdjustMin
	.dw 0x0d,0x0a
.code
LM110:
	R1=BP	// QImode move
	R2=BP+1
	R3=BP	// QImode move
	R1=BP+1
	R2=BP	// QImode move
	R3=BP+1
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R3=R2+(-1)
	R2=R1	// QImode move
	[R2]=R3	// QImode move
L101:
.debug
	.dw '.stabn 0x44,0,207,',0,0
	.dd LM111-_AdjustMin
	.dw 0x0d,0x0a
.code
LM111:
	R1=BP	// QImode move
	R2=BP+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	call _PlayNum	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,208,',0,0
	.dd LM112-_AdjustMin
	.dw 0x0d,0x0a
.code
LM112:
	R1=24	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,209,',0,0
	.dd LM113-_AdjustMin
	.dw 0x0d,0x0a
.code
LM113:
	pc=L95	// Indirect jump
L102:
.debug
	.dw '.stabn 0x44,0,211,',0,0
	.dd LM114-_AdjustMin
	.dw 0x0d,0x0a
.code
LM114:
	pc=L95	// Indirect jump
L95:
.debug
	.dw '.stabn 0x44,0,213,',0,0
	.dd LM115-_AdjustMin
	.dw 0x0d,0x0a
.code
LM115:
	pc=L92	// Indirect jump
L93:
.debug
	.dw '.stabn 0x44,0,214,',0,0
	.dd LM116-_AdjustMin
	.dw 0x0d,0x0a
.code
LM116:
LBE6:
.debug
	.dw '.stabn 0x44,0,214,',0,0
	.dd LM117-_AdjustMin
	.dw 0x0d,0x0a
.code
LM117:
L91:

	sp+=3
	pop bp from [sp]
	retf
	.endp	// end of AdjustMin

.debug
	.dw '.stabs "Min:p4",160,0,0,6',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB6-_AdjustMin
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "KeyCode:4",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "TempMin:4",128,0,0,1',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE6-_AdjustMin
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME5-_AdjustMin
	.dw 0x0d,0x0a
.code
LME5:
.code
.debug
	.dw '.stabs "AdjustSec:F4",36,0,0,',0,0,offset _AdjustSec,seg _AdjustSec,0x0d,0x0a
.CODE
.public _AdjustSec
_AdjustSec:	.proc
.debug
	.dw '.stabn 0x44,0,223,',0,0
	.dd LM118-_AdjustSec
	.dw 0x0d,0x0a
.code
LM118:
	// total=3, vars=3
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=3
	bp=sp+1

	R1=BP+6
	[bp+2]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,224,',0,0
	.dd LM119-_AdjustSec
	.dw 0x0d,0x0a
.code
LM119:
LBB7:
.debug
	.dw '.stabn 0x44,0,225,',0,0
	.dd LM120-_AdjustSec
	.dw 0x0d,0x0a
.code
LM120:
	R1=BP	// QImode move
	R2=BP+1
	R3=[bp+2]	// QImode move
	R1=[R3]	// QImode move
	R4=R2	// QImode move
	[R4]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,227,',0,0
	.dd LM121-_AdjustSec
	.dw 0x0d,0x0a
.code
LM121:
	R1=BP	// QImode move
	R2=BP+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySec	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,228,',0,0
	.dd LM122-_AdjustSec
	.dw 0x0d,0x0a
.code
LM122:
L112:
	pc=L114	// Indirect jump
	pc=L113	// Indirect jump
L114:
.debug
	.dw '.stabn 0x44,0,230,',0,0
	.dd LM123-_AdjustSec
	.dw 0x0d,0x0a
.code
LM123:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,231,',0,0
	.dd LM124-_AdjustSec
	.dw 0x0d,0x0a
.code
LM124:
	call _Key_Get	// call with return value
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,232,',0,0
	.dd LM125-_AdjustSec
	.dw 0x0d,0x0a
.code
LM125:
	R1=[BP]	// QImode move
	CMP R1,2	// QImode compare
	NSJZ L117	//QImode EQ
	CMP R1,2	// QImode compare
	NSJA L124	//QImode GTU
	CMP R1,1	// QImode compare
	NSJZ L116	//QImode EQ
	pc=L122	// Indirect jump
L124:
	CMP R1,4	// QImode compare
	NSJZ L119	//QImode EQ
	pc=L122	// Indirect jump
L116:
.debug
	.dw '.stabn 0x44,0,235,',0,0
	.dd LM126-_AdjustSec
	.dw 0x0d,0x0a
.code
LM126:
	R1=BP	// QImode move
	R2=BP+1
	R4=R2	// QImode move
	R3=[R4]	// QImode move
	R1=R3	// QImode move
	pc=L111	// Indirect jump
L117:
.debug
	.dw '.stabn 0x44,0,237,',0,0
	.dd LM127-_AdjustSec
	.dw 0x0d,0x0a
.code
LM127:
	R1=BP	// QImode move
	R2=BP+1
	R3=BP	// QImode move
	R1=BP+1
	R2=BP	// QImode move
	R3=BP+1
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R3=R2+1
	R2=R1	// QImode move
	[R2]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,238,',0,0
	.dd LM128-_AdjustSec
	.dw 0x0d,0x0a
.code
LM128:
	R1=BP	// QImode move
	R2=BP+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	CMP R1,59	// QImode compare
	NSJNA L118	//QImode LEU
	R1=BP	// QImode move
	R2=BP+1
	R1=0	// QImode move
	R4=R2	// QImode move
	[R4]=R1	// QImode move
L118:
.debug
	.dw '.stabn 0x44,0,239,',0,0
	.dd LM129-_AdjustSec
	.dw 0x0d,0x0a
.code
LM129:
	R1=BP	// QImode move
	R2=BP+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySec	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,240,',0,0
	.dd LM130-_AdjustSec
	.dw 0x0d,0x0a
.code
LM130:
	pc=L115	// Indirect jump
L119:
.debug
	.dw '.stabn 0x44,0,242,',0,0
	.dd LM131-_AdjustSec
	.dw 0x0d,0x0a
.code
LM131:
	R1=BP	// QImode move
	R2=BP+1
	R4=R2	// QImode move
	R1=[R4]	// QImode move
	CMP R1,0	// QImode test
	NSJNZ L120	//QImode NE
	R1=BP	// QImode move
	R2=BP+1
	R1=59	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
	pc=L121	// Indirect jump
L120:
.debug
	.dw '.stabn 0x44,0,243,',0,0
	.dd LM132-_AdjustSec
	.dw 0x0d,0x0a
.code
LM132:
	R1=BP	// QImode move
	R2=BP+1
	R3=BP	// QImode move
	R1=BP+1
	R2=BP	// QImode move
	R3=BP+1
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R3=R2+(-1)
	R2=R1	// QImode move
	[R2]=R3	// QImode move
L121:
.debug
	.dw '.stabn 0x44,0,244,',0,0
	.dd LM133-_AdjustSec
	.dw 0x0d,0x0a
.code
LM133:
	R1=BP	// QImode move
	R2=BP+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySec	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,245,',0,0
	.dd LM134-_AdjustSec
	.dw 0x0d,0x0a
.code
LM134:
	pc=L115	// Indirect jump
L122:
.debug
	.dw '.stabn 0x44,0,247,',0,0
	.dd LM135-_AdjustSec
	.dw 0x0d,0x0a
.code
LM135:
	pc=L115	// Indirect jump
L115:
.debug
	.dw '.stabn 0x44,0,249,',0,0
	.dd LM136-_AdjustSec
	.dw 0x0d,0x0a
.code
LM136:
	pc=L112	// Indirect jump
L113:
.debug
	.dw '.stabn 0x44,0,250,',0,0
	.dd LM137-_AdjustSec
	.dw 0x0d,0x0a
.code
LM137:
LBE7:
.debug
	.dw '.stabn 0x44,0,250,',0,0
	.dd LM138-_AdjustSec
	.dw 0x0d,0x0a
.code
LM138:
L111:

	sp+=3
	pop bp from [sp]
	retf
	.endp	// end of AdjustSec

.debug
	.dw '.stabs "Sec:p4",160,0,0,6',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB7-_AdjustSec
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "KeyCode:4",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "TempSec:4",128,0,0,1',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE7-_AdjustSec
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME6-_AdjustSec
	.dw 0x0d,0x0a
.code
LME6:
.code
.debug
	.dw '.stabs "Adjust:F19",36,0,0,',0,0,offset _Adjust,seg _Adjust,0x0d,0x0a
.CODE
.public _Adjust
_Adjust:	.proc
.debug
	.dw '.stabn 0x44,0,259,',0,0
	.dd LM139-_Adjust
	.dw 0x0d,0x0a
.code
LM139:
	// total=7, vars=7
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=7
	bp=sp+1

	R1=BP+10
	[bp+6]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,260,',0,0
	.dd LM140-_Adjust
	.dw 0x0d,0x0a
.code
LM140:
LBB8:
.debug
	.dw '.stabn 0x44,0,262,',0,0
	.dd LM141-_Adjust
	.dw 0x0d,0x0a
.code
LM141:
	call _Clock_GetYear	// call with return value
	[SP--]=R1	// QImode move
	call _AdjustYear	// call with return value
	SP = SP + 1	//SP
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,263,',0,0
	.dd LM142-_Adjust
	.dw 0x0d,0x0a
.code
LM142:
	call _Clock_GetMon	// call with return value
	[SP--]=R1	// QImode move
	call _AdjustMon	// call with return value
	SP = SP + 1	//SP
	R2=BP	// QImode move
	R3=BP+1
	R2=R3	// QImode move
	[R2]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,264,',0,0
	.dd LM143-_Adjust
	.dw 0x0d,0x0a
.code
LM143:
	call _Clock_GetDay	// call with return value
	[SP--]=R1	// QImode move
	R1=BP	// QImode move
	R2=BP+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	R1=[BP]	// QImode move
	[SP--]=R1	// QImode move
	call _AdjustDay	// call with return value
	SP = SP + 3	//SP
	R2=BP	// QImode move
	R3=BP+2
	R2=R3	// QImode move
	[R2]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,265,',0,0
	.dd LM144-_Adjust
	.dw 0x0d,0x0a
.code
LM144:
	call _Clock_GetHour	// call with return value
	[SP--]=R1	// QImode move
	call _AdjustHour	// call with return value
	SP = SP + 1	//SP
	R2=BP	// QImode move
	R3=BP+3
	R2=R3	// QImode move
	[R2]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,266,',0,0
	.dd LM145-_Adjust
	.dw 0x0d,0x0a
.code
LM145:
	call _Clock_GetMin	// call with return value
	[SP--]=R1	// QImode move
	call _AdjustMin	// call with return value
	SP = SP + 1	//SP
	R2=BP	// QImode move
	R3=BP+4
	R2=R3	// QImode move
	[R2]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,267,',0,0
	.dd LM146-_Adjust
	.dw 0x0d,0x0a
.code
LM146:
	call _Clock_GetSec	// call with return value
	[SP--]=R1	// QImode move
	call _AdjustSec	// call with return value
	SP = SP + 1	//SP
	R2=BP	// QImode move
	R3=BP+5
	R2=R3	// QImode move
	[R2]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,269,',0,0
	.dd LM147-_Adjust
	.dw 0x0d,0x0a
.code
LM147:
	R1=[BP]	// QImode move
	[SP--]=R1	// QImode move
	call _Clock_SetYear	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,270,',0,0
	.dd LM148-_Adjust
	.dw 0x0d,0x0a
.code
LM148:
	R1=BP	// QImode move
	R2=BP+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	call _Clock_SetMon	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,271,',0,0
	.dd LM149-_Adjust
	.dw 0x0d,0x0a
.code
LM149:
	R1=BP	// QImode move
	R2=BP+2
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	call _Clock_SetDay	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,272,',0,0
	.dd LM150-_Adjust
	.dw 0x0d,0x0a
.code
LM150:
	R1=BP	// QImode move
	R2=BP+3
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	call _Clock_SetHour	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,273,',0,0
	.dd LM151-_Adjust
	.dw 0x0d,0x0a
.code
LM151:
	R1=BP	// QImode move
	R2=BP+4
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	call _Clock_SetMin	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,274,',0,0
	.dd LM152-_Adjust
	.dw 0x0d,0x0a
.code
LM152:
	R1=BP	// QImode move
	R2=BP+5
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	call _Clock_SetSec	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,276,',0,0
	.dd LM153-_Adjust
	.dw 0x0d,0x0a
.code
LM153:
	R1=14	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,277,',0,0
	.dd LM154-_Adjust
	.dw 0x0d,0x0a
.code
LM154:
	R1=[BP]	// QImode move
	[SP--]=R1	// QImode move
	call _PlayYear	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,278,',0,0
	.dd LM155-_Adjust
	.dw 0x0d,0x0a
.code
LM155:
	R1=BP	// QImode move
	R2=BP+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	call _PlayMon	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,279,',0,0
	.dd LM156-_Adjust
	.dw 0x0d,0x0a
.code
LM156:
	R1=BP	// QImode move
	R2=BP+2
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	call _PlayDay	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,280,',0,0
	.dd LM157-_Adjust
	.dw 0x0d,0x0a
.code
LM157:
	R1=BP	// QImode move
	R2=BP+3
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	call _PlayHour	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,281,',0,0
	.dd LM158-_Adjust
	.dw 0x0d,0x0a
.code
LM158:
	R1=BP	// QImode move
	R2=BP+4
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	call _PlayMin	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,282,',0,0
	.dd LM159-_Adjust
	.dw 0x0d,0x0a
.code
LM159:
LBE8:
.debug
	.dw '.stabn 0x44,0,282,',0,0
	.dd LM160-_Adjust
	.dw 0x0d,0x0a
.code
LM160:
L131:

	sp+=7
	pop bp from [sp]
	retf
	.endp	// end of Adjust

.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB8-_Adjust
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
	.dw '.stabs "TempHour:4",128,0,0,3',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "TempMin:4",128,0,0,4',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "TempSec:4",128,0,0,5',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE8-_Adjust
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME7-_Adjust
	.dw 0x0d,0x0a
.code
LME7:
.external _PlayMin
.external _Clock_SetSec
.external _Clock_SetMin
.external _Clock_SetHour
.external _Clock_SetDay
.external _Clock_SetMon
.external _Clock_SetYear
.external _Clock_GetSec
.external _Clock_GetMin
.external _Clock_GetHour
.external _Clock_GetDay
.external _Clock_GetMon
.external _Clock_GetYear
.external _PlaySec
.external _PlaySnd
.external _PlayNum
.external _PlayHour
.external _PlayDay
.external _Month_Day
.external _PlayMon
.external _Key_Get
.external _PlayYear
	.end

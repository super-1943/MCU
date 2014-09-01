// GCC for SUNPLUS u'nSP version 1.0.21-3
// Command: C:\PROGRA~1\Sunplus\UNSPID~1.0\cc1.exe C:\DOCUME~1\ADMINI~1\LOCALS~1\Temp\cc6Paaaa.i -fkeep-inline-functions -quiet -dumpbase main.c -mglobal-var-iram -gstabs -Wall -o .\Debug/main.asm
	.external __sn_func_ptr_sec

// gcc2_compiled.:

.debug
	.dw '.stabs "F:/myproject/lingyang/sound/",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
.code
.debug
	.dw '.stabs "F:/myproject/lingyang/sound/main.c",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
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
	.dw '.stabs "main:F1",36,0,0,',0,0,offset _main,seg _main,0x0d,0x0a
.CODE
.public _main
_main:	.proc
.debug
	.dw '.stabn 0x44,0,46,',0,0
	.dd LM1-_main
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
	.dw '.stabn 0x44,0,47,',0,0
	.dd LM2-_main
	.dw 0x0d,0x0a
.code
LM2:
LBB2:
.debug
	.dw '.stabn 0x44,0,48,',0,0
	.dd LM3-_main
	.dw 0x0d,0x0a
.code
LM3:
	R1=BP	// QImode move
	R2=BP+1
	R1=0	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,50,',0,0
	.dd LM4-_main
	.dw 0x0d,0x0a
.code
LM4:
	call _Key_Init	// call without return value
.debug
	.dw '.stabn 0x44,0,51,',0,0
	.dd LM5-_main
	.dw 0x0d,0x0a
.code
LM5:
	call _Clock_Start	// call without return value
.debug
	.dw '.stabn 0x44,0,53,',0,0
	.dd LM6-_main
	.dw 0x0d,0x0a
.code
LM6:
L3:
	pc=L5	// Indirect jump
	pc=L4	// Indirect jump
L5:
.debug
	.dw '.stabn 0x44,0,55,',0,0
	.dd LM7-_main
	.dw 0x0d,0x0a
.code
LM7:
	call _Key_Get	// call with return value
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,56,',0,0
	.dd LM8-_main
	.dw 0x0d,0x0a
.code
LM8:
	R1=[BP]	// QImode move
	CMP R1,1	// QImode compare
	NSJZ L7	//QImode EQ
	CMP R1,(-32767)	// QImode compare
	NSJZ L10	//QImode EQ
	pc=L11	// Indirect jump
L7:
.debug
	.dw '.stabn 0x44,0,59,',0,0
	.dd LM9-_main
	.dw 0x0d,0x0a
.code
LM9:
	R1=BP	// QImode move
	R2=BP+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	CMP R1,0	// QImode test
	NSJNZ L8	//QImode NE
.debug
	.dw '.stabn 0x44,0,61,',0,0
	.dd LM10-_main
	.dw 0x0d,0x0a
.code
LM10:
	call _PlayDate	// call without return value
.debug
	.dw '.stabn 0x44,0,62,',0,0
	.dd LM11-_main
	.dw 0x0d,0x0a
.code
LM11:
	R1=BP	// QImode move
	R2=BP+1
	R1=1	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,63,',0,0
	.dd LM12-_main
	.dw 0x0d,0x0a
.code
LM12:
	pc=L9	// Indirect jump
L8:
.debug
	.dw '.stabn 0x44,0,66,',0,0
	.dd LM13-_main
	.dw 0x0d,0x0a
.code
LM13:
	call _PlayTime	// call without return value
.debug
	.dw '.stabn 0x44,0,67,',0,0
	.dd LM14-_main
	.dw 0x0d,0x0a
.code
LM14:
	R1=BP	// QImode move
	R2=BP+1
	R1=0	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
L9:
.debug
	.dw '.stabn 0x44,0,69,',0,0
	.dd LM15-_main
	.dw 0x0d,0x0a
.code
LM15:
	pc=L6	// Indirect jump
L10:
.debug
	.dw '.stabn 0x44,0,71,',0,0
	.dd LM16-_main
	.dw 0x0d,0x0a
.code
LM16:
	call _Adjust	// call without return value
.debug
	.dw '.stabn 0x44,0,72,',0,0
	.dd LM17-_main
	.dw 0x0d,0x0a
.code
LM17:
	pc=L6	// Indirect jump
L11:
.debug
	.dw '.stabn 0x44,0,74,',0,0
	.dd LM18-_main
	.dw 0x0d,0x0a
.code
LM18:
	pc=L6	// Indirect jump
L6:
.debug
	.dw '.stabn 0x44,0,76,',0,0
	.dd LM19-_main
	.dw 0x0d,0x0a
.code
LM19:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,77,',0,0
	.dd LM20-_main
	.dw 0x0d,0x0a
.code
LM20:
	R1=31	// QImode move
	[28691]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,78,',0,0
	.dd LM21-_main
	.dw 0x0d,0x0a
.code
LM21:
	pc=L3	// Indirect jump
L4:
.debug
	.dw '.stabn 0x44,0,79,',0,0
	.dd LM22-_main
	.dw 0x0d,0x0a
.code
LM22:
LBE2:
.debug
	.dw '.stabn 0x44,0,79,',0,0
	.dd LM23-_main
	.dw 0x0d,0x0a
.code
LM23:
L2:

	sp+=3
	pop bp from [sp]
	retf
	.endp	// end of main

.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB2-_main
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "KeyCode:4",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "Flag:4",128,0,0,1',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE2-_main
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME1-_main
	.dw 0x0d,0x0a
.code
LME1:
.external _Adjust
.external _PlayTime
.external _PlayDate
.external _Key_Get
.external _Clock_Start
.external _Key_Init
	.end

// GCC for SUNPLUS u'nSP version 1.0.21-3
// Command: D:\PROGRA~1\Sunplus\UNSPID~1.0\cc1.exe C:\DOCUME~1\ZHANGZ~1.YSU\LOCALS~1\Temp\ccOQcaaa.i -fkeep-inline-functions -quiet -dumpbase led.c -mglobal-var-iram -gstabs -Wall -o .\Debug/led.asm
	.external __sn_func_ptr_sec

// gcc2_compiled.:

.debug
	.dw '.stabs "C:/Documents and Settings/zhangzhao.YSU-13AE14284FC/×ÀÃæ/shuma/",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
.code
.debug
	.dw '.stabs "C:/Documents and Settings/zhangzhao.YSU-13AE14284FC/×/300Ã/346/shuma/led.c",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
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
.public _tb
.iram
_tb:
	.dw 63
	.dw 6
	.dw 91
	.dw 79
	.dw 102
	.dw 109
	.dw 125
	.dw 7
	.dw 127
	.dw 111
	.dw 64
.debug
	.dw '.stabs "tb:G20=ar1;0;10;4",32,0,0,',0,0,offset _tb,seg _tb,0x0d,0x0a
.CODE
.public _dot
.iram
_dot:
	.dw 128
.debug
	.dw '.stabs "dot:G4",32,0,0,',0,0,offset _dot,seg _dot,0x0d,0x0a
.CODE
.debug
	.dw '.stabs "buffer:G21=ar1;0;7;4",32,0,0,',0,0,offset _buffer,seg _buffer,0x0d,0x0a
.CODE
.code
.debug
	.dw '.stabs "longdelay:F19",36,0,0,',0,0,offset _longdelay,seg _longdelay,0x0d,0x0a
.CODE
.public _longdelay
_longdelay:	.proc
.debug
	.dw '.stabn 0x44,0,6,',0,0
	.dd LM1-_longdelay
	.dw 0x0d,0x0a
.code
LM1:
	// total=3, vars=3
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=3
	bp=sp+1

	R1=BP+6
.debug
	.dw '.stabn 0x44,0,7,',0,0
	.dd LM2-_longdelay
	.dw 0x0d,0x0a
.code
LM2:
LBB2:
.debug
	.dw '.stabn 0x44,0,8,',0,0
	.dd LM3-_longdelay
	.dw 0x0d,0x0a
.code
LM3:
	R2=0	// QImode move
	[BP]=R2	// QImode move
L3:
	R2=[BP]	// QImode move
	CMP R2,599	// QImode compare
	NSJNG L6	//QImode LE
	pc=L4	// Indirect jump
L6:
.debug
	.dw '.stabn 0x44,0,9,',0,0
	.dd LM4-_longdelay
	.dw 0x0d,0x0a
.code
LM4:
	R2=BP	// QImode move
	R3=BP+1
	R2=20	// QImode move
	R4=R3	// QImode move
	[R4]=R2	// QImode move
L7:
	R2=BP	// QImode move
	R3=BP+1
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	CMP R2,0	// QImode test
	NSJNZ L10	//QImode NE
	pc=L5	// Indirect jump
L10:
.debug
	.dw '.stabn 0x44,0,10,',0,0
	.dd LM5-_longdelay
	.dw 0x0d,0x0a
.code
LM5:
	R2=1	// QImode move
	[28690]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,9,',0,0
	.dd LM6-_longdelay
	.dw 0x0d,0x0a
.code
LM6:
L9:
	R2=BP	// QImode move
	R3=BP+1
	R4=BP	// QImode move
	R2=BP+1
	R3=BP	// QImode move
	R3=BP+1
	[bp+2]=R3	// QImode move
	R4=[bp+2]	// QImode move
	R3=[R4]	// QImode move
	R4=R3+(-1)
	R3=R2	// QImode move
	[R3]=R4	// QImode move
	pc=L7	// Indirect jump
L8:
.debug
	.dw '.stabn 0x44,0,8,',0,0
	.dd LM7-_longdelay
	.dw 0x0d,0x0a
.code
LM7:
L5:
	R2=[BP]	// QImode move
	R3=R2+1
	[BP]=R3	// QImode move
	pc=L3	// Indirect jump
L4:
.debug
	.dw '.stabn 0x44,0,11,',0,0
	.dd LM8-_longdelay
	.dw 0x0d,0x0a
.code
LM8:
LBE2:
.debug
	.dw '.stabn 0x44,0,11,',0,0
	.dd LM9-_longdelay
	.dw 0x0d,0x0a
.code
LM9:
L2:

	sp+=3
	pop bp from [sp]
	retf
	.endp	// end of longdelay

.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB2-_longdelay
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "i:1",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "j:1",128,0,0,1',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE2-_longdelay
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME1-_longdelay
	.dw 0x0d,0x0a
.code
LME1:
.code
.debug
	.dw '.stabs "shortdelay:F19",36,0,0,',0,0,offset _shortdelay,seg _shortdelay,0x0d,0x0a
.CODE
.public _shortdelay
_shortdelay:	.proc
.debug
	.dw '.stabn 0x44,0,13,',0,0
	.dd LM10-_shortdelay
	.dw 0x0d,0x0a
.code
LM10:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
.debug
	.dw '.stabn 0x44,0,14,',0,0
	.dd LM11-_shortdelay
	.dw 0x0d,0x0a
.code
LM11:
LBB3:
.debug
	.dw '.stabn 0x44,0,15,',0,0
	.dd LM12-_shortdelay
	.dw 0x0d,0x0a
.code
LM12:
	R2=50	// QImode move
	[BP]=R2	// QImode move
L14:
	R2=[BP]	// QImode move
	CMP R2,0	// QImode test
	NSJNZ L17	//QImode NE
	pc=L15	// Indirect jump
L17:
.debug
	.dw '.stabn 0x44,0,16,',0,0
	.dd LM13-_shortdelay
	.dw 0x0d,0x0a
.code
LM13:
	R2=1	// QImode move
	[28690]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,15,',0,0
	.dd LM14-_shortdelay
	.dw 0x0d,0x0a
.code
LM14:
L16:
	R2=[BP]	// QImode move
	R3=R2+(-1)
	[BP]=R3	// QImode move
	pc=L14	// Indirect jump
L15:
.debug
	.dw '.stabn 0x44,0,17,',0,0
	.dd LM15-_shortdelay
	.dw 0x0d,0x0a
.code
LM15:
LBE3:
.debug
	.dw '.stabn 0x44,0,17,',0,0
	.dd LM16-_shortdelay
	.dw 0x0d,0x0a
.code
LM16:
L13:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of shortdelay

.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB3-_shortdelay
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "i:1",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE3-_shortdelay
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME2-_shortdelay
	.dw 0x0d,0x0a
.code
LME2:
.code
.debug
	.dw '.stabs "show:F19",36,0,0,',0,0,offset _show,seg _show,0x0d,0x0a
.CODE
.public _show
_show:	.proc
.debug
	.dw '.stabn 0x44,0,26,',0,0
	.dd LM17-_show
	.dw 0x0d,0x0a
.code
LM17:
	// total=16, vars=16
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=16
	bp=sp+1

	R1=BP+19
	[bp+10]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,27,',0,0
	.dd LM18-_show
	.dw 0x0d,0x0a
.code
LM18:
LBB4:
.debug
	.dw '.stabn 0x44,0,28,',0,0
	.dd LM19-_show
	.dw 0x0d,0x0a
.code
LM19:
	R1=(-1)	// QImode move
	[28674]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,29,',0,0
	.dd LM20-_show
	.dw 0x0d,0x0a
.code
LM20:
	R1=(-1)	// QImode move
	[28675]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,30,',0,0
	.dd LM21-_show
	.dw 0x0d,0x0a
.code
LM21:
	R1=(-1)	// QImode move
	[28672]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,31,',0,0
	.dd LM22-_show
	.dw 0x0d,0x0a
.code
LM22:
	R2=BP	// QImode move
	R1=BP+1
	R2=_tb	// QImode move
	R4=[bp+10]	// QImode move
	R3=[R4]	// QImode move
	R2 = R2 + R3	//addqi3
	R4=R2	// QImode move
	R3=[R4]	// QImode move
	R2=R1	// QImode move
	[R2]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,32,',0,0
	.dd LM23-_show
	.dw 0x0d,0x0a
.code
LM23:
	R1=BP	// QImode move
	R2=BP+1
	R1=R2	// QImode move
	R2=R2+1
	R1=[_tb+10]	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,33,',0,0
	.dd LM24-_show
	.dw 0x0d,0x0a
.code
LM24:
	R1=[bp+10]	// QImode move
	R4=[bp+10]	// QImode move
	R2=R4+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	CMP R1,99	// QImode compare
	NSJG L20	//QImode GT
.debug
	.dw '.stabn 0x44,0,35,',0,0
	.dd LM25-_show
	.dw 0x0d,0x0a
.code
LM25:
	pc=L19	// Indirect jump
.debug
	.dw '.stabn 0x44,0,36,',0,0
	.dd LM26-_show
	.dw 0x0d,0x0a
.code
LM26:
	pc=L21	// Indirect jump
L20:
.debug
	.dw '.stabn 0x44,0,37,',0,0
	.dd LM27-_show
	.dw 0x0d,0x0a
.code
LM27:
	R1=[bp+10]	// QImode move
	R4=[bp+10]	// QImode move
	R2=R4+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	CMP R1,19999	// QImode compare
	NSJG L22	//QImode GT
.debug
	.dw '.stabn 0x44,0,39,',0,0
	.dd LM28-_show
	.dw 0x0d,0x0a
.code
LM28:
	R1=BP	// QImode move
	R2=BP+1
	R1=R2	// QImode move
	R4=R2+2
	[bp+11]=R4	// QImode move
	R1=[bp+10]	// QImode move
	R1=[bp+10]	// QImode move
	R2=R1+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	R2=10000	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __divi1	// call with return value
	SP = SP + 2	//SP
	R3=_tb	// QImode move
	R2=R3	// QImode move
	R2 = R2 + R1	//addqi3
	R4=R2	// QImode move
	R1=[R4]	// QImode move
	R2=[bp+11]	// QImode move
	[R2]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,40,',0,0
	.dd LM29-_show
	.dw 0x0d,0x0a
.code
LM29:
	R1=BP	// QImode move
	R2=BP+1
	R1=R2	// QImode move
	R3=R2+3
	[bp+12]=R3	// QImode move
	R1=[bp+10]	// QImode move
	R4=[bp+10]	// QImode move
	R2=R4+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	R2=10000	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __modi1	// call with return value
	SP = SP + 2	//SP
	R2=1000	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __divi1	// call with return value
	SP = SP + 2	//SP
	R3=_tb	// QImode move
	R2=R3	// QImode move
	R2 = R2 + R1	//addqi3
	R4=R2	// QImode move
	R1=[R4]	// QImode move
	R2=[bp+12]	// QImode move
	[R2]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,41,',0,0
	.dd LM30-_show
	.dw 0x0d,0x0a
.code
LM30:
	R1=BP	// QImode move
	R3=BP+1
	R2=R3	// QImode move
	R1=R3+3
	R2=BP	// QImode move
	R3=BP+1
	R2=R3	// QImode move
	R3=R3+3
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R4=[_dot]	// QImode move
	R2|=R4
	R4=R1	// QImode move
	[R4]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,42,',0,0
	.dd LM31-_show
	.dw 0x0d,0x0a
.code
LM31:
	R1=BP	// QImode move
	R2=BP+1
	R1=R2	// QImode move
	R1=R2+4
	[bp+13]=R1	// QImode move
	R1=[bp+10]	// QImode move
	R3=[bp+10]	// QImode move
	R2=R3+1
	R4=R2	// QImode move
	R1=[R4]	// QImode move
	R2=100	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __divi1	// call with return value
	SP = SP + 2	//SP
	R2=10	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __modi1	// call with return value
	SP = SP + 2	//SP
	R3=_tb	// QImode move
	R2=R3	// QImode move
	R2 = R2 + R1	//addqi3
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	R4=[bp+13]	// QImode move
	[R4]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,43,',0,0
	.dd LM32-_show
	.dw 0x0d,0x0a
.code
LM32:
	pc=L21	// Indirect jump
L22:
.debug
	.dw '.stabn 0x44,0,46,',0,0
	.dd LM33-_show
	.dw 0x0d,0x0a
.code
LM33:
	pc=L19	// Indirect jump
L23:
L21:
.debug
	.dw '.stabn 0x44,0,48,',0,0
	.dd LM34-_show
	.dw 0x0d,0x0a
.code
LM34:
	R1=BP	// QImode move
	R2=BP+1
	R1=R2	// QImode move
	R2=R2+5
	R1=[_tb+10]	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,49,',0,0
	.dd LM35-_show
	.dw 0x0d,0x0a
.code
LM35:
	R1=BP	// QImode move
	R2=BP+1
	R1=R2	// QImode move
	R4=R2+6
	[bp+14]=R4	// QImode move
	R1=[bp+10]	// QImode move
	R1=[bp+10]	// QImode move
	R2=R1+2
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	R2=10	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __divi1	// call with return value
	SP = SP + 2	//SP
	R3=_tb	// QImode move
	R2=R3	// QImode move
	R2 = R2 + R1	//addqi3
	R4=R2	// QImode move
	R1=[R4]	// QImode move
	R4=[_dot]	// QImode move
	R1|=R4
	R4=[bp+14]	// QImode move
	[R4]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,50,',0,0
	.dd LM36-_show
	.dw 0x0d,0x0a
.code
LM36:
	R1=BP	// QImode move
	R2=BP+1
	R1=R2	// QImode move
	R1=R2+7
	[bp+15]=R1	// QImode move
	R1=[bp+10]	// QImode move
	R3=[bp+10]	// QImode move
	R2=R3+2
	R4=R2	// QImode move
	R1=[R4]	// QImode move
	R2=10	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __modi1	// call with return value
	SP = SP + 2	//SP
	R3=_tb	// QImode move
	R2=R3	// QImode move
	R2 = R2 + R1	//addqi3
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	R4=[bp+15]	// QImode move
	[R4]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,51,',0,0
	.dd LM37-_show
	.dw 0x0d,0x0a
.code
LM37:
	R1=BP	// QImode move
	R2=BP+9
	R1=0	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
L24:
	R1=BP	// QImode move
	R2=BP+9
	R4=R2	// QImode move
	R1=[R4]	// QImode move
	CMP R1,99	// QImode compare
	NSJNA L27	//QImode LEU
	pc=L25	// Indirect jump
L27:
.debug
	.dw '.stabn 0x44,0,53,',0,0
	.dd LM38-_show
	.dw 0x0d,0x0a
.code
LM38:
	R1=0	// QImode move
	[BP]=R1	// QImode move
L28:
	R1=[BP]	// QImode move
	CMP R1,7	// QImode compare
	NSJNA L31	//QImode LEU
	pc=L26	// Indirect jump
L31:
.debug
	.dw '.stabn 0x44,0,55,',0,0
	.dd LM39-_show
	.dw 0x0d,0x0a
.code
LM39:
	R1=256	// QImode move
	R2=[BP]	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __lshiu1	// call with return value
	SP = SP + 2	//SP
	R2=BP	// QImode move
	R3=BP+1
	R4=[BP]	// QImode move
	R2=R3	// QImode move
	R2 = R2 + R4	//addqi3
	R3=R2	// QImode move
	R1|=[R3]	// iorqi3_r0R
	[28672]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,56,',0,0
	.dd LM40-_show
	.dw 0x0d,0x0a
.code
LM40:
	call _shortdelay	// call without return value
.debug
	.dw '.stabn 0x44,0,53,',0,0
	.dd LM41-_show
	.dw 0x0d,0x0a
.code
LM41:
L30:
	R1=[BP]	// QImode move
	R2=R1+1
	[BP]=R2	// QImode move
	pc=L28	// Indirect jump
L29:
.debug
	.dw '.stabn 0x44,0,51,',0,0
	.dd LM42-_show
	.dw 0x0d,0x0a
.code
LM42:
L26:
	R1=BP	// QImode move
	R2=BP+9
	R3=BP	// QImode move
	R1=BP+9
	R2=BP	// QImode move
	R3=BP+9
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R3=R2+1
	R2=R1	// QImode move
	[R2]=R3	// QImode move
	pc=L24	// Indirect jump
L25:
.debug
	.dw '.stabn 0x44,0,59,',0,0
	.dd LM43-_show
	.dw 0x0d,0x0a
.code
LM43:
LBE4:
.debug
	.dw '.stabn 0x44,0,59,',0,0
	.dd LM44-_show
	.dw 0x0d,0x0a
.code
LM44:
L19:

	sp+=16
	pop bp from [sp]
	retf
	.endp	// end of show

.debug
	.dw '.stabs "mode:p1",160,0,0,19',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "freq:p1",160,0,0,20',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "mvol:p1",160,0,0,21',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB4-_show
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "count:4",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "tmp:21",128,0,0,1',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "j:4",128,0,0,9',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE4-_show
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME3-_show
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
	.dw '.stabn 0x44,0,65,',0,0
	.dd LM45-_main
	.dw 0x0d,0x0a
.code
LM45:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,67,',0,0
	.dd LM46-_main
	.dw 0x0d,0x0a
.code
LM46:
	R1=(-1)	// QImode move
	[28674]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,68,',0,0
	.dd LM47-_main
	.dw 0x0d,0x0a
.code
LM47:
	R1=(-1)	// QImode move
	[28675]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,69,',0,0
	.dd LM48-_main
	.dw 0x0d,0x0a
.code
LM48:
	R1=(-1)	// QImode move
	[28672]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,71,',0,0
	.dd LM49-_main
	.dw 0x0d,0x0a
.code
LM49:
L37:
	pc=L39	// Indirect jump
	pc=L38	// Indirect jump
L39:
.debug
	.dw '.stabn 0x44,0,73,',0,0
	.dd LM50-_main
	.dw 0x0d,0x0a
.code
LM50:
	R1=20	// QImode move
	[SP--]=R1	// QImode move
	R1=10000	// QImode move
	[SP--]=R1	// QImode move
	R1=2	// QImode move
	[SP--]=R1	// QImode move
	call _show	// call without return value
	SP = SP + 3	//SP
.debug
	.dw '.stabn 0x44,0,74,',0,0
	.dd LM51-_main
	.dw 0x0d,0x0a
.code
LM51:
	pc=L37	// Indirect jump
L38:
.debug
	.dw '.stabn 0x44,0,75,',0,0
	.dd LM52-_main
	.dw 0x0d,0x0a
.code
LM52:
.debug
	.dw '.stabn 0x44,0,75,',0,0
	.dd LM53-_main
	.dw 0x0d,0x0a
.code
LM53:
L36:

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
.public _buffer
_buffer:
	.dw 8 dup(0)
.external __lshiu1
.external __modi1
.external __divi1
	.end

// GCC for SUNPLUS u'nSP version 1.0.21-3
// Command: D:\PROGRA~1\Sunplus\cc1.exe C:\DOCUME~1\GAODEB~1\LOCALS~1\Temp\cc6xbaaa.i -fkeep-inline-functions -quiet -dumpbase led.c -mglobal-var-iram -gstabs -Wall -o .\Debug/led.asm
	.external __sn_func_ptr_sec

// gcc2_compiled.:

.debug
	.dw '.stabs "C:/Documents and Settings/gao debang/×ÀÃæ/¸öÈË¹¤³ÌÎÄ¼þ¼Ð/gao/shuma/",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
.code
.debug
	.dw '.stabs "C:/Documents and Settings/gao debang/×/300Ã/346/¸/366È/313¹/244³/314Î/304¼/376¼/320/gao/shuma/led.c",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
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
	R2=0	// QImode move
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
	R2=20	// QImode move
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
	.dw '.stabn 0x44,0,30,',0,0
	.dd LM19-_show
	.dw 0x0d,0x0a
.code
LM19:
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
	.dw '.stabn 0x44,0,31,',0,0
	.dd LM20-_show
	.dw 0x0d,0x0a
.code
LM20:
	R1=BP	// QImode move
	R2=BP+1
	R1=R2	// QImode move
	R2=R2+1
	R1=[_tb+10]	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,32,',0,0
	.dd LM21-_show
	.dw 0x0d,0x0a
.code
LM21:
	R1=[bp+10]	// QImode move
	R4=[bp+10]	// QImode move
	R2=R4+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	CMP R1,99	// QImode compare
	NSJG L20	//QImode GT
.debug
	.dw '.stabn 0x44,0,34,',0,0
	.dd LM22-_show
	.dw 0x0d,0x0a
.code
LM22:
	pc=L19	// Indirect jump
.debug
	.dw '.stabn 0x44,0,35,',0,0
	.dd LM23-_show
	.dw 0x0d,0x0a
.code
LM23:
	pc=L21	// Indirect jump
L20:
.debug
	.dw '.stabn 0x44,0,36,',0,0
	.dd LM24-_show
	.dw 0x0d,0x0a
.code
LM24:
	R1=[bp+10]	// QImode move
	R4=[bp+10]	// QImode move
	R2=R4+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	CMP R1,19999	// QImode compare
	NSJG L22	//QImode GT
.debug
	.dw '.stabn 0x44,0,38,',0,0
	.dd LM25-_show
	.dw 0x0d,0x0a
.code
LM25:
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
	.dw '.stabn 0x44,0,39,',0,0
	.dd LM26-_show
	.dw 0x0d,0x0a
.code
LM26:
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
	.dw '.stabn 0x44,0,40,',0,0
	.dd LM27-_show
	.dw 0x0d,0x0a
.code
LM27:
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
	.dw '.stabn 0x44,0,41,',0,0
	.dd LM28-_show
	.dw 0x0d,0x0a
.code
LM28:
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
	.dw '.stabn 0x44,0,42,',0,0
	.dd LM29-_show
	.dw 0x0d,0x0a
.code
LM29:
	pc=L21	// Indirect jump
L22:
.debug
	.dw '.stabn 0x44,0,45,',0,0
	.dd LM30-_show
	.dw 0x0d,0x0a
.code
LM30:
	pc=L19	// Indirect jump
L23:
L21:
.debug
	.dw '.stabn 0x44,0,47,',0,0
	.dd LM31-_show
	.dw 0x0d,0x0a
.code
LM31:
	R1=BP	// QImode move
	R2=BP+1
	R1=R2	// QImode move
	R2=R2+5
	R1=[_tb+10]	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,48,',0,0
	.dd LM32-_show
	.dw 0x0d,0x0a
.code
LM32:
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
	.dw '.stabn 0x44,0,49,',0,0
	.dd LM33-_show
	.dw 0x0d,0x0a
.code
LM33:
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
	.dw '.stabn 0x44,0,50,',0,0
	.dd LM34-_show
	.dw 0x0d,0x0a
.code
LM34:
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
	CMP R1,0	// QImode test
	NSJZ L27	//QImode EQ
	pc=L25	// Indirect jump
L27:
.debug
	.dw '.stabn 0x44,0,52,',0,0
	.dd LM35-_show
	.dw 0x0d,0x0a
.code
LM35:
	R1=0	// QImode move
	[BP]=R1	// QImode move
L28:
	R1=[BP]	// QImode move
	CMP R1,7	// QImode compare
	NSJNA L31	//QImode LEU
	pc=L26	// Indirect jump
L31:
.debug
	.dw '.stabn 0x44,0,54,',0,0
	.dd LM36-_show
	.dw 0x0d,0x0a
.code
LM36:
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
	.dw '.stabn 0x44,0,55,',0,0
	.dd LM37-_show
	.dw 0x0d,0x0a
.code
LM37:
	call _shortdelay	// call without return value
.debug
	.dw '.stabn 0x44,0,57,',0,0
	.dd LM38-_show
	.dw 0x0d,0x0a
.code
LM38:
	R1=0	// QImode move
	[28672]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,52,',0,0
	.dd LM39-_show
	.dw 0x0d,0x0a
.code
LM39:
L30:
	R1=[BP]	// QImode move
	R2=R1+1
	[BP]=R2	// QImode move
	pc=L28	// Indirect jump
L29:
.debug
	.dw '.stabn 0x44,0,50,',0,0
	.dd LM40-_show
	.dw 0x0d,0x0a
.code
LM40:
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
	.dw '.stabn 0x44,0,60,',0,0
	.dd LM41-_show
	.dw 0x0d,0x0a
.code
LM41:
LBE4:
.debug
	.dw '.stabn 0x44,0,60,',0,0
	.dd LM42-_show
	.dw 0x0d,0x0a
.code
LM42:
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
	.dw '.stabs "KeyScan:F19",36,0,0,',0,0,offset _KeyScan,seg _KeyScan,0x0d,0x0a
.CODE
.public _KeyScan
_KeyScan:	.proc
.debug
	.dw '.stabn 0x44,0,76,',0,0
	.dd LM43-_KeyScan
	.dw 0x0d,0x0a
.code
LM43:
	// total=2, vars=2
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=2
	bp=sp+1

	R1=BP+5
.debug
	.dw '.stabn 0x44,0,77,',0,0
	.dd LM44-_KeyScan
	.dw 0x0d,0x0a
.code
LM44:
LBB5:
.debug
	.dw '.stabn 0x44,0,78,',0,0
	.dd LM45-_KeyScan
	.dw 0x0d,0x0a
.code
LM45:
	R2=1	// QImode move
	[28690]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,79,',0,0
	.dd LM46-_KeyScan
	.dw 0x0d,0x0a
.code
LM46:
	R2=(-256)	// QImode move
	[28679]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,80,',0,0
	.dd LM47-_KeyScan
	.dw 0x0d,0x0a
.code
LM47:
	R2=(-256)	// QImode move
	[28680]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,81,',0,0
	.dd LM48-_KeyScan
	.dw 0x0d,0x0a
.code
LM48:
	R2=[28677]	// QImode move
	[BP]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,83,',0,0
	.dd LM49-_KeyScan
	.dw 0x0d,0x0a
.code
LM49:
	R2=BP	// QImode move
	R3=BP+1
	R2=[BP]	// QImode move
	R4=R2^255
	R2=R3	// QImode move
	[R2]=R4	// QImode move
.debug
	.dw '.stabn 0x44,0,85,',0,0
	.dd LM50-_KeyScan
	.dw 0x0d,0x0a
.code
LM50:
	R2=BP	// QImode move
	R3=BP+1
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	CMP R2,32	// QImode compare
	NSJZ L41	//QImode EQ
	CMP R2,32	// QImode compare
	NSJG L48	//QImode GT
	CMP R2,8	// QImode compare
	NSJZ L44	//QImode EQ
	CMP R2,16	// QImode compare
	NSJZ L42	//QImode EQ
	pc=L46	// Indirect jump
L48:
	CMP R2,64	// QImode compare
	NSJZ L40	//QImode EQ
	CMP R2,128	// QImode compare
	NSJZ L38	//QImode EQ
	pc=L46	// Indirect jump
L38:
.debug
	.dw '.stabn 0x44,0,88,',0,0
	.dd LM51-_KeyScan
	.dw 0x0d,0x0a
.code
LM51:
	R2=[_buffer]	// QImode move
	R3=1	// QImode move
	[_buffer]=R2+R3  //addqi3_Qrr
.debug
	.dw '.stabn 0x44,0,89,',0,0
	.dd LM52-_KeyScan
	.dw 0x0d,0x0a
.code
LM52:
	R2=[_buffer]	// QImode move
	CMP R2,3	// QImode compare
	NSJNZ L39	//QImode NE
.debug
	.dw '.stabn 0x44,0,90,',0,0
	.dd LM53-_KeyScan
	.dw 0x0d,0x0a
.code
LM53:
	R2=0	// QImode move
	[_buffer]=R2	// QImode move
L39:
.debug
	.dw '.stabn 0x44,0,91,',0,0
	.dd LM54-_KeyScan
	.dw 0x0d,0x0a
.code
LM54:
	pc=L37	// Indirect jump
L40:
.debug
	.dw '.stabn 0x44,0,93,',0,0
	.dd LM55-_KeyScan
	.dw 0x0d,0x0a
.code
LM55:
	R2=[_buffer+1]	// QImode move
	R3=100	// QImode move
	[_buffer+1]=R2+R3  //addqi3_Qrr
.debug
	.dw '.stabn 0x44,0,94,',0,0
	.dd LM56-_KeyScan
	.dw 0x0d,0x0a
.code
LM56:
	pc=L37	// Indirect jump
L41:
.debug
	.dw '.stabn 0x44,0,96,',0,0
	.dd LM57-_KeyScan
	.dw 0x0d,0x0a
.code
LM57:
	R2=[_buffer+1]	// QImode move
	R3=(-100)	// QImode move
	[_buffer+1]=R2+R3  //addqi3_Qrr
.debug
	.dw '.stabn 0x44,0,97,',0,0
	.dd LM58-_KeyScan
	.dw 0x0d,0x0a
.code
LM58:
	pc=L37	// Indirect jump
L42:
.debug
	.dw '.stabn 0x44,0,99,',0,0
	.dd LM59-_KeyScan
	.dw 0x0d,0x0a
.code
LM59:
	R2=[_buffer+2]	// QImode move
	CMP R2,50	// QImode compare
	NSJNZ L43	//QImode NE
.debug
	.dw '.stabn 0x44,0,101,',0,0
	.dd LM60-_KeyScan
	.dw 0x0d,0x0a
.code
LM60:
	R2=0	// QImode move
	[_buffer+2]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,102,',0,0
	.dd LM61-_KeyScan
	.dw 0x0d,0x0a
.code
LM61:
	pc=L37	// Indirect jump
L43:
.debug
	.dw '.stabn 0x44,0,104,',0,0
	.dd LM62-_KeyScan
	.dw 0x0d,0x0a
.code
LM62:
	R2=[_buffer+2]	// QImode move
	R3=1	// QImode move
	[_buffer+2]=R2+R3  //addqi3_Qrr
.debug
	.dw '.stabn 0x44,0,105,',0,0
	.dd LM63-_KeyScan
	.dw 0x0d,0x0a
.code
LM63:
	pc=L37	// Indirect jump
L44:
.debug
	.dw '.stabn 0x44,0,107,',0,0
	.dd LM64-_KeyScan
	.dw 0x0d,0x0a
.code
LM64:
	R2=[_buffer+2]	// QImode move
	CMP R2,0	// QImode test
	NSJNZ L45	//QImode NE
.debug
	.dw '.stabn 0x44,0,109,',0,0
	.dd LM65-_KeyScan
	.dw 0x0d,0x0a
.code
LM65:
	R2=50	// QImode move
	[_buffer+2]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,110,',0,0
	.dd LM66-_KeyScan
	.dw 0x0d,0x0a
.code
LM66:
	pc=L37	// Indirect jump
L45:
.debug
	.dw '.stabn 0x44,0,112,',0,0
	.dd LM67-_KeyScan
	.dw 0x0d,0x0a
.code
LM67:
	R2=[_buffer+2]	// QImode move
	R3=(-1)	// QImode move
	[_buffer+2]=R2+R3  //addqi3_Qrr
.debug
	.dw '.stabn 0x44,0,113,',0,0
	.dd LM68-_KeyScan
	.dw 0x0d,0x0a
.code
LM68:
	pc=L37	// Indirect jump
L46:
.debug
	.dw '.stabn 0x44,0,115,',0,0
	.dd LM69-_KeyScan
	.dw 0x0d,0x0a
.code
LM69:
	pc=L37	// Indirect jump
L37:
.debug
	.dw '.stabn 0x44,0,117,',0,0
	.dd LM70-_KeyScan
	.dw 0x0d,0x0a
.code
LM70:
LBE5:
.debug
	.dw '.stabn 0x44,0,117,',0,0
	.dd LM71-_KeyScan
	.dw 0x0d,0x0a
.code
LM71:
L36:

	sp+=2
	pop bp from [sp]
	retf
	.endp	// end of KeyScan

.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB5-_KeyScan
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "KeyTemp:1",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "Value:1",128,0,0,1',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE5-_KeyScan
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME4-_KeyScan
	.dw 0x0d,0x0a
.code
LME4:
.code
.debug
	.dw '.stabs "main:F1",36,0,0,',0,0,offset _main,seg _main,0x0d,0x0a
.CODE
.public _main
_main:	.proc
.debug
	.dw '.stabn 0x44,0,121,',0,0
	.dd LM72-_main
	.dw 0x0d,0x0a
.code
LM72:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,123,',0,0
	.dd LM73-_main
	.dw 0x0d,0x0a
.code
LM73:
	R1=(-1)	// QImode move
	[28674]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,124,',0,0
	.dd LM74-_main
	.dw 0x0d,0x0a
.code
LM74:
	R1=(-1)	// QImode move
	[28675]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,125,',0,0
	.dd LM75-_main
	.dw 0x0d,0x0a
.code
LM75:
	R1=(-1)	// QImode move
	[28672]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,126,',0,0
	.dd LM76-_main
	.dw 0x0d,0x0a
.code
LM76:
	R1=0	// QImode move
	[_buffer]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,127,',0,0
	.dd LM77-_main
	.dw 0x0d,0x0a
.code
LM77:
	R1=100	// QImode move
	[_buffer+1]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,128,',0,0
	.dd LM78-_main
	.dw 0x0d,0x0a
.code
LM78:
	R1=20	// QImode move
	[_buffer+2]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,129,',0,0
	.dd LM79-_main
	.dw 0x0d,0x0a
.code
LM79:
L59:
	pc=L61	// Indirect jump
	pc=L60	// Indirect jump
L61:
.debug
	.dw '.stabn 0x44,0,131,',0,0
	.dd LM80-_main
	.dw 0x0d,0x0a
.code
LM80:
	call _KeyScan	// call without return value
.debug
	.dw '.stabn 0x44,0,132,',0,0
	.dd LM81-_main
	.dw 0x0d,0x0a
.code
LM81:
	R1=[_buffer+2]	// QImode move
	[SP--]=R1	// QImode move
	R1=[_buffer+1]	// QImode move
	[SP--]=R1	// QImode move
	R1=[_buffer]	// QImode move
	[SP--]=R1	// QImode move
	call _show	// call without return value
	SP = SP + 3	//SP
.debug
	.dw '.stabn 0x44,0,133,',0,0
	.dd LM82-_main
	.dw 0x0d,0x0a
.code
LM82:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,134,',0,0
	.dd LM83-_main
	.dw 0x0d,0x0a
.code
LM83:
	pc=L59	// Indirect jump
L60:
.debug
	.dw '.stabn 0x44,0,135,',0,0
	.dd LM84-_main
	.dw 0x0d,0x0a
.code
LM84:
.debug
	.dw '.stabn 0x44,0,135,',0,0
	.dd LM85-_main
	.dw 0x0d,0x0a
.code
LM85:
L58:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of main

.debug
	.dw '.stabf ',0,0
	.dd LME5-_main
	.dw 0x0d,0x0a
.code
LME5:
.iram
.public _buffer
_buffer:
	.dw 8 dup(0)
.external __lshiu1
.external __modi1
.external __divi1
	.end

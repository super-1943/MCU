// GCC for SUNPLUS u'nSP version 1.0.21-3
// Command: D:\PROGRA~1\Sunplus\UNSPID~1.0\cc1.exe C:\DOCUME~1\ADMINI~1\LOCALS~1\Temp\ccWsaaaa.i -fkeep-inline-functions -quiet -dumpbase disp.c -mglobal-var-iram -gstabs -Wall -o .\Debug/disp.asm
	.external __sn_func_ptr_sec

// gcc2_compiled.:

.debug
	.dw '.stabs "C:/Documents and Settings/Administrator/×ÀÃæ/voice/voice/",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
.code
.debug
	.dw '.stabs "C:/Documents and Settings/Administrator/×/300Ã/346/voice/voice/disp.c",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
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
	.dw '.stabs "apm:G4",32,0,0,',0,0,offset _apm,seg _apm,0x0d,0x0a
.CODE
.public _dian
.iram
_dian:
	.dw 1
.debug
	.dw '.stabs "dian:G4",32,0,0,',0,0,offset _dian,seg _dian,0x0d,0x0a
.CODE
.public _shan_flag
.iram
_shan_flag:
	.dw 0
.debug
	.dw '.stabs "shan_flag:G11",32,0,0,',0,0,offset _shan_flag,seg _shan_flag,0x0d,0x0a
.CODE
.code
.debug
	.dw '.stabs "disp_Init:F19",36,0,0,',0,0,offset _disp_Init,seg _disp_Init,0x0d,0x0a
.CODE
.public _disp_Init
_disp_Init:	.proc
.debug
	.dw '.stabn 0x44,0,8,',0,0
	.dd LM1-_disp_Init
	.dw 0x0d,0x0a
.code
LM1:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,9,',0,0
	.dd LM2-_disp_Init
	.dw 0x0d,0x0a
.code
LM2:
	R2=[28674]	// QImode move
	R3=R2|(-64)
	[28674]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,10,',0,0
	.dd LM3-_disp_Init
	.dw 0x0d,0x0a
.code
LM3:
	R2=[28675]	// QImode move
	R3=R2|(-64)
	[28675]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,11,',0,0
	.dd LM4-_disp_Init
	.dw 0x0d,0x0a
.code
LM4:
	R2=[28672]	// QImode move
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,12,',0,0
	.dd LM5-_disp_Init
	.dw 0x0d,0x0a
.code
LM5:
	R2=[28679]	// QImode move
	R3=R2|(-256)
	[28679]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,13,',0,0
	.dd LM6-_disp_Init
	.dw 0x0d,0x0a
.code
LM6:
	R2=[28680]	// QImode move
	R3=R2|(-256)
	[28680]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,14,',0,0
	.dd LM7-_disp_Init
	.dw 0x0d,0x0a
.code
LM7:
	R2=[28677]	// QImode move
	[28677]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,15,',0,0
	.dd LM8-_disp_Init
	.dw 0x0d,0x0a
.code
LM8:
.debug
	.dw '.stabn 0x44,0,15,',0,0
	.dd LM9-_disp_Init
	.dw 0x0d,0x0a
.code
LM9:
L2:

	pop bp from [sp]
	retf
	.endp	// end of disp_Init

.debug
	.dw '.stabf ',0,0
	.dd LME1-_disp_Init
	.dw 0x0d,0x0a
.code
LME1:
.text
LC0:
	.dw 16128
	.dw 1536
	.dw 23296
	.dw 20224
	.dw 26112
	.dw 27904
	.dw 32000
	.dw 1792
	.dw 32512
	.dw 28416
	.dw 64
	.dw 128
LC1:
	.dw 256
	.dw 512
	.dw 1024
	.dw 2048
	.dw 4096
	.dw 8192
	.dw 16384
	.dw -32768
.code
.debug
	.dw '.stabs "disp:F19",36,0,0,',0,0,offset _disp,seg _disp,0x0d,0x0a
.CODE
.public _disp
_disp:	.proc
.debug
	.dw '.stabn 0x44,0,17,',0,0
	.dd LM10-_disp
	.dw 0x0d,0x0a
.code
LM10:
	// total=53, vars=53
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=53
	bp=sp+1

	R1=BP+56
	[bp+38]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,18,',0,0
	.dd LM11-_disp
	.dw 0x0d,0x0a
.code
LM11:
LBB2:
	R1=BP	// QImode move
	R2=LC0	// QImode move
	R3=12	// QImode move
	[SP--]=R3	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __BlockCopy	// call with return value
	SP = SP + 3	//SP
.debug
	.dw '.stabn 0x44,0,19,',0,0
	.dd LM12-_disp
	.dw 0x0d,0x0a
.code
LM12:
	R1=BP	// QImode move
	R2=BP+12
	R1=R2	// QImode move
	R2=LC1	// QImode move
	R3=8	// QImode move
	[SP--]=R3	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __BlockCopy	// call with return value
	SP = SP + 3	//SP
.debug
	.dw '.stabn 0x44,0,20,',0,0
	.dd LM13-_disp
	.dw 0x0d,0x0a
.code
LM13:
	R1=BP	// QImode move
	R2=BP+20
	R1=0	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
	R1=BP	// QImode move
	R2=BP+21
	R1=0	// QImode move
	R4=R2	// QImode move
	[R4]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,23,',0,0
	.dd LM14-_disp
	.dw 0x0d,0x0a
.code
LM14:
	R1=BP	// QImode move
	R2=BP+22
	R1=R2	// QImode move
	R1=R2+14
	[bp+39]=R1	// QImode move
	R2=[bp+38]	// QImode move
	R1=[R2]	// QImode move
	R2=10	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __modi1	// call with return value
	SP = SP + 2	//SP
	[SP--]=R1	// QImode move
	call __cvi1f2	// call with return value
	SP = SP + 1	//SP
	R3=[bp+39]	// QImode move
	[R3++]=R1	// [RD]=RS HFmode, RD!=RS+1
	[R3--]=R2
.debug
	.dw '.stabn 0x44,0,24,',0,0
	.dd LM15-_disp
	.dw 0x0d,0x0a
.code
LM15:
	R1=BP	// QImode move
	R2=BP+22
	R1=R2	// QImode move
	R4=R2+12
	[bp+40]=R4	// QImode move
	R2=[bp+38]	// QImode move
	R1=[R2]	// QImode move
	R2=10	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __divi1	// call with return value
	SP = SP + 2	//SP
	[SP--]=R1	// QImode move
	call __cvi1f2	// call with return value
	SP = SP + 1	//SP
	R3=[bp+40]	// QImode move
	[R3++]=R1	// [RD]=RS HFmode, RD!=RS+1
	[R3--]=R2
.debug
	.dw '.stabn 0x44,0,25,',0,0
	.dd LM16-_disp
	.dw 0x0d,0x0a
.code
LM16:
	R1=BP	// QImode move
	R2=BP+22
	R1=R2	// QImode move
	R4=R2+10
	[bp+41]=R4	// QImode move
	R1=[bp+38]	// QImode move
	R1=[bp+38]	// QImode move
	R2=R1+3
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	R2=10	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __modi1	// call with return value
	SP = SP + 2	//SP
	[SP--]=R1	// QImode move
	call __cvi1f2	// call with return value
	SP = SP + 1	//SP
	R4=[bp+41]	// QImode move
	[R4++]=R1	// [RD]=RS HFmode, RD!=RS+1
	[R4--]=R2
.debug
	.dw '.stabn 0x44,0,26,',0,0
	.dd LM17-_disp
	.dw 0x0d,0x0a
.code
LM17:
	R1=BP	// QImode move
	R2=BP+22
	R1=R2	// QImode move
	R1=R2+8
	[bp+42]=R1	// QImode move
	R1=[bp+38]	// QImode move
	R3=[bp+38]	// QImode move
	R2=R3+3
	R4=R2	// QImode move
	R1=[R4]	// QImode move
	R2=10	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __divi1	// call with return value
	SP = SP + 2	//SP
	[SP--]=R1	// QImode move
	call __cvi1f2	// call with return value
	SP = SP + 1	//SP
	R3=[bp+42]	// QImode move
	[R3++]=R1	// [RD]=RS HFmode, RD!=RS+1
	[R3--]=R2
.debug
	.dw '.stabn 0x44,0,27,',0,0
	.dd LM18-_disp
	.dw 0x0d,0x0a
.code
LM18:
	R1=BP	// QImode move
	R2=BP+22
	R1=R2	// QImode move
	R4=R2+6
	[bp+43]=R4	// QImode move
	R1=[bp+38]	// QImode move
	R1=[bp+38]	// QImode move
	R2=R1+2
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	R2=10	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __modi1	// call with return value
	SP = SP + 2	//SP
	[SP--]=R1	// QImode move
	call __cvi1f2	// call with return value
	SP = SP + 1	//SP
	R4=[bp+43]	// QImode move
	[R4++]=R1	// [RD]=RS HFmode, RD!=RS+1
	[R4--]=R2
.debug
	.dw '.stabn 0x44,0,28,',0,0
	.dd LM19-_disp
	.dw 0x0d,0x0a
.code
LM19:
	R1=BP	// QImode move
	R2=BP+22
	R1=R2	// QImode move
	R1=R2+4
	[bp+44]=R1	// QImode move
	R1=[bp+38]	// QImode move
	R3=[bp+38]	// QImode move
	R2=R3+2
	R4=R2	// QImode move
	R1=[R4]	// QImode move
	R2=10	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __divi1	// call with return value
	SP = SP + 2	//SP
	[SP--]=R1	// QImode move
	call __cvi1f2	// call with return value
	SP = SP + 1	//SP
	R3=[bp+44]	// QImode move
	[R3++]=R1	// [RD]=RS HFmode, RD!=RS+1
	[R3--]=R2
.debug
	.dw '.stabn 0x44,0,29,',0,0
	.dd LM20-_disp
	.dw 0x0d,0x0a
.code
LM20:
	R1=BP	// QImode move
	R2=BP+22
	R1=R2	// QImode move
	R4=R2+2
	[bp+45]=R4	// QImode move
	R1=[bp+38]	// QImode move
	R1=[bp+38]	// QImode move
	R2=R1+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	R2=10	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __modi1	// call with return value
	SP = SP + 2	//SP
	[SP--]=R1	// QImode move
	call __cvi1f2	// call with return value
	SP = SP + 1	//SP
	R4=[bp+45]	// QImode move
	[R4++]=R1	// [RD]=RS HFmode, RD!=RS+1
	[R4--]=R2
.debug
	.dw '.stabn 0x44,0,30,',0,0
	.dd LM21-_disp
	.dw 0x0d,0x0a
.code
LM21:
	R1=BP	// QImode move
	R1=BP+22
	[bp+46]=R1	// QImode move
	R1=[bp+38]	// QImode move
	R3=[bp+38]	// QImode move
	R2=R3+1
	R4=R2	// QImode move
	R1=[R4]	// QImode move
	R2=10	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __divi1	// call with return value
	SP = SP + 2	//SP
	[SP--]=R1	// QImode move
	call __cvi1f2	// call with return value
	SP = SP + 1	//SP
	R3=[bp+46]	// QImode move
	[R3++]=R1	// [RD]=RS HFmode, RD!=RS+1
	[R3--]=R2
.debug
	.dw '.stabn 0x44,0,32,',0,0
	.dd LM22-_disp
	.dw 0x0d,0x0a
.code
LM22:
	R1=[_shan_flag]	// QImode move
	CMP R1,1	// QImode compare
	NSJNZ L4	//QImode NE
.debug
	.dw '.stabn 0x44,0,34,',0,0
	.dd LM23-_disp
	.dw 0x0d,0x0a
.code
LM23:
	R1=[_num]	// QImode move
	CMP R1,1	// QImode compare
	NSJNZ L5	//QImode NE
.debug
	.dw '.stabn 0x44,0,36,',0,0
	.dd LM24-_disp
	.dw 0x0d,0x0a
.code
LM24:
	R1=BP	// QImode move
	R2=BP+20
	R1=0	// QImode move
	R4=R2	// QImode move
	[R4]=R1	// QImode move
L6:
	R1=BP	// QImode move
	R2=BP+20
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	CMP R1,1	// QImode compare
	NSJNG L9	//QImode LE
	pc=L5	// Indirect jump
L9:
.debug
	.dw '.stabn 0x44,0,38,',0,0
	.dd LM25-_disp
	.dw 0x0d,0x0a
.code
LM25:
	R2=BP	// QImode move
	R1=BP+12
	R2=BP	// QImode move
	R3=BP+20
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R1 = R1 + R2	//addqi3
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	[28677]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,39,',0,0
	.dd LM26-_disp
	.dw 0x0d,0x0a
.code
LM26:
	R1=BP	// QImode move
	R4=BP+21
	[bp+47]=R4	// QImode move
	R2=BP	// QImode move
	R1=BP+22
	R2=BP	// QImode move
	R3=BP+20
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R3=R2	// QImode move
	R2=R3 lsl 1
	R1 = R1 + R2	//addqi3
	R2=R1	// QImode move
	R3=[R2++]	// RD=[RS] HFmode, RD!=RS
	R4=[R2--]
	push R3,R4 to [sp]	// pushhf
	call __cvf2i1	// call with return value
	SP = SP + 2	//SP
	R3=[bp+47]	// QImode move
	[R3]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,40,',0,0
	.dd LM27-_disp
	.dw 0x0d,0x0a
.code
LM27:
	R1=BP	// QImode move
	R2=BP+21
	R4=R2	// QImode move
	R3=[R4]	// QImode move
	R1=BP	// QImode move
	R1 = R1 + R3	//addqi3
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,41,',0,0
	.dd LM28-_disp
	.dw 0x0d,0x0a
.code
LM28:
	R1=2	// QImode move
	[SP--]=R1	// QImode move
	call _disp_delay	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,36,',0,0
	.dd LM29-_disp
	.dw 0x0d,0x0a
.code
LM29:
L8:
	R1=BP	// QImode move
	R2=BP+20
	R3=BP	// QImode move
	R1=BP+20
	R2=BP	// QImode move
	R3=BP+20
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R3=R2+1
	R2=R1	// QImode move
	[R2]=R3	// QImode move
	pc=L6	// Indirect jump
L7:
L5:
.debug
	.dw '.stabn 0x44,0,44,',0,0
	.dd LM30-_disp
	.dw 0x0d,0x0a
.code
LM30:
	R1=BP	// QImode move
	R2=BP+20
	R1=2	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
L10:
	R1=BP	// QImode move
	R2=BP+20
	R4=R2	// QImode move
	R1=[R4]	// QImode move
	CMP R1,3	// QImode compare
	NSJNG L13	//QImode LE
	pc=L11	// Indirect jump
L13:
.debug
	.dw '.stabn 0x44,0,46,',0,0
	.dd LM31-_disp
	.dw 0x0d,0x0a
.code
LM31:
	R2=BP	// QImode move
	R1=BP+12
	R2=BP	// QImode move
	R3=BP+20
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R1 = R1 + R2	//addqi3
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	[28677]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,47,',0,0
	.dd LM32-_disp
	.dw 0x0d,0x0a
.code
LM32:
	R1=BP	// QImode move
	R4=BP+21
	[bp+48]=R4	// QImode move
	R2=BP	// QImode move
	R1=BP+22
	R2=BP	// QImode move
	R3=BP+20
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R3=R2	// QImode move
	R2=R3 lsl 1
	R1 = R1 + R2	//addqi3
	R2=R1	// QImode move
	R3=[R2++]	// RD=[RS] HFmode, RD!=RS
	R4=[R2--]
	push R3,R4 to [sp]	// pushhf
	call __cvf2i1	// call with return value
	SP = SP + 2	//SP
	R3=[bp+48]	// QImode move
	[R3]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,48,',0,0
	.dd LM33-_disp
	.dw 0x0d,0x0a
.code
LM33:
	R1=BP	// QImode move
	R2=BP+21
	R4=R2	// QImode move
	R3=[R4]	// QImode move
	R1=BP	// QImode move
	R1 = R1 + R3	//addqi3
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,49,',0,0
	.dd LM34-_disp
	.dw 0x0d,0x0a
.code
LM34:
	R1=2	// QImode move
	[SP--]=R1	// QImode move
	call _disp_delay	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,44,',0,0
	.dd LM35-_disp
	.dw 0x0d,0x0a
.code
LM35:
L12:
	R1=BP	// QImode move
	R2=BP+20
	R3=BP	// QImode move
	R1=BP+20
	R2=BP	// QImode move
	R3=BP+20
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R3=R2+1
	R2=R1	// QImode move
	[R2]=R3	// QImode move
	pc=L10	// Indirect jump
L11:
.debug
	.dw '.stabn 0x44,0,51,',0,0
	.dd LM36-_disp
	.dw 0x0d,0x0a
.code
LM36:
	pc=L14	// Indirect jump
L4:
.debug
	.dw '.stabn 0x44,0,52,',0,0
	.dd LM37-_disp
	.dw 0x0d,0x0a
.code
LM37:
	R1=[_shan_flag]	// QImode move
	CMP R1,2	// QImode compare
	NSJNZ L15	//QImode NE
.debug
	.dw '.stabn 0x44,0,55,',0,0
	.dd LM38-_disp
	.dw 0x0d,0x0a
.code
LM38:
	R1=BP	// QImode move
	R2=BP+20
	R1=0	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
L16:
	R1=BP	// QImode move
	R2=BP+20
	R4=R2	// QImode move
	R1=[R4]	// QImode move
	CMP R1,1	// QImode compare
	NSJNG L19	//QImode LE
	pc=L17	// Indirect jump
L19:
.debug
	.dw '.stabn 0x44,0,57,',0,0
	.dd LM39-_disp
	.dw 0x0d,0x0a
.code
LM39:
	R2=BP	// QImode move
	R1=BP+12
	R2=BP	// QImode move
	R3=BP+20
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R1 = R1 + R2	//addqi3
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	[28677]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,58,',0,0
	.dd LM40-_disp
	.dw 0x0d,0x0a
.code
LM40:
	R1=BP	// QImode move
	R4=BP+21
	[bp+49]=R4	// QImode move
	R2=BP	// QImode move
	R1=BP+22
	R2=BP	// QImode move
	R3=BP+20
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R3=R2	// QImode move
	R2=R3 lsl 1
	R1 = R1 + R2	//addqi3
	R2=R1	// QImode move
	R3=[R2++]	// RD=[RS] HFmode, RD!=RS
	R4=[R2--]
	push R3,R4 to [sp]	// pushhf
	call __cvf2i1	// call with return value
	SP = SP + 2	//SP
	R3=[bp+49]	// QImode move
	[R3]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,59,',0,0
	.dd LM41-_disp
	.dw 0x0d,0x0a
.code
LM41:
	R1=BP	// QImode move
	R2=BP+21
	R4=R2	// QImode move
	R3=[R4]	// QImode move
	R1=BP	// QImode move
	R1 = R1 + R3	//addqi3
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,60,',0,0
	.dd LM42-_disp
	.dw 0x0d,0x0a
.code
LM42:
	R1=2	// QImode move
	[SP--]=R1	// QImode move
	call _disp_delay	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,55,',0,0
	.dd LM43-_disp
	.dw 0x0d,0x0a
.code
LM43:
L18:
	R1=BP	// QImode move
	R2=BP+20
	R3=BP	// QImode move
	R1=BP+20
	R2=BP	// QImode move
	R3=BP+20
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R3=R2+1
	R2=R1	// QImode move
	[R2]=R3	// QImode move
	pc=L16	// Indirect jump
L17:
.debug
	.dw '.stabn 0x44,0,62,',0,0
	.dd LM44-_disp
	.dw 0x0d,0x0a
.code
LM44:
	R1=[_num]	// QImode move
	CMP R1,1	// QImode compare
	NSJNZ L20	//QImode NE
.debug
	.dw '.stabn 0x44,0,64,',0,0
	.dd LM45-_disp
	.dw 0x0d,0x0a
.code
LM45:
	R1=BP	// QImode move
	R2=BP+20
	R1=2	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
L21:
	R1=BP	// QImode move
	R2=BP+20
	R4=R2	// QImode move
	R1=[R4]	// QImode move
	CMP R1,3	// QImode compare
	NSJNG L24	//QImode LE
	pc=L20	// Indirect jump
L24:
.debug
	.dw '.stabn 0x44,0,66,',0,0
	.dd LM46-_disp
	.dw 0x0d,0x0a
.code
LM46:
	R2=BP	// QImode move
	R1=BP+12
	R2=BP	// QImode move
	R3=BP+20
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R1 = R1 + R2	//addqi3
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	[28677]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,67,',0,0
	.dd LM47-_disp
	.dw 0x0d,0x0a
.code
LM47:
	R1=BP	// QImode move
	R4=BP+21
	[bp+50]=R4	// QImode move
	R2=BP	// QImode move
	R1=BP+22
	R2=BP	// QImode move
	R3=BP+20
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R3=R2	// QImode move
	R2=R3 lsl 1
	R1 = R1 + R2	//addqi3
	R2=R1	// QImode move
	R3=[R2++]	// RD=[RS] HFmode, RD!=RS
	R4=[R2--]
	push R3,R4 to [sp]	// pushhf
	call __cvf2i1	// call with return value
	SP = SP + 2	//SP
	R3=[bp+50]	// QImode move
	[R3]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,68,',0,0
	.dd LM48-_disp
	.dw 0x0d,0x0a
.code
LM48:
	R1=BP	// QImode move
	R2=BP+21
	R4=R2	// QImode move
	R3=[R4]	// QImode move
	R1=BP	// QImode move
	R1 = R1 + R3	//addqi3
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,69,',0,0
	.dd LM49-_disp
	.dw 0x0d,0x0a
.code
LM49:
	R1=2	// QImode move
	[SP--]=R1	// QImode move
	call _disp_delay	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,64,',0,0
	.dd LM50-_disp
	.dw 0x0d,0x0a
.code
LM50:
L23:
	R1=BP	// QImode move
	R2=BP+20
	R3=BP	// QImode move
	R1=BP+20
	R2=BP	// QImode move
	R3=BP+20
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R3=R2+1
	R2=R1	// QImode move
	[R2]=R3	// QImode move
	pc=L21	// Indirect jump
L22:
L20:
.debug
	.dw '.stabn 0x44,0,72,',0,0
	.dd LM51-_disp
	.dw 0x0d,0x0a
.code
LM51:
	pc=L14	// Indirect jump
L15:
.debug
	.dw '.stabn 0x44,0,74,',0,0
	.dd LM52-_disp
	.dw 0x0d,0x0a
.code
LM52:
	R1=BP	// QImode move
	R2=BP+20
	R1=0	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
L26:
	R1=BP	// QImode move
	R2=BP+20
	R4=R2	// QImode move
	R1=[R4]	// QImode move
	CMP R1,3	// QImode compare
	NSJNG L29	//QImode LE
	pc=L14	// Indirect jump
L29:
.debug
	.dw '.stabn 0x44,0,76,',0,0
	.dd LM53-_disp
	.dw 0x0d,0x0a
.code
LM53:
	R2=BP	// QImode move
	R1=BP+12
	R2=BP	// QImode move
	R3=BP+20
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R1 = R1 + R2	//addqi3
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	[28677]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,77,',0,0
	.dd LM54-_disp
	.dw 0x0d,0x0a
.code
LM54:
	R1=BP	// QImode move
	R4=BP+21
	[bp+51]=R4	// QImode move
	R2=BP	// QImode move
	R1=BP+22
	R2=BP	// QImode move
	R3=BP+20
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R3=R2	// QImode move
	R2=R3 lsl 1
	R1 = R1 + R2	//addqi3
	R2=R1	// QImode move
	R3=[R2++]	// RD=[RS] HFmode, RD!=RS
	R4=[R2--]
	push R3,R4 to [sp]	// pushhf
	call __cvf2i1	// call with return value
	SP = SP + 2	//SP
	R3=[bp+51]	// QImode move
	[R3]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,78,',0,0
	.dd LM55-_disp
	.dw 0x0d,0x0a
.code
LM55:
	R1=BP	// QImode move
	R2=BP+21
	R4=R2	// QImode move
	R3=[R4]	// QImode move
	R1=BP	// QImode move
	R1 = R1 + R3	//addqi3
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,79,',0,0
	.dd LM56-_disp
	.dw 0x0d,0x0a
.code
LM56:
	R1=2	// QImode move
	[SP--]=R1	// QImode move
	call _disp_delay	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,74,',0,0
	.dd LM57-_disp
	.dw 0x0d,0x0a
.code
LM57:
L28:
	R1=BP	// QImode move
	R2=BP+20
	R3=BP	// QImode move
	R1=BP+20
	R2=BP	// QImode move
	R3=BP+20
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R3=R2+1
	R2=R1	// QImode move
	[R2]=R3	// QImode move
	pc=L26	// Indirect jump
L27:
L25:
L14:
.debug
	.dw '.stabn 0x44,0,81,',0,0
	.dd LM58-_disp
	.dw 0x0d,0x0a
.code
LM58:
	R1=BP	// QImode move
	R2=BP+20
	R1=4	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
L30:
	R1=BP	// QImode move
	R2=BP+20
	R4=R2	// QImode move
	R1=[R4]	// QImode move
	CMP R1,7	// QImode compare
	NSJNG L33	//QImode LE
	pc=L31	// Indirect jump
L33:
.debug
	.dw '.stabn 0x44,0,83,',0,0
	.dd LM59-_disp
	.dw 0x0d,0x0a
.code
LM59:
	R2=BP	// QImode move
	R1=BP+12
	R2=BP	// QImode move
	R3=BP+20
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R1 = R1 + R2	//addqi3
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	[28677]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,84,',0,0
	.dd LM60-_disp
	.dw 0x0d,0x0a
.code
LM60:
	R1=BP	// QImode move
	R4=BP+21
	[bp+52]=R4	// QImode move
	R2=BP	// QImode move
	R1=BP+22
	R2=BP	// QImode move
	R3=BP+20
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R3=R2	// QImode move
	R2=R3 lsl 1
	R1 = R1 + R2	//addqi3
	R2=R1	// QImode move
	R3=[R2++]	// RD=[RS] HFmode, RD!=RS
	R4=[R2--]
	push R3,R4 to [sp]	// pushhf
	call __cvf2i1	// call with return value
	SP = SP + 2	//SP
	R3=[bp+52]	// QImode move
	[R3]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,85,',0,0
	.dd LM61-_disp
	.dw 0x0d,0x0a
.code
LM61:
	R1=BP	// QImode move
	R2=BP+21
	R4=R2	// QImode move
	R3=[R4]	// QImode move
	R1=BP	// QImode move
	R1 = R1 + R3	//addqi3
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,86,',0,0
	.dd LM62-_disp
	.dw 0x0d,0x0a
.code
LM62:
	R1=2	// QImode move
	[SP--]=R1	// QImode move
	call _disp_delay	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,81,',0,0
	.dd LM63-_disp
	.dw 0x0d,0x0a
.code
LM63:
L32:
	R1=BP	// QImode move
	R2=BP+20
	R3=BP	// QImode move
	R1=BP+20
	R2=BP	// QImode move
	R3=BP+20
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R3=R2+1
	R2=R1	// QImode move
	[R2]=R3	// QImode move
	pc=L30	// Indirect jump
L31:
.debug
	.dw '.stabn 0x44,0,88,',0,0
	.dd LM64-_disp
	.dw 0x0d,0x0a
.code
LM64:
	R1=[_apm]	// QImode move
	CMP R1,0	// QImode test
	NSJNZ L34	//QImode NE
.debug
	.dw '.stabn 0x44,0,89,',0,0
	.dd LM65-_disp
	.dw 0x0d,0x0a
.code
LM65:
	R1=BP	// QImode move
	R2=BP+10
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[28672]=R1	// QImode move
	pc=L35	// Indirect jump
L34:
.debug
	.dw '.stabn 0x44,0,91,',0,0
	.dd LM66-_disp
	.dw 0x0d,0x0a
.code
LM66:
	R1=BP	// QImode move
	R2=BP+11
	R4=R2	// QImode move
	R1=[R4]	// QImode move
	[28672]=R1	// QImode move
L35:
.debug
	.dw '.stabn 0x44,0,92,',0,0
	.dd LM67-_disp
	.dw 0x0d,0x0a
.code
LM67:
	R1=2	// QImode move
	[SP--]=R1	// QImode move
	call _disp_delay	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,93,',0,0
	.dd LM68-_disp
	.dw 0x0d,0x0a
.code
LM68:
	R1=[_dian]	// QImode move
	CMP R1,1	// QImode compare
	NSJNZ L36	//QImode NE
.debug
	.dw '.stabn 0x44,0,95,',0,0
	.dd LM69-_disp
	.dw 0x0d,0x0a
.code
LM69:
	R1=2048	// QImode move
	[28677]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,96,',0,0
	.dd LM70-_disp
	.dw 0x0d,0x0a
.code
LM70:
	R1=(-32768)	// QImode move
	[28672]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,97,',0,0
	.dd LM71-_disp
	.dw 0x0d,0x0a
.code
LM71:
	R1=2	// QImode move
	[SP--]=R1	// QImode move
	call _disp_delay	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,98,',0,0
	.dd LM72-_disp
	.dw 0x0d,0x0a
.code
LM72:
	R1=512	// QImode move
	[28677]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,99,',0,0
	.dd LM73-_disp
	.dw 0x0d,0x0a
.code
LM73:
	R1=(-32768)	// QImode move
	[28672]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,100,',0,0
	.dd LM74-_disp
	.dw 0x0d,0x0a
.code
LM74:
	R1=2	// QImode move
	[SP--]=R1	// QImode move
	call _disp_delay	// call without return value
	SP = SP + 1	//SP
L36:
.debug
	.dw '.stabn 0x44,0,102,',0,0
	.dd LM75-_disp
	.dw 0x0d,0x0a
.code
LM75:
	R1=0	// QImode move
	[28677]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,103,',0,0
	.dd LM76-_disp
	.dw 0x0d,0x0a
.code
LM76:
	R1=0	// QImode move
	[28672]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,104,',0,0
	.dd LM77-_disp
	.dw 0x0d,0x0a
.code
LM77:
LBE2:
.debug
	.dw '.stabn 0x44,0,104,',0,0
	.dd LM78-_disp
	.dw 0x0d,0x0a
.code
LM78:
L3:

	sp+=53
	pop bp from [sp]
	retf
	.endp	// end of disp

.debug
	.dw '.stabs "t:p1",160,0,0,56',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "h:p1",160,0,0,57',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "m:p1",160,0,0,58',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "s:p1",160,0,0,59',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB2-_disp
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "d:20=ar1;0;11;1",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "dig:21=ar1;0;7;1",128,0,0,12',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "i:1",128,0,0,20',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "mm:1",128,0,0,21',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "dis:22=ar1;0;7;12",128,0,0,22',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE2-_disp
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME2-_disp
	.dw 0x0d,0x0a
.code
LME2:
.code
.debug
	.dw '.stabs "disp_delay:F19",36,0,0,',0,0,offset _disp_delay,seg _disp_delay,0x0d,0x0a
.CODE
.public _disp_delay
_disp_delay:	.proc
.debug
	.dw '.stabn 0x44,0,106,',0,0
	.dd LM79-_disp_delay
	.dw 0x0d,0x0a
.code
LM79:
	// total=3, vars=3
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=3
	bp=sp+1

	R1=BP+6
.debug
	.dw '.stabn 0x44,0,107,',0,0
	.dd LM80-_disp_delay
	.dw 0x0d,0x0a
.code
LM80:
LBB3:
	R2=0	// QImode move
	[BP]=R2	// QImode move
	R2=BP	// QImode move
	R3=BP+1
	R2=0	// QImode move
	R4=R3	// QImode move
	[R4]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,108,',0,0
	.dd LM81-_disp_delay
	.dw 0x0d,0x0a
.code
LM81:
	R2=0	// QImode move
	[BP]=R2	// QImode move
L50:
	R2=[BP]	// QImode move
	R3=R1	// QImode move
	CMP R2,[R3]	// QImode compare
	NSJL L53	//QImode LT
	pc=L51	// Indirect jump
L53:
.debug
	.dw '.stabn 0x44,0,110,',0,0
	.dd LM82-_disp_delay
	.dw 0x0d,0x0a
.code
LM82:
	R2=BP	// QImode move
	R3=BP+1
	R2=0	// QImode move
	R4=R3	// QImode move
	[R4]=R2	// QImode move
L54:
	R2=BP	// QImode move
	R3=BP+1
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	CMP R2,239	// QImode compare
	NSJNG L57	//QImode LE
	pc=L52	// Indirect jump
L57:
.debug
	.dw '.stabn 0x44,0,111,',0,0
	.dd LM83-_disp_delay
	.dw 0x0d,0x0a
.code
LM83:
	R2=1	// QImode move
	[28690]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,110,',0,0
	.dd LM84-_disp_delay
	.dw 0x0d,0x0a
.code
LM84:
L56:
	R2=BP	// QImode move
	R3=BP+1
	R4=BP	// QImode move
	R2=BP+1
	R3=BP	// QImode move
	R3=BP+1
	[bp+2]=R3	// QImode move
	R4=[bp+2]	// QImode move
	R3=[R4]	// QImode move
	R4=R3+1
	R3=R2	// QImode move
	[R3]=R4	// QImode move
	pc=L54	// Indirect jump
L55:
.debug
	.dw '.stabn 0x44,0,108,',0,0
	.dd LM85-_disp_delay
	.dw 0x0d,0x0a
.code
LM85:
L52:
	R2=[BP]	// QImode move
	R3=R2+1
	[BP]=R3	// QImode move
	pc=L50	// Indirect jump
L51:
.debug
	.dw '.stabn 0x44,0,113,',0,0
	.dd LM86-_disp_delay
	.dw 0x0d,0x0a
.code
LM86:
LBE3:
.debug
	.dw '.stabn 0x44,0,113,',0,0
	.dd LM87-_disp_delay
	.dw 0x0d,0x0a
.code
LM87:
L49:

	sp+=3
	pop bp from [sp]
	retf
	.endp	// end of disp_delay

.debug
	.dw '.stabs "j:p1",160,0,0,6',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB3-_disp_delay
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "DelayValuel:1",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "DelayValue2:1",128,0,0,1',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE3-_disp_delay
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME3-_disp_delay
	.dw 0x0d,0x0a
.code
LME3:
.code
.debug
	.dw '.stabs "disp_ID:F19",36,0,0,',0,0,offset _disp_ID,seg _disp_ID,0x0d,0x0a
.CODE
.public _disp_ID
_disp_ID:	.proc
.debug
	.dw '.stabn 0x44,0,116,',0,0
	.dd LM88-_disp_ID
	.dw 0x0d,0x0a
.code
LM88:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,117,',0,0
	.dd LM89-_disp_ID
	.dw 0x0d,0x0a
.code
LM89:
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	R1=2	// QImode move
	[SP--]=R1	// QImode move
	R1=4	// QImode move
	[SP--]=R1	// QImode move
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	call _disp	// call without return value
	SP = SP + 4	//SP
.debug
	.dw '.stabn 0x44,0,118,',0,0
	.dd LM90-_disp_ID
	.dw 0x0d,0x0a
.code
LM90:
.debug
	.dw '.stabn 0x44,0,118,',0,0
	.dd LM91-_disp_ID
	.dw 0x0d,0x0a
.code
LM91:
L60:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of disp_ID

.debug
	.dw '.stabf ',0,0
	.dd LME4-_disp_ID
	.dw 0x0d,0x0a
.code
LME4:
.iram
.public _apm
_apm:
	.dw 0
.external _num
.external __BlockCopy
.external __cvf2i1
.external __cvi1f2
.external __divi1
.external __modi1
	.end

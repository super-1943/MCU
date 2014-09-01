// GCC for SUNPLUS u'nSP version 1.0.21-3
// Command: D:\PROGRA~1\Sunplus\UNSPID~1.0\cc1.exe C:\DOCUME~1\ADMINI~1\LOCALS~1\Temp\ccMHaaaa.i -fkeep-inline-functions -quiet -dumpbase system.c -mglobal-var-iram -gstabs -Wall -o .\Debug/system.asm
	.external __sn_func_ptr_sec

// gcc2_compiled.:

.debug
	.dw '.stabs "C:/Documents and Settings/Administrator/×ÀÃæ/voice/voice/",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
.code
.debug
	.dw '.stabs "C:/Documents and Settings/Administrator/×/300Ã/346/voice/voice/system.c",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
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
.public _num
.iram
_num:
	.dw 0
.debug
	.dw '.stabs "num:G4",32,0,0,',0,0,offset _num,seg _num,0x0d,0x0a
.CODE
.public _adjustflag
.iram
_adjustflag:
	.dw 0
.debug
	.dw '.stabs "adjustflag:G11",32,0,0,',0,0,offset _adjustflag,seg _adjustflag,0x0d,0x0a
.CODE
.public _nflag
.iram
_nflag:
	.dw 0
.debug
	.dw '.stabs "nflag:G11",32,0,0,',0,0,offset _nflag,seg _nflag,0x0d,0x0a
.CODE
.code
.debug
	.dw '.stabs "DelayTime:F19",36,0,0,',0,0,offset _DelayTime,seg _DelayTime,0x0d,0x0a
.CODE
.public _DelayTime
_DelayTime:	.proc
.debug
	.dw '.stabn 0x44,0,18,',0,0
	.dd LM1-_DelayTime
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
	.dw '.stabn 0x44,0,19,',0,0
	.dd LM2-_DelayTime
	.dw 0x0d,0x0a
.code
LM2:
LBB2:
.debug
	.dw '.stabn 0x44,0,20,',0,0
	.dd LM3-_DelayTime
	.dw 0x0d,0x0a
.code
LM3:
	R2=0	// QImode move
	[BP]=R2	// QImode move
L3:
	R2=[BP]	// QImode move
	R3=R1	// QImode move
	CMP R2,[R3]	// QImode compare
	NSJB L6	//QImode LTU
	pc=L4	// Indirect jump
L6:
.debug
	.dw '.stabn 0x44,0,21,',0,0
	.dd LM4-_DelayTime
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
	CMP R2,9	// QImode compare
	NSJNA L10	//QImode LEU
	pc=L5	// Indirect jump
L10:
.debug
	.dw '.stabn 0x44,0,22,',0,0
	.dd LM5-_DelayTime
	.dw 0x0d,0x0a
.code
LM5:
	R2=1	// QImode move
	[28690]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,21,',0,0
	.dd LM6-_DelayTime
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
	R4=R3+1
	R3=R2	// QImode move
	[R3]=R4	// QImode move
	pc=L7	// Indirect jump
L8:
.debug
	.dw '.stabn 0x44,0,20,',0,0
	.dd LM7-_DelayTime
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
	.dw '.stabn 0x44,0,23,',0,0
	.dd LM8-_DelayTime
	.dw 0x0d,0x0a
.code
LM8:
LBE2:
.debug
	.dw '.stabn 0x44,0,23,',0,0
	.dd LM9-_DelayTime
	.dw 0x0d,0x0a
.code
LM9:
L2:

	sp+=3
	pop bp from [sp]
	retf
	.endp	// end of DelayTime

.debug
	.dw '.stabs "ii:p1",160,0,0,6',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB2-_DelayTime
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "aa:4",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "bb:4",128,0,0,1',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE2-_DelayTime
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME1-_DelayTime
	.dw 0x0d,0x0a
.code
LME1:
.code
.debug
	.dw '.stabs "clock:F19",36,0,0,',0,0,offset _clock,seg _clock,0x0d,0x0a
.CODE
.public _clock
_clock:	.proc
.debug
	.dw '.stabn 0x44,0,25,',0,0
	.dd LM10-_clock
	.dw 0x0d,0x0a
.code
LM10:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,26,',0,0
	.dd LM11-_clock
	.dw 0x0d,0x0a
.code
LM11:
	R2=[_num]	// QImode move
	CMP R2,2	// QImode compare
	NSJNZ L14	//QImode NE
.debug
	.dw '.stabn 0x44,0,28,',0,0
	.dd LM12-_clock
	.dw 0x0d,0x0a
.code
LM12:
	R2=0	// QImode move
	[_num]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,29,',0,0
	.dd LM13-_clock
	.dw 0x0d,0x0a
.code
LM13:
	R2=_sec	// QImode move
	R4=R2	// QImode move
	R3=[R4]	// QImode move
	[_sec]=R3	// QImode move
	R3=R3+1
	R4=R2	// QImode move
	[R4]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,30,',0,0
	.dd LM14-_clock
	.dw 0x0d,0x0a
.code
LM14:
	R2=[_hour]	// QImode move
	CMP R2,11	// QImode compare
	NSJNZ L14	//QImode NE
	R2=[_min]	// QImode move
	CMP R2,59	// QImode compare
	NSJNZ L14	//QImode NE
	R2=[_sec]	// QImode move
	CMP R2,60	// QImode compare
	NSJNZ L14	//QImode NE
.debug
	.dw '.stabn 0x44,0,31,',0,0
	.dd LM15-_clock
	.dw 0x0d,0x0a
.code
LM15:
	R2=[_apm]	// QImode move
	R3=R2^0xffff	// one_cmplqi2
	[_apm]=R3	// QImode move
L15:
L14:
.debug
	.dw '.stabn 0x44,0,33,',0,0
	.dd LM16-_clock
	.dw 0x0d,0x0a
.code
LM16:
	R2=[_sec]	// QImode move
	CMP R2,60	// QImode compare
	NSJNZ L16	//QImode NE
.debug
	.dw '.stabn 0x44,0,35,',0,0
	.dd LM17-_clock
	.dw 0x0d,0x0a
.code
LM17:
	R2=0	// QImode move
	[_sec]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,36,',0,0
	.dd LM18-_clock
	.dw 0x0d,0x0a
.code
LM18:
	R3=[_min]	// QImode move
	R2=R3+1
	R3=R2	// QImode move
	[_min]=R3	// QImode move
	[_min]=R3	// QImode move
L16:
.debug
	.dw '.stabn 0x44,0,38,',0,0
	.dd LM19-_clock
	.dw 0x0d,0x0a
.code
LM19:
	R2=[_min]	// QImode move
	CMP R2,60	// QImode compare
	NSJNZ L17	//QImode NE
.debug
	.dw '.stabn 0x44,0,40,',0,0
	.dd LM20-_clock
	.dw 0x0d,0x0a
.code
LM20:
	R2=0	// QImode move
	[_min]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,41,',0,0
	.dd LM21-_clock
	.dw 0x0d,0x0a
.code
LM21:
	R3=[_hour]	// QImode move
	R2=R3+1
	R3=R2	// QImode move
	[_hour]=R3	// QImode move
	[_hour]=R3	// QImode move
L17:
.debug
	.dw '.stabn 0x44,0,43,',0,0
	.dd LM22-_clock
	.dw 0x0d,0x0a
.code
LM22:
	R2=[_hour]	// QImode move
	CMP R2,12	// QImode compare
	NSJNA L18	//QImode LEU
.debug
	.dw '.stabn 0x44,0,45,',0,0
	.dd LM23-_clock
	.dw 0x0d,0x0a
.code
LM23:
	R2=1	// QImode move
	[_hour]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,46,',0,0
	.dd LM24-_clock
	.dw 0x0d,0x0a
.code
LM24:
	R2=[_apm]	// QImode move
	R3=R2^0xffff	// one_cmplqi2
	[_apm]=R3	// QImode move
L18:
.debug
	.dw '.stabn 0x44,0,49,',0,0
	.dd LM25-_clock
	.dw 0x0d,0x0a
.code
LM25:
.debug
	.dw '.stabn 0x44,0,49,',0,0
	.dd LM26-_clock
	.dw 0x0d,0x0a
.code
LM26:
L13:

	pop bp from [sp]
	retf
	.endp	// end of clock

.debug
	.dw '.stabf ',0,0
	.dd LME2-_clock
	.dw 0x0d,0x0a
.code
LME2:
.code
.debug
	.dw '.stabs "AdjustInit:F19",36,0,0,',0,0,offset _AdjustInit,seg _AdjustInit,0x0d,0x0a
.CODE
.public _AdjustInit
_AdjustInit:	.proc
.debug
	.dw '.stabn 0x44,0,53,',0,0
	.dd LM27-_AdjustInit
	.dw 0x0d,0x0a
.code
LM27:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,54,',0,0
	.dd LM28-_AdjustInit
	.dw 0x0d,0x0a
.code
LM28:
	R2=[28674]	// QImode move
	R3=R2&(-16)
	[28674]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,55,',0,0
	.dd LM29-_AdjustInit
	.dw 0x0d,0x0a
.code
LM29:
	R2=[28675]	// QImode move
	R3=R2|15
	[28675]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,56,',0,0
	.dd LM30-_AdjustInit
	.dw 0x0d,0x0a
.code
LM30:
	R2=[28672]	// QImode move
	R3=R2&(-16)
	[28672]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,57,',0,0
	.dd LM31-_AdjustInit
	.dw 0x0d,0x0a
.code
LM31:
.debug
	.dw '.stabn 0x44,0,57,',0,0
	.dd LM32-_AdjustInit
	.dw 0x0d,0x0a
.code
LM32:
L26:

	pop bp from [sp]
	retf
	.endp	// end of AdjustInit

.debug
	.dw '.stabf ',0,0
	.dd LME3-_AdjustInit
	.dw 0x0d,0x0a
.code
LME3:
.code
.debug
	.dw '.stabs "ModeSel:F19",36,0,0,',0,0,offset _ModeSel,seg _ModeSel,0x0d,0x0a
.CODE
.public _ModeSel
_ModeSel:	.proc
.debug
	.dw '.stabn 0x44,0,64,',0,0
	.dd LM33-_ModeSel
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
	.dw '.stabn 0x44,0,65,',0,0
	.dd LM34-_ModeSel
	.dw 0x0d,0x0a
.code
LM34:
	R2=[28672]	// QImode move
	R1=R2&1
	CMP R1,0	// QImode test
	NSJNZ L28	//QImode NE
.debug
	.dw '.stabn 0x44,0,67,',0,0
	.dd LM35-_ModeSel
	.dw 0x0d,0x0a
.code
LM35:
	R1=5000	// QImode move
	[SP--]=R1	// QImode move
	call _DelayTime	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,68,',0,0
	.dd LM36-_ModeSel
	.dw 0x0d,0x0a
.code
LM36:
	R1=[_nflag]	// QImode move
	CMP R1,0	// QImode test
	NSJNZ L28	//QImode NE
.debug
	.dw '.stabn 0x44,0,70,',0,0
	.dd LM37-_ModeSel
	.dw 0x0d,0x0a
.code
LM37:
L30:
	R2=[28672]	// QImode move
	R1=R2&1
	CMP R1,0	// QImode test
	NSJZ L32	//QImode EQ
	pc=L31	// Indirect jump
L32:
.debug
	.dw '.stabn 0x44,0,71,',0,0
	.dd LM38-_ModeSel
	.dw 0x0d,0x0a
.code
LM38:
	R1=1	// QImode move
	[28690]=R1	// QImode move
	pc=L30	// Indirect jump
L31:
.debug
	.dw '.stabn 0x44,0,72,',0,0
	.dd LM39-_ModeSel
	.dw 0x0d,0x0a
.code
LM39:
	R2=[_shan_flag]	// QImode move
	R1=R2+1
	R2=3	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __modu1	// call with return value
	SP = SP + 2	//SP
	[_shan_flag]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,73,',0,0
	.dd LM40-_ModeSel
	.dw 0x0d,0x0a
.code
LM40:
	R2=[_adjustflag]	// QImode move
	R1=R2+1
	R2=3	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __modu1	// call with return value
	SP = SP + 2	//SP
	[_adjustflag]=R1	// QImode move
L29:
L28:
.debug
	.dw '.stabn 0x44,0,76,',0,0
	.dd LM41-_ModeSel
	.dw 0x0d,0x0a
.code
LM41:
	R2=[28672]	// QImode move
	R1=R2&2
	CMP R1,0	// QImode test
	NSJNZ L33	//QImode NE
.debug
	.dw '.stabn 0x44,0,78,',0,0
	.dd LM42-_ModeSel
	.dw 0x0d,0x0a
.code
LM42:
	R1=5000	// QImode move
	[SP--]=R1	// QImode move
	call _DelayTime	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,80,',0,0
	.dd LM43-_ModeSel
	.dw 0x0d,0x0a
.code
LM43:
	R1=[_adjustflag]	// QImode move
	CMP R1,0	// QImode test
	NSJNZ L33	//QImode NE
.debug
	.dw '.stabn 0x44,0,83,',0,0
	.dd LM44-_ModeSel
	.dw 0x0d,0x0a
.code
LM44:
	R1=5000	// QImode move
	[SP--]=R1	// QImode move
	call _DelayTime	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,84,',0,0
	.dd LM45-_ModeSel
	.dw 0x0d,0x0a
.code
LM45:
L35:
	R2=[28672]	// QImode move
	R1=R2&2
	CMP R1,0	// QImode test
	NSJZ L37	//QImode EQ
	pc=L36	// Indirect jump
L37:
.debug
	.dw '.stabn 0x44,0,85,',0,0
	.dd LM46-_ModeSel
	.dw 0x0d,0x0a
.code
LM46:
	R1=1	// QImode move
	[28690]=R1	// QImode move
	pc=L35	// Indirect jump
L36:
.debug
	.dw '.stabn 0x44,0,90,',0,0
	.dd LM47-_ModeSel
	.dw 0x0d,0x0a
.code
LM47:
	R2=[_shan_flag]	// QImode move
	R1=R2+1
	R2=3	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __modu1	// call with return value
	SP = SP + 2	//SP
	[_shan_flag]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,91,',0,0
	.dd LM48-_ModeSel
	.dw 0x0d,0x0a
.code
LM48:
	R2=[_nflag]	// QImode move
	R1=R2+1
	R2=3	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __modu1	// call with return value
	SP = SP + 2	//SP
	[_nflag]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,92,',0,0
	.dd LM49-_ModeSel
	.dw 0x0d,0x0a
.code
LM49:
	R1=[_nflag]	// QImode move
	CMP R1,0	// QImode test
	NSJNZ L38	//QImode NE
.debug
	.dw '.stabn 0x44,0,94,',0,0
	.dd LM50-_ModeSel
	.dw 0x0d,0x0a
.code
LM50:
	R1=1	// QImode move
	[_is_nao]=R1	// QImode move
L38:
.debug
	.dw '.stabn 0x44,0,96,',0,0
	.dd LM51-_ModeSel
	.dw 0x0d,0x0a
.code
LM51:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,98,',0,0
	.dd LM52-_ModeSel
	.dw 0x0d,0x0a
.code
LM52:
	R1=5000	// QImode move
	[SP--]=R1	// QImode move
	call _DelayTime	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,99,',0,0
	.dd LM53-_ModeSel
	.dw 0x0d,0x0a
.code
LM53:
L39:
	R2=[28672]	// QImode move
	R1=R2&2
	CMP R1,0	// QImode test
	NSJZ L41	//QImode EQ
	pc=L33	// Indirect jump
L41:
.debug
	.dw '.stabn 0x44,0,100,',0,0
	.dd LM54-_ModeSel
	.dw 0x0d,0x0a
.code
LM54:
	R1=1	// QImode move
	[28690]=R1	// QImode move
	pc=L39	// Indirect jump
L40:
L34:
L33:
.debug
	.dw '.stabn 0x44,0,105,',0,0
	.dd LM55-_ModeSel
	.dw 0x0d,0x0a
.code
LM55:
	R2=[28672]	// QImode move
	R1=R2&4
	CMP R1,0	// QImode test
	NSJNZ L42	//QImode NE
.debug
	.dw '.stabn 0x44,0,107,',0,0
	.dd LM56-_ModeSel
	.dw 0x0d,0x0a
.code
LM56:
	R1=5000	// QImode move
	[SP--]=R1	// QImode move
	call _DelayTime	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,108,',0,0
	.dd LM57-_ModeSel
	.dw 0x0d,0x0a
.code
LM57:
	R1=[_adjustflag]	// QImode move
	CMP R1,0	// QImode test
	NSJNZ L43	//QImode NE
	R1=[_nflag]	// QImode move
	CMP R1,0	// QImode test
	NSJNZ L43	//QImode NE
.debug
	.dw '.stabn 0x44,0,111,',0,0
	.dd LM58-_ModeSel
	.dw 0x0d,0x0a
.code
LM58:
	R1=[_min]	// QImode move
	[SP--]=R1	// QImode move
	R1=[_hour]	// QImode move
	[SP--]=R1	// QImode move
	call _PlayClock	// call without return value
	SP = SP + 2	//SP
L43:
.debug
	.dw '.stabn 0x44,0,113,',0,0
	.dd LM59-_ModeSel
	.dw 0x0d,0x0a
.code
LM59:
	R1=[_adjustflag]	// QImode move
	CMP R1,1	// QImode compare
	NSJNZ L44	//QImode NE
.debug
	.dw '.stabn 0x44,0,114,',0,0
	.dd LM60-_ModeSel
	.dw 0x0d,0x0a
.code
LM60:
	R1=[_hour]	// QImode move
	R2=1	// QImode move
	[_hour]=R1+R2  //addqi3_Qrr
L44:
.debug
	.dw '.stabn 0x44,0,115,',0,0
	.dd LM61-_ModeSel
	.dw 0x0d,0x0a
.code
LM61:
	R1=[_adjustflag]	// QImode move
	CMP R1,2	// QImode compare
	NSJNZ L45	//QImode NE
.debug
	.dw '.stabn 0x44,0,116,',0,0
	.dd LM62-_ModeSel
	.dw 0x0d,0x0a
.code
LM62:
	R1=[_min]	// QImode move
	R2=1	// QImode move
	[_min]=R1+R2  //addqi3_Qrr
L45:
.debug
	.dw '.stabn 0x44,0,118,',0,0
	.dd LM63-_ModeSel
	.dw 0x0d,0x0a
.code
LM63:
	R1=[_nflag]	// QImode move
	CMP R1,1	// QImode compare
	NSJNZ L46	//QImode NE
.debug
	.dw '.stabn 0x44,0,119,',0,0
	.dd LM64-_ModeSel
	.dw 0x0d,0x0a
.code
LM64:
	R1=[_nhour]	// QImode move
	R2=1	// QImode move
	[_nhour]=R1+R2  //addqi3_Qrr
L46:
.debug
	.dw '.stabn 0x44,0,120,',0,0
	.dd LM65-_ModeSel
	.dw 0x0d,0x0a
.code
LM65:
	R1=[_nflag]	// QImode move
	CMP R1,2	// QImode compare
	NSJNZ L42	//QImode NE
.debug
	.dw '.stabn 0x44,0,121,',0,0
	.dd LM66-_ModeSel
	.dw 0x0d,0x0a
.code
LM66:
	R1=[_nmin]	// QImode move
	R2=1	// QImode move
	[_nmin]=R1+R2  //addqi3_Qrr
L47:
L42:
.debug
	.dw '.stabn 0x44,0,123,',0,0
	.dd LM67-_ModeSel
	.dw 0x0d,0x0a
.code
LM67:
	R2=[28672]	// QImode move
	R1=R2&8
	CMP R1,0	// QImode test
	NSJNZ L48	//QImode NE
.debug
	.dw '.stabn 0x44,0,125,',0,0
	.dd LM68-_ModeSel
	.dw 0x0d,0x0a
.code
LM68:
	R1=5000	// QImode move
	[SP--]=R1	// QImode move
	call _DelayTime	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,126,',0,0
	.dd LM69-_ModeSel
	.dw 0x0d,0x0a
.code
LM69:
	R1=[_adjustflag]	// QImode move
	CMP R1,0	// QImode test
	NSJNZ L49	//QImode NE
	R1=[_nflag]	// QImode move
	CMP R1,0	// QImode test
	NSJNZ L49	//QImode NE
.debug
	.dw '.stabn 0x44,0,129,',0,0
	.dd LM70-_ModeSel
	.dw 0x0d,0x0a
.code
LM70:
	R1=[_tep]	// QImode move
	[SP--]=R1	// QImode move
	call _Playtemp	// call without return value
	SP = SP + 1	//SP
L49:
.debug
	.dw '.stabn 0x44,0,131,',0,0
	.dd LM71-_ModeSel
	.dw 0x0d,0x0a
.code
LM71:
	R1=[_adjustflag]	// QImode move
	CMP R1,1	// QImode compare
	NSJNZ L50	//QImode NE
.debug
	.dw '.stabn 0x44,0,132,',0,0
	.dd LM72-_ModeSel
	.dw 0x0d,0x0a
.code
LM72:
	R1=[_hour]	// QImode move
	R2=(-1)	// QImode move
	[_hour]=R1+R2  //addqi3_Qrr
L50:
.debug
	.dw '.stabn 0x44,0,133,',0,0
	.dd LM73-_ModeSel
	.dw 0x0d,0x0a
.code
LM73:
	R1=[_adjustflag]	// QImode move
	CMP R1,2	// QImode compare
	NSJNZ L51	//QImode NE
.debug
	.dw '.stabn 0x44,0,134,',0,0
	.dd LM74-_ModeSel
	.dw 0x0d,0x0a
.code
LM74:
	R1=[_min]	// QImode move
	R2=(-1)	// QImode move
	[_min]=R1+R2  //addqi3_Qrr
L51:
.debug
	.dw '.stabn 0x44,0,135,',0,0
	.dd LM75-_ModeSel
	.dw 0x0d,0x0a
.code
LM75:
	R1=[_nflag]	// QImode move
	CMP R1,1	// QImode compare
	NSJNZ L52	//QImode NE
.debug
	.dw '.stabn 0x44,0,137,',0,0
	.dd LM76-_ModeSel
	.dw 0x0d,0x0a
.code
LM76:
	R1=[_nhour]	// QImode move
	R2=(-1)	// QImode move
	[_nhour]=R1+R2  //addqi3_Qrr
L52:
.debug
	.dw '.stabn 0x44,0,139,',0,0
	.dd LM77-_ModeSel
	.dw 0x0d,0x0a
.code
LM77:
	R1=[_nflag]	// QImode move
	CMP R1,2	// QImode compare
	NSJNZ L48	//QImode NE
.debug
	.dw '.stabn 0x44,0,141,',0,0
	.dd LM78-_ModeSel
	.dw 0x0d,0x0a
.code
LM78:
	R1=[_nmin]	// QImode move
	R2=(-1)	// QImode move
	[_nmin]=R1+R2  //addqi3_Qrr
L53:
L48:
.debug
	.dw '.stabn 0x44,0,145,',0,0
	.dd LM79-_ModeSel
	.dw 0x0d,0x0a
.code
LM79:
	R1=[_min]	// QImode move
	CMP R1,60	// QImode compare
	NSJNZ L54	//QImode NE
.debug
	.dw '.stabn 0x44,0,147,',0,0
	.dd LM80-_ModeSel
	.dw 0x0d,0x0a
.code
LM80:
	R1=0	// QImode move
	[_min]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,148,',0,0
	.dd LM81-_ModeSel
	.dw 0x0d,0x0a
.code
LM81:
	R2=[_hour]	// QImode move
	R1=R2+1
	R2=R1	// QImode move
	[_hour]=R2	// QImode move
	[_hour]=R2	// QImode move
L54:
.debug
	.dw '.stabn 0x44,0,150,',0,0
	.dd LM82-_ModeSel
	.dw 0x0d,0x0a
.code
LM82:
	R1=[_min]	// QImode move
	CMP R1,(-1)	// QImode compare
	NSJNZ L55	//QImode NE
.debug
	.dw '.stabn 0x44,0,152,',0,0
	.dd LM83-_ModeSel
	.dw 0x0d,0x0a
.code
LM83:
	R1=59	// QImode move
	[_min]=R1	// QImode move
L55:
.debug
	.dw '.stabn 0x44,0,154,',0,0
	.dd LM84-_ModeSel
	.dw 0x0d,0x0a
.code
LM84:
	R1=[_hour]	// QImode move
	CMP R1,12	// QImode compare
	NSJNA L56	//QImode LEU
.debug
	.dw '.stabn 0x44,0,156,',0,0
	.dd LM85-_ModeSel
	.dw 0x0d,0x0a
.code
LM85:
	R1=1	// QImode move
	[_hour]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,157,',0,0
	.dd LM86-_ModeSel
	.dw 0x0d,0x0a
.code
LM86:
	R1=[_apm]	// QImode move
	R2=R1^0xffff	// one_cmplqi2
	[_apm]=R2	// QImode move
L56:
.debug
	.dw '.stabn 0x44,0,159,',0,0
	.dd LM87-_ModeSel
	.dw 0x0d,0x0a
.code
LM87:
	R1=[_hour]	// QImode move
	CMP R1,0	// QImode test
	NSJNZ L57	//QImode NE
.debug
	.dw '.stabn 0x44,0,161,',0,0
	.dd LM88-_ModeSel
	.dw 0x0d,0x0a
.code
LM88:
	R1=12	// QImode move
	[_hour]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,162,',0,0
	.dd LM89-_ModeSel
	.dw 0x0d,0x0a
.code
LM89:
	R1=[_apm]	// QImode move
	R2=R1^0xffff	// one_cmplqi2
	[_apm]=R2	// QImode move
L57:
.debug
	.dw '.stabn 0x44,0,165,',0,0
	.dd LM90-_ModeSel
	.dw 0x0d,0x0a
.code
LM90:
	R1=[_nmin]	// QImode move
	CMP R1,60	// QImode compare
	NSJNZ L58	//QImode NE
.debug
	.dw '.stabn 0x44,0,167,',0,0
	.dd LM91-_ModeSel
	.dw 0x0d,0x0a
.code
LM91:
	R1=0	// QImode move
	[_nmin]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,168,',0,0
	.dd LM92-_ModeSel
	.dw 0x0d,0x0a
.code
LM92:
	R2=[_nhour]	// QImode move
	R1=R2+1
	R2=R1	// QImode move
	[_nhour]=R2	// QImode move
	[_nhour]=R2	// QImode move
L58:
.debug
	.dw '.stabn 0x44,0,170,',0,0
	.dd LM93-_ModeSel
	.dw 0x0d,0x0a
.code
LM93:
	R1=[_nmin]	// QImode move
	CMP R1,(-1)	// QImode compare
	NSJNZ L59	//QImode NE
.debug
	.dw '.stabn 0x44,0,172,',0,0
	.dd LM94-_ModeSel
	.dw 0x0d,0x0a
.code
LM94:
	R1=59	// QImode move
	[_nmin]=R1	// QImode move
L59:
.debug
	.dw '.stabn 0x44,0,174,',0,0
	.dd LM95-_ModeSel
	.dw 0x0d,0x0a
.code
LM95:
	R1=[_nhour]	// QImode move
	CMP R1,12	// QImode compare
	NSJNA L60	//QImode LEU
.debug
	.dw '.stabn 0x44,0,176,',0,0
	.dd LM96-_ModeSel
	.dw 0x0d,0x0a
.code
LM96:
	R1=1	// QImode move
	[_nhour]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,177,',0,0
	.dd LM97-_ModeSel
	.dw 0x0d,0x0a
.code
LM97:
	R1=[_apm]	// QImode move
	R2=R1^0xffff	// one_cmplqi2
	[_apm]=R2	// QImode move
L60:
.debug
	.dw '.stabn 0x44,0,179,',0,0
	.dd LM98-_ModeSel
	.dw 0x0d,0x0a
.code
LM98:
	R1=[_nhour]	// QImode move
	CMP R1,0	// QImode test
	NSJNZ L61	//QImode NE
.debug
	.dw '.stabn 0x44,0,181,',0,0
	.dd LM99-_ModeSel
	.dw 0x0d,0x0a
.code
LM99:
	R1=12	// QImode move
	[_nhour]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,182,',0,0
	.dd LM100-_ModeSel
	.dw 0x0d,0x0a
.code
LM100:
	R1=[_apm]	// QImode move
	R2=R1^0xffff	// one_cmplqi2
	[_apm]=R2	// QImode move
L61:
.debug
	.dw '.stabn 0x44,0,184,',0,0
	.dd LM101-_ModeSel
	.dw 0x0d,0x0a
.code
LM101:
L62:
	R2=[28672]	// QImode move
	R1=R2&15
	CMP R1,15	// QImode compare
	NSJNZ L64	//QImode NE
	pc=L63	// Indirect jump
L64:
.debug
	.dw '.stabn 0x44,0,185,',0,0
	.dd LM102-_ModeSel
	.dw 0x0d,0x0a
.code
LM102:
	R1=1	// QImode move
	[28690]=R1	// QImode move
	pc=L62	// Indirect jump
L63:
.debug
	.dw '.stabn 0x44,0,186,',0,0
	.dd LM103-_ModeSel
	.dw 0x0d,0x0a
.code
LM103:
.debug
	.dw '.stabn 0x44,0,186,',0,0
	.dd LM104-_ModeSel
	.dw 0x0d,0x0a
.code
LM104:
L27:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of ModeSel

.debug
	.dw '.stabf ',0,0
	.dd LME4-_ModeSel
	.dw 0x0d,0x0a
.code
LME4:
.code
.debug
	.dw '.stabs "nclock:F19",36,0,0,',0,0,offset _nclock,seg _nclock,0x0d,0x0a
.CODE
.public _nclock
_nclock:	.proc
.debug
	.dw '.stabn 0x44,0,189,',0,0
	.dd LM105-_nclock
	.dw 0x0d,0x0a
.code
LM105:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,190,',0,0
	.dd LM106-_nclock
	.dw 0x0d,0x0a
.code
LM106:
	R1=[_nmin]	// QImode move
	CMP R1,[_min]	// QImode compare
	NSJNZ L97	//QImode NE
	R1=[_nhour]	// QImode move
	CMP R1,[_hour]	// QImode compare
	NSJNZ L97	//QImode NE
	R1=[_is_nao]	// QImode move
	CMP R1,1	// QImode compare
	NSJNZ L97	//QImode NE
.debug
	.dw '.stabn 0x44,0,192,',0,0
	.dd LM107-_nclock
	.dw 0x0d,0x0a
.code
LM107:
L98:
	R2=[28672]	// QImode move
	R1=R2&15
	CMP R1,15	// QImode compare
	NSJZ L100	//QImode EQ
	pc=L99	// Indirect jump
L100:
.debug
	.dw '.stabn 0x44,0,194,',0,0
	.dd LM108-_nclock
	.dw 0x0d,0x0a
.code
LM108:
	R1=[_min]	// QImode move
	[SP--]=R1	// QImode move
	R1=[_hour]	// QImode move
	[SP--]=R1	// QImode move
	call _PlayClock	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,195,',0,0
	.dd LM109-_nclock
	.dw 0x0d,0x0a
.code
LM109:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,196,',0,0
	.dd LM110-_nclock
	.dw 0x0d,0x0a
.code
LM110:
	R1=5000	// QImode move
	[SP--]=R1	// QImode move
	call _DelayTime	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,197,',0,0
	.dd LM111-_nclock
	.dw 0x0d,0x0a
.code
LM111:
	pc=L98	// Indirect jump
L99:
.debug
	.dw '.stabn 0x44,0,198,',0,0
	.dd LM112-_nclock
	.dw 0x0d,0x0a
.code
LM112:
	R1=0	// QImode move
	[_is_nao]=R1	// QImode move
L97:
.debug
	.dw '.stabn 0x44,0,200,',0,0
	.dd LM113-_nclock
	.dw 0x0d,0x0a
.code
LM113:
.debug
	.dw '.stabn 0x44,0,200,',0,0
	.dd LM114-_nclock
	.dw 0x0d,0x0a
.code
LM114:
L96:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of nclock

.debug
	.dw '.stabf ',0,0
	.dd LME5-_nclock
	.dw 0x0d,0x0a
.code
LME5:
.external _tep
.external _Playtemp
.external _nmin
.external _nhour
.external _PlayClock
.external _is_nao
.external _shan_flag
.external _apm
.external _min
.external _hour
.external _sec
.external __modu1
	.end

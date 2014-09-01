// GCC for SUNPLUS u'nSP version 1.0.21-3
// Command: D:\PROGRA~1\Sunplus\UNSPID~1.0\cc1.exe C:\DOCUME~1\ADMINI~1\LOCALS~1\Temp\ccYnaaaa.i -fkeep-inline-functions -quiet -dumpbase playsound.c -mglobal-var-iram -gstabs -Wall -o .\Debug/playsound.asm
	.external __sn_func_ptr_sec

// gcc2_compiled.:

.debug
	.dw '.stabs "C:/Documents and Settings/Administrator/×ÀÃæ/voice/voice/",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
.code
.debug
	.dw '.stabs "C:/Documents and Settings/Administrator/×/300Ã/346/voice/voice/playsound.c",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
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
.code
.debug
	.dw '.stabs "PlaySnd_Auto:F19",36,0,0,',0,0,offset _PlaySnd_Auto,seg _PlaySnd_Auto,0x0d,0x0a
.CODE
.public _PlaySnd_Auto
_PlaySnd_Auto:	.proc
.debug
	.dw '.stabn 0x44,0,5,',0,0
	.dd LM1-_PlaySnd_Auto
	.dw 0x0d,0x0a
.code
LM1:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,7,',0,0
	.dd LM2-_PlaySnd_Auto
	.dw 0x0d,0x0a
.code
LM2:
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	call _SACM_S480_Initial	// call with return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,8,',0,0
	.dd LM3-_PlaySnd_Auto
	.dw 0x0d,0x0a
.code
LM3:
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	R1=[BP]	// QImode move
	R3=[BP]	// QImode move
	R2=R3+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	R2=[BP]	// QImode move
	R1=[R2]	// QImode move
	[SP--]=R1	// QImode move
	call _SACM_S480_Play	// call without return value
	SP = SP + 3	//SP
.debug
	.dw '.stabn 0x44,0,9,',0,0
	.dd LM4-_PlaySnd_Auto
	.dw 0x0d,0x0a
.code
LM4:
L3:
	call _SACM_S480_Status	// call with return value
	R2=R1&1
	CMP R2,0	// QImode test
	NSJNZ L5	//QImode NE
	pc=L4	// Indirect jump
L5:
.debug
	.dw '.stabn 0x44,0,11,',0,0
	.dd LM5-_PlaySnd_Auto
	.dw 0x0d,0x0a
.code
LM5:
	call _SACM_S480_ServiceLoop	// call without return value
.debug
	.dw '.stabn 0x44,0,12,',0,0
	.dd LM6-_PlaySnd_Auto
	.dw 0x0d,0x0a
.code
LM6:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,13,',0,0
	.dd LM7-_PlaySnd_Auto
	.dw 0x0d,0x0a
.code
LM7:
	pc=L3	// Indirect jump
L4:
.debug
	.dw '.stabn 0x44,0,14,',0,0
	.dd LM8-_PlaySnd_Auto
	.dw 0x0d,0x0a
.code
LM8:
	call _SACM_S480_Stop	// call without return value
.debug
	.dw '.stabn 0x44,0,15,',0,0
	.dd LM9-_PlaySnd_Auto
	.dw 0x0d,0x0a
.code
LM9:
// GCC inline ASM start
	FIQ OFF
// GCC inline ASM end
.debug
	.dw '.stabn 0x44,0,17,',0,0
	.dd LM10-_PlaySnd_Auto
	.dw 0x0d,0x0a
.code
LM10:
.debug
	.dw '.stabn 0x44,0,17,',0,0
	.dd LM11-_PlaySnd_Auto
	.dw 0x0d,0x0a
.code
LM11:
L2:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of PlaySnd_Auto

.debug
	.dw '.stabs "uiSndIndex:p4",160,0,0,4',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "uiDAC_Chanl:p4",160,0,0,5',0x0d,0x0a
.CODE
.debug
	.dw '.stabf ',0,0
	.dd LME1-_PlaySnd_Auto
	.dw 0x0d,0x0a
.code
LME1:
.code
.debug
	.dw '.stabs "PlayClock:F19",36,0,0,',0,0,offset _PlayClock,seg _PlayClock,0x0d,0x0a
.CODE
.public _PlayClock
_PlayClock:	.proc
.debug
	.dw '.stabn 0x44,0,21,',0,0
	.dd LM12-_PlayClock
	.dw 0x0d,0x0a
.code
LM12:
	// total=8, vars=8
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=8
	bp=sp+1

	R1=BP+11
	[bp+4]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,22,',0,0
	.dd LM13-_PlayClock
	.dw 0x0d,0x0a
.code
LM13:
LBB2:
	R2=[bp+4]	// QImode move
	R1=[R2]	// QImode move
	R2=10	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __divu1	// call with return value
	SP = SP + 2	//SP
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,23,',0,0
	.dd LM14-_PlayClock
	.dw 0x0d,0x0a
.code
LM14:
	R1=BP	// QImode move
	R3=BP+1
	[bp+5]=R3	// QImode move
	R2=[bp+4]	// QImode move
	R1=[R2]	// QImode move
	R2=10	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __modu1	// call with return value
	SP = SP + 2	//SP
	R3=[bp+5]	// QImode move
	[R3]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,24,',0,0
	.dd LM15-_PlayClock
	.dw 0x0d,0x0a
.code
LM15:
	R1=BP	// QImode move
	R1=BP+2
	[bp+6]=R1	// QImode move
	R1=[bp+4]	// QImode move
	R3=[bp+4]	// QImode move
	R2=R3+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	R2=10	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __divu1	// call with return value
	SP = SP + 2	//SP
	R2=[bp+6]	// QImode move
	[R2]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,25,',0,0
	.dd LM16-_PlayClock
	.dw 0x0d,0x0a
.code
LM16:
	R1=BP	// QImode move
	R3=BP+3
	[bp+7]=R3	// QImode move
	R1=[bp+4]	// QImode move
	R1=[bp+4]	// QImode move
	R2=R1+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	R2=10	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __modu1	// call with return value
	SP = SP + 2	//SP
	R2=[bp+7]	// QImode move
	[R2]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,27,',0,0
	.dd LM17-_PlayClock
	.dw 0x0d,0x0a
.code
LM17:
	R3=[bp+4]	// QImode move
	R1=[R3]	// QImode move
	CMP R1,9	// QImode compare
	NSJA L8	//QImode GTU
.debug
	.dw '.stabn 0x44,0,28,',0,0
	.dd LM18-_PlayClock
	.dw 0x0d,0x0a
.code
LM18:
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	R2=[bp+4]	// QImode move
	R1=[R2]	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd_Auto	// call without return value
	SP = SP + 2	//SP
	pc=L9	// Indirect jump
L8:
.debug
	.dw '.stabn 0x44,0,29,',0,0
	.dd LM19-_PlayClock
	.dw 0x0d,0x0a
.code
LM19:
	R1=BP	// QImode move
	R2=BP+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	CMP R1,0	// QImode test
	NSJNZ L10	//QImode NE
.debug
	.dw '.stabn 0x44,0,31,',0,0
	.dd LM20-_PlayClock
	.dw 0x0d,0x0a
.code
LM20:
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	R1=[BP]	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd_Auto	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,32,',0,0
	.dd LM21-_PlayClock
	.dw 0x0d,0x0a
.code
LM21:
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	R1=10	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd_Auto	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,33,',0,0
	.dd LM22-_PlayClock
	.dw 0x0d,0x0a
.code
LM22:
	pc=L9	// Indirect jump
L10:
.debug
	.dw '.stabn 0x44,0,36,',0,0
	.dd LM23-_PlayClock
	.dw 0x0d,0x0a
.code
LM23:
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	R1=[BP]	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd_Auto	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,37,',0,0
	.dd LM24-_PlayClock
	.dw 0x0d,0x0a
.code
LM24:
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	R1=10	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd_Auto	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,38,',0,0
	.dd LM25-_PlayClock
	.dw 0x0d,0x0a
.code
LM25:
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	R1=BP	// QImode move
	R2=BP+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd_Auto	// call without return value
	SP = SP + 2	//SP
L11:
L9:
.debug
	.dw '.stabn 0x44,0,41,',0,0
	.dd LM26-_PlayClock
	.dw 0x0d,0x0a
.code
LM26:
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	R1=14	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd_Auto	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,43,',0,0
	.dd LM27-_PlayClock
	.dw 0x0d,0x0a
.code
LM27:
	R1=[bp+4]	// QImode move
	R1=[bp+4]	// QImode move
	R2=R1+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	CMP R1,0	// QImode test
	NSJNZ L12	//QImode NE
.debug
	.dw '.stabn 0x44,0,45,',0,0
	.dd LM28-_PlayClock
	.dw 0x0d,0x0a
.code
LM28:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,46,',0,0
	.dd LM29-_PlayClock
	.dw 0x0d,0x0a
.code
LM29:
	pc=L13	// Indirect jump
L12:
.debug
	.dw '.stabn 0x44,0,47,',0,0
	.dd LM30-_PlayClock
	.dw 0x0d,0x0a
.code
LM30:
	R1=BP	// QImode move
	R2=BP+3
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	CMP R1,0	// QImode test
	NSJNZ L14	//QImode NE
.debug
	.dw '.stabn 0x44,0,49,',0,0
	.dd LM31-_PlayClock
	.dw 0x0d,0x0a
.code
LM31:
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	R1=BP	// QImode move
	R2=BP+2
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd_Auto	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,50,',0,0
	.dd LM32-_PlayClock
	.dw 0x0d,0x0a
.code
LM32:
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	R1=10	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd_Auto	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,51,',0,0
	.dd LM33-_PlayClock
	.dw 0x0d,0x0a
.code
LM33:
	pc=L13	// Indirect jump
L14:
.debug
	.dw '.stabn 0x44,0,52,',0,0
	.dd LM34-_PlayClock
	.dw 0x0d,0x0a
.code
LM34:
	R1=BP	// QImode move
	R2=BP+2
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	CMP R1,0	// QImode test
	NSJNZ L16	//QImode NE
.debug
	.dw '.stabn 0x44,0,54,',0,0
	.dd LM35-_PlayClock
	.dw 0x0d,0x0a
.code
LM35:
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	R1=BP	// QImode move
	R2=BP+3
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd_Auto	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,55,',0,0
	.dd LM36-_PlayClock
	.dw 0x0d,0x0a
.code
LM36:
	pc=L13	// Indirect jump
L16:
.debug
	.dw '.stabn 0x44,0,58,',0,0
	.dd LM37-_PlayClock
	.dw 0x0d,0x0a
.code
LM37:
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	R1=BP	// QImode move
	R2=BP+2
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd_Auto	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,59,',0,0
	.dd LM38-_PlayClock
	.dw 0x0d,0x0a
.code
LM38:
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	R1=10	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd_Auto	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,60,',0,0
	.dd LM39-_PlayClock
	.dw 0x0d,0x0a
.code
LM39:
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	R1=BP	// QImode move
	R2=BP+3
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd_Auto	// call without return value
	SP = SP + 2	//SP
L17:
L15:
L13:
.debug
	.dw '.stabn 0x44,0,62,',0,0
	.dd LM40-_PlayClock
	.dw 0x0d,0x0a
.code
LM40:
LBE2:
.debug
	.dw '.stabn 0x44,0,62,',0,0
	.dd LM41-_PlayClock
	.dw 0x0d,0x0a
.code
LM41:
L7:

	sp+=8
	pop bp from [sp]
	retf
	.endp	// end of PlayClock

.debug
	.dw '.stabs "h:p11",160,0,0,11',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "m:p11",160,0,0,12',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB2-_PlayClock
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "hhour:11",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "lhour:11",128,0,0,1',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "hmin:11",128,0,0,2',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "lmin:11",128,0,0,3',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE2-_PlayClock
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME2-_PlayClock
	.dw 0x0d,0x0a
.code
LME2:
.code
.debug
	.dw '.stabs "Playtemp:F19",36,0,0,',0,0,offset _Playtemp,seg _Playtemp,0x0d,0x0a
.CODE
.public _Playtemp
_Playtemp:	.proc
.debug
	.dw '.stabn 0x44,0,65,',0,0
	.dd LM42-_Playtemp
	.dw 0x0d,0x0a
.code
LM42:
	// total=4, vars=4
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=4
	bp=sp+1

	R1=BP+7
	[bp+2]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,66,',0,0
	.dd LM43-_Playtemp
	.dw 0x0d,0x0a
.code
LM43:
LBB3:
	R2=[bp+2]	// QImode move
	R1=[R2]	// QImode move
	R2=10	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __divu1	// call with return value
	SP = SP + 2	//SP
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,67,',0,0
	.dd LM44-_Playtemp
	.dw 0x0d,0x0a
.code
LM44:
	R1=BP	// QImode move
	R3=BP+1
	[bp+3]=R3	// QImode move
	R2=[bp+2]	// QImode move
	R1=[R2]	// QImode move
	R2=10	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __modu1	// call with return value
	SP = SP + 2	//SP
	R3=[bp+3]	// QImode move
	[R3]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,68,',0,0
	.dd LM45-_Playtemp
	.dw 0x0d,0x0a
.code
LM45:
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	R1=12	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd_Auto	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,69,',0,0
	.dd LM46-_Playtemp
	.dw 0x0d,0x0a
.code
LM46:
	R2=[bp+2]	// QImode move
	R1=[R2]	// QImode move
	CMP R1,9	// QImode compare
	NSJA L24	//QImode GTU
.debug
	.dw '.stabn 0x44,0,71,',0,0
	.dd LM47-_Playtemp
	.dw 0x0d,0x0a
.code
LM47:
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	R3=[bp+2]	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd_Auto	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,72,',0,0
	.dd LM48-_Playtemp
	.dw 0x0d,0x0a
.code
LM48:
	pc=L25	// Indirect jump
L24:
.debug
	.dw '.stabn 0x44,0,73,',0,0
	.dd LM49-_Playtemp
	.dw 0x0d,0x0a
.code
LM49:
	R1=BP	// QImode move
	R2=BP+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	CMP R1,0	// QImode test
	NSJNZ L26	//QImode NE
.debug
	.dw '.stabn 0x44,0,75,',0,0
	.dd LM50-_Playtemp
	.dw 0x0d,0x0a
.code
LM50:
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	R1=[BP]	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd_Auto	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,76,',0,0
	.dd LM51-_Playtemp
	.dw 0x0d,0x0a
.code
LM51:
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	R1=10	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd_Auto	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,77,',0,0
	.dd LM52-_Playtemp
	.dw 0x0d,0x0a
.code
LM52:
	pc=L25	// Indirect jump
L26:
.debug
	.dw '.stabn 0x44,0,80,',0,0
	.dd LM53-_Playtemp
	.dw 0x0d,0x0a
.code
LM53:
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	R1=[BP]	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd_Auto	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,81,',0,0
	.dd LM54-_Playtemp
	.dw 0x0d,0x0a
.code
LM54:
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	R1=10	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd_Auto	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,82,',0,0
	.dd LM55-_Playtemp
	.dw 0x0d,0x0a
.code
LM55:
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	R1=BP	// QImode move
	R2=BP+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd_Auto	// call without return value
	SP = SP + 2	//SP
L27:
L25:
.debug
	.dw '.stabn 0x44,0,84,',0,0
	.dd LM56-_Playtemp
	.dw 0x0d,0x0a
.code
LM56:
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	R1=13	// QImode move
	[SP--]=R1	// QImode move
	call _PlaySnd_Auto	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,86,',0,0
	.dd LM57-_Playtemp
	.dw 0x0d,0x0a
.code
LM57:
LBE3:
.debug
	.dw '.stabn 0x44,0,86,',0,0
	.dd LM58-_Playtemp
	.dw 0x0d,0x0a
.code
LM58:
L23:

	sp+=4
	pop bp from [sp]
	retf
	.endp	// end of Playtemp

.debug
	.dw '.stabs "temperature:p11",160,0,0,7',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB3-_Playtemp
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "htemp:11",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "ltemp:11",128,0,0,1',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE3-_Playtemp
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME3-_Playtemp
	.dw 0x0d,0x0a
.code
LME3:
.external _SACM_S480_Stop
.external _SACM_S480_ServiceLoop
.external _SACM_S480_Status
.external _SACM_S480_Play
.external _SACM_S480_Initial
.external __modu1
.external __divu1
	.end

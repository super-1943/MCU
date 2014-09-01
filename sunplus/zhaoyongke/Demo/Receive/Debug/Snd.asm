// GCC for SUNPLUS u'nSP version 1.0.21-3
// Command: C:\PROGRA~1\Sunplus\UNSPID~1.0\cc1.exe C:\DOCUME~1\ADMINI~1\LOCALS~1\Temp\ccY5aaaa.i -fkeep-inline-functions -quiet -dumpbase Snd.c -mglobal-var-iram -gstabs -Wall -o .\Debug/Snd.asm
	.external __sn_func_ptr_sec

// gcc2_compiled.:

.debug
	.dw '.stabs "E:/zhaoyongke/Demo/Receive/",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
.code
.debug
	.dw '.stabs "E:/zhaoyongke/Demo/Receive/Snd.c",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
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
	.dw '.stabs "PlaySnd:F19",36,0,0,',0,0,offset _PlaySnd,seg _PlaySnd,0x0d,0x0a
.CODE
.public _PlaySnd
_PlaySnd:	.proc
.debug
	.dw '.stabn 0x44,0,8,',0,0
	.dd LM1-_PlaySnd
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
	.dw '.stabn 0x44,0,9,',0,0
	.dd LM2-_PlaySnd
	.dw 0x0d,0x0a
.code
LM2:
	call _SACM_A1600_Initial	// call without return value
.debug
	.dw '.stabn 0x44,0,10,',0,0
	.dd LM3-_PlaySnd
	.dw 0x0d,0x0a
.code
LM3:
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	R2=[BP]	// QImode move
	R1=[R2]	// QImode move
	[SP--]=R1	// QImode move
	call _SACM_A1600_Play	// call without return value
	SP = SP + 3	//SP
.debug
	.dw '.stabn 0x44,0,12,',0,0
	.dd LM4-_PlaySnd
	.dw 0x0d,0x0a
.code
LM4:
L3:
	call _SACM_A1600_Status	// call with return value
	R2=R1&1
	CMP R2,0	// QImode test
	NSJNZ L5	//QImode NE
	pc=L4	// Indirect jump
L5:
.debug
	.dw '.stabn 0x44,0,14,',0,0
	.dd LM5-_PlaySnd
	.dw 0x0d,0x0a
.code
LM5:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,15,',0,0
	.dd LM6-_PlaySnd
	.dw 0x0d,0x0a
.code
LM6:
	call _SACM_A1600_ServiceLoop	// call without return value
.debug
	.dw '.stabn 0x44,0,16,',0,0
	.dd LM7-_PlaySnd
	.dw 0x0d,0x0a
.code
LM7:
	pc=L3	// Indirect jump
L4:
.debug
	.dw '.stabn 0x44,0,17,',0,0
	.dd LM8-_PlaySnd
	.dw 0x0d,0x0a
.code
LM8:
.debug
	.dw '.stabn 0x44,0,17,',0,0
	.dd LM9-_PlaySnd
	.dw 0x0d,0x0a
.code
LM9:
L2:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of PlaySnd

.debug
	.dw '.stabs "SndIdx:p4",160,0,0,4',0x0d,0x0a
.CODE
.debug
	.dw '.stabf ',0,0
	.dd LME1-_PlaySnd
	.dw 0x0d,0x0a
.code
LME1:
// ISR ATTRIBUTE FUNCTION, LOCATE in .text SECTION
.text
.debug
	.dw '.stabs "FIQ:F19",36,0,0,',0,0,offset _FIQ,seg _FIQ,0x0d,0x0a
.TEXT
.public _FIQ
_FIQ:	.proc
.debug
	.dw '.stabn 0x44,0,25,',0,0
	.dd LM10-_FIQ
	.dw 0x0d,0x0a
.text
LM10:
	// ISR ATTRIBUTE FUNCTION, PUSH r1,bp
	push r1,bp to [sp]

	// total=1, vars=1
	// frame_pointer_needed: 1
	sp-=1
	bp=sp+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,26,',0,0
	.dd LM11-_FIQ
	.dw 0x0d,0x0a
.text
LM11:
	R1=8192	// QImode move
	[28689]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,27,',0,0
	.dd LM12-_FIQ
	.dw 0x0d,0x0a
.text
LM12:
	call _SACM_A1600_ISR	// call without return value
.debug
	.dw '.stabn 0x44,0,28,',0,0
	.dd LM13-_FIQ
	.dw 0x0d,0x0a
.text
LM13:
.debug
	.dw '.stabn 0x44,0,28,',0,0
	.dd LM14-_FIQ
	.dw 0x0d,0x0a
.text
LM14:
L7:

	sp+=1
	// ISR ATTRIBUTE FUNCTION, POP r1,bp
	pop r1,bp from [sp]
	reti
	.endp	// end of FIQ

.debug
	.dw '.stabf ',0,0
	.dd LME2-_FIQ
	.dw 0x0d,0x0a
.text
LME2:
.external _SACM_A1600_ISR
.external _SACM_A1600_ServiceLoop
.external _SACM_A1600_Status
.external _SACM_A1600_Play
.external _SACM_A1600_Initial
	.end

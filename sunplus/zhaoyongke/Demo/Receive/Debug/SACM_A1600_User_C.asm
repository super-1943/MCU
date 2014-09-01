// GCC for SUNPLUS u'nSP version 1.0.21-3
// Command: C:\PROGRA~1\Sunplus\UNSPID~1.0\cc1.exe C:\DOCUME~1\ADMINI~1\LOCALS~1\Temp\ccaeaaaa.i -fkeep-inline-functions -quiet -dumpbase SACM_A1600_User_C.c -mglobal-var-iram -gstabs -Wall -o .\Debug/SACM_A1600_User_C.asm
	.external __sn_func_ptr_sec

// gcc2_compiled.:

.debug
	.dw '.stabs "E:/zhaoyongke/Demo/Receive/",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
.code
.debug
	.dw '.stabs "E:/zhaoyongke/Demo/Receive/SACM_A1600_User_C.c",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
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
	.dw '.stabs "ResAddr:G4",32,0,0,',0,0,offset _ResAddr,seg _ResAddr,0x0d,0x0a
.CODE
.code
.debug
	.dw '.stabs "USER_A1600_GetResource_Init:F19",36,0,0,',0,0,offset _USER_A1600_GetResource_Init,seg _USER_A1600_GetResource_Init,0x0d,0x0a
.CODE
.public _USER_A1600_GetResource_Init
_USER_A1600_GetResource_Init:	.proc
.debug
	.dw '.stabn 0x44,0,28,',0,0
	.dd LM1-_USER_A1600_GetResource_Init
	.dw 0x0d,0x0a
.code
LM1:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
.debug
	.dw '.stabn 0x44,0,29,',0,0
	.dd LM2-_USER_A1600_GetResource_Init
	.dw 0x0d,0x0a
.code
LM2:
LBB2:
.debug
	.dw '.stabn 0x44,0,30,',0,0
	.dd LM3-_USER_A1600_GetResource_Init
	.dw 0x0d,0x0a
.code
LM3:
	R2=R1	// QImode move
	R3=[R2]	// QImode move
	R2=R3	// QImode move
	R2=R2+_SACM_A1600_SpeechTable
	R4=R2	// QImode move
	R3=[R4]	// QImode move
	[BP]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,31,',0,0
	.dd LM4-_USER_A1600_GetResource_Init
	.dw 0x0d,0x0a
.code
LM4:
	R2=[BP]	// QImode move
	R4=R2	// QImode move
	R3=[R4]	// QImode move
	[_ResAddr]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,32,',0,0
	.dd LM5-_USER_A1600_GetResource_Init
	.dw 0x0d,0x0a
.code
LM5:
LBE2:
.debug
	.dw '.stabn 0x44,0,32,',0,0
	.dd LM6-_USER_A1600_GetResource_Init
	.dw 0x0d,0x0a
.code
LM6:
L2:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of USER_A1600_GetResource_Init

.debug
	.dw '.stabs "SoundIndex:p4",160,0,0,4',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB2-_USER_A1600_GetResource_Init
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "p_Addr:20=*4",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE2-_USER_A1600_GetResource_Init
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME1-_USER_A1600_GetResource_Init
	.dw 0x0d,0x0a
.code
LME1:
.code
.debug
	.dw '.stabs "USER_A1600_GetResource:F19",36,0,0,',0,0,offset _USER_A1600_GetResource,seg _USER_A1600_GetResource,0x0d,0x0a
.CODE
.public _USER_A1600_GetResource
_USER_A1600_GetResource:	.proc
.debug
	.dw '.stabn 0x44,0,42,',0,0
	.dd LM7-_USER_A1600_GetResource
	.dw 0x0d,0x0a
.code
LM7:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
.debug
	.dw '.stabn 0x44,0,43,',0,0
	.dd LM8-_USER_A1600_GetResource
	.dw 0x0d,0x0a
.code
LM8:
L4:
	R2=R1	// QImode move
	R3=R1+1
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	CMP R2,0	// QImode test
	NSJNZ L6	//QImode NE
	pc=L5	// Indirect jump
L6:
.debug
	.dw '.stabn 0x44,0,45,',0,0
	.dd LM9-_USER_A1600_GetResource
	.dw 0x0d,0x0a
.code
LM9:
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	R3=[_ResAddr]	// QImode move
	R4=R3	// QImode move
	R4=[R4]	// QImode move
	[BP]=R4	// QImode move
	R3=[BP]	// QImode move
	R4=R2	// QImode move
	[R4]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,46,',0,0
	.dd LM10-_USER_A1600_GetResource
	.dw 0x0d,0x0a
.code
LM10:
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	R3=R2+1
	R4=R1	// QImode move
	[R4]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,47,',0,0
	.dd LM11-_USER_A1600_GetResource
	.dw 0x0d,0x0a
.code
LM11:
	R2=[_ResAddr]	// QImode move
	R3=1	// QImode move
	[_ResAddr]=R2+R3  //addqi3_Qrr
.debug
	.dw '.stabn 0x44,0,48,',0,0
	.dd LM12-_USER_A1600_GetResource
	.dw 0x0d,0x0a
.code
LM12:
	R2=R1	// QImode move
	R3=R1+1
	R4=R1	// QImode move
	R2=R1+1
	R3=R1	// QImode move
	R3=R1+1
	[BP]=R3	// QImode move
	R4=[BP]	// QImode move
	R3=[R4]	// QImode move
	R4=R3+(-1)
	R3=R2	// QImode move
	[R3]=R4	// QImode move
.debug
	.dw '.stabn 0x44,0,49,',0,0
	.dd LM13-_USER_A1600_GetResource
	.dw 0x0d,0x0a
.code
LM13:
	pc=L4	// Indirect jump
L5:
.debug
	.dw '.stabn 0x44,0,50,',0,0
	.dd LM14-_USER_A1600_GetResource
	.dw 0x0d,0x0a
.code
LM14:
.debug
	.dw '.stabn 0x44,0,50,',0,0
	.dd LM15-_USER_A1600_GetResource
	.dw 0x0d,0x0a
.code
LM15:
L3:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of USER_A1600_GetResource

.debug
	.dw '.stabs "p_Buf:p20",160,0,0,4',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "Words:p4",160,0,0,5',0x0d,0x0a
.CODE
.debug
	.dw '.stabf ',0,0
	.dd LME2-_USER_A1600_GetResource
	.dw 0x0d,0x0a
.code
LME2:
.iram
.public _ResAddr
_ResAddr:
	.dw 0
.external _SACM_A1600_SpeechTable
	.end

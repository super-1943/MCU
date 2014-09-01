// GCC for SUNPLUS u'nSP version 1.0.23
// Command: C:\PROGRA~1\Sunplus\UNSPID~1.2D\toolchain\cc1.exe C:\DOCUME~1\ADMINI~1\LOCALS~1\Temp\ccW8aaaa.i -fkeep-inline-functions -quiet -dumpbase main.c -mglobal-var-iram -gstabs -Wall -o .\Debug/main.asm
	.external __sn_func_ptr_sec

// gcc2_compiled.:

.debug
	.dw '.stabs "E:/kkk  yuyinshibie/",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
.code
.debug
	.dw '.stabs "E:/kkk  yuyinshibie/main.c",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
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
	.dw '.stabs "Delay:F19",36,0,0,',0,0,offset _Delay,seg _Delay,0x0d,0x0a
.CODE
.public _Delay
_Delay:	.proc
.debug
	.dw '.stabn 0x44,0,67,',0,0
	.dd LM1-_Delay
	.dw 0x0d,0x0a
.code
LM1:
	// total=1, vars=1
	// frame_pointer_needed: 1
.debug
	.dw '.stabn 0xa6,0,0,1',0x0d, 0x0a
.code
	PUSH BP to [SP]
	SP-=1
	BP=SP+1

	R1=BP+4
LBB2:
.debug
	.dw '.stabn 0x44,0,69,',0,0
	.dd LM2-_Delay
	.dw 0x0d,0x0a
.code
LM2:
	R2=0	// QImode move
	[BP]=R2	// QImode move
L3:
	R2=[BP]	// QImode move
	CMP R2,16382	// QImode compare
	NSJNA L6	//QImode LEU
	PC=L4	// jump
L6:
.debug
	.dw '.stabn 0x44,0,71,',0,0
	.dd LM3-_Delay
	.dw 0x0d,0x0a
.code
LM3:
	R2=1	// QImode move
	[28690]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,69,',0,0
	.dd LM4-_Delay
	.dw 0x0d,0x0a
.code
LM4:
L5:
	R2=[BP]	// QImode move
	R3=R2+1
	[BP]=R3	// QImode move
	PC=L3	// jump
L4:
.debug
	.dw '.stabn 0x44,0,73,',0,0
	.dd LM5-_Delay
	.dw 0x0d,0x0a
.code
LM5:
LBE2:
.debug
	.dw '.stabn 0x44,0,73,',0,0
	.dd LM6-_Delay
	.dw 0x0d,0x0a
.code
LM6:
L2:

	SP+=1
	POP BP from [SP]
	RETF
	.endp	// end of Delay

.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB2-_Delay
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "i:4",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE2-_Delay
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME1-_Delay
	.dw 0x0d,0x0a
.code
LME1:
.code
.debug
	.dw '.stabs "PlaySnd:F19",36,0,0,',0,0,offset _PlaySnd,seg _PlaySnd,0x0d,0x0a
.CODE
.public _PlaySnd
_PlaySnd:	.proc
.debug
	.dw '.stabn 0x44,0,83,',0,0
	.dd LM7-_PlaySnd
	.dw 0x0d,0x0a
.code
LM7:
	// total=1, vars=1
	// frame_pointer_needed: 1
.debug
	.dw '.stabn 0xa6,0,0,1',0x0d, 0x0a
.code
	PUSH BP to [SP]
	SP-=1
	BP=SP+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,84,',0,0
	.dd LM8-_PlaySnd
	.dw 0x0d,0x0a
.code
LM8:
	CALL _BSR_StopRecognizer	// call without return value
.debug
	.dw '.stabn 0x44,0,85,',0,0
	.dd LM9-_PlaySnd
	.dw 0x0d,0x0a
.code
LM9:
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	CALL _SACM_S480_Initial	// call with return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,86,',0,0
	.dd LM10-_PlaySnd
	.dw 0x0d,0x0a
.code
LM10:
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
	CALL _SACM_S480_Play	// call with return value
	SP = SP + 3	//SP
.debug
	.dw '.stabn 0x44,0,87,',0,0
	.dd LM11-_PlaySnd
	.dw 0x0d,0x0a
.code
LM11:
L9:
	CALL _SACM_S480_Status	// call with return value
	R2=R1&1
	CMP R2,0	// QImode test
	NSJNZ L11	//QImode NE
	PC=L10	// jump
L11:
.debug
	.dw '.stabn 0x44,0,89,',0,0
	.dd LM12-_PlaySnd
	.dw 0x0d,0x0a
.code
LM12:
	CALL _SACM_S480_ServiceLoop	// call with return value
.debug
	.dw '.stabn 0x44,0,90,',0,0
	.dd LM13-_PlaySnd
	.dw 0x0d,0x0a
.code
LM13:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,91,',0,0
	.dd LM14-_PlaySnd
	.dw 0x0d,0x0a
.code
LM14:
	PC=L9	// jump
L10:
.debug
	.dw '.stabn 0x44,0,92,',0,0
	.dd LM15-_PlaySnd
	.dw 0x0d,0x0a
.code
LM15:
	CALL _SACM_S480_Stop	// call with return value
.debug
	.dw '.stabn 0x44,0,93,',0,0
	.dd LM16-_PlaySnd
	.dw 0x0d,0x0a
.code
LM16:
	R1=0	// QImode move
	[SP--]=R1	// QImode move
	CALL _BSR_InitRecognizer	// call with return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,94,',0,0
	.dd LM17-_PlaySnd
	.dw 0x0d,0x0a
.code
LM17:
.debug
	.dw '.stabn 0x44,0,94,',0,0
	.dd LM18-_PlaySnd
	.dw 0x0d,0x0a
.code
LM18:
L8:

	SP+=1
	POP BP from [SP]
	RETF
	.endp	// end of PlaySnd

.debug
	.dw '.stabs "SndIndex:p4",160,0,0,4',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "DAC_Channel:p4",160,0,0,5',0x0d,0x0a
.CODE
.debug
	.dw '.stabf ',0,0
	.dd LME2-_PlaySnd
	.dw 0x0d,0x0a
.code
LME2:
.code
.debug
	.dw '.stabs "TrainWord:F1",36,0,0,',0,0,offset _TrainWord,seg _TrainWord,0x0d,0x0a
.CODE
.public _TrainWord
_TrainWord:	.proc
.debug
	.dw '.stabn 0x44,0,104,',0,0
	.dd LM19-_TrainWord
	.dw 0x0d,0x0a
.code
LM19:
	// total=2, vars=2
	// frame_pointer_needed: 1
.debug
	.dw '.stabn 0xa6,0,0,2',0x0d, 0x0a
.code
	PUSH BP to [SP]
	SP-=2
	BP=SP+1

	R1=BP+5
	[BP+1]=R1	// QImode move
LBB3:
.debug
	.dw '.stabn 0x44,0,106,',0,0
	.dd LM20-_TrainWord
	.dw 0x0d,0x0a
.code
LM20:
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	R1=[BP+1]	// QImode move
	R3=[BP+1]	// QImode move
	R2=R3+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	CALL _PlaySnd	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,107,',0,0
	.dd LM21-_TrainWord
	.dw 0x0d,0x0a
.code
LM21:
L14:
	PC=L16	// jump
	PC=L15	// jump
L16:
.debug
	.dw '.stabn 0x44,0,109,',0,0
	.dd LM22-_TrainWord
	.dw 0x0d,0x0a
.code
LM22:
	R1=0	// QImode move
	[SP--]=R1	// QImode move
	R2=[BP+1]	// QImode move
	R1=[R2]	// QImode move
	[SP--]=R1	// QImode move
	CALL _BSR_Train	// call with return value
	SP = SP + 2	//SP
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,111,',0,0
	.dd LM23-_TrainWord
	.dw 0x0d,0x0a
.code
LM23:
	R1=[BP]	// QImode move
	CMP R1,0	// QImode test
	NSJNZ L17	//QImode NE
	PC=L15	// jump
L17:
.debug
	.dw '.stabn 0x44,0,112,',0,0
	.dd LM24-_TrainWord
	.dw 0x0d,0x0a
.code
LM24:
	R2=[BP]	// QImode move
	R1=R2	// QImode move
	R1=R1-(-6)
	CMP R1,5	// QImode compare
	NSJA L25	//QImode GTU
	R2=L26	// QImode move
	R1 = R1 + R2	//addqi3
	R3=R1	// QImode move
	R1=[R3]	// QImode move
	PC=R1	// tablejump
.text
L26:
	.dw L24
	.dw L23
	.dw L22
	.dw L21
	.dw L20
	.dw L19
.code
L19:
.debug
	.dw '.stabn 0x44,0,115,',0,0
	.dd LM25-_TrainWord
	.dw 0x0d,0x0a
.code
LM25:
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	R1=7	// QImode move
	[SP--]=R1	// QImode move
	CALL _PlaySnd	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,116,',0,0
	.dd LM26-_TrainWord
	.dw 0x0d,0x0a
.code
LM26:
	R1=(-1)	// QImode move
	PC=L13	// jump
L20:
.debug
	.dw '.stabn 0x44,0,118,',0,0
	.dd LM27-_TrainWord
	.dw 0x0d,0x0a
.code
LM27:
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	R1=6	// QImode move
	[SP--]=R1	// QImode move
	CALL _PlaySnd	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,119,',0,0
	.dd LM28-_TrainWord
	.dw 0x0d,0x0a
.code
LM28:
	PC=L18	// jump
L21:
.debug
	.dw '.stabn 0x44,0,121,',0,0
	.dd LM29-_TrainWord
	.dw 0x0d,0x0a
.code
LM29:
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	R1=8	// QImode move
	[SP--]=R1	// QImode move
	CALL _PlaySnd	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,122,',0,0
	.dd LM30-_TrainWord
	.dw 0x0d,0x0a
.code
LM30:
	R1=(-3)	// QImode move
	PC=L13	// jump
L22:
.debug
	.dw '.stabn 0x44,0,124,',0,0
	.dd LM31-_TrainWord
	.dw 0x0d,0x0a
.code
LM31:
	R1=(-4)	// QImode move
	PC=L13	// jump
L23:
.debug
	.dw '.stabn 0x44,0,126,',0,0
	.dd LM32-_TrainWord
	.dw 0x0d,0x0a
.code
LM32:
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	R1=8	// QImode move
	[SP--]=R1	// QImode move
	CALL _PlaySnd	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,127,',0,0
	.dd LM33-_TrainWord
	.dw 0x0d,0x0a
.code
LM33:
	R1=(-5)	// QImode move
	PC=L13	// jump
L24:
.debug
	.dw '.stabn 0x44,0,129,',0,0
	.dd LM34-_TrainWord
	.dw 0x0d,0x0a
.code
LM34:
	R1=(-6)	// QImode move
	PC=L13	// jump
L25:
.debug
	.dw '.stabn 0x44,0,131,',0,0
	.dd LM35-_TrainWord
	.dw 0x0d,0x0a
.code
LM35:
	PC=L18	// jump
L18:
.debug
	.dw '.stabn 0x44,0,133,',0,0
	.dd LM36-_TrainWord
	.dw 0x0d,0x0a
.code
LM36:
	PC=L14	// jump
L15:
.debug
	.dw '.stabn 0x44,0,134,',0,0
	.dd LM37-_TrainWord
	.dw 0x0d,0x0a
.code
LM37:
	R1=0	// QImode move
	PC=L13	// jump
.debug
	.dw '.stabn 0x44,0,135,',0,0
	.dd LM38-_TrainWord
	.dw 0x0d,0x0a
.code
LM38:
LBE3:
.debug
	.dw '.stabn 0x44,0,135,',0,0
	.dd LM39-_TrainWord
	.dw 0x0d,0x0a
.code
LM39:
L13:

	SP+=2
	POP BP from [SP]
	RETF
	.endp	// end of TrainWord

.debug
	.dw '.stabs "WordID:p4",160,0,0,5',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "SndID:p4",160,0,0,6',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB3-_TrainWord
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "Result:1",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE3-_TrainWord
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME3-_TrainWord
	.dw 0x0d,0x0a
.code
LME3:
.code
.debug
	.dw '.stabs "TrainSD:F19",36,0,0,',0,0,offset _TrainSD,seg _TrainSD,0x0d,0x0a
.CODE
.public _TrainSD
_TrainSD:	.proc
.debug
	.dw '.stabn 0x44,0,144,',0,0
	.dd LM40-_TrainSD
	.dw 0x0d,0x0a
.code
LM40:
	// total=1, vars=1
	// frame_pointer_needed: 1
.debug
	.dw '.stabn 0xa6,0,0,1',0x0d, 0x0a
.code
	PUSH BP to [SP]
	SP-=1
	BP=SP+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,145,',0,0
	.dd LM41-_TrainSD
	.dw 0x0d,0x0a
.code
LM41:
L30:
	R1=0	// QImode move
	[SP--]=R1	// QImode move
	R1=256	// QImode move
	[SP--]=R1	// QImode move
	CALL _TrainWord	// call with return value
	SP = SP + 2	//SP
	CMP R1,0	// QImode test
	NSJNZ L32	//QImode NE
	PC=L31	// jump
L32:
	PC=L30	// jump
L31:
.debug
	.dw '.stabn 0x44,0,146,',0,0
	.dd LM42-_TrainSD
	.dw 0x0d,0x0a
.code
LM42:
L33:
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	R1=257	// QImode move
	[SP--]=R1	// QImode move
	CALL _TrainWord	// call with return value
	SP = SP + 2	//SP
	CMP R1,0	// QImode test
	NSJNZ L35	//QImode NE
	PC=L34	// jump
L35:
	PC=L33	// jump
L34:
.debug
	.dw '.stabn 0x44,0,150,',0,0
	.dd LM43-_TrainSD
	.dw 0x0d,0x0a
.code
LM43:
.debug
	.dw '.stabn 0x44,0,150,',0,0
	.dd LM44-_TrainSD
	.dw 0x0d,0x0a
.code
LM44:
L29:

	SP+=1
	POP BP from [SP]
	RETF
	.endp	// end of TrainSD

.debug
	.dw '.stabf ',0,0
	.dd LME4-_TrainSD
	.dw 0x0d,0x0a
.code
LME4:
.code
.debug
	.dw '.stabs "StoreSD:F19",36,0,0,',0,0,offset _StoreSD,seg _StoreSD,0x0d,0x0a
.CODE
.public _StoreSD
_StoreSD:	.proc
.debug
	.dw '.stabn 0x44,0,159,',0,0
	.dd LM45-_StoreSD
	.dw 0x0d,0x0a
.code
LM45:
	// total=7, vars=7
	// frame_pointer_needed: 1
.debug
	.dw '.stabn 0xa6,0,0,7',0x0d, 0x0a
.code
	PUSH BP to [SP]
	SP-=7
	BP=SP+1

	R1=BP+10
	[BP+4]=R1	// QImode move
LBB4:
.debug
	.dw '.stabn 0x44,0,160,',0,0
	.dd LM46-_StoreSD
	.dw 0x0d,0x0a
.code
LM46:
	R1=(-8192)	// QImode move
	[SP--]=R1	// QImode move
	CALL _F_FlashErase	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,161,',0,0
	.dd LM47-_StoreSD
	.dw 0x0d,0x0a
.code
LM47:
	R1=(-7936)	// QImode move
	[SP--]=R1	// QImode move
	CALL _F_FlashErase	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,162,',0,0
	.dd LM48-_StoreSD
	.dw 0x0d,0x0a
.code
LM48:
	R1=(-8192)	// QImode move
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,163,',0,0
	.dd LM49-_StoreSD
	.dw 0x0d,0x0a
.code
LM49:
	R1=BP	// QImode move
	R2=BP+2
	R1=256	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
L39:
	R1=BP	// QImode move
	R2=BP+2
	R4=R2	// QImode move
	R1=[R4]	// QImode move
	CMP R1,257	// QImode compare
	NSJNA L42	//QImode LEU
	PC=L40	// jump
L42:
.debug
	.dw '.stabn 0x44,0,165,',0,0
	.dd LM50-_StoreSD
	.dw 0x0d,0x0a
.code
LM50:
	R1=BP	// QImode move
	R1=BP+3
	[BP+5]=R1	// QImode move
	R1=BP	// QImode move
	R2=BP+2
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	CALL _BSR_ExportSDWord	// call with return value
	SP = SP + 1	//SP
	R4=[BP+5]	// QImode move
	[R4]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,166,',0,0
	.dd LM51-_StoreSD
	.dw 0x0d,0x0a
.code
LM51:
L43:
	R1=BP	// QImode move
	R2=BP+3
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	CMP R1,0	// QImode test
	NSJNZ L45	//QImode NE
	PC=L44	// jump
L45:
.debug
	.dw '.stabn 0x44,0,167,',0,0
	.dd LM52-_StoreSD
	.dw 0x0d,0x0a
.code
LM52:
	R1=BP	// QImode move
	R4=BP+3
	[BP+6]=R4	// QImode move
	R1=BP	// QImode move
	R2=BP+2
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	CALL _BSR_ExportSDWord	// call with return value
	SP = SP + 1	//SP
	R4=[BP+6]	// QImode move
	[R4]=R1	// QImode move
	PC=L43	// jump
L44:
.debug
	.dw '.stabn 0x44,0,168,',0,0
	.dd LM53-_StoreSD
	.dw 0x0d,0x0a
.code
LM53:
	R1=BP	// QImode move
	R2=BP+1
	R1=0	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
L46:
	R1=BP	// QImode move
	R2=BP+1
	R4=R2	// QImode move
	R1=[R4]	// QImode move
	CMP R1,99	// QImode compare
	NSJNA L49	//QImode LEU
	PC=L41	// jump
L49:
.debug
	.dw '.stabn 0x44,0,170,',0,0
	.dd LM54-_StoreSD
	.dw 0x0d,0x0a
.code
LM54:
	R1=BP	// QImode move
	R2=BP+1
	R1=R2	// QImode move
	R3=[R1]
	R4=0
	R1=_BSR_SDModel	// QImode move
	R2=R3	// QImode move
	R1 = R1 + R2	//addqi3
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	[SP--]=R2	// QImode move
	R1=[BP]	// QImode move
	[SP--]=R1	// QImode move
	CALL _F_FlashWrite1Word	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,171,',0,0
	.dd LM55-_StoreSD
	.dw 0x0d,0x0a
.code
LM55:
	R1=[BP]	// QImode move
	R2=R1+1
	[BP]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,168,',0,0
	.dd LM56-_StoreSD
	.dw 0x0d,0x0a
.code
LM56:
L48:
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
	PC=L46	// jump
L47:
.debug
	.dw '.stabn 0x44,0,163,',0,0
	.dd LM57-_StoreSD
	.dw 0x0d,0x0a
.code
LM57:
L41:
	R1=BP	// QImode move
	R2=BP+2
	R3=BP	// QImode move
	R1=BP+2
	R2=BP	// QImode move
	R3=BP+2
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R3=R2+1
	R2=R1	// QImode move
	[R2]=R3	// QImode move
	PC=L39	// jump
L40:
.debug
	.dw '.stabn 0x44,0,174,',0,0
	.dd LM58-_StoreSD
	.dw 0x0d,0x0a
.code
LM58:
LBE4:
.debug
	.dw '.stabn 0x44,0,174,',0,0
	.dd LM59-_StoreSD
	.dw 0x0d,0x0a
.code
LM59:
L38:

	SP+=7
	POP BP from [SP]
	RETF
	.endp	// end of StoreSD

.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB4-_StoreSD
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "ulAddr:4",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "i:4",128,0,0,1',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "commandID:4",128,0,0,2',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "g_Ret:4",128,0,0,3',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE4-_StoreSD
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME5-_StoreSD
	.dw 0x0d,0x0a
.code
LME5:
.code
.debug
	.dw '.stabs "LoadSD:F19",36,0,0,',0,0,offset _LoadSD,seg _LoadSD,0x0d,0x0a
.CODE
.public _LoadSD
_LoadSD:	.proc
.debug
	.dw '.stabn 0x44,0,183,',0,0
	.dd LM60-_LoadSD
	.dw 0x0d,0x0a
.code
LM60:
	// total=8, vars=8
	// frame_pointer_needed: 1
.debug
	.dw '.stabn 0xa6,0,0,8',0x0d, 0x0a
.code
	PUSH BP to [SP]
	SP-=8
	BP=SP+1

	R1=BP+11
	[BP+5]=R1	// QImode move
LBB5:
.debug
	.dw '.stabn 0x44,0,184,',0,0
	.dd LM61-_LoadSD
	.dw 0x0d,0x0a
.code
LM61:
	R1=(-8192)	// QImode move
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,185,',0,0
	.dd LM62-_LoadSD
	.dw 0x0d,0x0a
.code
LM62:
	R1=BP	// QImode move
	R2=BP+2
	R1=0	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
L54:
	R1=BP	// QImode move
	R2=BP+2
	R4=R2	// QImode move
	R1=[R4]	// QImode move
	CMP R1,1	// QImode compare
	NSJNA L57	//QImode LEU
	PC=L55	// jump
L57:
.debug
	.dw '.stabn 0x44,0,187,',0,0
	.dd LM63-_LoadSD
	.dw 0x0d,0x0a
.code
LM63:
	R1=BP	// QImode move
	R2=BP+1
	R1=0	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
L58:
	R1=BP	// QImode move
	R2=BP+1
	R4=R2	// QImode move
	R1=[R4]	// QImode move
	CMP R1,99	// QImode compare
	NSJNA L61	//QImode LEU
	PC=L59	// jump
L61:
.debug
	.dw '.stabn 0x44,0,189,',0,0
	.dd LM64-_LoadSD
	.dw 0x0d,0x0a
.code
LM64:
	R2=BP	// QImode move
	R1=BP+3
	R2=[BP]	// QImode move
	R4=R2	// QImode move
	R3=[R4]	// QImode move
	R2=R1	// QImode move
	[R2]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,190,',0,0
	.dd LM65-_LoadSD
	.dw 0x0d,0x0a
.code
LM65:
	R1=BP	// QImode move
	R2=BP+1
	R1=R2	// QImode move
	R3=[R1]
	R4=0
	R1=_BSR_SDModel	// QImode move
	R2=R3	// QImode move
	R1 = R1 + R2	//addqi3
	R2=BP	// QImode move
	R3=BP+3
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R3=R1	// QImode move
	[R3]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,191,',0,0
	.dd LM66-_LoadSD
	.dw 0x0d,0x0a
.code
LM66:
	R1=[BP]	// QImode move
	R2=R1+1
	[BP]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,187,',0,0
	.dd LM67-_LoadSD
	.dw 0x0d,0x0a
.code
LM67:
L60:
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
	PC=L58	// jump
L59:
.debug
	.dw '.stabn 0x44,0,193,',0,0
	.dd LM68-_LoadSD
	.dw 0x0d,0x0a
.code
LM68:
	R1=BP	// QImode move
	R3=BP+4
	[BP+6]=R3	// QImode move
	CALL _BSR_ImportSDWord	// call with return value
	R4=[BP+6]	// QImode move
	[R4]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,194,',0,0
	.dd LM69-_LoadSD
	.dw 0x0d,0x0a
.code
LM69:
L62:
	R1=BP	// QImode move
	R2=BP+4
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	CMP R1,0	// QImode test
	NSJNZ L64	//QImode NE
	PC=L56	// jump
L64:
.debug
	.dw '.stabn 0x44,0,195,',0,0
	.dd LM70-_LoadSD
	.dw 0x0d,0x0a
.code
LM70:
	R1=BP	// QImode move
	R4=BP+4
	[BP+7]=R4	// QImode move
	CALL _BSR_ImportSDWord	// call with return value
	R2=[BP+7]	// QImode move
	[R2]=R1	// QImode move
	PC=L62	// jump
L63:
.debug
	.dw '.stabn 0x44,0,185,',0,0
	.dd LM71-_LoadSD
	.dw 0x0d,0x0a
.code
LM71:
L56:
	R1=BP	// QImode move
	R2=BP+2
	R3=BP	// QImode move
	R1=BP+2
	R2=BP	// QImode move
	R3=BP+2
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R3=R2+1
	R2=R1	// QImode move
	[R2]=R3	// QImode move
	PC=L54	// jump
L55:
.debug
	.dw '.stabn 0x44,0,197,',0,0
	.dd LM72-_LoadSD
	.dw 0x0d,0x0a
.code
LM72:
LBE5:
.debug
	.dw '.stabn 0x44,0,197,',0,0
	.dd LM73-_LoadSD
	.dw 0x0d,0x0a
.code
LM73:
L53:

	SP+=8
	POP BP from [SP]
	RETF
	.endp	// end of LoadSD

.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB5-_LoadSD
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "p:20=*4",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "k:4",128,0,0,1',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "jk:4",128,0,0,2',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "Ret:4",128,0,0,3',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "g_Ret:4",128,0,0,4',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE5-_LoadSD
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME6-_LoadSD
	.dw 0x0d,0x0a
.code
LME6:
.code
.debug
	.dw '.stabs "GoAhead:F19",36,0,0,',0,0,offset _GoAhead,seg _GoAhead,0x0d,0x0a
.CODE
.public _GoAhead
_GoAhead:	.proc
.debug
	.dw '.stabn 0x44,0,206,',0,0
	.dd LM74-_GoAhead
	.dw 0x0d,0x0a
.code
LM74:
	// total=2, vars=2
	// frame_pointer_needed: 1
.debug
	.dw '.stabn 0xa6,0,0,2',0x0d, 0x0a
.code
	PUSH BP to [SP]
	SP-=2
	BP=SP+1

	R1=BP+5
	[BP+1]=R1	// QImode move
LBB6:
.debug
	.dw '.stabn 0x44,0,208,',0,0
	.dd LM75-_GoAhead
	.dw 0x0d,0x0a
.code
LM75:
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	CALL _PlaySnd	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,209,',0,0
	.dd LM76-_GoAhead
	.dw 0x0d,0x0a
.code
LM76:
	R1=10240	// QImode move
	[28677]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,210,',0,0
	.dd LM77-_GoAhead
	.dw 0x0d,0x0a
.code
LM77:
	R1=0	// QImode move
	[BP]=R1	// QImode move
L69:
	R1=[BP]	// QImode move
	CMP R1,39	// QImode compare
	NSJNA L72	//QImode LEU
	PC=L70	// jump
L72:
.debug
	.dw '.stabn 0x44,0,211,',0,0
	.dd LM78-_GoAhead
	.dw 0x0d,0x0a
.code
LM78:
	CALL _Delay	// call without return value
.debug
	.dw '.stabn 0x44,0,210,',0,0
	.dd LM79-_GoAhead
	.dw 0x0d,0x0a
.code
LM79:
L71:
	R1=[BP]	// QImode move
	R2=R1+1
	[BP]=R2	// QImode move
	PC=L69	// jump
L70:
.debug
	.dw '.stabn 0x44,0,212,',0,0
	.dd LM80-_GoAhead
	.dw 0x0d,0x0a
.code
LM80:
	R1=0	// QImode move
	[28677]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,213,',0,0
	.dd LM81-_GoAhead
	.dw 0x0d,0x0a
.code
LM81:
LBE6:
.debug
	.dw '.stabn 0x44,0,213,',0,0
	.dd LM82-_GoAhead
	.dw 0x0d,0x0a
.code
LM82:
L68:

	SP+=2
	POP BP from [SP]
	RETF
	.endp	// end of GoAhead

.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB6-_GoAhead
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "j:4",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE6-_GoAhead
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME7-_GoAhead
	.dw 0x0d,0x0a
.code
LME7:
.code
.debug
	.dw '.stabs "BackUp:F19",36,0,0,',0,0,offset _BackUp,seg _BackUp,0x0d,0x0a
.CODE
.public _BackUp
_BackUp:	.proc
.debug
	.dw '.stabn 0x44,0,221,',0,0
	.dd LM83-_BackUp
	.dw 0x0d,0x0a
.code
LM83:
	// total=2, vars=2
	// frame_pointer_needed: 1
.debug
	.dw '.stabn 0xa6,0,0,2',0x0d, 0x0a
.code
	PUSH BP to [SP]
	SP-=2
	BP=SP+1

	R1=BP+5
	[BP+1]=R1	// QImode move
LBB7:
.debug
	.dw '.stabn 0x44,0,223,',0,0
	.dd LM84-_BackUp
	.dw 0x0d,0x0a
.code
LM84:
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	R1=2	// QImode move
	[SP--]=R1	// QImode move
	CALL _PlaySnd	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,224,',0,0
	.dd LM85-_BackUp
	.dw 0x0d,0x0a
.code
LM85:
	R1=5120	// QImode move
	[28677]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,225,',0,0
	.dd LM86-_BackUp
	.dw 0x0d,0x0a
.code
LM86:
	R1=0	// QImode move
	[BP]=R1	// QImode move
L75:
	R1=[BP]	// QImode move
	CMP R1,39	// QImode compare
	NSJNA L78	//QImode LEU
	PC=L76	// jump
L78:
.debug
	.dw '.stabn 0x44,0,226,',0,0
	.dd LM87-_BackUp
	.dw 0x0d,0x0a
.code
LM87:
	CALL _Delay	// call without return value
.debug
	.dw '.stabn 0x44,0,225,',0,0
	.dd LM88-_BackUp
	.dw 0x0d,0x0a
.code
LM88:
L77:
	R1=[BP]	// QImode move
	R2=R1+1
	[BP]=R2	// QImode move
	PC=L75	// jump
L76:
.debug
	.dw '.stabn 0x44,0,227,',0,0
	.dd LM89-_BackUp
	.dw 0x0d,0x0a
.code
LM89:
	R1=0	// QImode move
	[28677]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,228,',0,0
	.dd LM90-_BackUp
	.dw 0x0d,0x0a
.code
LM90:
LBE7:
.debug
	.dw '.stabn 0x44,0,228,',0,0
	.dd LM91-_BackUp
	.dw 0x0d,0x0a
.code
LM91:
L74:

	SP+=2
	POP BP from [SP]
	RETF
	.endp	// end of BackUp

.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB7-_BackUp
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "j:4",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE7-_BackUp
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME8-_BackUp
	.dw 0x0d,0x0a
.code
LME8:
.code
.debug
	.dw '.stabs "TurnLeft:F19",36,0,0,',0,0,offset _TurnLeft,seg _TurnLeft,0x0d,0x0a
.CODE
.public _TurnLeft
_TurnLeft:	.proc
.debug
	.dw '.stabn 0x44,0,237,',0,0
	.dd LM92-_TurnLeft
	.dw 0x0d,0x0a
.code
LM92:
	// total=2, vars=2
	// frame_pointer_needed: 1
.debug
	.dw '.stabn 0xa6,0,0,2',0x0d, 0x0a
.code
	PUSH BP to [SP]
	SP-=2
	BP=SP+1

	R1=BP+5
	[BP+1]=R1	// QImode move
LBB8:
.debug
	.dw '.stabn 0x44,0,239,',0,0
	.dd LM93-_TurnLeft
	.dw 0x0d,0x0a
.code
LM93:
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	R1=10	// QImode move
	[SP--]=R1	// QImode move
	CALL _PlaySnd	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,240,',0,0
	.dd LM94-_TurnLeft
	.dw 0x0d,0x0a
.code
LM94:
	R1=0	// QImode move
	[BP]=R1	// QImode move
L81:
	R1=[BP]	// QImode move
	CMP R1,29	// QImode compare
	NSJNA L84	//QImode LEU
	PC=L82	// jump
L84:
.debug
	.dw '.stabn 0x44,0,242,',0,0
	.dd LM95-_TurnLeft
	.dw 0x0d,0x0a
.code
LM95:
	R1=9216	// QImode move
	[28677]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,243,',0,0
	.dd LM96-_TurnLeft
	.dw 0x0d,0x0a
.code
LM96:
	CALL _Delay	// call without return value
.debug
	.dw '.stabn 0x44,0,244,',0,0
	.dd LM97-_TurnLeft
	.dw 0x0d,0x0a
.code
LM97:
	CALL _Delay	// call without return value
.debug
	.dw '.stabn 0x44,0,245,',0,0
	.dd LM98-_TurnLeft
	.dw 0x0d,0x0a
.code
LM98:
	R1=10240	// QImode move
	[28677]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,246,',0,0
	.dd LM99-_TurnLeft
	.dw 0x0d,0x0a
.code
LM99:
	CALL _Delay	// call without return value
.debug
	.dw '.stabn 0x44,0,240,',0,0
	.dd LM100-_TurnLeft
	.dw 0x0d,0x0a
.code
LM100:
L83:
	R1=[BP]	// QImode move
	R2=R1+1
	[BP]=R2	// QImode move
	PC=L81	// jump
L82:
.debug
	.dw '.stabn 0x44,0,248,',0,0
	.dd LM101-_TurnLeft
	.dw 0x0d,0x0a
.code
LM101:
	R1=0	// QImode move
	[28677]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,249,',0,0
	.dd LM102-_TurnLeft
	.dw 0x0d,0x0a
.code
LM102:
LBE8:
.debug
	.dw '.stabn 0x44,0,249,',0,0
	.dd LM103-_TurnLeft
	.dw 0x0d,0x0a
.code
LM103:
L80:

	SP+=2
	POP BP from [SP]
	RETF
	.endp	// end of TurnLeft

.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB8-_TurnLeft
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "j:4",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE8-_TurnLeft
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME9-_TurnLeft
	.dw 0x0d,0x0a
.code
LME9:
.code
.debug
	.dw '.stabs "TurnRight:F19",36,0,0,',0,0,offset _TurnRight,seg _TurnRight,0x0d,0x0a
.CODE
.public _TurnRight
_TurnRight:	.proc
.debug
	.dw '.stabn 0x44,0,257,',0,0
	.dd LM104-_TurnRight
	.dw 0x0d,0x0a
.code
LM104:
	// total=2, vars=2
	// frame_pointer_needed: 1
.debug
	.dw '.stabn 0xa6,0,0,2',0x0d, 0x0a
.code
	PUSH BP to [SP]
	SP-=2
	BP=SP+1

	R1=BP+5
	[BP+1]=R1	// QImode move
LBB9:
.debug
	.dw '.stabn 0x44,0,259,',0,0
	.dd LM105-_TurnRight
	.dw 0x0d,0x0a
.code
LM105:
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	R1=10	// QImode move
	[SP--]=R1	// QImode move
	CALL _PlaySnd	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,260,',0,0
	.dd LM106-_TurnRight
	.dw 0x0d,0x0a
.code
LM106:
	R1=0	// QImode move
	[BP]=R1	// QImode move
L87:
	R1=[BP]	// QImode move
	CMP R1,29	// QImode compare
	NSJNA L90	//QImode LEU
	PC=L88	// jump
L90:
.debug
	.dw '.stabn 0x44,0,262,',0,0
	.dd LM107-_TurnRight
	.dw 0x0d,0x0a
.code
LM107:
	R1=6144	// QImode move
	[28677]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,263,',0,0
	.dd LM108-_TurnRight
	.dw 0x0d,0x0a
.code
LM108:
	CALL _Delay	// call without return value
.debug
	.dw '.stabn 0x44,0,264,',0,0
	.dd LM109-_TurnRight
	.dw 0x0d,0x0a
.code
LM109:
	CALL _Delay	// call without return value
.debug
	.dw '.stabn 0x44,0,265,',0,0
	.dd LM110-_TurnRight
	.dw 0x0d,0x0a
.code
LM110:
	R1=10240	// QImode move
	[28677]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,266,',0,0
	.dd LM111-_TurnRight
	.dw 0x0d,0x0a
.code
LM111:
	CALL _Delay	// call without return value
.debug
	.dw '.stabn 0x44,0,260,',0,0
	.dd LM112-_TurnRight
	.dw 0x0d,0x0a
.code
LM112:
L89:
	R1=[BP]	// QImode move
	R2=R1+1
	[BP]=R2	// QImode move
	PC=L87	// jump
L88:
.debug
	.dw '.stabn 0x44,0,268,',0,0
	.dd LM113-_TurnRight
	.dw 0x0d,0x0a
.code
LM113:
	R1=0	// QImode move
	[28677]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,269,',0,0
	.dd LM114-_TurnRight
	.dw 0x0d,0x0a
.code
LM114:
LBE9:
.debug
	.dw '.stabn 0x44,0,269,',0,0
	.dd LM115-_TurnRight
	.dw 0x0d,0x0a
.code
LM115:
L86:

	SP+=2
	POP BP from [SP]
	RETF
	.endp	// end of TurnRight

.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB9-_TurnRight
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "j:4",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE9-_TurnRight
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME10-_TurnRight
	.dw 0x0d,0x0a
.code
LME10:
.code
.debug
	.dw '.stabs "led_on:F19",36,0,0,',0,0,offset _led_on,seg _led_on,0x0d,0x0a
.CODE
.public _led_on
_led_on:	.proc
.debug
	.dw '.stabn 0x44,0,277,',0,0
	.dd LM116-_led_on
	.dw 0x0d,0x0a
.code
LM116:
	// total=0, vars=0
	// frame_pointer_needed: 1
.debug
	.dw '.stabn 0xa6,0,0,0',0x0d, 0x0a
.code
	PUSH BP to [SP]
	BP=SP+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,278,',0,0
	.dd LM117-_led_on
	.dw 0x0d,0x0a
.code
LM117:
	R2=0	// QImode move
	[28677]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,279,',0,0
	.dd LM118-_led_on
	.dw 0x0d,0x0a
.code
LM118:
.debug
	.dw '.stabn 0x44,0,279,',0,0
	.dd LM119-_led_on
	.dw 0x0d,0x0a
.code
LM119:
L92:

	POP BP from [SP]
	RETF
	.endp	// end of led_on

.debug
	.dw '.stabf ',0,0
	.dd LME11-_led_on
	.dw 0x0d,0x0a
.code
LME11:
.code
.debug
	.dw '.stabs "main:F1",36,0,0,',0,0,offset _main,seg _main,0x0d,0x0a
.CODE
.public _main
_main:	.proc
.debug
	.dw '.stabn 0x44,0,281,',0,0
	.dd LM120-_main
	.dw 0x0d,0x0a
.code
LM120:
	// total=4, vars=4
	// frame_pointer_needed: 1
.debug
	.dw '.stabn 0xa6,0,0,4',0x0d, 0x0a
.code
	PUSH BP to [SP]
	SP-=4
	BP=SP+1

	R1=BP+7
	[BP+3]=R1	// QImode move
LBB10:
.debug
	.dw '.stabn 0x44,0,282,',0,0
	.dd LM121-_main
	.dw 0x0d,0x0a
.code
LM121:
	R1=BP	// QImode move
	R2=BP+1
	R1=0	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,285,',0,0
	.dd LM122-_main
	.dw 0x0d,0x0a
.code
LM122:
	R1=(-256)	// QImode move
	[28674]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,286,',0,0
	.dd LM123-_main
	.dw 0x0d,0x0a
.code
LM123:
	R1=(-256)	// QImode move
	[28675]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,287,',0,0
	.dd LM124-_main
	.dw 0x0d,0x0a
.code
LM124:
	R1=0	// QImode move
	[28672]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,293,',0,0
	.dd LM125-_main
	.dw 0x0d,0x0a
.code
LM125:
	R1=(-1)	// QImode move
	[28679]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,294,',0,0
	.dd LM126-_main
	.dw 0x0d,0x0a
.code
LM126:
	R1=(-1)	// QImode move
	[28680]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,295,',0,0
	.dd LM127-_main
	.dw 0x0d,0x0a
.code
LM127:
	R1=(-1)	// QImode move
	[28677]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,297,',0,0
	.dd LM128-_main
	.dw 0x0d,0x0a
.code
LM128:
	R1=0	// QImode move
	[SP--]=R1	// QImode move
	CALL _BSR_DeleteSDGroup	// call with return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,298,',0,0
	.dd LM129-_main
	.dw 0x0d,0x0a
.code
LM129:
	R1=BP	// QImode move
	R2=BP+2
	R1=[0xe000]
	R3=R2	// QImode move
	[R3]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,299,',0,0
	.dd LM130-_main
	.dw 0x0d,0x0a
.code
LM130:
	R1=BP	// QImode move
	R2=BP+2
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	CMP R1,(-1)	// QImode compare
	NSJNZ L94	//QImode NE
.debug
	.dw '.stabn 0x44,0,301,',0,0
	.dd LM131-_main
	.dw 0x0d,0x0a
.code
LM131:
	CALL _TrainSD	// call without return value
.debug
	.dw '.stabn 0x44,0,302,',0,0
	.dd LM132-_main
	.dw 0x0d,0x0a
.code
LM132:
	CALL _StoreSD	// call without return value
.debug
	.dw '.stabn 0x44,0,303,',0,0
	.dd LM133-_main
	.dw 0x0d,0x0a
.code
LM133:
	PC=L95	// jump
L94:
.debug
	.dw '.stabn 0x44,0,306,',0,0
	.dd LM134-_main
	.dw 0x0d,0x0a
.code
LM134:
	CALL _LoadSD	// call without return value
L95:
.debug
	.dw '.stabn 0x44,0,309,',0,0
	.dd LM135-_main
	.dw 0x0d,0x0a
.code
LM135:
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	R1=9	// QImode move
	[SP--]=R1	// QImode move
	CALL _PlaySnd	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,310,',0,0
	.dd LM136-_main
	.dw 0x0d,0x0a
.code
LM136:
	R1=0	// QImode move
	[SP--]=R1	// QImode move
	CALL _BSR_InitRecognizer	// call with return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,312,',0,0
	.dd LM137-_main
	.dw 0x0d,0x0a
.code
LM137:
L96:
	PC=L98	// jump
	PC=L97	// jump
L98:
.debug
	.dw '.stabn 0x44,0,314,',0,0
	.dd LM138-_main
	.dw 0x0d,0x0a
.code
LM138:
	CALL _BSR_GetResult	// call with return value
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,316,',0,0
	.dd LM139-_main
	.dw 0x0d,0x0a
.code
LM139:
	R1=[BP]	// QImode move
	CMP R1,0	// QImode test
	NSJNG L99	//QImode LE
.debug
	.dw '.stabn 0x44,0,318,',0,0
	.dd LM140-_main
	.dw 0x0d,0x0a
.code
LM140:
	R1=[BP]	// QImode move
	CMP R1,256	// QImode compare
	NSJNZ L100	//QImode NE
.debug
	.dw '.stabn 0x44,0,320,',0,0
	.dd LM141-_main
	.dw 0x0d,0x0a
.code
LM141:
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	R1=5	// QImode move
	[SP--]=R1	// QImode move
	CALL _PlaySnd	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,321,',0,0
	.dd LM142-_main
	.dw 0x0d,0x0a
.code
LM142:
	R1=BP	// QImode move
	R2=BP+1
	R1=1	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
L100:
.debug
	.dw '.stabn 0x44,0,324,',0,0
	.dd LM143-_main
	.dw 0x0d,0x0a
.code
LM143:
	R1=BP	// QImode move
	R2=BP+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	CMP R1,1	// QImode compare
	NSJNZ L99	//QImode NE
.debug
	.dw '.stabn 0x44,0,326,',0,0
	.dd LM144-_main
	.dw 0x0d,0x0a
.code
LM144:
	R2=[BP]	// QImode move
	R1=R2	// QImode move
	R1=R1-257
	CMP R1,3	// QImode compare
	NSJA L107	//QImode GTU
	R2=L108	// QImode move
	R1 = R1 + R2	//addqi3
	R2=R1	// QImode move
	R1=[R2]	// QImode move
	PC=R1	// tablejump
.text
L108:
	.dw L103
	.dw L104
	.dw L105
	.dw L106
.code
L103:
.debug
	.dw '.stabn 0x44,0,329,',0,0
	.dd LM145-_main
	.dw 0x0d,0x0a
.code
LM145:
	CALL _led_on	// call without return value
.debug
	.dw '.stabn 0x44,0,331,',0,0
	.dd LM146-_main
	.dw 0x0d,0x0a
.code
LM146:
	R1=BP	// QImode move
	R2=BP+1
	R1=0	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,332,',0,0
	.dd LM147-_main
	.dw 0x0d,0x0a
.code
LM147:
	PC=L99	// jump
L104:
.debug
	.dw '.stabn 0x44,0,334,',0,0
	.dd LM148-_main
	.dw 0x0d,0x0a
.code
LM148:
	CALL _BackUp	// call without return value
.debug
	.dw '.stabn 0x44,0,335,',0,0
	.dd LM149-_main
	.dw 0x0d,0x0a
.code
LM149:
	R1=BP	// QImode move
	R2=BP+1
	R1=0	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,336,',0,0
	.dd LM150-_main
	.dw 0x0d,0x0a
.code
LM150:
	PC=L99	// jump
L105:
.debug
	.dw '.stabn 0x44,0,338,',0,0
	.dd LM151-_main
	.dw 0x0d,0x0a
.code
LM151:
	CALL _TurnLeft	// call without return value
.debug
	.dw '.stabn 0x44,0,339,',0,0
	.dd LM152-_main
	.dw 0x0d,0x0a
.code
LM152:
	R1=BP	// QImode move
	R2=BP+1
	R1=0	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,340,',0,0
	.dd LM153-_main
	.dw 0x0d,0x0a
.code
LM153:
	PC=L99	// jump
L106:
.debug
	.dw '.stabn 0x44,0,342,',0,0
	.dd LM154-_main
	.dw 0x0d,0x0a
.code
LM154:
	CALL _TurnRight	// call without return value
.debug
	.dw '.stabn 0x44,0,343,',0,0
	.dd LM155-_main
	.dw 0x0d,0x0a
.code
LM155:
	R1=BP	// QImode move
	R2=BP+1
	R1=0	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,344,',0,0
	.dd LM156-_main
	.dw 0x0d,0x0a
.code
LM156:
	PC=L99	// jump
L107:
.debug
	.dw '.stabn 0x44,0,346,',0,0
	.dd LM157-_main
	.dw 0x0d,0x0a
.code
LM157:
	PC=L99	// jump
L102:
L101:
L99:
.debug
	.dw '.stabn 0x44,0,351,',0,0
	.dd LM158-_main
	.dw 0x0d,0x0a
.code
LM158:
	R2=[28672]	// QImode move
	R1=R2&4
	CMP R1,0	// QImode test
	NSJZ L109	//QImode EQ
.debug
	.dw '.stabn 0x44,0,353,',0,0
	.dd LM159-_main
	.dw 0x0d,0x0a
.code
LM159:
	R1=(-8192)	// QImode move
	[SP--]=R1	// QImode move
	CALL _F_FlashErase	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,354,',0,0
	.dd LM160-_main
	.dw 0x0d,0x0a
.code
LM160:
L110:
	PC=L112	// jump
	PC=L109	// jump
L112:
.debug
	.dw '.stabn 0x44,0,356,',0,0
	.dd LM161-_main
	.dw 0x0d,0x0a
.code
LM161:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,357,',0,0
	.dd LM162-_main
	.dw 0x0d,0x0a
.code
LM162:
	PC=L110	// jump
L111:
L109:
.debug
	.dw '.stabn 0x44,0,359,',0,0
	.dd LM163-_main
	.dw 0x0d,0x0a
.code
LM163:
	PC=L96	// jump
L97:
.debug
	.dw '.stabn 0x44,0,360,',0,0
	.dd LM164-_main
	.dw 0x0d,0x0a
.code
LM164:
LBE10:
.debug
	.dw '.stabn 0x44,0,360,',0,0
	.dd LM165-_main
	.dw 0x0d,0x0a
.code
LM165:
L93:

	SP+=4
	POP BP from [SP]
	RETF
	.endp	// end of main

.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB10-_main
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "Result:1",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "Ready:4",128,0,0,1',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "BS_Flag:4",128,0,0,2',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE10-_main
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME12-_main
	.dw 0x0d,0x0a
.code
LME12:
.external _BSR_GetResult
.external _BSR_DeleteSDGroup
.external _BSR_ImportSDWord
.external _BSR_SDModel
.external _F_FlashWrite1Word
.external _BSR_ExportSDWord
.external _F_FlashErase
.external _BSR_Train
.external _BSR_InitRecognizer
.external _SACM_S480_Stop
.external _SACM_S480_ServiceLoop
.external _SACM_S480_Status
.external _SACM_S480_Play
.external _SACM_S480_Initial
.external _BSR_StopRecognizer
	.end

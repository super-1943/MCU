// GCC for SUNPLUS u'nSP version 1.0.21-3
// Command: D:\PROGRA~1\Sunplus\UNSPID~1.0\cc1.exe C:\DOCUME~1\ZHANGZ~1.YSU\LOCALS~1\Temp\ccmoaaaa.i -fkeep-inline-functions -quiet -dumpbase main.c -mglobal-var-iram -gstabs -o .\Debug/main.asm
	.external __sn_func_ptr_sec

// gcc2_compiled.:

.debug
	.dw '.stabs "F:/abc/shibieyuyin5/",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
.code
.debug
	.dw '.stabs "F:/abc/shibieyuyin5/main.c",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
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
.public _gActivated
.iram
_gActivated:
	.dw 0
.debug
	.dw '.stabs "gActivated:G1",32,0,0,',0,0,offset _gActivated,seg _gActivated,0x0d,0x0a
.CODE
.public _gTriggerRespond
.iram
_gTriggerRespond:
	.dw 9
	.dw 10
	.dw 9
.debug
	.dw '.stabs "gTriggerRespond:G20=ar1;0;2;1",32,0,0,',0,0,offset _gTriggerRespond,seg _gTriggerRespond,0x0d,0x0a
.CODE
.public _gComm2Respond
.iram
_gComm2Respond:
	.dw 11
	.dw 12
	.dw 13
.debug
	.dw '.stabs "gComm2Respond:G21=ar1;0;2;1",32,0,0,',0,0,offset _gComm2Respond,seg _gComm2Respond,0x0d,0x0a
.CODE
.public _PlayFlag
.iram
_PlayFlag:
	.dw 0
.debug
	.dw '.stabs "PlayFlag:G1",32,0,0,',0,0,offset _PlayFlag,seg _PlayFlag,0x0d,0x0a
.CODE
.code
.debug
	.dw '.stabs "PlayRespond2:F19",36,0,0,',0,0,offset _PlayRespond2,seg _PlayRespond2,0x0d,0x0a
.CODE
.public _PlayRespond2
_PlayRespond2:	.proc
.debug
	.dw '.stabn 0x44,0,80,',0,0
	.dd LM1-_PlayRespond2
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
	.dw '.stabn 0x44,0,81,',0,0
	.dd LM2-_PlayRespond2
	.dw 0x0d,0x0a
.code
LM2:
LBB2:
	call _BSR_StopRecognizer	// call without return value
.debug
	.dw '.stabn 0x44,0,82,',0,0
	.dd LM3-_PlayRespond2
	.dw 0x0d,0x0a
.code
LM3:
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	call _SACM_A2000_Initial	// call with return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,83,',0,0
	.dd LM4-_PlayRespond2
	.dw 0x0d,0x0a
.code
LM4:
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	R2=[BP]	// QImode move
	R1=[R2]	// QImode move
	[SP--]=R1	// QImode move
	call _SACM_A2000_Play	// call with return value
	SP = SP + 3	//SP
.debug
	.dw '.stabn 0x44,0,84,',0,0
	.dd LM5-_PlayRespond2
	.dw 0x0d,0x0a
.code
LM5:
L3:
	call _SACM_A2000_Status	// call with return value
	R2=R1&1
	CMP R2,0	// QImode test
	NSJNZ L5	//QImode NE
	pc=L4	// Indirect jump
L5:
.debug
	.dw '.stabn 0x44,0,86,',0,0
	.dd LM6-_PlayRespond2
	.dw 0x0d,0x0a
.code
LM6:
LBB3:
	call _SACM_A2000_ServiceLoop	// call with return value
.debug
	.dw '.stabn 0x44,0,87,',0,0
	.dd LM7-_PlayRespond2
	.dw 0x0d,0x0a
.code
LM7:
	call _ClearWatchDog	// call without return value
.debug
	.dw '.stabn 0x44,0,88,',0,0
	.dd LM8-_PlayRespond2
	.dw 0x0d,0x0a
.code
LM8:
LBE3:
	pc=L3	// Indirect jump
L4:
.debug
	.dw '.stabn 0x44,0,89,',0,0
	.dd LM9-_PlayRespond2
	.dw 0x0d,0x0a
.code
LM9:
	call _SACM_A2000_Stop	// call with return value
.debug
	.dw '.stabn 0x44,0,90,',0,0
	.dd LM10-_PlayRespond2
	.dw 0x0d,0x0a
.code
LM10:
	R1=0	// QImode move
	[SP--]=R1	// QImode move
	call _BSR_InitRecognizer	// call with return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,91,',0,0
	.dd LM11-_PlayRespond2
	.dw 0x0d,0x0a
.code
LM11:
	call _BSR_EnableCPUIndicator	// call without return value
.debug
	.dw '.stabn 0x44,0,92,',0,0
	.dd LM12-_PlayRespond2
	.dw 0x0d,0x0a
.code
LM12:
LBE2:
.debug
	.dw '.stabn 0x44,0,92,',0,0
	.dd LM13-_PlayRespond2
	.dw 0x0d,0x0a
.code
LM13:
L2:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of PlayRespond2

.debug
	.dw '.stabs "Result:p1",160,0,0,4',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB2-_PlayRespond2
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB3-_PlayRespond2
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE3-_PlayRespond2
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE2-_PlayRespond2
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME1-_PlayRespond2
	.dw 0x0d,0x0a
.code
LME1:
.code
.debug
	.dw '.stabs "PlayRespond:F19",36,0,0,',0,0,offset _PlayRespond,seg _PlayRespond,0x0d,0x0a
.CODE
.public _PlayRespond
_PlayRespond:	.proc
.debug
	.dw '.stabn 0x44,0,95,',0,0
	.dd LM14-_PlayRespond
	.dw 0x0d,0x0a
.code
LM14:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,96,',0,0
	.dd LM15-_PlayRespond
	.dw 0x0d,0x0a
.code
LM15:
LBB4:
	call _BSR_StopRecognizer	// call without return value
.debug
	.dw '.stabn 0x44,0,97,',0,0
	.dd LM16-_PlayRespond
	.dw 0x0d,0x0a
.code
LM16:
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	call _SACM_S480_Initial	// call with return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,98,',0,0
	.dd LM17-_PlayRespond
	.dw 0x0d,0x0a
.code
LM17:
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	R2=[BP]	// QImode move
	R1=[R2]	// QImode move
	[SP--]=R1	// QImode move
	call _SACM_S480_Play	// call with return value
	SP = SP + 3	//SP
.debug
	.dw '.stabn 0x44,0,99,',0,0
	.dd LM18-_PlayRespond
	.dw 0x0d,0x0a
.code
LM18:
L8:
	call _SACM_S480_Status	// call with return value
	R2=R1&1
	CMP R2,0	// QImode test
	NSJNZ L10	//QImode NE
	pc=L9	// Indirect jump
L10:
.debug
	.dw '.stabn 0x44,0,101,',0,0
	.dd LM19-_PlayRespond
	.dw 0x0d,0x0a
.code
LM19:
LBB5:
	call _SACM_S480_ServiceLoop	// call with return value
.debug
	.dw '.stabn 0x44,0,102,',0,0
	.dd LM20-_PlayRespond
	.dw 0x0d,0x0a
.code
LM20:
	call _ClearWatchDog	// call without return value
.debug
	.dw '.stabn 0x44,0,103,',0,0
	.dd LM21-_PlayRespond
	.dw 0x0d,0x0a
.code
LM21:
LBE5:
	pc=L8	// Indirect jump
L9:
.debug
	.dw '.stabn 0x44,0,104,',0,0
	.dd LM22-_PlayRespond
	.dw 0x0d,0x0a
.code
LM22:
	call _SACM_S480_Stop	// call with return value
.debug
	.dw '.stabn 0x44,0,105,',0,0
	.dd LM23-_PlayRespond
	.dw 0x0d,0x0a
.code
LM23:
	R1=0	// QImode move
	[SP--]=R1	// QImode move
	call _BSR_InitRecognizer	// call with return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,106,',0,0
	.dd LM24-_PlayRespond
	.dw 0x0d,0x0a
.code
LM24:
	call _BSR_EnableCPUIndicator	// call without return value
.debug
	.dw '.stabn 0x44,0,107,',0,0
	.dd LM25-_PlayRespond
	.dw 0x0d,0x0a
.code
LM25:
LBE4:
.debug
	.dw '.stabn 0x44,0,107,',0,0
	.dd LM26-_PlayRespond
	.dw 0x0d,0x0a
.code
LM26:
L7:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of PlayRespond

.debug
	.dw '.stabs "Result:p1",160,0,0,4',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB4-_PlayRespond
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB5-_PlayRespond
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE5-_PlayRespond
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE4-_PlayRespond
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME2-_PlayRespond
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
	.dw '.stabn 0x44,0,110,',0,0
	.dd LM27-_TrainWord
	.dw 0x0d,0x0a
.code
LM27:
	// total=2, vars=2
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=2
	bp=sp+1

	R1=BP+5
	[bp+1]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,111,',0,0
	.dd LM28-_TrainWord
	.dw 0x0d,0x0a
.code
LM28:
LBB6:
.debug
	.dw '.stabn 0x44,0,112,',0,0
	.dd LM29-_TrainWord
	.dw 0x0d,0x0a
.code
LM29:
	R1=[bp+1]	// QImode move
	R3=[bp+1]	// QImode move
	R2=R3+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	call _PlayRespond	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,113,',0,0
	.dd LM30-_TrainWord
	.dw 0x0d,0x0a
.code
LM30:
L13:
	pc=L15	// Indirect jump
	pc=L14	// Indirect jump
L15:
.debug
	.dw '.stabn 0x44,0,115,',0,0
	.dd LM31-_TrainWord
	.dw 0x0d,0x0a
.code
LM31:
	R1=0	// QImode move
	[SP--]=R1	// QImode move
	R2=[bp+1]	// QImode move
	R1=[R2]	// QImode move
	[SP--]=R1	// QImode move
	call _BSR_Train	// call with return value
	SP = SP + 2	//SP
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,116,',0,0
	.dd LM32-_TrainWord
	.dw 0x0d,0x0a
.code
LM32:
	R1=[BP]	// QImode move
	CMP R1,0	// QImode test
	NSJNZ L16	//QImode NE
	pc=L14	// Indirect jump
L16:
.debug
	.dw '.stabn 0x44,0,117,',0,0
	.dd LM33-_TrainWord
	.dw 0x0d,0x0a
.code
LM33:
	R2=[BP]	// QImode move
	R1=R2	// QImode move
	R1=R1-(-6)
	CMP R1,5	// QImode compare
	NSJA L17	//QImode GTU
	R2=L26	// QImode move
	R1 = R1 + R2	//addqi3
	R3=R1	// QImode move
	R1=[R3]	// QImode move
	pc=R1	// tablejump
.text
L26:
	.dw L25
	.dw L22
	.dw L21
	.dw L20
	.dw L19
	.dw L18
.code
L18:
.debug
	.dw '.stabn 0x44,0,120,',0,0
	.dd LM34-_TrainWord
	.dw 0x0d,0x0a
.code
LM34:
	R1=5	// QImode move
	[SP--]=R1	// QImode move
	call _PlayRespond	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,121,',0,0
	.dd LM35-_TrainWord
	.dw 0x0d,0x0a
.code
LM35:
	R1=(-1)	// QImode move
	pc=L12	// Indirect jump
L19:
.debug
	.dw '.stabn 0x44,0,123,',0,0
	.dd LM36-_TrainWord
	.dw 0x0d,0x0a
.code
LM36:
	R1=4	// QImode move
	[SP--]=R1	// QImode move
	call _PlayRespond	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,124,',0,0
	.dd LM37-_TrainWord
	.dw 0x0d,0x0a
.code
LM37:
	pc=L17	// Indirect jump
L20:
.debug
	.dw '.stabn 0x44,0,126,',0,0
	.dd LM38-_TrainWord
	.dw 0x0d,0x0a
.code
LM38:
	R1=14	// QImode move
	[SP--]=R1	// QImode move
	call _PlayRespond	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,127,',0,0
	.dd LM39-_TrainWord
	.dw 0x0d,0x0a
.code
LM39:
	R1=(-1)	// QImode move
	pc=L12	// Indirect jump
L21:
.debug
	.dw '.stabn 0x44,0,129,',0,0
	.dd LM40-_TrainWord
	.dw 0x0d,0x0a
.code
LM40:
	R1=(-1)	// QImode move
	pc=L12	// Indirect jump
L22:
.debug
	.dw '.stabn 0x44,0,131,',0,0
	.dd LM41-_TrainWord
	.dw 0x0d,0x0a
.code
LM41:
	R2=[bp+1]	// QImode move
	R1=[R2]	// QImode move
	CMP R1,256	// QImode compare
	NSJNZ L23	//QImode NE
	R1=6	// QImode move
	[SP--]=R1	// QImode move
	call _PlayRespond	// call without return value
	SP = SP + 1	//SP
	pc=L24	// Indirect jump
L23:
.debug
	.dw '.stabn 0x44,0,132,',0,0
	.dd LM42-_TrainWord
	.dw 0x0d,0x0a
.code
LM42:
	R1=7	// QImode move
	[SP--]=R1	// QImode move
	call _PlayRespond	// call without return value
	SP = SP + 1	//SP
L24:
.debug
	.dw '.stabn 0x44,0,133,',0,0
	.dd LM43-_TrainWord
	.dw 0x0d,0x0a
.code
LM43:
	R1=(-1)	// QImode move
	pc=L12	// Indirect jump
L25:
.debug
	.dw '.stabn 0x44,0,135,',0,0
	.dd LM44-_TrainWord
	.dw 0x0d,0x0a
.code
LM44:
	R1=(-1)	// QImode move
	pc=L12	// Indirect jump
L27:
L17:
.debug
	.dw '.stabn 0x44,0,137,',0,0
	.dd LM45-_TrainWord
	.dw 0x0d,0x0a
.code
LM45:
	pc=L13	// Indirect jump
L14:
.debug
	.dw '.stabn 0x44,0,138,',0,0
	.dd LM46-_TrainWord
	.dw 0x0d,0x0a
.code
LM46:
	R1=0	// QImode move
	pc=L12	// Indirect jump
.debug
	.dw '.stabn 0x44,0,139,',0,0
	.dd LM47-_TrainWord
	.dw 0x0d,0x0a
.code
LM47:
LBE6:
.debug
	.dw '.stabn 0x44,0,139,',0,0
	.dd LM48-_TrainWord
	.dw 0x0d,0x0a
.code
LM48:
L12:

	sp+=2
	pop bp from [sp]
	retf
	.endp	// end of TrainWord

.debug
	.dw '.stabs "WordID:p1",160,0,0,5',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "RespondID:p1",160,0,0,6',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB6-_TrainWord
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "res:1",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE6-_TrainWord
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
	.dw '.stabs "main:F1",36,0,0,',0,0,offset _main,seg _main,0x0d,0x0a
.CODE
.public _main
_main:	.proc
.debug
	.dw '.stabn 0x44,0,142,',0,0
	.dd LM49-_main
	.dw 0x0d,0x0a
.code
LM49:
	// total=4, vars=4
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=4
	bp=sp+1

	R1=BP+7
	[bp+3]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,143,',0,0
	.dd LM50-_main
	.dw 0x0d,0x0a
.code
LM50:
LBB7:
	R1=BP	// QImode move
	R2=BP+1
	R1=0	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
	R1=BP	// QImode move
	R2=BP+2
	R1=0	// QImode move
	R4=R2	// QImode move
	[R4]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,145,',0,0
	.dd LM51-_main
	.dw 0x0d,0x0a
.code
LM51:
	R1=0	// QImode move
	[SP--]=R1	// QImode move
	call _BSR_DeleteSDGroup	// call with return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,147,',0,0
	.dd LM52-_main
	.dw 0x0d,0x0a
.code
LM52:
	R1=0	// QImode move
	[SP--]=R1	// QImode move
	call _PlayRespond	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,149,',0,0
	.dd LM53-_main
	.dw 0x0d,0x0a
.code
LM53:
L32:
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	R1=256	// QImode move
	[SP--]=R1	// QImode move
	call _TrainWord	// call with return value
	SP = SP + 2	//SP
	CMP R1,0	// QImode test
	NSJNZ L34	//QImode NE
	pc=L33	// Indirect jump
L34:
	pc=L32	// Indirect jump
L33:
.debug
	.dw '.stabn 0x44,0,151,',0,0
	.dd LM54-_main
	.dw 0x0d,0x0a
.code
LM54:
L35:
	R1=2	// QImode move
	[SP--]=R1	// QImode move
	R1=257	// QImode move
	[SP--]=R1	// QImode move
	call _TrainWord	// call with return value
	SP = SP + 2	//SP
	CMP R1,0	// QImode test
	NSJNZ L37	//QImode NE
	pc=L36	// Indirect jump
L37:
	pc=L35	// Indirect jump
L36:
.debug
	.dw '.stabn 0x44,0,153,',0,0
	.dd LM55-_main
	.dw 0x0d,0x0a
.code
LM55:
L38:
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	R1=258	// QImode move
	[SP--]=R1	// QImode move
	call _TrainWord	// call with return value
	SP = SP + 2	//SP
	CMP R1,0	// QImode test
	NSJNZ L40	//QImode NE
	pc=L39	// Indirect jump
L40:
	pc=L38	// Indirect jump
L39:
.debug
	.dw '.stabn 0x44,0,156,',0,0
	.dd LM56-_main
	.dw 0x0d,0x0a
.code
LM56:
	R1=0	// QImode move
	[SP--]=R1	// QImode move
	call _BSR_InitRecognizer	// call with return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,157,',0,0
	.dd LM57-_main
	.dw 0x0d,0x0a
.code
LM57:
	call _BSR_EnableCPUIndicator	// call without return value
.debug
	.dw '.stabn 0x44,0,159,',0,0
	.dd LM58-_main
	.dw 0x0d,0x0a
.code
LM58:
	R1=8	// QImode move
	[SP--]=R1	// QImode move
	call _PlayRespond	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,161,',0,0
	.dd LM59-_main
	.dw 0x0d,0x0a
.code
LM59:
L41:
	pc=L43	// Indirect jump
	pc=L42	// Indirect jump
L43:
.debug
	.dw '.stabn 0x44,0,163,',0,0
	.dd LM60-_main
	.dw 0x0d,0x0a
.code
LM60:
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
.debug
	.dw '.stabn 0x44,0,164,',0,0
	.dd LM61-_main
	.dw 0x0d,0x0a
.code
LM61:
	R1=BP	// QImode move
	R2=BP+2
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	CMP R1,2	// QImode compare
	NSJNG L44	//QImode LE
	R1=BP	// QImode move
	R2=BP+2
	R1=0	// QImode move
	R4=R2	// QImode move
	[R4]=R1	// QImode move
L44:
.debug
	.dw '.stabn 0x44,0,165,',0,0
	.dd LM62-_main
	.dw 0x0d,0x0a
.code
LM62:
	call _BSR_GetResult	// call with return value
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,167,',0,0
	.dd LM63-_main
	.dw 0x0d,0x0a
.code
LM63:
	R1=[BP]	// QImode move
	CMP R1,0	// QImode test
	NSJNG L45	//QImode LE
.debug
	.dw '.stabn 0x44,0,169,',0,0
	.dd LM64-_main
	.dw 0x0d,0x0a
.code
LM64:
	R1=[_gActivated]	// QImode move
	CMP R1,0	// QImode test
	NSJZ L46	//QImode EQ
.debug
	.dw '.stabn 0x44,0,171,',0,0
	.dd LM65-_main
	.dw 0x0d,0x0a
.code
LM65:
	R1=BP	// QImode move
	R2=BP+1
	R1=0	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,172,',0,0
	.dd LM66-_main
	.dw 0x0d,0x0a
.code
LM66:
	R1=[BP]	// QImode move
	CMP R1,257	// QImode compare
	NSJZ L49	//QImode EQ
	CMP R1,257	// QImode compare
	NSJG L53	//QImode GT
	CMP R1,256	// QImode compare
	NSJZ L48	//QImode EQ
	pc=L47	// Indirect jump
L53:
	CMP R1,258	// QImode compare
	NSJZ L50	//QImode EQ
	pc=L47	// Indirect jump
L48:
.debug
	.dw '.stabn 0x44,0,175,',0,0
	.dd LM67-_main
	.dw 0x0d,0x0a
.code
LM67:
	R1=BP	// QImode move
	R2=BP+2
	R1=_gTriggerRespond	// QImode move
	R4=R2	// QImode move
	R2=[R4]	// QImode move
	R1 = R1 + R2	//addqi3
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	[SP--]=R2	// QImode move
	call _PlayRespond	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,176,',0,0
	.dd LM68-_main
	.dw 0x0d,0x0a
.code
LM68:
	pc=L47	// Indirect jump
L49:
.debug
	.dw '.stabn 0x44,0,178,',0,0
	.dd LM69-_main
	.dw 0x0d,0x0a
.code
LM69:
	R1=1	// QImode move
	[_PlayFlag]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,179,',0,0
	.dd LM70-_main
	.dw 0x0d,0x0a
.code
LM70:
	R1=0	// QImode move
	[SP--]=R1	// QImode move
	call _PlayRespond2	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,180,',0,0
	.dd LM71-_main
	.dw 0x0d,0x0a
.code
LM71:
	R1=0	// QImode move
	[_PlayFlag]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,181,',0,0
	.dd LM72-_main
	.dw 0x0d,0x0a
.code
LM72:
	R1=0	// QImode move
	[_gActivated]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,182,',0,0
	.dd LM73-_main
	.dw 0x0d,0x0a
.code
LM73:
	pc=L47	// Indirect jump
L50:
.debug
	.dw '.stabn 0x44,0,184,',0,0
	.dd LM74-_main
	.dw 0x0d,0x0a
.code
LM74:
	R1=BP	// QImode move
	R2=BP+2
	R1=_gComm2Respond	// QImode move
	R4=R2	// QImode move
	R2=[R4]	// QImode move
	R1 = R1 + R2	//addqi3
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	[SP--]=R2	// QImode move
	call _PlayRespond	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,185,',0,0
	.dd LM75-_main
	.dw 0x0d,0x0a
.code
LM75:
	R1=0	// QImode move
	[_gActivated]=R1	// QImode move
L52:
L47:
.debug
	.dw '.stabn 0x44,0,187,',0,0
	.dd LM76-_main
	.dw 0x0d,0x0a
.code
LM76:
	pc=L54	// Indirect jump
L46:
.debug
	.dw '.stabn 0x44,0,190,',0,0
	.dd LM77-_main
	.dw 0x0d,0x0a
.code
LM77:
	R1=[BP]	// QImode move
	CMP R1,256	// QImode compare
	NSJNZ L54	//QImode NE
.debug
	.dw '.stabn 0x44,0,192,',0,0
	.dd LM78-_main
	.dw 0x0d,0x0a
.code
LM78:
	R1=BP	// QImode move
	R2=BP+2
	R1=_gTriggerRespond	// QImode move
	R4=R2	// QImode move
	R2=[R4]	// QImode move
	R1 = R1 + R2	//addqi3
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	[SP--]=R2	// QImode move
	call _PlayRespond	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,193,',0,0
	.dd LM79-_main
	.dw 0x0d,0x0a
.code
LM79:
	R1=1	// QImode move
	[_gActivated]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,194,',0,0
	.dd LM80-_main
	.dw 0x0d,0x0a
.code
LM80:
	R1=BP	// QImode move
	R2=BP+1
	R1=0	// QImode move
	R4=R2	// QImode move
	[R4]=R1	// QImode move
L55:
L54:
.debug
	.dw '.stabn 0x44,0,197,',0,0
	.dd LM81-_main
	.dw 0x0d,0x0a
.code
LM81:
	pc=L56	// Indirect jump
L45:
.debug
	.dw '.stabn 0x44,0,198,',0,0
	.dd LM82-_main
	.dw 0x0d,0x0a
.code
LM82:
	R1=[_gActivated]	// QImode move
	CMP R1,0	// QImode test
	NSJZ L56	//QImode EQ
.debug
	.dw '.stabn 0x44,0,200,',0,0
	.dd LM83-_main
	.dw 0x0d,0x0a
.code
LM83:
	R1=BP	// QImode move
	R2=BP+1
	R3=BP	// QImode move
	R1=BP+1
	R2=BP	// QImode move
	R3=BP+1
	R2=R3	// QImode move
	R4=[R2]	// QImode move
	R2=R4+1
	R3=R2	// QImode move
	R4=R1	// QImode move
	[R4]=R3	// QImode move
	CMP R3,450	// QImode compare
	NSJNG L56	//QImode LE
.debug
	.dw '.stabn 0x44,0,202,',0,0
	.dd LM84-_main
	.dw 0x0d,0x0a
.code
LM84:
	R1=5	// QImode move
	[SP--]=R1	// QImode move
	call _PlayRespond	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,203,',0,0
	.dd LM85-_main
	.dw 0x0d,0x0a
.code
LM85:
	R1=0	// QImode move
	[_gActivated]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,204,',0,0
	.dd LM86-_main
	.dw 0x0d,0x0a
.code
LM86:
	R1=BP	// QImode move
	R2=BP+1
	R1=0	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
L58:
L57:
L56:
.debug
	.dw '.stabn 0x44,0,207,',0,0
	.dd LM87-_main
	.dw 0x0d,0x0a
.code
LM87:
	pc=L41	// Indirect jump
L42:
.debug
	.dw '.stabn 0x44,0,208,',0,0
	.dd LM88-_main
	.dw 0x0d,0x0a
.code
LM88:
LBE7:
.debug
	.dw '.stabn 0x44,0,208,',0,0
	.dd LM89-_main
	.dw 0x0d,0x0a
.code
LM89:
L31:

	sp+=4
	pop bp from [sp]
	retf
	.endp	// end of main

.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB7-_main
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "res:1",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "timeCnt:1",128,0,0,1',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "random_no:1",128,0,0,2',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE7-_main
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME4-_main
	.dw 0x0d,0x0a
.code
LME4:
.external _BSR_GetResult
.external _BSR_DeleteSDGroup
.external _BSR_Train
.external _SACM_S480_Stop
.external _SACM_S480_ServiceLoop
.external _SACM_S480_Status
.external _SACM_S480_Play
.external _SACM_S480_Initial
.external _BSR_EnableCPUIndicator
.external _BSR_InitRecognizer
.external _SACM_A2000_Stop
.external _ClearWatchDog
.external _SACM_A2000_ServiceLoop
.external _SACM_A2000_Status
.external _SACM_A2000_Play
.external _SACM_A2000_Initial
.external _BSR_StopRecognizer
	.end

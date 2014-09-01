// GCC for SUNPLUS u'nSP version 1.0.21-3
// Command: C:\PROGRA~1\Sunplus\UNSPID~1.0\cc1.exe c:\temp\cckzaaaa.i -fkeep-inline-functions -quiet -dumpbase main.c -mglobal-var-iram -gstabs -Wall -o .\Debug/main.asm
	.external __sn_func_ptr_sec

// gcc2_compiled.:

.debug
	.dw '.stabs "E:/program/sun/yejing/",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
.code
.debug
	.dw '.stabs "E:/program/sun/yejing/main.c",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
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
	.dw '.stabs "playsound:F19",36,0,0,',0,0,offset _playsound,seg _playsound,0x0d,0x0a
.CODE
.public _playsound
_playsound:	.proc
.debug
	.dw '.stabn 0x44,0,5,',0,0
	.dd LM1-_playsound
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
	.dw '.stabn 0x44,0,6,',0,0
	.dd LM2-_playsound
	.dw 0x0d,0x0a
.code
LM2:
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	call _SACM_A2000_Initial	// call with return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,7,',0,0
	.dd LM3-_playsound
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
	call _SACM_A2000_Play	// call without return value
	SP = SP + 3	//SP
.debug
	.dw '.stabn 0x44,0,8,',0,0
	.dd LM4-_playsound
	.dw 0x0d,0x0a
.code
LM4:
L3:
	call _SACM_A2000_Status	// call with return value
	R2=R1&1
	CMP R2,0	// QImode test
	NSJNZ L5	//QImode NE
	pc=L4	// Indirect jump
L5:
.debug
	.dw '.stabn 0x44,0,10,',0,0
	.dd LM5-_playsound
	.dw 0x0d,0x0a
.code
LM5:
	call _SACM_A2000_ServiceLoop	// call without return value
.debug
	.dw '.stabn 0x44,0,11,',0,0
	.dd LM6-_playsound
	.dw 0x0d,0x0a
.code
LM6:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,12,',0,0
	.dd LM7-_playsound
	.dw 0x0d,0x0a
.code
LM7:
	pc=L3	// Indirect jump
L4:
.debug
	.dw '.stabn 0x44,0,13,',0,0
	.dd LM8-_playsound
	.dw 0x0d,0x0a
.code
LM8:
	call _SACM_A2000_Stop	// call without return value
.debug
	.dw '.stabn 0x44,0,14,',0,0
	.dd LM9-_playsound
	.dw 0x0d,0x0a
.code
LM9:
.debug
	.dw '.stabn 0x44,0,14,',0,0
	.dd LM10-_playsound
	.dw 0x0d,0x0a
.code
LM10:
L2:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of playsound

.debug
	.dw '.stabs "index:p1",160,0,0,4',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "channel:p1",160,0,0,5',0x0d,0x0a
.CODE
.debug
	.dw '.stabf ',0,0
	.dd LME1-_playsound
	.dw 0x0d,0x0a
.code
LME1:
.text
LC0:
	.str 206, 210, 189, 208, 213, 212, 211, 192, 191, 198, 185, 254, 185, 254, 185, 254, 0
	// length = 17
LC1:
	.str 214, 247, 200, 203, 199, 235, 189, 248, 163, 161, 0
	// length = 11
LC2:
	.str 182, 212, 178, 187, 198, 240, 206, 210, 178, 187, 200, 207, 202, 182, 196, 227, 0
	// length = 17
LC3:
	.str 196, 227, 202, 199, 203, 173, 209, 189, 163, 191, 0
	// length = 11
.code
.debug
	.dw '.stabs "main:F1",36,0,0,',0,0,offset _main,seg _main,0x0d,0x0a
.CODE
.public _main
_main:	.proc
.debug
	.dw '.stabn 0x44,0,16,',0,0
	.dd LM11-_main
	.dw 0x0d,0x0a
.code
LM11:
	// total=2, vars=2
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=2
	bp=sp+1

	R1=BP+5
	[bp+1]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,17,',0,0
	.dd LM12-_main
	.dw 0x0d,0x0a
.code
LM12:
LBB2:
	R1=0	// QImode move
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,18,',0,0
	.dd LM13-_main
	.dw 0x0d,0x0a
.code
LM13:
	R1=[28674]	// QImode move
	R2=R1&(-8)
	[28674]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,19,',0,0
	.dd LM14-_main
	.dw 0x0d,0x0a
.code
LM14:
	R1=[28675]	// QImode move
	R2=R1&(-8)
	[28675]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,20,',0,0
	.dd LM15-_main
	.dw 0x0d,0x0a
.code
LM15:
	R1=[28672]	// QImode move
	R2=R1&(-8)
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,21,',0,0
	.dd LM16-_main
	.dw 0x0d,0x0a
.code
LM16:
	call _init_12864	// call without return value
.debug
	.dw '.stabn 0x44,0,22,',0,0
	.dd LM17-_main
	.dw 0x0d,0x0a
.code
LM17:
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	call _write_cmd_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,23,',0,0
	.dd LM18-_main
	.dw 0x0d,0x0a
.code
LM18:
	R1=8	// QImode move
	[SP--]=R1	// QImode move
	R1=0	// QImode move
	[SP--]=R1	// QImode move
	R1=0	// QImode move
	[SP--]=R1	// QImode move
	R1=LC0	// QImode move
	[SP--]=R1	// QImode move
	call _write_chinese_12864	// call without return value
	SP = SP + 4	//SP
.debug
	.dw '.stabn 0x44,0,25,',0,0
	.dd LM19-_main
	.dw 0x0d,0x0a
.code
LM19:
L8:
	pc=L10	// Indirect jump
	pc=L9	// Indirect jump
L10:
.debug
	.dw '.stabn 0x44,0,27,',0,0
	.dd LM20-_main
	.dw 0x0d,0x0a
.code
LM20:
	R1=[28674]	// QImode move
	R2=R1&(-8)
	[28674]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,28,',0,0
	.dd LM21-_main
	.dw 0x0d,0x0a
.code
LM21:
	R1=[28675]	// QImode move
	R2=R1&(-8)
	[28675]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,29,',0,0
	.dd LM22-_main
	.dw 0x0d,0x0a
.code
LM22:
	R1=[28672]	// QImode move
	R2=R1&(-8)
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,30,',0,0
	.dd LM23-_main
	.dw 0x0d,0x0a
.code
LM23:
	R1=[28672]	// QImode move
	R2=R1&7
	[BP]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,31,',0,0
	.dd LM24-_main
	.dw 0x0d,0x0a
.code
LM24:
	R1=[BP]	// QImode move
	CMP R1,2	// QImode compare
	NSJZ L13	//QImode EQ
	CMP R1,2	// QImode compare
	NSJA L17	//QImode GTU
	CMP R1,1	// QImode compare
	NSJZ L12	//QImode EQ
	pc=L15	// Indirect jump
L17:
	CMP R1,4	// QImode compare
	NSJZ L14	//QImode EQ
	pc=L15	// Indirect jump
L12:
.debug
	.dw '.stabn 0x44,0,34,',0,0
	.dd LM25-_main
	.dw 0x0d,0x0a
.code
LM25:
	R1=5	// QImode move
	[SP--]=R1	// QImode move
	R1=0	// QImode move
	[SP--]=R1	// QImode move
	R1=0	// QImode move
	[SP--]=R1	// QImode move
	R1=LC1	// QImode move
	[SP--]=R1	// QImode move
	call _write_chinese_12864	// call without return value
	SP = SP + 4	//SP
.debug
	.dw '.stabn 0x44,0,35,',0,0
	.dd LM26-_main
	.dw 0x0d,0x0a
.code
LM26:
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	R1=0	// QImode move
	[SP--]=R1	// QImode move
	call _playsound	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,36,',0,0
	.dd LM27-_main
	.dw 0x0d,0x0a
.code
LM27:
	pc=L11	// Indirect jump
L13:
.debug
	.dw '.stabn 0x44,0,38,',0,0
	.dd LM28-_main
	.dw 0x0d,0x0a
.code
LM28:
	R1=8	// QImode move
	[SP--]=R1	// QImode move
	R1=0	// QImode move
	[SP--]=R1	// QImode move
	R1=0	// QImode move
	[SP--]=R1	// QImode move
	R1=LC2	// QImode move
	[SP--]=R1	// QImode move
	call _write_chinese_12864	// call without return value
	SP = SP + 4	//SP
.debug
	.dw '.stabn 0x44,0,39,',0,0
	.dd LM29-_main
	.dw 0x0d,0x0a
.code
LM29:
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	call _playsound	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,40,',0,0
	.dd LM30-_main
	.dw 0x0d,0x0a
.code
LM30:
	pc=L11	// Indirect jump
L14:
.debug
	.dw '.stabn 0x44,0,42,',0,0
	.dd LM31-_main
	.dw 0x0d,0x0a
.code
LM31:
	R1=5	// QImode move
	[SP--]=R1	// QImode move
	R1=0	// QImode move
	[SP--]=R1	// QImode move
	R1=0	// QImode move
	[SP--]=R1	// QImode move
	R1=LC3	// QImode move
	[SP--]=R1	// QImode move
	call _write_chinese_12864	// call without return value
	SP = SP + 4	//SP
.debug
	.dw '.stabn 0x44,0,43,',0,0
	.dd LM32-_main
	.dw 0x0d,0x0a
.code
LM32:
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	R1=2	// QImode move
	[SP--]=R1	// QImode move
	call _playsound	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,44,',0,0
	.dd LM33-_main
	.dw 0x0d,0x0a
.code
LM33:
	pc=L11	// Indirect jump
L15:
.debug
	.dw '.stabn 0x44,0,46,',0,0
	.dd LM34-_main
	.dw 0x0d,0x0a
.code
LM34:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,47,',0,0
	.dd LM35-_main
	.dw 0x0d,0x0a
.code
LM35:
	R1=8	// QImode move
	[SP--]=R1	// QImode move
	R1=0	// QImode move
	[SP--]=R1	// QImode move
	R1=0	// QImode move
	[SP--]=R1	// QImode move
	R1=LC0	// QImode move
	[SP--]=R1	// QImode move
	call _write_chinese_12864	// call without return value
	SP = SP + 4	//SP
L11:
.debug
	.dw '.stabn 0x44,0,49,',0,0
	.dd LM36-_main
	.dw 0x0d,0x0a
.code
LM36:
	pc=L8	// Indirect jump
L9:
.debug
	.dw '.stabn 0x44,0,50,',0,0
	.dd LM37-_main
	.dw 0x0d,0x0a
.code
LM37:
LBE2:
.debug
	.dw '.stabn 0x44,0,50,',0,0
	.dd LM38-_main
	.dw 0x0d,0x0a
.code
LM38:
L7:

	sp+=2
	pop bp from [sp]
	retf
	.endp	// end of main

.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB2-_main
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "key:11",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE2-_main
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME2-_main
	.dw 0x0d,0x0a
.code
LME2:
.external _write_chinese_12864
.external _write_cmd_12864
.external _init_12864
.external _SACM_A2000_Stop
.external _SACM_A2000_ServiceLoop
.external _SACM_A2000_Status
.external _SACM_A2000_Play
.external _SACM_A2000_Initial
	.end

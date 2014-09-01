// GCC for SUNPLUS u'nSP version 1.0.21-3
// Command: D:\PROGRA~1\SunPlus\UNSPID~1.0\cc1.exe C:\DOCUME~1\a\LOCALS~1\Temp\ccC6aaaa.i -fkeep-inline-functions -quiet -dumpbase main.c -mglobal-var-iram -gstabs -Wall -o .\Debug/main.asm
	.external __sn_func_ptr_sec

// gcc2_compiled.:

.debug
	.dw '.stabs "G:/key/",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
.code
.debug
	.dw '.stabs "G:/key/main.c",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
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
	.dw '.stabs "key_init:F19",36,0,0,',0,0,offset _key_init,seg _key_init,0x0d,0x0a
.CODE
.public _key_init
_key_init:	.proc
.debug
	.dw '.stabs "G:/key/mykey.h",0x84,0,0,',0,0,offset Ltext1, seg Ltext1,0x0d,0x0a
.code
.code
Ltext1:
.debug
	.dw '.stabn 0x44,0,44,',0,0
	.dd LM1-_key_init
	.dw 0x0d,0x0a
.code
LM1:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,45,',0,0
	.dd LM2-_key_init
	.dw 0x0d,0x0a
.code
LM2:
	R2=[28679]	// QImode move
	R3=R2&(-256)
	[28679]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,46,',0,0
	.dd LM3-_key_init
	.dw 0x0d,0x0a
.code
LM3:
	R2=[28680]	// QImode move
	R3=R2&(-256)
	[28680]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,47,',0,0
	.dd LM4-_key_init
	.dw 0x0d,0x0a
.code
LM4:
	R2=[28677]	// QImode move
	R3=R2|255
	[28677]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,48,',0,0
	.dd LM5-_key_init
	.dw 0x0d,0x0a
.code
LM5:
.debug
	.dw '.stabn 0x44,0,48,',0,0
	.dd LM6-_key_init
	.dw 0x0d,0x0a
.code
LM6:
L2:

	pop bp from [sp]
	retf
	.endp	// end of key_init

.debug
	.dw '.stabf ',0,0
	.dd LME1-_key_init
	.dw 0x0d,0x0a
.code
LME1:
.code
.debug
	.dw '.stabs "KeyScan:F19",36,0,0,',0,0,offset _KeyScan,seg _KeyScan,0x0d,0x0a
.CODE
.public _KeyScan
_KeyScan:	.proc
.debug
	.dw '.stabn 0x44,0,50,',0,0
	.dd LM7-_KeyScan
	.dw 0x0d,0x0a
.code
LM7:
	// total=2, vars=2
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=2
	bp=sp+1

	R1=BP+5
	[bp+1]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,51,',0,0
	.dd LM8-_KeyScan
	.dw 0x0d,0x0a
.code
LM8:
LBB2:
.debug
	.dw '.stabn 0x44,0,52,',0,0
	.dd LM9-_KeyScan
	.dw 0x0d,0x0a
.code
LM9:
	R2=[28677]	// QImode move
	R1=R2&255
	CMP R1,255	// QImode compare
	NSJNZ L4	//QImode NE
.debug
	.dw '.stabn 0x44,0,54,',0,0
	.dd LM10-_KeyScan
	.dw 0x0d,0x0a
.code
LM10:
	pc=L3	// Indirect jump
L4:
.debug
	.dw '.stabn 0x44,0,56,',0,0
	.dd LM11-_KeyScan
	.dw 0x0d,0x0a
.code
LM11:
	R1=[28677]	// QImode move
	R2=R1|(-256)
	[BP]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,57,',0,0
	.dd LM12-_KeyScan
	.dw 0x0d,0x0a
.code
LM12:
	R1=[BP]	// QImode move
	R2=R1^0xffff	// one_cmplqi2
	[BP]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,58,',0,0
	.dd LM13-_KeyScan
	.dw 0x0d,0x0a
.code
LM13:
	R1=[BP]	// QImode move
	CMP R1,8	// QImode compare
	NSJZ L14	//QImode EQ
	CMP R1,8	// QImode compare
	NSJG L21	//QImode GT
	CMP R1,2	// QImode compare
	NSJZ L17	//QImode EQ
	CMP R1,2	// QImode compare
	NSJG L22	//QImode GT
	CMP R1,1	// QImode compare
	NSJZ L18	//QImode EQ
	pc=L19	// Indirect jump
L22:
	CMP R1,4	// QImode compare
	NSJZ L16	//QImode EQ
	pc=L19	// Indirect jump
L21:
	CMP R1,32	// QImode compare
	NSJZ L10	//QImode EQ
	CMP R1,32	// QImode compare
	NSJG L23	//QImode GT
	CMP R1,16	// QImode compare
	NSJZ L12	//QImode EQ
	pc=L19	// Indirect jump
L23:
	CMP R1,64	// QImode compare
	NSJZ L8	//QImode EQ
	CMP R1,128	// QImode compare
	NSJZ L6	//QImode EQ
	pc=L19	// Indirect jump
L6:
.debug
	.dw '.stabn 0x44,0,61,',0,0
	.dd LM14-_KeyScan
	.dw 0x0d,0x0a
.code
LM14:
	R1=[_mode]	// QImode move
	R2=1	// QImode move
	[_mode]=R1+R2  //addqi3_Qrr
.debug
	.dw '.stabn 0x44,0,62,',0,0
	.dd LM15-_KeyScan
	.dw 0x0d,0x0a
.code
LM15:
	R1=[_mode]	// QImode move
	CMP R1,3	// QImode compare
	NSJNZ L7	//QImode NE
.debug
	.dw '.stabn 0x44,0,64,',0,0
	.dd LM16-_KeyScan
	.dw 0x0d,0x0a
.code
LM16:
	R1=0	// QImode move
	[_mode]=R1	// QImode move
L7:
.debug
	.dw '.stabn 0x44,0,66,',0,0
	.dd LM17-_KeyScan
	.dw 0x0d,0x0a
.code
LM17:
	pc=L5	// Indirect jump
L8:
.debug
	.dw '.stabn 0x44,0,68,',0,0
	.dd LM18-_KeyScan
	.dw 0x0d,0x0a
.code
LM18:
	R1=[_freq]	// QImode move
	R2=100	// QImode move
	[_freq]=R1+R2  //addqi3_Qrr
.debug
	.dw '.stabn 0x44,0,69,',0,0
	.dd LM19-_KeyScan
	.dw 0x0d,0x0a
.code
LM19:
	R1=[_freq]	// QImode move
	CMP R1,8999	// QImode compare
	NSJNA L9	//QImode LEU
.debug
	.dw '.stabn 0x44,0,71,',0,0
	.dd LM20-_KeyScan
	.dw 0x0d,0x0a
.code
LM20:
	R1=100	// QImode move
	[_freq]=R1	// QImode move
L9:
.debug
	.dw '.stabn 0x44,0,73,',0,0
	.dd LM21-_KeyScan
	.dw 0x0d,0x0a
.code
LM21:
	pc=L5	// Indirect jump
L10:
.debug
	.dw '.stabn 0x44,0,75,',0,0
	.dd LM22-_KeyScan
	.dw 0x0d,0x0a
.code
LM22:
	R1=[_freq]	// QImode move
	R2=(-100)	// QImode move
	[_freq]=R1+R2  //addqi3_Qrr
.debug
	.dw '.stabn 0x44,0,76,',0,0
	.dd LM23-_KeyScan
	.dw 0x0d,0x0a
.code
LM23:
	R1=[_freq]	// QImode move
	CMP R1,199	// QImode compare
	NSJA L11	//QImode GTU
.debug
	.dw '.stabn 0x44,0,78,',0,0
	.dd LM24-_KeyScan
	.dw 0x0d,0x0a
.code
LM24:
	R1=9000	// QImode move
	[_freq]=R1	// QImode move
L11:
.debug
	.dw '.stabn 0x44,0,80,',0,0
	.dd LM25-_KeyScan
	.dw 0x0d,0x0a
.code
LM25:
	pc=L5	// Indirect jump
L12:
.debug
	.dw '.stabn 0x44,0,82,',0,0
	.dd LM26-_KeyScan
	.dw 0x0d,0x0a
.code
LM26:
	R1=[_vol]	// QImode move
	CMP R1,50	// QImode compare
	NSJNZ L13	//QImode NE
.debug
	.dw '.stabn 0x44,0,84,',0,0
	.dd LM27-_KeyScan
	.dw 0x0d,0x0a
.code
LM27:
	R1=0	// QImode move
	[_vol]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,85,',0,0
	.dd LM28-_KeyScan
	.dw 0x0d,0x0a
.code
LM28:
	pc=L5	// Indirect jump
L13:
.debug
	.dw '.stabn 0x44,0,87,',0,0
	.dd LM29-_KeyScan
	.dw 0x0d,0x0a
.code
LM29:
	R1=[_vol]	// QImode move
	R2=1	// QImode move
	[_vol]=R1+R2  //addqi3_Qrr
.debug
	.dw '.stabn 0x44,0,88,',0,0
	.dd LM30-_KeyScan
	.dw 0x0d,0x0a
.code
LM30:
	pc=L5	// Indirect jump
L14:
.debug
	.dw '.stabn 0x44,0,90,',0,0
	.dd LM31-_KeyScan
	.dw 0x0d,0x0a
.code
LM31:
	R1=[_vol]	// QImode move
	CMP R1,0	// QImode test
	NSJNZ L15	//QImode NE
.debug
	.dw '.stabn 0x44,0,92,',0,0
	.dd LM32-_KeyScan
	.dw 0x0d,0x0a
.code
LM32:
	R1=50	// QImode move
	[_vol]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,93,',0,0
	.dd LM33-_KeyScan
	.dw 0x0d,0x0a
.code
LM33:
	pc=L5	// Indirect jump
L15:
.debug
	.dw '.stabn 0x44,0,95,',0,0
	.dd LM34-_KeyScan
	.dw 0x0d,0x0a
.code
LM34:
	R1=[_vol]	// QImode move
	R2=(-1)	// QImode move
	[_vol]=R1+R2  //addqi3_Qrr
.debug
	.dw '.stabn 0x44,0,96,',0,0
	.dd LM35-_KeyScan
	.dw 0x0d,0x0a
.code
LM35:
	pc=L5	// Indirect jump
L16:
.debug
	.dw '.stabn 0x44,0,98,',0,0
	.dd LM36-_KeyScan
	.dw 0x0d,0x0a
.code
LM36:
	R1=778	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,99,',0,0
	.dd LM37-_KeyScan
	.dw 0x0d,0x0a
.code
LM37:
	R1=1802	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,100,',0,0
	.dd LM38-_KeyScan
	.dw 0x0d,0x0a
.code
LM38:
	pc=L5	// Indirect jump
L17:
.debug
	.dw '.stabn 0x44,0,102,',0,0
	.dd LM39-_KeyScan
	.dw 0x0d,0x0a
.code
LM39:
	R1=783	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,103,',0,0
	.dd LM40-_KeyScan
	.dw 0x0d,0x0a
.code
LM40:
	R1=1807	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,104,',0,0
	.dd LM41-_KeyScan
	.dw 0x0d,0x0a
.code
LM41:
	pc=L5	// Indirect jump
L18:
.debug
	.dw '.stabn 0x44,0,106,',0,0
	.dd LM42-_KeyScan
	.dw 0x0d,0x0a
.code
LM42:
	R1=3841	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,107,',0,0
	.dd LM43-_KeyScan
	.dw 0x0d,0x0a
.code
LM43:
	pc=L3	// Indirect jump
L19:
.debug
	.dw '.stabn 0x44,0,109,',0,0
	.dd LM44-_KeyScan
	.dw 0x0d,0x0a
.code
LM44:
	pc=L5	// Indirect jump
L5:
.debug
	.dw '.stabn 0x44,0,111,',0,0
	.dd LM45-_KeyScan
	.dw 0x0d,0x0a
.code
LM45:
	R1=3840	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,112,',0,0
	.dd LM46-_KeyScan
	.dw 0x0d,0x0a
.code
LM46:
	R1=[_vol]	// QImode move
	[SP--]=R1	// QImode move
	R1=[_freq]	// QImode move
	[SP--]=R1	// QImode move
	R1=[_mode]	// QImode move
	[SP--]=R1	// QImode move
	call _show	// call without return value
	SP = SP + 3	//SP
.debug
	.dw '.stabn 0x44,0,113,',0,0
	.dd LM47-_KeyScan
	.dw 0x0d,0x0a
.code
LM47:
LBE2:
.debug
	.dw '.stabn 0x44,0,113,',0,0
	.dd LM48-_KeyScan
	.dw 0x0d,0x0a
.code
LM48:
L3:

	sp+=2
	pop bp from [sp]
	retf
	.endp	// end of KeyScan

.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB2-_KeyScan
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "temp:1",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE2-_KeyScan
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME2-_KeyScan
	.dw 0x0d,0x0a
.code
LME2:
.code
.debug
	.dw '.stabs "sendword:F19",36,0,0,',0,0,offset _sendword,seg _sendword,0x0d,0x0a
.CODE
.public _sendword
_sendword:	.proc
.debug
	.dw '.stabs "G:/key/my7219.h",0x84,0,0,',0,0,offset Ltext2, seg Ltext2,0x0d,0x0a
.code
.code
Ltext2:
.debug
	.dw '.stabn 0x44,0,36,',0,0
	.dd LM49-_sendword
	.dw 0x0d,0x0a
.code
LM49:
	// total=2, vars=2
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=2
	bp=sp+1

	R1=BP+5
.debug
	.dw '.stabn 0x44,0,37,',0,0
	.dd LM50-_sendword
	.dw 0x0d,0x0a
.code
LM50:
LBB3:
.debug
	.dw '.stabn 0x44,0,38,',0,0
	.dd LM51-_sendword
	.dw 0x0d,0x0a
.code
LM51:
	R2=[28677]	// QImode move
	R3=R2&(-16385)
	[28677]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,39,',0,0
	.dd LM52-_sendword
	.dw 0x0d,0x0a
.code
LM52:
	R2=0	// QImode move
	[BP]=R2	// QImode move
L42:
	R2=[BP]	// QImode move
	CMP R2,15	// QImode compare
	NSJNG L45	//QImode LE
	pc=L43	// Indirect jump
L45:
.debug
	.dw '.stabn 0x44,0,41,',0,0
	.dd LM53-_sendword
	.dw 0x0d,0x0a
.code
LM53:
	R2=1	// QImode move
	[28690]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,42,',0,0
	.dd LM54-_sendword
	.dw 0x0d,0x0a
.code
LM54:
	R2=BP	// QImode move
	R3=BP+1
	R2=R1	// QImode move
	R2=[R2]	// QImode move
	R4=R2&(-32768)
	R2=R3	// QImode move
	[R2]=R4	// QImode move
.debug
	.dw '.stabn 0x44,0,43,',0,0
	.dd LM55-_sendword
	.dw 0x0d,0x0a
.code
LM55:
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	R3=R2 lsl 1
	R4=R1	// QImode move
	[R4]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,44,',0,0
	.dd LM56-_sendword
	.dw 0x0d,0x0a
.code
LM56:
	R2=BP	// QImode move
	R3=BP+1
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	CMP R2,0	// QImode test
	NSJZ L46	//QImode EQ
.debug
	.dw '.stabn 0x44,0,46,',0,0
	.dd LM57-_sendword
	.dw 0x0d,0x0a
.code
LM57:
	R2=[28677]	// QImode move
	R3=R2|(-32768)
	[28677]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,47,',0,0
	.dd LM58-_sendword
	.dw 0x0d,0x0a
.code
LM58:
	R2=[28677]	// QImode move
	R3=R2&(-8193)
	[28677]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,48,',0,0
	.dd LM59-_sendword
	.dw 0x0d,0x0a
.code
LM59:
	R2=[28677]	// QImode move
	R3=R2|8192
	[28677]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,49,',0,0
	.dd LM60-_sendword
	.dw 0x0d,0x0a
.code
LM60:
	pc=L44	// Indirect jump
L46:
.debug
	.dw '.stabn 0x44,0,52,',0,0
	.dd LM61-_sendword
	.dw 0x0d,0x0a
.code
LM61:
	R2=[28677]	// QImode move
	R3=R2&32767
	[28677]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,53,',0,0
	.dd LM62-_sendword
	.dw 0x0d,0x0a
.code
LM62:
	R2=[28677]	// QImode move
	R3=R2&(-8193)
	[28677]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,54,',0,0
	.dd LM63-_sendword
	.dw 0x0d,0x0a
.code
LM63:
	R2=[28677]	// QImode move
	R3=R2|8192
	[28677]=R3	// QImode move
L47:
.debug
	.dw '.stabn 0x44,0,39,',0,0
	.dd LM64-_sendword
	.dw 0x0d,0x0a
.code
LM64:
L44:
	R2=[BP]	// QImode move
	R3=R2+1
	[BP]=R3	// QImode move
	pc=L42	// Indirect jump
L43:
.debug
	.dw '.stabn 0x44,0,57,',0,0
	.dd LM65-_sendword
	.dw 0x0d,0x0a
.code
LM65:
	R2=[28677]	// QImode move
	R3=R2|16384
	[28677]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,58,',0,0
	.dd LM66-_sendword
	.dw 0x0d,0x0a
.code
LM66:
	R2=1	// QImode move
	[28690]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,59,',0,0
	.dd LM67-_sendword
	.dw 0x0d,0x0a
.code
LM67:
LBE3:
.debug
	.dw '.stabn 0x44,0,59,',0,0
	.dd LM68-_sendword
	.dw 0x0d,0x0a
.code
LM68:
L41:

	sp+=2
	pop bp from [sp]
	retf
	.endp	// end of sendword

.debug
	.dw '.stabs "word:p4",160,0,0,5',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB3-_sendword
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "i:1",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "temp:1",128,0,0,1',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE3-_sendword
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME3-_sendword
	.dw 0x0d,0x0a
.code
LME3:
.code
.debug
	.dw '.stabs "init7219:F19",36,0,0,',0,0,offset _init7219,seg _init7219,0x0d,0x0a
.CODE
.public _init7219
_init7219:	.proc
.debug
	.dw '.stabn 0x44,0,61,',0,0
	.dd LM69-_init7219
	.dw 0x0d,0x0a
.code
LM69:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,62,',0,0
	.dd LM70-_init7219
	.dw 0x0d,0x0a
.code
LM70:
	R1=[28679]	// QImode move
	R2=R1|(-4096)
	[28679]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,63,',0,0
	.dd LM71-_init7219
	.dw 0x0d,0x0a
.code
LM71:
	R1=[28680]	// QImode move
	R2=R1|(-4096)
	[28680]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,64,',0,0
	.dd LM72-_init7219
	.dw 0x0d,0x0a
.code
LM72:
	R1=[28677]	// QImode move
	R2=R1&4095
	[28677]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,65,',0,0
	.dd LM73-_init7219
	.dw 0x0d,0x0a
.code
LM73:
	R1=2823	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,66,',0,0
	.dd LM74-_init7219
	.dw 0x0d,0x0a
.code
LM74:
	R1=2559	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,67,',0,0
	.dd LM75-_init7219
	.dw 0x0d,0x0a
.code
LM75:
	R1=2570	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,68,',0,0
	.dd LM76-_init7219
	.dw 0x0d,0x0a
.code
LM76:
	R1=3073	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,69,',0,0
	.dd LM77-_init7219
	.dw 0x0d,0x0a
.code
LM77:
	R1=3841	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,70,',0,0
	.dd LM78-_init7219
	.dw 0x0d,0x0a
.code
LM78:
	R1=3840	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,71,',0,0
	.dd LM79-_init7219
	.dw 0x0d,0x0a
.code
LM79:
.debug
	.dw '.stabn 0x44,0,71,',0,0
	.dd LM80-_init7219
	.dw 0x0d,0x0a
.code
LM80:
L50:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of init7219

.debug
	.dw '.stabf ',0,0
	.dd LME4-_init7219
	.dw 0x0d,0x0a
.code
LME4:
.code
.debug
	.dw '.stabs "show:F19",36,0,0,',0,0,offset _show,seg _show,0x0d,0x0a
.CODE
.public _show
_show:	.proc
.debug
	.dw '.stabn 0x44,0,80,',0,0
	.dd LM81-_show
	.dw 0x0d,0x0a
.code
LM81:
	// total=14, vars=14
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=14
	bp=sp+1

	R1=BP+17
	[bp+8]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,81,',0,0
	.dd LM82-_show
	.dw 0x0d,0x0a
.code
LM82:
LBB4:
.debug
	.dw '.stabn 0x44,0,83,',0,0
	.dd LM83-_show
	.dw 0x0d,0x0a
.code
LM83:
	R1=[28679]	// QImode move
	R2=R1|(-4096)
	[28679]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,84,',0,0
	.dd LM84-_show
	.dw 0x0d,0x0a
.code
LM84:
	R1=[28680]	// QImode move
	R2=R1|(-4096)
	[28680]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,85,',0,0
	.dd LM85-_show
	.dw 0x0d,0x0a
.code
LM85:
	R1=[28677]	// QImode move
	R2=R1&4095
	[28677]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,86,',0,0
	.dd LM86-_show
	.dw 0x0d,0x0a
.code
LM86:
	R1=2823	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,87,',0,0
	.dd LM87-_show
	.dw 0x0d,0x0a
.code
LM87:
	R1=2559	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,88,',0,0
	.dd LM88-_show
	.dw 0x0d,0x0a
.code
LM88:
	R1=2570	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,89,',0,0
	.dd LM89-_show
	.dw 0x0d,0x0a
.code
LM89:
	R1=3073	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,91,',0,0
	.dd LM90-_show
	.dw 0x0d,0x0a
.code
LM90:
	R2=[bp+8]	// QImode move
	R1=[R2]	// QImode move
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,92,',0,0
	.dd LM91-_show
	.dw 0x0d,0x0a
.code
LM91:
	R1=BP	// QImode move
	R3=BP+2
	[bp+9]=R3	// QImode move
	R1=[bp+8]	// QImode move
	R4=[bp+8]	// QImode move
	R2=R4+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	R2=10000	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __divi1	// call with return value
	SP = SP + 2	//SP
	R4=[bp+9]	// QImode move
	[R4]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,93,',0,0
	.dd LM92-_show
	.dw 0x0d,0x0a
.code
LM92:
	R1=BP	// QImode move
	R1=BP+3
	[bp+10]=R1	// QImode move
	R1=[bp+8]	// QImode move
	R3=[bp+8]	// QImode move
	R2=R3+1
	R4=R2	// QImode move
	R1=[R4]	// QImode move
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
	R2=[bp+10]	// QImode move
	[R2]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,94,',0,0
	.dd LM93-_show
	.dw 0x0d,0x0a
.code
LM93:
	R2=BP	// QImode move
	R1=BP+3
	R2=BP	// QImode move
	R3=BP+3
	R4=R3	// QImode move
	R4=[R4]	// QImode move
	R2=R4|128
	R4=R1	// QImode move
	[R4]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,95,',0,0
	.dd LM94-_show
	.dw 0x0d,0x0a
.code
LM94:
	R1=BP	// QImode move
	R1=BP+4
	[bp+11]=R1	// QImode move
	R1=[bp+8]	// QImode move
	R3=[bp+8]	// QImode move
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
	R2=[bp+11]	// QImode move
	[R2]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,96,',0,0
	.dd LM95-_show
	.dw 0x0d,0x0a
.code
LM95:
	R1=BP	// QImode move
	R3=BP+6
	[bp+12]=R3	// QImode move
	R1=[bp+8]	// QImode move
	R4=[bp+8]	// QImode move
	R2=R4+2
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	R2=10	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __divi1	// call with return value
	SP = SP + 2	//SP
	R2=R1|128
	R4=[bp+12]	// QImode move
	[R4]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,97,',0,0
	.dd LM96-_show
	.dw 0x0d,0x0a
.code
LM96:
	R1=BP	// QImode move
	R3=BP+7
	[bp+13]=R3	// QImode move
	R1=[bp+8]	// QImode move
	R4=[bp+8]	// QImode move
	R2=R4+2
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	R2=10	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __modi1	// call with return value
	SP = SP + 2	//SP
	R4=[bp+13]	// QImode move
	[R4]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,98,',0,0
	.dd LM97-_show
	.dw 0x0d,0x0a
.code
LM97:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,99,',0,0
	.dd LM98-_show
	.dw 0x0d,0x0a
.code
LM98:
	R2=[BP]	// QImode move
	R1=R2|2048
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,100,',0,0
	.dd LM99-_show
	.dw 0x0d,0x0a
.code
LM99:
	R1=BP	// QImode move
	R2=BP+2
	R3=R2	// QImode move
	R3=[R3]	// QImode move
	R1=R3|1536
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,101,',0,0
	.dd LM100-_show
	.dw 0x0d,0x0a
.code
LM100:
	R1=BP	// QImode move
	R2=BP+3
	R4=R2	// QImode move
	R4=[R4]	// QImode move
	R1=R4|1280
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,102,',0,0
	.dd LM101-_show
	.dw 0x0d,0x0a
.code
LM101:
	R1=BP	// QImode move
	R2=BP+4
	R3=R2	// QImode move
	R3=[R3]	// QImode move
	R1=R3|1024
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,103,',0,0
	.dd LM102-_show
	.dw 0x0d,0x0a
.code
LM102:
	R1=BP	// QImode move
	R2=BP+6
	R4=R2	// QImode move
	R4=[R4]	// QImode move
	R1=R4|512
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,104,',0,0
	.dd LM103-_show
	.dw 0x0d,0x0a
.code
LM103:
	R1=BP	// QImode move
	R2=BP+7
	R3=R2	// QImode move
	R3=[R3]	// QImode move
	R1=R3|256
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,105,',0,0
	.dd LM104-_show
	.dw 0x0d,0x0a
.code
LM104:
LBE4:
.debug
	.dw '.stabn 0x44,0,105,',0,0
	.dd LM105-_show
	.dw 0x0d,0x0a
.code
LM105:
L51:

	sp+=14
	pop bp from [sp]
	retf
	.endp	// end of show

.debug
	.dw '.stabs "mode:p1",160,0,0,17',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "freq:p1",160,0,0,18',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "mvol:p1",160,0,0,19',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB4-_show
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "tmp:20=ar1;0;7;1",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE4-_show
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME5-_show
	.dw 0x0d,0x0a
.code
LME5:
.code
.debug
	.dw '.stabs "wave_init:F19",36,0,0,',0,0,offset _wave_init,seg _wave_init,0x0d,0x0a
.CODE
.public _wave_init
_wave_init:	.proc
.debug
	.dw '.stabs "G:/key/wave.h",0x84,0,0,',0,0,offset Ltext3, seg Ltext3,0x0d,0x0a
.code
.code
Ltext3:
.debug
	.dw '.stabn 0x44,0,7,',0,0
	.dd LM106-_wave_init
	.dw 0x0d,0x0a
.code
LM106:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,8,',0,0
	.dd LM107-_wave_init
	.dw 0x0d,0x0a
.code
LM107:
	R2=0	// QImode move
	[28714]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,9,',0,0
	.dd LM108-_wave_init
	.dw 0x0d,0x0a
.code
LM108:
.debug
	.dw '.stabn 0x44,0,9,',0,0
	.dd LM109-_wave_init
	.dw 0x0d,0x0a
.code
LM109:
L52:

	pop bp from [sp]
	retf
	.endp	// end of wave_init

.debug
	.dw '.stabf ',0,0
	.dd LME6-_wave_init
	.dw 0x0d,0x0a
.code
LME6:
.code
.debug
	.dw '.stabs "wave:F19",36,0,0,',0,0,offset _wave,seg _wave,0x0d,0x0a
.CODE
.public _wave
_wave:	.proc
.debug
	.dw '.stabn 0x44,0,11,',0,0
	.dd LM110-_wave
	.dw 0x0d,0x0a
.code
LM110:
	// total=2, vars=2
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=2
	bp=sp+1

	R1=BP+5
	[bp+1]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,12,',0,0
	.dd LM111-_wave
	.dw 0x0d,0x0a
.code
LM111:
LBB5:
.debug
	.dw '.stabn 0x44,0,13,',0,0
	.dd LM112-_wave
	.dw 0x0d,0x0a
.code
LM112:
	R1=[_mode]	// QImode move
	CMP R1,0	// QImode test
	NSJNZ L54	//QImode NE
.debug
	.dw '.stabn 0x44,0,15,',0,0
	.dd LM113-_wave
	.dw 0x0d,0x0a
.code
LM113:
	R1=0	// QImode move
	[BP]=R1	// QImode move
L55:
	R1=[BP]	// QImode move
	CMP R1,255	// QImode compare
	NSJNG L58	//QImode LE
	pc=L54	// Indirect jump
L58:
.debug
	.dw '.stabn 0x44,0,17,',0,0
	.dd LM114-_wave
	.dw 0x0d,0x0a
.code
LM114:
	R1=_SINE	// QImode move
	R2=[BP]	// QImode move
	R1 = R1 + R2	//addqi3
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	R1=R2 lsl 1
	R2=[_vol]	// QImode move
	mr=R1*R2	// r3=R1*R2 16bit=16bit*16bit
	[28695]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,18,',0,0
	.dd LM115-_wave
	.dw 0x0d,0x0a
.code
LM115:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,15,',0,0
	.dd LM116-_wave
	.dw 0x0d,0x0a
.code
LM116:
L57:
	R1=[BP]	// QImode move
	R2=R1+1
	[BP]=R2	// QImode move
	pc=L55	// Indirect jump
L56:
L54:
.debug
	.dw '.stabn 0x44,0,21,',0,0
	.dd LM117-_wave
	.dw 0x0d,0x0a
.code
LM117:
	R1=[_mode]	// QImode move
	CMP R1,1	// QImode compare
	NSJNZ L59	//QImode NE
.debug
	.dw '.stabn 0x44,0,23,',0,0
	.dd LM118-_wave
	.dw 0x0d,0x0a
.code
LM118:
	R1=0	// QImode move
	[BP]=R1	// QImode move
L60:
	R1=[BP]	// QImode move
	CMP R1,99	// QImode compare
	NSJNG L63	//QImode LE
	pc=L61	// Indirect jump
L63:
.debug
	.dw '.stabn 0x44,0,25,',0,0
	.dd LM119-_wave
	.dw 0x0d,0x0a
.code
LM119:
	R1=[_vol]	// QImode move
	R2=20	// QImode move
	mr=R1*R2	// r3=R1*R2 16bit=16bit*16bit
	R1=R3 lsl 2
	R1=R1 lsl 4
	[28695]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,26,',0,0
	.dd LM120-_wave
	.dw 0x0d,0x0a
.code
LM120:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,23,',0,0
	.dd LM121-_wave
	.dw 0x0d,0x0a
.code
LM121:
L62:
	R1=[BP]	// QImode move
	R2=R1+1
	[BP]=R2	// QImode move
	pc=L60	// Indirect jump
L61:
.debug
	.dw '.stabn 0x44,0,28,',0,0
	.dd LM122-_wave
	.dw 0x0d,0x0a
.code
LM122:
	R1=100	// QImode move
	[BP]=R1	// QImode move
L64:
	R1=[BP]	// QImode move
	CMP R1,199	// QImode compare
	NSJNG L67	//QImode LE
	pc=L59	// Indirect jump
L67:
.debug
	.dw '.stabn 0x44,0,30,',0,0
	.dd LM123-_wave
	.dw 0x0d,0x0a
.code
LM123:
	R1=0	// QImode move
	[28695]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,31,',0,0
	.dd LM124-_wave
	.dw 0x0d,0x0a
.code
LM124:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,28,',0,0
	.dd LM125-_wave
	.dw 0x0d,0x0a
.code
LM125:
L66:
	R1=[BP]	// QImode move
	R2=R1+1
	[BP]=R2	// QImode move
	pc=L64	// Indirect jump
L65:
L59:
.debug
	.dw '.stabn 0x44,0,34,',0,0
	.dd LM126-_wave
	.dw 0x0d,0x0a
.code
LM126:
	R1=[_mode]	// QImode move
	CMP R1,2	// QImode compare
	NSJNZ L68	//QImode NE
.debug
	.dw '.stabn 0x44,0,36,',0,0
	.dd LM127-_wave
	.dw 0x0d,0x0a
.code
LM127:
	R1=0	// QImode move
	[BP]=R1	// QImode move
L69:
	R1=[BP]	// QImode move
	CMP R1,99	// QImode compare
	NSJNG L72	//QImode LE
	pc=L70	// Indirect jump
L72:
.debug
	.dw '.stabn 0x44,0,38,',0,0
	.dd LM128-_wave
	.dw 0x0d,0x0a
.code
LM128:
	R1=[BP]	// QImode move
	R2=[_vol]	// QImode move
	mr=R1*R2	// r3=R1*R2 16bit=16bit*16bit
	R1=5	// QImode move
	[SP--]=R1	// QImode move
	[SP--]=R3	// QImode move
	call __divu1	// call with return value
	SP = SP + 2	//SP
	R2=R1 lsl 2
	R2=R2 lsl 4
	[28695]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,39,',0,0
	.dd LM129-_wave
	.dw 0x0d,0x0a
.code
LM129:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,36,',0,0
	.dd LM130-_wave
	.dw 0x0d,0x0a
.code
LM130:
L71:
	R1=[BP]	// QImode move
	R2=R1+1
	[BP]=R2	// QImode move
	pc=L69	// Indirect jump
L70:
.debug
	.dw '.stabn 0x44,0,41,',0,0
	.dd LM131-_wave
	.dw 0x0d,0x0a
.code
LM131:
	R1=100	// QImode move
	[BP]=R1	// QImode move
L73:
	R1=[BP]	// QImode move
	CMP R1,0	// QImode test
	NSJG L76	//QImode GT
	pc=L68	// Indirect jump
L76:
.debug
	.dw '.stabn 0x44,0,43,',0,0
	.dd LM132-_wave
	.dw 0x0d,0x0a
.code
LM132:
	R1=[BP]	// QImode move
	R2=[_vol]	// QImode move
	mr=R1*R2	// r3=R1*R2 16bit=16bit*16bit
	R1=5	// QImode move
	[SP--]=R1	// QImode move
	[SP--]=R3	// QImode move
	call __divu1	// call with return value
	SP = SP + 2	//SP
	R2=R1 lsl 2
	R2=R2 lsl 4
	[28695]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,44,',0,0
	.dd LM133-_wave
	.dw 0x0d,0x0a
.code
LM133:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,41,',0,0
	.dd LM134-_wave
	.dw 0x0d,0x0a
.code
LM134:
L75:
	R1=[BP]	// QImode move
	R2=R1+(-1)
	[BP]=R2	// QImode move
	pc=L73	// Indirect jump
L74:
L68:
.debug
	.dw '.stabn 0x44,0,47,',0,0
	.dd LM135-_wave
	.dw 0x0d,0x0a
.code
LM135:
LBE5:
.debug
	.dw '.stabn 0x44,0,47,',0,0
	.dd LM136-_wave
	.dw 0x0d,0x0a
.code
LM136:
L53:

	sp+=2
	pop bp from [sp]
	retf
	.endp	// end of wave

.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB5-_wave
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "i:1",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE5-_wave
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME7-_wave
	.dw 0x0d,0x0a
.code
LME7:
.debug
	.dw '.stabs "mode:G4",32,0,0,',0,0,offset _mode,seg _mode,0x0d,0x0a
.CODE
.debug
	.dw '.stabs "freq:G4",32,0,0,',0,0,offset _freq,seg _freq,0x0d,0x0a
.CODE
.debug
	.dw '.stabs "vol:G4",32,0,0,',0,0,offset _vol,seg _vol,0x0d,0x0a
.CODE
.public _SINE
.iram
_SINE:
	.dw 400
	.dw 410
	.dw 420
	.dw 429
	.dw 439
	.dw 449
	.dw 459
	.dw 468
	.dw 478
	.dw 488
	.dw 497
	.dw 507
	.dw 516
	.dw 525
	.dw 535
	.dw 544
	.dw 553
	.dw 562
	.dw 571
	.dw 580
	.dw 589
	.dw 597
	.dw 606
	.dw 614
	.dw 622
	.dw 630
	.dw 638
	.dw 646
	.dw 654
	.dw 661
	.dw 669
	.dw 676
	.dw 683
	.dw 690
	.dw 696
	.dw 703
	.dw 709
	.dw 715
	.dw 721
	.dw 727
	.dw 733
	.dw 738
	.dw 743
	.dw 748
	.dw 753
	.dw 757
	.dw 762
	.dw 766
	.dw 770
	.dw 773
	.dw 777
	.dw 780
	.dw 783
	.dw 786
	.dw 788
	.dw 790
	.dw 792
	.dw 794
	.dw 796
	.dw 797
	.dw 798
	.dw 799
	.dw 800
	.dw 800
	.dw 800
	.dw 800
	.dw 800
	.dw 799
	.dw 798
	.dw 797
	.dw 796
	.dw 794
	.dw 792
	.dw 790
	.dw 788
	.dw 786
	.dw 783
	.dw 780
	.dw 777
	.dw 773
	.dw 770
	.dw 766
	.dw 762
	.dw 757
	.dw 753
	.dw 748
	.dw 743
	.dw 738
	.dw 733
	.dw 727
	.dw 721
	.dw 715
	.dw 709
	.dw 703
	.dw 696
	.dw 690
	.dw 683
	.dw 676
	.dw 669
	.dw 661
	.dw 654
	.dw 646
	.dw 638
	.dw 630
	.dw 622
	.dw 614
	.dw 606
	.dw 597
	.dw 589
	.dw 580
	.dw 571
	.dw 562
	.dw 553
	.dw 544
	.dw 535
	.dw 525
	.dw 516
	.dw 507
	.dw 497
	.dw 488
	.dw 478
	.dw 468
	.dw 459
	.dw 449
	.dw 439
	.dw 429
	.dw 420
	.dw 410
	.dw 400
	.dw 390
	.dw 380
	.dw 371
	.dw 361
	.dw 351
	.dw 341
	.dw 332
	.dw 322
	.dw 312
	.dw 303
	.dw 293
	.dw 284
	.dw 275
	.dw 265
	.dw 256
	.dw 247
	.dw 238
	.dw 229
	.dw 220
	.dw 211
	.dw 203
	.dw 194
	.dw 186
	.dw 178
	.dw 170
	.dw 162
	.dw 154
	.dw 146
	.dw 139
	.dw 131
	.dw 124
	.dw 117
	.dw 110
	.dw 104
	.dw 97
	.dw 91
	.dw 85
	.dw 79
	.dw 73
	.dw 67
	.dw 62
	.dw 57
	.dw 52
	.dw 47
	.dw 43
	.dw 38
	.dw 34
	.dw 30
	.dw 27
	.dw 23
	.dw 20
	.dw 17
	.dw 14
	.dw 12
	.dw 10
	.dw 8
	.dw 6
	.dw 4
	.dw 3
	.dw 2
	.dw 1
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 1
	.dw 2
	.dw 3
	.dw 4
	.dw 6
	.dw 8
	.dw 10
	.dw 12
	.dw 14
	.dw 17
	.dw 20
	.dw 23
	.dw 27
	.dw 30
	.dw 34
	.dw 38
	.dw 43
	.dw 47
	.dw 52
	.dw 57
	.dw 62
	.dw 67
	.dw 73
	.dw 79
	.dw 85
	.dw 91
	.dw 97
	.dw 104
	.dw 110
	.dw 117
	.dw 124
	.dw 131
	.dw 139
	.dw 146
	.dw 154
	.dw 162
	.dw 170
	.dw 178
	.dw 186
	.dw 194
	.dw 203
	.dw 211
	.dw 220
	.dw 229
	.dw 238
	.dw 247
	.dw 256
	.dw 265
	.dw 275
	.dw 284
	.dw 293
	.dw 303
	.dw 312
	.dw 322
	.dw 332
	.dw 341
	.dw 351
	.dw 361
	.dw 371
	.dw 380
	.dw 390
.debug
	.dw '.stabs "SINE:G21=ar1;0;255;4",32,0,0,',0,0,offset _SINE,seg _SINE,0x0d,0x0a
.CODE
.code
.debug
	.dw '.stabs "main:F1",36,0,0,',0,0,offset _main,seg _main,0x0d,0x0a
.CODE
.public _main
_main:	.proc
.debug
	.dw '.stabs "G:/key/main.c",0x84,0,0,',0,0,offset Ltext4, seg Ltext4,0x0d,0x0a
.code
.code
Ltext4:
.debug
	.dw '.stabn 0x44,0,35,',0,0
	.dd LM137-_main
	.dw 0x0d,0x0a
.code
LM137:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,38,',0,0
	.dd LM138-_main
	.dw 0x0d,0x0a
.code
LM138:
	R1=0	// QImode move
	[_mode]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,39,',0,0
	.dd LM139-_main
	.dw 0x0d,0x0a
.code
LM139:
	R1=100	// QImode move
	[_freq]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,40,',0,0
	.dd LM140-_main
	.dw 0x0d,0x0a
.code
LM140:
	R1=30	// QImode move
	[_vol]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,41,',0,0
	.dd LM141-_main
	.dw 0x0d,0x0a
.code
LM141:
	call _init7219	// call without return value
.debug
	.dw '.stabn 0x44,0,42,',0,0
	.dd LM142-_main
	.dw 0x0d,0x0a
.code
LM142:
	call _wave_init	// call without return value
.debug
	.dw '.stabn 0x44,0,43,',0,0
	.dd LM143-_main
	.dw 0x0d,0x0a
.code
LM143:
	R1=[_vol]	// QImode move
	[SP--]=R1	// QImode move
	R1=[_freq]	// QImode move
	[SP--]=R1	// QImode move
	R1=[_mode]	// QImode move
	[SP--]=R1	// QImode move
	call _show	// call without return value
	SP = SP + 3	//SP
.debug
	.dw '.stabn 0x44,0,44,',0,0
	.dd LM144-_main
	.dw 0x0d,0x0a
.code
LM144:
L86:
	pc=L88	// Indirect jump
	pc=L87	// Indirect jump
L88:
.debug
	.dw '.stabn 0x44,0,46,',0,0
	.dd LM145-_main
	.dw 0x0d,0x0a
.code
LM145:
	call _KeyScan	// call without return value
.debug
	.dw '.stabn 0x44,0,48,',0,0
	.dd LM146-_main
	.dw 0x0d,0x0a
.code
LM146:
	call _wave	// call without return value
.debug
	.dw '.stabn 0x44,0,49,',0,0
	.dd LM147-_main
	.dw 0x0d,0x0a
.code
LM147:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,50,',0,0
	.dd LM148-_main
	.dw 0x0d,0x0a
.code
LM148:
	pc=L86	// Indirect jump
L87:
.debug
	.dw '.stabn 0x44,0,51,',0,0
	.dd LM149-_main
	.dw 0x0d,0x0a
.code
LM149:
.debug
	.dw '.stabn 0x44,0,51,',0,0
	.dd LM150-_main
	.dw 0x0d,0x0a
.code
LM150:
L85:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of main

.debug
	.dw '.stabf ',0,0
	.dd LME8-_main
	.dw 0x0d,0x0a
.code
LME8:
.iram
.public _mode
_mode:
	.dw 0
.iram
.public _freq
_freq:
	.dw 0
.iram
.public _vol
_vol:
	.dw 0
.external __divu1
.external __modi1
.external __divi1
	.end

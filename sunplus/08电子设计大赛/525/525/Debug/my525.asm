// GCC for SUNPLUS u'nSP version 1.0.21-3
// Command: C:\PROGRA~1\Sunplus\UNSPID~1.0\cc1.exe C:\DOCUME~1\ADMINI~1\LOCALS~1\Temp\ccQZaaaa.i -fkeep-inline-functions -quiet -dumpbase my525.c -mglobal-var-iram -gstabs -Wall -o .\Debug/my525.asm
	.external __sn_func_ptr_sec

// gcc2_compiled.:

.debug
	.dw '.stabs "C:/Documents and Settings/Administrator/×ÀÃæ/¸öÈË¹¤³ÌÎÄ¼þ¼Ð/ÕÔÓÀ¿Æ/525/",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
.code
.debug
	.dw '.stabs "C:/Documents and Settings/Administrator/×/300Ã/346/¸/366È/313¹/244³/314Î/304¼/376¼/320/Õ/324Ó/300¿/306/525/my525.c",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
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
	.dw '.stabs "send525:F19",36,0,0,',0,0,offset _send525,seg _send525,0x0d,0x0a
.CODE
.public _send525
_send525:	.proc
.debug
	.dw '.stabs "C:/Documents and Settings/Administrator/×/300Ã/346/¸/366È/313¹/244³/314Î/304¼/376¼/320/Õ/324Ó/300¿/306/525/my525.h",0x84,0,0,',0,0,offset Ltext1, seg Ltext1,0x0d,0x0a
.code
.code
Ltext1:
.debug
	.dw '.stabn 0x44,0,30,',0,0
	.dd LM1-_send525
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
	.dw '.stabn 0x44,0,31,',0,0
	.dd LM2-_send525
	.dw 0x0d,0x0a
.code
LM2:
LBB2:
.debug
	.dw '.stabn 0x44,0,32,',0,0
	.dd LM3-_send525
	.dw 0x0d,0x0a
.code
LM3:
	R2=[28672]	// QImode move
	R3=R2&(-5)
	[28672]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,33,',0,0
	.dd LM4-_send525
	.dw 0x0d,0x0a
.code
LM4:
	R2=[28672]	// QImode move
	R3=R2&(-2)
	[28672]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,34,',0,0
	.dd LM5-_send525
	.dw 0x0d,0x0a
.code
LM5:
	R2=R1	// QImode move
	R3=[R2]	// QImode move
	R3=R3&4092
	[R2]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,35,',0,0
	.dd LM6-_send525
	.dw 0x0d,0x0a
.code
LM6:
	R4=R1	// QImode move
	R2=[R4]	// QImode move
	R2=R2|(-32768)
	[R4]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,36,',0,0
	.dd LM7-_send525
	.dw 0x0d,0x0a
.code
LM7:
	R2=1	// QImode move
	[28690]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,37,',0,0
	.dd LM8-_send525
	.dw 0x0d,0x0a
.code
LM8:
	R2=BP	// QImode move
	R3=BP+1
	R2=0	// QImode move
	R4=R3	// QImode move
	[R4]=R2	// QImode move
L3:
	R2=BP	// QImode move
	R3=BP+1
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	CMP R2,15	// QImode compare
	NSJNG L6	//QImode LE
	pc=L4	// Indirect jump
L6:
.debug
	.dw '.stabn 0x44,0,39,',0,0
	.dd LM9-_send525
	.dw 0x0d,0x0a
.code
LM9:
	R2=R1	// QImode move
	R2=[R2]	// QImode move
	R2=R2&(-32768)
	[BP]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,40,',0,0
	.dd LM10-_send525
	.dw 0x0d,0x0a
.code
LM10:
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	R3=R2 lsl 1
	R4=R1	// QImode move
	[R4]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,41,',0,0
	.dd LM11-_send525
	.dw 0x0d,0x0a
.code
LM11:
	R2=[BP]	// QImode move
	CMP R2,0	// QImode test
	NSJZ L7	//QImode EQ
.debug
	.dw '.stabn 0x44,0,43,',0,0
	.dd LM12-_send525
	.dw 0x0d,0x0a
.code
LM12:
	R2=[28672]	// QImode move
	R3=R2|2
	[28672]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,44,',0,0
	.dd LM13-_send525
	.dw 0x0d,0x0a
.code
LM13:
	R2=[28672]	// QImode move
	R3=R2&(-2)
	[28672]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,45,',0,0
	.dd LM14-_send525
	.dw 0x0d,0x0a
.code
LM14:
	R2=[28672]	// QImode move
	R3=R2|1
	[28672]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,46,',0,0
	.dd LM15-_send525
	.dw 0x0d,0x0a
.code
LM15:
	pc=L5	// Indirect jump
L7:
.debug
	.dw '.stabn 0x44,0,49,',0,0
	.dd LM16-_send525
	.dw 0x0d,0x0a
.code
LM16:
	R2=[28672]	// QImode move
	R3=R2&(-3)
	[28672]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,50,',0,0
	.dd LM17-_send525
	.dw 0x0d,0x0a
.code
LM17:
	R2=[28672]	// QImode move
	R3=R2&(-2)
	[28672]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,51,',0,0
	.dd LM18-_send525
	.dw 0x0d,0x0a
.code
LM18:
	R2=[28672]	// QImode move
	R3=R2|1
	[28672]=R3	// QImode move
L8:
.debug
	.dw '.stabn 0x44,0,37,',0,0
	.dd LM19-_send525
	.dw 0x0d,0x0a
.code
LM19:
L5:
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
	pc=L3	// Indirect jump
L4:
.debug
	.dw '.stabn 0x44,0,54,',0,0
	.dd LM20-_send525
	.dw 0x0d,0x0a
.code
LM20:
	R2=[28672]	// QImode move
	R3=R2|4
	[28672]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,55,',0,0
	.dd LM21-_send525
	.dw 0x0d,0x0a
.code
LM21:
LBE2:
.debug
	.dw '.stabn 0x44,0,55,',0,0
	.dd LM22-_send525
	.dw 0x0d,0x0a
.code
LM22:
L2:

	sp+=3
	pop bp from [sp]
	retf
	.endp	// end of send525

.debug
	.dw '.stabs "data:p1",160,0,0,6',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB2-_send525
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "temp:1",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "i:1",128,0,0,1',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE2-_send525
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME1-_send525
	.dw 0x0d,0x0a
.code
LME1:
.code
.debug
	.dw '.stabs "init525:F19",36,0,0,',0,0,offset _init525,seg _init525,0x0d,0x0a
.CODE
.public _init525
_init525:	.proc
.debug
	.dw '.stabn 0x44,0,59,',0,0
	.dd LM23-_init525
	.dw 0x0d,0x0a
.code
LM23:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,60,',0,0
	.dd LM24-_init525
	.dw 0x0d,0x0a
.code
LM24:
	R1=[28674]	// QImode move
	R2=R1|15
	[28674]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,61,',0,0
	.dd LM25-_init525
	.dw 0x0d,0x0a
.code
LM25:
	R1=[28675]	// QImode move
	R2=R1|15
	[28675]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,62,',0,0
	.dd LM26-_init525
	.dw 0x0d,0x0a
.code
LM26:
	R1=[28672]	// QImode move
	R2=R1&(-16)
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,63,',0,0
	.dd LM27-_init525
	.dw 0x0d,0x0a
.code
LM27:
	R1=[28672]	// QImode move
	R2=R1&(-9)
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,64,',0,0
	.dd LM28-_init525
	.dw 0x0d,0x0a
.code
LM28:
	R1=[28672]	// QImode move
	R2=R1|8
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,65,',0,0
	.dd LM29-_init525
	.dw 0x0d,0x0a
.code
LM29:
	R1=(-32513)	// QImode move
	[SP--]=R1	// QImode move
	call _send525	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,66,',0,0
	.dd LM30-_init525
	.dw 0x0d,0x0a
.code
LM30:
.debug
	.dw '.stabn 0x44,0,66,',0,0
	.dd LM31-_init525
	.dw 0x0d,0x0a
.code
LM31:
L11:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of init525

.debug
	.dw '.stabf ',0,0
	.dd LME2-_init525
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
	.dw '.stabs "C:/Documents and Settings/Administrator/×/300Ã/346/¸/366È/313¹/244³/314Î/304¼/376¼/320/Õ/324Ó/300¿/306/525/my7219.h",0x84,0,0,',0,0,offset Ltext2, seg Ltext2,0x0d,0x0a
.code
.code
Ltext2:
.debug
	.dw '.stabn 0x44,0,36,',0,0
	.dd LM32-_sendword
	.dw 0x0d,0x0a
.code
LM32:
	// total=2, vars=2
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=2
	bp=sp+1

	R1=BP+5
.debug
	.dw '.stabn 0x44,0,37,',0,0
	.dd LM33-_sendword
	.dw 0x0d,0x0a
.code
LM33:
LBB3:
.debug
	.dw '.stabn 0x44,0,38,',0,0
	.dd LM34-_sendword
	.dw 0x0d,0x0a
.code
LM34:
	R2=[28677]	// QImode move
	R3=R2&(-8193)
	[28677]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,39,',0,0
	.dd LM35-_sendword
	.dw 0x0d,0x0a
.code
LM35:
	R2=0	// QImode move
	[BP]=R2	// QImode move
L13:
	R2=[BP]	// QImode move
	CMP R2,15	// QImode compare
	NSJNG L16	//QImode LE
	pc=L14	// Indirect jump
L16:
.debug
	.dw '.stabn 0x44,0,41,',0,0
	.dd LM36-_sendword
	.dw 0x0d,0x0a
.code
LM36:
	R2=1	// QImode move
	[28690]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,42,',0,0
	.dd LM37-_sendword
	.dw 0x0d,0x0a
.code
LM37:
	R2=BP	// QImode move
	R3=BP+1
	R2=R1	// QImode move
	R2=[R2]	// QImode move
	R4=R2&(-32768)
	R2=R3	// QImode move
	[R2]=R4	// QImode move
.debug
	.dw '.stabn 0x44,0,43,',0,0
	.dd LM38-_sendword
	.dw 0x0d,0x0a
.code
LM38:
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	R3=R2 lsl 1
	R4=R1	// QImode move
	[R4]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,44,',0,0
	.dd LM39-_sendword
	.dw 0x0d,0x0a
.code
LM39:
	R2=BP	// QImode move
	R3=BP+1
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	CMP R2,0	// QImode test
	NSJZ L17	//QImode EQ
.debug
	.dw '.stabn 0x44,0,46,',0,0
	.dd LM40-_sendword
	.dw 0x0d,0x0a
.code
LM40:
	R2=[28677]	// QImode move
	R3=R2|(-32768)
	[28677]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,47,',0,0
	.dd LM41-_sendword
	.dw 0x0d,0x0a
.code
LM41:
	R2=[28677]	// QImode move
	R3=R2&(-16385)
	[28677]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,48,',0,0
	.dd LM42-_sendword
	.dw 0x0d,0x0a
.code
LM42:
	R2=[28677]	// QImode move
	R3=R2|16384
	[28677]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,49,',0,0
	.dd LM43-_sendword
	.dw 0x0d,0x0a
.code
LM43:
	pc=L15	// Indirect jump
L17:
.debug
	.dw '.stabn 0x44,0,52,',0,0
	.dd LM44-_sendword
	.dw 0x0d,0x0a
.code
LM44:
	R2=[28677]	// QImode move
	R3=R2&32767
	[28677]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,53,',0,0
	.dd LM45-_sendword
	.dw 0x0d,0x0a
.code
LM45:
	R2=[28677]	// QImode move
	R3=R2&(-16385)
	[28677]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,54,',0,0
	.dd LM46-_sendword
	.dw 0x0d,0x0a
.code
LM46:
	R2=[28677]	// QImode move
	R3=R2|16384
	[28677]=R3	// QImode move
L18:
.debug
	.dw '.stabn 0x44,0,39,',0,0
	.dd LM47-_sendword
	.dw 0x0d,0x0a
.code
LM47:
L15:
	R2=[BP]	// QImode move
	R3=R2+1
	[BP]=R3	// QImode move
	pc=L13	// Indirect jump
L14:
.debug
	.dw '.stabn 0x44,0,57,',0,0
	.dd LM48-_sendword
	.dw 0x0d,0x0a
.code
LM48:
	R2=[28677]	// QImode move
	R3=R2|8192
	[28677]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,58,',0,0
	.dd LM49-_sendword
	.dw 0x0d,0x0a
.code
LM49:
	R2=1	// QImode move
	[28690]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,59,',0,0
	.dd LM50-_sendword
	.dw 0x0d,0x0a
.code
LM50:
LBE3:
.debug
	.dw '.stabn 0x44,0,59,',0,0
	.dd LM51-_sendword
	.dw 0x0d,0x0a
.code
LM51:
L12:

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
	.dd LM52-_init7219
	.dw 0x0d,0x0a
.code
LM52:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,62,',0,0
	.dd LM53-_init7219
	.dw 0x0d,0x0a
.code
LM53:
	R1=[28679]	// QImode move
	R2=R1|(-4096)
	[28679]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,63,',0,0
	.dd LM54-_init7219
	.dw 0x0d,0x0a
.code
LM54:
	R1=[28680]	// QImode move
	R2=R1|(-4096)
	[28680]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,64,',0,0
	.dd LM55-_init7219
	.dw 0x0d,0x0a
.code
LM55:
	R1=[28677]	// QImode move
	R2=R1&4095
	[28677]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,65,',0,0
	.dd LM56-_init7219
	.dw 0x0d,0x0a
.code
LM56:
	R1=2823	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,66,',0,0
	.dd LM57-_init7219
	.dw 0x0d,0x0a
.code
LM57:
	R1=2559	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,67,',0,0
	.dd LM58-_init7219
	.dw 0x0d,0x0a
.code
LM58:
	R1=2570	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,68,',0,0
	.dd LM59-_init7219
	.dw 0x0d,0x0a
.code
LM59:
	R1=3073	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,69,',0,0
	.dd LM60-_init7219
	.dw 0x0d,0x0a
.code
LM60:
	R1=3841	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,70,',0,0
	.dd LM61-_init7219
	.dw 0x0d,0x0a
.code
LM61:
	R1=3840	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,71,',0,0
	.dd LM62-_init7219
	.dw 0x0d,0x0a
.code
LM62:
.debug
	.dw '.stabn 0x44,0,71,',0,0
	.dd LM63-_init7219
	.dw 0x0d,0x0a
.code
LM63:
L21:

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
	.dd LM64-_show
	.dw 0x0d,0x0a
.code
LM64:
	// total=14, vars=14
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=14
	bp=sp+1

	R1=BP+17
	[bp+8]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,81,',0,0
	.dd LM65-_show
	.dw 0x0d,0x0a
.code
LM65:
LBB4:
.debug
	.dw '.stabn 0x44,0,83,',0,0
	.dd LM66-_show
	.dw 0x0d,0x0a
.code
LM66:
	R1=[28679]	// QImode move
	R2=R1|(-4096)
	[28679]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,84,',0,0
	.dd LM67-_show
	.dw 0x0d,0x0a
.code
LM67:
	R1=[28680]	// QImode move
	R2=R1|(-4096)
	[28680]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,85,',0,0
	.dd LM68-_show
	.dw 0x0d,0x0a
.code
LM68:
	R1=[28677]	// QImode move
	R2=R1&4095
	[28677]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,86,',0,0
	.dd LM69-_show
	.dw 0x0d,0x0a
.code
LM69:
	R1=2823	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,87,',0,0
	.dd LM70-_show
	.dw 0x0d,0x0a
.code
LM70:
	R1=2559	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,88,',0,0
	.dd LM71-_show
	.dw 0x0d,0x0a
.code
LM71:
	R1=2570	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,89,',0,0
	.dd LM72-_show
	.dw 0x0d,0x0a
.code
LM72:
	R1=3073	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,91,',0,0
	.dd LM73-_show
	.dw 0x0d,0x0a
.code
LM73:
	R2=[bp+8]	// QImode move
	R1=[R2]	// QImode move
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,92,',0,0
	.dd LM74-_show
	.dw 0x0d,0x0a
.code
LM74:
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
	.dd LM75-_show
	.dw 0x0d,0x0a
.code
LM75:
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
	.dd LM76-_show
	.dw 0x0d,0x0a
.code
LM76:
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
	.dd LM77-_show
	.dw 0x0d,0x0a
.code
LM77:
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
	.dd LM78-_show
	.dw 0x0d,0x0a
.code
LM78:
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
	.dd LM79-_show
	.dw 0x0d,0x0a
.code
LM79:
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
	.dd LM80-_show
	.dw 0x0d,0x0a
.code
LM80:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,99,',0,0
	.dd LM81-_show
	.dw 0x0d,0x0a
.code
LM81:
	R2=[BP]	// QImode move
	R1=R2|2048
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,100,',0,0
	.dd LM82-_show
	.dw 0x0d,0x0a
.code
LM82:
	R1=1807	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,101,',0,0
	.dd LM83-_show
	.dw 0x0d,0x0a
.code
LM83:
	R1=BP	// QImode move
	R2=BP+2
	R3=R2	// QImode move
	R3=[R3]	// QImode move
	R1=R3|1536
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,102,',0,0
	.dd LM84-_show
	.dw 0x0d,0x0a
.code
LM84:
	R1=BP	// QImode move
	R2=BP+3
	R4=R2	// QImode move
	R4=[R4]	// QImode move
	R1=R4|1280
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,103,',0,0
	.dd LM85-_show
	.dw 0x0d,0x0a
.code
LM85:
	R1=BP	// QImode move
	R2=BP+4
	R3=R2	// QImode move
	R3=[R3]	// QImode move
	R1=R3|1024
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,104,',0,0
	.dd LM86-_show
	.dw 0x0d,0x0a
.code
LM86:
	R1=783	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,105,',0,0
	.dd LM87-_show
	.dw 0x0d,0x0a
.code
LM87:
	R1=BP	// QImode move
	R2=BP+6
	R4=R2	// QImode move
	R4=[R4]	// QImode move
	R1=R4|512
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,106,',0,0
	.dd LM88-_show
	.dw 0x0d,0x0a
.code
LM88:
	R1=BP	// QImode move
	R2=BP+7
	R3=R2	// QImode move
	R3=[R3]	// QImode move
	R1=R3|256
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,107,',0,0
	.dd LM89-_show
	.dw 0x0d,0x0a
.code
LM89:
LBE4:
.debug
	.dw '.stabn 0x44,0,107,',0,0
	.dd LM90-_show
	.dw 0x0d,0x0a
.code
LM90:
L22:

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
.public _table
.iram
_table:
	.dw 0
	.dw 12
	.dw 25
	.dw 37
	.dw 48
	.dw 59
	.dw 68
	.dw 77
	.dw 84
	.dw 90
	.dw 95
	.dw 98
	.dw 100
	.dw 100
	.dw 98
	.dw 95
	.dw 90
	.dw 84
	.dw 77
	.dw 68
	.dw 59
	.dw 48
	.dw 37
	.dw 25
	.dw 12
	.dw 0
.debug
	.dw '.stabs "table:G21=ar1;0;25;4",32,0,0,',0,0,offset _table,seg _table,0x0d,0x0a
.CODE
.code
.debug
	.dw '.stabs "delay:F19",36,0,0,',0,0,offset _delay,seg _delay,0x0d,0x0a
.CODE
.public _delay
_delay:	.proc
.debug
	.dw '.stabs "C:/Documents and Settings/Administrator/×/300Ã/346/¸/366È/313¹/244³/314Î/304¼/376¼/320/Õ/324Ó/300¿/306/525/my525.c",0x84,0,0,',0,0,offset Ltext3, seg Ltext3,0x0d,0x0a
.code
.code
Ltext3:
.debug
	.dw '.stabn 0x44,0,10,',0,0
	.dd LM91-_delay
	.dw 0x0d,0x0a
.code
LM91:
	// total=3, vars=3
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=3
	bp=sp+1

	R1=BP+6
.debug
	.dw '.stabn 0x44,0,11,',0,0
	.dd LM92-_delay
	.dw 0x0d,0x0a
.code
LM92:
LBB5:
.debug
	.dw '.stabn 0x44,0,12,',0,0
	.dd LM93-_delay
	.dw 0x0d,0x0a
.code
LM93:
	R2=0	// QImode move
	[BP]=R2	// QImode move
L24:
	R2=[BP]	// QImode move
	CMP R2,9	// QImode compare
	NSJNG L27	//QImode LE
	pc=L25	// Indirect jump
L27:
.debug
	.dw '.stabn 0x44,0,13,',0,0
	.dd LM94-_delay
	.dw 0x0d,0x0a
.code
LM94:
	R2=BP	// QImode move
	R3=BP+1
	R2=0	// QImode move
	R4=R3	// QImode move
	[R4]=R2	// QImode move
L28:
	R2=BP	// QImode move
	R3=BP+1
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	CMP R2,9	// QImode compare
	NSJNG L31	//QImode LE
	pc=L26	// Indirect jump
L31:
.debug
	.dw '.stabn 0x44,0,14,',0,0
	.dd LM95-_delay
	.dw 0x0d,0x0a
.code
LM95:
	R2=1	// QImode move
	[28690]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,13,',0,0
	.dd LM96-_delay
	.dw 0x0d,0x0a
.code
LM96:
L30:
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
	pc=L28	// Indirect jump
L29:
.debug
	.dw '.stabn 0x44,0,12,',0,0
	.dd LM97-_delay
	.dw 0x0d,0x0a
.code
LM97:
L26:
	R2=[BP]	// QImode move
	R3=R2+1
	[BP]=R3	// QImode move
	pc=L24	// Indirect jump
L25:
.debug
	.dw '.stabn 0x44,0,15,',0,0
	.dd LM98-_delay
	.dw 0x0d,0x0a
.code
LM98:
LBE5:
.debug
	.dw '.stabn 0x44,0,15,',0,0
	.dd LM99-_delay
	.dw 0x0d,0x0a
.code
LM99:
L23:

	sp+=3
	pop bp from [sp]
	retf
	.endp	// end of delay

.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB5-_delay
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
	.dd LBE5-_delay
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME6-_delay
	.dw 0x0d,0x0a
.code
LME6:
.code
.debug
	.dw '.stabs "main:F1",36,0,0,',0,0,offset _main,seg _main,0x0d,0x0a
.CODE
.public _main
_main:	.proc
.debug
	.dw '.stabn 0x44,0,17,',0,0
	.dd LM100-_main
	.dw 0x0d,0x0a
.code
LM100:
	// total=2, vars=2
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=2
	bp=sp+1

	R1=BP+5
	[bp+1]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,18,',0,0
	.dd LM101-_main
	.dw 0x0d,0x0a
.code
LM101:
LBB6:
.debug
	.dw '.stabn 0x44,0,19,',0,0
	.dd LM102-_main
	.dw 0x0d,0x0a
.code
LM102:
	call _init525	// call without return value
.debug
	.dw '.stabn 0x44,0,20,',0,0
	.dd LM103-_main
	.dw 0x0d,0x0a
.code
LM103:
	call _init7219	// call without return value
.debug
	.dw '.stabn 0x44,0,21,',0,0
	.dd LM104-_main
	.dw 0x0d,0x0a
.code
LM104:
L35:
	pc=L37	// Indirect jump
	pc=L36	// Indirect jump
L37:
.debug
	.dw '.stabn 0x44,0,34,',0,0
	.dd LM105-_main
	.dw 0x0d,0x0a
.code
LM105:
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	R1=100	// QImode move
	[SP--]=R1	// QImode move
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	call _show	// call without return value
	SP = SP + 3	//SP
.debug
	.dw '.stabn 0x44,0,36,',0,0
	.dd LM106-_main
	.dw 0x0d,0x0a
.code
LM106:
	pc=L35	// Indirect jump
L36:
.debug
	.dw '.stabn 0x44,0,37,',0,0
	.dd LM107-_main
	.dw 0x0d,0x0a
.code
LM107:
LBE6:
.debug
	.dw '.stabn 0x44,0,37,',0,0
	.dd LM108-_main
	.dw 0x0d,0x0a
.code
LM108:
L34:

	sp+=2
	pop bp from [sp]
	retf
	.endp	// end of main

.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB6-_main
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "i:1",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE6-_main
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME7-_main
	.dw 0x0d,0x0a
.code
LME7:
.external __modi1
.external __divi1
	.end

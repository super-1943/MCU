// GCC for SUNPLUS u'nSP version 1.0.21-3
// Command: D:\PROGRA~1\SunPlus\UNSPID~1.0\cc1.exe C:\DOCUME~1\a\LOCALS~1\Temp\ccKqaaaa.i -fkeep-inline-functions -quiet -dumpbase main.c -mglobal-var-iram -gstabs -Wall -o .\Debug/main.asm
	.external __sn_func_ptr_sec

// gcc2_compiled.:

.debug
	.dw '.stabs "H:/key/key/",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
.code
.debug
	.dw '.stabs "H:/key/key/main.c",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
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
	.dw '.stabs "delay:F19",36,0,0,',0,0,offset _delay,seg _delay,0x0d,0x0a
.CODE
.public _delay
_delay:	.proc
.debug
	.dw '.stabs "H:/key/key/mykey.h",0x84,0,0,',0,0,offset Ltext1, seg Ltext1,0x0d,0x0a
.code
.code
Ltext1:
.debug
	.dw '.stabn 0x44,0,25,',0,0
	.dd LM1-_delay
	.dw 0x0d,0x0a
.code
LM1:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,27,',0,0
	.dd LM2-_delay
	.dw 0x0d,0x0a
.code
LM2:
L3:
	R2=R1	// QImode move
	R3=[R2]	// QImode move
	R2=R3+(-1)
	R3=R2	// QImode move
	R2=R1	// QImode move
	[R2]=R3	// QImode move
	CMP R3,(-1)	// QImode compare
	NSJNZ L5	//QImode NE
	pc=L4	// Indirect jump
L5:
.debug
	.dw '.stabn 0x44,0,30,',0,0
	.dd LM3-_delay
	.dw 0x0d,0x0a
.code
LM3:
	R2=1	// QImode move
	[28690]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,31,',0,0
	.dd LM4-_delay
	.dw 0x0d,0x0a
.code
LM4:
	pc=L3	// Indirect jump
L4:
.debug
	.dw '.stabn 0x44,0,32,',0,0
	.dd LM5-_delay
	.dw 0x0d,0x0a
.code
LM5:
.debug
	.dw '.stabn 0x44,0,32,',0,0
	.dd LM6-_delay
	.dw 0x0d,0x0a
.code
LM6:
L2:

	pop bp from [sp]
	retf
	.endp	// end of delay

.debug
	.dw '.stabs "x:p1",160,0,0,3',0x0d,0x0a
.CODE
.debug
	.dw '.stabf ',0,0
	.dd LME1-_delay
	.dw 0x0d,0x0a
.code
LME1:
.code
.debug
	.dw '.stabs "storemem:F19",36,0,0,',0,0,offset _storemem,seg _storemem,0x0d,0x0a
.CODE
.public _storemem
_storemem:	.proc
.debug
	.dw '.stabn 0x44,0,34,',0,0
	.dd LM7-_storemem
	.dw 0x0d,0x0a
.code
LM7:
	// total=8, vars=8
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=8
	bp=sp+1

	R1=BP+11
.debug
	.dw '.stabn 0x44,0,35,',0,0
	.dd LM8-_storemem
	.dw 0x0d,0x0a
.code
LM8:
LBB2:
.debug
	.dw '.stabn 0x44,0,36,',0,0
	.dd LM9-_storemem
	.dw 0x0d,0x0a
.code
LM9:
	R2=[_mode]	// QImode move
	CMP R2,0	// QImode test
	NSJNZ L8	//QImode NE
.debug
	.dw '.stabn 0x44,0,38,',0,0
	.dd LM10-_storemem
	.dw 0x0d,0x0a
.code
LM10:
	R2=0	// QImode move
	[BP]=R2	// QImode move
L9:
	R2=[BP]	// QImode move
	CMP R2,255	// QImode compare
	NSJNG L12	//QImode LE
	pc=L8	// Indirect jump
L12:
.debug
	.dw '.stabn 0x44,0,40,',0,0
	.dd LM11-_storemem
	.dw 0x0d,0x0a
.code
LM11:
	R2=1	// QImode move
	[28690]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,41,',0,0
	.dd LM12-_storemem
	.dw 0x0d,0x0a
.code
LM12:
	R2=_mem_table	// QImode move
	R3=[BP]	// QImode move
	R2 = R2 + R3	//addqi3
	R3=_mem_table	// QImode move
	R4=[BP]	// QImode move
	R3 = R3 + R4	//addqi3
	R4=_SINE	// QImode move
	[bp+7]=R4	// QImode move
	R4=[BP]	// QImode move
	[bp+1]=R4	// QImode move
	R4=[bp+7]	// QImode move
	[bp+7]=R4	// QImode move
	R4=[bp+7]	// QImode move
	R4 = R4 + [bp+1]	//addqi3
	[bp+7]=R4	// QImode move
	R4=R3	// QImode move
	R4=[R4]	// QImode move
	[bp+2]=R4	// QImode move
	R3=[bp+2]	// QImode move
	R4=[bp+7]	// QImode move
	R3 = R3 + [R4]	//addqi3
	R4=R2	// QImode move
	[R4]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,38,',0,0
	.dd LM13-_storemem
	.dw 0x0d,0x0a
.code
LM13:
L11:
	R2=[BP]	// QImode move
	R3=R2+1
	[BP]=R3	// QImode move
	pc=L9	// Indirect jump
L10:
L8:
.debug
	.dw '.stabn 0x44,0,44,',0,0
	.dd LM14-_storemem
	.dw 0x0d,0x0a
.code
LM14:
	R2=[_mode]	// QImode move
	CMP R2,1	// QImode compare
	NSJNZ L13	//QImode NE
.debug
	.dw '.stabn 0x44,0,46,',0,0
	.dd LM15-_storemem
	.dw 0x0d,0x0a
.code
LM15:
	R2=0	// QImode move
	[BP]=R2	// QImode move
L14:
	R2=[BP]	// QImode move
	CMP R2,255	// QImode compare
	NSJNG L17	//QImode LE
	pc=L13	// Indirect jump
L17:
.debug
	.dw '.stabn 0x44,0,48,',0,0
	.dd LM16-_storemem
	.dw 0x0d,0x0a
.code
LM16:
	R2=1	// QImode move
	[28690]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,49,',0,0
	.dd LM17-_storemem
	.dw 0x0d,0x0a
.code
LM17:
	R2=_mem_table	// QImode move
	R3=[BP]	// QImode move
	R2 = R2 + R3	//addqi3
	R3=_mem_table	// QImode move
	R4=[BP]	// QImode move
	R3 = R3 + R4	//addqi3
	R4=_SQUR	// QImode move
	[bp+7]=R4	// QImode move
	R4=[BP]	// QImode move
	[bp+3]=R4	// QImode move
	R4=[bp+7]	// QImode move
	[bp+7]=R4	// QImode move
	R4=[bp+7]	// QImode move
	R4 = R4 + [bp+3]	//addqi3
	[bp+7]=R4	// QImode move
	R4=R3	// QImode move
	R4=[R4]	// QImode move
	[bp+4]=R4	// QImode move
	R3=[bp+4]	// QImode move
	R4=[bp+7]	// QImode move
	R3 = R3 + [R4]	//addqi3
	R4=R2	// QImode move
	[R4]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,46,',0,0
	.dd LM18-_storemem
	.dw 0x0d,0x0a
.code
LM18:
L16:
	R2=[BP]	// QImode move
	R3=R2+1
	[BP]=R3	// QImode move
	pc=L14	// Indirect jump
L15:
L13:
.debug
	.dw '.stabn 0x44,0,52,',0,0
	.dd LM19-_storemem
	.dw 0x0d,0x0a
.code
LM19:
	R2=[_mode]	// QImode move
	CMP R2,2	// QImode compare
	NSJNZ L18	//QImode NE
.debug
	.dw '.stabn 0x44,0,54,',0,0
	.dd LM20-_storemem
	.dw 0x0d,0x0a
.code
LM20:
	R2=0	// QImode move
	[BP]=R2	// QImode move
L19:
	R2=[BP]	// QImode move
	CMP R2,255	// QImode compare
	NSJNG L22	//QImode LE
	pc=L18	// Indirect jump
L22:
.debug
	.dw '.stabn 0x44,0,56,',0,0
	.dd LM21-_storemem
	.dw 0x0d,0x0a
.code
LM21:
	R2=1	// QImode move
	[28690]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,57,',0,0
	.dd LM22-_storemem
	.dw 0x0d,0x0a
.code
LM22:
	R2=_mem_table	// QImode move
	R3=[BP]	// QImode move
	R2 = R2 + R3	//addqi3
	R3=_mem_table	// QImode move
	R4=[BP]	// QImode move
	R3 = R3 + R4	//addqi3
	R4=_TRIG	// QImode move
	[bp+7]=R4	// QImode move
	R4=[BP]	// QImode move
	[bp+5]=R4	// QImode move
	R4=[bp+7]	// QImode move
	[bp+7]=R4	// QImode move
	R4=[bp+7]	// QImode move
	R4 = R4 + [bp+5]	//addqi3
	[bp+7]=R4	// QImode move
	R4=R3	// QImode move
	R4=[R4]	// QImode move
	[bp+6]=R4	// QImode move
	R3=[bp+6]	// QImode move
	R4=[bp+7]	// QImode move
	R3 = R3 + [R4]	//addqi3
	R4=R2	// QImode move
	[R4]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,54,',0,0
	.dd LM23-_storemem
	.dw 0x0d,0x0a
.code
LM23:
L21:
	R2=[BP]	// QImode move
	R3=R2+1
	[BP]=R3	// QImode move
	pc=L19	// Indirect jump
L20:
L18:
.debug
	.dw '.stabn 0x44,0,60,',0,0
	.dd LM24-_storemem
	.dw 0x0d,0x0a
.code
LM24:
	R2=[_mode]	// QImode move
	CMP R2,3	// QImode compare
	NSJNZ L23	//QImode NE
.debug
	.dw '.stabn 0x44,0,62,',0,0
	.dd LM25-_storemem
	.dw 0x0d,0x0a
.code
LM25:
	R2=0	// QImode move
	[BP]=R2	// QImode move
L24:
	R2=[BP]	// QImode move
	CMP R2,255	// QImode compare
	NSJNG L27	//QImode LE
	pc=L23	// Indirect jump
L27:
.debug
	.dw '.stabn 0x44,0,64,',0,0
	.dd LM26-_storemem
	.dw 0x0d,0x0a
.code
LM26:
	R2=1	// QImode move
	[28690]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,65,',0,0
	.dd LM27-_storemem
	.dw 0x0d,0x0a
.code
LM27:
	R2=_mem_table	// QImode move
	R3=[BP]	// QImode move
	R2 = R2 + R3	//addqi3
	R3=_mem_table	// QImode move
	R4=[BP]	// QImode move
	R3 = R3 + R4	//addqi3
	R4=R3	// QImode move
	R4=[R4]	// QImode move
	[bp+7]=R4	// QImode move
	R3=[bp+7]	// QImode move
	R4=R3 lsl 1
	R3=R2	// QImode move
	[R3]=R4	// QImode move
.debug
	.dw '.stabn 0x44,0,62,',0,0
	.dd LM28-_storemem
	.dw 0x0d,0x0a
.code
LM28:
L26:
	R2=[BP]	// QImode move
	R3=R2+1
	[BP]=R3	// QImode move
	pc=L24	// Indirect jump
L25:
L23:
.debug
	.dw '.stabn 0x44,0,68,',0,0
	.dd LM29-_storemem
	.dw 0x0d,0x0a
.code
LM29:
LBE2:
.debug
	.dw '.stabn 0x44,0,68,',0,0
	.dd LM30-_storemem
	.dw 0x0d,0x0a
.code
LM30:
L7:

	sp+=8
	pop bp from [sp]
	retf
	.endp	// end of storemem

.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB2-_storemem
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "i:1",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE2-_storemem
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME2-_storemem
	.dw 0x0d,0x0a
.code
LME2:
.code
.debug
	.dw '.stabs "clearmem:F19",36,0,0,',0,0,offset _clearmem,seg _clearmem,0x0d,0x0a
.CODE
.public _clearmem
_clearmem:	.proc
.debug
	.dw '.stabn 0x44,0,70,',0,0
	.dd LM31-_clearmem
	.dw 0x0d,0x0a
.code
LM31:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
.debug
	.dw '.stabn 0x44,0,71,',0,0
	.dd LM32-_clearmem
	.dw 0x0d,0x0a
.code
LM32:
LBB3:
.debug
	.dw '.stabn 0x44,0,72,',0,0
	.dd LM33-_clearmem
	.dw 0x0d,0x0a
.code
LM33:
	R2=0	// QImode move
	[BP]=R2	// QImode move
L37:
	R2=[BP]	// QImode move
	CMP R2,255	// QImode compare
	NSJNG L40	//QImode LE
	pc=L38	// Indirect jump
L40:
.debug
	.dw '.stabn 0x44,0,74,',0,0
	.dd LM34-_clearmem
	.dw 0x0d,0x0a
.code
LM34:
	R2=1	// QImode move
	[28690]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,75,',0,0
	.dd LM35-_clearmem
	.dw 0x0d,0x0a
.code
LM35:
	R2=_mem_table	// QImode move
	R3=[BP]	// QImode move
	R2 = R2 + R3	//addqi3
	R3=0	// QImode move
	R4=R2	// QImode move
	[R4]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,72,',0,0
	.dd LM36-_clearmem
	.dw 0x0d,0x0a
.code
LM36:
L39:
	R2=[BP]	// QImode move
	R3=R2+1
	[BP]=R3	// QImode move
	pc=L37	// Indirect jump
L38:
.debug
	.dw '.stabn 0x44,0,77,',0,0
	.dd LM37-_clearmem
	.dw 0x0d,0x0a
.code
LM37:
LBE3:
.debug
	.dw '.stabn 0x44,0,77,',0,0
	.dd LM38-_clearmem
	.dw 0x0d,0x0a
.code
LM38:
L36:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of clearmem

.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB3-_clearmem
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "i:1",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE3-_clearmem
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME3-_clearmem
	.dw 0x0d,0x0a
.code
LME3:
.code
.debug
	.dw '.stabs "initkey:F19",36,0,0,',0,0,offset _initkey,seg _initkey,0x0d,0x0a
.CODE
.public _initkey
_initkey:	.proc
.debug
	.dw '.stabn 0x44,0,79,',0,0
	.dd LM39-_initkey
	.dw 0x0d,0x0a
.code
LM39:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,80,',0,0
	.dd LM40-_initkey
	.dw 0x0d,0x0a
.code
LM40:
	R2=[28679]	// QImode move
	R3=R2&(-256)
	[28679]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,81,',0,0
	.dd LM41-_initkey
	.dw 0x0d,0x0a
.code
LM41:
	R2=[28680]	// QImode move
	R3=R2&(-256)
	[28680]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,82,',0,0
	.dd LM42-_initkey
	.dw 0x0d,0x0a
.code
LM42:
	R2=[28677]	// QImode move
	R3=R2|255
	[28677]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,83,',0,0
	.dd LM43-_initkey
	.dw 0x0d,0x0a
.code
LM43:
.debug
	.dw '.stabn 0x44,0,83,',0,0
	.dd LM44-_initkey
	.dw 0x0d,0x0a
.code
LM44:
L42:

	pop bp from [sp]
	retf
	.endp	// end of initkey

.debug
	.dw '.stabf ',0,0
	.dd LME4-_initkey
	.dw 0x0d,0x0a
.code
LME4:
.code
.debug
	.dw '.stabs "KeyScan:F19",36,0,0,',0,0,offset _KeyScan,seg _KeyScan,0x0d,0x0a
.CODE
.public _KeyScan
_KeyScan:	.proc
.debug
	.dw '.stabn 0x44,0,85,',0,0
	.dd LM45-_KeyScan
	.dw 0x0d,0x0a
.code
LM45:
	// total=3, vars=3
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=3
	bp=sp+1

	R1=BP+6
	[bp+2]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,87,',0,0
	.dd LM46-_KeyScan
	.dw 0x0d,0x0a
.code
LM46:
LBB4:
.debug
	.dw '.stabn 0x44,0,88,',0,0
	.dd LM47-_KeyScan
	.dw 0x0d,0x0a
.code
LM47:
	R1=BP	// QImode move
	R2=BP+1
	R1=[28677]	// QImode move
	R4=R1&255
	R3=R2	// QImode move
	[R3]=R4	// QImode move
.debug
	.dw '.stabn 0x44,0,89,',0,0
	.dd LM48-_KeyScan
	.dw 0x0d,0x0a
.code
LM48:
	R1=BP	// QImode move
	R2=BP+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	CMP R1,255	// QImode compare
	NSJNZ L44	//QImode NE
.debug
	.dw '.stabn 0x44,0,90,',0,0
	.dd LM49-_KeyScan
	.dw 0x0d,0x0a
.code
LM49:
	pc=L43	// Indirect jump
L44:
.debug
	.dw '.stabn 0x44,0,91,',0,0
	.dd LM50-_KeyScan
	.dw 0x0d,0x0a
.code
LM50:
	R2=[28677]	// QImode move
	R1=R2|(-256)
	R2=R1^0xffff	// one_cmplqi2
	[BP]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,92,',0,0
	.dd LM51-_KeyScan
	.dw 0x0d,0x0a
.code
LM51:
	R1=[BP]	// QImode move
	CMP R1,8	// QImode compare
	NSJZ L53	//QImode EQ
	CMP R1,8	// QImode compare
	NSJG L61	//QImode GT
	CMP R1,2	// QImode compare
	NSJZ L56	//QImode EQ
	CMP R1,2	// QImode compare
	NSJG L62	//QImode GT
	CMP R1,1	// QImode compare
	NSJZ L57	//QImode EQ
	pc=L59	// Indirect jump
L62:
	CMP R1,4	// QImode compare
	NSJZ L55	//QImode EQ
	pc=L59	// Indirect jump
L61:
	CMP R1,32	// QImode compare
	NSJZ L49	//QImode EQ
	CMP R1,32	// QImode compare
	NSJG L63	//QImode GT
	CMP R1,16	// QImode compare
	NSJZ L51	//QImode EQ
	pc=L59	// Indirect jump
L63:
	CMP R1,64	// QImode compare
	NSJZ L47	//QImode EQ
	CMP R1,128	// QImode compare
	NSJZ L46	//QImode EQ
	pc=L59	// Indirect jump
L46:
.debug
	.dw '.stabn 0x44,0,96,',0,0
	.dd LM52-_KeyScan
	.dw 0x0d,0x0a
.code
LM52:
	pc=L45	// Indirect jump
L47:
.debug
	.dw '.stabn 0x44,0,98,',0,0
	.dd LM53-_KeyScan
	.dw 0x0d,0x0a
.code
LM53:
	R1=[_freq]	// QImode move
	R2=100	// QImode move
	[_freq]=R1+R2  //addqi3_Qrr
.debug
	.dw '.stabn 0x44,0,99,',0,0
	.dd LM54-_KeyScan
	.dw 0x0d,0x0a
.code
LM54:
	R1=[_freq]	// QImode move
	CMP R1,19999	// QImode compare
	NSJNA L48	//QImode LEU
.debug
	.dw '.stabn 0x44,0,101,',0,0
	.dd LM55-_KeyScan
	.dw 0x0d,0x0a
.code
LM55:
	R1=100	// QImode move
	[_freq]=R1	// QImode move
L48:
.debug
	.dw '.stabn 0x44,0,103,',0,0
	.dd LM56-_KeyScan
	.dw 0x0d,0x0a
.code
LM56:
	R1=255	// QImode move
	[SP--]=R1	// QImode move
	call _delay	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,104,',0,0
	.dd LM57-_KeyScan
	.dw 0x0d,0x0a
.code
LM57:
	pc=L45	// Indirect jump
L49:
.debug
	.dw '.stabn 0x44,0,106,',0,0
	.dd LM58-_KeyScan
	.dw 0x0d,0x0a
.code
LM58:
	R1=[_freq]	// QImode move
	R2=(-100)	// QImode move
	[_freq]=R1+R2  //addqi3_Qrr
.debug
	.dw '.stabn 0x44,0,107,',0,0
	.dd LM59-_KeyScan
	.dw 0x0d,0x0a
.code
LM59:
	R1=[_freq]	// QImode move
	CMP R1,0	// QImode test
	NSJNZ L50	//QImode NE
.debug
	.dw '.stabn 0x44,0,109,',0,0
	.dd LM60-_KeyScan
	.dw 0x0d,0x0a
.code
LM60:
	R1=20000	// QImode move
	[_freq]=R1	// QImode move
L50:
.debug
	.dw '.stabn 0x44,0,111,',0,0
	.dd LM61-_KeyScan
	.dw 0x0d,0x0a
.code
LM61:
	R1=255	// QImode move
	[SP--]=R1	// QImode move
	call _delay	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,112,',0,0
	.dd LM62-_KeyScan
	.dw 0x0d,0x0a
.code
LM62:
	pc=L45	// Indirect jump
L51:
.debug
	.dw '.stabn 0x44,0,114,',0,0
	.dd LM63-_KeyScan
	.dw 0x0d,0x0a
.code
LM63:
	R1=[_vol]	// QImode move
	CMP R1,50	// QImode compare
	NSJNZ L52	//QImode NE
.debug
	.dw '.stabn 0x44,0,116,',0,0
	.dd LM64-_KeyScan
	.dw 0x0d,0x0a
.code
LM64:
	R1=0	// QImode move
	[_vol]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,117,',0,0
	.dd LM65-_KeyScan
	.dw 0x0d,0x0a
.code
LM65:
	pc=L45	// Indirect jump
L52:
.debug
	.dw '.stabn 0x44,0,119,',0,0
	.dd LM66-_KeyScan
	.dw 0x0d,0x0a
.code
LM66:
	R1=255	// QImode move
	[SP--]=R1	// QImode move
	call _delay	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,120,',0,0
	.dd LM67-_KeyScan
	.dw 0x0d,0x0a
.code
LM67:
	R1=[_vol]	// QImode move
	R2=1	// QImode move
	[_vol]=R1+R2  //addqi3_Qrr
.debug
	.dw '.stabn 0x44,0,121,',0,0
	.dd LM68-_KeyScan
	.dw 0x0d,0x0a
.code
LM68:
	pc=L45	// Indirect jump
L53:
.debug
	.dw '.stabn 0x44,0,123,',0,0
	.dd LM69-_KeyScan
	.dw 0x0d,0x0a
.code
LM69:
	R1=[_vol]	// QImode move
	CMP R1,0	// QImode test
	NSJNZ L54	//QImode NE
.debug
	.dw '.stabn 0x44,0,125,',0,0
	.dd LM70-_KeyScan
	.dw 0x0d,0x0a
.code
LM70:
	R1=50	// QImode move
	[_vol]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,126,',0,0
	.dd LM71-_KeyScan
	.dw 0x0d,0x0a
.code
LM71:
	pc=L45	// Indirect jump
L54:
.debug
	.dw '.stabn 0x44,0,128,',0,0
	.dd LM72-_KeyScan
	.dw 0x0d,0x0a
.code
LM72:
	R1=[_vol]	// QImode move
	R2=(-1)	// QImode move
	[_vol]=R1+R2  //addqi3_Qrr
.debug
	.dw '.stabn 0x44,0,129,',0,0
	.dd LM73-_KeyScan
	.dw 0x0d,0x0a
.code
LM73:
	R1=255	// QImode move
	[SP--]=R1	// QImode move
	call _delay	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,130,',0,0
	.dd LM74-_KeyScan
	.dw 0x0d,0x0a
.code
LM74:
	pc=L45	// Indirect jump
L55:
.debug
	.dw '.stabn 0x44,0,132,',0,0
	.dd LM75-_KeyScan
	.dw 0x0d,0x0a
.code
LM75:
	call _storemem	// call without return value
.debug
	.dw '.stabn 0x44,0,133,',0,0
	.dd LM76-_KeyScan
	.dw 0x0d,0x0a
.code
LM76:
	R1=255	// QImode move
	[SP--]=R1	// QImode move
	call _delay	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,134,',0,0
	.dd LM77-_KeyScan
	.dw 0x0d,0x0a
.code
LM77:
	pc=L45	// Indirect jump
L56:
.debug
	.dw '.stabn 0x44,0,136,',0,0
	.dd LM78-_KeyScan
	.dw 0x0d,0x0a
.code
LM78:
	call _clearmem	// call without return value
.debug
	.dw '.stabn 0x44,0,137,',0,0
	.dd LM79-_KeyScan
	.dw 0x0d,0x0a
.code
LM79:
	R1=255	// QImode move
	[SP--]=R1	// QImode move
	call _delay	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,138,',0,0
	.dd LM80-_KeyScan
	.dw 0x0d,0x0a
.code
LM80:
	pc=L45	// Indirect jump
L57:
.debug
	.dw '.stabn 0x44,0,140,',0,0
	.dd LM81-_KeyScan
	.dw 0x0d,0x0a
.code
LM81:
	R1=[_mode]	// QImode move
	R2=1	// QImode move
	[_mode]=R1+R2  //addqi3_Qrr
.debug
	.dw '.stabn 0x44,0,141,',0,0
	.dd LM82-_KeyScan
	.dw 0x0d,0x0a
.code
LM82:
	R1=[_mode]	// QImode move
	CMP R1,4	// QImode compare
	NSJNZ L58	//QImode NE
.debug
	.dw '.stabn 0x44,0,143,',0,0
	.dd LM83-_KeyScan
	.dw 0x0d,0x0a
.code
LM83:
	R1=0	// QImode move
	[_mode]=R1	// QImode move
L58:
.debug
	.dw '.stabn 0x44,0,145,',0,0
	.dd LM84-_KeyScan
	.dw 0x0d,0x0a
.code
LM84:
	R1=4095	// QImode move
	[SP--]=R1	// QImode move
	call _delay	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,146,',0,0
	.dd LM85-_KeyScan
	.dw 0x0d,0x0a
.code
LM85:
	pc=L45	// Indirect jump
L59:
.debug
	.dw '.stabn 0x44,0,148,',0,0
	.dd LM86-_KeyScan
	.dw 0x0d,0x0a
.code
LM86:
	pc=L45	// Indirect jump
L45:
.debug
	.dw '.stabn 0x44,0,150,',0,0
	.dd LM87-_KeyScan
	.dw 0x0d,0x0a
.code
LM87:
	R1=[_vol]	// QImode move
	[SP--]=R1	// QImode move
	R1=[_freq]	// QImode move
	[SP--]=R1	// QImode move
	R1=[_mode]	// QImode move
	[SP--]=R1	// QImode move
	call _show	// call without return value
	SP = SP + 3	//SP
.debug
	.dw '.stabn 0x44,0,151,',0,0
	.dd LM88-_KeyScan
	.dw 0x0d,0x0a
.code
LM88:
LBE4:
.debug
	.dw '.stabn 0x44,0,151,',0,0
	.dd LM89-_KeyScan
	.dw 0x0d,0x0a
.code
LM89:
L43:

	sp+=3
	pop bp from [sp]
	retf
	.endp	// end of KeyScan

.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB4-_KeyScan
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "temp:1",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "value:1",128,0,0,1',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE4-_KeyScan
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME5-_KeyScan
	.dw 0x0d,0x0a
.code
LME5:
.code
.debug
	.dw '.stabs "sendword:F19",36,0,0,',0,0,offset _sendword,seg _sendword,0x0d,0x0a
.CODE
.public _sendword
_sendword:	.proc
.debug
	.dw '.stabs "H:/key/key/my7219.h",0x84,0,0,',0,0,offset Ltext2, seg Ltext2,0x0d,0x0a
.code
.code
Ltext2:
.debug
	.dw '.stabn 0x44,0,36,',0,0
	.dd LM90-_sendword
	.dw 0x0d,0x0a
.code
LM90:
	// total=2, vars=2
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=2
	bp=sp+1

	R1=BP+5
.debug
	.dw '.stabn 0x44,0,37,',0,0
	.dd LM91-_sendword
	.dw 0x0d,0x0a
.code
LM91:
LBB5:
.debug
	.dw '.stabn 0x44,0,38,',0,0
	.dd LM92-_sendword
	.dw 0x0d,0x0a
.code
LM92:
	R2=[28677]	// QImode move
	R3=R2&(-16385)
	[28677]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,39,',0,0
	.dd LM93-_sendword
	.dw 0x0d,0x0a
.code
LM93:
	R2=0	// QImode move
	[BP]=R2	// QImode move
L82:
	R2=[BP]	// QImode move
	CMP R2,15	// QImode compare
	NSJNG L85	//QImode LE
	pc=L83	// Indirect jump
L85:
.debug
	.dw '.stabn 0x44,0,41,',0,0
	.dd LM94-_sendword
	.dw 0x0d,0x0a
.code
LM94:
	R2=1	// QImode move
	[28690]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,42,',0,0
	.dd LM95-_sendword
	.dw 0x0d,0x0a
.code
LM95:
	R2=BP	// QImode move
	R3=BP+1
	R2=R1	// QImode move
	R2=[R2]	// QImode move
	R4=R2&(-32768)
	R2=R3	// QImode move
	[R2]=R4	// QImode move
.debug
	.dw '.stabn 0x44,0,43,',0,0
	.dd LM96-_sendword
	.dw 0x0d,0x0a
.code
LM96:
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	R3=R2 lsl 1
	R4=R1	// QImode move
	[R4]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,44,',0,0
	.dd LM97-_sendword
	.dw 0x0d,0x0a
.code
LM97:
	R2=BP	// QImode move
	R3=BP+1
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	CMP R2,0	// QImode test
	NSJZ L86	//QImode EQ
.debug
	.dw '.stabn 0x44,0,46,',0,0
	.dd LM98-_sendword
	.dw 0x0d,0x0a
.code
LM98:
	R2=[28677]	// QImode move
	R3=R2|(-32768)
	[28677]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,47,',0,0
	.dd LM99-_sendword
	.dw 0x0d,0x0a
.code
LM99:
	R2=[28677]	// QImode move
	R3=R2&(-8193)
	[28677]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,48,',0,0
	.dd LM100-_sendword
	.dw 0x0d,0x0a
.code
LM100:
	R2=[28677]	// QImode move
	R3=R2|8192
	[28677]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,49,',0,0
	.dd LM101-_sendword
	.dw 0x0d,0x0a
.code
LM101:
	pc=L84	// Indirect jump
L86:
.debug
	.dw '.stabn 0x44,0,52,',0,0
	.dd LM102-_sendword
	.dw 0x0d,0x0a
.code
LM102:
	R2=[28677]	// QImode move
	R3=R2&32767
	[28677]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,53,',0,0
	.dd LM103-_sendword
	.dw 0x0d,0x0a
.code
LM103:
	R2=[28677]	// QImode move
	R3=R2&(-8193)
	[28677]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,54,',0,0
	.dd LM104-_sendword
	.dw 0x0d,0x0a
.code
LM104:
	R2=[28677]	// QImode move
	R3=R2|8192
	[28677]=R3	// QImode move
L87:
.debug
	.dw '.stabn 0x44,0,39,',0,0
	.dd LM105-_sendword
	.dw 0x0d,0x0a
.code
LM105:
L84:
	R2=[BP]	// QImode move
	R3=R2+1
	[BP]=R3	// QImode move
	pc=L82	// Indirect jump
L83:
.debug
	.dw '.stabn 0x44,0,57,',0,0
	.dd LM106-_sendword
	.dw 0x0d,0x0a
.code
LM106:
	R2=[28677]	// QImode move
	R3=R2|16384
	[28677]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,58,',0,0
	.dd LM107-_sendword
	.dw 0x0d,0x0a
.code
LM107:
	R2=1	// QImode move
	[28690]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,59,',0,0
	.dd LM108-_sendword
	.dw 0x0d,0x0a
.code
LM108:
LBE5:
.debug
	.dw '.stabn 0x44,0,59,',0,0
	.dd LM109-_sendword
	.dw 0x0d,0x0a
.code
LM109:
L81:

	sp+=2
	pop bp from [sp]
	retf
	.endp	// end of sendword

.debug
	.dw '.stabs "word:p4",160,0,0,5',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB5-_sendword
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
	.dd LBE5-_sendword
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME6-_sendword
	.dw 0x0d,0x0a
.code
LME6:
.code
.debug
	.dw '.stabs "init7219:F19",36,0,0,',0,0,offset _init7219,seg _init7219,0x0d,0x0a
.CODE
.public _init7219
_init7219:	.proc
.debug
	.dw '.stabn 0x44,0,61,',0,0
	.dd LM110-_init7219
	.dw 0x0d,0x0a
.code
LM110:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,62,',0,0
	.dd LM111-_init7219
	.dw 0x0d,0x0a
.code
LM111:
	R1=[28679]	// QImode move
	R2=R1|(-4096)
	[28679]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,63,',0,0
	.dd LM112-_init7219
	.dw 0x0d,0x0a
.code
LM112:
	R1=[28680]	// QImode move
	R2=R1|(-4096)
	[28680]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,64,',0,0
	.dd LM113-_init7219
	.dw 0x0d,0x0a
.code
LM113:
	R1=[28677]	// QImode move
	R2=R1&4095
	[28677]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,65,',0,0
	.dd LM114-_init7219
	.dw 0x0d,0x0a
.code
LM114:
	R1=2823	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,66,',0,0
	.dd LM115-_init7219
	.dw 0x0d,0x0a
.code
LM115:
	R1=2559	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,67,',0,0
	.dd LM116-_init7219
	.dw 0x0d,0x0a
.code
LM116:
	R1=2570	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,68,',0,0
	.dd LM117-_init7219
	.dw 0x0d,0x0a
.code
LM117:
	R1=3073	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,69,',0,0
	.dd LM118-_init7219
	.dw 0x0d,0x0a
.code
LM118:
	R1=3841	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,70,',0,0
	.dd LM119-_init7219
	.dw 0x0d,0x0a
.code
LM119:
	R1=3840	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,71,',0,0
	.dd LM120-_init7219
	.dw 0x0d,0x0a
.code
LM120:
.debug
	.dw '.stabn 0x44,0,71,',0,0
	.dd LM121-_init7219
	.dw 0x0d,0x0a
.code
LM121:
L90:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of init7219

.debug
	.dw '.stabf ',0,0
	.dd LME7-_init7219
	.dw 0x0d,0x0a
.code
LME7:
.code
.debug
	.dw '.stabs "show:F19",36,0,0,',0,0,offset _show,seg _show,0x0d,0x0a
.CODE
.public _show
_show:	.proc
.debug
	.dw '.stabn 0x44,0,80,',0,0
	.dd LM122-_show
	.dw 0x0d,0x0a
.code
LM122:
	// total=14, vars=14
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=14
	bp=sp+1

	R1=BP+17
	[bp+8]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,81,',0,0
	.dd LM123-_show
	.dw 0x0d,0x0a
.code
LM123:
LBB6:
.debug
	.dw '.stabn 0x44,0,83,',0,0
	.dd LM124-_show
	.dw 0x0d,0x0a
.code
LM124:
	R1=[28679]	// QImode move
	R2=R1|(-4096)
	[28679]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,84,',0,0
	.dd LM125-_show
	.dw 0x0d,0x0a
.code
LM125:
	R1=[28680]	// QImode move
	R2=R1|(-4096)
	[28680]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,85,',0,0
	.dd LM126-_show
	.dw 0x0d,0x0a
.code
LM126:
	R1=[28677]	// QImode move
	R2=R1&4095
	[28677]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,86,',0,0
	.dd LM127-_show
	.dw 0x0d,0x0a
.code
LM127:
	R1=2823	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,87,',0,0
	.dd LM128-_show
	.dw 0x0d,0x0a
.code
LM128:
	R1=2559	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,88,',0,0
	.dd LM129-_show
	.dw 0x0d,0x0a
.code
LM129:
	R1=2570	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,89,',0,0
	.dd LM130-_show
	.dw 0x0d,0x0a
.code
LM130:
	R1=3073	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,91,',0,0
	.dd LM131-_show
	.dw 0x0d,0x0a
.code
LM131:
	R2=[bp+8]	// QImode move
	R1=[R2]	// QImode move
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,92,',0,0
	.dd LM132-_show
	.dw 0x0d,0x0a
.code
LM132:
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
	.dd LM133-_show
	.dw 0x0d,0x0a
.code
LM133:
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
	.dd LM134-_show
	.dw 0x0d,0x0a
.code
LM134:
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
	.dd LM135-_show
	.dw 0x0d,0x0a
.code
LM135:
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
	.dd LM136-_show
	.dw 0x0d,0x0a
.code
LM136:
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
	.dd LM137-_show
	.dw 0x0d,0x0a
.code
LM137:
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
	.dd LM138-_show
	.dw 0x0d,0x0a
.code
LM138:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,99,',0,0
	.dd LM139-_show
	.dw 0x0d,0x0a
.code
LM139:
	R2=[BP]	// QImode move
	R1=R2|2048
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,100,',0,0
	.dd LM140-_show
	.dw 0x0d,0x0a
.code
LM140:
	R1=1807	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,101,',0,0
	.dd LM141-_show
	.dw 0x0d,0x0a
.code
LM141:
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
	.dd LM142-_show
	.dw 0x0d,0x0a
.code
LM142:
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
	.dd LM143-_show
	.dw 0x0d,0x0a
.code
LM143:
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
	.dd LM144-_show
	.dw 0x0d,0x0a
.code
LM144:
	R1=783	// QImode move
	[SP--]=R1	// QImode move
	call _sendword	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,105,',0,0
	.dd LM145-_show
	.dw 0x0d,0x0a
.code
LM145:
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
	.dd LM146-_show
	.dw 0x0d,0x0a
.code
LM146:
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
	.dd LM147-_show
	.dw 0x0d,0x0a
.code
LM147:
LBE6:
.debug
	.dw '.stabn 0x44,0,107,',0,0
	.dd LM148-_show
	.dw 0x0d,0x0a
.code
LM148:
L91:

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
	.dd LBB6-_show
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "tmp:20=ar1;0;7;1",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE6-_show
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME8-_show
	.dw 0x0d,0x0a
.code
LME8:
.code
.debug
	.dw '.stabs "initwave:F19",36,0,0,',0,0,offset _initwave,seg _initwave,0x0d,0x0a
.CODE
.public _initwave
_initwave:	.proc
.debug
	.dw '.stabs "H:/key/key/wave.h",0x84,0,0,',0,0,offset Ltext3, seg Ltext3,0x0d,0x0a
.code
.code
Ltext3:
.debug
	.dw '.stabn 0x44,0,11,',0,0
	.dd LM149-_initwave
	.dw 0x0d,0x0a
.code
LM149:
	// total=5, vars=5
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=5
	bp=sp+1

	R1=BP+8
	[bp+1]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,12,',0,0
	.dd LM150-_initwave
	.dw 0x0d,0x0a
.code
LM150:
LBB7:
.debug
	.dw '.stabn 0x44,0,13,',0,0
	.dd LM151-_initwave
	.dw 0x0d,0x0a
.code
LM151:
	R1=0	// QImode move
	[28714]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,14,',0,0
	.dd LM152-_initwave
	.dw 0x0d,0x0a
.code
LM152:
	R1=0	// QImode move
	[BP]=R1	// QImode move
L93:
	R1=[BP]	// QImode move
	CMP R1,255	// QImode compare
	NSJNG L96	//QImode LE
	pc=L94	// Indirect jump
L96:
.debug
	.dw '.stabn 0x44,0,16,',0,0
	.dd LM153-_initwave
	.dw 0x0d,0x0a
.code
LM153:
	R1=_SINE	// QImode move
	R2=[BP]	// QImode move
	R1 = R1 + R2	//addqi3
	R2=_SINE	// QImode move
	R3=[BP]	// QImode move
	R2 = R2 + R3	//addqi3
	R4=R2	// QImode move
	R3=[R4]	// QImode move
	R2=R3 lsl 2
	R2=R2 lsl 4
	R3=R1	// QImode move
	[R3]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,17,',0,0
	.dd LM154-_initwave
	.dw 0x0d,0x0a
.code
LM154:
	R1=_SINE	// QImode move
	R2=[BP]	// QImode move
	[bp+2]=R1	// QImode move
	R4=[bp+2]	// QImode move
	R4 = R4 + R2	//addqi3
	[bp+2]=R4	// QImode move
	R1=_SINE	// QImode move
	R3=[BP]	// QImode move
	R2=R1	// QImode move
	R2 = R2 + R3	//addqi3
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	R2=50	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __divu1	// call with return value
	SP = SP + 2	//SP
	R4=[bp+2]	// QImode move
	[R4]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,18,',0,0
	.dd LM155-_initwave
	.dw 0x0d,0x0a
.code
LM155:
	R1=_SQUR	// QImode move
	R2=[BP]	// QImode move
	[bp+3]=R1	// QImode move
	R1=[bp+3]	// QImode move
	R1 = R1 + R2	//addqi3
	[bp+3]=R1	// QImode move
	R1=_SQUR	// QImode move
	R3=[BP]	// QImode move
	R2=R1	// QImode move
	R2 = R2 + R3	//addqi3
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	R2=50	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __divu1	// call with return value
	SP = SP + 2	//SP
	R4=[bp+3]	// QImode move
	[R4]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,19,',0,0
	.dd LM156-_initwave
	.dw 0x0d,0x0a
.code
LM156:
	R1=_TRIG	// QImode move
	R2=[BP]	// QImode move
	[bp+4]=R1	// QImode move
	R1=[bp+4]	// QImode move
	R1 = R1 + R2	//addqi3
	[bp+4]=R1	// QImode move
	R1=_TRIG	// QImode move
	R3=[BP]	// QImode move
	R2=R1	// QImode move
	R2 = R2 + R3	//addqi3
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	R2=30	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __divu1	// call with return value
	SP = SP + 2	//SP
	R4=[bp+4]	// QImode move
	[R4]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,20,',0,0
	.dd LM157-_initwave
	.dw 0x0d,0x0a
.code
LM157:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,14,',0,0
	.dd LM158-_initwave
	.dw 0x0d,0x0a
.code
LM158:
L95:
	R1=[BP]	// QImode move
	R2=R1+1
	[BP]=R2	// QImode move
	pc=L93	// Indirect jump
L94:
.debug
	.dw '.stabn 0x44,0,22,',0,0
	.dd LM159-_initwave
	.dw 0x0d,0x0a
.code
LM159:
LBE7:
.debug
	.dw '.stabn 0x44,0,22,',0,0
	.dd LM160-_initwave
	.dw 0x0d,0x0a
.code
LM160:
L92:

	sp+=5
	pop bp from [sp]
	retf
	.endp	// end of initwave

.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB7-_initwave
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "i:1",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE7-_initwave
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME9-_initwave
	.dw 0x0d,0x0a
.code
LME9:
.code
.debug
	.dw '.stabs "wave:F19",36,0,0,',0,0,offset _wave,seg _wave,0x0d,0x0a
.CODE
.public _wave
_wave:	.proc
.debug
	.dw '.stabn 0x44,0,24,',0,0
	.dd LM161-_wave
	.dw 0x0d,0x0a
.code
LM161:
	// total=2, vars=2
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=2
	bp=sp+1

	R1=BP+5
	[bp+1]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,25,',0,0
	.dd LM162-_wave
	.dw 0x0d,0x0a
.code
LM162:
LBB8:
.debug
	.dw '.stabn 0x44,0,26,',0,0
	.dd LM163-_wave
	.dw 0x0d,0x0a
.code
LM163:
	R1=[_mode]	// QImode move
	CMP R1,0	// QImode test
	NSJNZ L99	//QImode NE
.debug
	.dw '.stabn 0x44,0,28,',0,0
	.dd LM164-_wave
	.dw 0x0d,0x0a
.code
LM164:
	R1=0	// QImode move
	[BP]=R1	// QImode move
L100:
	R1=[BP]	// QImode move
	CMP R1,255	// QImode compare
	NSJNG L103	//QImode LE
	pc=L101	// Indirect jump
L103:
.debug
	.dw '.stabn 0x44,0,30,',0,0
	.dd LM165-_wave
	.dw 0x0d,0x0a
.code
LM165:
	R1=_SINE	// QImode move
	R2=[BP]	// QImode move
	R1 = R1 + R2	//addqi3
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	R1=[_vol]	// QImode move
	mr=R2*R1	// r3=R2*R1 16bit=16bit*16bit
	[28695]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,31,',0,0
	.dd LM166-_wave
	.dw 0x0d,0x0a
.code
LM166:
	R1=[_freq]	// QImode move
	R2=100	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __divu1	// call with return value
	SP = SP + 2	//SP
	R3=200	// QImode move
	R2=R3	// QImode move
	R2 = R2 - R1	//subqi3
	[SP--]=R2	// QImode move
	call _delay	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,32,',0,0
	.dd LM167-_wave
	.dw 0x0d,0x0a
.code
LM167:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,28,',0,0
	.dd LM168-_wave
	.dw 0x0d,0x0a
.code
LM168:
L102:
	R1=[BP]	// QImode move
	R2=R1+1
	[BP]=R2	// QImode move
	pc=L100	// Indirect jump
L101:
.debug
	.dw '.stabn 0x44,0,34,',0,0
	.dd LM169-_wave
	.dw 0x0d,0x0a
.code
LM169:
	pc=L98	// Indirect jump
L99:
.debug
	.dw '.stabn 0x44,0,36,',0,0
	.dd LM170-_wave
	.dw 0x0d,0x0a
.code
LM170:
	R1=[_mode]	// QImode move
	CMP R1,1	// QImode compare
	NSJNZ L104	//QImode NE
.debug
	.dw '.stabn 0x44,0,38,',0,0
	.dd LM171-_wave
	.dw 0x0d,0x0a
.code
LM171:
	R1=0	// QImode move
	[BP]=R1	// QImode move
L105:
	R1=[BP]	// QImode move
	CMP R1,255	// QImode compare
	NSJNG L108	//QImode LE
	pc=L106	// Indirect jump
L108:
.debug
	.dw '.stabn 0x44,0,40,',0,0
	.dd LM172-_wave
	.dw 0x0d,0x0a
.code
LM172:
	R1=_SQUR	// QImode move
	R2=[BP]	// QImode move
	R1 = R1 + R2	//addqi3
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	R1=[_vol]	// QImode move
	mr=R2*R1	// r3=R2*R1 16bit=16bit*16bit
	[28695]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,41,',0,0
	.dd LM173-_wave
	.dw 0x0d,0x0a
.code
LM173:
	R1=[_freq]	// QImode move
	R2=100	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __divu1	// call with return value
	SP = SP + 2	//SP
	R3=200	// QImode move
	R2=R3	// QImode move
	R2 = R2 - R1	//subqi3
	[SP--]=R2	// QImode move
	call _delay	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,42,',0,0
	.dd LM174-_wave
	.dw 0x0d,0x0a
.code
LM174:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,38,',0,0
	.dd LM175-_wave
	.dw 0x0d,0x0a
.code
LM175:
L107:
	R1=[BP]	// QImode move
	R2=R1+1
	[BP]=R2	// QImode move
	pc=L105	// Indirect jump
L106:
.debug
	.dw '.stabn 0x44,0,44,',0,0
	.dd LM176-_wave
	.dw 0x0d,0x0a
.code
LM176:
	pc=L98	// Indirect jump
L104:
.debug
	.dw '.stabn 0x44,0,46,',0,0
	.dd LM177-_wave
	.dw 0x0d,0x0a
.code
LM177:
	R1=[_mode]	// QImode move
	CMP R1,2	// QImode compare
	NSJNZ L109	//QImode NE
.debug
	.dw '.stabn 0x44,0,48,',0,0
	.dd LM178-_wave
	.dw 0x0d,0x0a
.code
LM178:
	R1=0	// QImode move
	[BP]=R1	// QImode move
L110:
	R1=[BP]	// QImode move
	CMP R1,255	// QImode compare
	NSJNG L113	//QImode LE
	pc=L111	// Indirect jump
L113:
.debug
	.dw '.stabn 0x44,0,50,',0,0
	.dd LM179-_wave
	.dw 0x0d,0x0a
.code
LM179:
	R1=_TRIG	// QImode move
	R2=[BP]	// QImode move
	R1 = R1 + R2	//addqi3
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	R1=[_vol]	// QImode move
	mr=R2*R1	// r3=R2*R1 16bit=16bit*16bit
	[28695]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,51,',0,0
	.dd LM180-_wave
	.dw 0x0d,0x0a
.code
LM180:
	R1=[_freq]	// QImode move
	R2=100	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __divu1	// call with return value
	SP = SP + 2	//SP
	R3=200	// QImode move
	R2=R3	// QImode move
	R2 = R2 - R1	//subqi3
	[SP--]=R2	// QImode move
	call _delay	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,52,',0,0
	.dd LM181-_wave
	.dw 0x0d,0x0a
.code
LM181:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,48,',0,0
	.dd LM182-_wave
	.dw 0x0d,0x0a
.code
LM182:
L112:
	R1=[BP]	// QImode move
	R2=R1+1
	[BP]=R2	// QImode move
	pc=L110	// Indirect jump
L111:
.debug
	.dw '.stabn 0x44,0,54,',0,0
	.dd LM183-_wave
	.dw 0x0d,0x0a
.code
LM183:
	pc=L98	// Indirect jump
L109:
.debug
	.dw '.stabn 0x44,0,56,',0,0
	.dd LM184-_wave
	.dw 0x0d,0x0a
.code
LM184:
	R1=[_mode]	// QImode move
	CMP R1,3	// QImode compare
	NSJNZ L114	//QImode NE
.debug
	.dw '.stabn 0x44,0,58,',0,0
	.dd LM185-_wave
	.dw 0x0d,0x0a
.code
LM185:
	R1=0	// QImode move
	[BP]=R1	// QImode move
L115:
	R1=[BP]	// QImode move
	CMP R1,255	// QImode compare
	NSJNG L118	//QImode LE
	pc=L116	// Indirect jump
L118:
.debug
	.dw '.stabn 0x44,0,60,',0,0
	.dd LM186-_wave
	.dw 0x0d,0x0a
.code
LM186:
	R1=_mem_table	// QImode move
	R2=[BP]	// QImode move
	R1 = R1 + R2	//addqi3
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	R1=[_vol]	// QImode move
	mr=R2*R1	// r3=R2*R1 16bit=16bit*16bit
	[28695]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,61,',0,0
	.dd LM187-_wave
	.dw 0x0d,0x0a
.code
LM187:
	R1=[_freq]	// QImode move
	R2=100	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __divu1	// call with return value
	SP = SP + 2	//SP
	R3=200	// QImode move
	R2=R3	// QImode move
	R2 = R2 - R1	//subqi3
	[SP--]=R2	// QImode move
	call _delay	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,62,',0,0
	.dd LM188-_wave
	.dw 0x0d,0x0a
.code
LM188:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,58,',0,0
	.dd LM189-_wave
	.dw 0x0d,0x0a
.code
LM189:
L117:
	R1=[BP]	// QImode move
	R2=R1+1
	[BP]=R2	// QImode move
	pc=L115	// Indirect jump
L116:
.debug
	.dw '.stabn 0x44,0,64,',0,0
	.dd LM190-_wave
	.dw 0x0d,0x0a
.code
LM190:
	pc=L98	// Indirect jump
L114:
.debug
	.dw '.stabn 0x44,0,66,',0,0
	.dd LM191-_wave
	.dw 0x0d,0x0a
.code
LM191:
LBE8:
.debug
	.dw '.stabn 0x44,0,66,',0,0
	.dd LM192-_wave
	.dw 0x0d,0x0a
.code
LM192:
L98:

	sp+=2
	pop bp from [sp]
	retf
	.endp	// end of wave

.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB8-_wave
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "i:1",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE8-_wave
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME10-_wave
	.dw 0x0d,0x0a
.code
LME10:
.debug
	.dw '.stabs "mode:G4",32,0,0,',0,0,offset _mode,seg _mode,0x0d,0x0a
.CODE
.debug
	.dw '.stabs "freq:G4",32,0,0,',0,0,offset _freq,seg _freq,0x0d,0x0a
.CODE
.debug
	.dw '.stabs "vol:G4",32,0,0,',0,0,offset _vol,seg _vol,0x0d,0x0a
.CODE
.debug
	.dw '.stabs "index:G4",32,0,0,',0,0,offset _index,seg _index,0x0d,0x0a
.CODE
.public _SQUR
.iram
_SQUR:
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw -64
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 0
.debug
	.dw '.stabs "SQUR:G21=ar1;0;255;4",32,0,0,',0,0,offset _SQUR,seg _SQUR,0x0d,0x0a
.CODE
.public _TRIG
.iram
_TRIG:
	.dw 0
	.dw 261
	.dw 522
	.dw 783
	.dw 1044
	.dw 1306
	.dw 1567
	.dw 1828
	.dw 2089
	.dw 2351
	.dw 2612
	.dw 2873
	.dw 3134
	.dw 3395
	.dw 3657
	.dw 3918
	.dw 4179
	.dw 4440
	.dw 4702
	.dw 4963
	.dw 5224
	.dw 5485
	.dw 5746
	.dw 6008
	.dw 6269
	.dw 6530
	.dw 6791
	.dw 7053
	.dw 7314
	.dw 7575
	.dw 7836
	.dw 8097
	.dw 8359
	.dw 8620
	.dw 8881
	.dw 9142
	.dw 9404
	.dw 9665
	.dw 9926
	.dw 10187
	.dw 10448
	.dw 10710
	.dw 10971
	.dw 11232
	.dw 11493
	.dw 11755
	.dw 12016
	.dw 12277
	.dw 12538
	.dw 12800
	.dw 13061
	.dw 13322
	.dw 13583
	.dw 13844
	.dw 14106
	.dw 14367
	.dw 14628
	.dw 14889
	.dw 15151
	.dw 15412
	.dw 15673
	.dw 15934
	.dw 16195
	.dw 16457
	.dw 16718
	.dw 16979
	.dw 17240
	.dw 17502
	.dw 17763
	.dw 18024
	.dw 18285
	.dw 18546
	.dw 18808
	.dw 19069
	.dw 19330
	.dw 19591
	.dw 19853
	.dw 20114
	.dw 20375
	.dw 20636
	.dw 20897
	.dw 21159
	.dw 21420
	.dw 21681
	.dw 21942
	.dw 22204
	.dw 22465
	.dw 22726
	.dw 22987
	.dw 23248
	.dw 23510
	.dw 23771
	.dw 24032
	.dw 24293
	.dw 24555
	.dw 24816
	.dw 25077
	.dw 25338
	.dw 25600
	.dw 25861
	.dw 26122
	.dw 26383
	.dw 26644
	.dw 26906
	.dw 27167
	.dw 27428
	.dw 27689
	.dw 27951
	.dw 28212
	.dw 28473
	.dw 28734
	.dw 28995
	.dw 29257
	.dw 29518
	.dw 29779
	.dw 30040
	.dw 30302
	.dw 30563
	.dw 30824
	.dw 31085
	.dw 31346
	.dw 31608
	.dw 31869
	.dw 32130
	.dw 32391
	.dw 32653
	.dw -32622
	.dw -32361
	.dw -32100
	.dw -32361
	.dw -32622
	.dw 32653
	.dw 32391
	.dw 32130
	.dw 31869
	.dw 31608
	.dw 31346
	.dw 31085
	.dw 30824
	.dw 30563
	.dw 30302
	.dw 30040
	.dw 29779
	.dw 29518
	.dw 29257
	.dw 28995
	.dw 28734
	.dw 28473
	.dw 28212
	.dw 27951
	.dw 27689
	.dw 27428
	.dw 27167
	.dw 26906
	.dw 26644
	.dw 26383
	.dw 26122
	.dw 25861
	.dw 25600
	.dw 25338
	.dw 25077
	.dw 24816
	.dw 24555
	.dw 24293
	.dw 24032
	.dw 23771
	.dw 23510
	.dw 23248
	.dw 22987
	.dw 22726
	.dw 22465
	.dw 22204
	.dw 21942
	.dw 21681
	.dw 21420
	.dw 21159
	.dw 20897
	.dw 20636
	.dw 20375
	.dw 20114
	.dw 19853
	.dw 19591
	.dw 19330
	.dw 19069
	.dw 18808
	.dw 18546
	.dw 18285
	.dw 18024
	.dw 17763
	.dw 17502
	.dw 17240
	.dw 16979
	.dw 16718
	.dw 16457
	.dw 16195
	.dw 15934
	.dw 15673
	.dw 15412
	.dw 15151
	.dw 14889
	.dw 14628
	.dw 14367
	.dw 14106
	.dw 13844
	.dw 13583
	.dw 13322
	.dw 13061
	.dw 12800
	.dw 12538
	.dw 12277
	.dw 12016
	.dw 11755
	.dw 11493
	.dw 11232
	.dw 10971
	.dw 10710
	.dw 10448
	.dw 10187
	.dw 9926
	.dw 9665
	.dw 9404
	.dw 9142
	.dw 8881
	.dw 8620
	.dw 8359
	.dw 8097
	.dw 7836
	.dw 7575
	.dw 7314
	.dw 7053
	.dw 6791
	.dw 6530
	.dw 6269
	.dw 6008
	.dw 5746
	.dw 5485
	.dw 5224
	.dw 4963
	.dw 4702
	.dw 4440
	.dw 4179
	.dw 3918
	.dw 3657
	.dw 3395
	.dw 3134
	.dw 2873
	.dw 2612
	.dw 2351
	.dw 2089
	.dw 1828
	.dw 1567
	.dw 1306
	.dw 1044
	.dw 783
	.dw 522
	.dw 261
.debug
	.dw '.stabs "TRIG:G21",32,0,0,',0,0,offset _TRIG,seg _TRIG,0x0d,0x0a
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
	.dw '.stabs "SINE:G22=ar1;0;255;4",32,0,0,',0,0,offset _SINE,seg _SINE,0x0d,0x0a
.CODE
.debug
	.dw '.stabs "mem_table:G21",32,0,0,',0,0,offset _mem_table,seg _mem_table,0x0d,0x0a
.CODE
.code
.debug
	.dw '.stabs "main:F1",36,0,0,',0,0,offset _main,seg _main,0x0d,0x0a
.CODE
.public _main
_main:	.proc
.debug
	.dw '.stabs "H:/key/key/main.c",0x84,0,0,',0,0,offset Ltext4, seg Ltext4,0x0d,0x0a
.code
.code
Ltext4:
.debug
	.dw '.stabn 0x44,0,77,',0,0
	.dd LM193-_main
	.dw 0x0d,0x0a
.code
LM193:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,78,',0,0
	.dd LM194-_main
	.dw 0x0d,0x0a
.code
LM194:
	R1=0	// QImode move
	[_mode]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,79,',0,0
	.dd LM195-_main
	.dw 0x0d,0x0a
.code
LM195:
	R1=400	// QImode move
	[_freq]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,80,',0,0
	.dd LM196-_main
	.dw 0x0d,0x0a
.code
LM196:
	R1=20	// QImode move
	[_vol]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,81,',0,0
	.dd LM197-_main
	.dw 0x0d,0x0a
.code
LM197:
	call _init7219	// call without return value
.debug
	.dw '.stabn 0x44,0,82,',0,0
	.dd LM198-_main
	.dw 0x0d,0x0a
.code
LM198:
	call _initkey	// call without return value
.debug
	.dw '.stabn 0x44,0,83,',0,0
	.dd LM199-_main
	.dw 0x0d,0x0a
.code
LM199:
	call _initwave	// call without return value
.debug
	.dw '.stabn 0x44,0,84,',0,0
	.dd LM200-_main
	.dw 0x0d,0x0a
.code
LM200:
	R1=128	// QImode move
	[28691]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,85,',0,0
	.dd LM201-_main
	.dw 0x0d,0x0a
.code
LM201:
	R1=[_vol]	// QImode move
	[SP--]=R1	// QImode move
	R1=[_freq]	// QImode move
	[SP--]=R1	// QImode move
	R1=[_mode]	// QImode move
	[SP--]=R1	// QImode move
	call _show	// call without return value
	SP = SP + 3	//SP
.debug
	.dw '.stabn 0x44,0,86,',0,0
	.dd LM202-_main
	.dw 0x0d,0x0a
.code
LM202:
L128:
	pc=L130	// Indirect jump
	pc=L129	// Indirect jump
L130:
.debug
	.dw '.stabn 0x44,0,88,',0,0
	.dd LM203-_main
	.dw 0x0d,0x0a
.code
LM203:
	call _KeyScan	// call without return value
.debug
	.dw '.stabn 0x44,0,89,',0,0
	.dd LM204-_main
	.dw 0x0d,0x0a
.code
LM204:
	call _wave	// call without return value
.debug
	.dw '.stabn 0x44,0,90,',0,0
	.dd LM205-_main
	.dw 0x0d,0x0a
.code
LM205:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,91,',0,0
	.dd LM206-_main
	.dw 0x0d,0x0a
.code
LM206:
	pc=L128	// Indirect jump
L129:
.debug
	.dw '.stabn 0x44,0,92,',0,0
	.dd LM207-_main
	.dw 0x0d,0x0a
.code
LM207:
.debug
	.dw '.stabn 0x44,0,92,',0,0
	.dd LM208-_main
	.dw 0x0d,0x0a
.code
LM208:
L127:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of main

.debug
	.dw '.stabf ',0,0
	.dd LME11-_main
	.dw 0x0d,0x0a
.code
LME11:
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
.iram
.public _mem_table
_mem_table:
	.dw 256 dup(0)
.iram
.public _index
_index:
	.dw 0
.external __divu1
.external __modi1
.external __divi1
	.end

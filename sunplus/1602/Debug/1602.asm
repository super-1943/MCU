// GCC for SUNPLUS u'nSP version 1.0.21-3
// Command: D:\PROGRA~1\SunPlus\UNSPID~1.0\cc1.exe C:\DOCUME~1\a\LOCALS~1\Temp\ccE5aaaa.i -fkeep-inline-functions -quiet -dumpbase 1602.c -mglobal-var-iram -gstabs -Wall -o .\Debug/1602.asm
	.external __sn_func_ptr_sec

// gcc2_compiled.:

.debug
	.dw '.stabs "C:/Documents and Settings/a/My Documents/1602/",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
.code
.debug
	.dw '.stabs "C:/Documents and Settings/a/My Documents/1602/1602.c",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
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
	.dw '.stabn 0x44,0,38,',0,0
	.dd LM1-_delay
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
	.dw '.stabn 0x44,0,39,',0,0
	.dd LM2-_delay
	.dw 0x0d,0x0a
.code
LM2:
LBB2:
.debug
	.dw '.stabn 0x44,0,40,',0,0
	.dd LM3-_delay
	.dw 0x0d,0x0a
.code
LM3:
	R2=200	// QImode move
	[BP]=R2	// QImode move
L3:
	R2=[BP]	// QImode move
	CMP R2,0	// QImode test
	NSJNZ L6	//QImode NE
	pc=L4	// Indirect jump
L6:
.debug
	.dw '.stabn 0x44,0,41,',0,0
	.dd LM4-_delay
	.dw 0x0d,0x0a
.code
LM4:
	R2=BP	// QImode move
	R3=BP+1
	R2=10	// QImode move
	R4=R3	// QImode move
	[R4]=R2	// QImode move
L7:
	R2=BP	// QImode move
	R3=BP+1
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	CMP R2,0	// QImode test
	NSJNZ L10	//QImode NE
	pc=L5	// Indirect jump
L10:
.debug
	.dw '.stabn 0x44,0,42,',0,0
	.dd LM5-_delay
	.dw 0x0d,0x0a
.code
LM5:
	R2=1	// QImode move
	[28690]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,41,',0,0
	.dd LM6-_delay
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
	R4=R3+(-1)
	R3=R2	// QImode move
	[R3]=R4	// QImode move
	pc=L7	// Indirect jump
L8:
.debug
	.dw '.stabn 0x44,0,40,',0,0
	.dd LM7-_delay
	.dw 0x0d,0x0a
.code
LM7:
L5:
	R2=[BP]	// QImode move
	R3=R2+(-1)
	[BP]=R3	// QImode move
	pc=L3	// Indirect jump
L4:
.debug
	.dw '.stabn 0x44,0,43,',0,0
	.dd LM8-_delay
	.dw 0x0d,0x0a
.code
LM8:
LBE2:
.debug
	.dw '.stabn 0x44,0,43,',0,0
	.dd LM9-_delay
	.dw 0x0d,0x0a
.code
LM9:
L2:

	sp+=3
	pop bp from [sp]
	retf
	.endp	// end of delay

.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB2-_delay
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
	.dd LBE2-_delay
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME1-_delay
	.dw 0x0d,0x0a
.code
LME1:
.code
.debug
	.dw '.stabs "initport:F19",36,0,0,',0,0,offset _initport,seg _initport,0x0d,0x0a
.CODE
.public _initport
_initport:	.proc
.debug
	.dw '.stabn 0x44,0,45,',0,0
	.dd LM10-_initport
	.dw 0x0d,0x0a
.code
LM10:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,46,',0,0
	.dd LM11-_initport
	.dw 0x0d,0x0a
.code
LM11:
	R2=[28674]	// QImode move
	R3=R2|(-16)
	[28674]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,47,',0,0
	.dd LM12-_initport
	.dw 0x0d,0x0a
.code
LM12:
	R2=[28675]	// QImode move
	R3=R2|(-16)
	[28675]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,48,',0,0
	.dd LM13-_initport
	.dw 0x0d,0x0a
.code
LM13:
	R2=[28672]	// QImode move
	R3=R2&15
	[28672]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,49,',0,0
	.dd LM14-_initport
	.dw 0x0d,0x0a
.code
LM14:
.debug
	.dw '.stabn 0x44,0,49,',0,0
	.dd LM15-_initport
	.dw 0x0d,0x0a
.code
LM15:
L13:

	pop bp from [sp]
	retf
	.endp	// end of initport

.debug
	.dw '.stabf ',0,0
	.dd LME2-_initport
	.dw 0x0d,0x0a
.code
LME2:
.code
.debug
	.dw '.stabs "init1602:F19",36,0,0,',0,0,offset _init1602,seg _init1602,0x0d,0x0a
.CODE
.public _init1602
_init1602:	.proc
.debug
	.dw '.stabn 0x44,0,51,',0,0
	.dd LM16-_init1602
	.dw 0x0d,0x0a
.code
LM16:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,52,',0,0
	.dd LM17-_init1602
	.dw 0x0d,0x0a
.code
LM17:
	R1=[28672]	// QImode move
	R2=R1&255
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,53,',0,0
	.dd LM18-_init1602
	.dw 0x0d,0x0a
.code
LM18:
	R1=0	// QImode move
	[SP--]=R1	// QImode move
	R1=56	// QImode move
	[SP--]=R1	// QImode move
	call _writecommand	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,54,',0,0
	.dd LM19-_init1602
	.dw 0x0d,0x0a
.code
LM19:
	call _delay	// call without return value
.debug
	.dw '.stabn 0x44,0,55,',0,0
	.dd LM20-_init1602
	.dw 0x0d,0x0a
.code
LM20:
	R1=0	// QImode move
	[SP--]=R1	// QImode move
	R1=56	// QImode move
	[SP--]=R1	// QImode move
	call _writecommand	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,56,',0,0
	.dd LM21-_init1602
	.dw 0x0d,0x0a
.code
LM21:
	call _delay	// call without return value
.debug
	.dw '.stabn 0x44,0,57,',0,0
	.dd LM22-_init1602
	.dw 0x0d,0x0a
.code
LM22:
	R1=0	// QImode move
	[SP--]=R1	// QImode move
	R1=56	// QImode move
	[SP--]=R1	// QImode move
	call _writecommand	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,58,',0,0
	.dd LM23-_init1602
	.dw 0x0d,0x0a
.code
LM23:
	call _delay	// call without return value
.debug
	.dw '.stabn 0x44,0,59,',0,0
	.dd LM24-_init1602
	.dw 0x0d,0x0a
.code
LM24:
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	R1=56	// QImode move
	[SP--]=R1	// QImode move
	call _writecommand	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,60,',0,0
	.dd LM25-_init1602
	.dw 0x0d,0x0a
.code
LM25:
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	R1=8	// QImode move
	[SP--]=R1	// QImode move
	call _writecommand	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,61,',0,0
	.dd LM26-_init1602
	.dw 0x0d,0x0a
.code
LM26:
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	call _writecommand	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,62,',0,0
	.dd LM27-_init1602
	.dw 0x0d,0x0a
.code
LM27:
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	R1=6	// QImode move
	[SP--]=R1	// QImode move
	call _writecommand	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,63,',0,0
	.dd LM28-_init1602
	.dw 0x0d,0x0a
.code
LM28:
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	R1=12	// QImode move
	[SP--]=R1	// QImode move
	call _writecommand	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,64,',0,0
	.dd LM29-_init1602
	.dw 0x0d,0x0a
.code
LM29:
.debug
	.dw '.stabn 0x44,0,64,',0,0
	.dd LM30-_init1602
	.dw 0x0d,0x0a
.code
LM30:
L14:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of init1602

.debug
	.dw '.stabf ',0,0
	.dd LME3-_init1602
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
	.dw '.stabn 0x44,0,70,',0,0
	.dd LM31-_main
	.dw 0x0d,0x0a
.code
LM31:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,71,',0,0
	.dd LM32-_main
	.dw 0x0d,0x0a
.code
LM32:
	call _initport	// call without return value
.debug
	.dw '.stabn 0x44,0,72,',0,0
	.dd LM33-_main
	.dw 0x0d,0x0a
.code
LM33:
	call _init1602	// call without return value
.debug
	.dw '.stabn 0x44,0,73,',0,0
	.dd LM34-_main
	.dw 0x0d,0x0a
.code
LM34:
L16:
	pc=L18	// Indirect jump
	pc=L17	// Indirect jump
L18:
.debug
	.dw '.stabn 0x44,0,75,',0,0
	.dd LM35-_main
	.dw 0x0d,0x0a
.code
LM35:
	R1=48	// QImode move
	[SP--]=R1	// QImode move
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	call _displaychar	// call without return value
	SP = SP + 3	//SP
.debug
	.dw '.stabn 0x44,0,76,',0,0
	.dd LM36-_main
	.dw 0x0d,0x0a
.code
LM36:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,77,',0,0
	.dd LM37-_main
	.dw 0x0d,0x0a
.code
LM37:
	pc=L16	// Indirect jump
L17:
.debug
	.dw '.stabn 0x44,0,78,',0,0
	.dd LM38-_main
	.dw 0x0d,0x0a
.code
LM38:
.debug
	.dw '.stabn 0x44,0,78,',0,0
	.dd LM39-_main
	.dw 0x0d,0x0a
.code
LM39:
L15:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of main

.debug
	.dw '.stabf ',0,0
	.dd LME4-_main
	.dw 0x0d,0x0a
.code
LME4:
.code
.debug
	.dw '.stabs "writecommand:F19",36,0,0,',0,0,offset _writecommand,seg _writecommand,0x0d,0x0a
.CODE
.public _writecommand
_writecommand:	.proc
.debug
	.dw '.stabn 0x44,0,80,',0,0
	.dd LM40-_writecommand
	.dw 0x0d,0x0a
.code
LM40:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,81,',0,0
	.dd LM41-_writecommand
	.dw 0x0d,0x0a
.code
LM41:
	R1=[BP]	// QImode move
	R3=[BP]	// QImode move
	R2=R3+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	CMP R1,0	// QImode test
	NSJZ L20	//QImode EQ
.debug
	.dw '.stabn 0x44,0,83,',0,0
	.dd LM42-_writecommand
	.dw 0x0d,0x0a
.code
LM42:
	call _waitbusy	// call with return value
L20:
.debug
	.dw '.stabn 0x44,0,85,',0,0
	.dd LM43-_writecommand
	.dw 0x0d,0x0a
.code
LM43:
	R1=[28672]	// QImode move
	R2=R1&(-129)
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,86,',0,0
	.dd LM44-_writecommand
	.dw 0x0d,0x0a
.code
LM44:
	R1=[28672]	// QImode move
	R2=R1&(-65)
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,87,',0,0
	.dd LM45-_writecommand
	.dw 0x0d,0x0a
.code
LM45:
	R1=[28672]	// QImode move
	R2=R1&15
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,88,',0,0
	.dd LM46-_writecommand
	.dw 0x0d,0x0a
.code
LM46:
	R1=[BP]	// QImode move
	R2=[R1]	// QImode move
	R1=R2 lsl 4
	R1=R1 lsl 4
	R2=[28672]	// QImode move
	R3=R2	// QImode move
	R3|=R1
	R1=R3	// QImode move
	[28672]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,89,',0,0
	.dd LM47-_writecommand
	.dw 0x0d,0x0a
.code
LM47:
	R1=[28672]	// QImode move
	R2=R1&(-33)
	[28672]=R2	// QImode move
	R1=[28672]	// QImode move
	R2=R1&(-33)
	[28672]=R2	// QImode move
	R1=[28672]	// QImode move
	R2=R1&(-33)
	[28672]=R2	// QImode move
	R1=[28672]	// QImode move
	R2=R1&(-33)
	[28672]=R2	// QImode move
	R1=[28672]	// QImode move
	R2=R1|32
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,90,',0,0
	.dd LM48-_writecommand
	.dw 0x0d,0x0a
.code
LM48:
.debug
	.dw '.stabn 0x44,0,90,',0,0
	.dd LM49-_writecommand
	.dw 0x0d,0x0a
.code
LM49:
L19:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of writecommand

.debug
	.dw '.stabs "data:p2",160,0,0,4',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "busy:p2",160,0,0,5',0x0d,0x0a
.CODE
.debug
	.dw '.stabf ',0,0
	.dd LME5-_writecommand
	.dw 0x0d,0x0a
.code
LME5:
.code
.debug
	.dw '.stabs "writedata:F19",36,0,0,',0,0,offset _writedata,seg _writedata,0x0d,0x0a
.CODE
.public _writedata
_writedata:	.proc
.debug
	.dw '.stabn 0x44,0,92,',0,0
	.dd LM50-_writedata
	.dw 0x0d,0x0a
.code
LM50:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,93,',0,0
	.dd LM51-_writedata
	.dw 0x0d,0x0a
.code
LM51:
	call _waitbusy	// call with return value
.debug
	.dw '.stabn 0x44,0,94,',0,0
	.dd LM52-_writedata
	.dw 0x0d,0x0a
.code
LM52:
	R1=[28672]	// QImode move
	R2=R1&15
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,95,',0,0
	.dd LM53-_writedata
	.dw 0x0d,0x0a
.code
LM53:
	R3=[BP]	// QImode move
	R2=[R3]	// QImode move
	R1=R2 lsl 4
	R1=R1 lsl 4
	R2=[28672]	// QImode move
	R3=R2	// QImode move
	R3|=R1
	R1=R3	// QImode move
	[28672]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,96,',0,0
	.dd LM54-_writedata
	.dw 0x0d,0x0a
.code
LM54:
	R1=[28672]	// QImode move
	R2=R1&(-65)
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,97,',0,0
	.dd LM55-_writedata
	.dw 0x0d,0x0a
.code
LM55:
	R1=[28672]	// QImode move
	R2=R1&(-129)
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,98,',0,0
	.dd LM56-_writedata
	.dw 0x0d,0x0a
.code
LM56:
	R1=[28672]	// QImode move
	R2=R1&(-33)
	[28672]=R2	// QImode move
	R1=[28672]	// QImode move
	R2=R1&(-33)
	[28672]=R2	// QImode move
	R1=[28672]	// QImode move
	R2=R1&(-33)
	[28672]=R2	// QImode move
	R1=[28672]	// QImode move
	R2=R1&(-33)
	[28672]=R2	// QImode move
	R1=[28672]	// QImode move
	R2=R1|32
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,99,',0,0
	.dd LM57-_writedata
	.dw 0x0d,0x0a
.code
LM57:
.debug
	.dw '.stabn 0x44,0,99,',0,0
	.dd LM58-_writedata
	.dw 0x0d,0x0a
.code
LM58:
L22:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of writedata

.debug
	.dw '.stabs "data:p2",160,0,0,4',0x0d,0x0a
.CODE
.debug
	.dw '.stabf ',0,0
	.dd LME6-_writedata
	.dw 0x0d,0x0a
.code
LME6:
.code
.debug
	.dw '.stabs "waitbusy:F2",36,0,0,',0,0,offset _waitbusy,seg _waitbusy,0x0d,0x0a
.CODE
.public _waitbusy
_waitbusy:	.proc
.debug
	.dw '.stabn 0x44,0,101,',0,0
	.dd LM59-_waitbusy
	.dw 0x0d,0x0a
.code
LM59:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R2=BP+3
.debug
	.dw '.stabn 0x44,0,102,',0,0
	.dd LM60-_waitbusy
	.dw 0x0d,0x0a
.code
LM60:
	R1=[28672]	// QImode move
	R3=R1|(-256)
	[28672]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,103,',0,0
	.dd LM61-_waitbusy
	.dw 0x0d,0x0a
.code
LM61:
	R1=[28672]	// QImode move
	R3=R1&(-129)
	[28672]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,104,',0,0
	.dd LM62-_waitbusy
	.dw 0x0d,0x0a
.code
LM62:
	R1=[28672]	// QImode move
	R3=R1|64
	[28672]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,105,',0,0
	.dd LM63-_waitbusy
	.dw 0x0d,0x0a
.code
LM63:
	R1=[28672]	// QImode move
	R3=R1&(-33)
	[28672]=R3	// QImode move
	R1=[28672]	// QImode move
	R3=R1&(-33)
	[28672]=R3	// QImode move
	R1=[28672]	// QImode move
	R3=R1&(-33)
	[28672]=R3	// QImode move
	R1=[28672]	// QImode move
	R3=R1&(-33)
	[28672]=R3	// QImode move
	R1=[28672]	// QImode move
	R3=R1|32
	[28672]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,108,',0,0
	.dd LM64-_waitbusy
	.dw 0x0d,0x0a
.code
LM64:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,110,',0,0
	.dd LM65-_waitbusy
	.dw 0x0d,0x0a
.code
LM65:
	R1=[28672]	// QImode move
	R3=R1 lsr 4
	R3=R3 lsr 4
	R1=R3	// QImode move
	pc=L23	// Indirect jump
.debug
	.dw '.stabn 0x44,0,111,',0,0
	.dd LM66-_waitbusy
	.dw 0x0d,0x0a
.code
LM66:
.debug
	.dw '.stabn 0x44,0,111,',0,0
	.dd LM67-_waitbusy
	.dw 0x0d,0x0a
.code
LM67:
L23:

	pop bp from [sp]
	retf
	.endp	// end of waitbusy

.debug
	.dw '.stabf ',0,0
	.dd LME7-_waitbusy
	.dw 0x0d,0x0a
.code
LME7:
.code
.debug
	.dw '.stabs "readdata:F2",36,0,0,',0,0,offset _readdata,seg _readdata,0x0d,0x0a
.CODE
.public _readdata
_readdata:	.proc
.debug
	.dw '.stabn 0x44,0,113,',0,0
	.dd LM68-_readdata
	.dw 0x0d,0x0a
.code
LM68:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R2=BP+3
.debug
	.dw '.stabn 0x44,0,114,',0,0
	.dd LM69-_readdata
	.dw 0x0d,0x0a
.code
LM69:
	R1=[28672]	// QImode move
	R3=R1|64
	[28672]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,115,',0,0
	.dd LM70-_readdata
	.dw 0x0d,0x0a
.code
LM70:
	R1=[28672]	// QImode move
	R3=R1|128
	[28672]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,116,',0,0
	.dd LM71-_readdata
	.dw 0x0d,0x0a
.code
LM71:
	R1=[28672]	// QImode move
	R3=R1&(-33)
	[28672]=R3	// QImode move
	R1=[28672]	// QImode move
	R3=R1&(-33)
	[28672]=R3	// QImode move
	R1=[28672]	// QImode move
	R3=R1&(-33)
	[28672]=R3	// QImode move
	R1=[28672]	// QImode move
	R3=R1&(-33)
	[28672]=R3	// QImode move
	R1=[28672]	// QImode move
	R3=R1|32
	[28672]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,117,',0,0
	.dd LM72-_readdata
	.dw 0x0d,0x0a
.code
LM72:
	R1=[28672]	// QImode move
	R3=R1 lsr 4
	R3=R3 lsr 4
	R1=R3	// QImode move
	pc=L24	// Indirect jump
.debug
	.dw '.stabn 0x44,0,118,',0,0
	.dd LM73-_readdata
	.dw 0x0d,0x0a
.code
LM73:
.debug
	.dw '.stabn 0x44,0,118,',0,0
	.dd LM74-_readdata
	.dw 0x0d,0x0a
.code
LM74:
L24:

	pop bp from [sp]
	retf
	.endp	// end of readdata

.debug
	.dw '.stabf ',0,0
	.dd LME8-_readdata
	.dw 0x0d,0x0a
.code
LME8:
.code
.debug
	.dw '.stabs "displaychar:F19",36,0,0,',0,0,offset _displaychar,seg _displaychar,0x0d,0x0a
.CODE
.public _displaychar
_displaychar:	.proc
.debug
	.dw '.stabn 0x44,0,120,',0,0
	.dd LM75-_displaychar
	.dw 0x0d,0x0a
.code
LM75:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,121,',0,0
	.dd LM76-_displaychar
	.dw 0x0d,0x0a
.code
LM76:
	R2=[BP]	// QImode move
	R2=[BP]	// QImode move
	R1=R2+1
	R2=[BP]	// QImode move
	R4=[BP]	// QImode move
	R3=R4+1
	R2=R3	// QImode move
	R2=[R2]	// QImode move
	R4=R2&1
	R2=R1	// QImode move
	[R2]=R4	// QImode move
.debug
	.dw '.stabn 0x44,0,122,',0,0
	.dd LM77-_displaychar
	.dw 0x0d,0x0a
.code
LM77:
	R3=[BP]	// QImode move
	R4=[R3]	// QImode move
	R4=R4&15
	[R3]=R4	// QImode move
.debug
	.dw '.stabn 0x44,0,123,',0,0
	.dd LM78-_displaychar
	.dw 0x0d,0x0a
.code
LM78:
	R1=[BP]	// QImode move
	R1=[BP]	// QImode move
	R2=R1+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	CMP R1,0	// QImode test
	NSJZ L26	//QImode EQ
.debug
	.dw '.stabn 0x44,0,125,',0,0
	.dd LM79-_displaychar
	.dw 0x0d,0x0a
.code
LM79:
	R4=[BP]	// QImode move
	R1=[R4]	// QImode move
	R1=R1|64
	[R4]=R1	// QImode move
L26:
.debug
	.dw '.stabn 0x44,0,127,',0,0
	.dd LM80-_displaychar
	.dw 0x0d,0x0a
.code
LM80:
	R2=[BP]	// QImode move
	R3=[R2]	// QImode move
	R3=R3|128
	[R2]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,128,',0,0
	.dd LM81-_displaychar
	.dw 0x0d,0x0a
.code
LM81:
	R1=0	// QImode move
	[SP--]=R1	// QImode move
	R4=[BP]	// QImode move
	R1=[R4]	// QImode move
	[SP--]=R1	// QImode move
	call _writecommand	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,129,',0,0
	.dd LM82-_displaychar
	.dw 0x0d,0x0a
.code
LM82:
	R1=[BP]	// QImode move
	R1=[BP]	// QImode move
	R2=R1+2
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	call _writedata	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,130,',0,0
	.dd LM83-_displaychar
	.dw 0x0d,0x0a
.code
LM83:
.debug
	.dw '.stabn 0x44,0,130,',0,0
	.dd LM84-_displaychar
	.dw 0x0d,0x0a
.code
LM84:
L25:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of displaychar

.debug
	.dw '.stabs "x:p2",160,0,0,4',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "y:p2",160,0,0,5',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "data:p2",160,0,0,6',0x0d,0x0a
.CODE
.debug
	.dw '.stabf ',0,0
	.dd LME9-_displaychar
	.dw 0x0d,0x0a
.code
LME9:
	.end

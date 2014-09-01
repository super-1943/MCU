// GCC for SUNPLUS u'nSP version 1.0.21-3
// Command: C:\PROGRA~1\Sunplus\UNSPID~1.0\cc1.exe c:\temp\cc6daaaa.i -fkeep-inline-functions -quiet -dumpbase ziku12864.c -mglobal-var-iram -gstabs -Wall -o .\Debug/ziku12864.asm
	.external __sn_func_ptr_sec

// gcc2_compiled.:

.debug
	.dw '.stabs "E:/program/sun/yejing/",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
.code
.debug
	.dw '.stabs "E:/program/sun/yejing/ziku12864.c",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
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
	.dw '.stabs "init_12864:F19",36,0,0,',0,0,offset _init_12864,seg _init_12864,0x0d,0x0a
.CODE
.public _init_12864
_init_12864:	.proc
.debug
	.dw '.stabn 0x44,0,8,',0,0
	.dd LM1-_init_12864
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
	.dw '.stabn 0x44,0,10,',0,0
	.dd LM2-_init_12864
	.dw 0x0d,0x0a
.code
LM2:
	R1=[28674]	// QImode move
	R2=R1|56
	[28674]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,11,',0,0
	.dd LM3-_init_12864
	.dw 0x0d,0x0a
.code
LM3:
	R1=[28675]	// QImode move
	R2=R1|56
	[28675]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,12,',0,0
	.dd LM4-_init_12864
	.dw 0x0d,0x0a
.code
LM4:
	R1=[28672]	// QImode move
	R2=R1&(-57)
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,19,',0,0
	.dd LM5-_init_12864
	.dw 0x0d,0x0a
.code
LM5:
	R1=100	// QImode move
	[SP--]=R1	// QImode move
	call _delay_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,20,',0,0
	.dd LM6-_init_12864
	.dw 0x0d,0x0a
.code
LM6:
	R1=48	// QImode move
	[SP--]=R1	// QImode move
	call _write_cmd_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,21,',0,0
	.dd LM7-_init_12864
	.dw 0x0d,0x0a
.code
LM7:
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	call _write_cmd_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,22,',0,0
	.dd LM8-_init_12864
	.dw 0x0d,0x0a
.code
LM8:
	R1=12	// QImode move
	[SP--]=R1	// QImode move
	call _write_cmd_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,23,',0,0
	.dd LM9-_init_12864
	.dw 0x0d,0x0a
.code
LM9:
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	call _write_cmd_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,24,',0,0
	.dd LM10-_init_12864
	.dw 0x0d,0x0a
.code
LM10:
	R1=6	// QImode move
	[SP--]=R1	// QImode move
	call _write_cmd_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,25,',0,0
	.dd LM11-_init_12864
	.dw 0x0d,0x0a
.code
LM11:
	R1=100	// QImode move
	[SP--]=R1	// QImode move
	call _delay_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,26,',0,0
	.dd LM12-_init_12864
	.dw 0x0d,0x0a
.code
LM12:
.debug
	.dw '.stabn 0x44,0,26,',0,0
	.dd LM13-_init_12864
	.dw 0x0d,0x0a
.code
LM13:
L2:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of init_12864

.debug
	.dw '.stabf ',0,0
	.dd LME1-_init_12864
	.dw 0x0d,0x0a
.code
LME1:
.text
LC0:
	.dw 128
	.dw 129
	.dw 130
	.dw 131
	.dw 132
	.dw 133
	.dw 134
	.dw 135
	.dw 144
	.dw 145
	.dw 146
	.dw 147
	.dw 148
	.dw 149
	.dw 150
	.dw 151
	.dw 136
	.dw 137
	.dw 138
	.dw 139
	.dw 140
	.dw 141
	.dw 142
	.dw 143
	.dw 152
	.dw 153
	.dw 154
	.dw 155
	.dw 156
	.dw 157
	.dw 158
	.dw 159
.code
.debug
	.dw '.stabs "write_chinese_12864:F19",36,0,0,',0,0,offset _write_chinese_12864,seg _write_chinese_12864,0x0d,0x0a
.CODE
.public _write_chinese_12864
_write_chinese_12864:	.proc
.debug
	.dw '.stabn 0x44,0,39,',0,0
	.dd LM14-_write_chinese_12864
	.dw 0x0d,0x0a
.code
LM14:
	// total=34, vars=34
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=34
	bp=sp+1

	R1=BP+37
	[bp+32]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,40,',0,0
	.dd LM15-_write_chinese_12864
	.dw 0x0d,0x0a
.code
LM15:
LBB2:
	R2=BP	// QImode move
	R1=BP	// QImode move
	R2=LC0	// QImode move
	R3=32	// QImode move
	[SP--]=R3	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __BlockCopy	// call with return value
	SP = SP + 3	//SP
.debug
	.dw '.stabn 0x44,0,46,',0,0
	.dd LM16-_write_chinese_12864
	.dw 0x0d,0x0a
.code
LM16:
	R1=48	// QImode move
	[SP--]=R1	// QImode move
	call _write_cmd_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,47,',0,0
	.dd LM17-_write_chinese_12864
	.dw 0x0d,0x0a
.code
LM17:
L4:
	R2=[bp+32]	// QImode move
	R2=[bp+32]	// QImode move
	R1=R2+3
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	R3=R2	// QImode move
	R2=R2+(-1)
	R4=R1	// QImode move
	[R4]=R2	// QImode move
	CMP R3,0	// QImode test
	NSJNZ L6	//QImode NE
	pc=L5	// Indirect jump
L6:
.debug
	.dw '.stabn 0x44,0,49,',0,0
	.dd LM18-_write_chinese_12864
	.dw 0x0d,0x0a
.code
LM18:
	R2=[bp+32]	// QImode move
	R2=[bp+32]	// QImode move
	R1=R2+1
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	R4=R2	// QImode move
	R3=BP	// QImode move
	R3 = R3 + R4	//addqi3
	R4=R3	// QImode move
	R4=[R4]	// QImode move
	[bp+33]=R4	// QImode move
	R3=[bp+33]	// QImode move
	[SP--]=R3	// QImode move
	R2=R2+1
	R4=R1	// QImode move
	[R4]=R2	// QImode move
	call _write_cmd_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,50,',0,0
	.dd LM19-_write_chinese_12864
	.dw 0x0d,0x0a
.code
LM19:
	R2=[bp+32]	// QImode move
	R2=[bp+32]	// QImode move
	R1=R2+2
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	R3=R2	// QImode move
	R4=[bp+32]	// QImode move
	R3 = R3 + [R4]	//addqi3
	R4=R3	// QImode move
	R4=[R4]	// QImode move
	[bp+33]=R4	// QImode move
	R3=[bp+33]	// QImode move
	[SP--]=R3	// QImode move
	R2=R2+1
	R4=R1	// QImode move
	[R4]=R2	// QImode move
	call _write_data_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,51,',0,0
	.dd LM20-_write_chinese_12864
	.dw 0x0d,0x0a
.code
LM20:
	R2=[bp+32]	// QImode move
	R2=[bp+32]	// QImode move
	R1=R2+2
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	R3=R2	// QImode move
	R4=[bp+32]	// QImode move
	R3 = R3 + [R4]	//addqi3
	R4=R3	// QImode move
	R4=[R4]	// QImode move
	[bp+33]=R4	// QImode move
	R3=[bp+33]	// QImode move
	[SP--]=R3	// QImode move
	R2=R2+1
	R4=R1	// QImode move
	[R4]=R2	// QImode move
	call _write_data_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,52,',0,0
	.dd LM21-_write_chinese_12864
	.dw 0x0d,0x0a
.code
LM21:
	pc=L4	// Indirect jump
L5:
.debug
	.dw '.stabn 0x44,0,53,',0,0
	.dd LM22-_write_chinese_12864
	.dw 0x0d,0x0a
.code
LM22:
LBE2:
.debug
	.dw '.stabn 0x44,0,53,',0,0
	.dd LM23-_write_chinese_12864
	.dw 0x0d,0x0a
.code
LM23:
L3:

	sp+=34
	pop bp from [sp]
	retf
	.endp	// end of write_chinese_12864

.debug
	.dw '.stabs "str:p20=*11",160,0,0,37',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "first_addr:p11",160,0,0,38',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "first_hanzi:p11",160,0,0,39',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "length:p11",160,0,0,40',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB2-_write_chinese_12864
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "Address:21=ar1;0;31;11",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE2-_write_chinese_12864
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME2-_write_chinese_12864
	.dw 0x0d,0x0a
.code
LME2:
.code
.debug
	.dw '.stabs "delay_12864:F19",36,0,0,',0,0,offset _delay_12864,seg _delay_12864,0x0d,0x0a
.CODE
.public _delay_12864
_delay_12864:	.proc
.debug
	.dw '.stabn 0x44,0,56,',0,0
	.dd LM24-_delay_12864
	.dw 0x0d,0x0a
.code
LM24:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,57,',0,0
	.dd LM25-_delay_12864
	.dw 0x0d,0x0a
.code
LM25:
L9:
	R2=R1	// QImode move
	R3=[R2]	// QImode move
	R2=R3+(-1)
	R3=R2	// QImode move
	R2=R1	// QImode move
	[R2]=R3	// QImode move
	CMP R3,(-1)	// QImode compare
	NSJNZ L11	//QImode NE
	pc=L10	// Indirect jump
L11:
.debug
	.dw '.stabn 0x44,0,59,',0,0
	.dd LM26-_delay_12864
	.dw 0x0d,0x0a
.code
LM26:
	R2=1	// QImode move
	[28690]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,60,',0,0
	.dd LM27-_delay_12864
	.dw 0x0d,0x0a
.code
LM27:
	pc=L9	// Indirect jump
L10:
.debug
	.dw '.stabn 0x44,0,61,',0,0
	.dd LM28-_delay_12864
	.dw 0x0d,0x0a
.code
LM28:
.debug
	.dw '.stabn 0x44,0,61,',0,0
	.dd LM29-_delay_12864
	.dw 0x0d,0x0a
.code
LM29:
L8:

	pop bp from [sp]
	retf
	.endp	// end of delay_12864

.debug
	.dw '.stabs "t:p4",160,0,0,3',0x0d,0x0a
.CODE
.debug
	.dw '.stabf ',0,0
	.dd LME3-_delay_12864
	.dw 0x0d,0x0a
.code
LME3:
.code
.debug
	.dw '.stabs "write_byte_12864:F19",36,0,0,',0,0,offset _write_byte_12864,seg _write_byte_12864,0x0d,0x0a
.CODE
.public _write_byte_12864
_write_byte_12864:	.proc
.debug
	.dw '.stabn 0x44,0,65,',0,0
	.dd LM30-_write_byte_12864
	.dw 0x0d,0x0a
.code
LM30:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
.debug
	.dw '.stabn 0x44,0,66,',0,0
	.dd LM31-_write_byte_12864
	.dw 0x0d,0x0a
.code
LM31:
LBB3:
.debug
	.dw '.stabn 0x44,0,67,',0,0
	.dd LM32-_write_byte_12864
	.dw 0x0d,0x0a
.code
LM32:
	R2=R1	// QImode move
	R3=[R2]	// QImode move
	R3=R3&255
	[R2]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,68,',0,0
	.dd LM33-_write_byte_12864
	.dw 0x0d,0x0a
.code
LM33:
	R2=0	// QImode move
	[BP]=R2	// QImode move
L14:
	R2=[BP]	// QImode move
	CMP R2,7	// QImode compare
	NSJNA L17	//QImode LEU
	pc=L15	// Indirect jump
L17:
.debug
	.dw '.stabn 0x44,0,70,',0,0
	.dd LM34-_write_byte_12864
	.dw 0x0d,0x0a
.code
LM34:
	R4=R1	// QImode move
	R4=[R4]	// QImode move
	R2=R4&128
	CMP R2,0	// QImode test
	NSJZ L18	//QImode EQ
.debug
	.dw '.stabn 0x44,0,72,',0,0
	.dd LM35-_write_byte_12864
	.dw 0x0d,0x0a
.code
LM35:
	R2=[28672]	// QImode move
	R3=R2|16
	[28672]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,73,',0,0
	.dd LM36-_write_byte_12864
	.dw 0x0d,0x0a
.code
LM36:
	pc=L19	// Indirect jump
L18:
.debug
	.dw '.stabn 0x44,0,76,',0,0
	.dd LM37-_write_byte_12864
	.dw 0x0d,0x0a
.code
LM37:
	R2=[28672]	// QImode move
	R3=R2&(-17)
	[28672]=R3	// QImode move
L19:
.debug
	.dw '.stabn 0x44,0,78,',0,0
	.dd LM38-_write_byte_12864
	.dw 0x0d,0x0a
.code
LM38:
// GCC inline ASM start
	NOP
// GCC inline ASM end
.debug
	.dw '.stabn 0x44,0,79,',0,0
	.dd LM39-_write_byte_12864
	.dw 0x0d,0x0a
.code
LM39:
	R2=[28672]	// QImode move
	R3=R2&(-9)
	[28672]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,81,',0,0
	.dd LM40-_write_byte_12864
	.dw 0x0d,0x0a
.code
LM40:
	R2=[28672]	// QImode move
	R3=R2|8
	[28672]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,83,',0,0
	.dd LM41-_write_byte_12864
	.dw 0x0d,0x0a
.code
LM41:
	R2=[28672]	// QImode move
	R3=R2&(-9)
	[28672]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,85,',0,0
	.dd LM42-_write_byte_12864
	.dw 0x0d,0x0a
.code
LM42:
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	R3=R2 lsl 1
	R4=R1	// QImode move
	[R4]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,86,',0,0
	.dd LM43-_write_byte_12864
	.dw 0x0d,0x0a
.code
LM43:
	R2=1	// QImode move
	[28690]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,68,',0,0
	.dd LM44-_write_byte_12864
	.dw 0x0d,0x0a
.code
LM44:
L16:
	R2=[BP]	// QImode move
	R3=R2+1
	[BP]=R3	// QImode move
	pc=L14	// Indirect jump
L15:
.debug
	.dw '.stabn 0x44,0,88,',0,0
	.dd LM45-_write_byte_12864
	.dw 0x0d,0x0a
.code
LM45:
LBE3:
.debug
	.dw '.stabn 0x44,0,88,',0,0
	.dd LM46-_write_byte_12864
	.dw 0x0d,0x0a
.code
LM46:
L13:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of write_byte_12864

.debug
	.dw '.stabs "b:p11",160,0,0,4',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB3-_write_byte_12864
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "i:11",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE3-_write_byte_12864
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME4-_write_byte_12864
	.dw 0x0d,0x0a
.code
LME4:
.code
.debug
	.dw '.stabs "read_byte_12864:F11",36,0,0,',0,0,offset _read_byte_12864,seg _read_byte_12864,0x0d,0x0a
.CODE
.public _read_byte_12864
_read_byte_12864:	.proc
.debug
	.dw '.stabn 0x44,0,92,',0,0
	.dd LM47-_read_byte_12864
	.dw 0x0d,0x0a
.code
LM47:
	// total=3, vars=3
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=3
	bp=sp+1

	R2=BP+6
.debug
	.dw '.stabn 0x44,0,93,',0,0
	.dd LM48-_read_byte_12864
	.dw 0x0d,0x0a
.code
LM48:
LBB4:
	R1=0	// QImode move
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,94,',0,0
	.dd LM49-_read_byte_12864
	.dw 0x0d,0x0a
.code
LM49:
	R1=BP	// QImode move
	R3=BP+1
	R1=0	// QImode move
	R4=R3	// QImode move
	[R4]=R1	// QImode move
L23:
	R1=BP	// QImode move
	R3=BP+1
	R4=R3	// QImode move
	R1=[R4]	// QImode move
	CMP R1,7	// QImode compare
	NSJNA L26	//QImode LEU
	pc=L24	// Indirect jump
L26:
.debug
	.dw '.stabn 0x44,0,96,',0,0
	.dd LM50-_read_byte_12864
	.dw 0x0d,0x0a
.code
LM50:
	R1=[BP]	// QImode move
	R3=R1 lsl 1
	[BP]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,97,',0,0
	.dd LM51-_read_byte_12864
	.dw 0x0d,0x0a
.code
LM51:
	R1=[28672]	// QImode move
	R3=R1&(-9)
	[28672]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,98,',0,0
	.dd LM52-_read_byte_12864
	.dw 0x0d,0x0a
.code
LM52:
// GCC inline ASM start
	NOP
// GCC inline ASM end
.debug
	.dw '.stabn 0x44,0,99,',0,0
	.dd LM53-_read_byte_12864
	.dw 0x0d,0x0a
.code
LM53:
	R1=[28672]	// QImode move
	R3=R1|8
	[28672]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,100,',0,0
	.dd LM54-_read_byte_12864
	.dw 0x0d,0x0a
.code
LM54:
// GCC inline ASM start
	NOP
// GCC inline ASM end
.debug
	.dw '.stabn 0x44,0,101,',0,0
	.dd LM55-_read_byte_12864
	.dw 0x0d,0x0a
.code
LM55:
	R3=[28672]	// QImode move
	R1=R3&16
	CMP R1,0	// QImode test
	NSJZ L27	//QImode EQ
.debug
	.dw '.stabn 0x44,0,103,',0,0
	.dd LM56-_read_byte_12864
	.dw 0x0d,0x0a
.code
LM56:
	R1=[BP]	// QImode move
	R1=R1|1
	[BP]=R1	// QImode move
L27:
.debug
	.dw '.stabn 0x44,0,105,',0,0
	.dd LM57-_read_byte_12864
	.dw 0x0d,0x0a
.code
LM57:
	R1=[28672]	// QImode move
	R3=R1&(-9)
	[28672]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,106,',0,0
	.dd LM58-_read_byte_12864
	.dw 0x0d,0x0a
.code
LM58:
// GCC inline ASM start
	NOP
// GCC inline ASM end
.debug
	.dw '.stabn 0x44,0,107,',0,0
	.dd LM59-_read_byte_12864
	.dw 0x0d,0x0a
.code
LM59:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,94,',0,0
	.dd LM60-_read_byte_12864
	.dw 0x0d,0x0a
.code
LM60:
L25:
	R1=BP	// QImode move
	R3=BP+1
	R4=BP	// QImode move
	R1=BP+1
	R3=BP	// QImode move
	R3=BP+1
	[bp+2]=R3	// QImode move
	R4=[bp+2]	// QImode move
	R3=[R4]	// QImode move
	R4=R3+1
	R3=R1	// QImode move
	[R3]=R4	// QImode move
	pc=L23	// Indirect jump
L24:
.debug
	.dw '.stabn 0x44,0,109,',0,0
	.dd LM61-_read_byte_12864
	.dw 0x0d,0x0a
.code
LM61:
	R3=[BP]	// QImode move
	R1=R3	// QImode move
	pc=L22	// Indirect jump
.debug
	.dw '.stabn 0x44,0,110,',0,0
	.dd LM62-_read_byte_12864
	.dw 0x0d,0x0a
.code
LM62:
LBE4:
.debug
	.dw '.stabn 0x44,0,110,',0,0
	.dd LM63-_read_byte_12864
	.dw 0x0d,0x0a
.code
LM63:
L22:

	sp+=3
	pop bp from [sp]
	retf
	.endp	// end of read_byte_12864

.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB4-_read_byte_12864
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "da:11",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "i:11",128,0,0,1',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE4-_read_byte_12864
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME5-_read_byte_12864
	.dw 0x0d,0x0a
.code
LME5:
.code
.debug
	.dw '.stabs "write_cmd_12864:F19",36,0,0,',0,0,offset _write_cmd_12864,seg _write_cmd_12864,0x0d,0x0a
.CODE
.public _write_cmd_12864
_write_cmd_12864:	.proc
.debug
	.dw '.stabn 0x44,0,113,',0,0
	.dd LM64-_write_cmd_12864
	.dw 0x0d,0x0a
.code
LM64:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,114,',0,0
	.dd LM65-_write_cmd_12864
	.dw 0x0d,0x0a
.code
LM65:
	R2=[BP]	// QImode move
	R3=[R2]	// QImode move
	R3=R3&255
	[R2]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,116,',0,0
	.dd LM66-_write_cmd_12864
	.dw 0x0d,0x0a
.code
LM66:
	R1=[28672]	// QImode move
	R2=R1|32
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,117,',0,0
	.dd LM67-_write_cmd_12864
	.dw 0x0d,0x0a
.code
LM67:
	R1=248	// QImode move
	[SP--]=R1	// QImode move
	call _write_byte_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,118,',0,0
	.dd LM68-_write_cmd_12864
	.dw 0x0d,0x0a
.code
LM68:
	R2=[BP]	// QImode move
	R2=[R2]	// QImode move
	R1=R2&240
	[SP--]=R1	// QImode move
	call _write_byte_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,119,',0,0
	.dd LM69-_write_cmd_12864
	.dw 0x0d,0x0a
.code
LM69:
	R3=[BP]	// QImode move
	R2=[R3]	// QImode move
	R1=R2 lsl 4
	[SP--]=R1	// QImode move
	call _write_byte_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,120,',0,0
	.dd LM70-_write_cmd_12864
	.dw 0x0d,0x0a
.code
LM70:
	R1=[28672]	// QImode move
	R2=R1&(-33)
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,129,',0,0
	.dd LM71-_write_cmd_12864
	.dw 0x0d,0x0a
.code
LM71:
.debug
	.dw '.stabn 0x44,0,129,',0,0
	.dd LM72-_write_cmd_12864
	.dw 0x0d,0x0a
.code
LM72:
L30:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of write_cmd_12864

.debug
	.dw '.stabs "cmd:p11",160,0,0,4',0x0d,0x0a
.CODE
.debug
	.dw '.stabf ',0,0
	.dd LME6-_write_cmd_12864
	.dw 0x0d,0x0a
.code
LME6:
.code
.debug
	.dw '.stabs "write_data_12864:F19",36,0,0,',0,0,offset _write_data_12864,seg _write_data_12864,0x0d,0x0a
.CODE
.public _write_data_12864
_write_data_12864:	.proc
.debug
	.dw '.stabn 0x44,0,131,',0,0
	.dd LM73-_write_data_12864
	.dw 0x0d,0x0a
.code
LM73:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,132,',0,0
	.dd LM74-_write_data_12864
	.dw 0x0d,0x0a
.code
LM74:
	R2=[BP]	// QImode move
	R3=[R2]	// QImode move
	R3=R3&255
	[R2]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,134,',0,0
	.dd LM75-_write_data_12864
	.dw 0x0d,0x0a
.code
LM75:
	R1=[28672]	// QImode move
	R2=R1|32
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,135,',0,0
	.dd LM76-_write_data_12864
	.dw 0x0d,0x0a
.code
LM76:
	R1=250	// QImode move
	[SP--]=R1	// QImode move
	call _write_byte_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,136,',0,0
	.dd LM77-_write_data_12864
	.dw 0x0d,0x0a
.code
LM77:
	R2=[BP]	// QImode move
	R2=[R2]	// QImode move
	R1=R2&240
	[SP--]=R1	// QImode move
	call _write_byte_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,137,',0,0
	.dd LM78-_write_data_12864
	.dw 0x0d,0x0a
.code
LM78:
	R3=[BP]	// QImode move
	R2=[R3]	// QImode move
	R1=R2 lsl 4
	[SP--]=R1	// QImode move
	call _write_byte_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,138,',0,0
	.dd LM79-_write_data_12864
	.dw 0x0d,0x0a
.code
LM79:
	R1=[28672]	// QImode move
	R2=R1&(-33)
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,149,',0,0
	.dd LM80-_write_data_12864
	.dw 0x0d,0x0a
.code
LM80:
.debug
	.dw '.stabn 0x44,0,149,',0,0
	.dd LM81-_write_data_12864
	.dw 0x0d,0x0a
.code
LM81:
L31:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of write_data_12864

.debug
	.dw '.stabs "d:p11",160,0,0,4',0x0d,0x0a
.CODE
.debug
	.dw '.stabf ',0,0
	.dd LME7-_write_data_12864
	.dw 0x0d,0x0a
.code
LME7:
.code
.debug
	.dw '.stabs "wait_busy:F19",36,0,0,',0,0,offset _wait_busy,seg _wait_busy,0x0d,0x0a
.CODE
.public _wait_busy
_wait_busy:	.proc
.debug
	.dw '.stabn 0x44,0,151,',0,0
	.dd LM82-_wait_busy
	.dw 0x0d,0x0a
.code
LM82:
	// total=2, vars=2
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=2
	bp=sp+1

	R1=BP+5
	[bp+1]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,152,',0,0
	.dd LM83-_wait_busy
	.dw 0x0d,0x0a
.code
LM83:
LBB5:
.debug
	.dw '.stabn 0x44,0,153,',0,0
	.dd LM84-_wait_busy
	.dw 0x0d,0x0a
.code
LM84:
	call _read_stat_12864	// call with return value
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,154,',0,0
	.dd LM85-_wait_busy
	.dw 0x0d,0x0a
.code
LM85:
L33:
	R2=[BP]	// QImode move
	R1=R2&128
	CMP R1,0	// QImode test
	NSJNZ L35	//QImode NE
	pc=L34	// Indirect jump
L35:
.debug
	.dw '.stabn 0x44,0,156,',0,0
	.dd LM86-_wait_busy
	.dw 0x0d,0x0a
.code
LM86:
	call _read_stat_12864	// call with return value
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,157,',0,0
	.dd LM87-_wait_busy
	.dw 0x0d,0x0a
.code
LM87:
	R1=10	// QImode move
	[SP--]=R1	// QImode move
	call _delay_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,158,',0,0
	.dd LM88-_wait_busy
	.dw 0x0d,0x0a
.code
LM88:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,159,',0,0
	.dd LM89-_wait_busy
	.dw 0x0d,0x0a
.code
LM89:
	pc=L33	// Indirect jump
L34:
.debug
	.dw '.stabn 0x44,0,160,',0,0
	.dd LM90-_wait_busy
	.dw 0x0d,0x0a
.code
LM90:
LBE5:
.debug
	.dw '.stabn 0x44,0,160,',0,0
	.dd LM91-_wait_busy
	.dw 0x0d,0x0a
.code
LM91:
L32:

	sp+=2
	pop bp from [sp]
	retf
	.endp	// end of wait_busy

.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB5-_wait_busy
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "i:11",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE5-_wait_busy
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME8-_wait_busy
	.dw 0x0d,0x0a
.code
LME8:
.code
.debug
	.dw '.stabs "read_stat_12864:F11",36,0,0,',0,0,offset _read_stat_12864,seg _read_stat_12864,0x0d,0x0a
.CODE
.public _read_stat_12864
_read_stat_12864:	.proc
.debug
	.dw '.stabn 0x44,0,162,',0,0
	.dd LM92-_read_stat_12864
	.dw 0x0d,0x0a
.code
LM92:
	// total=3, vars=3
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=3
	bp=sp+1

	R1=BP+6
	[bp+2]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,164,',0,0
	.dd LM93-_read_stat_12864
	.dw 0x0d,0x0a
.code
LM93:
LBB6:
.debug
	.dw '.stabn 0x44,0,165,',0,0
	.dd LM94-_read_stat_12864
	.dw 0x0d,0x0a
.code
LM94:
	R1=100	// QImode move
	[SP--]=R1	// QImode move
	call _delay_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,166,',0,0
	.dd LM95-_read_stat_12864
	.dw 0x0d,0x0a
.code
LM95:
	R1=[28672]	// QImode move
	R2=R1|32
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,167,',0,0
	.dd LM96-_read_stat_12864
	.dw 0x0d,0x0a
.code
LM96:
	R1=252	// QImode move
	[SP--]=R1	// QImode move
	call _write_byte_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,168,',0,0
	.dd LM97-_read_stat_12864
	.dw 0x0d,0x0a
.code
LM97:
	R1=[28674]	// QImode move
	R2=R1&(-57)
	[28674]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,169,',0,0
	.dd LM98-_read_stat_12864
	.dw 0x0d,0x0a
.code
LM98:
	call _read_byte_12864	// call with return value
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,170,',0,0
	.dd LM99-_read_stat_12864
	.dw 0x0d,0x0a
.code
LM99:
	call _read_byte_12864	// call with return value
	R2=BP	// QImode move
	R3=BP+1
	R2=R3	// QImode move
	[R2]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,171,',0,0
	.dd LM100-_read_stat_12864
	.dw 0x0d,0x0a
.code
LM100:
	R2=BP	// QImode move
	R1=BP+1
	R2=BP	// QImode move
	R3=BP+1
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R3=R2 lsr 4
	R2=R1	// QImode move
	[R2]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,172,',0,0
	.dd LM101-_read_stat_12864
	.dw 0x0d,0x0a
.code
LM101:
	R1=BP	// QImode move
	R2=BP+1
	R4=[BP]	// QImode move
	R3=R2	// QImode move
	R3=[R3]	// QImode move
	R4|=R3
	[BP]=R4	// QImode move
.debug
	.dw '.stabn 0x44,0,173,',0,0
	.dd LM102-_read_stat_12864
	.dw 0x0d,0x0a
.code
LM102:
	R1=[28672]	// QImode move
	R2=R1&(-33)
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,174,',0,0
	.dd LM103-_read_stat_12864
	.dw 0x0d,0x0a
.code
LM103:
	R1=[28674]	// QImode move
	R2=R1|56
	[28674]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,175,',0,0
	.dd LM104-_read_stat_12864
	.dw 0x0d,0x0a
.code
LM104:
	R2=[BP]	// QImode move
	R1=R2	// QImode move
	pc=L37	// Indirect jump
.debug
	.dw '.stabn 0x44,0,193,',0,0
	.dd LM105-_read_stat_12864
	.dw 0x0d,0x0a
.code
LM105:
LBE6:
.debug
	.dw '.stabn 0x44,0,193,',0,0
	.dd LM106-_read_stat_12864
	.dw 0x0d,0x0a
.code
LM106:
L37:

	sp+=3
	pop bp from [sp]
	retf
	.endp	// end of read_stat_12864

.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB6-_read_stat_12864
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "da:11",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "i:11",128,0,0,1',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE6-_read_stat_12864
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME9-_read_stat_12864
	.dw 0x0d,0x0a
.code
LME9:
.code
.debug
	.dw '.stabs "read_data_12864:F11",36,0,0,',0,0,offset _read_data_12864,seg _read_data_12864,0x0d,0x0a
.CODE
.public _read_data_12864
_read_data_12864:	.proc
.debug
	.dw '.stabn 0x44,0,195,',0,0
	.dd LM107-_read_data_12864
	.dw 0x0d,0x0a
.code
LM107:
	// total=3, vars=3
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=3
	bp=sp+1

	R1=BP+6
	[bp+2]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,197,',0,0
	.dd LM108-_read_data_12864
	.dw 0x0d,0x0a
.code
LM108:
LBB7:
.debug
	.dw '.stabn 0x44,0,198,',0,0
	.dd LM109-_read_data_12864
	.dw 0x0d,0x0a
.code
LM109:
	R1=100	// QImode move
	[SP--]=R1	// QImode move
	call _delay_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,199,',0,0
	.dd LM110-_read_data_12864
	.dw 0x0d,0x0a
.code
LM110:
	R1=[28672]	// QImode move
	R2=R1|32
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,200,',0,0
	.dd LM111-_read_data_12864
	.dw 0x0d,0x0a
.code
LM111:
	R1=254	// QImode move
	[SP--]=R1	// QImode move
	call _write_byte_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,201,',0,0
	.dd LM112-_read_data_12864
	.dw 0x0d,0x0a
.code
LM112:
	R1=[28674]	// QImode move
	R2=R1&(-57)
	[28674]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,202,',0,0
	.dd LM113-_read_data_12864
	.dw 0x0d,0x0a
.code
LM113:
	call _read_byte_12864	// call with return value
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,203,',0,0
	.dd LM114-_read_data_12864
	.dw 0x0d,0x0a
.code
LM114:
	call _read_byte_12864	// call with return value
	R2=BP	// QImode move
	R3=BP+1
	R2=R3	// QImode move
	[R2]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,204,',0,0
	.dd LM115-_read_data_12864
	.dw 0x0d,0x0a
.code
LM115:
	R2=BP	// QImode move
	R1=BP+1
	R2=BP	// QImode move
	R3=BP+1
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R3=R2 lsr 4
	R2=R1	// QImode move
	[R2]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,205,',0,0
	.dd LM116-_read_data_12864
	.dw 0x0d,0x0a
.code
LM116:
	R1=BP	// QImode move
	R2=BP+1
	R4=[BP]	// QImode move
	R3=R2	// QImode move
	R3=[R3]	// QImode move
	R4|=R3
	[BP]=R4	// QImode move
.debug
	.dw '.stabn 0x44,0,206,',0,0
	.dd LM117-_read_data_12864
	.dw 0x0d,0x0a
.code
LM117:
	R1=[28672]	// QImode move
	R2=R1&(-33)
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,207,',0,0
	.dd LM118-_read_data_12864
	.dw 0x0d,0x0a
.code
LM118:
	R1=[28674]	// QImode move
	R2=R1|56
	[28674]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,208,',0,0
	.dd LM119-_read_data_12864
	.dw 0x0d,0x0a
.code
LM119:
	R2=[BP]	// QImode move
	R1=R2	// QImode move
	pc=L38	// Indirect jump
.debug
	.dw '.stabn 0x44,0,226,',0,0
	.dd LM120-_read_data_12864
	.dw 0x0d,0x0a
.code
LM120:
LBE7:
.debug
	.dw '.stabn 0x44,0,226,',0,0
	.dd LM121-_read_data_12864
	.dw 0x0d,0x0a
.code
LM121:
L38:

	sp+=3
	pop bp from [sp]
	retf
	.endp	// end of read_data_12864

.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB7-_read_data_12864
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "da:11",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "i:11",128,0,0,1',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE7-_read_data_12864
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME10-_read_data_12864
	.dw 0x0d,0x0a
.code
LME10:
.code
.debug
	.dw '.stabs "byte_reverse:F11",36,0,0,',0,0,offset _byte_reverse,seg _byte_reverse,0x0d,0x0a
.CODE
.public _byte_reverse
_byte_reverse:	.proc
.debug
	.dw '.stabn 0x44,0,228,',0,0
	.dd LM122-_byte_reverse
	.dw 0x0d,0x0a
.code
LM122:
	// total=3, vars=3
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=3
	bp=sp+1

	R2=BP+6
.debug
	.dw '.stabn 0x44,0,229,',0,0
	.dd LM123-_byte_reverse
	.dw 0x0d,0x0a
.code
LM123:
LBB8:
	R1=BP	// QImode move
	R3=BP+1
	R1=0	// QImode move
	R4=R3	// QImode move
	[R4]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,230,',0,0
	.dd LM124-_byte_reverse
	.dw 0x0d,0x0a
.code
LM124:
	R1=0	// QImode move
	[BP]=R1	// QImode move
L40:
	R1=[BP]	// QImode move
	CMP R1,7	// QImode compare
	NSJNA L43	//QImode LEU
	pc=L41	// Indirect jump
L43:
.debug
	.dw '.stabn 0x44,0,232,',0,0
	.dd LM125-_byte_reverse
	.dw 0x0d,0x0a
.code
LM125:
	R3=BP	// QImode move
	R1=BP+1
	R3=BP	// QImode move
	R3=BP+1
	[bp+2]=R3	// QImode move
	R4=[bp+2]	// QImode move
	R3=[R4]	// QImode move
	R4=R3 lsl 1
	R3=R1	// QImode move
	[R3]=R4	// QImode move
.debug
	.dw '.stabn 0x44,0,233,',0,0
	.dd LM126-_byte_reverse
	.dw 0x0d,0x0a
.code
LM126:
	R4=R2	// QImode move
	R4=[R4]	// QImode move
	R1=R4&1
	CMP R1,0	// QImode test
	NSJZ L44	//QImode EQ
.debug
	.dw '.stabn 0x44,0,235,',0,0
	.dd LM127-_byte_reverse
	.dw 0x0d,0x0a
.code
LM127:
	R3=BP	// QImode move
	R1=BP+1
	R3=BP	// QImode move
	R3=BP+1
	[bp+2]=R3	// QImode move
	R4=[bp+2]	// QImode move
	R4=[R4]	// QImode move
	R3=R4|1
	R4=R1	// QImode move
	[R4]=R3	// QImode move
L44:
.debug
	.dw '.stabn 0x44,0,237,',0,0
	.dd LM128-_byte_reverse
	.dw 0x0d,0x0a
.code
LM128:
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	R3=R1 lsr 1
	R4=R2	// QImode move
	[R4]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,238,',0,0
	.dd LM129-_byte_reverse
	.dw 0x0d,0x0a
.code
LM129:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,230,',0,0
	.dd LM130-_byte_reverse
	.dw 0x0d,0x0a
.code
LM130:
L42:
	R1=[BP]	// QImode move
	R3=R1+1
	[BP]=R3	// QImode move
	pc=L40	// Indirect jump
L41:
.debug
	.dw '.stabn 0x44,0,240,',0,0
	.dd LM131-_byte_reverse
	.dw 0x0d,0x0a
.code
LM131:
	R1=BP	// QImode move
	R3=BP+1
	R1=R3	// QImode move
	R4=[R1]	// QImode move
	R1=R4	// QImode move
	pc=L39	// Indirect jump
.debug
	.dw '.stabn 0x44,0,241,',0,0
	.dd LM132-_byte_reverse
	.dw 0x0d,0x0a
.code
LM132:
LBE8:
.debug
	.dw '.stabn 0x44,0,241,',0,0
	.dd LM133-_byte_reverse
	.dw 0x0d,0x0a
.code
LM133:
L39:

	sp+=3
	pop bp from [sp]
	retf
	.endp	// end of byte_reverse

.debug
	.dw '.stabs "d:p11",160,0,0,6',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB8-_byte_reverse
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "i:11",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "t:11",128,0,0,1',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE8-_byte_reverse
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME11-_byte_reverse
	.dw 0x0d,0x0a
.code
LME11:
.code
.debug
	.dw '.stabs "graph_clear:F19",36,0,0,',0,0,offset _graph_clear,seg _graph_clear,0x0d,0x0a
.CODE
.public _graph_clear
_graph_clear:	.proc
.debug
	.dw '.stabn 0x44,0,243,',0,0
	.dd LM134-_graph_clear
	.dw 0x0d,0x0a
.code
LM134:
	// total=3, vars=3
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=3
	bp=sp+1

	R1=BP+6
	[bp+2]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,244,',0,0
	.dd LM135-_graph_clear
	.dw 0x0d,0x0a
.code
LM135:
LBB9:
.debug
	.dw '.stabn 0x44,0,245,',0,0
	.dd LM136-_graph_clear
	.dw 0x0d,0x0a
.code
LM136:
	call _init_12864	// call without return value
.debug
	.dw '.stabn 0x44,0,246,',0,0
	.dd LM137-_graph_clear
	.dw 0x0d,0x0a
.code
LM137:
	R1=BP	// QImode move
	R2=BP+1
	R1=0	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
L48:
	R1=BP	// QImode move
	R2=BP+1
	R4=R2	// QImode move
	R1=[R4]	// QImode move
	CMP R1,31	// QImode compare
	NSJNA L51	//QImode LEU
	pc=L49	// Indirect jump
L51:
.debug
	.dw '.stabn 0x44,0,248,',0,0
	.dd LM138-_graph_clear
	.dw 0x0d,0x0a
.code
LM138:
	R1=52	// QImode move
	[SP--]=R1	// QImode move
	call _write_cmd_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,249,',0,0
	.dd LM139-_graph_clear
	.dw 0x0d,0x0a
.code
LM139:
	R1=10	// QImode move
	[SP--]=R1	// QImode move
	call _delay_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,250,',0,0
	.dd LM140-_graph_clear
	.dw 0x0d,0x0a
.code
LM140:
	R1=2	// QImode move
	[SP--]=R1	// QImode move
	call _write_cmd_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,251,',0,0
	.dd LM141-_graph_clear
	.dw 0x0d,0x0a
.code
LM141:
	R1=10	// QImode move
	[SP--]=R1	// QImode move
	call _delay_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,252,',0,0
	.dd LM142-_graph_clear
	.dw 0x0d,0x0a
.code
LM142:
	R1=BP	// QImode move
	R2=BP+1
	R1=R2	// QImode move
	R3=[R1]	// QImode move
	R1=R3+128
	[SP--]=R1	// QImode move
	call _write_cmd_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,253,',0,0
	.dd LM143-_graph_clear
	.dw 0x0d,0x0a
.code
LM143:
	R1=10	// QImode move
	[SP--]=R1	// QImode move
	call _delay_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,254,',0,0
	.dd LM144-_graph_clear
	.dw 0x0d,0x0a
.code
LM144:
	R1=128	// QImode move
	[SP--]=R1	// QImode move
	call _write_cmd_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,255,',0,0
	.dd LM145-_graph_clear
	.dw 0x0d,0x0a
.code
LM145:
	R1=10	// QImode move
	[SP--]=R1	// QImode move
	call _delay_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,256,',0,0
	.dd LM146-_graph_clear
	.dw 0x0d,0x0a
.code
LM146:
	R1=0	// QImode move
	[BP]=R1	// QImode move
L52:
	R1=[BP]	// QImode move
	CMP R1,31	// QImode compare
	NSJNA L55	//QImode LEU
	pc=L53	// Indirect jump
L55:
.debug
	.dw '.stabn 0x44,0,258,',0,0
	.dd LM147-_graph_clear
	.dw 0x0d,0x0a
.code
LM147:
	R1=0	// QImode move
	[SP--]=R1	// QImode move
	call _write_data_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,256,',0,0
	.dd LM148-_graph_clear
	.dw 0x0d,0x0a
.code
LM148:
L54:
	R1=[BP]	// QImode move
	R2=R1+1
	[BP]=R2	// QImode move
	pc=L52	// Indirect jump
L53:
.debug
	.dw '.stabn 0x44,0,260,',0,0
	.dd LM149-_graph_clear
	.dw 0x0d,0x0a
.code
LM149:
	R1=10	// QImode move
	[SP--]=R1	// QImode move
	call _delay_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,261,',0,0
	.dd LM150-_graph_clear
	.dw 0x0d,0x0a
.code
LM150:
	R1=54	// QImode move
	[SP--]=R1	// QImode move
	call _write_cmd_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,262,',0,0
	.dd LM151-_graph_clear
	.dw 0x0d,0x0a
.code
LM151:
	R1=10	// QImode move
	[SP--]=R1	// QImode move
	call _delay_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,246,',0,0
	.dd LM152-_graph_clear
	.dw 0x0d,0x0a
.code
LM152:
L50:
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
	pc=L48	// Indirect jump
L49:
.debug
	.dw '.stabn 0x44,0,265,',0,0
	.dd LM153-_graph_clear
	.dw 0x0d,0x0a
.code
LM153:
LBE9:
.debug
	.dw '.stabn 0x44,0,265,',0,0
	.dd LM154-_graph_clear
	.dw 0x0d,0x0a
.code
LM154:
L47:

	sp+=3
	pop bp from [sp]
	retf
	.endp	// end of graph_clear

.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB9-_graph_clear
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "i:11",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "j:11",128,0,0,1',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE9-_graph_clear
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME12-_graph_clear
	.dw 0x0d,0x0a
.code
LME12:
.code
.debug
	.dw '.stabs "graph:F19",36,0,0,',0,0,offset _graph,seg _graph,0x0d,0x0a
.CODE
.public _graph
_graph:	.proc
.debug
	.dw '.stabn 0x44,0,268,',0,0
	.dd LM155-_graph
	.dw 0x0d,0x0a
.code
LM155:
	// total=4, vars=4
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=4
	bp=sp+1

	R1=BP+7
	[bp+2]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,269,',0,0
	.dd LM156-_graph
	.dw 0x0d,0x0a
.code
LM156:
LBB10:
.debug
	.dw '.stabn 0x44,0,270,',0,0
	.dd LM157-_graph
	.dw 0x0d,0x0a
.code
LM157:
	R1=BP	// QImode move
	R2=BP+1
	R1=0	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
L59:
	R1=BP	// QImode move
	R2=BP+1
	R4=R2	// QImode move
	R1=[R4]	// QImode move
	CMP R1,31	// QImode compare
	NSJNA L62	//QImode LEU
	pc=L60	// Indirect jump
L62:
.debug
	.dw '.stabn 0x44,0,272,',0,0
	.dd LM158-_graph
	.dw 0x0d,0x0a
.code
LM158:
	R1=52	// QImode move
	[SP--]=R1	// QImode move
	call _write_cmd_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,273,',0,0
	.dd LM159-_graph
	.dw 0x0d,0x0a
.code
LM159:
	R1=10	// QImode move
	[SP--]=R1	// QImode move
	call _delay_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,274,',0,0
	.dd LM160-_graph
	.dw 0x0d,0x0a
.code
LM160:
	R1=2	// QImode move
	[SP--]=R1	// QImode move
	call _write_cmd_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,275,',0,0
	.dd LM161-_graph
	.dw 0x0d,0x0a
.code
LM161:
	R1=10	// QImode move
	[SP--]=R1	// QImode move
	call _delay_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,276,',0,0
	.dd LM162-_graph
	.dw 0x0d,0x0a
.code
LM162:
	R1=BP	// QImode move
	R2=BP+1
	R1=R2	// QImode move
	R3=[R1]	// QImode move
	R1=R3+128
	[SP--]=R1	// QImode move
	call _write_cmd_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,277,',0,0
	.dd LM163-_graph
	.dw 0x0d,0x0a
.code
LM163:
	R1=10	// QImode move
	[SP--]=R1	// QImode move
	call _delay_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,278,',0,0
	.dd LM164-_graph
	.dw 0x0d,0x0a
.code
LM164:
	R1=128	// QImode move
	[SP--]=R1	// QImode move
	call _write_cmd_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,279,',0,0
	.dd LM165-_graph
	.dw 0x0d,0x0a
.code
LM165:
	R1=10	// QImode move
	[SP--]=R1	// QImode move
	call _delay_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,280,',0,0
	.dd LM166-_graph
	.dw 0x0d,0x0a
.code
LM166:
	R1=0	// QImode move
	[BP]=R1	// QImode move
L63:
	R1=[BP]	// QImode move
	CMP R1,7	// QImode compare
	NSJNA L66	//QImode LEU
	pc=L64	// Indirect jump
L66:
.debug
	.dw '.stabn 0x44,0,282,',0,0
	.dd LM167-_graph
	.dw 0x0d,0x0a
.code
LM167:
	R1=BP	// QImode move
	R2=BP+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	R2=[BP]	// QImode move
	R3=R2	// QImode move
	R2=R3 lsl 1
	R4=16	// QImode move
	[bp+3]=R4	// QImode move
	R4=[bp+3]	// QImode move
	mr=R1*R4	// r3=R1*R4 16bit=16bit*16bit
	R1=R2	// QImode move
	R1 = R1 + R3	//addqi3
	R2=R1	// QImode move
	R1=[bp+2]	// QImode move
	R2 = R2 + [R1]	//addqi3
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	call _write_data_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,283,',0,0
	.dd LM168-_graph
	.dw 0x0d,0x0a
.code
LM168:
	R1=100	// QImode move
	[SP--]=R1	// QImode move
	call _delay_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,284,',0,0
	.dd LM169-_graph
	.dw 0x0d,0x0a
.code
LM169:
	R1=BP	// QImode move
	R2=BP+1
	R4=R2	// QImode move
	R1=[R4]	// QImode move
	R2=[BP]	// QImode move
	R3=R2	// QImode move
	R2=R3 lsl 1
	R3=16	// QImode move
	[bp+3]=R3	// QImode move
	R4=[bp+3]	// QImode move
	mr=R1*R4	// r3=R1*R4 16bit=16bit*16bit
	R1=R2	// QImode move
	R1 = R1 + R3	//addqi3
	R2=R1	// QImode move
	R1=[bp+2]	// QImode move
	R2 = R2 + [R1]	//addqi3
	R1=R2+1
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	[SP--]=R2	// QImode move
	call _write_data_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,285,',0,0
	.dd LM170-_graph
	.dw 0x0d,0x0a
.code
LM170:
	R1=100	// QImode move
	[SP--]=R1	// QImode move
	call _delay_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,280,',0,0
	.dd LM171-_graph
	.dw 0x0d,0x0a
.code
LM171:
L65:
	R1=[BP]	// QImode move
	R2=R1+1
	[BP]=R2	// QImode move
	pc=L63	// Indirect jump
L64:
.debug
	.dw '.stabn 0x44,0,287,',0,0
	.dd LM172-_graph
	.dw 0x0d,0x0a
.code
LM172:
	R1=0	// QImode move
	[BP]=R1	// QImode move
L67:
	R1=[BP]	// QImode move
	CMP R1,7	// QImode compare
	NSJNA L70	//QImode LEU
	pc=L68	// Indirect jump
L70:
.debug
	.dw '.stabn 0x44,0,289,',0,0
	.dd LM173-_graph
	.dw 0x0d,0x0a
.code
LM173:
	R1=BP	// QImode move
	R2=BP+1
	R4=R2	// QImode move
	R1=[R4]	// QImode move
	R2=[BP]	// QImode move
	R3=16	// QImode move
	[bp+3]=R3	// QImode move
	R4=[bp+3]	// QImode move
	mr=R1*R4	// r3=R1*R4 16bit=16bit*16bit
	R1=R2	// QImode move
	R2=R1 lsl 1
	R1=R3	// QImode move
	R1 = R1 + R2	//addqi3
	R2=R1	// QImode move
	R1=[bp+2]	// QImode move
	R2 = R2 + [R1]	//addqi3
	R1=R2+512
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	[SP--]=R2	// QImode move
	call _write_data_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,290,',0,0
	.dd LM174-_graph
	.dw 0x0d,0x0a
.code
LM174:
	R1=100	// QImode move
	[SP--]=R1	// QImode move
	call _delay_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,291,',0,0
	.dd LM175-_graph
	.dw 0x0d,0x0a
.code
LM175:
	R1=BP	// QImode move
	R2=BP+1
	R4=R2	// QImode move
	R1=[R4]	// QImode move
	R2=[BP]	// QImode move
	R3=16	// QImode move
	[bp+3]=R3	// QImode move
	R4=[bp+3]	// QImode move
	mr=R1*R4	// r3=R1*R4 16bit=16bit*16bit
	R1=R2	// QImode move
	R2=R1 lsl 1
	R1=R3	// QImode move
	R1 = R1 + R2	//addqi3
	R2=R1	// QImode move
	R1=[bp+2]	// QImode move
	R2 = R2 + [R1]	//addqi3
	R1=R2+513
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	[SP--]=R2	// QImode move
	call _write_data_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,292,',0,0
	.dd LM176-_graph
	.dw 0x0d,0x0a
.code
LM176:
	R1=100	// QImode move
	[SP--]=R1	// QImode move
	call _delay_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,287,',0,0
	.dd LM177-_graph
	.dw 0x0d,0x0a
.code
LM177:
L69:
	R1=[BP]	// QImode move
	R2=R1+1
	[BP]=R2	// QImode move
	pc=L67	// Indirect jump
L68:
.debug
	.dw '.stabn 0x44,0,294,',0,0
	.dd LM178-_graph
	.dw 0x0d,0x0a
.code
LM178:
	R1=54	// QImode move
	[SP--]=R1	// QImode move
	call _write_cmd_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,295,',0,0
	.dd LM179-_graph
	.dw 0x0d,0x0a
.code
LM179:
	R1=10	// QImode move
	[SP--]=R1	// QImode move
	call _delay_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,270,',0,0
	.dd LM180-_graph
	.dw 0x0d,0x0a
.code
LM180:
L61:
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
	pc=L59	// Indirect jump
L60:
.debug
	.dw '.stabn 0x44,0,297,',0,0
	.dd LM181-_graph
	.dw 0x0d,0x0a
.code
LM181:
LBE10:
.debug
	.dw '.stabn 0x44,0,297,',0,0
	.dd LM182-_graph
	.dw 0x0d,0x0a
.code
LM182:
L58:

	sp+=4
	pop bp from [sp]
	retf
	.endp	// end of graph

.debug
	.dw '.stabs "table:p22=*2",160,0,0,7',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB10-_graph
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "i:11",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "j:11",128,0,0,1',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE10-_graph
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME13-_graph
	.dw 0x0d,0x0a
.code
LME13:
.code
.debug
	.dw '.stabs "graph_off:F19",36,0,0,',0,0,offset _graph_off,seg _graph_off,0x0d,0x0a
.CODE
.public _graph_off
_graph_off:	.proc
.debug
	.dw '.stabn 0x44,0,299,',0,0
	.dd LM183-_graph_off
	.dw 0x0d,0x0a
.code
LM183:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,300,',0,0
	.dd LM184-_graph_off
	.dw 0x0d,0x0a
.code
LM184:
	R1=48	// QImode move
	[SP--]=R1	// QImode move
	call _write_cmd_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,301,',0,0
	.dd LM185-_graph_off
	.dw 0x0d,0x0a
.code
LM185:
.debug
	.dw '.stabn 0x44,0,301,',0,0
	.dd LM186-_graph_off
	.dw 0x0d,0x0a
.code
LM186:
L74:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of graph_off

.debug
	.dw '.stabf ',0,0
	.dd LME14-_graph_off
	.dw 0x0d,0x0a
.code
LME14:
.code
.debug
	.dw '.stabs "clear:F19",36,0,0,',0,0,offset _clear,seg _clear,0x0d,0x0a
.CODE
.public _clear
_clear:	.proc
.debug
	.dw '.stabn 0x44,0,303,',0,0
	.dd LM187-_clear
	.dw 0x0d,0x0a
.code
LM187:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,304,',0,0
	.dd LM188-_clear
	.dw 0x0d,0x0a
.code
LM188:
	R1=48	// QImode move
	[SP--]=R1	// QImode move
	call _write_cmd_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,305,',0,0
	.dd LM189-_clear
	.dw 0x0d,0x0a
.code
LM189:
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	call _write_cmd_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,306,',0,0
	.dd LM190-_clear
	.dw 0x0d,0x0a
.code
LM190:
.debug
	.dw '.stabn 0x44,0,306,',0,0
	.dd LM191-_clear
	.dw 0x0d,0x0a
.code
LM191:
L75:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of clear

.debug
	.dw '.stabf ',0,0
	.dd LME15-_clear
	.dw 0x0d,0x0a
.code
LME15:
.text
LC1:
	.dw 32
	.dw 32
	.dw 32
	.dw 32
	.dw 32
	.dw 32
	.dw 32
	.dw 32
.code
.debug
	.dw '.stabs "write_int_12864:F19",36,0,0,',0,0,offset _write_int_12864,seg _write_int_12864,0x0d,0x0a
.CODE
.public _write_int_12864
_write_int_12864:	.proc
.debug
	.dw '.stabn 0x44,0,308,',0,0
	.dd LM192-_write_int_12864
	.dw 0x0d,0x0a
.code
LM192:
	// total=12, vars=12
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=12
	bp=sp+1

	R1=BP+15
	[bp+10]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,309,',0,0
	.dd LM193-_write_int_12864
	.dw 0x0d,0x0a
.code
LM193:
LBB11:
	R1=0	// QImode move
	[BP]=R1	// QImode move
	R1=BP	// QImode move
	R2=BP+1
	R1=0	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,310,',0,0
	.dd LM194-_write_int_12864
	.dw 0x0d,0x0a
.code
LM194:
	R1=BP	// QImode move
	R2=BP+2
	R1=R2	// QImode move
	R2=LC1	// QImode move
	R3=8	// QImode move
	[SP--]=R3	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __BlockCopy	// call with return value
	SP = SP + 3	//SP
.debug
	.dw '.stabn 0x44,0,311,',0,0
	.dd LM195-_write_int_12864
	.dw 0x0d,0x0a
.code
LM195:
	R2=[bp+10]	// QImode move
	R1=[R2]	// QImode move
	CMP R1,0	// QImode test
	NSJNL L77	//QImode GE
.debug
	.dw '.stabn 0x44,0,313,',0,0
	.dd LM196-_write_int_12864
	.dw 0x0d,0x0a
.code
LM196:
	R1=BP	// QImode move
	R2=BP+1
	R1=1	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,314,',0,0
	.dd LM197-_write_int_12864
	.dw 0x0d,0x0a
.code
LM197:
	R2=[bp+10]	// QImode move
	R1=-[R2]	// QImode negative
	R3=[bp+10]	// QImode move
	[R3]=R1	// QImode move
L77:
.debug
	.dw '.stabn 0x44,0,317,',0,0
	.dd LM198-_write_int_12864
	.dw 0x0d,0x0a
.code
LM198:
L78:
	R2=[bp+10]	// QImode move
	R1=[R2]	// QImode move
	R2=10	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __divi1	// call with return value
	SP = SP + 2	//SP
	CMP R1,0	// QImode test
	NSJNZ L80	//QImode NE
	pc=L79	// Indirect jump
L80:
.debug
	.dw '.stabn 0x44,0,319,',0,0
	.dd LM199-_write_int_12864
	.dw 0x0d,0x0a
.code
LM199:
	R2=BP	// QImode move
	R1=BP+2
	R3=7	// QImode move
	R2=R3	// QImode move
	R2-=[BP]	// subqi3_r0R R2=R2-[BP]
	[bp+11]=R1	// QImode move
	R3=[bp+11]	// QImode move
	R3 = R3 + R2	//addqi3
	[bp+11]=R3	// QImode move
	R2=[bp+10]	// QImode move
	R1=[R2]	// QImode move
	R2=10	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __modi1	// call with return value
	SP = SP + 2	//SP
	R2=R1+48
	R3=[bp+11]	// QImode move
	[R3]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,320,',0,0
	.dd LM200-_write_int_12864
	.dw 0x0d,0x0a
.code
LM200:
	R2=[bp+10]	// QImode move
	R1=[R2]	// QImode move
	R2=10	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __divi1	// call with return value
	SP = SP + 2	//SP
	R3=[bp+10]	// QImode move
	[R3]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,321,',0,0
	.dd LM201-_write_int_12864
	.dw 0x0d,0x0a
.code
LM201:
	R1=[BP]	// QImode move
	R2=R1+1
	[BP]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,322,',0,0
	.dd LM202-_write_int_12864
	.dw 0x0d,0x0a
.code
LM202:
	pc=L78	// Indirect jump
L79:
.debug
	.dw '.stabn 0x44,0,323,',0,0
	.dd LM203-_write_int_12864
	.dw 0x0d,0x0a
.code
LM203:
	R2=BP	// QImode move
	R1=BP+2
	R3=7	// QImode move
	R2=R3	// QImode move
	R2-=[BP]	// subqi3_r0R R2=R2-[BP]
	R1 = R1 + R2	//addqi3
	R3=[bp+10]	// QImode move
	R2=[R3]	// QImode move
	R3=R2+48
	R2=R1	// QImode move
	[R2]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,324,',0,0
	.dd LM204-_write_int_12864
	.dw 0x0d,0x0a
.code
LM204:
	R1=BP	// QImode move
	R2=BP+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	CMP R1,0	// QImode test
	NSJZ L81	//QImode EQ
.debug
	.dw '.stabn 0x44,0,326,',0,0
	.dd LM205-_write_int_12864
	.dw 0x0d,0x0a
.code
LM205:
	R2=BP	// QImode move
	R1=BP+2
	R3=6	// QImode move
	R2=R3	// QImode move
	R2-=[BP]	// subqi3_r0R R2=R2-[BP]
	R1 = R1 + R2	//addqi3
	R2=45	// QImode move
	R3=R1	// QImode move
	[R3]=R2	// QImode move
L81:
.debug
	.dw '.stabn 0x44,0,328,',0,0
	.dd LM206-_write_int_12864
	.dw 0x0d,0x0a
.code
LM206:
	R1=4	// QImode move
	[SP--]=R1	// QImode move
	R1=0	// QImode move
	[SP--]=R1	// QImode move
	R1=[bp+10]	// QImode move
	R1=[bp+10]	// QImode move
	R2=R1+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	R1=BP+2
	[SP--]=R1	// QImode move
	call _write_chinese_12864	// call without return value
	SP = SP + 4	//SP
.debug
	.dw '.stabn 0x44,0,329,',0,0
	.dd LM207-_write_int_12864
	.dw 0x0d,0x0a
.code
LM207:
LBE11:
.debug
	.dw '.stabn 0x44,0,329,',0,0
	.dd LM208-_write_int_12864
	.dw 0x0d,0x0a
.code
LM208:
L76:

	sp+=12
	pop bp from [sp]
	retf
	.endp	// end of write_int_12864

.debug
	.dw '.stabs "myint:p1",160,0,0,15',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "pos:p11",160,0,0,16',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB11-_write_int_12864
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "t:11",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "flag:11",128,0,0,1',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "buffer:23=ar1;0;7;11",128,0,0,2',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE11-_write_int_12864
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME16-_write_int_12864
	.dw 0x0d,0x0a
.code
LME16:
.code
.debug
	.dw '.stabs "write_hanzi_12864:F19",36,0,0,',0,0,offset _write_hanzi_12864,seg _write_hanzi_12864,0x0d,0x0a
.CODE
.public _write_hanzi_12864
_write_hanzi_12864:	.proc
.debug
	.dw '.stabn 0x44,0,338,',0,0
	.dd LM209-_write_hanzi_12864
	.dw 0x0d,0x0a
.code
LM209:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,340,',0,0
	.dd LM210-_write_hanzi_12864
	.dw 0x0d,0x0a
.code
LM210:
L85:

	pop bp from [sp]
	retf
	.endp	// end of write_hanzi_12864

.debug
	.dw '.stabs "hanzi:p20",160,0,0,3',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "length:p11",160,0,0,4',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "hang:p11",160,0,0,5',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "align:p11",160,0,0,6',0x0d,0x0a
.CODE
.debug
	.dw '.stabf ',0,0
	.dd LME17-_write_hanzi_12864
	.dw 0x0d,0x0a
.code
LME17:
.code
.debug
	.dw '.stabs "write_cgram:F19",36,0,0,',0,0,offset _write_cgram,seg _write_cgram,0x0d,0x0a
.CODE
.public _write_cgram
_write_cgram:	.proc
.debug
	.dw '.stabn 0x44,0,343,',0,0
	.dd LM211-_write_cgram
	.dw 0x0d,0x0a
.code
LM211:
	// total=2, vars=2
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=2
	bp=sp+1

	R1=BP+5
	[bp+1]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,344,',0,0
	.dd LM212-_write_cgram
	.dw 0x0d,0x0a
.code
LM212:
LBB12:
.debug
	.dw '.stabn 0x44,0,345,',0,0
	.dd LM213-_write_cgram
	.dw 0x0d,0x0a
.code
LM213:
	call _init_12864	// call without return value
.debug
	.dw '.stabn 0x44,0,346,',0,0
	.dd LM214-_write_cgram
	.dw 0x0d,0x0a
.code
LM214:
	call _clear	// call without return value
.debug
	.dw '.stabn 0x44,0,347,',0,0
	.dd LM215-_write_cgram
	.dw 0x0d,0x0a
.code
LM215:
	R1=64	// QImode move
	[SP--]=R1	// QImode move
	call _write_cmd_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,348,',0,0
	.dd LM216-_write_cgram
	.dw 0x0d,0x0a
.code
LM216:
	R1=0	// QImode move
	[BP]=R1	// QImode move
L87:
	R1=[BP]	// QImode move
	CMP R1,127	// QImode compare
	NSJNA L90	//QImode LEU
	pc=L88	// Indirect jump
L90:
.debug
	.dw '.stabn 0x44,0,350,',0,0
	.dd LM217-_write_cgram
	.dw 0x0d,0x0a
.code
LM217:
	R3=[bp+1]	// QImode move
	R2=[R3]	// QImode move
	R1=R2	// QImode move
	R1 = R1 + [BP]	//addqi3
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	[SP--]=R2	// QImode move
	call _write_data_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,351,',0,0
	.dd LM218-_write_cgram
	.dw 0x0d,0x0a
.code
LM218:
	R1=10	// QImode move
	[SP--]=R1	// QImode move
	call _delay_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,348,',0,0
	.dd LM219-_write_cgram
	.dw 0x0d,0x0a
.code
LM219:
L89:
	R1=[BP]	// QImode move
	R2=R1+1
	[BP]=R2	// QImode move
	pc=L87	// Indirect jump
L88:
.debug
	.dw '.stabn 0x44,0,353,',0,0
	.dd LM220-_write_cgram
	.dw 0x0d,0x0a
.code
LM220:
	R1=128	// QImode move
	[SP--]=R1	// QImode move
	call _write_cmd_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,354,',0,0
	.dd LM221-_write_cgram
	.dw 0x0d,0x0a
.code
LM221:
	R1=0	// QImode move
	[SP--]=R1	// QImode move
	call _write_data_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,355,',0,0
	.dd LM222-_write_cgram
	.dw 0x0d,0x0a
.code
LM222:
	R1=0	// QImode move
	[SP--]=R1	// QImode move
	call _write_data_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,356,',0,0
	.dd LM223-_write_cgram
	.dw 0x0d,0x0a
.code
LM223:
	R1=0	// QImode move
	[SP--]=R1	// QImode move
	call _write_data_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,357,',0,0
	.dd LM224-_write_cgram
	.dw 0x0d,0x0a
.code
LM224:
	R1=2	// QImode move
	[SP--]=R1	// QImode move
	call _write_data_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,358,',0,0
	.dd LM225-_write_cgram
	.dw 0x0d,0x0a
.code
LM225:
	R1=0	// QImode move
	[SP--]=R1	// QImode move
	call _write_data_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,359,',0,0
	.dd LM226-_write_cgram
	.dw 0x0d,0x0a
.code
LM226:
	R1=4	// QImode move
	[SP--]=R1	// QImode move
	call _write_data_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,360,',0,0
	.dd LM227-_write_cgram
	.dw 0x0d,0x0a
.code
LM227:
	R1=0	// QImode move
	[SP--]=R1	// QImode move
	call _write_data_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,361,',0,0
	.dd LM228-_write_cgram
	.dw 0x0d,0x0a
.code
LM228:
	R1=6	// QImode move
	[SP--]=R1	// QImode move
	call _write_data_12864	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,363,',0,0
	.dd LM229-_write_cgram
	.dw 0x0d,0x0a
.code
LM229:
LBE12:
.debug
	.dw '.stabn 0x44,0,363,',0,0
	.dd LM230-_write_cgram
	.dw 0x0d,0x0a
.code
LM230:
L86:

	sp+=2
	pop bp from [sp]
	retf
	.endp	// end of write_cgram

.debug
	.dw '.stabs "table:p20",160,0,0,5',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB12-_write_cgram
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "i:11",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE12-_write_cgram
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME18-_write_cgram
	.dw 0x0d,0x0a
.code
LME18:
.external __BlockCopy
.external __divi1
.external __modi1
	.end

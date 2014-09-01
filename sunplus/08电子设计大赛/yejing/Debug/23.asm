// GCC for SUNPLUS u'nSP version 1.0.21-3
// Command: D:\PROGRA~1\Sunplus\UNSPID~1.0\cc1.exe C:\DOCUME~1\ZHANGZ~1.YSU\LOCALS~1\Temp\cccZbaaa.i -fkeep-inline-functions -quiet -dumpbase 23.c -mglobal-var-iram -gstabs -Wall -o .\Debug/23.asm
	.external __sn_func_ptr_sec

// gcc2_compiled.:

.debug
	.dw '.stabs "F:/abc/kkk/yejing/",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
.code
.debug
	.dw '.stabs "F:/abc/kkk/yejing/23.c",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
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
	.dw '.stabn 0x44,0,10,',0,0
	.dd LM1-_delay
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
	.dw '.stabn 0x44,0,11,',0,0
	.dd LM2-_delay
	.dw 0x0d,0x0a
.code
LM2:
LBB2:
.debug
	.dw '.stabn 0x44,0,12,',0,0
	.dd LM3-_delay
	.dw 0x0d,0x0a
.code
LM3:
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
	.dw '.stabn 0x44,0,14,',0,0
	.dd LM4-_delay
	.dw 0x0d,0x0a
.code
LM4:
	R2=0	// QImode move
	[BP]=R2	// QImode move
L6:
	R2=[BP]	// QImode move
	CMP R2,124	// QImode compare
	NSJNA L9	//QImode LEU
	pc=L7	// Indirect jump
L9:
.debug
	.dw '.stabn 0x44,0,15,',0,0
	.dd LM5-_delay
	.dw 0x0d,0x0a
.code
LM5:
	R2=1	// QImode move
	[28690]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,14,',0,0
	.dd LM6-_delay
	.dw 0x0d,0x0a
.code
LM6:
L8:
	R2=[BP]	// QImode move
	R3=R2+1
	[BP]=R3	// QImode move
	pc=L6	// Indirect jump
L7:
.debug
	.dw '.stabn 0x44,0,16,',0,0
	.dd LM7-_delay
	.dw 0x0d,0x0a
.code
LM7:
	pc=L3	// Indirect jump
L4:
.debug
	.dw '.stabn 0x44,0,17,',0,0
	.dd LM8-_delay
	.dw 0x0d,0x0a
.code
LM8:
LBE2:
.debug
	.dw '.stabn 0x44,0,17,',0,0
	.dd LM9-_delay
	.dw 0x0d,0x0a
.code
LM9:
L2:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of delay

.debug
	.dw '.stabs "t:p4",160,0,0,4',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB2-_delay
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "i:11",128,0,0,0',0x0d,0x0a
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
	.dw '.stabs "busy:F1",36,0,0,',0,0,offset _busy,seg _busy,0x0d,0x0a
.CODE
.public _busy
_busy:	.proc
.debug
	.dw '.stabn 0x44,0,21,',0,0
	.dd LM10-_busy
	.dw 0x0d,0x0a
.code
LM10:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R2=BP+3
.debug
	.dw '.stabn 0x44,0,22,',0,0
	.dd LM11-_busy
	.dw 0x0d,0x0a
.code
LM11:
	R1=[28672]	// QImode move
	R3=R1&(-2)
	[28672]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,23,',0,0
	.dd LM12-_busy
	.dw 0x0d,0x0a
.code
LM12:
	R1=[28672]	// QImode move
	R3=R1|2
	[28672]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,24,',0,0
	.dd LM13-_busy
	.dw 0x0d,0x0a
.code
LM13:
// GCC inline ASM start
	NOP
// GCC inline ASM end
.debug
	.dw '.stabn 0x44,0,25,',0,0
	.dd LM14-_busy
	.dw 0x0d,0x0a
.code
LM14:
	R1=[28672]	// QImode move
	R3=R1|4
	[28672]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,26,',0,0
	.dd LM15-_busy
	.dw 0x0d,0x0a
.code
LM15:
// GCC inline ASM start
	NOP
// GCC inline ASM end
.debug
	.dw '.stabn 0x44,0,27,',0,0
	.dd LM16-_busy
	.dw 0x0d,0x0a
.code
LM16:
	R1=[28672]	// QImode move
	R3=R1&(-5)
	[28672]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,28,',0,0
	.dd LM17-_busy
	.dw 0x0d,0x0a
.code
LM17:
	R1=[28672]	// QImode move
	R3=R1 lsr 4
	R3=R3 lsr 4
	R1=R3	// QImode move
	pc=L12	// Indirect jump
.debug
	.dw '.stabn 0x44,0,29,',0,0
	.dd LM18-_busy
	.dw 0x0d,0x0a
.code
LM18:
.debug
	.dw '.stabn 0x44,0,29,',0,0
	.dd LM19-_busy
	.dw 0x0d,0x0a
.code
LM19:
L12:

	pop bp from [sp]
	retf
	.endp	// end of busy

.debug
	.dw '.stabf ',0,0
	.dd LME2-_busy
	.dw 0x0d,0x0a
.code
LME2:
.code
.debug
	.dw '.stabs "write_cmd:F19",36,0,0,',0,0,offset _write_cmd,seg _write_cmd,0x0d,0x0a
.CODE
.public _write_cmd
_write_cmd:	.proc
.debug
	.dw '.stabn 0x44,0,31,',0,0
	.dd LM20-_write_cmd
	.dw 0x0d,0x0a
.code
LM20:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,32,',0,0
	.dd LM21-_write_cmd
	.dw 0x0d,0x0a
.code
LM21:
	R1=[28672]	// QImode move
	R2=R1&(-5)
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,33,',0,0
	.dd LM22-_write_cmd
	.dw 0x0d,0x0a
.code
LM22:
// GCC inline ASM start
	NOP
// GCC inline ASM end
.debug
	.dw '.stabn 0x44,0,34,',0,0
	.dd LM23-_write_cmd
	.dw 0x0d,0x0a
.code
LM23:
	R1=[28672]	// QImode move
	R2=R1&(-2)
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,35,',0,0
	.dd LM24-_write_cmd
	.dw 0x0d,0x0a
.code
LM24:
// GCC inline ASM start
	NOP
// GCC inline ASM end
.debug
	.dw '.stabn 0x44,0,36,',0,0
	.dd LM25-_write_cmd
	.dw 0x0d,0x0a
.code
LM25:
	R1=[28672]	// QImode move
	R2=R1&(-3)
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,37,',0,0
	.dd LM26-_write_cmd
	.dw 0x0d,0x0a
.code
LM26:
// GCC inline ASM start
	NOP
// GCC inline ASM end
.debug
	.dw '.stabn 0x44,0,38,',0,0
	.dd LM27-_write_cmd
	.dw 0x0d,0x0a
.code
LM27:
	R1=[28672]	// QImode move
	R2=R1&255
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,39,',0,0
	.dd LM28-_write_cmd
	.dw 0x0d,0x0a
.code
LM28:
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
	.dw '.stabn 0x44,0,40,',0,0
	.dd LM29-_write_cmd
	.dw 0x0d,0x0a
.code
LM29:
// GCC inline ASM start
	NOP
// GCC inline ASM end
.debug
	.dw '.stabn 0x44,0,41,',0,0
	.dd LM30-_write_cmd
	.dw 0x0d,0x0a
.code
LM30:
	R1=[28672]	// QImode move
	R2=R1|4
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,42,',0,0
	.dd LM31-_write_cmd
	.dw 0x0d,0x0a
.code
LM31:
// GCC inline ASM start
	NOP
// GCC inline ASM end
.debug
	.dw '.stabn 0x44,0,43,',0,0
	.dd LM32-_write_cmd
	.dw 0x0d,0x0a
.code
LM32:
	R1=[28672]	// QImode move
	R2=R1&(-5)
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,44,',0,0
	.dd LM33-_write_cmd
	.dw 0x0d,0x0a
.code
LM33:
// GCC inline ASM start
	NOP
// GCC inline ASM end
.debug
	.dw '.stabn 0x44,0,45,',0,0
	.dd LM34-_write_cmd
	.dw 0x0d,0x0a
.code
LM34:
	call _busy	// call with return value
.debug
	.dw '.stabn 0x44,0,46,',0,0
	.dd LM35-_write_cmd
	.dw 0x0d,0x0a
.code
LM35:
.debug
	.dw '.stabn 0x44,0,46,',0,0
	.dd LM36-_write_cmd
	.dw 0x0d,0x0a
.code
LM36:
L13:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of write_cmd

.debug
	.dw '.stabs "cmd:p1",160,0,0,4',0x0d,0x0a
.CODE
.debug
	.dw '.stabf ',0,0
	.dd LME3-_write_cmd
	.dw 0x0d,0x0a
.code
LME3:
.code
.debug
	.dw '.stabs "write_dat:F19",36,0,0,',0,0,offset _write_dat,seg _write_dat,0x0d,0x0a
.CODE
.public _write_dat
_write_dat:	.proc
.debug
	.dw '.stabn 0x44,0,49,',0,0
	.dd LM37-_write_dat
	.dw 0x0d,0x0a
.code
LM37:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,50,',0,0
	.dd LM38-_write_dat
	.dw 0x0d,0x0a
.code
LM38:
	R1=[28672]	// QImode move
	R2=R1&(-5)
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,51,',0,0
	.dd LM39-_write_dat
	.dw 0x0d,0x0a
.code
LM39:
// GCC inline ASM start
	NOP
// GCC inline ASM end
.debug
	.dw '.stabn 0x44,0,52,',0,0
	.dd LM40-_write_dat
	.dw 0x0d,0x0a
.code
LM40:
	R1=[28672]	// QImode move
	R2=R1|1
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,53,',0,0
	.dd LM41-_write_dat
	.dw 0x0d,0x0a
.code
LM41:
// GCC inline ASM start
	NOP
// GCC inline ASM end
.debug
	.dw '.stabn 0x44,0,54,',0,0
	.dd LM42-_write_dat
	.dw 0x0d,0x0a
.code
LM42:
	R1=[28672]	// QImode move
	R2=R1&(-3)
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,55,',0,0
	.dd LM43-_write_dat
	.dw 0x0d,0x0a
.code
LM43:
// GCC inline ASM start
	NOP
// GCC inline ASM end
.debug
	.dw '.stabn 0x44,0,56,',0,0
	.dd LM44-_write_dat
	.dw 0x0d,0x0a
.code
LM44:
	R1=[28672]	// QImode move
	R2=R1&255
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,57,',0,0
	.dd LM45-_write_dat
	.dw 0x0d,0x0a
.code
LM45:
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
	.dw '.stabn 0x44,0,58,',0,0
	.dd LM46-_write_dat
	.dw 0x0d,0x0a
.code
LM46:
// GCC inline ASM start
	NOP
// GCC inline ASM end
.debug
	.dw '.stabn 0x44,0,59,',0,0
	.dd LM47-_write_dat
	.dw 0x0d,0x0a
.code
LM47:
	R1=[28672]	// QImode move
	R2=R1|4
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,60,',0,0
	.dd LM48-_write_dat
	.dw 0x0d,0x0a
.code
LM48:
// GCC inline ASM start
	NOP
// GCC inline ASM end
.debug
	.dw '.stabn 0x44,0,61,',0,0
	.dd LM49-_write_dat
	.dw 0x0d,0x0a
.code
LM49:
	R1=[28672]	// QImode move
	R2=R1&(-5)
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,62,',0,0
	.dd LM50-_write_dat
	.dw 0x0d,0x0a
.code
LM50:
// GCC inline ASM start
	NOP
// GCC inline ASM end
.debug
	.dw '.stabn 0x44,0,63,',0,0
	.dd LM51-_write_dat
	.dw 0x0d,0x0a
.code
LM51:
	call _busy	// call with return value
.debug
	.dw '.stabn 0x44,0,64,',0,0
	.dd LM52-_write_dat
	.dw 0x0d,0x0a
.code
LM52:
.debug
	.dw '.stabn 0x44,0,64,',0,0
	.dd LM53-_write_dat
	.dw 0x0d,0x0a
.code
LM53:
L14:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of write_dat

.debug
	.dw '.stabs "dat:p1",160,0,0,4',0x0d,0x0a
.CODE
.debug
	.dw '.stabf ',0,0
	.dd LME4-_write_dat
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
	.dw '.stabn 0x44,0,67,',0,0
	.dd LM54-_show
	.dw 0x0d,0x0a
.code
LM54:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,68,',0,0
	.dd LM55-_show
	.dw 0x0d,0x0a
.code
LM55:
L16:
	R2=[BP]	// QImode move
	R1=[R2]	// QImode move
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	CMP R2,0	// QImode test
	NSJNZ L18	//QImode NE
	pc=L17	// Indirect jump
L18:
.debug
	.dw '.stabn 0x44,0,70,',0,0
	.dd LM56-_show
	.dw 0x0d,0x0a
.code
LM56:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,71,',0,0
	.dd LM57-_show
	.dw 0x0d,0x0a
.code
LM57:
	R2=[BP]	// QImode move
	R1=[R2]	// QImode move
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	[SP--]=R2	// QImode move
	call _write_dat	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,72,',0,0
	.dd LM58-_show
	.dw 0x0d,0x0a
.code
LM58:
	R2=[BP]	// QImode move
	R1=[R2]	// QImode move
	R2=R1+1
	R3=[BP]	// QImode move
	[R3]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,73,',0,0
	.dd LM59-_show
	.dw 0x0d,0x0a
.code
LM59:
	pc=L16	// Indirect jump
L17:
.debug
	.dw '.stabn 0x44,0,74,',0,0
	.dd LM60-_show
	.dw 0x0d,0x0a
.code
LM60:
.debug
	.dw '.stabn 0x44,0,74,',0,0
	.dd LM61-_show
	.dw 0x0d,0x0a
.code
LM61:
L15:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of show

.debug
	.dw '.stabs "str:p20=*2",160,0,0,4',0x0d,0x0a
.CODE
.debug
	.dw '.stabf ',0,0
	.dd LME5-_show
	.dw 0x0d,0x0a
.code
LME5:
.code
.debug
	.dw '.stabs "goxy:F19",36,0,0,',0,0,offset _goxy,seg _goxy,0x0d,0x0a
.CODE
.public _goxy
_goxy:	.proc
.debug
	.dw '.stabn 0x44,0,76,',0,0
	.dd LM62-_goxy
	.dw 0x0d,0x0a
.code
LM62:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,77,',0,0
	.dd LM63-_goxy
	.dw 0x0d,0x0a
.code
LM63:
	R2=[BP]	// QImode move
	R1=[R2]	// QImode move
	CMP R1,1	// QImode compare
	NSJNZ L21	//QImode NE
.debug
	.dw '.stabn 0x44,0,78,',0,0
	.dd LM64-_goxy
	.dw 0x0d,0x0a
.code
LM64:
	R1=[BP]	// QImode move
	R3=[BP]	// QImode move
	R2=R3+1
	R4=R2	// QImode move
	R4=[R4]	// QImode move
	R1=R4|128
	[SP--]=R1	// QImode move
	call _write_cmd	// call without return value
	SP = SP + 1	//SP
L21:
.debug
	.dw '.stabn 0x44,0,79,',0,0
	.dd LM65-_goxy
	.dw 0x0d,0x0a
.code
LM65:
	R2=[BP]	// QImode move
	R1=[R2]	// QImode move
	CMP R1,2	// QImode compare
	NSJNZ L22	//QImode NE
.debug
	.dw '.stabn 0x44,0,80,',0,0
	.dd LM66-_goxy
	.dw 0x0d,0x0a
.code
LM66:
	R1=[BP]	// QImode move
	R3=[BP]	// QImode move
	R2=R3+1
	R4=R2	// QImode move
	R3=[R4]	// QImode move
	R1=R3+64
	[SP--]=R1	// QImode move
	call _write_cmd	// call without return value
	SP = SP + 1	//SP
L22:
.debug
	.dw '.stabn 0x44,0,81,',0,0
	.dd LM67-_goxy
	.dw 0x0d,0x0a
.code
LM67:
.debug
	.dw '.stabn 0x44,0,81,',0,0
	.dd LM68-_goxy
	.dw 0x0d,0x0a
.code
LM68:
L20:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of goxy

.debug
	.dw '.stabs "y:p1",160,0,0,4',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "x:p1",160,0,0,5',0x0d,0x0a
.CODE
.debug
	.dw '.stabf ',0,0
	.dd LME6-_goxy
	.dw 0x0d,0x0a
.code
LME6:
.code
.debug
	.dw '.stabs "init_1602:F19",36,0,0,',0,0,offset _init_1602,seg _init_1602,0x0d,0x0a
.CODE
.public _init_1602
_init_1602:	.proc
.debug
	.dw '.stabn 0x44,0,83,',0,0
	.dd LM69-_init_1602
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
	.dw '.stabn 0x44,0,84,',0,0
	.dd LM70-_init_1602
	.dw 0x0d,0x0a
.code
LM70:
	R1=[28672]	// QImode move
	R2=R1&(-5)
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,85,',0,0
	.dd LM71-_init_1602
	.dw 0x0d,0x0a
.code
LM71:
	R1=15	// QImode move
	[SP--]=R1	// QImode move
	call _delay	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,86,',0,0
	.dd LM72-_init_1602
	.dw 0x0d,0x0a
.code
LM72:
	R1=56	// QImode move
	[SP--]=R1	// QImode move
	call _write_cmd	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,87,',0,0
	.dd LM73-_init_1602
	.dw 0x0d,0x0a
.code
LM73:
	R1=5	// QImode move
	[SP--]=R1	// QImode move
	call _delay	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,88,',0,0
	.dd LM74-_init_1602
	.dw 0x0d,0x0a
.code
LM74:
	R1=56	// QImode move
	[SP--]=R1	// QImode move
	call _write_cmd	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,89,',0,0
	.dd LM75-_init_1602
	.dw 0x0d,0x0a
.code
LM75:
	R1=5	// QImode move
	[SP--]=R1	// QImode move
	call _delay	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,90,',0,0
	.dd LM76-_init_1602
	.dw 0x0d,0x0a
.code
LM76:
	R1=56	// QImode move
	[SP--]=R1	// QImode move
	call _write_cmd	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,91,',0,0
	.dd LM77-_init_1602
	.dw 0x0d,0x0a
.code
LM77:
	R1=56	// QImode move
	[SP--]=R1	// QImode move
	call _write_cmd	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,92,',0,0
	.dd LM78-_init_1602
	.dw 0x0d,0x0a
.code
LM78:
// GCC inline ASM start
	NOP
// GCC inline ASM end
.debug
	.dw '.stabn 0x44,0,93,',0,0
	.dd LM79-_init_1602
	.dw 0x0d,0x0a
.code
LM79:
	R1=8	// QImode move
	[SP--]=R1	// QImode move
	call _write_cmd	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,94,',0,0
	.dd LM80-_init_1602
	.dw 0x0d,0x0a
.code
LM80:
// GCC inline ASM start
	NOP
// GCC inline ASM end
.debug
	.dw '.stabn 0x44,0,95,',0,0
	.dd LM81-_init_1602
	.dw 0x0d,0x0a
.code
LM81:
	R1=6	// QImode move
	[SP--]=R1	// QImode move
	call _write_cmd	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,96,',0,0
	.dd LM82-_init_1602
	.dw 0x0d,0x0a
.code
LM82:
// GCC inline ASM start
	NOP
// GCC inline ASM end
.debug
	.dw '.stabn 0x44,0,97,',0,0
	.dd LM83-_init_1602
	.dw 0x0d,0x0a
.code
LM83:
	R1=12	// QImode move
	[SP--]=R1	// QImode move
	call _write_cmd	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,98,',0,0
	.dd LM84-_init_1602
	.dw 0x0d,0x0a
.code
LM84:
// GCC inline ASM start
	NOP
// GCC inline ASM end
.debug
	.dw '.stabn 0x44,0,99,',0,0
	.dd LM85-_init_1602
	.dw 0x0d,0x0a
.code
LM85:
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	call _write_cmd	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,100,',0,0
	.dd LM86-_init_1602
	.dw 0x0d,0x0a
.code
LM86:
// GCC inline ASM start
	NOP
// GCC inline ASM end
.debug
	.dw '.stabn 0x44,0,101,',0,0
	.dd LM87-_init_1602
	.dw 0x0d,0x0a
.code
LM87:
.debug
	.dw '.stabn 0x44,0,101,',0,0
	.dd LM88-_init_1602
	.dw 0x0d,0x0a
.code
LM88:
L25:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of init_1602

.debug
	.dw '.stabf ',0,0
	.dd LME7-_init_1602
	.dw 0x0d,0x0a
.code
LME7:
.text
LC0:
	.str 'I', ' ', 'a', 'm', ' ', 'k', 'k', 'k', 0
	// length = 9
LC1:
	.str 'w', 'k', 0
	// length = 3
.code
.debug
	.dw '.stabs "main:F1",36,0,0,',0,0,offset _main,seg _main,0x0d,0x0a
.CODE
.public _main
_main:	.proc
.debug
	.dw '.stabn 0x44,0,104,',0,0
	.dd LM89-_main
	.dw 0x0d,0x0a
.code
LM89:
	// total=2, vars=2
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=2
	bp=sp+1

	R1=BP+5
	[bp+1]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,105,',0,0
	.dd LM90-_main
	.dw 0x0d,0x0a
.code
LM90:
LBB3:
	R1=0	// QImode move
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,106,',0,0
	.dd LM91-_main
	.dw 0x0d,0x0a
.code
LM91:
	R1=(-1)	// QImode move
	[28674]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,107,',0,0
	.dd LM92-_main
	.dw 0x0d,0x0a
.code
LM92:
	R1=(-1)	// QImode move
	[28675]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,108,',0,0
	.dd LM93-_main
	.dw 0x0d,0x0a
.code
LM93:
	R1=0	// QImode move
	[28672]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,109,',0,0
	.dd LM94-_main
	.dw 0x0d,0x0a
.code
LM94:
	call _init_1602	// call without return value
.debug
	.dw '.stabn 0x44,0,110,',0,0
	.dd LM95-_main
	.dw 0x0d,0x0a
.code
LM95:
	R1=500	// QImode move
	[SP--]=R1	// QImode move
	call _delay	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,111,',0,0
	.dd LM96-_main
	.dw 0x0d,0x0a
.code
LM96:
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	call _write_cmd	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,112,',0,0
	.dd LM97-_main
	.dw 0x0d,0x0a
.code
LM97:
	R1=6	// QImode move
	[SP--]=R1	// QImode move
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	call _goxy	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,113,',0,0
	.dd LM98-_main
	.dw 0x0d,0x0a
.code
LM98:
	R1=LC0	// QImode move
	[SP--]=R1	// QImode move
	call _show	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,114,',0,0
	.dd LM99-_main
	.dw 0x0d,0x0a
.code
LM99:
	R1=1000	// QImode move
	[SP--]=R1	// QImode move
	call _delay	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,115,',0,0
	.dd LM100-_main
	.dw 0x0d,0x0a
.code
LM100:
	R1=0	// QImode move
	[SP--]=R1	// QImode move
	R1=2	// QImode move
	[SP--]=R1	// QImode move
	call _goxy	// call without return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,116,',0,0
	.dd LM101-_main
	.dw 0x0d,0x0a
.code
LM101:
	R1=LC1	// QImode move
	[SP--]=R1	// QImode move
	call _show	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,117,',0,0
	.dd LM102-_main
	.dw 0x0d,0x0a
.code
LM102:
	R1=1000	// QImode move
	[SP--]=R1	// QImode move
	call _delay	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,118,',0,0
	.dd LM103-_main
	.dw 0x0d,0x0a
.code
LM103:
L27:
	pc=L29	// Indirect jump
	pc=L28	// Indirect jump
L29:
.debug
	.dw '.stabn 0x44,0,121,',0,0
	.dd LM104-_main
	.dw 0x0d,0x0a
.code
LM104:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,122,',0,0
	.dd LM105-_main
	.dw 0x0d,0x0a
.code
LM105:
	pc=L27	// Indirect jump
L28:
.debug
	.dw '.stabn 0x44,0,123,',0,0
	.dd LM106-_main
	.dw 0x0d,0x0a
.code
LM106:
LBE3:
.debug
	.dw '.stabn 0x44,0,123,',0,0
	.dd LM107-_main
	.dw 0x0d,0x0a
.code
LM107:
L26:

	sp+=2
	pop bp from [sp]
	retf
	.endp	// end of main

.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB3-_main
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "i:1",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE3-_main
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME8-_main
	.dw 0x0d,0x0a
.code
LME8:
	.end

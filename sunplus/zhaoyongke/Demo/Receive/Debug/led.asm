// GCC for SUNPLUS u'nSP version 1.0.21-3
// Command: C:\PROGRA~1\Sunplus\UNSPID~1.0\cc1.exe C:\DOCUME~1\ADMINI~1\LOCALS~1\Temp\cc06aaaa.i -fkeep-inline-functions -quiet -dumpbase led.c -mglobal-var-iram -gstabs -Wall -o .\Debug/led.asm
	.external __sn_func_ptr_sec

// gcc2_compiled.:

.debug
	.dw '.stabs "E:/zhaoyongke/Demo/Receive/",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
.code
.debug
	.dw '.stabs "E:/zhaoyongke/Demo/Receive/led.c",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
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
	.dw '.stabn 0x44,0,3,',0,0
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
	.dw '.stabn 0x44,0,4,',0,0
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
	pc=L3	// Indirect jump
L4:
.debug
	.dw '.stabn 0x44,0,5,',0,0
	.dd LM3-_delay
	.dw 0x0d,0x0a
.code
LM3:
.debug
	.dw '.stabn 0x44,0,5,',0,0
	.dd LM4-_delay
	.dw 0x0d,0x0a
.code
LM4:
L2:

	pop bp from [sp]
	retf
	.endp	// end of delay

.debug
	.dw '.stabs "t:p4",160,0,0,3',0x0d,0x0a
.CODE
.debug
	.dw '.stabf ',0,0
	.dd LME1-_delay
	.dw 0x0d,0x0a
.code
LME1:
.text
LC0:
	.dw 16128
	.dw 1536
	.dw 23296
	.dw 20224
	.dw 26112
	.dw 27904
	.dw 32000
	.dw 1792
	.dw 32512
	.dw 28416
	.dw 16384
.code
.debug
	.dw '.stabs "show:F19",36,0,0,',0,0,offset _show,seg _show,0x0d,0x0a
.CODE
.public _show
_show:	.proc
.debug
	.dw '.stabn 0x44,0,7,',0,0
	.dd LM5-_show
	.dw 0x0d,0x0a
.code
LM5:
	// total=13, vars=13
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=13
	bp=sp+1

	R1=BP+16
	[bp+12]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,8,',0,0
	.dd LM6-_show
	.dw 0x0d,0x0a
.code
LM6:
LBB2:
	R2=BP	// QImode move
	R1=BP	// QImode move
	R2=LC0	// QImode move
	R3=11	// QImode move
	[SP--]=R3	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __BlockCopy	// call with return value
	SP = SP + 3	//SP
.debug
	.dw '.stabn 0x44,0,10,',0,0
	.dd LM7-_show
	.dw 0x0d,0x0a
.code
LM7:
	R1=BP	// QImode move
	R2=BP+11
	R1=0	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
L8:
	R2=BP	// QImode move
	R1=BP+11
	R2=[bp+12]	// QImode move
	R4=[bp+12]	// QImode move
	R3=R4+1
	R2=R1	// QImode move
	R1=[R2]	// QImode move
	R4=R3	// QImode move
	CMP R1,[R4]	// QImode compare
	NSJB L11	//QImode LTU
	pc=L9	// Indirect jump
L11:
.debug
	.dw '.stabn 0x44,0,12,',0,0
	.dd LM8-_show
	.dw 0x0d,0x0a
.code
LM8:
	R1=150	// QImode move
	[SP--]=R1	// QImode move
	call _delay	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,13,',0,0
	.dd LM9-_show
	.dw 0x0d,0x0a
.code
LM9:
	R1=[28677]	// QImode move
	R2=R1&255
	[28677]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,14,',0,0
	.dd LM10-_show
	.dw 0x0d,0x0a
.code
LM10:
	R1=[28672]	// QImode move
	R2=R1&255
	[28672]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,15,',0,0
	.dd LM11-_show
	.dw 0x0d,0x0a
.code
LM11:
	R2=[bp+12]	// QImode move
	R1=[R2]	// QImode move
	R2=BP	// QImode move
	R3=BP+11
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R1 = R1 + R2	//addqi3
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	R1=BP	// QImode move
	R1 = R1 + R2	//addqi3
	R2=[28672]	// QImode move
	R3=R2	// QImode move
	R4=R1	// QImode move
	R3|=[R4]	// iorqi3_r0R
	R1=R3	// QImode move
	[28672]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,16,',0,0
	.dd LM12-_show
	.dw 0x0d,0x0a
.code
LM12:
	R1=BP	// QImode move
	R2=BP+11
	R1=256	// QImode move
	R4=R2	// QImode move
	R2=[R4]	// QImode move
	[SP--]=R2	// QImode move
	[SP--]=R1	// QImode move
	call __lshiu1	// call with return value
	SP = SP + 2	//SP
	R2=[28677]	// QImode move
	R3=R2	// QImode move
	R3|=R1
	R1=R3	// QImode move
	[28677]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,10,',0,0
	.dd LM13-_show
	.dw 0x0d,0x0a
.code
LM13:
L10:
	R1=BP	// QImode move
	R2=BP+11
	R3=BP	// QImode move
	R1=BP+11
	R2=BP	// QImode move
	R3=BP+11
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R3=R2+1
	R2=R1	// QImode move
	[R2]=R3	// QImode move
	pc=L8	// Indirect jump
L9:
.debug
	.dw '.stabn 0x44,0,18,',0,0
	.dd LM14-_show
	.dw 0x0d,0x0a
.code
LM14:
LBE2:
.debug
	.dw '.stabn 0x44,0,18,',0,0
	.dd LM15-_show
	.dw 0x0d,0x0a
.code
LM15:
L7:

	sp+=13
	pop bp from [sp]
	retf
	.endp	// end of show

.debug
	.dw '.stabs "buffer:p20=*4",160,0,0,16',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "size:p4",160,0,0,17',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB2-_show
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "segtable:21=ar1;0;10;11",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "i:1",128,0,0,11',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE2-_show
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME2-_show
	.dw 0x0d,0x0a
.code
LME2:
.external __BlockCopy
.external __lshiu1
	.end

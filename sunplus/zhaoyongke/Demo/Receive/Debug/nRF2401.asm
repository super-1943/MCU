// GCC for SUNPLUS u'nSP version 1.0.21-3
// Command: C:\PROGRA~1\Sunplus\UNSPID~1.0\cc1.exe C:\DOCUME~1\ADMINI~1\LOCALS~1\Temp\ccecbaaa.i -fkeep-inline-functions -quiet -dumpbase nRF2401.c -mglobal-var-iram -gstabs -Wall -o .\Debug/nRF2401.asm
	.external __sn_func_ptr_sec

// gcc2_compiled.:

.debug
	.dw '.stabs "E:/zhaoyongke/Demo/Receive/",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
.code
.debug
	.dw '.stabs "E:/zhaoyongke/Demo/Receive/nRF2401.c",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
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
.public _InitData
.text
_InitData:
	.dw 8
	.dw 8
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 1
	.dw 0
	.dw 0
	.dw 0
	.dw 0
	.dw 1
	.dw 163
	.dw 79
	.dw 5
.debug
	.dw '.stabs "InitData:G20=ar1;0;14;4",32,0,0,',0,0,offset _InitData,seg _InitData,0x0d,0x0a
.CODE
.debug
	.dw '.stabs "AddrBuffer:G21=ar1;0;4;4",32,0,0,',0,0,offset _AddrBuffer,seg _AddrBuffer,0x0d,0x0a
.CODE
.debug
	.dw '.stabs "AddrByteCnt:G4",32,0,0,',0,0,offset _AddrByteCnt,seg _AddrByteCnt,0x0d,0x0a
.CODE
.code
.debug
	.dw '.stabs "nRF2401_Initial:F19",36,0,0,',0,0,offset _nRF2401_Initial,seg _nRF2401_Initial,0x0d,0x0a
.CODE
.public _nRF2401_Initial
_nRF2401_Initial:	.proc
.debug
	.dw '.stabn 0x44,0,72,',0,0
	.dd LM1-_nRF2401_Initial
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
	.dw '.stabn 0x44,0,73,',0,0
	.dd LM2-_nRF2401_Initial
	.dw 0x0d,0x0a
.code
LM2:
	R1=152	// QImode move
	[28691]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,74,',0,0
	.dd LM3-_nRF2401_Initial
	.dw 0x0d,0x0a
.code
LM3:
	R1=[28680]	// QImode move
	R2=R1|63
	[28680]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,75,',0,0
	.dd LM4-_nRF2401_Initial
	.dw 0x0d,0x0a
.code
LM4:
	R1=[28679]	// QImode move
	R2=R1|55
	[28679]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,76,',0,0
	.dd LM5-_nRF2401_Initial
	.dw 0x0d,0x0a
.code
LM5:
	R1=[28679]	// QImode move
	R2=R1&(-9)
	[28679]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,77,',0,0
	.dd LM6-_nRF2401_Initial
	.dw 0x0d,0x0a
.code
LM6:
	R1=[28678]	// QImode move
	R2=R1&(-63)
	[28678]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,79,',0,0
	.dd LM7-_nRF2401_Initial
	.dw 0x0d,0x0a
.code
LM7:
	call _nRF2401_ON	// call without return value
.debug
	.dw '.stabn 0x44,0,80,',0,0
	.dd LM8-_nRF2401_Initial
	.dw 0x0d,0x0a
.code
LM8:
	R1=3000	// QImode move
	[SP--]=R1	// QImode move
	call _Delay_Us	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,81,',0,0
	.dd LM9-_nRF2401_Initial
	.dw 0x0d,0x0a
.code
LM9:
	call _nRF2401_WriteCommand	// call without return value
.debug
	.dw '.stabn 0x44,0,82,',0,0
	.dd LM10-_nRF2401_Initial
	.dw 0x0d,0x0a
.code
LM10:
	R1=300	// QImode move
	[SP--]=R1	// QImode move
	call _Delay_Us	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,83,',0,0
	.dd LM11-_nRF2401_Initial
	.dw 0x0d,0x0a
.code
LM11:
.debug
	.dw '.stabn 0x44,0,83,',0,0
	.dd LM12-_nRF2401_Initial
	.dw 0x0d,0x0a
.code
LM12:
L2:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of nRF2401_Initial

.debug
	.dw '.stabf ',0,0
	.dd LME1-_nRF2401_Initial
	.dw 0x0d,0x0a
.code
LME1:
.code
.debug
	.dw '.stabs "nRF2401_ON:F19",36,0,0,',0,0,offset _nRF2401_ON,seg _nRF2401_ON,0x0d,0x0a
.CODE
.public _nRF2401_ON
_nRF2401_ON:	.proc
.debug
	.dw '.stabn 0x44,0,92,',0,0
	.dd LM13-_nRF2401_ON
	.dw 0x0d,0x0a
.code
LM13:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,93,',0,0
	.dd LM14-_nRF2401_ON
	.dw 0x0d,0x0a
.code
LM14:
	R2=[28678]	// QImode move
	R3=R2|1
	[28678]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,94,',0,0
	.dd LM15-_nRF2401_ON
	.dw 0x0d,0x0a
.code
LM15:
.debug
	.dw '.stabn 0x44,0,94,',0,0
	.dd LM16-_nRF2401_ON
	.dw 0x0d,0x0a
.code
LM16:
L3:

	pop bp from [sp]
	retf
	.endp	// end of nRF2401_ON

.debug
	.dw '.stabf ',0,0
	.dd LME2-_nRF2401_ON
	.dw 0x0d,0x0a
.code
LME2:
.code
.debug
	.dw '.stabs "nRF2401_OFF:F19",36,0,0,',0,0,offset _nRF2401_OFF,seg _nRF2401_OFF,0x0d,0x0a
.CODE
.public _nRF2401_OFF
_nRF2401_OFF:	.proc
.debug
	.dw '.stabn 0x44,0,103,',0,0
	.dd LM17-_nRF2401_OFF
	.dw 0x0d,0x0a
.code
LM17:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,104,',0,0
	.dd LM18-_nRF2401_OFF
	.dw 0x0d,0x0a
.code
LM18:
	R2=[28678]	// QImode move
	R3=R2&(-2)
	[28678]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,105,',0,0
	.dd LM19-_nRF2401_OFF
	.dw 0x0d,0x0a
.code
LM19:
.debug
	.dw '.stabn 0x44,0,105,',0,0
	.dd LM20-_nRF2401_OFF
	.dw 0x0d,0x0a
.code
LM20:
L4:

	pop bp from [sp]
	retf
	.endp	// end of nRF2401_OFF

.debug
	.dw '.stabf ',0,0
	.dd LME3-_nRF2401_OFF
	.dw 0x0d,0x0a
.code
LME3:
.code
.debug
	.dw '.stabs "nRF2401_WriteCommand:F19",36,0,0,',0,0,offset _nRF2401_WriteCommand,seg _nRF2401_WriteCommand,0x0d,0x0a
.CODE
.public _nRF2401_WriteCommand
_nRF2401_WriteCommand:	.proc
.debug
	.dw '.stabn 0x44,0,114,',0,0
	.dd LM21-_nRF2401_WriteCommand
	.dw 0x0d,0x0a
.code
LM21:
	// total=2, vars=2
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=2
	bp=sp+1

	R1=BP+5
	[bp+1]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,115,',0,0
	.dd LM22-_nRF2401_WriteCommand
	.dw 0x0d,0x0a
.code
LM22:
LBB2:
.debug
	.dw '.stabn 0x44,0,116,',0,0
	.dd LM23-_nRF2401_WriteCommand
	.dw 0x0d,0x0a
.code
LM23:
	R1=[28678]	// QImode move
	R2=R1&(-3)
	[28678]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,117,',0,0
	.dd LM24-_nRF2401_WriteCommand
	.dw 0x0d,0x0a
.code
LM24:
	R1=[28678]	// QImode move
	R2=R1|4
	[28678]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,118,',0,0
	.dd LM25-_nRF2401_WriteCommand
	.dw 0x0d,0x0a
.code
LM25:
	R1=5	// QImode move
	[SP--]=R1	// QImode move
	call _Delay_Us	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,119,',0,0
	.dd LM26-_nRF2401_WriteCommand
	.dw 0x0d,0x0a
.code
LM26:
	R1=0	// QImode move
	[BP]=R1	// QImode move
L6:
	R1=[BP]	// QImode move
	CMP R1,14	// QImode compare
	NSJNA L9	//QImode LEU
	pc=L7	// Indirect jump
L9:
.debug
	.dw '.stabn 0x44,0,121,',0,0
	.dd LM27-_nRF2401_WriteCommand
	.dw 0x0d,0x0a
.code
LM27:
	R1=_InitData	// QImode move
	R2=[BP]	// QImode move
	R1 = R1 + R2	//addqi3
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	[SP--]=R2	// QImode move
	call _nRF2401_WriteByte	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,119,',0,0
	.dd LM28-_nRF2401_WriteCommand
	.dw 0x0d,0x0a
.code
LM28:
L8:
	R1=[BP]	// QImode move
	R2=R1+1
	[BP]=R2	// QImode move
	pc=L6	// Indirect jump
L7:
.debug
	.dw '.stabn 0x44,0,123,',0,0
	.dd LM29-_nRF2401_WriteCommand
	.dw 0x0d,0x0a
.code
LM29:
	R1=[28678]	// QImode move
	R2=R1&(-5)
	[28678]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,124,',0,0
	.dd LM30-_nRF2401_WriteCommand
	.dw 0x0d,0x0a
.code
LM30:
	R1=[28678]	// QImode move
	R2=R1|2
	[28678]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,125,',0,0
	.dd LM31-_nRF2401_WriteCommand
	.dw 0x0d,0x0a
.code
LM31:
LBE2:
.debug
	.dw '.stabn 0x44,0,125,',0,0
	.dd LM32-_nRF2401_WriteCommand
	.dw 0x0d,0x0a
.code
LM32:
L5:

	sp+=2
	pop bp from [sp]
	retf
	.endp	// end of nRF2401_WriteCommand

.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB2-_nRF2401_WriteCommand
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "i:4",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE2-_nRF2401_WriteCommand
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME4-_nRF2401_WriteCommand
	.dw 0x0d,0x0a
.code
LME4:
.code
.debug
	.dw '.stabs "nRF2401_Mode:F19",36,0,0,',0,0,offset _nRF2401_Mode,seg _nRF2401_Mode,0x0d,0x0a
.CODE
.public _nRF2401_Mode
_nRF2401_Mode:	.proc
.debug
	.dw '.stabn 0x44,0,134,',0,0
	.dd LM33-_nRF2401_Mode
	.dw 0x0d,0x0a
.code
LM33:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,135,',0,0
	.dd LM34-_nRF2401_Mode
	.dw 0x0d,0x0a
.code
LM34:
	R1=[28678]	// QImode move
	R2=R1&(-3)
	[28678]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,136,',0,0
	.dd LM35-_nRF2401_Mode
	.dw 0x0d,0x0a
.code
LM35:
	R1=[28678]	// QImode move
	R2=R1|4
	[28678]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,137,',0,0
	.dd LM36-_nRF2401_Mode
	.dw 0x0d,0x0a
.code
LM36:
	R2=[BP]	// QImode move
	R1=[R2]	// QImode move
	CMP R1,0	// QImode test
	NSJNZ L12	//QImode NE
.debug
	.dw '.stabn 0x44,0,138,',0,0
	.dd LM37-_nRF2401_Mode
	.dw 0x0d,0x0a
.code
LM37:
	R2=[_InitData+14]	// QImode move
	R1=R2|1
	[SP--]=R1	// QImode move
	call _nRF2401_WriteByte	// call without return value
	SP = SP + 1	//SP
	pc=L13	// Indirect jump
L12:
.debug
	.dw '.stabn 0x44,0,140,',0,0
	.dd LM38-_nRF2401_Mode
	.dw 0x0d,0x0a
.code
LM38:
	R2=[_InitData+14]	// QImode move
	R1=R2&254
	[SP--]=R1	// QImode move
	call _nRF2401_WriteByte	// call without return value
	SP = SP + 1	//SP
L13:
.debug
	.dw '.stabn 0x44,0,141,',0,0
	.dd LM39-_nRF2401_Mode
	.dw 0x0d,0x0a
.code
LM39:
	R1=[28678]	// QImode move
	R2=R1&(-5)
	[28678]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,142,',0,0
	.dd LM40-_nRF2401_Mode
	.dw 0x0d,0x0a
.code
LM40:
	R1=[28678]	// QImode move
	R2=R1|2
	[28678]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,143,',0,0
	.dd LM41-_nRF2401_Mode
	.dw 0x0d,0x0a
.code
LM41:
.debug
	.dw '.stabn 0x44,0,143,',0,0
	.dd LM42-_nRF2401_Mode
	.dw 0x0d,0x0a
.code
LM42:
L11:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of nRF2401_Mode

.debug
	.dw '.stabs "uiMode:p4",160,0,0,4',0x0d,0x0a
.CODE
.debug
	.dw '.stabf ',0,0
	.dd LME5-_nRF2401_Mode
	.dw 0x0d,0x0a
.code
LME5:
.code
.debug
	.dw '.stabs "nRF2401_SetAddress:F19",36,0,0,',0,0,offset _nRF2401_SetAddress,seg _nRF2401_SetAddress,0x0d,0x0a
.CODE
.public _nRF2401_SetAddress
_nRF2401_SetAddress:	.proc
.debug
	.dw '.stabn 0x44,0,153,',0,0
	.dd LM43-_nRF2401_SetAddress
	.dw 0x0d,0x0a
.code
LM43:
	// total=2, vars=2
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=2
	bp=sp+1

	R1=BP+5
.debug
	.dw '.stabn 0x44,0,154,',0,0
	.dd LM44-_nRF2401_SetAddress
	.dw 0x0d,0x0a
.code
LM44:
LBB3:
.debug
	.dw '.stabn 0x44,0,155,',0,0
	.dd LM45-_nRF2401_SetAddress
	.dw 0x0d,0x0a
.code
LM45:
	R2=0	// QImode move
	[BP]=R2	// QImode move
L16:
	R2=R1	// QImode move
	R3=R1+1
	R2=[BP]	// QImode move
	R4=R3	// QImode move
	CMP R2,[R4]	// QImode compare
	NSJB L19	//QImode LTU
	pc=L17	// Indirect jump
L19:
.debug
	.dw '.stabn 0x44,0,157,',0,0
	.dd LM46-_nRF2401_SetAddress
	.dw 0x0d,0x0a
.code
LM46:
	R2=_AddrBuffer	// QImode move
	R3=[BP]	// QImode move
	R2 = R2 + R3	//addqi3
	R3=R1	// QImode move
	R4=[R3]	// QImode move
	R3=R4	// QImode move
	R3 = R3 + [BP]	//addqi3
	R4=R3	// QImode move
	R4=[R4]	// QImode move
	[bp+1]=R4	// QImode move
	R3=[bp+1]	// QImode move
	R4=R2	// QImode move
	[R4]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,155,',0,0
	.dd LM47-_nRF2401_SetAddress
	.dw 0x0d,0x0a
.code
LM47:
L18:
	R2=[BP]	// QImode move
	R3=R2+1
	[BP]=R3	// QImode move
	pc=L16	// Indirect jump
L17:
.debug
	.dw '.stabn 0x44,0,159,',0,0
	.dd LM48-_nRF2401_SetAddress
	.dw 0x0d,0x0a
.code
LM48:
	R2=R1	// QImode move
	R3=R1+1
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	[_AddrByteCnt]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,160,',0,0
	.dd LM49-_nRF2401_SetAddress
	.dw 0x0d,0x0a
.code
LM49:
LBE3:
.debug
	.dw '.stabn 0x44,0,160,',0,0
	.dd LM50-_nRF2401_SetAddress
	.dw 0x0d,0x0a
.code
LM50:
L15:

	sp+=2
	pop bp from [sp]
	retf
	.endp	// end of nRF2401_SetAddress

.debug
	.dw '.stabs "Address:p22=*4",160,0,0,5',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "AddrByte:p4",160,0,0,6',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB3-_nRF2401_SetAddress
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "i:4",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE3-_nRF2401_SetAddress
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME6-_nRF2401_SetAddress
	.dw 0x0d,0x0a
.code
LME6:
.code
.debug
	.dw '.stabs "nRF2401_WriteByte:F19",36,0,0,',0,0,offset _nRF2401_WriteByte,seg _nRF2401_WriteByte,0x0d,0x0a
.CODE
.public _nRF2401_WriteByte
_nRF2401_WriteByte:	.proc
.debug
	.dw '.stabn 0x44,0,169,',0,0
	.dd LM51-_nRF2401_WriteByte
	.dw 0x0d,0x0a
.code
LM51:
	// total=2, vars=2
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=2
	bp=sp+1

	R1=BP+5
	[bp+1]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,170,',0,0
	.dd LM52-_nRF2401_WriteByte
	.dw 0x0d,0x0a
.code
LM52:
LBB4:
.debug
	.dw '.stabn 0x44,0,171,',0,0
	.dd LM53-_nRF2401_WriteByte
	.dw 0x0d,0x0a
.code
LM53:
	R1=0	// QImode move
	[BP]=R1	// QImode move
L22:
	R1=[BP]	// QImode move
	CMP R1,7	// QImode compare
	NSJNA L25	//QImode LEU
	pc=L23	// Indirect jump
L25:
.debug
	.dw '.stabn 0x44,0,173,',0,0
	.dd LM54-_nRF2401_WriteByte
	.dw 0x0d,0x0a
.code
LM54:
	R1=[28678]	// QImode move
	R2=R1&(-17)
	[28678]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,174,',0,0
	.dd LM55-_nRF2401_WriteByte
	.dw 0x0d,0x0a
.code
LM55:
	R2=[bp+1]	// QImode move
	R2=[R2]	// QImode move
	R1=R2&128
	CMP R1,0	// QImode test
	NSJZ L26	//QImode EQ
.debug
	.dw '.stabn 0x44,0,175,',0,0
	.dd LM56-_nRF2401_WriteByte
	.dw 0x0d,0x0a
.code
LM56:
	R1=[28678]	// QImode move
	R2=R1|32
	[28678]=R2	// QImode move
	pc=L27	// Indirect jump
L26:
.debug
	.dw '.stabn 0x44,0,177,',0,0
	.dd LM57-_nRF2401_WriteByte
	.dw 0x0d,0x0a
.code
LM57:
	R1=[28678]	// QImode move
	R2=R1&(-33)
	[28678]=R2	// QImode move
L27:
.debug
	.dw '.stabn 0x44,0,178,',0,0
	.dd LM58-_nRF2401_WriteByte
	.dw 0x0d,0x0a
.code
LM58:
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	call _Delay_Us	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,179,',0,0
	.dd LM59-_nRF2401_WriteByte
	.dw 0x0d,0x0a
.code
LM59:
	R1=[28678]	// QImode move
	R2=R1|16
	[28678]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,180,',0,0
	.dd LM60-_nRF2401_WriteByte
	.dw 0x0d,0x0a
.code
LM60:
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	call _Delay_Us	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,181,',0,0
	.dd LM61-_nRF2401_WriteByte
	.dw 0x0d,0x0a
.code
LM61:
	R1=[28678]	// QImode move
	R2=R1&(-17)
	[28678]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,182,',0,0
	.dd LM62-_nRF2401_WriteByte
	.dw 0x0d,0x0a
.code
LM62:
	R3=[bp+1]	// QImode move
	R1=[R3]	// QImode move
	R2=R1 lsl 1
	R1=[bp+1]	// QImode move
	[R1]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,171,',0,0
	.dd LM63-_nRF2401_WriteByte
	.dw 0x0d,0x0a
.code
LM63:
L24:
	R1=[BP]	// QImode move
	R2=R1+1
	[BP]=R2	// QImode move
	pc=L22	// Indirect jump
L23:
.debug
	.dw '.stabn 0x44,0,184,',0,0
	.dd LM64-_nRF2401_WriteByte
	.dw 0x0d,0x0a
.code
LM64:
LBE4:
.debug
	.dw '.stabn 0x44,0,184,',0,0
	.dd LM65-_nRF2401_WriteByte
	.dw 0x0d,0x0a
.code
LM65:
L21:

	sp+=2
	pop bp from [sp]
	retf
	.endp	// end of nRF2401_WriteByte

.debug
	.dw '.stabs "uiData:p4",160,0,0,5',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB4-_nRF2401_WriteByte
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "i:4",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE4-_nRF2401_WriteByte
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME7-_nRF2401_WriteByte
	.dw 0x0d,0x0a
.code
LME7:
.code
.debug
	.dw '.stabs "nRF2401_WriteWord:F19",36,0,0,',0,0,offset _nRF2401_WriteWord,seg _nRF2401_WriteWord,0x0d,0x0a
.CODE
.public _nRF2401_WriteWord
_nRF2401_WriteWord:	.proc
.debug
	.dw '.stabn 0x44,0,193,',0,0
	.dd LM66-_nRF2401_WriteWord
	.dw 0x0d,0x0a
.code
LM66:
	// total=2, vars=2
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=2
	bp=sp+1

	R1=BP+5
	[bp+1]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,194,',0,0
	.dd LM67-_nRF2401_WriteWord
	.dw 0x0d,0x0a
.code
LM67:
LBB5:
.debug
	.dw '.stabn 0x44,0,195,',0,0
	.dd LM68-_nRF2401_WriteWord
	.dw 0x0d,0x0a
.code
LM68:
	R1=0	// QImode move
	[BP]=R1	// QImode move
L31:
	R1=[BP]	// QImode move
	CMP R1,15	// QImode compare
	NSJNA L34	//QImode LEU
	pc=L32	// Indirect jump
L34:
.debug
	.dw '.stabn 0x44,0,197,',0,0
	.dd LM69-_nRF2401_WriteWord
	.dw 0x0d,0x0a
.code
LM69:
	R1=[28678]	// QImode move
	R2=R1&(-17)
	[28678]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,198,',0,0
	.dd LM70-_nRF2401_WriteWord
	.dw 0x0d,0x0a
.code
LM70:
	R2=[bp+1]	// QImode move
	R2=[R2]	// QImode move
	R1=R2&(-32768)
	CMP R1,0	// QImode test
	NSJZ L35	//QImode EQ
.debug
	.dw '.stabn 0x44,0,199,',0,0
	.dd LM71-_nRF2401_WriteWord
	.dw 0x0d,0x0a
.code
LM71:
	R1=[28678]	// QImode move
	R2=R1|32
	[28678]=R2	// QImode move
	pc=L36	// Indirect jump
L35:
.debug
	.dw '.stabn 0x44,0,201,',0,0
	.dd LM72-_nRF2401_WriteWord
	.dw 0x0d,0x0a
.code
LM72:
	R1=[28678]	// QImode move
	R2=R1&(-33)
	[28678]=R2	// QImode move
L36:
.debug
	.dw '.stabn 0x44,0,202,',0,0
	.dd LM73-_nRF2401_WriteWord
	.dw 0x0d,0x0a
.code
LM73:
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	call _Delay_Us	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,203,',0,0
	.dd LM74-_nRF2401_WriteWord
	.dw 0x0d,0x0a
.code
LM74:
	R1=[28678]	// QImode move
	R2=R1|16
	[28678]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,204,',0,0
	.dd LM75-_nRF2401_WriteWord
	.dw 0x0d,0x0a
.code
LM75:
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	call _Delay_Us	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,205,',0,0
	.dd LM76-_nRF2401_WriteWord
	.dw 0x0d,0x0a
.code
LM76:
	R1=[28678]	// QImode move
	R2=R1&(-17)
	[28678]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,206,',0,0
	.dd LM77-_nRF2401_WriteWord
	.dw 0x0d,0x0a
.code
LM77:
	R3=[bp+1]	// QImode move
	R1=[R3]	// QImode move
	R2=R1 lsl 1
	R1=[bp+1]	// QImode move
	[R1]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,195,',0,0
	.dd LM78-_nRF2401_WriteWord
	.dw 0x0d,0x0a
.code
LM78:
L33:
	R1=[BP]	// QImode move
	R2=R1+1
	[BP]=R2	// QImode move
	pc=L31	// Indirect jump
L32:
.debug
	.dw '.stabn 0x44,0,208,',0,0
	.dd LM79-_nRF2401_WriteWord
	.dw 0x0d,0x0a
.code
LM79:
LBE5:
.debug
	.dw '.stabn 0x44,0,208,',0,0
	.dd LM80-_nRF2401_WriteWord
	.dw 0x0d,0x0a
.code
LM80:
L30:

	sp+=2
	pop bp from [sp]
	retf
	.endp	// end of nRF2401_WriteWord

.debug
	.dw '.stabs "uiData:p4",160,0,0,5',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB5-_nRF2401_WriteWord
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "i:4",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE5-_nRF2401_WriteWord
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME8-_nRF2401_WriteWord
	.dw 0x0d,0x0a
.code
LME8:
.code
.debug
	.dw '.stabs "nRF2401_SendByte:F19",36,0,0,',0,0,offset _nRF2401_SendByte,seg _nRF2401_SendByte,0x0d,0x0a
.CODE
.public _nRF2401_SendByte
_nRF2401_SendByte:	.proc
.debug
	.dw '.stabn 0x44,0,217,',0,0
	.dd LM81-_nRF2401_SendByte
	.dw 0x0d,0x0a
.code
LM81:
	// total=2, vars=2
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=2
	bp=sp+1

	R1=BP+5
	[bp+1]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,218,',0,0
	.dd LM82-_nRF2401_SendByte
	.dw 0x0d,0x0a
.code
LM82:
LBB6:
.debug
	.dw '.stabn 0x44,0,221,',0,0
	.dd LM83-_nRF2401_SendByte
	.dw 0x0d,0x0a
.code
LM83:
	R1=[28678]	// QImode move
	R2=R1|2
	[28678]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,222,',0,0
	.dd LM84-_nRF2401_SendByte
	.dw 0x0d,0x0a
.code
LM84:
	R1=10	// QImode move
	[SP--]=R1	// QImode move
	call _Delay_Us	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,223,',0,0
	.dd LM85-_nRF2401_SendByte
	.dw 0x0d,0x0a
.code
LM85:
	R1=0	// QImode move
	[BP]=R1	// QImode move
L40:
	R1=[BP]	// QImode move
	CMP R1,[_AddrByteCnt]	// QImode compare
	NSJB L43	//QImode LTU
	pc=L41	// Indirect jump
L43:
.debug
	.dw '.stabn 0x44,0,225,',0,0
	.dd LM86-_nRF2401_SendByte
	.dw 0x0d,0x0a
.code
LM86:
	R1=_AddrBuffer	// QImode move
	R2=[BP]	// QImode move
	R1 = R1 + R2	//addqi3
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	[SP--]=R2	// QImode move
	call _nRF2401_WriteByte	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,223,',0,0
	.dd LM87-_nRF2401_SendByte
	.dw 0x0d,0x0a
.code
LM87:
L42:
	R1=[BP]	// QImode move
	R2=R1+1
	[BP]=R2	// QImode move
	pc=L40	// Indirect jump
L41:
.debug
	.dw '.stabn 0x44,0,227,',0,0
	.dd LM88-_nRF2401_SendByte
	.dw 0x0d,0x0a
.code
LM88:
	R2=[bp+1]	// QImode move
	R1=[R2]	// QImode move
	[SP--]=R1	// QImode move
	call _nRF2401_WriteByte	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,228,',0,0
	.dd LM89-_nRF2401_SendByte
	.dw 0x0d,0x0a
.code
LM89:
	R1=[28678]	// QImode move
	R2=R1&(-3)
	[28678]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,229,',0,0
	.dd LM90-_nRF2401_SendByte
	.dw 0x0d,0x0a
.code
LM90:
	R1=[28678]	// QImode move
	R2=R1&(-33)
	[28678]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,230,',0,0
	.dd LM91-_nRF2401_SendByte
	.dw 0x0d,0x0a
.code
LM91:
	R1=200	// QImode move
	[SP--]=R1	// QImode move
	call _Delay_Us	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,231,',0,0
	.dd LM92-_nRF2401_SendByte
	.dw 0x0d,0x0a
.code
LM92:
LBE6:
.debug
	.dw '.stabn 0x44,0,231,',0,0
	.dd LM93-_nRF2401_SendByte
	.dw 0x0d,0x0a
.code
LM93:
L39:

	sp+=2
	pop bp from [sp]
	retf
	.endp	// end of nRF2401_SendByte

.debug
	.dw '.stabs "TxData:p4",160,0,0,5',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB6-_nRF2401_SendByte
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "i:4",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE6-_nRF2401_SendByte
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME9-_nRF2401_SendByte
	.dw 0x0d,0x0a
.code
LME9:
.code
.debug
	.dw '.stabs "nRF2401_SendWord:F19",36,0,0,',0,0,offset _nRF2401_SendWord,seg _nRF2401_SendWord,0x0d,0x0a
.CODE
.public _nRF2401_SendWord
_nRF2401_SendWord:	.proc
.debug
	.dw '.stabn 0x44,0,240,',0,0
	.dd LM94-_nRF2401_SendWord
	.dw 0x0d,0x0a
.code
LM94:
	// total=2, vars=2
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=2
	bp=sp+1

	R1=BP+5
	[bp+1]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,241,',0,0
	.dd LM95-_nRF2401_SendWord
	.dw 0x0d,0x0a
.code
LM95:
LBB7:
.debug
	.dw '.stabn 0x44,0,244,',0,0
	.dd LM96-_nRF2401_SendWord
	.dw 0x0d,0x0a
.code
LM96:
	R1=[28678]	// QImode move
	R2=R1|2
	[28678]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,245,',0,0
	.dd LM97-_nRF2401_SendWord
	.dw 0x0d,0x0a
.code
LM97:
	R1=10	// QImode move
	[SP--]=R1	// QImode move
	call _Delay_Us	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,246,',0,0
	.dd LM98-_nRF2401_SendWord
	.dw 0x0d,0x0a
.code
LM98:
	R1=0	// QImode move
	[BP]=R1	// QImode move
L46:
	R1=[BP]	// QImode move
	CMP R1,[_AddrByteCnt]	// QImode compare
	NSJB L49	//QImode LTU
	pc=L47	// Indirect jump
L49:
.debug
	.dw '.stabn 0x44,0,248,',0,0
	.dd LM99-_nRF2401_SendWord
	.dw 0x0d,0x0a
.code
LM99:
	R1=_AddrBuffer	// QImode move
	R2=[BP]	// QImode move
	R1 = R1 + R2	//addqi3
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	[SP--]=R2	// QImode move
	call _nRF2401_WriteByte	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,246,',0,0
	.dd LM100-_nRF2401_SendWord
	.dw 0x0d,0x0a
.code
LM100:
L48:
	R1=[BP]	// QImode move
	R2=R1+1
	[BP]=R2	// QImode move
	pc=L46	// Indirect jump
L47:
.debug
	.dw '.stabn 0x44,0,250,',0,0
	.dd LM101-_nRF2401_SendWord
	.dw 0x0d,0x0a
.code
LM101:
	R2=[bp+1]	// QImode move
	R1=[R2]	// QImode move
	[SP--]=R1	// QImode move
	call _nRF2401_WriteWord	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,251,',0,0
	.dd LM102-_nRF2401_SendWord
	.dw 0x0d,0x0a
.code
LM102:
	R1=[28678]	// QImode move
	R2=R1&(-3)
	[28678]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,252,',0,0
	.dd LM103-_nRF2401_SendWord
	.dw 0x0d,0x0a
.code
LM103:
	R1=[28678]	// QImode move
	R2=R1&(-33)
	[28678]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,253,',0,0
	.dd LM104-_nRF2401_SendWord
	.dw 0x0d,0x0a
.code
LM104:
	R1=200	// QImode move
	[SP--]=R1	// QImode move
	call _Delay_Us	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,254,',0,0
	.dd LM105-_nRF2401_SendWord
	.dw 0x0d,0x0a
.code
LM105:
LBE7:
.debug
	.dw '.stabn 0x44,0,254,',0,0
	.dd LM106-_nRF2401_SendWord
	.dw 0x0d,0x0a
.code
LM106:
L45:

	sp+=2
	pop bp from [sp]
	retf
	.endp	// end of nRF2401_SendWord

.debug
	.dw '.stabs "TxData:p4",160,0,0,5',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB7-_nRF2401_SendWord
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "i:4",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE7-_nRF2401_SendWord
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME10-_nRF2401_SendWord
	.dw 0x0d,0x0a
.code
LME10:
.code
.debug
	.dw '.stabs "nRF2401_SendBuffer_Byte:F19",36,0,0,',0,0,offset _nRF2401_SendBuffer_Byte,seg _nRF2401_SendBuffer_Byte,0x0d,0x0a
.CODE
.public _nRF2401_SendBuffer_Byte
_nRF2401_SendBuffer_Byte:	.proc
.debug
	.dw '.stabn 0x44,0,264,',0,0
	.dd LM107-_nRF2401_SendBuffer_Byte
	.dw 0x0d,0x0a
.code
LM107:
	// total=2, vars=2
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=2
	bp=sp+1

	R1=BP+5
	[bp+1]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,265,',0,0
	.dd LM108-_nRF2401_SendBuffer_Byte
	.dw 0x0d,0x0a
.code
LM108:
LBB8:
.debug
	.dw '.stabn 0x44,0,268,',0,0
	.dd LM109-_nRF2401_SendBuffer_Byte
	.dw 0x0d,0x0a
.code
LM109:
	R1=[28678]	// QImode move
	R2=R1|2
	[28678]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,269,',0,0
	.dd LM110-_nRF2401_SendBuffer_Byte
	.dw 0x0d,0x0a
.code
LM110:
	R1=10	// QImode move
	[SP--]=R1	// QImode move
	call _Delay_Us	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,270,',0,0
	.dd LM111-_nRF2401_SendBuffer_Byte
	.dw 0x0d,0x0a
.code
LM111:
	R1=0	// QImode move
	[BP]=R1	// QImode move
L52:
	R1=[BP]	// QImode move
	CMP R1,[_AddrByteCnt]	// QImode compare
	NSJB L55	//QImode LTU
	pc=L53	// Indirect jump
L55:
.debug
	.dw '.stabn 0x44,0,272,',0,0
	.dd LM112-_nRF2401_SendBuffer_Byte
	.dw 0x0d,0x0a
.code
LM112:
	R1=_AddrBuffer	// QImode move
	R2=[BP]	// QImode move
	R1 = R1 + R2	//addqi3
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	[SP--]=R2	// QImode move
	call _nRF2401_WriteByte	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,270,',0,0
	.dd LM113-_nRF2401_SendBuffer_Byte
	.dw 0x0d,0x0a
.code
LM113:
L54:
	R1=[BP]	// QImode move
	R2=R1+1
	[BP]=R2	// QImode move
	pc=L52	// Indirect jump
L53:
.debug
	.dw '.stabn 0x44,0,274,',0,0
	.dd LM114-_nRF2401_SendBuffer_Byte
	.dw 0x0d,0x0a
.code
LM114:
	R1=0	// QImode move
	[BP]=R1	// QImode move
L56:
	R1=[bp+1]	// QImode move
	R1=[bp+1]	// QImode move
	R2=R1+1
	R1=[BP]	// QImode move
	R3=R2	// QImode move
	CMP R1,[R3]	// QImode compare
	NSJB L59	//QImode LTU
	pc=L57	// Indirect jump
L59:
.debug
	.dw '.stabn 0x44,0,276,',0,0
	.dd LM115-_nRF2401_SendBuffer_Byte
	.dw 0x0d,0x0a
.code
LM115:
	R1=[bp+1]	// QImode move
	R2=[R1]	// QImode move
	R1=R2	// QImode move
	R1 = R1 + [BP]	//addqi3
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	[SP--]=R2	// QImode move
	call _nRF2401_WriteByte	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,274,',0,0
	.dd LM116-_nRF2401_SendBuffer_Byte
	.dw 0x0d,0x0a
.code
LM116:
L58:
	R1=[BP]	// QImode move
	R2=R1+1
	[BP]=R2	// QImode move
	pc=L56	// Indirect jump
L57:
.debug
	.dw '.stabn 0x44,0,278,',0,0
	.dd LM117-_nRF2401_SendBuffer_Byte
	.dw 0x0d,0x0a
.code
LM117:
	R1=[28678]	// QImode move
	R2=R1&(-3)
	[28678]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,279,',0,0
	.dd LM118-_nRF2401_SendBuffer_Byte
	.dw 0x0d,0x0a
.code
LM118:
	R1=[28678]	// QImode move
	R2=R1&(-33)
	[28678]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,280,',0,0
	.dd LM119-_nRF2401_SendBuffer_Byte
	.dw 0x0d,0x0a
.code
LM119:
	R1=200	// QImode move
	[SP--]=R1	// QImode move
	call _Delay_Us	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,281,',0,0
	.dd LM120-_nRF2401_SendBuffer_Byte
	.dw 0x0d,0x0a
.code
LM120:
LBE8:
.debug
	.dw '.stabn 0x44,0,281,',0,0
	.dd LM121-_nRF2401_SendBuffer_Byte
	.dw 0x0d,0x0a
.code
LM121:
L51:

	sp+=2
	pop bp from [sp]
	retf
	.endp	// end of nRF2401_SendBuffer_Byte

.debug
	.dw '.stabs "TxData:p22",160,0,0,5',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "DataByte:p4",160,0,0,6',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB8-_nRF2401_SendBuffer_Byte
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "i:4",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE8-_nRF2401_SendBuffer_Byte
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME11-_nRF2401_SendBuffer_Byte
	.dw 0x0d,0x0a
.code
LME11:
.code
.debug
	.dw '.stabs "nRF2401_SendBuffer_Word:F19",36,0,0,',0,0,offset _nRF2401_SendBuffer_Word,seg _nRF2401_SendBuffer_Word,0x0d,0x0a
.CODE
.public _nRF2401_SendBuffer_Word
_nRF2401_SendBuffer_Word:	.proc
.debug
	.dw '.stabn 0x44,0,291,',0,0
	.dd LM122-_nRF2401_SendBuffer_Word
	.dw 0x0d,0x0a
.code
LM122:
	// total=2, vars=2
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=2
	bp=sp+1

	R1=BP+5
	[bp+1]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,292,',0,0
	.dd LM123-_nRF2401_SendBuffer_Word
	.dw 0x0d,0x0a
.code
LM123:
LBB9:
.debug
	.dw '.stabn 0x44,0,295,',0,0
	.dd LM124-_nRF2401_SendBuffer_Word
	.dw 0x0d,0x0a
.code
LM124:
	R1=[28678]	// QImode move
	R2=R1|2
	[28678]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,296,',0,0
	.dd LM125-_nRF2401_SendBuffer_Word
	.dw 0x0d,0x0a
.code
LM125:
	R1=10	// QImode move
	[SP--]=R1	// QImode move
	call _Delay_Us	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,297,',0,0
	.dd LM126-_nRF2401_SendBuffer_Word
	.dw 0x0d,0x0a
.code
LM126:
	R1=0	// QImode move
	[BP]=R1	// QImode move
L63:
	R1=[BP]	// QImode move
	CMP R1,[_AddrByteCnt]	// QImode compare
	NSJB L66	//QImode LTU
	pc=L64	// Indirect jump
L66:
.debug
	.dw '.stabn 0x44,0,299,',0,0
	.dd LM127-_nRF2401_SendBuffer_Word
	.dw 0x0d,0x0a
.code
LM127:
	R1=_AddrBuffer	// QImode move
	R2=[BP]	// QImode move
	R1 = R1 + R2	//addqi3
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	[SP--]=R2	// QImode move
	call _nRF2401_WriteByte	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,297,',0,0
	.dd LM128-_nRF2401_SendBuffer_Word
	.dw 0x0d,0x0a
.code
LM128:
L65:
	R1=[BP]	// QImode move
	R2=R1+1
	[BP]=R2	// QImode move
	pc=L63	// Indirect jump
L64:
.debug
	.dw '.stabn 0x44,0,301,',0,0
	.dd LM129-_nRF2401_SendBuffer_Word
	.dw 0x0d,0x0a
.code
LM129:
	R1=0	// QImode move
	[BP]=R1	// QImode move
L67:
	R1=[bp+1]	// QImode move
	R1=[bp+1]	// QImode move
	R2=R1+1
	R1=[BP]	// QImode move
	R3=R2	// QImode move
	CMP R1,[R3]	// QImode compare
	NSJB L70	//QImode LTU
	pc=L68	// Indirect jump
L70:
.debug
	.dw '.stabn 0x44,0,303,',0,0
	.dd LM130-_nRF2401_SendBuffer_Word
	.dw 0x0d,0x0a
.code
LM130:
	R1=[bp+1]	// QImode move
	R2=[R1]	// QImode move
	R1=R2	// QImode move
	R1 = R1 + [BP]	//addqi3
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	[SP--]=R2	// QImode move
	call _nRF2401_WriteWord	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,301,',0,0
	.dd LM131-_nRF2401_SendBuffer_Word
	.dw 0x0d,0x0a
.code
LM131:
L69:
	R1=[BP]	// QImode move
	R2=R1+1
	[BP]=R2	// QImode move
	pc=L67	// Indirect jump
L68:
.debug
	.dw '.stabn 0x44,0,305,',0,0
	.dd LM132-_nRF2401_SendBuffer_Word
	.dw 0x0d,0x0a
.code
LM132:
	R1=[28678]	// QImode move
	R2=R1&(-3)
	[28678]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,306,',0,0
	.dd LM133-_nRF2401_SendBuffer_Word
	.dw 0x0d,0x0a
.code
LM133:
	R1=[28678]	// QImode move
	R2=R1&(-33)
	[28678]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,307,',0,0
	.dd LM134-_nRF2401_SendBuffer_Word
	.dw 0x0d,0x0a
.code
LM134:
	R1=200	// QImode move
	[SP--]=R1	// QImode move
	call _Delay_Us	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,308,',0,0
	.dd LM135-_nRF2401_SendBuffer_Word
	.dw 0x0d,0x0a
.code
LM135:
LBE9:
.debug
	.dw '.stabn 0x44,0,308,',0,0
	.dd LM136-_nRF2401_SendBuffer_Word
	.dw 0x0d,0x0a
.code
LM136:
L62:

	sp+=2
	pop bp from [sp]
	retf
	.endp	// end of nRF2401_SendBuffer_Word

.debug
	.dw '.stabs "TxData:p22",160,0,0,5',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "DataWord:p4",160,0,0,6',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB9-_nRF2401_SendBuffer_Word
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "i:4",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE9-_nRF2401_SendBuffer_Word
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME12-_nRF2401_SendBuffer_Word
	.dw 0x0d,0x0a
.code
LME12:
.code
.debug
	.dw '.stabs "nRF2401_RxStatus:F4",36,0,0,',0,0,offset _nRF2401_RxStatus,seg _nRF2401_RxStatus,0x0d,0x0a
.CODE
.public _nRF2401_RxStatus
_nRF2401_RxStatus:	.proc
.debug
	.dw '.stabn 0x44,0,318,',0,0
	.dd LM137-_nRF2401_RxStatus
	.dw 0x0d,0x0a
.code
LM137:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R2=BP+3
.debug
	.dw '.stabn 0x44,0,319,',0,0
	.dd LM138-_nRF2401_RxStatus
	.dw 0x0d,0x0a
.code
LM138:
	R3=[28677]	// QImode move
	R1=R3&8
	CMP R1,0	// QImode test
	NSJNZ L74	//QImode NE
.debug
	.dw '.stabn 0x44,0,320,',0,0
	.dd LM139-_nRF2401_RxStatus
	.dw 0x0d,0x0a
.code
LM139:
	R1=0	// QImode move
	pc=L73	// Indirect jump
	pc=L75	// Indirect jump
L74:
.debug
	.dw '.stabn 0x44,0,322,',0,0
	.dd LM140-_nRF2401_RxStatus
	.dw 0x0d,0x0a
.code
LM140:
	R1=1	// QImode move
	pc=L73	// Indirect jump
L75:
.debug
	.dw '.stabn 0x44,0,323,',0,0
	.dd LM141-_nRF2401_RxStatus
	.dw 0x0d,0x0a
.code
LM141:
.debug
	.dw '.stabn 0x44,0,323,',0,0
	.dd LM142-_nRF2401_RxStatus
	.dw 0x0d,0x0a
.code
LM142:
L73:

	pop bp from [sp]
	retf
	.endp	// end of nRF2401_RxStatus

.debug
	.dw '.stabf ',0,0
	.dd LME13-_nRF2401_RxStatus
	.dw 0x0d,0x0a
.code
LME13:
.code
.debug
	.dw '.stabs "nRF2401_ReceiveByte:F19",36,0,0,',0,0,offset _nRF2401_ReceiveByte,seg _nRF2401_ReceiveByte,0x0d,0x0a
.CODE
.public _nRF2401_ReceiveByte
_nRF2401_ReceiveByte:	.proc
.debug
	.dw '.stabn 0x44,0,332,',0,0
	.dd LM143-_nRF2401_ReceiveByte
	.dw 0x0d,0x0a
.code
LM143:
	// total=4, vars=4
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=4
	bp=sp+1

	R1=BP+7
	[bp+3]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,333,',0,0
	.dd LM144-_nRF2401_ReceiveByte
	.dw 0x0d,0x0a
.code
LM144:
LBB10:
	R1=0	// QImode move
	[BP]=R1	// QImode move
	R1=BP	// QImode move
	R2=BP+1
	R1=0	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,334,',0,0
	.dd LM145-_nRF2401_ReceiveByte
	.dw 0x0d,0x0a
.code
LM145:
	R1=BP	// QImode move
	R2=BP+2
	R1=0	// QImode move
	R4=R2	// QImode move
	[R4]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,336,',0,0
	.dd LM146-_nRF2401_ReceiveByte
	.dw 0x0d,0x0a
.code
LM146:
	R1=[28679]	// QImode move
	R2=R1&(-33)
	[28679]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,337,',0,0
	.dd LM147-_nRF2401_ReceiveByte
	.dw 0x0d,0x0a
.code
LM147:
L78:
	R2=[28677]	// QImode move
	R1=R2&8
	CMP R1,0	// QImode test
	NSJNZ L80	//QImode NE
	pc=L79	// Indirect jump
L80:
.debug
	.dw '.stabn 0x44,0,339,',0,0
	.dd LM148-_nRF2401_ReceiveByte
	.dw 0x0d,0x0a
.code
LM148:
	R2=BP	// QImode move
	R1=BP+2
	R2=BP	// QImode move
	R3=BP+2
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R3=R2 lsl 1
	R2=R1	// QImode move
	[R2]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,340,',0,0
	.dd LM149-_nRF2401_ReceiveByte
	.dw 0x0d,0x0a
.code
LM149:
	R1=[28678]	// QImode move
	R2=R1&(-17)
	[28678]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,341,',0,0
	.dd LM150-_nRF2401_ReceiveByte
	.dw 0x0d,0x0a
.code
LM150:
	R2=[28677]	// QImode move
	R1=R2&32
	CMP R1,0	// QImode test
	NSJZ L81	//QImode EQ
.debug
	.dw '.stabn 0x44,0,342,',0,0
	.dd LM151-_nRF2401_ReceiveByte
	.dw 0x0d,0x0a
.code
LM151:
	R2=BP	// QImode move
	R1=BP+2
	R2=BP	// QImode move
	R3=BP+2
	R4=R3	// QImode move
	R4=[R4]	// QImode move
	R2=R4|1
	R4=R1	// QImode move
	[R4]=R2	// QImode move
L81:
.debug
	.dw '.stabn 0x44,0,343,',0,0
	.dd LM152-_nRF2401_ReceiveByte
	.dw 0x0d,0x0a
.code
LM152:
	R1=[BP]	// QImode move
	R2=R1+1
	[BP]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,344,',0,0
	.dd LM153-_nRF2401_ReceiveByte
	.dw 0x0d,0x0a
.code
LM153:
	R1=[28678]	// QImode move
	R2=R1|16
	[28678]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,345,',0,0
	.dd LM154-_nRF2401_ReceiveByte
	.dw 0x0d,0x0a
.code
LM154:
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	call _Delay_Us	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,346,',0,0
	.dd LM155-_nRF2401_ReceiveByte
	.dw 0x0d,0x0a
.code
LM155:
	R1=[BP]	// QImode move
	CMP R1,7	// QImode compare
	NSJNA L82	//QImode LEU
.debug
	.dw '.stabn 0x44,0,348,',0,0
	.dd LM156-_nRF2401_ReceiveByte
	.dw 0x0d,0x0a
.code
LM156:
	R1=0	// QImode move
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,349,',0,0
	.dd LM157-_nRF2401_ReceiveByte
	.dw 0x0d,0x0a
.code
LM157:
	R2=[bp+3]	// QImode move
	R1=[R2]	// QImode move
	R2=BP	// QImode move
	R3=BP+1
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R1 = R1 + R2	//addqi3
	R2=BP	// QImode move
	R3=BP+2
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R3=R1	// QImode move
	[R3]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,350,',0,0
	.dd LM158-_nRF2401_ReceiveByte
	.dw 0x0d,0x0a
.code
LM158:
	R1=BP	// QImode move
	R2=BP+2
	R1=0	// QImode move
	R4=R2	// QImode move
	[R4]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,351,',0,0
	.dd LM159-_nRF2401_ReceiveByte
	.dw 0x0d,0x0a
.code
LM159:
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
L82:
.debug
	.dw '.stabn 0x44,0,353,',0,0
	.dd LM160-_nRF2401_ReceiveByte
	.dw 0x0d,0x0a
.code
LM160:
	R1=[28678]	// QImode move
	R2=R1&(-17)
	[28678]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,354,',0,0
	.dd LM161-_nRF2401_ReceiveByte
	.dw 0x0d,0x0a
.code
LM161:
	pc=L78	// Indirect jump
L79:
.debug
	.dw '.stabn 0x44,0,355,',0,0
	.dd LM162-_nRF2401_ReceiveByte
	.dw 0x0d,0x0a
.code
LM162:
	R1=[28679]	// QImode move
	R2=R1|32
	[28679]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,356,',0,0
	.dd LM163-_nRF2401_ReceiveByte
	.dw 0x0d,0x0a
.code
LM163:
LBE10:
.debug
	.dw '.stabn 0x44,0,356,',0,0
	.dd LM164-_nRF2401_ReceiveByte
	.dw 0x0d,0x0a
.code
LM164:
L77:

	sp+=4
	pop bp from [sp]
	retf
	.endp	// end of nRF2401_ReceiveByte

.debug
	.dw '.stabs "RxData:p22",160,0,0,7',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB10-_nRF2401_ReceiveByte
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "i:4",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "j:4",128,0,0,1',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "dat:4",128,0,0,2',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE10-_nRF2401_ReceiveByte
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME14-_nRF2401_ReceiveByte
	.dw 0x0d,0x0a
.code
LME14:
.code
.debug
	.dw '.stabs "nRF2401_ReceiveWord:F19",36,0,0,',0,0,offset _nRF2401_ReceiveWord,seg _nRF2401_ReceiveWord,0x0d,0x0a
.CODE
.public _nRF2401_ReceiveWord
_nRF2401_ReceiveWord:	.proc
.debug
	.dw '.stabn 0x44,0,365,',0,0
	.dd LM165-_nRF2401_ReceiveWord
	.dw 0x0d,0x0a
.code
LM165:
	// total=4, vars=4
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=4
	bp=sp+1

	R1=BP+7
	[bp+3]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,366,',0,0
	.dd LM166-_nRF2401_ReceiveWord
	.dw 0x0d,0x0a
.code
LM166:
LBB11:
	R1=0	// QImode move
	[BP]=R1	// QImode move
	R1=BP	// QImode move
	R2=BP+1
	R1=0	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,367,',0,0
	.dd LM167-_nRF2401_ReceiveWord
	.dw 0x0d,0x0a
.code
LM167:
	R1=BP	// QImode move
	R2=BP+2
	R1=0	// QImode move
	R4=R2	// QImode move
	[R4]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,369,',0,0
	.dd LM168-_nRF2401_ReceiveWord
	.dw 0x0d,0x0a
.code
LM168:
	R1=[28679]	// QImode move
	R2=R1&(-33)
	[28679]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,370,',0,0
	.dd LM169-_nRF2401_ReceiveWord
	.dw 0x0d,0x0a
.code
LM169:
L87:
	R2=[28677]	// QImode move
	R1=R2&8
	CMP R1,0	// QImode test
	NSJNZ L89	//QImode NE
	pc=L88	// Indirect jump
L89:
.debug
	.dw '.stabn 0x44,0,372,',0,0
	.dd LM170-_nRF2401_ReceiveWord
	.dw 0x0d,0x0a
.code
LM170:
	R2=BP	// QImode move
	R1=BP+2
	R2=BP	// QImode move
	R3=BP+2
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R3=R2 lsl 1
	R2=R1	// QImode move
	[R2]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,373,',0,0
	.dd LM171-_nRF2401_ReceiveWord
	.dw 0x0d,0x0a
.code
LM171:
	R1=[28678]	// QImode move
	R2=R1&(-17)
	[28678]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,374,',0,0
	.dd LM172-_nRF2401_ReceiveWord
	.dw 0x0d,0x0a
.code
LM172:
	R2=[28677]	// QImode move
	R1=R2&32
	CMP R1,0	// QImode test
	NSJZ L90	//QImode EQ
.debug
	.dw '.stabn 0x44,0,375,',0,0
	.dd LM173-_nRF2401_ReceiveWord
	.dw 0x0d,0x0a
.code
LM173:
	R2=BP	// QImode move
	R1=BP+2
	R2=BP	// QImode move
	R3=BP+2
	R4=R3	// QImode move
	R4=[R4]	// QImode move
	R2=R4|1
	R4=R1	// QImode move
	[R4]=R2	// QImode move
L90:
.debug
	.dw '.stabn 0x44,0,376,',0,0
	.dd LM174-_nRF2401_ReceiveWord
	.dw 0x0d,0x0a
.code
LM174:
	R1=[BP]	// QImode move
	R2=R1+1
	[BP]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,377,',0,0
	.dd LM175-_nRF2401_ReceiveWord
	.dw 0x0d,0x0a
.code
LM175:
	R1=[28678]	// QImode move
	R2=R1|16
	[28678]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,378,',0,0
	.dd LM176-_nRF2401_ReceiveWord
	.dw 0x0d,0x0a
.code
LM176:
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	call _Delay_Us	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,379,',0,0
	.dd LM177-_nRF2401_ReceiveWord
	.dw 0x0d,0x0a
.code
LM177:
	R1=[BP]	// QImode move
	CMP R1,15	// QImode compare
	NSJNA L91	//QImode LEU
.debug
	.dw '.stabn 0x44,0,381,',0,0
	.dd LM178-_nRF2401_ReceiveWord
	.dw 0x0d,0x0a
.code
LM178:
	R1=0	// QImode move
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,382,',0,0
	.dd LM179-_nRF2401_ReceiveWord
	.dw 0x0d,0x0a
.code
LM179:
	R2=[bp+3]	// QImode move
	R1=[R2]	// QImode move
	R2=BP	// QImode move
	R3=BP+1
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R1 = R1 + R2	//addqi3
	R2=BP	// QImode move
	R3=BP+2
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R3=R1	// QImode move
	[R3]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,383,',0,0
	.dd LM180-_nRF2401_ReceiveWord
	.dw 0x0d,0x0a
.code
LM180:
	R1=BP	// QImode move
	R2=BP+2
	R1=0	// QImode move
	R4=R2	// QImode move
	[R4]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,384,',0,0
	.dd LM181-_nRF2401_ReceiveWord
	.dw 0x0d,0x0a
.code
LM181:
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
L91:
.debug
	.dw '.stabn 0x44,0,386,',0,0
	.dd LM182-_nRF2401_ReceiveWord
	.dw 0x0d,0x0a
.code
LM182:
	R1=[28678]	// QImode move
	R2=R1&(-17)
	[28678]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,387,',0,0
	.dd LM183-_nRF2401_ReceiveWord
	.dw 0x0d,0x0a
.code
LM183:
	pc=L87	// Indirect jump
L88:
.debug
	.dw '.stabn 0x44,0,388,',0,0
	.dd LM184-_nRF2401_ReceiveWord
	.dw 0x0d,0x0a
.code
LM184:
	R1=[28679]	// QImode move
	R2=R1|32
	[28679]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,389,',0,0
	.dd LM185-_nRF2401_ReceiveWord
	.dw 0x0d,0x0a
.code
LM185:
LBE11:
.debug
	.dw '.stabn 0x44,0,389,',0,0
	.dd LM186-_nRF2401_ReceiveWord
	.dw 0x0d,0x0a
.code
LM186:
L86:

	sp+=4
	pop bp from [sp]
	retf
	.endp	// end of nRF2401_ReceiveWord

.debug
	.dw '.stabs "RxData:p22",160,0,0,7',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB11-_nRF2401_ReceiveWord
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "i:4",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "j:4",128,0,0,1',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "dat:4",128,0,0,2',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE11-_nRF2401_ReceiveWord
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME15-_nRF2401_ReceiveWord
	.dw 0x0d,0x0a
.code
LME15:
.code
.debug
	.dw '.stabs "Delay_Us:F19",36,0,0,',0,0,offset _Delay_Us,seg _Delay_Us,0x0d,0x0a
.CODE
.public _Delay_Us
_Delay_Us:	.proc
.debug
	.dw '.stabn 0x44,0,398,',0,0
	.dd LM187-_Delay_Us
	.dw 0x0d,0x0a
.code
LM187:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R1=BP+4
.debug
	.dw '.stabn 0x44,0,399,',0,0
	.dd LM188-_Delay_Us
	.dw 0x0d,0x0a
.code
LM188:
LBB12:
.debug
	.dw '.stabn 0x44,0,400,',0,0
	.dd LM189-_Delay_Us
	.dw 0x0d,0x0a
.code
LM189:
	R2=152	// QImode move
	[28691]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,401,',0,0
	.dd LM190-_Delay_Us
	.dw 0x0d,0x0a
.code
LM190:
	R2=0	// QImode move
	[BP]=R2	// QImode move
L96:
	R2=[BP]	// QImode move
	R3=R1	// QImode move
	CMP R2,[R3]	// QImode compare
	NSJB L99	//QImode LTU
	pc=L97	// Indirect jump
L99:
.debug
	.dw '.stabn 0x44,0,403,',0,0
	.dd LM191-_Delay_Us
	.dw 0x0d,0x0a
.code
LM191:
	R2=1	// QImode move
	[28690]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,401,',0,0
	.dd LM192-_Delay_Us
	.dw 0x0d,0x0a
.code
LM192:
L98:
	R2=[BP]	// QImode move
	R3=R2+1
	[BP]=R3	// QImode move
	pc=L96	// Indirect jump
L97:
.debug
	.dw '.stabn 0x44,0,405,',0,0
	.dd LM193-_Delay_Us
	.dw 0x0d,0x0a
.code
LM193:
LBE12:
.debug
	.dw '.stabn 0x44,0,405,',0,0
	.dd LM194-_Delay_Us
	.dw 0x0d,0x0a
.code
LM194:
L95:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of Delay_Us

.debug
	.dw '.stabs "TimeCnt:p4",160,0,0,4',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB12-_Delay_Us
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "i:1",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE12-_Delay_Us
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME16-_Delay_Us
	.dw 0x0d,0x0a
.code
LME16:
.iram
.public _AddrBuffer
_AddrBuffer:
	.dw 5 dup(0)
.iram
.public _AddrByteCnt
_AddrByteCnt:
	.dw 0
	.end

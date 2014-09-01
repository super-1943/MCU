// GCC for SUNPLUS u'nSP version 1.0.21-3
// Command: D:\PROGRA~1\Sunplus\UNSPID~1.0\cc1.exe C:\DOCUME~1\ADMINI~1\LOCALS~1\Temp\cce0aaaa.i -fkeep-inline-functions -quiet -dumpbase ADConv.c -mglobal-var-iram -gstabs -Wall -o .\Debug/ADConv.asm
	.external __sn_func_ptr_sec

// gcc2_compiled.:

.debug
	.dw '.stabs "C:/Documents and Settings/Administrator/×ÀÃæ/voice/voice/",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
.code
.debug
	.dw '.stabs "C:/Documents and Settings/Administrator/×/300Ã/346/voice/voice/ADConv.c",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
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
.debug
	.dw '.stabs "uiData:G5",32,0,0,',0,0,offset _uiData,seg _uiData,0x0d,0x0a
.CODE
.debug
	.dw '.stabs "i:G4",32,0,0,',0,0,offset _i,seg _i,0x0d,0x0a
.CODE
.debug
	.dw '.stabs "fVoltage:G12",32,0,0,',0,0,offset _fVoltage,seg _fVoltage,0x0d,0x0a
.CODE
.code
.debug
	.dw '.stabs "ADInit:F19",36,0,0,',0,0,offset _ADInit,seg _ADInit,0x0d,0x0a
.CODE
.public _ADInit
_ADInit:	.proc
.debug
	.dw '.stabn 0x44,0,8,',0,0
	.dd LM1-_ADInit
	.dw 0x0d,0x0a
.code
LM1:
	// total=0, vars=0
	// frame_pointer_needed: 1
	push bp to [sp]
	bp=sp+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,9,',0,0
	.dd LM2-_ADInit
	.dw 0x0d,0x0a
.code
LM2:
	R2=5	// QImode move
	[28715]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,10,',0,0
	.dd LM3-_ADInit
	.dw 0x0d,0x0a
.code
LM3:
	R2=1	// QImode move
	[28693]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,11,',0,0
	.dd LM4-_ADInit
	.dw 0x0d,0x0a
.code
LM4:
	R2=[28716]	// QImode move
	R3=R2
	R4=0
	//split [_uiData], R3
	[_uiData]=R3	// QImode move
	[_uiData+1]=R4	// QImode move
.debug
	.dw '.stabn 0x44,0,12,',0,0
	.dd LM5-_ADInit
	.dw 0x0d,0x0a
.code
LM5:
	R3=0	// HFmode immediate to register move
	R4=0
	[_fVoltage]=R3	// HFmode [Label]=RS
	[_fVoltage+1]=R4
.debug
	.dw '.stabn 0x44,0,13,',0,0
	.dd LM6-_ADInit
	.dw 0x0d,0x0a
.code
LM6:
	//split R3, 0
	R3=0	// QImode move
	R4=0	// QImode move
	//split [_uiData], R3
	[_uiData]=R3	// QImode move
	[_uiData+1]=R4	// QImode move
.debug
	.dw '.stabn 0x44,0,14,',0,0
	.dd LM7-_ADInit
	.dw 0x0d,0x0a
.code
LM7:
.debug
	.dw '.stabn 0x44,0,14,',0,0
	.dd LM8-_ADInit
	.dw 0x0d,0x0a
.code
LM8:
L2:

	pop bp from [sp]
	retf
	.endp	// end of ADInit

.debug
	.dw '.stabf ',0,0
	.dd LME1-_ADInit
	.dw 0x0d,0x0a
.code
LME1:
.code
.debug
	.dw '.stabs "AD:F4",36,0,0,',0,0,offset _AD,seg _AD,0x0d,0x0a
.CODE
.public _AD
_AD:	.proc
.debug
	.dw '.stabn 0x44,0,16,',0,0
	.dd LM9-_AD
	.dw 0x0d,0x0a
.code
LM9:
	// total=1, vars=1
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=1
	bp=sp+1

	R2=BP+4
.debug
	.dw '.stabn 0x44,0,17,',0,0
	.dd LM10-_AD
	.dw 0x0d,0x0a
.code
LM10:
LBB2:
.debug
	.dw '.stabn 0x44,0,18,',0,0
	.dd LM11-_AD
	.dw 0x0d,0x0a
.code
LM11:
L4:
	R3=[28715]	// QImode move
	R1=R3&(-32768)
	CMP R1,0	// QImode test
	NSJZ L6	//QImode EQ
	pc=L5	// Indirect jump
L6:
.debug
	.dw '.stabn 0x44,0,20,',0,0
	.dd LM12-_AD
	.dw 0x0d,0x0a
.code
LM12:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,21,',0,0
	.dd LM13-_AD
	.dw 0x0d,0x0a
.code
LM13:
	pc=L4	// Indirect jump
L5:
.debug
	.dw '.stabn 0x44,0,22,',0,0
	.dd LM14-_AD
	.dw 0x0d,0x0a
.code
LM14:
	R1=[28716]	// QImode move
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,23,',0,0
	.dd LM15-_AD
	.dw 0x0d,0x0a
.code
LM15:
	R1=[BP]	// QImode move
	R3=R1&(-64)
	R1=R3	// QImode move
	pc=L3	// Indirect jump
.debug
	.dw '.stabn 0x44,0,24,',0,0
	.dd LM16-_AD
	.dw 0x0d,0x0a
.code
LM16:
LBE2:
.debug
	.dw '.stabn 0x44,0,24,',0,0
	.dd LM17-_AD
	.dw 0x0d,0x0a
.code
LM17:
L3:

	sp+=1
	pop bp from [sp]
	retf
	.endp	// end of AD

.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB2-_AD
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "uiData:4",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE2-_AD
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME2-_AD
	.dw 0x0d,0x0a
.code
LME2:
.code
.debug
	.dw '.stabs "ADtoVoltage:F12",36,0,0,',0,0,offset _ADtoVoltage,seg _ADtoVoltage,0x0d,0x0a
.CODE
.public _ADtoVoltage
_ADtoVoltage:	.proc
.debug
	.dw '.stabn 0x44,0,26,',0,0
	.dd LM18-_ADtoVoltage
	.dw 0x0d,0x0a
.code
LM18:
	// total=12, vars=12
	// frame_pointer_needed: 1
	push bp to [sp]
	sp-=12
	bp=sp+1

	R1=BP+15
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,27,',0,0
	.dd LM19-_ADtoVoltage
	.dw 0x0d,0x0a
.code
LM19:
	call _ADInit	// call without return value
.debug
	.dw '.stabn 0x44,0,28,',0,0
	.dd LM20-_ADtoVoltage
	.dw 0x0d,0x0a
.code
LM20:
	R1=0	// QImode move
	[_i]=R1	// QImode move
L9:
	R1=[_i]	// QImode move
	CMP R1,7	// QImode compare
	NSJNA L12	//QImode LEU
	pc=L10	// Indirect jump
L12:
.debug
	.dw '.stabn 0x44,0,30,',0,0
	.dd LM21-_ADtoVoltage
	.dw 0x0d,0x0a
.code
LM21:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,31,',0,0
	.dd LM22-_ADtoVoltage
	.dw 0x0d,0x0a
.code
LM22:
	call _AD	// call with return value
	R3=R1
	R4=0
	//split [bp+10], R3
	[bp+10]=R3	// QImode move
	[bp+11]=R4	// QImode move
	//split R1, [_uiData]
	R1=[_uiData]	// QImode move
	R2=[_uiData+1]	// QImode move
	//split [bp+1], R1
	[bp+1]=R1	// QImode move
	[bp+2]=R2	// QImode move
	R3=[bp+1]	// QImode move
	[bp+3]=R3	// QImode move
	R4=[bp+10]	// QImode move
	R4 = R4 + [bp+3]	//addqi3
	[bp+3]=R4	// QImode move
	R1=[bp+3]	// QImode move
	R3=1	// QImode move
	[bp+4]=R3	// QImode move
	R4=[bp+3]	// QImode move
	R3=[bp+1]	// QImode move
	CMP R4,R3	// QImode compare
	NSJB L13	//QImode LTU
	R4=0	// QImode move
	[bp+4]=R4	// QImode move
L13:
	R3=[bp+2]	// QImode move
	[bp+5]=R3	// QImode move
	R4=[bp+11]	// QImode move
	R4 = R4 + [bp+5]	//addqi3
	[bp+5]=R4	// QImode move
	R2=[bp+5]	// QImode move
	R3=[bp+5]	// QImode move
	R3 = R3 + [bp+4]	//addqi3
	R2=R3	// QImode move
	//split [_uiData], R1
	[_uiData]=R1	// QImode move
	[_uiData+1]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,28,',0,0
	.dd LM23-_ADtoVoltage
	.dw 0x0d,0x0a
.code
LM23:
L11:
	R1=[_i]	// QImode move
	R2=1	// QImode move
	[_i]=R1+R2  //addqi3_Qrr
	pc=L9	// Indirect jump
L10:
.debug
	.dw '.stabn 0x44,0,33,',0,0
	.dd LM24-_ADtoVoltage
	.dw 0x0d,0x0a
.code
LM24:
	//split R1, [_uiData]
	R1=[_uiData]	// QImode move
	R2=[_uiData+1]	// QImode move
	R3=3	// QImode move
	[SP--]=R3	// QImode move
	push R1,R2 to [sp]	// pushhi
	call __rshu2	// call with return value
	SP = SP + 3	//SP
	//split [_uiData], R1
	[_uiData]=R1	// QImode move
	[_uiData+1]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,34,',0,0
	.dd LM25-_ADtoVoltage
	.dw 0x0d,0x0a
.code
LM25:
	//split R1, [_uiData]
	R1=[_uiData]	// QImode move
	R2=[_uiData+1]	// QImode move
	CMP R2, 0	// HImode 1st compare
	NSJL  L15	// HImode LT
	JNZ L19
	CMP R1,0
	NSJB L15
L19:
	//split R1, [_uiData]
	R1=[_uiData]	// QImode move
	R2=[_uiData+1]	// QImode move
	push R1,R2 to [sp]	// pushhi
	call __cvi2f2	// call with return value
	SP = SP + 2	//SP
	[bp+6]=R1	// HFmode [BP+#IM6]=RS
	[bp+7]=R2
	pc=L14	// Indirect jump
L15:
	//split R1, [_uiData]
	R1=[_uiData]	// QImode move
	R2=[_uiData+1]	// QImode move
	R3=R1&1	// HImode RD=RS&#IMM16
	R4=R2&0
	//split [bp+8], R3
	[bp+8]=R3	// QImode move
	[bp+9]=R4	// QImode move
	//split R1, [_uiData]
	R1=[_uiData]	// QImode move
	R2=[_uiData+1]	// QImode move
	R3=1	// QImode move
	[SP--]=R3	// QImode move
	push R1,R2 to [sp]	// pushhi
	call __rshu2	// call with return value
	SP = SP + 3	//SP
	//split R3, R1
	R3=R1	// QImode move
	R4=R2	// QImode move
	R1=[bp+8]	// QImode move
	R1|=R3
	R2=[bp+9]	// QImode move
	R2|=R4
	push R1,R2 to [sp]	// pushhi
	call __cvi2f2	// call with return value
	SP = SP + 2	//SP
	[bp+6]=R1	// HFmode [BP+#IM6]=RS
	[bp+7]=R2
	R1=[bp+6]	// HFmode RD=[BP+#IM6]
	R2=[bp+7]
	push R1,R2 to [sp]	// pushhf
	R3=[bp+6]	// HFmode RD=[BP+#IM6]
	R4=[bp+7]
	push R3,R4 to [sp]	// pushhf
	call __addf2	// call with return value
	SP = SP + 4	//SP
	[bp+6]=R1	// HFmode [BP+#IM6]=RS
	[bp+7]=R2
L14:
	R1=49152	// HFmode immediate to register move
	R2=18303
	push R1,R2 to [sp]	// pushhf
	R1=[bp+6]	// HFmode RD=[BP+#IM6]
	R2=[bp+7]
	push R1,R2 to [sp]	// pushhf
	call __divf2	// call with return value
	SP = SP + 4	//SP
	[_fVoltage]=R1	// HFmode [Label]=RS
	[_fVoltage+1]=R2
.debug
	.dw '.stabn 0x44,0,35,',0,0
	.dd LM26-_ADtoVoltage
	.dw 0x0d,0x0a
.code
LM26:
	R1=[_fVoltage]	// HFmode RD=[Label]
	R2=[_fVoltage+1]
	R3=0	// HFmode immediate to register move
	R4=16416
	push R3,R4 to [sp]	// pushhf
	push R1,R2 to [sp]	// pushhf
	call __mulf2	// call with return value
	SP = SP + 4	//SP
	[_fVoltage]=R1	// HFmode [Label]=RS
	[_fVoltage+1]=R2
.debug
	.dw '.stabn 0x44,0,36,',0,0
	.dd LM27-_ADtoVoltage
	.dw 0x0d,0x0a
.code
LM27:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,37,',0,0
	.dd LM28-_ADtoVoltage
	.dw 0x0d,0x0a
.code
LM28:
	R3=[_fVoltage]	// HFmode RD=[Label]
	R4=[_fVoltage+1]
	R1=R3	// HFmode register to register move _4
	R2=R4
	pc=L8	// Indirect jump
.debug
	.dw '.stabn 0x44,0,38,',0,0
	.dd LM29-_ADtoVoltage
	.dw 0x0d,0x0a
.code
LM29:
.debug
	.dw '.stabn 0x44,0,38,',0,0
	.dd LM30-_ADtoVoltage
	.dw 0x0d,0x0a
.code
LM30:
L8:

	sp+=12
	pop bp from [sp]
	retf
	.endp	// end of ADtoVoltage

.debug
	.dw '.stabf ',0,0
	.dd LME3-_ADtoVoltage
	.dw 0x0d,0x0a
.code
LME3:
.iram
.public _uiData
_uiData:
	.dw 2 dup(0)
.iram
.public _i
_i:
	.dw 0
.iram
.public _fVoltage
_fVoltage:
	.dw 2 dup(0)
.external __mulf2
.external __divf2
.external __addf2
.external __cvi2f2
.external __rshu2
	.end

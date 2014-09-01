//========================================================
//	文件名称：	SACM_A1600.asm
//	功能描述：	A1600语音播放用户接口程序
//				一般情况下仅需修改C_SYSTEMCLOCK和C_CLOCK_SET即可
//	维护记录：	2006-10-16	v1.0, by Qwerty
//========================================================

//=========================================================================
//	包含文件
//=========================================================================
.INCLUDE SPCE061A.inc

//=========================================================================
//	常量定义
//=========================================================================
.DEFINE C_20M						20480000
.DEFINE C_24M						24576000
.DEFINE C_32M						32768000
.DEFINE C_40M						40960000
.DEFINE C_49M						49152000

//***** 请自行修改C_SYSTEMCLOCK和C_CLOCK_SET ******************************
.DEFINE C_SYSTEM_CLOCK				C_49M
.DEFINE	C_CLOCK_SET					C_Fosc_49M	// value of [P_SystemClock], defined in spce061a.inc
//*************************************************************************

.DEFINE C_Timer_Setting_8K			65536 - (C_SYSTEM_CLOCK/2)/8000
.DEFINE C_Timer_Setting_16K			65536 - (C_SYSTEM_CLOCK/2)/16000

.DEFINE C_A1600_Timer_Setting_X1	C_Timer_Setting_8K
.DEFINE C_A1600_Timer_Setting_X2	C_Timer_Setting_16K

//=========================================================================
//	全局函数声明
//=========================================================================
.PUBLIC F_SACM_A1600_Init
.PUBLIC F_SACM_A1600_DAC_Timer_X1
.PUBLIC F_SACM_A1600_DAC_Timer_X2
.PUBLIC F_SACM_A1600_SendDAC1
.PUBLIC F_SACM_A1600_SendDAC2
.PUBLIC F_SACM_A1600_EndPlay
.PUBLIC F_SACM_A1600_RampUpDAC1
.PUBLIC F_SACM_A1600_RampUpDAC2
.PUBLIC F_SACM_A1600_RampDnDAC1
.PUBLIC F_SACM_A1600_RampDnDAC2


.CODE
//======================================================
// 函数名称：	SACM_A1600_Init
// C调用：		无
// 汇编调用：	F_SACM_A1600_Init
// 实现功能：   (仅被库函数调用)A1600初始化过程
// 入口参数：	无
// 出口参数：	无
// 破坏寄存器：	r1
//======================================================
F_SACM_A1600_Init:
	fir_mov off
	r1 = C_CLOCK_SET				// Setup system clock
	[P_SystemClock] = r1
	
	r1 = 0x00A0						// Latch DAC1 by TimerA; Latch DAC2 by TimerA
	[P_DAC_Ctrl] = r1

	r1 = [P_INT_Mask]
	r1 |= C_FIQ_TMA					// Enable Timer A FIQ
	[P_INT_Mask] = r1
	fiq on
	retf

//======================================================
// 函数名称：	SACM_A1600_DAC_Timer_X1
// C调用：		无
// 汇编调用：	F_SACM_A1600_DAC_Timer_X1
// 实现功能：   (仅被库函数调用)当DAC_FIRType选择0时执行的Timer初始化过程(初始化为8000Hz)
// 入口参数：	无
// 出口参数：	无
// 破坏寄存器：	无
//======================================================
F_SACM_A1600_DAC_Timer_X1:
	push r1 to [sp]
	r1 = 0x0030						// TimerA CKA=Fosc/2 CKB=1 Tout:off
	[P_TimerA_Ctrl] = r1
	r1= C_A1600_Timer_Setting_X1	// TimerA setting
	[P_TimerA_Data] = r1
	pop r1 from [sp]
	retf

//======================================================
// 函数名称：	SACM_A1600_DAC_Timer_X2
// C调用：		无
// 汇编调用：	F_SACM_A1600_DAC_Timer_X2
// 实现功能：   (仅被库函数调用)当DAC_FIRType选择1~3时执行的Timer初始化过程(初始化为16000Hz)
// 入口参数：	无
// 出口参数：	无
// 破坏寄存器：	无
//======================================================
F_SACM_A1600_DAC_Timer_X2:
	push r1 to [sp]
	r1 = 0x0030						// TimerA CKA=Fosc/2 CKB=1 Tout:off
	[P_TimerA_Ctrl] = r1
	r1= C_A1600_Timer_Setting_X2	// TimerA setting
	[P_TimerA_Data] = r1
	pop r1 from [sp]
	retf

//======================================================
// 函数名称：	SACM_A1600_SendDAC1
// C调用：		无
// 汇编调用：	F_SACM_A1600_SendDAC1
// 实现功能：   (仅被库函数调用)解码后的数字量由DAC1输出过程
// 入口参数：	r1 - 即将输出的数字量
// 出口参数：	无
// 破坏寄存器：	无
//======================================================
F_SACM_A1600_SendDAC1:
	push r1 to [sp]
	[P_DAC1] = r1
	pop r1 from [sp]
	retf

//======================================================
// 函数名称：	SACM_A1600_SendDAC2
// C调用：		无
// 汇编调用：	F_SACM_A1600_SendDAC2
// 实现功能：   (仅被库函数调用)解码后的数字量由DAC2输出过程
// 入口参数：	r1 - 即将输出的数字量
// 出口参数：	无
// 破坏寄存器：	无
//======================================================
F_SACM_A1600_SendDAC2:
	push r1 to [sp]
	[P_DAC2] = r1
	pop r1 from [sp]
	retf

//======================================================
// 函数名称：	SACM_A1600_EndPlay
// C调用：		无
// 汇编调用：	SACM_A1600_EndPlay
// 实现功能：   (仅被库函数调用)当一段语音播放完毕时执行的过程
// 入口参数：	无
// 出口参数：	无
// 破坏寄存器：	无
//======================================================
F_SACM_A1600_EndPlay:
	nop
	retf

//======================================================
// 函数名称：	SACM_A1600_RampUpDAC1
// C调用：		无
// 汇编调用：	F_SACM_A1600_RampUpDAC1
// 实现功能：   (仅被库函数调用)在一段语音播放开始前执行的渐入过程(DAC1)
// 入口参数：	无
// 出口参数：	无
// 破坏寄存器：	无
//======================================================
F_SACM_A1600_RampUpDAC1:
	push r1 to [sp]
	r1 = [P_DAC1]
	r1 &= 0xffc0
	cmp r1, 0x8000
	jb ?L_Loop2
	je ?L_Exit
?L_Loop1:
	call F_SACM_RampDelay
	r1 -= 0x0040
	[P_DAC1] = r1
	cmp r1, 0x8000
	jne ?L_Loop1
	jmp ?L_Exit
?L_Loop2:
	call F_SACM_RampDelay
	r1 += 0x0040
	[P_DAC1] = r1
	cmp r1, 0x8000
	jne ?L_Loop2
?L_Exit:
	pop r1 from [sp]
	retf

//======================================================
// 函数名称：	SACM_A1600_RampUpDAC2
// C调用：		无
// 汇编调用：	F_SACM_A1600_RampUpDAC2
// 实现功能：   (仅被库函数调用)在一段语音播放开始前执行的渐入过程(DAC2)
// 入口参数：	无
// 出口参数：	无
// 破坏寄存器：	无
//======================================================
F_SACM_A1600_RampUpDAC2:
	push r1 to [sp]
	r1 = [P_DAC2]
	r1 &= 0xffc0
	cmp r1, 0x8000
	jb ?L_Loop2
	je ?L_Exit
?L_Loop1:
	call F_SACM_RampDelay
	r1 -= 0x0040
	[P_DAC2] = r1
	cmp r1, 0x8000
	jne ?L_Loop1
	jmp ?L_Exit
?L_Loop2:
	call F_SACM_RampDelay
	r1 += 0x0040
	[P_DAC2] = r1
	cmp r1, 0x8000
	jne ?L_Loop2
?L_Exit:
	pop r1 from [sp]
	retf

//======================================================
// 函数名称：	SACM_A1600_RampDnDAC1
// C调用：		无
// 汇编调用：	F_SACM_A1600_RampDnDAC1
// 实现功能：   (仅被库函数调用)在一段语音播放结束后执行的渐出过程(DAC1)
// 入口参数：	无
// 出口参数：	无
// 破坏寄存器：	无
//======================================================
F_SACM_A1600_RampDnDAC1:
	push r1 to [sp]
	r1 = [P_DAC1]
	r1 &= 0xffc0
	jz ?L_Exit
?L_Loop:
	call F_SACM_RampDelay
	r1 -= 0x0040
	[P_DAC1] = r1
	jnz ?L_Loop
?L_Exit:
	pop r1 from [sp]
	retf

//======================================================
// 函数名称：	SACM_A1600_RampDnDAC2
// C调用：		无
// 汇编调用：	F_SACM_A1600_RampDnDAC2
// 实现功能：   (仅被库函数调用)在一段语音播放结束后执行的渐出过程(DAC2)
// 入口参数：	无
// 出口参数：	无
// 破坏寄存器：	无
//======================================================
F_SACM_A1600_RampDnDAC2:
	push r1 to [sp]
	r1 = [P_DAC2]
	r1 &= 0xffc0
	jz ?L_Exit
?L_Loop:
	call F_SACM_RampDelay
	r1 -= 0x0040
	[P_DAC2] = r1
	jnz ?L_Loop
?L_Exit:
	pop r1 from [sp]
	retf


//======================================================
// 函数名称：	SACM_RampDelay
// C调用：		无
// 汇编调用：	F_SACM_RampDelay
// 实现功能：   (仅被RampUp/RampDn函数调用)延时程序
// 入口参数：	无
// 出口参数：	无
// 破坏寄存器：	无
//======================================================
.DEFINE C_SACM_RAMP_DELAY   80
F_SACM_RampDelay:
	push r1 to [sp]
	r1 = C_SACM_RAMP_DELAY 			// Ramp Up/Dn delay per step
?L_Loop:
	r1 -= 0x0001
	jnz ?L_Loop
	pop r1 from [sp]
	retf

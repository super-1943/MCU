//========================================================
//	文件名称：	isr.asm
//	功能描述：	将解码队列的语音资源送到DAC进行播放
//	维护记录：	2005-09-12	v1.0
//========================================================

.INCLUDE s480.inc
.INCLUDE hardware.inc

.TEXT
.PUBLIC _FIQ
_FIQ:
	push r1,r5 to [sp]
	r1 = C_FIQ_TMA
	test r1,[P_INT_Ctrl]
	jnz L_FIQ_TimerA
	r1 = C_FIQ_TMB
	test r1,[P_INT_Ctrl]
	jnz L_FIQ_TimerB
L_FIQ_PWM:
	r1 = C_FIQ_PWM
	[P_INT_Clear] = r1
	pop r1,r5 from [sp]
	reti
L_FIQ_TimerA:
	[P_INT_Clear] = r1
	call F_FIQ_Service_SACM_S480
	pop r1,r5 from [sp]
	reti
L_FIQ_TimerB:
	[P_INT_Clear] = r1
	pop r1,r5 from [sp]
	reti
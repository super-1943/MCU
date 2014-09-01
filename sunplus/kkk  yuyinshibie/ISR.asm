//============================================================
// 文件名称：ISR.asm     
// 实现功能: 语音播放/识别中断服务
// 维护记录： 2003-9-9 V1.0
//============================================================
.include hardware.inc

.public	_FIQ;

.external _BSR_FIQ_Routine
.external F_FIQ_Service_SACM_S480

.text
_FIQ:
	push R1,R5 to [sp];			// 寄存器压栈保护
	R1 = C_FIQ_TMA;
	[P_INT_Clear] = R1;
	call _BSR_FIQ_Routine			//语音识别中断服务
	call F_FIQ_Service_SACM_S480;	//语音播放中断服务
	pop R1,R5 from [sp];
	reti;

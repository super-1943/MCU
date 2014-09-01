.PUBLIC _FIQ
//...............................................
.EXTERNAL _BSR_FIQ_Routine
.EXTERNAL __gIsStopRecog 				//变量值 = 0 辨识器忙
						 				//       = 1 辨识器停止
						 

.PUBLIC _BREAK,_IRQ0, _IRQ1, _IRQ2, _IRQ3, _IRQ4, _IRQ5, _IRQ6, _IRQ7
.EXTERNAL _PlayFlag
//..................................................
.INCLUDE s480.inc;
.INCLUDE A2000.inc;
.INCLUDE resource.inc
.INCLUDE hardware.inc

.TEXT
_FIQ:
	push r1,r4 to [sp]
	r1 = [P_INT_Ctrl]
	r1 &= 0x2000
	jz ?notTimerA						//当不为TIQ_TMA，则转
	r1 = [__gIsStopRecog]
	jnz ?BSR_NotBusy					//[__gIsStopRecog]为1则转至放音处理
	call _BSR_FIQ_Routine				//为0，调用辨识子程序
	jmp ?BSR_Busy						//返回中断
?BSR_NotBusy:							//放音处理
	r2 = [_PlayFlag]
	jnz ?Play2000						//[_PlayFlag]为1则是播放2000
	call F_FIQ_Service_SACM_S480;		//为0，播放480
	jmp ?BSR_Busy						//返回中断
?Play2000:								//2000播放子程序
	call F_FIQ_Service_SACM_A2000;
?BSR_Busy:								//返回中断
	r1 = 0x2000
	[P_INT_Clear] = r1
	pop	r1,r4 from [sp];
	reti;
?notTimerA:
	r1 = 0x8800;
    [P_INT_Clear] = r1;
	pop	r1,r4 from [sp];
	reti;

_BREAK: 
_IRQ0:
_IRQ1: 
_IRQ2: 
_IRQ3: 
_IRQ4: 
_IRQ5: 
_IRQ6: 
_IRQ7:
.END

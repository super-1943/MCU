.PUBLIC _FIQ
.EXTERNAL _BSR_FIQ_Routine
.EXTERNAL __gIsStopRecog                 //变量值 = 0 辨识器忙;= 1 辨识器停止
.EXTERNAL _PlayFlag
.INCLUDE s480.inc;
.INCLUDE A2000.inc;
.INCLUDE resource.inc
.INCLUDE hardware.inc
.TEXT

//============================================================================================
//函数: FIQ()
//语法：void FIQ(void)
//描述：FIQ中服务断函数
//参数：无
//返回：无
//===============================================================================================
_FIQ:
	PUSH R1,R4 TO [SP]
	R1 = [P_INT_Ctrl]
	R1 &= 0x2000
	JZ L_notTimerA						//当不为TIQ_TMA，则转
	R1 = [__gIsStopRecog]
	JNZ L_BSR_NotBusy					//[__gIsStopRecog]为1则转至放音处理
	CALL _BSR_FIQ_Routine				//为0，调用辨识子程序
	JMP L_BSR_Busy						//返回中断
L_BSR_NotBusy:							//放音处理
	R2 = [_PlayFlag]
	JNZ L_Play2000						//[_PlayFlag]为1则是播放2000
	CALL F_FIQ_Service_SACM_S480;		//为0，播放480
	JMP L_BSR_Busy						//返回中断
L_Play2000:								//2000播放子程序
	CALL F_FIQ_Service_SACM_A2000;
L_BSR_Busy:								//返回中断
	R1 = 0x2000
	[P_INT_Clear] = R1
	POP	R1,R4 FROM [SP];
	reti;
L_notTimerA:
	R1 = 0x8800;
    [P_INT_Clear] = R1;
	POP	R1,R4 FROM [SP];
	RETI;
.END

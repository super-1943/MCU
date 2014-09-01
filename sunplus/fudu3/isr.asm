.INCLUDE hardware.inc               
.INCLUDE dvr.inc 
//*********************************************************//
//函数：FIQ()
//语法：void  FIQ(void)
//描述：快速请求中断；
//		入口地址：_FIQ
//		功能：调用语音解码并播放API
//参数：无
//返回：无
//*********************************************************//
.TEXT
.PUBLIC _FIQ 
_FIQ:                  
		push r1,r5 to [sp]                
        call    F_FIQ_Service_SACM_DVR  // for playback
        r1 = C_FIQ_TMA
        [P_INT_Clear] = r1
        pop r1,r5 from [sp] 
        reti             

        

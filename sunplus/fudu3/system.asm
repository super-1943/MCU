.INCLUDE resource.inc;
.INCLUDE hardware.inc;
.INCLUDE key.inc;

//*********************************************************//
//函数:System_Initial()
//描述:键盘扫描初始化
//参数:无
//返回:无
//*********************************************************//
.CODE
.PUBLIC _System_Initial;
.PUBLIC	F_System_Initial;
_System_Initial: .PROC
F_System_Initial:

		call	F_User_Init_IO;				// 调用键盘扫描
		call	F_Key_Scan_Initial;			 
		retf;
	   .ENDP;
//*********I/O初始化为下拉输入*****************************//
//*********************************************************//
F_User_Init_IO:
		r1 = 0x0000;
        [P_IOA_Dir] = r1;                    //A口为输入口
        [P_IOA_Attrib] = r1;				 
        [P_IOA_Data] = r1;                   //下拉输入 
        r1 = 0x0000;                        
        retf; 

//*********************************************************//
//函数:System_ServiceLoop()
//描述:键盘去抖和键盘扫描
//参数:无
//返回:无
//*********************************************************//
.PUBLIC _System_ServiceLoop;
_System_ServiceLoop: .PROC                  

		call	F_Key_DebounceCnt_Down;		//键盘去抖
		call    F_Key_Scan_ServiceLoop;		//键盘扫描		
		r1=0x0001;                      	// 
		[P_Watchdog_Clear]=r1;       		//
        retf;
        .ENDP;
//*********************************************************//
//函数:Clear_WatchDog()
//描述:看门狗清0
//参数:无
//返回:无
//*********************************************************//
.PUBLIC _Clear_WatchDog;
_Clear_WatchDog: 	.PROC
		r1=0x0001;                      	
		[P_Watchdog_Clear]=r1;       		
		retf;
		.ENDP
        
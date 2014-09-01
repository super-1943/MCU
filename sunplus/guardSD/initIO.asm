.PUBLIC 	_InitIO
.PUBLIC 	_ShowRes
.PUBLIC 	_ClearWatchDog

.DEFINE 	Port_IOA_Attrib 		0x7003
.DEFINE 	Port_IOA_Dir 			0x7002
.DEFINE 	Port_IOA_Data 			0x7000

.DEFINE 	Port_IOB_Attrib 		0x7008
.DEFINE 	Port_IOB_Dir 			0x7007
.DEFINE 	Port_IOB_Data 			0x7005

.CODE

_ClearWatchDog: .PROC
 push r1 to [SP]
 r1 = 0x0001
 [0x7012] = r1
 pop r1 from [SP]
 retf
.ENDP

_ShowRes: .PROC
	push r1, r5 to [SP]
	r5 = SP + 5
	r4 = [r5+3]				
	[0x7005] = r4
	pop r1, r5 from [SP]
	retf
.ENDP

_InitIO: .PROC
	r1=0xffff
	[Port_IOB_Attrib] = r1		//B口设置为同向输出
	[Port_IOB_Dir] = r1			
	//r1 = 0
	[Port_IOB_Data] = r1        //B口置高电平
	r1=0xffff
	[Port_IOA_Attrib] = r1		//A口设置为同向输出
	[Port_IOA_Dir] = r1			
	r1 = 0xffff
	[Port_IOA_Data] = r1        //A口置高电平
	retf
.ENDP

.PUBLIC _LED_RED_ON
_LED_RED_ON: .PROC
    r1 = [Port_IOB_Data]
    r1 = 0xfffe;
    [Port_IOB_Data] = r1;
   retf
.ENDP

.PUBLIC _LED_RED_OFF
_LED_RED_OFF: .PROC
    r1 = [Port_IOB_Data]
    r1 = 0xffff;
    [Port_IOB_Data] = r1;
   retf   
.ENDP
.PUBLIC _LED_GRE_ON
_LED_GRE_ON: .PROC
    r1 = [Port_IOB_Data]
    r1 = 0xfffd;
    [Port_IOB_Data] = r1;
   retf
.ENDP

.PUBLIC _LED_GRE_OFF
_LED_GRE_OFF: .PROC
    r1 = [Port_IOB_Data]
    r1 = 0xffff;
    [Port_IOB_Data] = r1;
   retf   
.ENDP
.END
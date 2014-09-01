//*****************************************************************************/
// 描述： IRQ5中断有两个中断源：2Hz和4Hz,该程序利用2Hz中断来控制
// 		  发光二极管的亮灭，时间间隔为1s,设定B口低八位输出。
// 日期： 2003/07/09
// 版本:  1.8.0
//*****************************************************************************/

.define     P_IOA_DATA				0x7000;
.define 	P_IOA_DIR				0x7002;
.define 	P_IOA_ATTRI				0x7003;
.DEFINE		P_IOB_DATA          	0x7005;
.DEFINE		P_IOB_DIR           	0x7007;
.DEFINE		P_IOB_ATTRI	        	0x7008;
.DEFINE		P_INT_CTRL	        	0x7010;
.DEFINE 	P_INT_CTRL_NEW      	0x702D;
.DEFINE		P_INT_CLEAR	        	0x7011;
.DEFINE		P_Watchdog_Clear		0x7012;
.RAM
.VAR G_Time2
.CODE

//============================================================================= 
// 函数： main()
// 描述：主函数
//=============================================================================
.PUBLIC _main
_main:
	INT OFF
	R1 = 0xffff 				//设定IOB口为同相输出口；
	[P_IOB_ATTRI] = R1 
	[P_IOB_DIR] = R1 
	[P_IOB_DATA] = R1 
	[P_IOA_DIR]=r1;
	[P_IOA_ATTRI]=r1;
	[P_IOA_DATA]=r1;

	R1 = 0x0004			        //开中断IRQ5_2Hz
	[P_INT_CTRL] = R1 
	[P_INT_CTRL_NEW] = R1 
	R1 = 0
	[G_Time2] = R1 
	INT	irq 
L_loop:
	nop 
	R1 = 0x0001;
    [P_Watchdog_Clear] = R1    //清看门狗
	nop
	jmp L_loop 
		
.TEXT	
.PUBLIC _IRQ5
_IRQ5:	
	push R1,R5 to [sp]		   //压栈保护  					 
	R1 = 0x0004      
	[P_INT_CLEAR] = R1 
	R2 = [G_Time2] 
 	R2+ = 0x0001 
	[G_Time2] = R2   
    CMP R2,2				    //比较是否为1秒
    JBE L_LED2HZ_OFF		    //小于等于则LED灭
    R1 = 0xff00 				//大于则LED亮					 
	[P_IOB_DATA] = R1 
    CMP R2,3				    //比较是否为两秒
    JBE L_LED2Hz_RET		    //小于等于则LED继续亮    
    R2 = 0x0000 		    	//否则，TIME1单元清零，返回中断
	[G_Time2] = R2 
    JMP L_LED2Hz_RET
L_LED2HZ_OFF:
    R1 = 0xffff 			 
	[P_IOB_DATA] = R1 
L_LED2Hz_RET:  
    POP R1,R5 FROM [sp]
    RETI    
    
//*****************************************************************************/
//  main.asm 结束
//*****************************************************************************/	


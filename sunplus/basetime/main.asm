//*****************************************************************************/
// ������ IRQ5�ж��������ж�Դ��2Hz��4Hz,�ó�������2Hz�ж�������
// 		  ��������ܵ�����ʱ����Ϊ1s,�趨B�ڵͰ�λ�����
// ���ڣ� 2003/07/09
// �汾:  1.8.0
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
// ������ main()
// ������������
//=============================================================================
.PUBLIC _main
_main:
	INT OFF
	R1 = 0xffff 				//�趨IOB��Ϊͬ������ڣ�
	[P_IOB_ATTRI] = R1 
	[P_IOB_DIR] = R1 
	[P_IOB_DATA] = R1 
	[P_IOA_DIR]=r1;
	[P_IOA_ATTRI]=r1;
	[P_IOA_DATA]=r1;

	R1 = 0x0004			        //���ж�IRQ5_2Hz
	[P_INT_CTRL] = R1 
	[P_INT_CTRL_NEW] = R1 
	R1 = 0
	[G_Time2] = R1 
	INT	irq 
L_loop:
	nop 
	R1 = 0x0001;
    [P_Watchdog_Clear] = R1    //�忴�Ź�
	nop
	jmp L_loop 
		
.TEXT	
.PUBLIC _IRQ5
_IRQ5:	
	push R1,R5 to [sp]		   //ѹջ����  					 
	R1 = 0x0004      
	[P_INT_CLEAR] = R1 
	R2 = [G_Time2] 
 	R2+ = 0x0001 
	[G_Time2] = R2   
    CMP R2,2				    //�Ƚ��Ƿ�Ϊ1��
    JBE L_LED2HZ_OFF		    //С�ڵ�����LED��
    R1 = 0xff00 				//������LED��					 
	[P_IOB_DATA] = R1 
    CMP R2,3				    //�Ƚ��Ƿ�Ϊ����
    JBE L_LED2Hz_RET		    //С�ڵ�����LED������    
    R2 = 0x0000 		    	//����TIME1��Ԫ���㣬�����ж�
	[G_Time2] = R2 
    JMP L_LED2Hz_RET
L_LED2HZ_OFF:
    R1 = 0xffff 			 
	[P_IOB_DATA] = R1 
L_LED2Hz_RET:  
    POP R1,R5 FROM [sp]
    RETI    
    
//*****************************************************************************/
//  main.asm ����
//*****************************************************************************/	


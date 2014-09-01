//***********************************************************
//����: 1)ѡ��ͬ��ʱ��Դ,ͬһռ�ձ�8/16���۲�ʾ������Ƶ�ʵı仯
//      2)ѡ��ͬһʱ��Դ���ı�ռ�ձ�,�۲�ʾ�������Ƚ������� 
//����: 2003/07/08
//�汾��1.8.0
//*************************************************************
.define			timefosc_2		0x0230;	//clkAѡ��fosc/2Hz
.define			timefosc_256	0x0231;	//clkAѡ��fosc/256Hz
.define			timeclk_32768	0x0232;	//clkAѡ��32768Hz
.define			timeclk_8192	0x0233;	//clkAѡ��8192Hz
.define			timeclk_4096	0x0234;	//clkAѡ��4096Hz
.define			timeclk_2048	0x0205;	//clkBѡ��2048Hz
.define			timeclk_1024	0x020d;	//clkBѡ��1024Hz
.define			timeclk_256		0x0215; //clkBѡ��256Hz
.define			timeclk_4		0x0225; //clkBѡ��4Hz
.define			timeclk_2		0x0065;	//clkBѡ��2HzHz
 
//Ƶ��ѡ��fosc/2Hz;
//ʹ����Ҳ�����Լ����ò�ͬƵ���µ�ռ�ձȣ�
 
.define			timepwm_1		0x0070; 	//����ѡ��1/6
.define			timepwm_2		0x00b0;	    //����ѡ��2/6
.define			timepwm_3		0x00f0;		//����ѡ��3/6
.define			timepwm_4		0x0130;		//����ѡ��4/6 		
.define			timepwm_5		0x0170;		//����ѡ��5/6 		 
.define			timepwm_6		0x01b0;		//����ѡ��6/6 		
.define			timepwm_7		0x01f0;		//����ѡ��7/6 	
.define			timepwm_8		0x0230;		//����ѡ��8/6 		
.define			timepwm_9		0x0270;		//����ѡ��9/6        
.define			timepwm_10		0x02b0;		//����ѡ��10/6 		
.define			timepwm_11		0x02f0;		//����ѡ��11/6 		
.define			timepwm_12		0x0330;		//����ѡ��12/6 		
.define			timepwm_13		0x0370;		//����ѡ��13/6 		
.define			timepwm_14		0x03b0;		//����ѡ��14/6
 
.define			time_clk	timefosc_256;	//Ƶ��ѡ��
.define			time_pwm	timepwm_1;	 	//����ѡ��
 
.define		    P_TimerA_Data	  0x700A;
.define		    P_TimerA_Ctrl	  0x700B;
.define	     	P_IOB_DATA  	  0x7005;
.define	    	P_IOB_DIR   	  0x7007;
.define		    P_IOB_ATTRI		  0x7008;
.define	    	P_Feedback		  0x7009;
.define         p_watchdog_clear  0x7012;
.define 		p_IOA_Data		  0x7000;
.define			p_IOA_Attrib	  0x7003;
.define			p_IOA_Dir		  0x7002;
.code
.public _main;	
_main:
	r1=0xffff;
	[p_IOA_Dir]=r1;
	[p_IOA_Attrib]=r1;
	[p_IOA_Data]=r1;
	R1=0x0100; 			    	//IOB8����Ϊͬ������� 
    [P_IOB_DIR] = R1; 
	[P_IOB_ATTRI] = R1; 
	R1 = 0x0000; 
	[P_IOB_DATA ] = R1;
	R1 = 0x0000;
	
	[P_Feedback] = R1;          //����IOB8��ΪAPWMO�˿�
	R1 = 0xff9f; 		        //�趨TA_TIMEOUT/16=(time_clk/96)/16=8kHz
	[P_TimerA_Data] = R1; 
	R1 = time_clk; 
	[P_TimerA_Ctrl] = R1; 
L_loop:
    nop;
    R1 = 0x0001;
    [p_watchdog_clear] = R1;    //�忴�Ź�
    jmp L_loop;
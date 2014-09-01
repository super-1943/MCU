#ifndef	__HARDWARE_H__
#define	__HARDWARE_H__
//	write your header here

//========================================================================================
// Progarm: The file be included by modules
// Arranged by: Andy Hsu
// Date: 	2000/06/23: first version
//			2000/07/24: modified
//========================================================================================
//////////////////////////////////////////////////////////////////
// Define Area for I/O									
//////////////////////////////////////////////////////////////////
#define	Port_IOA_Data   		0x7000        //portA data
#define Port_IOA_Buffer         0x7001        //portA buffer
#define Port_IOA_Dir            0x7002        //portA direction
#define Port_IOA_Attrib         0x7003        //portA attribution
#define Port_IO_RL              0x7004        //portA last data latch
#define Port_IOB_Data           0x7005        //portB data
#define Port_IOB_Buffer         0x7006        //portB buffer
#define Port_IOB_Dir            0x7007        //portB direction
#define Port_IOB_Attrib         0x7008        //portB attribution

#define Port_Feed_Back          0x7009        //portB.4 portB.5 SFC
#define Port_TimerA_Data        0x700A        //timer A data
#define Port_TimerA_Ctrl        0x700B        //timer A control
#define Port_TimerB_Data        0x700C        //timer B data
#define Port_TimerB_Ctrl        0x700D        //timer B control
#define Port_TimeBaseSetup      0x700E        //time base configuration
#define Port_INT_Ctrl           0x7010        //interrupt control
#define Port_INT_Clear          0x7011        //Interrupt clear register
#define Port_Watchdog_Clear     0x7012        //clear watchdog ??
#define Port_SystemClock        0x7013        //system clock generator setup
#define Port_ADDA               0x7014        //10-bit DA(W) AD(R)
#define Port_DAC1               0x7014        //
#define Port_AD_Ctrl            0x7015        //AD/DA control
#define Port_AD_Status          0x7015        //AD status
#define Port_DAC2               0x7016        //DAC channel 2
#define Port_PWM                0x7016        //PWM output
#define Port_DA_Ctrl            0x7017        //DAC latch control
#define Port_LVD_Ctrl           0x7018        //Low voltage detect control


// Define for Port_INT_Ctrl 
#define C_IRQ6_TMB2             0x0001;        	// Timer B IRQ6
#define C_IRQ6_TMB1             0x0002;        	// Timer A IRQ6
#define C_IRQ5_2Hz              0x0004;        	// 2Hz IRQ5
#define C_IRQ5_4Hz              0x0008;        	// 4Hz IRQ5
#define C_IRQ4_1KHz             0x0010;        	// 1024Hz IRQ4
#define C_IRQ4_2KHz             0x0020;        	// 2048Hz IRQ4
#define C_IRQ4_4KHz             0x0040;        	// 4096Hz IRQ4
#define C_IRQ3_KEY              0x0080;        	// Key Change IRQ3
#define C_IRQ3_EXT1             0x0100;        	// Ext1 IRQ3
#define C_IRQ3_EXT2             0x0200;        	// Ext2 IRQ3
#define C_IRQ2_TMB              0x0400;        	// Timer B IRQ2
#define C_FIQ_TMB               0x0800;        	// Timer B FIQ
#define C_IRQ1_TMA              0x1000;        	// Timer A IRQ1
#define C_FIQ_TMA               0x2000;        	// Timer A FIQ
#define C_IRQ0_PWM              0x4000;        	// PWM IRQ0
#define C_FIQ_PWM               0x8000;        	// PWM FIQ

// Define for Port_TimerA_Ctrl, Port_TimerB_Ctrl                               
#define	C_Fosc_2				0x0000			// Timer A
#define	C_Fosc_256		    	0x0001			//
#define	C_32768Hz				0x0002			//
#define	C_8192Hz				0x0003			//
#define	C_4096Hz				0x0004			//
#define	C_A1					0x0005			//
#define C_A0					0x0006			//
#define C_Ext1					0x0007			//

#define	C_2048Hz				0x0000			//
#define	C_1024Hz				0x0008			//
#define	C_256Hz					0x0010			//
#define	C_TMB1Hz				0x0018			//
#define	C_4Hz					0x0020			//
#define	C_2Hz					0x0028			//
#define	C_B1					0x0030			//
#define	C_Ext2					0x0038			//

#define	C_Off					0x0000			//
#define C_D1					0x0040			//
#define C_D2					0x0080			//
#define C_D3					0x00C0			//
#define C_D4					0x0100			//
#define C_D5					0x0140			//
#define C_D6					0x0180			//
#define C_D7					0x01C0			//
#define C_D8					0x0200			//
#define C_D9					0x0240			//
#define C_D10					0x0280			//
#define C_D11					0x02C0			//
#define C_D12					0x0300			//
#define C_D13					0x0340			//
#define C_D14					0x0380			//
#define C_TA_Div_2				0x03C0			// Timer A

#define C_TB_Div_2				0x03C0			// Timer B

// Define for Port_SystemClock
#define C_Fosc					0x0000			// b3..b0
#define C_Fosc_Div_2			0x0001			//
#define C_Fosc_Div_4			0x0002			//
#define C_Fosc_Div_8			0x0003			// (default)
#define C_Fosc_Div_16			0x0004			//
#define C_Fosc_Div_32			0x0005			//
#define C_Fosc_Div_64			0x0006			//
#define C_Sleep					0x0007		 	//

#define	C_32K_Work				0x0000			// b4
#define C_32K_Off				0x0000			// 
#define C_StrongMode			0x0000			// b5
#define C_AutoMode				0x0000			//

// Define for Port_AD_Ctrl
#define	C_AD					0x0001			//
#define C_DA					0x0000			//
#define C_MIC					0x0000			//
#define C_LINE					0x0002			//

// Define for Port_DA_Ctrl
#define C_PushPull				0x0000			// b0, (default) 
#define C_DoubleEnd				0x0001			// b0
#define	C_DAC_Mode				0x0000			// b1, (default)
#define C_PWM_Mode				0x0002			// b1

#define	C_D1_Direct				0x0000			// DAC1 latch
#define C_D1_LatchA				0x0008			// 
#define C_D1_LatchB				0x0010			//
#define C_D1_LatchAB			0x0018			//

#define	C_D2_Direct				0x0000			// DAC2 latch
#define C_D2_LatchA				0x0020			// 
#define C_D2_LatchB				0x0040			//
#define C_D2_LatchAB			0x00C0			//

// Define for Port_LVD_Ctrl
#define C_LVD24V				0x0000			// LVD = 2.4V 
#define C_LVD28V				0x0001			// LVD = 2.8V
#define C_LVD32V				0x0002			// LVD = 3.2V
#define C_LVD36V				0x0003			// LVD = 3.6V

#endif

extern void STD_Init_IOA(unsigned int, unsigned int, unsigned int);
extern void STD_Init_IOB(unsigned int, unsigned int, unsigned int);
extern unsigned int STD_Import(unsigned int);
extern void STD_Export(unsigned int, unsigned int);

#define	Full	1
#define	Empty	2

#define DAC1	1
#define DAC2	2

#define		Ramp_UpDn_Off	0
#define 	Ramp_Up_On		1
#define		Ramp_Dn_On		2
#define		Ramp_UpDn_On	3	



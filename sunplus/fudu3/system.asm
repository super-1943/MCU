.INCLUDE resource.inc;
.INCLUDE hardware.inc;
.INCLUDE key.inc;

//*********************************************************//
//����:System_Initial()
//����:����ɨ���ʼ��
//����:��
//����:��
//*********************************************************//
.CODE
.PUBLIC _System_Initial;
.PUBLIC	F_System_Initial;
_System_Initial: .PROC
F_System_Initial:

		call	F_User_Init_IO;				// ���ü���ɨ��
		call	F_Key_Scan_Initial;			 
		retf;
	   .ENDP;
//*********I/O��ʼ��Ϊ��������*****************************//
//*********************************************************//
F_User_Init_IO:
		r1 = 0x0000;
        [P_IOA_Dir] = r1;                    //A��Ϊ�����
        [P_IOA_Attrib] = r1;				 
        [P_IOA_Data] = r1;                   //�������� 
        r1 = 0x0000;                        
        retf; 

//*********************************************************//
//����:System_ServiceLoop()
//����:����ȥ���ͼ���ɨ��
//����:��
//����:��
//*********************************************************//
.PUBLIC _System_ServiceLoop;
_System_ServiceLoop: .PROC                  

		call	F_Key_DebounceCnt_Down;		//����ȥ��
		call    F_Key_Scan_ServiceLoop;		//����ɨ��		
		r1=0x0001;                      	// 
		[P_Watchdog_Clear]=r1;       		//
        retf;
        .ENDP;
//*********************************************************//
//����:Clear_WatchDog()
//����:���Ź���0
//����:��
//����:��
//*********************************************************//
.PUBLIC _Clear_WatchDog;
_Clear_WatchDog: 	.PROC
		r1=0x0001;                      	
		[P_Watchdog_Clear]=r1;       		
		retf;
		.ENDP
        
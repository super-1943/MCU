.INCLUDE hardware.inc               
.INCLUDE dvr.inc 
//*********************************************************//
//������FIQ()
//�﷨��void  FIQ(void)
//���������������жϣ�
//		��ڵ�ַ��_FIQ
//		���ܣ������������벢����API
//��������
//���أ���
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

        

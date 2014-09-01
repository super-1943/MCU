.PUBLIC _FIQ
.EXTERNAL _BSR_FIQ_Routine
.EXTERNAL __gIsStopRecog                 //����ֵ = 0 ��ʶ��æ;= 1 ��ʶ��ֹͣ
.EXTERNAL _PlayFlag
.INCLUDE s480.inc;
.INCLUDE A2000.inc;
.INCLUDE resource.inc
.INCLUDE hardware.inc
.TEXT

//============================================================================================
//����: FIQ()
//�﷨��void FIQ(void)
//������FIQ�з���Ϻ���
//��������
//���أ���
//===============================================================================================
_FIQ:
	PUSH R1,R4 TO [SP]
	R1 = [P_INT_Ctrl]
	R1 &= 0x2000
	JZ L_notTimerA						//����ΪTIQ_TMA����ת
	R1 = [__gIsStopRecog]
	JNZ L_BSR_NotBusy					//[__gIsStopRecog]Ϊ1��ת����������
	CALL _BSR_FIQ_Routine				//Ϊ0�����ñ�ʶ�ӳ���
	JMP L_BSR_Busy						//�����ж�
L_BSR_NotBusy:							//��������
	R2 = [_PlayFlag]
	JNZ L_Play2000						//[_PlayFlag]Ϊ1���ǲ���2000
	CALL F_FIQ_Service_SACM_S480;		//Ϊ0������480
	JMP L_BSR_Busy						//�����ж�
L_Play2000:								//2000�����ӳ���
	CALL F_FIQ_Service_SACM_A2000;
L_BSR_Busy:								//�����ж�
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

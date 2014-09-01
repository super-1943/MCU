//============================================================
// �ļ����ƣ�ISR.asm     
// ʵ�ֹ���: ��������/ʶ���жϷ���
// ά����¼�� 2003-9-9 V1.0
//============================================================
.include hardware.inc

.public	_FIQ;

.external _BSR_FIQ_Routine
.external F_FIQ_Service_SACM_S480

.text
_FIQ:
	push R1,R5 to [sp];			// �Ĵ���ѹջ����
	R1 = C_FIQ_TMA;
	[P_INT_Clear] = R1;
	call _BSR_FIQ_Routine			//����ʶ���жϷ���
	call F_FIQ_Service_SACM_S480;	//���������жϷ���
	pop R1,R5 from [sp];
	reti;

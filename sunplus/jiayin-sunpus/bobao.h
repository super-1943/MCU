#ifndef	__BOBAO_h__
#define	__BOBAO_h__
//	write your header here
//========================================================
//	�﷨��ʽ��	void PlaySnd_Auto(unsigned int uiSndIndex,
//								unsigned int uiDAC_Channel)
//	ʵ�ֹ��ܣ�	ͨ���Զ���ʽ����������Դ
//	������		1.uiSndIndex��������Դ��� 
//				2.uiDAC_Channel����������ͨ��
//	����ֵ��	��
//========================================================

void PlaySnd_Auto(unsigned int uiSndIndex,unsigned int uiDAC_Channel)
{
	SACM_S480_Initial(1);						//��ʼ��Ϊ�Զ����ŷ�ʽ
	SACM_S480_Play(uiSndIndex,uiDAC_Channel,3);	//����
	while((SACM_S480_Status() & 0x0001) != 0)
	{											//�жϲ���״̬���绹�ڲ��������ѭ��
		SACM_S480_ServiceLoop();				//����ϵͳ�������
		*P_Watchdog_Clear = 0x0001;			
	}	
	SACM_S480_Stop();							//ֹͣ����
}
#endif

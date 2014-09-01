//----------------------------------------------------------------------------
//-- �ó������ض��˱�ʶ��һ��������
//--
//-- �ڳ���������ͨ����������ѵ����ʾ�ض���������ʶ�����е�һ�����Ϊ�������
//-- 
//-- �ڳ���һ��ʼΪѵ�����ƣ����������Ȼ����ʾѵ���������ѵ����Ͽ�ʼ��ʶ��ʶ��
//���������ƺ󣬷��������������Ӧ�𣬾����������£�
//****************ѵ��******************************************
//    ��ʾ��                          ��������
//--------------------------------------------------------
//"�����봥������"                    "����"
//"�������һ������"                    "��ǹ"
//"������ڶ�������"                    "���ڸ�ʲô��"
//"����˵һ��"��������ʾ��ÿ˵��һ����ִ����
//"û�������κ�����"����û�м�⵽����ʱ���ִ����
//"�����������Ʋ���ͬ"����������������Ʋ�ͬʱ���ִ����
//"�������������ͬ"������������������в���ʱ���ִ����
//"׼���������뿪ʼ��ʶ"�������������ȫ��ѵ���ɹ�ʱ������ʶ��
//*****************ʶ��*****************************************
//     ��������                           Ӧ��	
//---------------------------------------------------------
//"����"                                "��"/"����"
//"��ǹ"                                "ǹ��"
//"���ڸ�ʲô��"                        "����Ѳ��"/"������Ϣ"/"���ڵ���"

//ע�⣺��ÿ����ʾ��������2-3��������������ϴ�Ӧ�����2-3����ٷ�������

#include "bsrsd.h"

#define NAME_ID 		0x100
#define COMMAND_ONE_ID 	0x101
#define COMMAND_TWO_ID 	0x102
#define RSP_INTR		0
#define RSP_NAME		1
#define RSP_FIRE		2
#define RSP_GUARD		3
#define RSP_AGAIN		4
#define RSP_NOVOICE		5
#define RSP_NAMEDIFF	6
#define RSP_CMDDIFF		7
#define RSP_STAR		8
#define RSP_MASTER		9
#define RSP_HERE		10
#define RSP_GUNSHOT		0
#define RSP_PATROL		11
#define RSP_READY		12
#define RSP_COPY		13
#define RSP_NOISY		14

//..................ȫ�̱���....................
int gActivated = 0;	//�ñ������ڼ���Ƿ��д����������ʶ������
                    //Ϊ�����������λ��1 
					 
int gTriggerRespond[] = {RSP_MASTER, RSP_HERE, RSP_MASTER};
int gComm2Respond[] = {RSP_PATROL, RSP_READY, RSP_COPY};
extern void ClearWatchDog();
int PlayFlag = 0;

void PlayRespond2(int Result)
{
	BSR_StopRecognizer();
	SACM_A2000_Initial(1);
	SACM_A2000_Play(Result, 3, 3);
	while((SACM_A2000_Status()&0x0001) != 0)
	{
		SACM_A2000_ServiceLoop();
		ClearWatchDog();
	}
	SACM_A2000_Stop();
	BSR_InitRecognizer(BSR_MIC);
	BSR_EnableCPUIndicator();	
}

void PlayRespond(int Result)
{
	BSR_StopRecognizer();
	SACM_S480_Initial(1);
	SACM_S480_Play(Result, 3, 3);
	while((SACM_S480_Status()&0x0001) != 0)
	{
		SACM_S480_ServiceLoop();
		ClearWatchDog();
	}
	SACM_S480_Stop();
	BSR_InitRecognizer(BSR_MIC);
	BSR_EnableCPUIndicator();	
}

int TrainWord(int WordID, int RespondID)
{
	int res;
	PlayRespond(RespondID);
	while(1)
	{
		res = BSR_Train(WordID,BSR_TRAIN_TWICE);
		if(res == 0) break;
		switch(res)
		{
		case -1: 									//û�м�������
			PlayRespond(RSP_NOVOICE);
			return -1;
		case -2: 									//��Ҫ����ѵ��һ��
			PlayRespond(RSP_AGAIN);
			break;
		case -3: 									//����̫��
			PlayRespond(RSP_NOISY);
			return -1;		
		case -4: 									//���ݿ���
		 	return -1;
		case -5: 									//����������ͬ
			if(WordID == NAME_ID)	PlayRespond(RSP_NAMEDIFF);//�����������Ʋ�ͬ
			else					PlayRespond(RSP_CMDDIFF);//�����������ͬ
			return -1;
		case -6: 									//��Ŵ���
			return -1;
		}
	}
	return 0;
}

int main()
{
	int res, timeCnt=0, random_no=0;
	
	BSR_DeleteSDGroup(0);							// ��ʼ���洢��RAM

	PlayRespond(RSP_INTR);				    		//���ſ�ʼѵ������ʾ��
	//..........ѵ������..............................
	while(TrainWord(NAME_ID,1) != 0) ;
	//..........ѵ����һ������.......................
	while(TrainWord(COMMAND_ONE_ID,2) != 0) ;
	//..........ѵ���ڶ�������.......................
	while(TrainWord(COMMAND_TWO_ID,3) != 0) ;
	
	//..........��ʼʶ������.........................
	BSR_InitRecognizer(BSR_MIC);		    		//��ʶ����ʼ��
	BSR_EnableCPUIndicator();

	PlayRespond(RSP_STAR);			    			// ���ſ�ʼ��ʶ����ʾ��
	
	while(1)
	{
		random_no ++;
		if(random_no >= 3) random_no = 0;
		res = BSR_GetResult();
		
		if(res > 0)							//ʶ�������
		{
			if(gActivated)
			{
				timeCnt = 0;
				switch(res)
				{
				case NAME_ID:
					PlayRespond(gTriggerRespond[random_no]);
					break;
				case COMMAND_ONE_ID:
					PlayFlag = 1;
					PlayRespond2(RSP_GUNSHOT);
					PlayFlag = 0;
					gActivated = 0;
					break;
				case COMMAND_TWO_ID:
					PlayRespond(gComm2Respond[random_no]);	
					gActivated = 0;
				}				
			}
			else
			{
				if(res == NAME_ID)
				{
					PlayRespond(gTriggerRespond[random_no]);
					gActivated = 1;
					timeCnt = 0;
				}
			}	
		}
		else if (gActivated)
		{
			if (++timeCnt > 450)			//������ʱ
			{
				PlayRespond(RSP_NOVOICE); 	//���趨ʱ����û�м�������					
				gActivated = 0;
				timeCnt = 0;
			}
		}
	}
}
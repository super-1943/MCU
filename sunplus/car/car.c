#include <spce061a.h>

int main()
{
	int i;
	*P_IOB_Data= 0x0000; //����IOB0~IOB15�˿�Ϊ�����ݻ���ĵ͵�ƽ���
	*P_IOB_Dir = 0xffff;
	*P_IOB_Attrib = 0xffff;
	while(1)
	{
		*P_IOB_Data=0x0001;
		for(i=0;i<0x0fff;i++)
			*P_Watchdog_Clear=1;
		*P_IOB_Data=0x0000;
		for(i=0;i<0x0fff;i++)
			*P_Watchdog_Clear=1;
	}
}
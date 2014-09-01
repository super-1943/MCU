#include <spce061a.h>
unsigned int tb[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x40};
unsigned int dot=0x80;
unsigned int buffer[8];//buffer[0]��ģʽ��buffer��1����Ƶ�ʣ�buffer��2��������ѹ��buffer[3]Ϊȫ�ֱ���
void longdelay(void)
{
	int i,j;
	for(i=0;i<600;i++)
		for(j=0;j;j--)
		*P_Watchdog_Clear=1;
}
void shortdelay(void)
{
	int i;
	for(i=20;i;i--)
		*P_Watchdog_Clear=1;
}

//������ʾģ��		void show��int mode��int freq��int mvol����
//���ú�����shortdelay();
//��ڲ�����int mode��0�������Ҳ���1��������2�������ǲ�
//			int freq: Ƶ�ʣ���HzΪ��λ,��ʾ���������ʱ��λΪkHz;
//			int mvol: ������ֵ��10*vmax;
//���ڲ�������
void show(int mode,int freq,int mvol)
{
	unsigned int count,tmp[8],j;
//	*P_IOA_Dir=0xffff;
//	*P_IOA_Attrib=0xffff;
	tmp[0]=tb[mode];
	tmp[1]=tb[10];
	if(freq<100)
	{
		return;
	}
	else if(freq<20000)
	{
		tmp[2]=tb[freq/10000];
		tmp[3]=tb[(freq%10000)/1000];
		tmp[3]|=dot;
		tmp[4]=tb[(freq/100)%10];
	}
	else
	{
		return;
	}
	tmp[5]=tb[10];
	tmp[6]=tb[mvol/10]|dot;
	tmp[7]=tb[mvol%10];
	for(j=0;j<1;j++)
	{
	for(count=0;count<8;count++)
	{
		*P_IOA_Data=((0x0100<<count)|tmp[count]);
		shortdelay();
		
		*P_IOA_Data=0x0000;	
	}
	}
}

/*****************************************************
��������ģ�飺  int KeyTemp,Value;
���ú����� KeyValue()
��ڲ����� ��

           ��1����int mode��1��
		   ��2����int freq��100Hz��
		   ��3����int freq��100Hz��
		   ��4����int mvol��0.1V��
		   ��5����int mvol��0.1V��
		   ��6��7 ���޶��壻
		   ��8����ִ�С�		   
*****************************************************/			 
void KeyScan()
{
	 int KeyTemp,Value;
	*P_Watchdog_Clear = 0x0001;
	*P_IOB_Dir = 0xff00;
	*P_IOB_Attrib = 0xff00;
	KeyTemp=*P_IOB_Data;

	Value=KeyTemp^0x00ff;	

	switch(Value)
	{
			case 0x0080:
					buffer[0]++;
					if(buffer[0]==3)
						buffer[0]=0;
					break;
			case 0x0040:
					buffer[1]+=100;
					break;
			case 0x0020:
					buffer[1]-=100;
					break;
			case 0x0010:
					if(buffer[2]==50)
					{
						buffer[2]=0;
						break;
					}
					buffer[2]++;
					break;
			case 0x0008:
					if(buffer[2]==0)
					{
						buffer[2]=50;
						break;
					}
					buffer[2]--;
					break;
			default:
					break;
	}
}
	

int main(void)
{
	
	*P_IOA_Dir=0xffff;
	*P_IOA_Attrib=0xffff;
	*P_IOA_Data=0xffff;
	buffer[0]=0;
	buffer[1]=100;
	buffer[2]=20;
	while(1)
	{
		KeyScan();
		show(buffer[0],buffer[1],buffer[2]);
		*P_Watchdog_Clear=1;
	}
}


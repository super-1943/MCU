#include <fstream.h>
#include <string.h>
void main(void)
{
	char inname[20];
begin:	cout<<"������Hex�ļ�����";
	cin>>inname;
	ifstream a(inname);
	if(!a)
	{
		cout<<"�޷����ļ�����������ȷ���ļ�����"<<endl;
		goto begin;
	}
	ofstream b("mid");
	char buff[100];
	int length;
	while(!a.eof())
	{
		a>>buff;
		length=strlen(buff);
		for(int i=9;i<length-2;i++)
		{
			cout<<buff[i];
			b<<buff[i];
		}
		
		cout<<endl;
		b<<endl;
	}
	a.close();
	b.close();
	
	int count=0;
	a.open("mid");
	b.open("kkk.txt");
	char bx;
	int flag=0;
	b<<"const unsigned char dataforprogram[]PROGMEM={"<<endl;
	while(!a.eof())
	{

		a>>bx;
		if(((bx>='0' && bx<='9')|(bx>='A' && bx<='F')) && flag==0)
		{
			b<<"0x";
			b<<bx;
			flag=1;
			continue;
		}
		if(((bx>='0' && bx<='9')|(bx>='A' && bx<='F')) && flag==1)
		{
			b<<bx;
			flag=0;
			b<<',';
			count++;
			if(count%10==0)
			{
				b<<endl;
			}
		}
	}
	b<<"\13};";
	b<<count<<endl;
	cout<<"OK"<<endl;
	a.close();
	b.close();
	cout<<"ת����ɣ��뵽��Ŀ¼�ļ�������kkk.txt�ļ���"<<endl;
}

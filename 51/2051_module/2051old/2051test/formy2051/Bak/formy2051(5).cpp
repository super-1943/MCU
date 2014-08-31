#include <fstream.h>
#include <string.h>
void main(void)
{
	ifstream a("1.hex");
	ofstream b("2.hex");
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
	a.open("2.hex");
	b.open("kkk.txt");
	char bx;
	int flag=0;
	a<<"const unsigned char dataforprogram[]PROGMEM={"<<endl;
	while(!b.eof())
	{

		b>>bx;
		if(((bx>='0' && bx<='9')|(bx>='A' && bx<='F')) && flag==0)
		{
			a<<"0x";
			a<<bx;
			flag=1;
			continue;
		}
		if(((bx>='0' && bx<='9')|(bx>='A' && bx<='F')) && flag==1)
		{
			a<<bx;
			flag=0;242526H
			a<<',';
			count++;
			if(count%10==0)
			{
				a<<endl;
			}
		}
	}
	a<<"\13};";
	a<<count<<endl;
	cout<<"OK"<<endl;
	
}

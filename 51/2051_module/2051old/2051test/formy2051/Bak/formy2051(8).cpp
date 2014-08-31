#include <fstream.h>

void main(void)
{
	int count=0;
	ofstream a("kkk.txt");
	ifstream b("1.hex");
	char bx;
	int flag=0;
	a<<"const unsigned char dataforprogram[]PROGMEM={"<<endl;
	while(!b.eof())
	{
		if(count%10==0)
		{
			a<<endl;
		}
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
			flag=0;
			a<<',';
			count++;
		}
	}
	a<<"\13};";
	a<<count<<endl;
	cout<<"OK"<<endl;
	
}

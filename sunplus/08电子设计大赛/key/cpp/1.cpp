#include <fstream.h>
void main()
{
	ofstream a("kkk.txt");
	int tb[256];
	for(int i=0;i<128;i++)
	{
		tb[i]=i<<6;
	}
	for(i=128;i<256;i++)
	{
		tb[i]=(256-i)<<6;
	}
	for(i=0;i<256;i++)
	{
		a<<tb[i]*10*20/49<<",";
	}
	a<<endl;
	a.close();
}
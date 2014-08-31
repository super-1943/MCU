#include<reg52.h>
#include <absacc.h>
#define LCMDW(x) 	XBYTE[0x8000+x]
void main(void)
{
	unsigned char i;
	for(i=0;i<100;i++)
	{
		LCMDW(i)=i;
	}
	while(1)
	{

	}
}
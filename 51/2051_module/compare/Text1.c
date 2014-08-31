#include <reg51.h>
sbit comp=P3^6;
sbit led=P3^7;
void main(void)
{
	while(1)
	{
		led=comp;
	}
}
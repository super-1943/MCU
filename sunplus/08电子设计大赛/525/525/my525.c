#include <spce061a.h>
#include <my525.h>
#include <my7219.h>
#include <key.h>
unsigned int table[]={0,12,25,37,48,59,68,77,84,90,95,98,100,100,98,95,90,84,77,68,59,48,37,25,12,0};



void delay(void)
{
	int i,j;
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
			*P_Watchdog_Clear=1;
}
int main(void)
{
	int i;
	init525();
	init7219();
	while(1)
	{
/*	
		for(i=0;i<25;i++)
		{
		send525(10*(table[i]+100));
		*P_Watchdog_Clear=1;
		}
		for(i=0;i<25;i++)
		{
			send525(10*(100-table[i]));
			*P_Watchdog_Clear=1;
		}
*/
		show(1,100,1);
			
	}
}
	
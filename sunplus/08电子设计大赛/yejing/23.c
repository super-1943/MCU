#include <spce061a.h>
#define nop __asm("NOP")
#define rs_0 (*P_IOA_Data&=~0x0001)
#define rs_1 (*P_IOA_Data|=0x0001)
#define rw_0 (*P_IOA_Data&=~0x0002)
#define rw_1 (*P_IOA_Data|=0x0002)
#define e_0 (*P_IOA_Data&=~0x0004)
#define e_1 (*P_IOA_Data|=0x0004)
void delay(unsigned int t)             //t∫¡√Î
{
	unsigned char i;
	while(t--)
	{
    	for(i=0;i<125;i++)
    		*P_Watchdog_Clear=1;
	}
}


int busy(void)
{
	rs_0;
	rw_1;
	nop;
	e_1;
	nop;
	e_0;
	return (*P_IOA_Data>>8);
}
void write_cmd(int cmd)
{
	e_0;
	nop;
	rs_0;
	nop;
	rw_0;
	nop;
	*P_IOA_Data&=0x00ff;
	*P_IOA_Data|=(cmd<<8);
	nop;
	e_1;
	nop;
	e_0;
	nop;
	busy();
}

void write_dat(int dat)
{
	e_0;
	nop;
	rs_1;
	nop;
	rw_0;
	nop;
	*P_IOA_Data&=0x00ff;
	*P_IOA_Data|=(dat<<8);
	nop;
	e_1;
	nop;
	e_0;
	nop;
	busy();
}

void show(char * str)
{
	while(*str!='\0')
	{
		*P_Watchdog_Clear=1;
		write_dat(*str);
		str++;
	}
}
void goxy(int y,int x)
{
	if(y==1)
		write_cmd(0x80|x);
	if(y==2)
		write_cmd(x+(0x40));
}
void init_1602(void)
{
	e_0;
	delay(15);
	write_cmd(0x38);
	delay(5);
	write_cmd(0x38);
	delay(5);
	write_cmd(0x38);
	write_cmd(0x38);
	nop;
	write_cmd(0x08);
	nop;
	write_cmd(0x06);
	nop;
	write_cmd(0x0c);
	nop;
	write_cmd(0x01);
	nop;
}

int main(void)
{
	int i=0;
	*P_IOA_Dir=0xffff;
	*P_IOA_Attrib=0xffff;
	*P_IOA_Data=0x0000;
	init_1602();
	delay(500);
	write_cmd(0x01);
	goxy(1,6);
	show("I am kkk");
	delay(1000);
	goxy(2,0);
	show("wk");
	delay(1000);
	while(1)
	{			
		*P_Watchdog_Clear=1;
	}
}

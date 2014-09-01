#include <spce061a.h>

#define Command (*P_IOA_Data&=~0x0080)
#define Data (*P_IOA_Data|=0x0080)
#define Read (*P_IOA_Data|=0x0040)
#define Write (*P_IOA_Data&=~0x0040)
#define E_0 (*P_IOA_Data &=~0x0020)
#define E_1 (*P_IOA_Data |=0x0020)
#define Execute E_0;E_0;E_0;E_0;E_1;

#define ClearAll 0x01
#define Return 0x02
#define CursorLeftWordNoMove 0x04
#define CursorLeftWordLeft 0x05
#define CursorRightWordNoMove 0x06
#define CursorRightWordRight 0x07

#define MainOpen 0x0c
#define MainClose 0x08
#define CursorShow 0x02
#define CursorNoShow 0x00
#define CursorFlash 0x01
#define CursorNoFlash 0x00


#define WordMoveLeft 0x18
#define WordMoveRight 0x1c
#define CursorMoveLeft 0x10
#define CursorMoveRight 0x14
#define LCMMode 0x38
void writecommand(char data,char busy);
char waitbusy(void);
void writedata(char data);
char readdata(void);
void displaychar(char x,char y,char data);

void delay(void)
{
	int i,j;
	for(i=200;i;i--)
		for(j=10;j;j--)
			*P_Watchdog_Clear=1;
}
void initport(void)
{
	*P_IOA_Dir|=0xfff0;
	*P_IOA_Attrib|=0xfff0;
	*P_IOA_Data&=~0xfff0;
}
void init1602(void)
{
	*P_IOA_Data&=0x00ff;
	writecommand(LCMMode,0);
	delay();
	writecommand(LCMMode,0);
	delay();
	writecommand(LCMMode,0);
	delay();
	writecommand(LCMMode,1);
	writecommand(MainClose,1);
	writecommand(ClearAll,1);
	writecommand(CursorRightWordNoMove,1);
	writecommand(MainOpen,1);
}

	
	

int main(void)
{
	initport();
	init1602();
	while(1)
	{
		displaychar(1,1,'0');
		*P_Watchdog_Clear=1;
	}
}
void writecommand(char data,char busy)
{
	if(busy)
	{
		waitbusy();
	}
	Command;
	Write;
	*P_IOA_Data&=~0xfff0;
	*P_IOA_Data|=data<<8;
	Execute;
}
void writedata(char data)
{
	waitbusy();
	*P_IOA_Data&=~0xfff0;
	*P_IOA_Data|=data<<8;
	Write;
	Command;
	Execute;
}
char waitbusy(void)
{
	*P_IOA_Data|=0xff00;
	Command;
	Read;
	Execute;
//	while(*P_IOA_Data&0x8000)
	{
		*P_Watchdog_Clear=1;
	}
	return (*P_IOA_Data>>8);
}
char readdata(void)
{
	Read;
	Data;
	Execute;
	return (*P_IOA_Data>>8);
}
void displaychar(char x,char y,char data)
{
	y&=0x0001;
	x&=0x000f;
	if(y)
	{
		x|=0x0040;
	}
	x|=0x0080;
	writecommand(x,0);
	writedata(data);
}
#include "clock.h"
extern const int SINTABLE[60];

void drawclock(void)
{
	unsigned char i;
	int x,y;
	Clear();
	circle(CENTER_X,CENTER_Y,LEN_RADIUS,COLOR_BACK);
	ShowCharWithColor(CENTER_X-8,CENTER_Y-LEN_RADIUS+2,'1'-0x20,COLOR_NUMB,COLOR_BACK);
	ShowCharWithColor(CENTER_X,CENTER_Y-LEN_RADIUS+2,'2'-0x20,COLOR_NUMB,COLOR_BACK);
	ShowCharWithColor(CENTER_X-4,CENTER_Y+LEN_RADIUS-14,'6'-0x20,COLOR_NUMB,COLOR_BACK);
	ShowCharWithColor(CENTER_X+LEN_RADIUS-10,CENTER_Y-4,'3'-0x20,COLOR_NUMB,COLOR_BACK);
	ShowCharWithColor(CENTER_X-LEN_RADIUS+2,CENTER_Y-4,'9'-0x20,COLOR_NUMB,COLOR_BACK);
	for(i=0;i<60;i++)
	{
		if(i%15==0)
		{
			continue;
		}
		x=CENTER_X+LEN_RADIUS*SINTABLE[i]/100;
		y=CENTER_Y-LEN_RADIUS*SINTABLE[(i+15)%60]/100;
		line_deg(x,y,(i+30)%60,2,COLOR_NUMB);
	}
}

void move_second(unsigned char dlast,unsigned char dthis)
{
	line_deg(CENTER_X,CENTER_Y,dlast,LEN_SECN,COLOR_BACK);
	line_deg(CENTER_X,CENTER_Y,dthis,LEN_SECN,COLOR_SECN);
}
void move_minute(unsigned char dlast,unsigned char dthis)
{
	line_deg(CENTER_X,CENTER_Y,dlast,LEN_MINU,COLOR_BACK);
	line_deg(CENTER_X,CENTER_Y,dthis,LEN_MINU,COLOR_MINU);
}
void move_hour(unsigned char dlast,unsigned char dthis)
{
	line_deg(CENTER_X,CENTER_Y,dlast%60,LEN_HOUR,COLOR_BACK);
	line_deg(CENTER_X,CENTER_Y,dthis%60,LEN_HOUR,COLOR_HOUR);
}


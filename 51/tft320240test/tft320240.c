#include "tft320240.h"
#include "string.h"

extern code unsigned char ascii_font[][16];
extern code unsigned char Hanzi[];
//---------------------------------------------------------------------------
void tft320240_delay(UINT t)
{
	UCHAR i;
	while( t > 0 )
	{
		t--;
		for ( i = 0; i < 255; i++ )
			;
	}
}
//---------------------------------------------------------------------------
void tft320240_W_COM(UINT dat)
{
	CTRLPORT&=~LCD_RS;// = 0;
	DATAPORT = dat >> 8;
	CTRLPORT&=~LCD_WR;// = 0;
	CTRLPORT|=LCD_WR;// = 1;
	DATAPORT = dat & 0xFF;
	CTRLPORT&=~LCD_WR;// = 0;
	CTRLPORT|=LCD_WR;// = 1;
}
//---------------------------------------------------------------------------
void tft320240_W_DATA(UINT dat)
{
	CTRLPORT|=LCD_RS;// = 1;
	DATAPORT = dat >> 8;
	CTRLPORT&=~LCD_WR;// = 0;
	CTRLPORT|=LCD_WR;// = 1;
	DATAPORT = dat & 0xFF;
	CTRLPORT&=~LCD_WR;// = 0;
	CTRLPORT|=LCD_WR;// = 1;
}
//---------------------------------------------------------------------------
void tft320240_blockwrite(UINT sx, UINT ex, UINT sy, UINT ey)
{
	tft320240_W_COM(0x0050);
	tft320240_W_DATA(sx);
	tft320240_W_COM(0x0051);
	tft320240_W_DATA(ex);
	tft320240_W_COM(0x0052);
	tft320240_W_DATA(sy);
	tft320240_W_COM(0x0053);
	tft320240_W_DATA(ey);

	tft320240_W_COM(0x0020);//IMPORTANT
	tft320240_W_DATA(0);
	tft320240_W_COM(0x0021);
	tft320240_W_DATA(0);

	tft320240_W_COM(0x0022);
}
//---------------------------------------------------------------------------
void tft320240_clear(void)
{
	tft320240_show(0x0000, 0x00EF, 0x0000, 0x013F, 0x0000);
}


//---------------------------------------------------------------------------
void tft320240_initial(void)
{
//	DATADIR=0xff;
	DATAPORT=0x00;
//	CTRLDIR=LCD_RESET|LCD_RS|LCD_WR;
	CTRLPORT|=LCD_RESET;// = 1;
	tft320240_delay(50);
	CTRLPORT&=~LCD_RESET;// = 0;
	tft320240_delay(200);
	CTRLPORT|=LCD_RESET;// = 1;
	tft320240_delay(50);	
	
	
	tft320240_W_COM(0x0000);tft320240_W_DATA(0x0000);
	tft320240_W_COM(0x0001);tft320240_W_DATA(0x0100);
	tft320240_W_COM(0x0002);tft320240_W_DATA(0x0700);
	tft320240_W_COM(0x0003);tft320240_W_DATA(0x10B0);

	tft320240_W_COM(0x0004);tft320240_W_DATA(0x0000);
	tft320240_W_COM(0x0008);tft320240_W_DATA(0x0207);
	tft320240_W_COM(0x0009);tft320240_W_DATA(0x0000);
	tft320240_W_COM(0x000A);tft320240_W_DATA(0x0000);
	tft320240_W_COM(0x000C);tft320240_W_DATA(0x0000);
	tft320240_W_COM(0x000D);tft320240_W_DATA(0x0000);
	tft320240_W_COM(0x000F);tft320240_W_DATA(0x0000);
	tft320240_W_COM(0x0007);tft320240_W_DATA(0x0101);
	tft320240_delay(10);

	tft320240_W_COM(0x0010);tft320240_W_DATA(0x12B0);
	tft320240_W_COM(0x0011);tft320240_W_DATA(0x0007);
	tft320240_W_COM(0x0017);tft320240_W_DATA(0x0001);
	tft320240_W_COM(0x0012);tft320240_W_DATA(0x01BB);
	tft320240_W_COM(0x0013);tft320240_W_DATA(0x1F00);
	tft320240_W_COM(0x0029);tft320240_W_DATA(0x0012);
	tft320240_delay(10);

	tft320240_W_COM(0x0030);tft320240_W_DATA(0x0102);
	tft320240_W_COM(0x0031);tft320240_W_DATA(0x0C15);
	tft320240_W_COM(0x0032);tft320240_W_DATA(0x0B18);
	tft320240_W_COM(0x0033);tft320240_W_DATA(0x1C0F);
	tft320240_W_COM(0x0034);tft320240_W_DATA(0x120B);
	tft320240_W_COM(0x0035);tft320240_W_DATA(0x0A04);
	tft320240_W_COM(0x0036);tft320240_W_DATA(0x1F00);
	tft320240_W_COM(0x0037);tft320240_W_DATA(0x051F);
	tft320240_W_COM(0x0038);tft320240_W_DATA(0x0305);
	tft320240_W_COM(0x0039);tft320240_W_DATA(0x0A05);
	tft320240_W_COM(0x003A);tft320240_W_DATA(0x0F04);
	tft320240_W_COM(0x003B);tft320240_W_DATA(0x0F00);
	tft320240_W_COM(0x003C);tft320240_W_DATA(0x000F);
	tft320240_W_COM(0x003D);tft320240_W_DATA(0x050F);
	tft320240_W_COM(0x003E);tft320240_W_DATA(0x0204);
	tft320240_W_COM(0x003F);tft320240_W_DATA(0x0404);

	tft320240_W_COM(0x0050);tft320240_W_DATA(0x0000);
	tft320240_W_COM(0x0051);tft320240_W_DATA(0x00EF);
	tft320240_W_COM(0x0052);tft320240_W_DATA(0x0000);
	tft320240_W_COM(0x0053);tft320240_W_DATA(0x013F);
	tft320240_delay(10);

	tft320240_W_COM(0x0060);tft320240_W_DATA(0x2700);
	tft320240_W_COM(0x0061);tft320240_W_DATA(0x0001);
	tft320240_W_COM(0x006A);tft320240_W_DATA(0x0000);
	tft320240_delay(10);

	tft320240_W_COM(0x0080);tft320240_W_DATA(0x0000);
	tft320240_W_COM(0x0081);tft320240_W_DATA(0x0000);
	tft320240_W_COM(0x0082);tft320240_W_DATA(0x0000);
	tft320240_W_COM(0x0083);tft320240_W_DATA(0x0000);
	tft320240_W_COM(0x0084);tft320240_W_DATA(0x0000);
	tft320240_W_COM(0x0085);tft320240_W_DATA(0x0000);

	tft320240_W_COM(0x0090);tft320240_W_DATA(0x0018);
	tft320240_W_COM(0x0092);tft320240_W_DATA(0x0000);
	tft320240_W_COM(0x0093);tft320240_W_DATA(0x0103);
	tft320240_W_COM(0x0095);tft320240_W_DATA(0x0210);
	tft320240_W_COM(0x0097);tft320240_W_DATA(0x0000);
	tft320240_W_COM(0x0098);tft320240_W_DATA(0x0000);

	tft320240_W_COM(0x00F0);tft320240_W_DATA(0x5408);
	tft320240_W_COM(0x00F2);tft320240_W_DATA(0x00DF);
	tft320240_W_COM(0x00F3);tft320240_W_DATA(0x0006);
	tft320240_W_COM(0x00F4);tft320240_W_DATA(0x001F);
	tft320240_W_COM(0x00F7);tft320240_W_DATA(0x0080);
	tft320240_W_COM(0x00F0);tft320240_W_DATA(0x0000);

	tft320240_W_COM(0x0007);tft320240_W_DATA(0x0173);
	tft320240_delay(80);
	tft320240_W_COM(0x0007);tft320240_W_DATA(0x0171);
	tft320240_delay(80);
	tft320240_W_COM(0x0007);tft320240_W_DATA(0x0173);
	tft320240_delay(80);
}
void tft320240_show(UINT sx, UINT ex, UINT sy, UINT ey, UINT dat)
{
	UINT x, y, i, j;
	tft320240_blockwrite(sx, ex, sy, ey);
	
	x = ex - sx;
	y = ey - sy;
	
	for ( i = 0; i <= y; i++ )
		for ( j = 0; j <= x; j++ )
			tft320240_W_DATA(dat);
}
//---------------------------------------------------------------------------
void tft320240_show_colorchar(UCHAR sx, UINT sy, UCHAR index, UINT CharColor, UINT BkColor)
{
	UCHAR i, j;
	UCHAR mask;

	if ( index > 95 )
		return;

	tft320240_blockwrite(sx, sx+7, sy, sy+15);	
	for ( i = 0; i < 16; i++ )
	{
		mask = 0x80;
		for ( j = 0; j < 8; j++ )
		{
			tft320240_W_DATA((ascii_font[index][i] & mask) ? CharColor : BkColor);
			mask >>= 1;
		}
	}
}
//---------------------------------------------------------------------------
void tft320240_show_string(UCHAR sx, UINT sy, char* string)
{
	UCHAR len;

	len = strlen( string );
	tft320240_show(sx, len*8+2, sy, sy+17, 0);
	++sx;
	++sy;
	while( *string != 0 )
	{
		tft320240_show_colorchar(sx, sy, *string-32, 0xFFFF, 0x0000);
		sx += 8;
		string++;
	}
}
void tft320240_show_hanzi(UCHAR sx, UINT sy, UCHAR index, UINT CharColor, UINT BkColor)
{
	UCHAR i, j;
	UCHAR mask;
	tft320240_blockwrite(sx, sx+15, sy, sy+15);//16*16 
	for ( i = 0; i < 32; i++ )
	{
		mask = 0x80;
		for ( j = 0; j <8; j++ )
		{
			tft320240_W_DATA((Hanzi[index*32+i] & mask) ? CharColor : BkColor);
			mask >>= 1;
		}
	}
}

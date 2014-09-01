#include "tft320240.h"
#include "string.h"

extern const unsigned char ascii_font[][16];
extern const unsigned char Hanzi[];
const int SINTABLE[60]=
{
	0,   10,  21 , 31, 41, 50 , 59, 67, 74, 81, 
	87,	 91,  95 , 98, 99, 100, 99, 98, 95, 91, 
	87,  81,  74 , 67, 59, 50 , 41,	31, 21, 10, 
	0 ,  -10, -21, -31,-41,-50, -59,-67,-74,-81,
	-87, -91, -95, -98,-99,-100,-99,-98,-95,-91,
	-87, -81, -74, -67,-59,-50 ,-41,-31,-21,-10 
};
void green_dark_heng(void)
{
	unsigned int t;
	for(t=0;t<=0x018f;t+=1)
	{
		Show(0,0x00ef,t,t, t<<6);	
	}
}
/***************************************************************
画线函数
参数：起点横坐标，终点横坐标，起点纵坐标，终点纵坐标，线颜色
***************************************************************/
void drawline(int sx, int ex, int sy, int ey,UINT linecolor)
{
	int a,b;
	int diffx,diffy;
	if(sx==ex)
	{
		if(sy<=ey)
		{
			for(b=sy;b<=ey;b++)
			{
				BlockWrite(sx,sx,b,b);
				W_DATA(linecolor);
			}
		}
		else
		{
			for(b=ey;b<=sy;b++)
			{
				BlockWrite(sx,sx,b,b);
				W_DATA(linecolor);
			}
		}
		return;
	}
	if(sy==ey)
	{
		if(sx<=ex)
		{
			for(a=sx;a<=ex;a++)
			{
				BlockWrite(a,a,sy,sy);
				W_DATA(linecolor);		
			}
		}
		else
		{
			for(a=ex;a<=sx;a++)
			{
				BlockWrite(a,a,sy,sy);
				W_DATA(linecolor);		
			}
		}
		return;
	}
//剩下就是一般情况了！！！
#define ABS(x) ((x>0)?(x):(-x))

	diffx=ex-sx;
	diffy=ey-sy;
	if(ABS(diffx)>ABS(diffy))
	{
		if(sx<ex)
		{
			for(a=sx;a<=ex;a++)
			{
				b=sy+(a-sx)*diffy/diffx;
				BlockWrite(a,a,b,b);
				W_DATA(linecolor);
			}
		}
		else
		{
			for(a=ex;a<=sx;a++)
			{
				b=ey+(a-ex)*diffy/diffx;
				BlockWrite(a,a,b,b);
				W_DATA(linecolor);
			}
		}
	}
	else//ABS(diffx)<=ABS(diffy)
	{
		if(sy<ey)
		{
			for(b=sy;b<=ey;b++)
			{
				a=sx+(b-sy)*diffx/diffy;
				BlockWrite(a,a,b,b);
				W_DATA(linecolor);
			}
		}
		else
		{
			for(b=ey;b<=sy;b++)
			{
				a=ex+(b-ey)*diffx/diffy;
				BlockWrite(a,a,b,b);
				W_DATA(linecolor);
			}
		}
	}
}
/******************************************************
绘制矩形函数
参数说明：起点横坐标，起点纵坐标，终点横坐标，终点纵坐标
		  矩形颜色

******************************************************/
void juxing(UINT x0,UINT y0,UINT x1,UINT y1,UINT color)
{
	drawline(x0,x1,y1,y1,color);
	drawline(x0,x1,y0,y0,color);
	drawline(x1,x1,y0,y1,color);
	drawline(x0,x0,y0,y1,color);
}
/**************************************************************************
显示图片函数
参数说明：图片数据首地址，起点横坐标，起点纵坐标，图片宽度，图片高度
***************************************************************************/
void show_pic(unsigned char * table,UINT x0,UINT y0,UINT width,UINT height)
{
	UINT x;
	UINT temp;
	BlockWrite(x0,x0+width-1,y0,y0+height-1);
	for(x=0;x<width*height*2;x+=2)
	{
		temp=table[x]<<8;
		temp+=table[x+1];
		W_DATA(temp);
	}
}

//---------------------------------------------------------------------------
void Delay(UINT t)
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
void W_COM(UINT dat)
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
void W_DATA(UINT dat)
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
void BlockWrite(UINT sx, UINT ex, UINT sy, UINT ey)
{
	W_COM(0x0050);
	W_DATA(sx);
	W_COM(0x0051);
	W_DATA(ex);
	W_COM(0x0052);
	W_DATA(sy);
	W_COM(0x0053);
	W_DATA(ey);

	W_COM(0x0020);//IMPORTANT
	W_DATA(0);
	W_COM(0x0021);
	W_DATA(0);

	W_COM(0x0022);
}
//---------------------------------------------------------------------------
void Clear(void)
{
	Show(0x0000, 0x00EF, 0x0000, 0x013F, 0x0000);
}
//---------------------------------------------------------------------------
void Full(void)
{
	Show(0x0000, 0x00EF, 0x0000, 0x013F, 0xFFFF);
}
//---------------------------------------------------------------------------
void Red(void)
{
	Show(0x0000, 0x00EF, 0x0000, 0x013F, 0xF800);
}
//---------------------------------------------------------------------------
void Green(void)
{
	Show(0x0000, 0x00EF, 0x0000, 0x013F, 0x07E0);
}
//---------------------------------------------------------------------------
void Blue(void)
{
	Show(0x0000, 0x00EF, 0x0000, 0x013F, 0x001F);
}
//---------------------------------------------------------------------------
void Show(UINT sx, UINT ex, UINT sy, UINT ey, UINT dat)
{
	UINT x, y, i, j;
	BlockWrite(sx, ex, sy, ey);
	
	x = ex - sx;
	y = ey - sy;
	
	for ( i = 0; i <= y; i++ )
		for ( j = 0; j <= x; j++ )
			W_DATA(dat);
}
//---------------------------------------------------------------------------
void SPFD5408A_CPT24_Initial(void)
{
	DATADIR=0xff;
	DATAPORT=0x00;
	CTRLDIR=LCD_RESET|LCD_RS|LCD_WR;
	CTRLPORT|=LCD_RESET;// = 1;
	Delay(50);
	CTRLPORT&=~LCD_RESET;// = 0;
	Delay(200);
	CTRLPORT|=LCD_RESET;// = 1;
	Delay(50);	
	
	
	W_COM(0x0000);W_DATA(0x0000);
	W_COM(0x0001);W_DATA(0x0100);
	W_COM(0x0002);W_DATA(0x0700);
	W_COM(0x0003);W_DATA(0x10B0);

	W_COM(0x0004);W_DATA(0x0000);
	W_COM(0x0008);W_DATA(0x0207);
	W_COM(0x0009);W_DATA(0x0000);
	W_COM(0x000A);W_DATA(0x0000);
	W_COM(0x000C);W_DATA(0x0000);
	W_COM(0x000D);W_DATA(0x0000);
	W_COM(0x000F);W_DATA(0x0000);
	W_COM(0x0007);W_DATA(0x0101);
	Delay(10);

	W_COM(0x0010);W_DATA(0x12B0);
	W_COM(0x0011);W_DATA(0x0007);
	W_COM(0x0017);W_DATA(0x0001);
	W_COM(0x0012);W_DATA(0x01BB);
	W_COM(0x0013);W_DATA(0x1F00);
	W_COM(0x0029);W_DATA(0x0012);
	Delay(10);

	W_COM(0x0030);W_DATA(0x0102);
	W_COM(0x0031);W_DATA(0x0C15);
	W_COM(0x0032);W_DATA(0x0B18);
	W_COM(0x0033);W_DATA(0x1C0F);
	W_COM(0x0034);W_DATA(0x120B);
	W_COM(0x0035);W_DATA(0x0A04);
	W_COM(0x0036);W_DATA(0x1F00);
	W_COM(0x0037);W_DATA(0x051F);
	W_COM(0x0038);W_DATA(0x0305);
	W_COM(0x0039);W_DATA(0x0A05);
	W_COM(0x003A);W_DATA(0x0F04);
	W_COM(0x003B);W_DATA(0x0F00);
	W_COM(0x003C);W_DATA(0x000F);
	W_COM(0x003D);W_DATA(0x050F);
	W_COM(0x003E);W_DATA(0x0204);
	W_COM(0x003F);W_DATA(0x0404);

	W_COM(0x0050);W_DATA(0x0000);
	W_COM(0x0051);W_DATA(0x00EF);
	W_COM(0x0052);W_DATA(0x0000);
	W_COM(0x0053);W_DATA(0x013F);
	Delay(10);

	W_COM(0x0060);W_DATA(0x2700);
	W_COM(0x0061);W_DATA(0x0001);
	W_COM(0x006A);W_DATA(0x0000);
	Delay(10);

	W_COM(0x0080);W_DATA(0x0000);
	W_COM(0x0081);W_DATA(0x0000);
	W_COM(0x0082);W_DATA(0x0000);
	W_COM(0x0083);W_DATA(0x0000);
	W_COM(0x0084);W_DATA(0x0000);
	W_COM(0x0085);W_DATA(0x0000);

	W_COM(0x0090);W_DATA(0x0018);
	W_COM(0x0092);W_DATA(0x0000);
	W_COM(0x0093);W_DATA(0x0103);
	W_COM(0x0095);W_DATA(0x0210);
	W_COM(0x0097);W_DATA(0x0000);
	W_COM(0x0098);W_DATA(0x0000);

	W_COM(0x00F0);W_DATA(0x5408);
	W_COM(0x00F2);W_DATA(0x00DF);
	W_COM(0x00F3);W_DATA(0x0006);
	W_COM(0x00F4);W_DATA(0x001F);
	W_COM(0x00F7);W_DATA(0x0080);
	W_COM(0x00F0);W_DATA(0x0000);

	W_COM(0x0007);W_DATA(0x0173);
	Delay(80);
	W_COM(0x0007);W_DATA(0x0171);
	Delay(80);
	W_COM(0x0007);W_DATA(0x0173);
	Delay(80);
}

//---------------------------------------------------------------------------
void ShowCharWithColor(UCHAR sx, UINT sy, UCHAR index, UINT CharColor, UINT BkColor)
{
	UCHAR i, j;
	UCHAR mask;

	if ( index > 95 )
		return;

	BlockWrite(sx, sx+7, sy, sy+15);	
	for ( i = 0; i < 16; i++ )
	{
		mask = 0x80;
		for ( j = 0; j < 8; j++ )
		{
			W_DATA((ascii_font[index][i] & mask) ? CharColor : BkColor);
			mask >>= 1;
		}
	}
}
//---------------------------------------------------------------------------
void ShowString(UCHAR sx, UINT sy, char* string)
{
	UCHAR len;

	len = strlen( string );
	Show(sx, len*8+2, sy, sy+17, 0);
	++sx;
	++sy;
	while( *string != 0 )
	{
		ShowCharWithColor(sx, sy, *string-32, 0xFFFF, 0x0000);
		sx += 8;
		string++;
	}
}
void ShowHanzi(UCHAR sx, UINT sy, UCHAR index, UINT CharColor, UINT BkColor)
{
	UCHAR i, j;
	UCHAR mask;
	BlockWrite(sx, sx+15, sy, sy+15);//16*16 
	for ( i = 0; i < 32; i++ )
	{
		mask = 0x80;
		for ( j = 0; j <8; j++ )
		{
			W_DATA((Hanzi[index*32+i] & mask) ? CharColor : BkColor);
			mask >>= 1;
		}
	}
}
//---------------------------------------------------------------------------
void circle(int cx,int cy,int cr,UINT color)
{
	int x,y,temp,r2=cr*cr;
	for(y=cy-cr;y<cy+cr;y++)
	{
		for(x=cx-cr;x<cx+cr;x++)
		{
			temp=(x-cx)*(x-cx);
			temp+=(y-cy)*(y-cy);
			if(temp<=r2)
			{
				BlockWrite(x, x, y, y);	
				W_DATA(color);
			}
		}
	}
}
void line_deg(int cx,int cy,int deg,int len,UINT color)
{
	int dx,dy;
	dx=cx+len*SINTABLE[deg]/100;
	dy=cy-len*SINTABLE[(deg+15)%60]/100;
	drawline(cx,dx,cy,dy,color);
}
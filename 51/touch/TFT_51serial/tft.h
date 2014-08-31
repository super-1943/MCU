#ifndef _kkk_tft_h
#define _kkk_tft_h
/*****************************************
KGM726H6 - 8 interface + TP Test

LCD PART:
IM0 - Connect to VCC(Select 8 bit interface)
IM3 - Fixed to GND
VCC1/VCC2/VCI - Connect together with 2.8~3.3V
CS - Connect to GND
RS - P3.1
WR - P3.0
RD - Connect to VDD
RESET - P3.2
DB17-DB10 - P1
DB7-DB0 - Not Connect
X/Y - Connect to TSC2046 X/Y

TSC2046 PART:
CLK - P2.0
CS - P2.1
DIN - P2.2
BUSY - P2.3
DOUT - P2.4
PENIRQ - P2.5
*******************************************/


typedef bit uint1;
typedef unsigned char uint8, uchar, UCHAR;
typedef unsigned int uint16, uint, UINT;
typedef unsigned long uint32, ulong, ULONG;
//---------------------------------------------------------------------------

sbit LCD_WR = P3^5;
sbit LCD_RS = P3^4;//RS, DC
sbit LCD_RESET = P3^6;

//---------------------------------------------------------------------------

void Delay(UINT t);
void W_COM(UINT dat);
void W_DATA(UINT dat);
void SPFD5408A_CPT24_Initial(void);
void Clear(void);
void Full(void);
void Red(void);
void Green(void);
void Blue(void);
void Show(UINT sx, UINT ex, UINT sy, UINT ey, UINT dat);
void BlockWrite(UINT sx, UINT ex, UINT sy, UINT ey);

//Text Function
void ShowCharWithColor(UCHAR sx, UINT sy, UCHAR index, UINT CharColor, UINT BkColor);
void ShowString(UCHAR sx, UINT sy, char* string);




void green_dark_heng(void)
{
	unsigned int t;
	for(t=0;t<=0x018f;t+=1)
	{
		Show(0,0x00ef,t,t, t<<6);	
	}
}
/***************************************************************
画线函数（有问题）
参数：起点横坐标，终点横坐标，起点纵坐标，终点纵坐标，线颜色
目前当sx<=ex,sy<=ey时正常
***************************************************************/
void drawline(UINT sx, UINT ex, UINT sy, UINT ey,UINT linecolor)
{
	unsigned long int a,b;
	UINT diffx,diffy;
	diffx=ex-sx;
	diffy=ey-sy;
	if(diffx==0)
	{
		for(b=sy;b<=ey;b++)
		{
			BlockWrite(sx,sx,b,b);
			W_DATA(linecolor);
		}		
	}
	else if(diffy==0)
	{
		for(a=sx;a<ex;a++)
		{
			BlockWrite(a,a,sy,sy);
			W_DATA(linecolor);		
		}
	}
	else
	{
		for(a=sx;a<=ex;a++)
		{
			b=(a-sx)*diffy/diffx;
			BlockWrite(a,a,b,b);
			W_DATA(linecolor);
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
	LCD_RS = 0;
	P0 = dat >> 8;
	LCD_WR = 0;
	LCD_WR = 1;
	P0 = dat & 0xFF;
	LCD_WR = 0;
	LCD_WR = 1;
}
//---------------------------------------------------------------------------
void W_DATA(UINT dat)
{
	LCD_RS = 1;
	P0 = dat >> 8;
	LCD_WR = 0;
	LCD_WR = 1;
	P0 = dat & 0xFF;
	LCD_WR = 0;
	LCD_WR = 1;
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




#endif
#ifndef _kkk_tft_h
#define _kkk_tft_h
typedef bit uint1;
typedef unsigned char uint8, uchar, UCHAR;
typedef unsigned int uint16, uint, UINT;
typedef unsigned long uint32, ulong, ULONG;
//---------------------------------------------------------------------------
sbit A0=P3^2;//RS, DC
sbit _WR=P3^3;
sbit _RD=P3^4;
sbit _RES=P3^5;

//---------------------------------------------------------------------------

void Delay(UINT t);
void W_COM(UINT dat);
void W_DATA(UINT dat);
void SPFD5420A_CPT30W_Initial(void);
void Clear(void);
void Full(void);
void Red(UINT sx, UINT ex, UINT sy, UINT ey);
void Green(UINT sx, UINT ex, UINT sy, UINT ey);
void Blue(UINT sx, UINT ex, UINT sy, UINT ey);
void Show(UINT sx, UINT ex, UINT sy, UINT ey, UINT dat);
void BlockWrite(UINT sx, UINT ex, UINT sy, UINT ey);
void ShowGradualColor(void);

void Sleep_In(void);
void Sleep_Out(void);

//Text Function
void ShowCharWithColor(UCHAR sx, UINT sy, UCHAR index, UINT CharColor, UINT BkColor);
void ShowString(UCHAR sx, UINT sy, char* string);

void Show040BMP_240_400(UCHAR index);
void Show040_240400_18BIT(void);
void LE_Control(UCHAR var, bit HL);




/****************************
正弦曲线函数
****************************/
void sin(void)
{
	unsigned int x;
	for(x=0;x<100;x++)
	{
		BlockWrite(sintable[x]+119,sintable[x]+119,x,x);
		W_DATA(0xf800);
	}
	for(x=100;x<200;x++)
	{
		BlockWrite(sintable[200-x-1]+119,sintable[200-x-1]+119,x,x);
		W_DATA(0xf800);
	}
	for(x=200;x<300;x++)
	{	
		BlockWrite(119-sintable[x-200],119-sintable[x-200],x,x);
		W_DATA(0xf800);
	}
	for(x=300;x<400;x++)
	{	
		BlockWrite(119-sintable[400-x-1],119-sintable[400-x-1],x,x);
		W_DATA(0xf800);
	}	
}

void blue_dark_zong(void)
{
	unsigned int t;
	for(t=0;t<=0x00ef;t+=1)
	{
		Show(t, t, 0x0000, 0x018F, t);	
	}
}
void red_dark_zong(void)
{
	unsigned int t;
	for(t=0;t<=0x00ef;t+=1)
	{
		Show(t, t, 0x0000, 0x018F, t<<11);	
	}
}
void green_dark_zong(void)
{
	unsigned int t;
	for(t=0;t<=0x00ef;t+=1)
	{
		Show(t, t, 0x0000, 0x018F, t<<6);	
	}
}
void blue_dark_heng(void)
{
	unsigned int t;
	for(t=0;t<=0x018f;t+=1)
	{
		Show(0,0x00ef,t,t, t);	
	}
}	
void red_dark_heng(void)
{
	unsigned int t;
	for(t=0;t<=0x018f;t+=1)
	{
		Show(0,0x00ef,t,t, t<<11);	
	}
}	
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
	A0 = 0;
	P2 = dat >> 8;
	P1 = dat & 0xFF;
	_WR = 0;
	_WR = 1;
}
//---------------------------------------------------------------------------
void W_DATA(UINT dat)
{
	A0 = 1;
	P2 = dat >> 8;
	P1 = dat & 0xFF;
	_WR = 0;
	_WR = 1;
}
/**************************************************
块写入函数
参数说明：起点横坐标，终点横坐标，
		  起点纵坐标，终点纵坐标
作用：在屏里画一矩形区域，为数据更新区间，调用该
	  函数之后，可以向该区间写入新的数据。
**************************************************/
void BlockWrite(UINT sx, UINT ex, UINT sy, UINT ey)
{
	W_COM(0x0210);
	W_DATA(sx);
	W_COM(0x0211);
	W_DATA(ex);
	W_COM(0x0212);
	W_DATA(sy);
	W_COM(0x0213);
	W_DATA(ey);

	W_COM(0x0200);
	W_DATA(0);
	W_COM(0x0201);
	W_DATA(0);

	W_COM(0x0202);
}
//---------------------------------------------------------------------------
void Clear(void)
{	Show(0x0000, 0x00EF, 0x0000, 0x018F, 0x0000);	}
void Full(void)
{	Show(0x0000, 0x00EF, 0x0000, 0x018F, 0xFFFF);	}
void Red(UINT sx, UINT ex, UINT sy, UINT ey)
{	Show(sx, ex,sy,ey, 0xF800);	}
void Green(UINT sx, UINT ex, UINT sy, UINT ey)
{	Show(sx, ex,sy,ey, 0x07E0);	}
void Blue(UINT sx, UINT ex, UINT sy, UINT ey)
{	Show(sx, ex,sy,ey, 0x001F);	}


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
void SPFD5420A_CPT30W_Initial(void)
{
	_RD = 1;
	P0=0xf0;
	_RES = 1;
	Delay(10);
	_RES = 0;
	Delay(50);
	_RES = 1;
	Delay(10);
	
	W_COM(0x0606); W_DATA(0x0000);
	Delay(100);
	W_COM(0x0606); W_DATA(0x0000);
	Delay(5);
	W_COM(0x0007); W_DATA(0x0001);
	Delay(5);
	W_COM(0x0110); W_DATA(0x0001);
	Delay(5);
	
	W_COM(0x0100); W_DATA(0x17B0);
	W_COM(0x0101); W_DATA(0x0147);
	W_COM(0x0102); W_DATA(0x019D);
	W_COM(0x0103); W_DATA(0x2F00);
	W_COM(0x0281); W_DATA(0x0001);
	Delay(5);
	
	W_COM(0x0102); W_DATA(0x01BD);
	Delay(5);
	
	W_COM(0x0000); W_DATA(0x0000);
	W_COM(0x0001); W_DATA(0x0100);
	W_COM(0x0002); W_DATA(0x0100);
	W_COM(0x0003); W_DATA(0x10B0);
	W_COM(0x0008); W_DATA(0x0808);
	W_COM(0x0009); W_DATA(0x0001);
	W_COM(0x000B); W_DATA(0x0010);
	W_COM(0x000C); W_DATA(0x0000);
	W_COM(0x000F); W_DATA(0x0000);
	W_COM(0x0010); W_DATA(0x0014);
	W_COM(0x0011); W_DATA(0x0202);
	W_COM(0x0012); W_DATA(0x0300);
	W_COM(0x0020); W_DATA(0x021E);
	W_COM(0x0021); W_DATA(0x0202);
	W_COM(0x0022); W_DATA(0x0100);

	W_COM(0x0090); W_DATA(0x8000);
	W_COM(0x0092); W_DATA(0x0000);
	W_COM(0x0100); W_DATA(0x17B0);
	W_COM(0x0101); W_DATA(0x0147);
	W_COM(0x0102); W_DATA(0x01B8);
	W_COM(0x0103); W_DATA(0x2C00);
	W_COM(0x0107); W_DATA(0x0000);
	W_COM(0x0110); W_DATA(0x0001);
	W_COM(0x0210); W_DATA(0x0000);
	W_COM(0x0211); W_DATA(0x00EF);
	W_COM(0x0212); W_DATA(0x0000);
	W_COM(0x0213); W_DATA(0x018F);
	W_COM(0x0200); W_DATA(0x0000);
	W_COM(0x0201); W_DATA(0x0000);
	W_COM(0x0280); W_DATA(0x0000);
	W_COM(0x0281); W_DATA(0x0000);
	W_COM(0x0282); W_DATA(0x0000);

	W_COM(0x0300); W_DATA(0x0501); //GAMMA Control
	W_COM(0x0301); W_DATA(0x0C2F);
	W_COM(0x0302); W_DATA(0x0D33);
	W_COM(0x0303); W_DATA(0x330D);
	W_COM(0x0304); W_DATA(0x2F0C);
	W_COM(0x0305); W_DATA(0x0105);
	W_COM(0x0306); W_DATA(0x030A);
	W_COM(0x0307); W_DATA(0x0A03);
	W_COM(0x0308); W_DATA(0x0006);
	W_COM(0x0309); W_DATA(0x0004);
	W_COM(0x030A); W_DATA(0x0E05);
	W_COM(0x030B); W_DATA(0x0E01);
	W_COM(0x030C); W_DATA(0x010E);
	W_COM(0x030D); W_DATA(0x050E);
	W_COM(0x030E); W_DATA(0x0400);
	W_COM(0x030F); W_DATA(0x0600);

	W_COM(0x0400); W_DATA(0x3500); //Base Image Number of Line
	W_COM(0x0401); W_DATA(0x0001); //Base Image Display Control
	W_COM(0x0404); W_DATA(0x0000); //Base Image Vertical Scroll Control
	W_COM(0x0500); W_DATA(0x0000);
	W_COM(0x0501); W_DATA(0x0000);
	W_COM(0x0502); W_DATA(0x0000);
	W_COM(0x0503); W_DATA(0x0000);
	W_COM(0x0504); W_DATA(0x0000);
	W_COM(0x0505); W_DATA(0x0000);
	W_COM(0x0600); W_DATA(0x0000); //
	W_COM(0x0606); W_DATA(0x0000); //
	W_COM(0x06F0); W_DATA(0x0000); //

	W_COM(0x07F0); W_DATA(0x5420);
	W_COM(0x07F2); W_DATA(0x00DF);
	W_COM(0x07F3); W_DATA(0x2890);
	W_COM(0x07F4); W_DATA(0x0022);
	W_COM(0x07F5); W_DATA(0x0011);
	W_COM(0x07F0); W_DATA(0x0000);

	W_COM(0x0007); W_DATA(0x0173); //Display Control 1
	Delay(200);
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
//---------------------------------------------------------------------------

void ShowGradualColor(void)
{
	unsigned int i, j, k;

	for ( i = 0; i <= 399; i++ )		
	{
		k = 0;
		for ( j = 0; j <= 239; j++ );
//			W_DATA(GradualColor[k++]);
	}
}
//---------------------------------------------------------------------------
void Sleep_In(void)
{
	W_COM(0x0007); W_DATA(0x0170);
	Delay(50);
	W_COM(0x0007); W_DATA(0x0000);//Display off
	Delay(50);
	W_COM(0x0100); W_DATA(0x16B2);//Set to sleep mode
}
//---------------------------------------------------------------------------
void Sleep_Out(void)
{
	W_COM(0x0100); W_DATA(0x16B0);//Release state
	W_COM(0x0007); W_DATA(0x0173);
}
//---------------------------------------------------------------------------

#endif
//---------------------------------------------------------------------------
/*
KGM701A9: 16bit interface
VDD : 2.8~3.3V
DB7-DB0 : P1
DB15-DB8 : P2
RS : P3.0
WR: P3.1
RD  : P3.2
RESET : P3.3
CS : Connect to GND
FMARK : Not Connect
*/

#include "reg52.h"
#include "font.h"
#include "string.h"
typedef bit uint1;
typedef unsigned char uint8, uchar, UCHAR;
typedef unsigned int uint16, uint, UINT;
typedef unsigned long uint32, ulong, ULONG;

unsigned char code sintable[]={
0,2,4,6,7,9,11,13,15,17,19,21,22,24,26,28,30,31,33,35,37,39,40,42,44,46,47,49,51,52,54,56,57,59,61,62,64,65,67,69,70,72,73,75,76,77,79,80,82,83,84,86,87,88,89,91,92,93,94,95,96,98,99,100,101,102,103,104,104,105,106,107,108,109,109,110,111,111,112,113,113,114,114,115,115,116,116,117,117,117,118,118,118,118,119,119,119,119,119,119,119,119,119,119,119,119,118,118,118,118,117,117,117,116,116,116,115,115,114,114,113,112,112,111,110,110,109,108,107,107,106,105,104,103,102,101,100,99,98,97,96,95,94,92,91,90,89,88,86,85,84,82,81,80,78,77,75,74,72,71,69,68,66,65,63,62,60,58,57,55,53,52,50,48,47,45,43,41,40,38,36,34,32,31,29,27,25,23,21,20,18,16,14,12,10,8,7,5,3,1,-1,-3,-5,-7,-8,-10,-12,-14,-16,-18,-20,-21,-23,-25,-27,-29,-31,-32,-34,-36,-38,-40,-41,-43,-45,-47,-48,-50,-52,-53,-55,-57,-58,-60,-62,-63,-65,-66,-68,-69,-71,-72,-74,-75,-77,-78,-80,-81,-82,-84,-85,-86,-88,-89,-90,-91,-92,-94,-95,-96,-97,-98,-99,-100,-101,-102,-103,-104,-105,-106,-107,-107,-108,-109,-110,-110,-111,-112,-112,-113,-114,-114,-115,-115,-116,-116,-116,-117,-117,-117,-118,-118,-118,-118,-119,-119,-119,-119,-119,-119,-119,-119,-119,-119,-119,-119,-118,-118,-118,-118,-117,-117,-117,-116,-116,-115,-115,-114,-114,-113,-113,-112,-111,-111,-110,-109,-109,-108,-107,-106,-105,-104,-104,-103,-102,-101,-100,-99,-98,-96,-95,-94,-93,-92,-91,-89,-88,-87,-86,-84,-83,-82,-80,-79,-77,-76,-75,-73,-72,-70,-69,-67,-65,-64,-62,-61,-59,-57,-56,-54,-52,-51,-49,-47,-46,-44,-42,-40,-39,-37,-35,-33,-31,-30,-28,-26,-24,-22,-21,-19,-17,-15,-13,-11,-9,-7,-6,-4,-2,0,
};

//---------------------------------------------------------------------------
sbit A0=P3^0;//RS, DC
sbit _WR=P3^1;
sbit _RD=P3^2;
sbit _RES=P3^3;

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


/*******************kkk*****************/
void sin(void)
{
	unsigned int x,y;
	for(y=0;y<4;y++)
	{
		for(x=0;x<400;x++)
		{	
			BlockWrite(sintable[x]+119,sintable[x]+119,x+y,x+y);
			W_DATA(0xf800);
		}
		Delay(100);
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
void juxing(UINT x0,UINT y0,UINT x1,UINT y1,UINT color)
{
	drawline(x0,x1,y1,y1,color);
	drawline(x0,x1,y0,y0,color);
	drawline(x1,x1,y0,y1,color);
	drawline(x0,x0,y0,y1,color);
	
}

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
void main(void)
{
	_RD = 1;
	P0=0xf0;
	_RES = 1;
	Delay(10);
	_RES = 0;
	Delay(50);
	_RES = 1;
	Delay(10);
	SPFD5420A_CPT30W_Initial();
	Clear();
	juxing(0,0,239,40,0x07e0);
	Blue(1,238,1,39);
	ShowString(1,1,"Hello ,world!!!");
	ShowString(1,17,"My name is KKK!!!");
	Delay(10000);
	Clear();
	juxing(0,0,239,20,0x07e0);
	Blue(1,238,1,19);
	ShowString(1,1,"Now let's have a look!");
	Delay(10000);
	while(1)
	{
		blue_dark_zong();
		Delay(1000);
		red_dark_heng();
		Delay(1000);
		green_dark_zong();
		Delay(1000);
		blue_dark_heng();
		Delay(1000);
		red_dark_zong();
		Delay(1000);
		green_dark_heng();
		Delay(10000);		
		Clear();
		drawline(0,0x00ef,0,0x018f,0xffff);
		Delay(1000);
		drawline(0,0x00ef,0,0x018f,0xffff);
		Delay(1000);
		drawline(0,0,0,399,0xffff);
		drawline(239,239,0,399,0xffff);
		drawline(0,239,0,0,0xffff);
		drawline(0,239,399,399,0xffff);
		Delay(10000);
		Clear();
		sin();
		Delay(1000);
		Clear();
//		show_pic(gImage_1,0,0,49,49);

//		show_pic(gImage_1,40,40,60,40);
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
//---------------------------------------------------------------------------
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
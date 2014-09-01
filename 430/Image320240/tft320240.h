#ifndef _kkk_tft320240_h
#define _kkk_tft320240_h
#include "msp430x14x.h"
/*****************************************
KGM726H6 - 8 interface
LCD PART:
IM0 - Connect to VCC(Select 8 bit interface)
IM3 - Fixed to GND
VCC1/VCC2/VCI - Connect together with 2.8~3.3V
CS - Connect to GND
RS - P2.0
WR - P2.1
RD - Connect to VDD
RESET - P2.2
DB17-DB10 - P1
DB7-DB0 - Not Connect
*******************************************/

typedef unsigned char uint8, uchar, UCHAR;
typedef unsigned int uint16, uint, UINT;
typedef unsigned long uint32, ulong, ULONG;

#define LCD_RS 0x01
#define LCD_WR 0x02
#define LCD_RESET 0x04
#define DATAPORT P3OUT
#define DATADIR  P3DIR
#define CTRLPORT P2OUT
#define CTRLDIR  P2DIR

extern void Delay(UINT t);
extern void W_COM(UINT dat);
extern void W_DATA(UINT dat);
extern void SPFD5408A_CPT24_Initial(void);
extern void Clear(void);
extern void Full(void);
extern void Red(void);
extern void Green(void);
extern void Blue(void);
extern void Show(UINT sx, UINT ex, UINT sy, UINT ey, UINT dat);
extern void BlockWrite(UINT sx, UINT ex, UINT sy, UINT ey);

extern void show_pic(const unsigned char * table,UINT x0,UINT y0,UINT width,UINT height);
extern void show_pic_ext(const unsigned char * table,UINT x0,UINT y0,UINT width,UINT height);
//Text Function
extern void ShowCharWithColor(UCHAR sx, UINT sy, UCHAR index, UINT CharColor, UINT BkColor);
extern void ShowString(UCHAR sx, UINT sy, char* string);
extern void drawline(int sx, int ex, int sy, int ey,UINT linecolor);
extern void ShowHanzi(UCHAR sx, UINT sy, UCHAR index, UINT CharColor, UINT BkColor);
#endif
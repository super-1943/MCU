#ifndef _kkk_tft320240_h
#define _kkk_tft320240_h
#include "reg52.h"

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
typedef unsigned short UINT;
typedef unsigned char UCHAR;


#define LCD_RS 0x01
#define LCD_WR 0x02
#define LCD_RESET 0x04
#define DATAPORT P1
#define DATADIR  P1
#define CTRLPORT P2
#define CTRLDIR  P2

extern void tft320240_delay(UINT t);
extern void tft320240_W_COM(UINT dat);
extern void tft320240_W_DATA(UINT dat);
extern void tft320240_initial(void);
extern void tft320240_clear(void);

extern void tft320240_show(UINT sx, UINT ex, UINT sy, UINT ey, UINT dat);
extern void tft320240_blockwrite(UINT sx, UINT ex, UINT sy, UINT ey);

//Text Function
extern void tft320240_show_colorchar(UCHAR sx, UINT sy, UCHAR index, UINT CharColor, UINT BkColor);
extern void tft320240_show_string(UCHAR sx, UINT sy, char* string);
extern void tft320240_drawline(int sx, int ex, int sy, int ey,UINT linecolor);
extern void tft320240_show_hanzi(UCHAR sx, UINT sy, UCHAR index, UINT CharColor, UINT BkColor);
#endif
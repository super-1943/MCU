#ifndef _kkk_clock_h
#define _kkk_clock_h
#include "tft320240.h"
#define COLOR_RED  0xf800
#define COLOR_GREEN 0x07e0
#define COLOR_BLUE 0x001f
#define COLOR_BACK COLOR_RED+COLOR_GREEN
#define COLOR_HOUR 1500
#define COLOR_MINU 2000
#define COLOR_SECN 2250
#define COLOR_NUMB 0xf800

#define LEN_RADIUS 75
#define LEN_HOUR   30
#define LEN_MINU   45
#define LEN_SECN   60

#define CENTER_X   120
#define CENTER_Y   200


extern void drawclock(void);
extern void move_second(unsigned char dlast,unsigned char dthis);
extern void move_minute(unsigned char dlast,unsigned char dthis);
extern void move_hour(unsigned char dlast,unsigned char dthis);
#endif
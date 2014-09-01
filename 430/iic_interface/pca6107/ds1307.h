#ifndef _kkk_ds1307_h
#define _kkk_ds1307_h
#define uchar unsigned char 
#define uint unsigned int 
struct Timer
{
  uchar hour;
  uchar minute;
  uchar second;
  uchar year;
  uchar month;
  uchar date;
  uchar week;
};
void get_time(struct Timer *pt);
void set_time(struct Timer *pt);


#endif
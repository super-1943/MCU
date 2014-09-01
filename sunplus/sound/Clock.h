#ifndef	__CLOCK_h__
#define	__CLOCK_h__
//	write your header here
extern void Clock_ISR();
extern void Clock_Start();
extern unsigned int Clock_GetYear();
extern unsigned int Clock_GetMon();
extern unsigned int Clock_GetDay();
extern unsigned int Clock_GetHour();
extern unsigned int Clock_GetMin();
extern unsigned int Clock_GetSec();
extern void Clock_SetYear(unsigned int Year);
extern void Clock_SetMon(unsigned int Mon);
extern void Clock_SetDay(unsigned int Day);
extern void Clock_SetHour(unsigned int Hour);
extern void Clock_SetMin(unsigned int Min);
extern void Clock_SetSec(unsigned int Sec);

extern const unsigned int Month_Day[12];
#endif

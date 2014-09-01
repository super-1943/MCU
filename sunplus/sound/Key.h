#ifndef	__KEY_h__
#define	__KEY_h__
//	write your header here

void Key_Init(void);
void Key_Scan(void);
unsigned Key_Get(void);

#define KEY_1			0x0001
#define KEY_2			0x0002
#define KEY_3			0x0004
#define KEY_LONG_1		0x8001
#define KEY_LONG_2		0x8002
#define KEY_LONG_3		0x8004

#endif

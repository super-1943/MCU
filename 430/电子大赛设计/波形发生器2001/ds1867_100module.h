#ifndef ds1867_100_module_h
#define ds1867_100_module_h
void delay_1867(unsigned int ms);
void init_1867_100(void);
void send_bit_1867(unsigned char i);
void send_1867(unsigned char stack,unsigned char W0,unsigned char W1);//��һ������ѡ��Ƭ���ڶ���������W0��ֵ(0-255),����������W1��ֵ(0-255)
#endif
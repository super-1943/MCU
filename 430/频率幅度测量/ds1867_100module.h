#ifndef ds1867_100_module_h
#define ds1867_100_module_h
void delay_1867(unsigned int ms);
void init_1867_100(void);
void send_bit_1867(unsigned char i);
void send_1867(unsigned char stack,unsigned char W0,unsigned char W1);//第一个参数选择划片，第二个参数给W0赋值(0-255),第三个参数W1赋值(0-255)
#endif
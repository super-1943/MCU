#ifndef MAX507_2009
#define MAX507_2009

#define CONTROL_DIR P5DIR
#define CONTROL_OUT P5OUT
#define CS_0 P5OUT&=~(BIT0)
#define CS_1 P5OUT|=BIT0
#define WR_0 P5OUT&=~(BIT1)
#define WR_1 P5OUT|=BIT1
#define LDAC_0 P5OUT&=~(BIT2)
#define LDAC_1 P5OUT|=BIT2
#define CLR_0 P5OUT&=~(BIT3)
#define CLR_1 P5OUT|=BIT3

#define DAT_LSB_DIR P1DIR
#define DAT_LSB_OUT P1OUT
#define DAT_MSB_DIR P6DIR
#define DAT_MSB_OUT P6OUT

void delay(unsigned int i);
void init_device(void);
/***************************************************
����˵������DAC��д������
����˵����lsbΪ�Ͱ�λ��msb�ĵ���λ��Ϊdac���ݵĸ���λ
****************************************************/

void write_data_input(unsigned char lsb,unsigned char msb);
void write_data_DAC(void);
#endif
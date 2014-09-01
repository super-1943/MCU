/************************************************************************
IIC通信实验——无线电协会msp430f1491学习板
作者：赵永科
日期：2009-7-23
函数作用：实现基本iic通信
************************************************************************/

#ifndef _kkk_iic_h
#define _kkk_iic_h
void iic_init(void);
void iic_start(void);
void iic_stop(void);
void iic_send_byte(unsigned char d);
void iic_send_ack(void);
void iic_send_nack(void);
unsigned char iic_read_ack(void);
unsigned char iic_read_byte(void);


#define SDA_Mask 0x20
#define SCL_Mask 0x40
#define SDA_Dir  P1DIR
#define SCL_Dir  P1DIR
#define SDA_0 P1OUT&=~SDA_Mask
#define SDA_1 P1OUT|=SDA_Mask
#define SCL_0 P1OUT&=~SCL_Mask
#define SCL_1 P1OUT|=SCL_Mask
#define DataIn P1IN
#endif
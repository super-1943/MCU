/************************************************************************
IICͨ��ʵ�顪�����ߵ�Э��msp430f1491ѧϰ��
���ߣ�������
���ڣ�2009-7-23
�������ã�ʵ�ֻ���iicͨ��
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


#endif
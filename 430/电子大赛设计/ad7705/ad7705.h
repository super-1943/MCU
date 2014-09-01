#ifndef _AD7705_H_
  #define _AD7705_H_
#include "msp430x16x.h"
#define AD7705_SCLK_1     P5OUT|=0x80
#define AD7705_SCLK_0     P5OUT&=~0x80
#define AD7705_DIN_1      P5OUT|=0x40
#define AD7705_DIN_0      P5OUT&=~0x40

#define AD7705_DRDY       (P5IN&0x02)
#define AD7705_DOUT       (P5IN&0x01)

// ͨѶ�Ĵ�����ַ����
  #define   RD_COMM_REG            0x08       //ѡ��ͨѶ�Ĵ�������
  #define   WR_SETUP_REG           0x10       //ѡ�����üĴ�����д
  #define   RD_SETUP_REG           0x18       //ѡ�����üĴ�������
  #define   WR_CLOCK_REG           0x20       //ѡ��ʱ�ӼĴ�����д
  #define   RD_CLOCK_REG           0x28       //ѡ��ʱ�ӼĴ�������
  #define   RD_DATA_REG            0x38       //ѡ�����ݼĴ�������
  #define   RD_TEST_REG            0x48       //ѡ�в��ԼĴ�������
  #define   WR_TEST_REG            0x40       //ѡ�в��ԼĴ�����д
  #define   WR_OFFSET_REG          0x60       //ѡ��offset�Ĵ�����д
  #define   RD_OFFSET_REG          0x68       //ѡ��offset�Ĵ�������
  #define   WR_FULL_REG            0x70       //ѡ��full scale�Ĵ�����д
  #define   RD_FULL_REG            0x78       //ѡ��full scale�Ĵ�������

  #define   SYS_ZERO_CALI          0x80       //ϵͳ��У׼ģʽ
  #define   SYS_FULL_CALI          0xC0       //ϵͳ������У׼ģʽ

  #define   ZERO_CALIBRATION       0x00       //ϵͳ��У׼
  #define   FULL_CALIBRATION       0x01       //ϵͳ������У׼

  #define   CLOCK_REG_SET          0x04       //CLOCK�Ĵ������ã��޷�Ƶ��50HZ�����������

  #define   DELAY                  _NOP()
 
  // ��������
  void  AD7705_Init(void);
  void  AD7705_Reset(void);
  void  AD7705_Start(void);
  void AD7705_Initsss(void);
  unsigned int AD7705_Result(void);
  unsigned char AD7705_ReadByte(void);
  void  AD7705_WriteByte(unsigned char d);

  float AD7705_ReadVol(void);
  void delay_ms(unsigned int t);
#endif

#ifndef _AD7705_H_
  #define _AD7705_H_
#include "msp430x16x.h"
#define AD7705_SCLK_1     P5OUT|=0x80
#define AD7705_SCLK_0     P5OUT&=~0x80
#define AD7705_DIN_1      P5OUT|=0x40
#define AD7705_DIN_0      P5OUT&=~0x40

#define AD7705_DRDY       (P5IN&0x02)
#define AD7705_DOUT       (P5IN&0x01)

// 通讯寄存器地址定义
  #define   RD_COMM_REG            0x08       //选中通讯寄存器，读
  #define   WR_SETUP_REG           0x10       //选中设置寄存器，写
  #define   RD_SETUP_REG           0x18       //选中设置寄存器，读
  #define   WR_CLOCK_REG           0x20       //选中时钟寄存器，写
  #define   RD_CLOCK_REG           0x28       //选中时钟寄存器，读
  #define   RD_DATA_REG            0x38       //选中数据寄存器，读
  #define   RD_TEST_REG            0x48       //选中测试寄存器，读
  #define   WR_TEST_REG            0x40       //选中测试寄存器，写
  #define   WR_OFFSET_REG          0x60       //选中offset寄存器，写
  #define   RD_OFFSET_REG          0x68       //选中offset寄存器，读
  #define   WR_FULL_REG            0x70       //选中full scale寄存器，写
  #define   RD_FULL_REG            0x78       //选中full scale寄存器，读

  #define   SYS_ZERO_CALI          0x80       //系统零校准模式
  #define   SYS_FULL_CALI          0xC0       //系统满量程校准模式

  #define   ZERO_CALIBRATION       0x00       //系统零校准
  #define   FULL_CALIBRATION       0x01       //系统满量程校准

  #define   CLOCK_REG_SET          0x04       //CLOCK寄存器设置，无分频，50HZ输出更新速率

  #define   DELAY                  _NOP()
 
  // 函数声明
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

#include "ad7705.h"
//****************************************************************************
//功能：AD7705串行接口失步后将其复位。复位后要延时500us再访问
//参数：无
//返回：无
//备注：
//****************************************************************************
void delay_ms(unsigned int i)
{
  unsigned int t;
  while(i--)
  {
    for(t=2000;t;t--);
  }
}

void AD7705_Initsss(void)
{
  extern unsigned char i;
  AD7705_Reset();
  AD7705_WriteByte(WR_SETUP_REG); 
  AD7705_WriteByte(0x44);
  AD7705_WriteByte(RD_SETUP_REG); 
  i=AD7705_ReadByte();
  AD7705_WriteByte(WR_CLOCK_REG); 
  AD7705_WriteByte(0x08);
  AD7705_WriteByte(RD_CLOCK_REG); 
  i=AD7705_ReadByte();
  AD7705_WriteByte(RD_TEST_REG); 
  i=AD7705_ReadByte();
  i=i;
}


unsigned int AD7705_Result(void)
{
    unsigned int t=0;
    AD7705_Reset();    
    AD7705_WriteByte(WR_SETUP_REG); 
    delay_ms(10);
    AD7705_WriteByte(0x44);
    delay_ms(10);
    while(AD7705_DRDY);
    delay_ms(10);
    AD7705_WriteByte(RD_DATA_REG); 
    delay_ms(10);
    t|=(AD7705_ReadByte()<<8);
    t|=AD7705_ReadByte();
    return t;
}




void AD7705_Reset(void)
{
  unsigned char i;
  P5DIR|=0xc0;
  for( i=0; i<36; i++ )
  {
    AD7705_SCLK_0;
    AD7705_DIN_1;    // DIN端口连续写36个周期的高电平，保证复位
    DELAY;
    AD7705_SCLK_1;
    DELAY; 
  } 
  delay_ms(10);    // 复位之后等待1MS          
}


//****************************************************************************
//功能：从AD7705读一个字节的数据
//参数：无
//返回：读到的一字节数据
//备注：无
//****************************************************************************
unsigned char AD7705_ReadByte(void)
{
  unsigned char i, d=0;
  // 读数据，高位在前
  for( i=0; i<8; i++ )
  {
    d<<= 1;
    AD7705_SCLK_0; 
    DELAY;
    if(AD7705_DOUT) d++;
    AD7705_SCLK_1; 
    DELAY;
  } 
  return d; 
}


//****************************************************************************
//功能：往AD7705写1个字节数据
//参数：要写入AD7705的数据
//返回：无
//备注：无
//****************************************************************************
void AD7705_WriteByte(unsigned char d)
{
  unsigned char i;
  for(i=0; i<8; i++)
  {
    AD7705_SCLK_0;
    if(d & 0x80) 
      AD7705_DIN_1;
    else       
      AD7705_DIN_0; 
	DELAY;
    AD7705_SCLK_1; 
    DELAY;
	d <<= 1;
  } 
}

//------------------------------------------------------------------------------------------
//功能：先写offset寄存器，再写full scale寄存器，然后启动7705进行单次转换
//参数：
//返回：无
//备注：
//------------------------------------------------------------------------------------------
void AD7705_Start(void)
{
  // 复位，防止接口迷失
  AD7705_Reset();
  
  // 复位之后一定要重新设置各寄存器，复位之后默认状态为等待对通信寄存器的一次操作
  // 遵循先写命令，后写数据的原则，命令默认写到通信寄存器

  //写OFFSET寄存器
  AD7705_WriteByte(WR_OFFSET_REG);
  AD7705_WriteByte(0xFF);
  AD7705_WriteByte(0xFF);
  AD7705_WriteByte(0xFF);
  AD7705_WriteByte(0xFF);

  //写满量程校准寄存器
  AD7705_WriteByte(WR_FULL_REG);
  AD7705_WriteByte(0xFF);
  AD7705_WriteByte(0xFF);
  AD7705_WriteByte(0xFF);
  AD7705_WriteByte(0xFF);

  AD7705_WriteByte(WR_CLOCK_REG);  // next write to clock reg,AIN1,  0010 0000
  AD7705_WriteByte(0x00);          // CLKDIS=0,CLKDIV=0,CLK=0,FS1=0,FS2=0  0001 0000

  AD7705_WriteByte(WR_SETUP_REG);  // next write to setup reg,AIN1   0001 0000
  AD7705_WriteByte(0x04);          // 正常状态启动装换,GAIN=1,B/U=0,BUF=0,FSYNC=0，增益=1,双极性
}
  
void AD7705_Init(void)
{
  // 复位，防止接口迷失
  AD7705_Reset();  

  AD7705_WriteByte(WR_CLOCK_REG);  // next write to clock reg,AIN1,  0010 0000
  AD7705_WriteByte(0x10);          // CLKDIS=0,CLKDIV=0,CLK=0,FS1=0,FS2=0  0001 0000
                                   // 外部主时钟频率为2.4576MHz

  AD7705_WriteByte(WR_SETUP_REG);  // next write to setup reg,AIN1   0001 0000
  AD7705_WriteByte(0x44);          // SELF-CAL,GAIN=1,B/U=0,BUF=0,FSYNC=0，自校准模式，增益=1,双极性
} 
 
float AD7705_ReadVol(void)
{
  unsigned char adc_1_h=0, adc_1_l=0;
  unsigned int    ADValue = 0;
  float   vol;

  AD7705_Start();
  while(AD7705_DRDY);
  AD7705_WriteByte(RD_DATA_REG);    //READ FROM DATA REG,AIN1
  adc_1_h=AD7705_ReadByte();
  adc_1_l=AD7705_ReadByte();

  ADValue |=  adc_1_h;
  ADValue <<= 8;
  ADValue |=  adc_1_l;

  vol = ADValue / 65535.0 * 2480;
  return vol;   
} 


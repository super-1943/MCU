#include "ad7705.h"
//****************************************************************************
//���ܣ�AD7705���нӿ�ʧ�����临λ����λ��Ҫ��ʱ500us�ٷ���
//��������
//���أ���
//��ע��
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
    AD7705_DIN_1;    // DIN�˿�����д36�����ڵĸߵ�ƽ����֤��λ
    DELAY;
    AD7705_SCLK_1;
    DELAY; 
  } 
  delay_ms(10);    // ��λ֮��ȴ�1MS          
}


//****************************************************************************
//���ܣ���AD7705��һ���ֽڵ�����
//��������
//���أ�������һ�ֽ�����
//��ע����
//****************************************************************************
unsigned char AD7705_ReadByte(void)
{
  unsigned char i, d=0;
  // �����ݣ���λ��ǰ
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
//���ܣ���AD7705д1���ֽ�����
//������Ҫд��AD7705������
//���أ���
//��ע����
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
//���ܣ���дoffset�Ĵ�������дfull scale�Ĵ�����Ȼ������7705���е���ת��
//������
//���أ���
//��ע��
//------------------------------------------------------------------------------------------
void AD7705_Start(void)
{
  // ��λ����ֹ�ӿ���ʧ
  AD7705_Reset();
  
  // ��λ֮��һ��Ҫ�������ø��Ĵ�������λ֮��Ĭ��״̬Ϊ�ȴ���ͨ�żĴ�����һ�β���
  // ��ѭ��д�����д���ݵ�ԭ������Ĭ��д��ͨ�żĴ���

  //дOFFSET�Ĵ���
  AD7705_WriteByte(WR_OFFSET_REG);
  AD7705_WriteByte(0xFF);
  AD7705_WriteByte(0xFF);
  AD7705_WriteByte(0xFF);
  AD7705_WriteByte(0xFF);

  //д������У׼�Ĵ���
  AD7705_WriteByte(WR_FULL_REG);
  AD7705_WriteByte(0xFF);
  AD7705_WriteByte(0xFF);
  AD7705_WriteByte(0xFF);
  AD7705_WriteByte(0xFF);

  AD7705_WriteByte(WR_CLOCK_REG);  // next write to clock reg,AIN1,  0010 0000
  AD7705_WriteByte(0x00);          // CLKDIS=0,CLKDIV=0,CLK=0,FS1=0,FS2=0  0001 0000

  AD7705_WriteByte(WR_SETUP_REG);  // next write to setup reg,AIN1   0001 0000
  AD7705_WriteByte(0x04);          // ����״̬����װ��,GAIN=1,B/U=0,BUF=0,FSYNC=0������=1,˫����
}
  
void AD7705_Init(void)
{
  // ��λ����ֹ�ӿ���ʧ
  AD7705_Reset();  

  AD7705_WriteByte(WR_CLOCK_REG);  // next write to clock reg,AIN1,  0010 0000
  AD7705_WriteByte(0x10);          // CLKDIS=0,CLKDIV=0,CLK=0,FS1=0,FS2=0  0001 0000
                                   // �ⲿ��ʱ��Ƶ��Ϊ2.4576MHz

  AD7705_WriteByte(WR_SETUP_REG);  // next write to setup reg,AIN1   0001 0000
  AD7705_WriteByte(0x44);          // SELF-CAL,GAIN=1,B/U=0,BUF=0,FSYNC=0����У׼ģʽ������=1,˫����
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


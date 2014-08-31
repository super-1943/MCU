#include "sd.h"
#include "myfun.h" //�������ϵĹ�������ͷ�ļ�

/*******************************************************

        +-------------------------------------+
        |  ���ϵ���  �߼���Դ����  SD�� ����  |
        +-------------------------------------+

  ��Դ���Ȩ�� ���� ȫȨ���У��������ã�������������֪
        �Ͻ�����������ҵĿ�ģ�Υ�߱ؾ�������Ը�
         ���ϵ��� 
             ->��Ʒ��վ http://www.znmcu.cn/
             ->��Ʒ���� http://shop.znmcu.cn/
             ->��Ʒ��ѯ QQ :987582714 
			            MSN:yzn07@126.com
	                    WW :yzn07				  
********************************************************/

//��������
//--------------------------------------------------------------
bit is_init;        //�ڳ�ʼ����ʱ�����ô˱���Ϊ1,ͬ�����ݴ��䣨SPI�������
//---------------------------------------------------------------

unsigned char bdata _dat;
sbit _dat7=_dat^7;
sbit _dat6=_dat^6;
sbit _dat5=_dat^5;
sbit _dat4=_dat^4;
sbit _dat3=_dat^3;
sbit _dat2=_dat^2;
sbit _dat1=_dat^1;
sbit _dat0=_dat^0;

/******************************************************************
 - ����������IOģ��SPI������һ���ֽ�
 - ����ģ�飺SD��ģ��
 - �������ԣ��ڲ�
 - ����˵����x��Ҫ���͵��ֽ�
 - ����˵�����޷���
 - ע������is_initΪ1ʱ��д���ٶȷ�������ʼ��SD��SPI�ٶȲ���̫��
 ******************************************************************/

void SD_spi_write(unsigned char x) 
{
 _dat=x;
 
 SD_SI=_dat7;
 SD_SCL=0; 
 if(is_init) delay(DELAY_TIME); 
 SD_SCL=1;
 if(is_init) delay(DELAY_TIME);

 SD_SI=_dat6;
 SD_SCL=0; 
 if(is_init) delay(DELAY_TIME); 
 SD_SCL=1;
 if(is_init) delay(DELAY_TIME);

 SD_SI=_dat5;
 SD_SCL=0;
 if(is_init) delay(DELAY_TIME);
 SD_SCL=1;
 if(is_init) delay(DELAY_TIME);

 SD_SI=_dat4;
 SD_SCL=0;
 if(is_init) delay(DELAY_TIME); 
 SD_SCL=1;
 if(is_init) delay(DELAY_TIME);

 SD_SI=_dat3;
 SD_SCL=0; 
 if(is_init) delay(DELAY_TIME); 
 SD_SCL=1;
 if(is_init) delay(DELAY_TIME);

 SD_SI=_dat2;
 SD_SCL=0;
 if(is_init) delay(DELAY_TIME); 
 SD_SCL=1;
 if(is_init) delay(DELAY_TIME);

 SD_SI=_dat1;
 SD_SCL=0; 
 if(is_init) delay(DELAY_TIME); 
 SD_SCL=1;
 if(is_init) delay(DELAY_TIME);

 SD_SI=_dat0;
 SD_SCL=0;
 if(is_init) delay(DELAY_TIME);  
 SD_SCL=1;
 if(is_init) delay(DELAY_TIME);
}

/******************************************************************
 - ����������IOģ��SPI����ȡһ���ֽ�
 - ����ģ�飺SD��ģ��
 - �������ԣ��ڲ�
 - ����˵������
 - ����˵�������ض������ֽ�
 ******************************************************************/

unsigned char SD_spi_read() //SPI��һ���ֽ�
{  
 SD_SO=1;

 SD_SCL=1;
 if(is_init) delay(DELAY_TIME);
 SD_SCL=0;
 if(is_init) delay(DELAY_TIME); 
 _dat7=SD_SO; 

 SD_SCL=1;
 if(is_init) delay(DELAY_TIME);
 SD_SCL=0;
 if(is_init) delay(DELAY_TIME);
 _dat6=SD_SO; 

 SD_SCL=1;
 if(is_init) delay(DELAY_TIME);
 SD_SCL=0;
 if(is_init) delay(DELAY_TIME);
 _dat5=SD_SO; 

 SD_SCL=1;
 if(is_init) delay(DELAY_TIME);
 SD_SCL=0;
 if(is_init) delay(DELAY_TIME);
 _dat4=SD_SO; 

 SD_SCL=1;
 if(is_init) delay(DELAY_TIME);
 SD_SCL=0;
 if(is_init) delay(DELAY_TIME); 
 _dat3=SD_SO; 

 SD_SCL=1;
 if(is_init) delay(DELAY_TIME);
 SD_SCL=0;
 if(is_init) delay(DELAY_TIME);
 _dat2=SD_SO; 

 SD_SCL=1;
 if(is_init) delay(DELAY_TIME);
 SD_SCL=0;
 if(is_init) delay(DELAY_TIME);
 _dat1=SD_SO;

 SD_SCL=1;
 if(is_init) delay(DELAY_TIME);
 SD_SCL=0;
 if(is_init) delay(DELAY_TIME);
 _dat0=SD_SO; 
 
 return (_dat);
}

/******************************************************************
 - ������������SD��д����
 - ����ģ�飺SD��ģ��
 - �������ԣ��ڲ�
 - ����˵����SD����������6���ֽڣ�pcmd��ָ�������ֽ����е�ָ��
 - ����˵��������д���SD���Ļ�Ӧֵ�����ò��ɹ���������0xff
 ******************************************************************/

unsigned char SD_Write_Cmd(unsigned char *pcmd) //��SD��д���pcmd�������ֽ����е��׵�ַ
{
 unsigned char temp,time=0;

 SD_CS=1;
 SD_spi_write(0xff); //��߼����ԣ����û�������ЩSD�����ܲ�֧��   
 SD_CS=0;

 SD_spi_write(pcmd[0]);
 SD_spi_write(pcmd[1]);
 SD_spi_write(pcmd[2]);
 SD_spi_write(pcmd[3]);
 SD_spi_write(pcmd[4]);
 SD_spi_write(pcmd[5]);

 do 
 {  
  temp = SD_spi_read();//һֱ����ֱ�������Ĳ���0xff��ʱ
  time++;
 }while((temp==0xff)&&(time<TRY_TIME)); 

 return(temp);
}

/******************************************************************
 - ������������λSD�����õ�CMD0��ʹ��SD���л���SPIģʽ
 - ����ģ�飺SD��ģ��
 - �������ԣ��ⲿ�����û�����
 - ����˵������
 - ����˵�������óɹ�������0x00�����򷵻�INIT_CMD0_ERROR (sd.h���ж���)
 ******************************************************************/
unsigned char SD_Reset()//SD����λ������SPIģʽ��ʹ��CMD0������0��
{
	unsigned char time,temp,i;
	unsigned char pcmd[] = {0x40,0x00,0x00,0x00,0x00,0x95}; //����0���ֽ�����
	is_init=1; //��is_init��Ϊ1
	SD_CS=1;  //�ر�Ƭѡ 
	for(i=0;i<0x0f;i++) //��ʼʱ������Ҫ��������74��ʱ���źţ����Ǳ���ģ�����
	{
		SD_spi_write(0xff); //120��ʱ��
	}
	SD_CS=0; //��Ƭѡ
	
	time=0;
	do
	{ 
		temp=SD_Write_Cmd(pcmd);//д��CMD0
		time++;
		if(time==TRY_TIME) 
		{ 
			SD_CS=1; //�ر�Ƭѡ
			return(INIT_CMD0_ERROR);//CMD0д��ʧ��
		}
	}while(temp!=0x01);
	SD_CS=1; //�ر�Ƭѡ
	SD_spi_write(0xff); //����SD���Ĳ���ʱ�������ﲹ8��ʱ�� 
	return 0;//����0,˵����λ�����ɹ�
}

/******************************************************************
 - ������������ʼ��SD����ʹ��CMD1
 - ����ģ�飺SD��ģ��
 - �������ԣ��ⲿ�����û�����
 - ����˵������
 - ����˵�������óɹ�������0x00�����򷵻�INIT_CMD1_ERROR (sd.h���ж���)
 ******************************************************************/

unsigned char SD_Init()	//��ʼ����ʹ��CMD1������1��
{  
	unsigned char time,temp;
	unsigned char pcmd[] = {0x41,0x00,0x00,0x00,0x00,0xff}; //����1���ֽ�����
	SD_CS=0; //��Ƭѡ
	time=0;
	do
	{ 
		temp=SD_Write_Cmd(pcmd);
		time++;
		if(time==TRY_TIME) 
		{ 
			SD_CS=1; //�ر�Ƭѡ
			return(INIT_CMD1_ERROR);//CMD1д��ʧ��
		}
	}while(temp!=0);
		 
	is_init=0; //��ʼ����ϣ���is_init����Ϊ0,Ϊ������Ժ�����ݴ����ٶ� 
	
	SD_CS=1;  //�ر�Ƭѡ 
	SD_spi_write(0xff); //����SD���Ĳ���ʱ�������ﲹ8��ʱ��
	return(0); //����0,˵����ʼ�������ɹ�
} 

/****************************************************************************
 - ������������bufferָ���512���ֽڵ�����д�뵽SD����addr������
 - ����ģ�飺SD��ģ��
 - �������ԣ��ⲿ�����û�����
 - ����˵����addr:������ַ
             buffer:ָ�����ݻ�������ָ��
 - ����˵�������óɹ�������0x00�����򷵻�WRITE_BLOCK_ERROR (sd.h���ж���)
 - ע��SD����ʼ���ɹ��󣬶�д����ʱ��������SPI�ٶ������������Ч��
 ****************************************************************************/

unsigned char SD_Write_Sector(unsigned long addr,unsigned char *buffer)	//��SD���е�ָ����ַ������д��512���ֽڣ�ʹ��CMD24������24��
{  
 unsigned char temp,time;
 unsigned int i;
 unsigned char pcmd[] = {0x58,0x00,0x00,0x00,0x00,0xff}; //��SD���е����飨512�ֽڣ�һ��������д�����ݣ���CMD24

 addr<<=9; //addr = addr * 512	�����ַ��������ַ��תΪ�ֽڵ�ַ �������������SD�����������Ϊ4G��
	
 pcmd[1]=((addr&0xff000000)>>24); //���ֽڵ�ַд�뵽CMD24�ֽ�������
 pcmd[2]=((addr&0x00ff0000)>>16);
 pcmd[3]=((addr&0x0000ff00)>>8);

 SD_CS=0;//��SD��Ƭѡ

 time=0;
 do
 {  
  temp=SD_Write_Cmd(pcmd);
  time++;
  if(time==TRY_TIME) 
  { 
   SD_CS=1; //�ر�Ƭѡ
   return(temp); //����д��ʧ��
  }
 }while(temp!=0); 

 for(i=0;i<100;i++) //����Ҫ��������ʱ���ź�
 {
  SD_spi_read();
 }
	
 SD_spi_write(0xfe);//д�뿪ʼ�ֽ� 0xfe���������Ҫд���512���ֽڵ�����	
	
 for(i=0;i<512;i++) //����������Ҫд���512���ֽ�д��SD��
 {
  SD_spi_write(buffer[i]);
 }
  
 SD_spi_write(0xff); 
 SD_spi_write(0xff); //�����ֽڵ�CRCУ���룬���ù���
   
    
 temp=SD_spi_read();   //��ȡ����ֵ
 if((temp&0x1F)!=0x05) //�������ֵ�� XXX00101˵�������Ѿ���SD��������
 {
  SD_CS=1;
  return(WRITE_BLOCK_ERROR); //д������ʧ��
 }
 
 while(SD_spi_read()!=0xff);//�ȵ�SD����æ�����ݱ������Ժ�SD��Ҫ����Щ����д�뵽�����FLASH�У���Ҫһ��ʱ�䣩
						    //æʱ����������ֵΪ0x00,��æʱ��Ϊ0xff

 SD_CS=1; //�ر�Ƭѡ

 SD_spi_write(0xff);//����SD���Ĳ���ʱ�������ﲹ8��ʱ��
 return(0);		 //����0,˵��д���������ɹ�
} 

/****************************************************************************
 - ������������ȡaddr������512���ֽڵ�bufferָ������ݻ�����
 - ����ģ�飺SD��ģ��
 - �������ԣ��ⲿ�����û�����
 - ����˵����addr:������ַ
             buffer:ָ�����ݻ�������ָ��
 - ����˵�������óɹ�������0x00�����򷵻�READ_BLOCK_ERROR (sd.h���ж���)
 - ע��SD����ʼ���ɹ��󣬶�д����ʱ��������SPI�ٶ������������Ч��
 ****************************************************************************/

unsigned char SD_Read_Sector(unsigned long addr,unsigned char *buffer)//��SD����ָ�������ж���512���ֽڣ�ʹ��CMD17��17�����
{
 unsigned int j;
 unsigned char time,temp;
 unsigned char pcmd[]={0x51,0x00,0x00,0x00,0x00,0xff}; //CMD17���ֽ�����
   
 addr<<=9; //addr=addr*512	   �����ַ��������ַ��תΪ�ֽڵ�ַ

 pcmd[1]=((addr&0xff000000)>>24);//���ֽڵ�ַд�뵽CMD17�ֽ�������
 pcmd[2]=((addr&0x00FF0000)>>16);
 pcmd[3]=((addr&0x0000FF00)>>8);

 SD_CS=0;//��Ƭѡ 

 time=0;
 do
 {  
  temp=SD_Write_Cmd(pcmd); //д��CMD17
  time++;
  if(time==TRY_TIME) 
  {
   return(READ_BLOCK_ERROR); //����ʧ��
  }
 }while(temp!=0); 
   			
 while (SD_spi_read()!= 0xfe); //һֱ����������0xfeʱ��˵���������512�ֽڵ�������

 for(j=0;j<512;j++)	 //������д�뵽���ݻ�������
 {	
  buffer[j]=SD_spi_read();
 }

 SD_spi_read();
 SD_spi_read();//��ȡ�����ֽڵ�CRCУ���룬���ù�������

 SD_CS=1;  //SD���ر�Ƭѡ 

 SD_spi_write(0xff);//����SD���Ĳ���ʱ�������ﲹ8��ʱ��

 return 0;
}

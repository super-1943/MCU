#include "sd.h"
#include "myfun.h" //这是振南的公共函数头文件

/*******************************************************

        +-------------------------------------+
        |  振南电子  高级资源驱动  SD卡 部分  |
        +-------------------------------------+

  此源码版权属 振南 全权享有，如欲引用，敬请署名并告知
        严禁随意用于商业目的，违者必究，后果自负
         振南电子 
             ->产品网站 http://www.znmcu.cn/
             ->产品网店 http://shop.znmcu.cn/
             ->产品咨询 QQ :987582714 
			            MSN:yzn07@126.com
	                    WW :yzn07				  
********************************************************/

//变量定义
//--------------------------------------------------------------
bit is_init;        //在初始化的时候设置此变量为1,同步数据传输（SPI）会放慢
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
 - 功能描述：IO模拟SPI，发送一个字节
 - 隶属模块：SD卡模块
 - 函数属性：内部
 - 参数说明：x是要发送的字节
 - 返回说明：无返回
 - 注：其中is_init为1时，写的速度放慢，初始化SD卡SPI速度不能太高
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
 - 功能描述：IO模拟SPI，读取一个字节
 - 隶属模块：SD卡模块
 - 函数属性：内部
 - 参数说明：无
 - 返回说明：返回读到的字节
 ******************************************************************/

unsigned char SD_spi_read() //SPI读一个字节
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
 - 功能描述：向SD卡写命令
 - 隶属模块：SD卡模块
 - 函数属性：内部
 - 参数说明：SD卡的命令是6个字节，pcmd是指向命令字节序列的指针
 - 返回说明：命令写入后，SD卡的回应值，调用不成功，将返回0xff
 ******************************************************************/

unsigned char SD_Write_Cmd(unsigned char *pcmd) //向SD卡写命令，pcmd是命令字节序列的首地址
{
 unsigned char temp,time=0;

 SD_CS=1;
 SD_spi_write(0xff); //提高兼容性，如果没有这里，有些SD卡可能不支持   
 SD_CS=0;

 SD_spi_write(pcmd[0]);
 SD_spi_write(pcmd[1]);
 SD_spi_write(pcmd[2]);
 SD_spi_write(pcmd[3]);
 SD_spi_write(pcmd[4]);
 SD_spi_write(pcmd[5]);

 do 
 {  
  temp = SD_spi_read();//一直读，直到读到的不是0xff或超时
  time++;
 }while((temp==0xff)&&(time<TRY_TIME)); 

 return(temp);
}

/******************************************************************
 - 功能描述：复位SD卡，用到CMD0，使用SD卡切换到SPI模式
 - 隶属模块：SD卡模块
 - 函数属性：外部，供用户调用
 - 参数说明：无
 - 返回说明：调用成功，返回0x00，否则返回INIT_CMD0_ERROR (sd.h中有定义)
 ******************************************************************/
unsigned char SD_Reset()//SD卡复位，进入SPI模式，使用CMD0（命令0）
{
	unsigned char time,temp,i;
	unsigned char pcmd[] = {0x40,0x00,0x00,0x00,0x00,0x95}; //命令0的字节序列
	is_init=1; //将is_init置为1
	SD_CS=1;  //关闭片选 
	for(i=0;i<0x0f;i++) //初始时，首先要发送最少74个时钟信号，这是必须的！！！
	{
		SD_spi_write(0xff); //120个时钟
	}
	SD_CS=0; //打开片选
	
	time=0;
	do
	{ 
		temp=SD_Write_Cmd(pcmd);//写入CMD0
		time++;
		if(time==TRY_TIME) 
		{ 
			SD_CS=1; //关闭片选
			return(INIT_CMD0_ERROR);//CMD0写入失败
		}
	}while(temp!=0x01);
	SD_CS=1; //关闭片选
	SD_spi_write(0xff); //按照SD卡的操作时序在这里补8个时钟 
	return 0;//返回0,说明复位操作成功
}

/******************************************************************
 - 功能描述：初始化SD卡，使用CMD1
 - 隶属模块：SD卡模块
 - 函数属性：外部，供用户调用
 - 参数说明：无
 - 返回说明：调用成功，返回0x00，否则返回INIT_CMD1_ERROR (sd.h中有定义)
 ******************************************************************/

unsigned char SD_Init()	//初始化，使用CMD1（命令1）
{  
	unsigned char time,temp;
	unsigned char pcmd[] = {0x41,0x00,0x00,0x00,0x00,0xff}; //命令1的字节序列
	SD_CS=0; //打开片选
	time=0;
	do
	{ 
		temp=SD_Write_Cmd(pcmd);
		time++;
		if(time==TRY_TIME) 
		{ 
			SD_CS=1; //关闭片选
			return(INIT_CMD1_ERROR);//CMD1写入失败
		}
	}while(temp!=0);
		 
	is_init=0; //初始化完毕，将is_init设置为0,为了提高以后的数据传输速度 
	
	SD_CS=1;  //关闭片选 
	SD_spi_write(0xff); //按照SD卡的操作时序在这里补8个时钟
	return(0); //返回0,说明初始化操作成功
} 

/****************************************************************************
 - 功能描述：将buffer指向的512个字节的数据写入到SD卡的addr扇区中
 - 隶属模块：SD卡模块
 - 函数属性：外部，供用户调用
 - 参数说明：addr:扇区地址
             buffer:指向数据缓冲区的指针
 - 返回说明：调用成功，返回0x00，否则返回WRITE_BLOCK_ERROR (sd.h中有定义)
 - 注：SD卡初始化成功后，读写扇区时，尽量将SPI速度提上来，提高效率
 ****************************************************************************/

unsigned char SD_Write_Sector(unsigned long addr,unsigned char *buffer)	//向SD卡中的指定地址的扇区写入512个字节，使用CMD24（命令24）
{  
 unsigned char temp,time;
 unsigned int i;
 unsigned char pcmd[] = {0x58,0x00,0x00,0x00,0x00,0xff}; //向SD卡中单个块（512字节，一个扇区）写入数据，用CMD24

 addr<<=9; //addr = addr * 512	将块地址（扇区地址）转为字节地址 ［这里就限制了SD卡的最大容量为4G］
	
 pcmd[1]=((addr&0xff000000)>>24); //将字节地址写入到CMD24字节序列中
 pcmd[2]=((addr&0x00ff0000)>>16);
 pcmd[3]=((addr&0x0000ff00)>>8);

 SD_CS=0;//打开SD卡片选

 time=0;
 do
 {  
  temp=SD_Write_Cmd(pcmd);
  time++;
  if(time==TRY_TIME) 
  { 
   SD_CS=1; //关闭片选
   return(temp); //命令写入失败
  }
 }while(temp!=0); 

 for(i=0;i<100;i++) //这里要插入若干时钟信号
 {
  SD_spi_read();
 }
	
 SD_spi_write(0xfe);//写入开始字节 0xfe，后面就是要写入的512个字节的数据	
	
 for(i=0;i<512;i++) //将缓冲区中要写入的512个字节写入SD卡
 {
  SD_spi_write(buffer[i]);
 }
  
 SD_spi_write(0xff); 
 SD_spi_write(0xff); //两个字节的CRC校验码，不用关心
   
    
 temp=SD_spi_read();   //读取返回值
 if((temp&0x1F)!=0x05) //如果返回值是 XXX00101说明数据已经被SD卡接受了
 {
  SD_CS=1;
  return(WRITE_BLOCK_ERROR); //写块数据失败
 }
 
 while(SD_spi_read()!=0xff);//等到SD卡不忙（数据被接受以后，SD卡要将这些数据写入到自身的FLASH中，需要一个时间）
						    //忙时，读回来的值为0x00,不忙时，为0xff

 SD_CS=1; //关闭片选

 SD_spi_write(0xff);//按照SD卡的操作时序在这里补8个时钟
 return(0);		 //返回0,说明写扇区操作成功
} 

/****************************************************************************
 - 功能描述：读取addr扇区的512个字节到buffer指向的数据缓冲区
 - 隶属模块：SD卡模块
 - 函数属性：外部，供用户调用
 - 参数说明：addr:扇区地址
             buffer:指向数据缓冲区的指针
 - 返回说明：调用成功，返回0x00，否则返回READ_BLOCK_ERROR (sd.h中有定义)
 - 注：SD卡初始化成功后，读写扇区时，尽量将SPI速度提上来，提高效率
 ****************************************************************************/

unsigned char SD_Read_Sector(unsigned long addr,unsigned char *buffer)//从SD卡的指定扇区中读出512个字节，使用CMD17（17号命令）
{
 unsigned int j;
 unsigned char time,temp;
 unsigned char pcmd[]={0x51,0x00,0x00,0x00,0x00,0xff}; //CMD17的字节序列
   
 addr<<=9; //addr=addr*512	   将块地址（扇区地址）转为字节地址

 pcmd[1]=((addr&0xff000000)>>24);//将字节地址写入到CMD17字节序列中
 pcmd[2]=((addr&0x00FF0000)>>16);
 pcmd[3]=((addr&0x0000FF00)>>8);

 SD_CS=0;//打开片选 

 time=0;
 do
 {  
  temp=SD_Write_Cmd(pcmd); //写入CMD17
  time++;
  if(time==TRY_TIME) 
  {
   return(READ_BLOCK_ERROR); //读块失败
  }
 }while(temp!=0); 
   			
 while (SD_spi_read()!= 0xfe); //一直读，当读到0xfe时，说明后面的是512字节的数据了

 for(j=0;j<512;j++)	 //将数据写入到数据缓冲区中
 {	
  buffer[j]=SD_spi_read();
 }

 SD_spi_read();
 SD_spi_read();//读取两个字节的CRC校验码，不用关心它们

 SD_CS=1;  //SD卡关闭片选 

 SD_spi_write(0xff);//按照SD卡的操作时序在这里补8个时钟

 return 0;
}

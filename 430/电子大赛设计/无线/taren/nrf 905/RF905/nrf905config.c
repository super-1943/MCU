#include "nrf905.h"
#include <iom8v.h>
extern void DelayMs(uchar ms);
extern void DelayUs(uint us);

#define SIZE 32

uchar TxBuf[SIZE]={101,102,103,104,105,106,107,108,109,110,
                   111,112,113,114,115,116,117,118,119,120,
                   121,122,123,124,125,126,127,128,129,130,
				    131,132};
uchar RxBuf[SIZE];
void nrf905_Config(void)
{
  CLR(PORTB,CSN);                                // Spi 片选开
  nrf905_SpiRW(WC);                              // Write config command
  nrf905_SpiRW(CH_NO_BYTE);                      //中心频率低8位
  nrf905_SpiRW(PA_PWR_10dBm | HFREQ_PLL_433MHz); //发射+10dBm,发射频率433MHz,中心频率第9位=0
  nrf905_SpiRW(TX_AFW_4BYTE | RX_AFW_4BYTE);     //接收地址宽度4字节,发送地址宽度4字节
  nrf905_SpiRW(RX_PW_32BYTE);                    //接收数据宽度32字节
  nrf905_SpiRW(TX_PW_32BYTE);                    //发送数据宽度32字节
  nrf905_SpiRW(RX_ADDRESS_0);                    //接收有效地址第1字节
  nrf905_SpiRW(RX_ADDRESS_1);                    //接收有效地址第2字节
  nrf905_SpiRW(RX_ADDRESS_2);                    //接收有效地址第3字节
  nrf905_SpiRW(RX_ADDRESS_3);                    //接收有效地址第4字节
  nrf905_SpiRW(CRC16_EN | XOF_16MHz);            //CRC16模式使能,晶体振荡器频率16MHz
  SET(PORTB,CSN);                                // Disable Spi
}

uchar nrf905_SpiRW(uchar val) 
{   uchar temp;

    SPDR=val;
	while ((SPSR&(1<<SPIF))==0)
	;
	temp=SPDR;
	return temp;
}

//PwrDown->StandBy
void nrf905_StandBy()
{
   SET(PORTB,PWRUP);
   CLR(PORTB,TRXCE);
   CLR(PORTB,TX_EN);
}

//->PwrDown
void nrf905_Off()
{
  CLR(PORTB,PWRUP);
}

//->ShockBurst Send
void nrf905_TxOn()
{
  SET(PORTB,PWRUP);
  SET(PORTB,TX_EN);
  CLR(PORTB,TRXCE);
}

//->ShockBurst Send
void nrf905_TxSend()
{
  SET(PORTB,TRXCE);
  DelayUs(20);//>10us
  CLR(PORTB,TRXCE);//只发送一次
}

//->ShockBurst Recv
void nrf905_RxOn()
{
  SET(PORTB,PWRUP);
  CLR(PORTB,TX_EN);      //maybe first
  SET(PORTB,TRXCE);
}

//初始化nrf905
void nrf905_Init()
{
   nrf905_StandBy();
   DelayMs(10);//!!!must >3ms
   nrf905_Config();
   
   nrf905_SpiTest();//test...
   nrf905_RxOn();
}

//测试：通过读配置，判断SPI操作是否正确
void nrf905_SpiTest()
{uchar i;
  CLR(PORTB,CSN);                   
  nrf905_SpiRW(RC);  //读配置
  for (i=0;i<10;i++)
  { 
    RxBuf[i]=  nrf905_SpiRW(0);//read from nrf905
  }
  SET(PORTB,CSN);  
}

//写Tx地址
void nrf905_SetTxAddr()
{
  CLR(PORTB,CSN);                   
  nrf905_SpiRW(WTA);  //写Tx地址  
  nrf905_SpiRW(TX_ADDRESS_0);
  nrf905_SpiRW(TX_ADDRESS_1);
  nrf905_SpiRW(TX_ADDRESS_2);
  nrf905_SpiRW(TX_ADDRESS_3);
  SET(PORTB,CSN);  
}

//写Tx数据
void nrf905_SetData()
{uchar i;

  CLR(PORTB,CSN);                   
  nrf905_SpiRW(WTP);  //写TxPayload 
  for (i=0;i<SIZE;i++)
  { 
    nrf905_SpiRW(TxBuf[i]);
  }
  
  SET(PORTB,CSN);  
}

//等待发送结束
void nrf905_WaitSended()
{
   while ((PINC&(1<<DR))==0);
}

//发送TxBuf中的数据
void nrf905_SendData()
{
   nrf905_TxOn();      //切换到发送模式
   nrf905_SetTxAddr(); //写发送地址
   nrf905_SetData();   //写数据
   nrf905_TxSend();    //启动发送
  // nrf905_WaitSended();//等待发送结束   有改动
   DelayMs(10);
   
}

//测试直接重新发送上次写入的数据
void nrf905_SendAgain()
{
   nrf905_TxOn();
   nrf905_TxSend();
  // nrf905_WaitSended();
   DelayMs(20);
}

//读出接收到的数据
void nrf905_ReadData()
{
  uchar i;

  CLR(PORTB,CSN);                   
  nrf905_SpiRW(RRP);  //读RxPayload 
  for (i=0;i<SIZE;i++)
  { 
    RxBuf[i]=nrf905_SpiRW(0);//read...
  }
  
  SET(PORTB,CSN);  

}



//接收处理
uchar  RfRecvProc()
{uchar i;
   //if((PINC&(1<<CD))==0)  return 'C';
	
  // if ((PINC&(1<<AM))==0) return 'A';//一般先AM=1指示地址匹配对
   
   if ((PINC&(1<<DR))==0) return 'N';//DR=1时表示数据接收对而且Crc正确
   
   //已经接收到数据
   nrf905_ReadData();//读出...
   return 'y';
  /* for (i=0;i<32;i++)
   { if (RxBuf[i]!=(i+i)) 
        return;
   }*/
   
   //数据接收正确...灯指示
    //    CPL(PORTD,LED);
   
   //从机回送数据包,这样双方都能指示是否收到有效数据包
  /* #ifndef MASTER
     RfSendProc();
   #endif*/
}

//发送测试
void RfSendProc()
{uchar i;
  // for (i=0;i<32;i++) 
  // TxBuf[i]=i+i;
   nrf905_SendData();  //发送测试数据
   nrf905_RxOn();      //重新回到接收状态
}





void DelayMs(uchar ms)
{char i;
for (i=0;i<ms;i++)
  {DelayUs(1000);
  }
  return;
}

void DelayUs(uint us)
{uint i;
  for (i=0;i<us;i++)
  ;
}
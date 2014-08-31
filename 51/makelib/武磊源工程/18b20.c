
#include<18B20.h>
#include<1602.h>
#include<1302.h>
//unsigned char code digit[11]={"0123456789-"};     //定义字符数组显示数字
extern unsigned char code digit[];
unsigned char code Str[]={"WXWL    DS18B20"};    //说明显示的是温度
unsigned char code Error[]={"  DS18B20 ERROR"};     //说明没有检测到DS18B20
unsigned char code Error1[]={" PLEASE  CHECK"};     //说明没有检测到DS18B20
unsigned char code Temp[]={"WENDU:"};             //说明显示的是温度
unsigned char code Cent[]={"Cent"};              //温度单位
bit yes0 ;
unsigned char flag,tltemp;						//负温度标志 和临时暂存变量
unsigned char TL,TH,TN,TD;     //储存暂存器的温度低位、高位、整数部分、小数部分
/**********************************************************/
void DS18B20_delay(uint num)//延时函数
{
  while( --num );
}
void Ds18B20_beep()		//蜂鸣器响一声函数
{
  unsigned char i;
  for (i=0;i<100;i++)
   {
   Lcd_delay(100);
   BEEP=!BEEP;       //BEEP取反
   } 
   BEEP=1;           //关闭蜂鸣器
   DS18B20_delay(250);       //延时     
}
/**********************************************************/
bit DS18B20_Init(void)//初始化ds1820		延时30晶振
{
  
     DQ = 1;      //DQ复位
     DS18B20_delay(22);    //稍做延时
     DQ = 0;      //单片机将DQ拉低
     DS18B20_delay(240);   //精确延时 大于 480us
     DQ = 1;       //拉高总线
     DS18B20_delay(22);

     yes0 = DQ;    //如果=0则初始化成功 =1则初始化失败
     DS18B20_delay(270);
     DQ = 1; 
     
     return(yes0); //返回信号，若yes0为0则存在,若yes0为1则不存在
}
/**********************************************************/
DS18B20_ReadOneByte(void)//读一个字节
{
uchar i = 0;
uchar dat = 0;

for (i = 8; i > 0; i--)
  {
    DQ = 0; // 给脉冲信号
    dat >>= 1;
    DQ = 1; // 给脉冲信号

    if(DQ)
     dat |= 0x80;
    DS18B20_delay(10);	  //随着晶振调整延时
  }

    return (dat);
}

/**********************************************************/
DS18B20_WriteOneByte(uchar dat)//写一个字节
{
  uchar i = 0;
  for (i = 8; i > 0; i--)
  {
    DQ = 0;
    DQ = dat&0x01;
    DS18B20_delay(13);		  //随着晶振调整延时

    DQ = 1;
    dat>>=1;
  }
}
 void Ds18B20_TempConv()   //转换成适合显示的
{  if((TH&0xf8)!=0x00)//判断高五位 得到温度正负标志
		{
		flag=1;
		TL=~TL;	 //取反
		TH=~TH;	  //取反
		tltemp=TL+1; //低位加1
		TL=tltemp;
		if(tltemp>255) TH++;  //如果低8位大于255，向高8位进1
	   TN=TH*16+TL/16;      //实际温度值=(TH*256+TL)/16,即：TH*16+TL/16
				                  //这样得出的是温度的整数部分,小数部分被丢弃了
	   TD=(TL%16)*10/16;    //计算温度的小数部分,将余数乘以10再除以16取整，
		}
		TN=TH*16+TL/16;      //实际温度值=(TH*256+TL)/16,即：TH*16+TL/16
				                  //这样得出的是温度的整数部分,小数部分被丢弃了
	   TD=(TL%16)*10/16;    //计算温度的小数部分,将余数乘以10再除以16取整，
			                  //这样得到的是温度小数部分的第一位数字(保留1位小数)
}
 /*****************************************************
函数功能：显示没有检测到DS18B20
***************************************************/   
void DS18B20_display_error(void)
 {
       unsigned char i;
	    Lcd_WriteCom(0x01); //清屏
		 Lcd_delay(5);
	 	     Lcd_WriteAddress(0x00);    //写显示地址，将在第1行第1列开始显示
			   i = 0;                //从第一个字符开始显示
				while(Error[i] != '\0')  //只要没有写到结束标志，就继续写
				{						
					Lcd_WriteData(Error[i]);   //将字符常量写入LCD
					i++;                 //指向下一个字符
					Lcd_delay(10);        //延时100ms较长时间，以看清关于显示的说明
				}	
			
	 	     Lcd_WriteAddress(0x40);    //写显示地址，将在第1行第1列开始显示
			   i = 0;                //从第一个字符开始显示
				while(Error1[i] != '\0')  //只要没有写到结束标志，就继续写
				{						
					Lcd_WriteData(Error1[i]);   //将字符常量写入LCD
					i++;                 //指向下一个字符
					Lcd_delay(10);        //延时100ms较长时间，以看清关于显示的说明
				}
				Ds18B20_beep();		//蜂鸣器响一声函数	
			//	while(1)              //进入死循环，等待查明原因	   如果多个应用的话会使别的程序没办法运行，一般不加
				  ;
}
/********以下是读取温度值函数********/
Ds18B20_GetTemperture(void)
{ 
 DS18B20_Init();					//DS18B20初始化
  if(yes0==0) 					//若yes0为0,说明DS18B20正常
  {
  	    DS18B20_WriteOneByte(0xCC);  		// 跳过读序号列号的操作
     	DS18B20_WriteOneByte(0x44);  		// 启动温度转换
		 Lcd_delay(200);		//调用显示函数延时,等待A/D转换结束,分辨率为12位时需延时750ms以上
     	DS18B20_Init();
    	DS18B20_WriteOneByte(0xCC);  		//跳过读序号列号的操作
     	DS18B20_WriteOneByte(0xBE);  		//读取温度寄存器
     	TL = DS18B20_ReadOneByte();  	//温度低8位
     	TH= DS18B20_ReadOneByte();  	//温度高8位 
   }
	else  
	{
	DS18B20_display_error();
	}
}
/*****************************************************
函数功能：显示说明信息
***************************************************/   
void DS18B20_display_explain(void)
 {
       unsigned char i;
	 	     Lcd_WriteAddress(0x00);    //写显示地址，将在第1行第1列开始显示
			   i = 0;                //从第一个字符开始显示
				while(Str[i] != '\0')  //只要没有写到结束标志，就继续写
				{						
					Lcd_WriteData(Str[i]);   //将字符常量写入LCD
					i++;                 //指向下一个字符
					Lcd_delay(1);        //延时100ms较长时间，以看清关于显示的说明
				}	
}
/*****************************************************
函数功能：显示温度符号
***************************************************/   
void DS18B20_display_symbol(void)
 {
       unsigned char i;
	 	     Lcd_WriteAddress(0x40);    //写显示地址，将在第2行第1列开始显示
			   i = 0;                //从第一个字符开始显示
				while(Temp[i] != '\0')  //只要没有写到结束标志，就继续写
				{						
					Lcd_WriteData(Temp[i]);   //将字符常量写入LCD
					i++;                 //指向下一个字符
					Lcd_delay(1);        //延时1ms给硬件一点反应时间
				}	
}

/*****************************************************
函数功能：显示温度的小数点
***************************************************/   
void 	DS18B20_display_dot(void)
{         
	 Lcd_WriteAddress(0x49);	  //写显示地址，将在第2行第10列开始显示		   
	 Lcd_WriteData('.');      //将小数点的字符常量写入LCD
	 Lcd_delay(1);         //延时1ms给硬件一点反应时间		
}
/*****************************************************
函数功能：显示温度的单位(Cent)
***************************************************/   
void 	DS18B20_display_cent(void)
{
           unsigned char i;    
	 	     Lcd_WriteAddress(0x4c);        //写显示地址，将在第2行第13列开始显示	
			   i = 0;                    //从第一个字符开始显示 
				while(Cent[i] != '\0')     //只要没有写到结束标志，就继续写
				{					
					Lcd_WriteData(Cent[i]);     //将字符常量写入LCD
					i++;                 //指向下一个字符
					Lcd_delay(1);        //延时1ms给硬件一点反应时间
				}	
}
/*****************************************************
函数功能：显示温度的整数部分
入口参数：x
***************************************************/ 
void DS18B20_display_temp1(unsigned char x)
{
 unsigned char j,k,l;     //j,k,l分别储存温度的百位、十位和个位
	j=x/100;              //取百位
	k=(x%100)/10;    //取十位
	l=x%10;             //取个位  
	Lcd_WriteAddress(0x46);    //写显示地址,将在第2行第7列开始显示
	if(flag==1)				//负温度时 显示“—”
	{
	Lcd_WriteData(digit[10]);    //将百位数字的字符常量写入LCD
	Lcd_delay(1);         //延时5ms给硬件一点反应时间
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              	}
	else{
	Lcd_WriteData(digit[j]);    //将百位数字的字符常量写入LCD
	Lcd_delay(1);         //延时5ms给硬件一点反应时间
	}
	Lcd_WriteData(digit[k]);    //将十位数字的字符常量写入LCD
	Lcd_delay(1);         //延时5ms给硬件一点反应时间
	Lcd_WriteData(digit[l]);    //将个位数字的字符常量写入LCD
	Lcd_delay(1);         //延时5ms给硬件一点反应时间     
 }
 /*****************************************************
函数功能：显示温度的小数数部分
入口参数：x
***************************************************/ 
 void DS18B20_display_temp2(unsigned char x)
{
 	Lcd_WriteAddress(0x4a);      //写显示地址,将在第2行第11列开始显示
	Lcd_delay(1);         //延时10ms给硬件一点反应时间
	Lcd_WriteData(digit[x]);     //将小数部分的第一位数字字符常量写入LCD
	Lcd_delay(1);          //延时1ms给硬件一点反应时间
}
 /********以下是显示函数, 在前4位数码管上显示出温度值********/
void Ds18B20_Display()
{ 
	 DS18B20_display_temp1(TN);    //显示温度的整数部分
	 DS18B20_display_temp2(TD);    //显示温度的小数部分
}
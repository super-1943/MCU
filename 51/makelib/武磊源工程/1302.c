#include<1602.h>
#include<1302.h>
#include<hongwai.h>
extern unsigned char a[];	  //不能只写extern丢掉unsigned char
unsigned char code digit[11]={"0123456789-"};     //定义字符数组显示数字
bit K1_FLAG=0;				//定义按键标志位，当按下K1键时，该位置1，K1键未按下时，该位为0。
unsigned char QH_FLAG=1;//按键控制年月日时分切换标志
char time_buf[7] ={0,0,0,0,0,0,0};		//DS1302时间缓冲区，存放秒、分、时、日、月、星期、年


/*****************************************************
函数功能：延时若干微秒
入口参数：n
***************************************************/ 
void Ds1302_delaynus(unsigned char n)
{
 unsigned char i;
 for(i=0;i<n;i++);
}
/*****************************************************
函数功能：延时1ms
***************************************************/
void Ds1302_delay1ms()
{
   		unsigned char i,j;	
	 	for(i=0;i<10;i++)
	  	for(j=0;j<33;j++)
	   ;		 
 }

/*********************************************************/
void Ds1302_beep()		//蜂鸣器响一声函数
{
  unsigned char i;
  for (i=0;i<100;i++)
   {
   Ds1302_delay1ms();
   BEEP=!BEEP;       //BEEP取反
   } 
   BEEP=1;           //关闭蜂鸣器
 //  Ds1302_delay(250);       //延时     
}

/*****************************************************
函数功能：向1302写一个字节数据
入口参数：x
***************************************************/ 
void Ds1302_Write(unsigned char dat)
{
  unsigned char i; 
  SCLK=0;            //拉低SCLK，为脉冲上升沿写入数据做好准备
  //Ds1302_delaynus(2);       //稍微等待，使硬件做好准备
  for(i=0;i<8;i++)      //连续写8个二进制位数据
    {
	     DATA=dat&0x01;    //取出dat的第0位数据写入1302  低位在前，高位在后
	//	 Ds1302_delaynus(2);       //稍微等待，使硬件做好准备
		 SCLK=1;           //上升沿写入数据
	//	 Ds1302_delaynus(2);      //稍微等待，使硬件做好准备
		 SCLK=0;           //重新拉低SCLK，形成脉冲
		 dat>>=1;          //将dat的各数据位右移1位，准备写入下一个数据位
	  }
	
 }
/*****************************************************
函数功能：根据命令字，向1302写一个字节数据
入口参数：Cmd，储存命令字；dat，储存待写的数据
***************************************************/ 
void Ds1302_WriteSet(unsigned char Cmd,unsigned char dat)
 {	  
        RST=0;           //禁止数据传递
        SCLK=0;          //确保写数居前SCLK被拉低
	    RST=1;           //启动数据传输
	    Ds1302_delaynus(2);     //稍微等待，使硬件做好准备
	    Ds1302_Write(Cmd);  //写入命令字
	    Ds1302_Write(dat);  //写数据
	    SCLK=1;          //将时钟电平置于高电平状态
	    RST=0;           //禁止数据传递
 }
/*****************************************************
函数功能：从1302读一个字节数据
入口参数：x
***************************************************/ 
 unsigned char Ds1302_Read(void)
 {
    unsigned char i,dat;
//	Ds1302_delaynus(2);       //稍微等待，使硬件做好准备
	for(i=0;i<8;i++)   //连续读8个二进制位数据
	 {	 dat>>=1;
		 if(DATA==1)    //如果读出的数据是1
		 dat|=0x80;    //将1取出，写在dat的最高位
		 SCLK=1;       //将SCLK置于高电平，为下降沿读出
		 //Ds1302_delaynus(2);  //稍微等待
		 SCLK=0;       //拉低SCLK，形成脉冲下降沿
		// Ds1302_delaynus(2);  //稍微等待
	  }	 
  return dat;        //将读出的数据返回
}  
/*****************************************************
函数功能：根据命令字，从1302读取一个字节数据
入口参数：Cmd
注：读出的数据必须按‘格式’转化，不能直接用
***************************************************/ 
unsigned char  Ds1302_ReadSet(unsigned char Cmd)
 {
  unsigned char dat;
  RST=0;                 //拉低RST
  SCLK=0;                //确保写数居前SCLK被拉低
  RST=1;                 //启动数据传输
  Ds1302_Write(Cmd);       //写入命令字
  dat=Ds1302_Read();       //读出数据
  SCLK=1;              //将时钟电平置于已知状态
  RST=0;               //禁止数据传递
  return dat;          //将读出的数据返回
}
/*****************************************************
函数功能： 1302进行初始化设置
***************************************************/ 
void Ds1302_Int(void)
{	
    unsigned char flag;
   
    flag= Ds1302_ReadSet(0x81);
	if(flag&0x80)	{      //判断时钟芯片是否关闭
    Ds1302_WriteSet(0x8E,0x00);                 //根据写状态寄存器命令字，写入不保护指令 
   	Ds1302_WriteSet(0x80,((55/10)<<4|(55%10)));   //根据写秒寄存器命令字，写入秒的初始值
	Ds1302_WriteSet(0x82,((59/10)<<4|(59%10)));   //根据写分寄存器命令字，写入分的初始值
	Ds1302_WriteSet(0x84,((23/10)<<4|(23%10))); //根据写小时寄存器命令字，写入小时的初始值
	Ds1302_WriteSet(0x86,((30/10)<<4|(18%10))); //根据写日寄存器命令字，写入日的初始值
	Ds1302_WriteSet(0x88,((3/10)<<4|(6%10))); //根据写月寄存器命令字，写入月的初始值
	Ds1302_WriteSet(0x8c,((11/10)<<4|(9%10)));  //根据写年寄存器命令字，写入年的初始值
	Ds1302_WriteSet(0x90,0xa5);                //打开充电功能 选择2K电阻充电方式
	Ds1302_WriteSet(0x8E,0x80);			   //根据写状态寄存器命令字，写入保护指令
  }	 

  /*--------------------这是每次都初始化的语句-----------------*/
   
  /* Ds1302_WriteSet(0x8E,0x00);                 //根据写状态寄存器命令字，写入不保护指令
   Ds1302_WriteSet(0x80,((55/10)<<4|(55%10)));   //根据写秒寄存器命令字，写入秒的初始值

	Ds1302_WriteSet(0x82,((59/10)<<4|(59%10)));   //根据写分寄存器命令字，写入分的初始值

	Ds1302_WriteSet(0x84,((23/10)<<4|(23%10))); //根据写小时寄存器命令字，写入小时的初始值

	Ds1302_WriteSet(0x86,((30/10)<<4|(18%10))); //根据写日寄存器命令字，写入日的初始值

	Ds1302_WriteSet(0x88,((3/10)<<4|(6%10))); //根据写月寄存器命令字，写入月的初始值

	Ds1302_WriteSet(0x8c,((11/10)<<4|(9%10)));   //根据写年寄存器命令字，写入年的初始值

	Ds1302_WriteSet(0x90,0xa5);                //打开充电功能 选择2K电阻充电方式

	Ds1302_WriteSet(0x8E,0x80);              //根据写状态寄存器命令字，写入保护指令	*/

						
}
 /**************************************************************
以下是1302数据的显示程序
**************************************************************/
/*****************************************************
函数功能：显示秒
入口参数：x
***************************************************/ 
void Ds1302_DisplaySecond(unsigned char x)
{
 unsigned char i,j;     //j,k分别储存十位和个位
	i=x/10;//取十位
	j=x%10;//取个位     
	Lcd_WriteAddress(0x49);    //写显示地址,将在第2行第7列开始显示
	Lcd_delay(1);
	Lcd_WriteData(digit[i]);    //将百位数字的字符常量写入LCD
	Lcd_delay(1);
	Lcd_WriteData(digit[j]);    //将十位数字的字符常量写入LCD
	Lcd_delay(1);			 //延时1ms给硬件一点反应时间            
 }

/*****************************************************
函数功能：显示分钟
入口参数：x
***************************************************/ 
void Ds1302_DisplayMinute(unsigned char x)
{
 unsigned char i,j;     //j,k十位和个位
	i=x/10;//取十位
	j=x%10;//取个位     
	Lcd_WriteAddress(0x46);    //写显示地址,将在第2行第7列开始显示
	Lcd_delay(1);
	Lcd_WriteData(digit[i]);    //将百位数字的字符常量写入LCD
	Lcd_delay(1);
	Lcd_WriteData(digit[j]);    //将十位数字的字符常量写入LCD
	Lcd_delay(1);			 //延时1ms给硬件一点反应时间           
 }
/*****************************************************
函数功能：显示小时
入口参数：x
***************************************************/ 
void Ds1302_DisplayHour(unsigned char x)
{
 unsigned char i,j;     //j,k十位和个位
	i=x/10;//取十位
	j=x%10;//取个位     
	Lcd_WriteAddress(0x43);    //写显示地址,将在第2行第7列开始显示
	Lcd_delay(1);
	Lcd_WriteData(digit[i]);    //将百位数字的字符常量写入LCD
	Lcd_delay(1);
	Lcd_WriteData(digit[j]);    //将十位数字的字符常量写入LCD
	Lcd_delay(1);		   //延时1ms给硬件一点反应时间            
 }
 /*****************************************************
函数功能：显示日
入口参数：x
***************************************************/ 
void Ds1302_DisplayDay(unsigned char x)
{
 	unsigned char i,j;     //j,k十位和个位
	i=x/10;//取十位
	j=x%10;//取个位     
	Lcd_WriteAddress(0x0d);    //写显示地址,将在第2行第7列开始显示
	Lcd_delay(1);
	Lcd_WriteData(digit[i]);    //将十位数字的字符常量写入LCD
	Lcd_delay(1);
	Lcd_WriteData(digit[j]);    //将个位数字的字符常量写入LCD
	Lcd_delay(1);		   //延时1ms给硬件一点反应时间           
 }
 /*****************************************************
函数功能：显示月
入口参数：x
***************************************************/ 
void Ds1302_DisplayMonth(unsigned char x)
{
 unsigned char i,j;     //j,k分别储存十位和个位
	i=x/10;//取十位
	j=x%10;//取个位     
	Lcd_WriteAddress(0x0a);    //写显示地址,将在第2行第7列开始显示
	Lcd_delay(1);
	Lcd_WriteData(digit[i]);    //将十位位数字的字符常量写入LCD
	Lcd_delay(1);
	Lcd_WriteData(digit[j]);    //将个位数字的字符常量写入LCD
	Lcd_delay(1);		   //延时1ms给硬件一点反应时间            
 }
/*****************************************************
函数功能：显示年
入口参数：x
***************************************************/ 
void Ds1302_DisplayYear(unsigned char x)
{
 unsigned char i,j;     //j,k分别储存十位和个位
	i=x/10;//取十位
	j=x%10;//取个位     
	Lcd_WriteAddress(0x07);    //写显示地址,将在第2行第7列开始显示
	Lcd_delay(1);
	Lcd_WriteData(digit[i]);    //将十位位数字的字符常量写入LCD
	Lcd_delay(1);
	Lcd_WriteData(digit[j]);    //将个位数字的字符常量写入LCD
	Lcd_delay(1);			//延时1ms给硬件一点反应时间           
 }
/**********************************************************
函数功能：在对应位置显示date ——
*********************************************************/
void Ds1302_QLShow(void)
{ Lcd_WriteAddress(0x00);  //写Date的显示地址,将在第1行第2列开始显示
  Lcd_delay(1);
  Lcd_WriteData('D');      //将字符常量写入LCD
   Lcd_delay(1);
  Lcd_WriteData('a');      //将字符常量写入LCD
   Lcd_delay(1);
  Lcd_WriteData('t');      //将字符常量写入LCD
   Lcd_delay(1);
  Lcd_WriteData('e');      //将字符常量写入LCD
   Lcd_delay(1);
  Lcd_WriteData(':');      //将字符常量写入LCD
   Lcd_delay(1);
   Lcd_WriteData('2');      //将字符常量写入LCD
   Lcd_delay(1);
  Lcd_WriteData('0');      //将字符常量写入LCD
   Lcd_delay(1);
  Lcd_WriteAddress(0x09);  //写年月分隔符的显示地址， 显示在第1行第9列
   Lcd_delay(1);
  Lcd_WriteData('-');      //将字符常量写入LCD
   Lcd_delay(1);
  Lcd_WriteAddress(0x0c);  //写月日分隔符的显示地址， 显示在第1行第12列
   Lcd_delay(1);
  Lcd_WriteData('-');      //将字符常量写入LCD
   Lcd_delay(1);
 Lcd_WriteAddress(0x0f);  //写月日分隔符的显示地址， 显示在第1行第12列
   Lcd_delay(1);
  Lcd_WriteData(' ');      //将字符常量写入LCD 	  //写入空格防止屏幕显示乱码
   Lcd_delay(1);
  Lcd_WriteAddress(0x45);  //写小时与分钟分隔符的显示地址， 显示在第2行第6列
   Lcd_delay(1);
  Lcd_WriteData(':');      //将字符常量写入LCD
   Lcd_delay(1);
  Lcd_WriteAddress(0x48);  //写分钟与秒分隔符的显示地址， 显示在第2行第9列
   Lcd_delay(1);
  Lcd_WriteData(':');      //将字符常量写入LCD
   Lcd_delay(1);
}
/**********************************************************************************
函数功能：读取时间
**********************************************************************************/
 void time_get_show(void)
{ unsigned char second,minute,hour,day,month,year;      //分别储存苗、分、小时，日，月，年
  unsigned char ReadValue;   //储存从1302读取的数据
  if(K1_FLAG==0)
  {
   if(K1==0)				//若K1键按下
	{
			Lcd_delay(10);		//延时10ms去抖
			if(K1==0)
			{
				while(!K1);		//等待K1键释放
				Ds1302_beep();		//蜂鸣器响一声
				K1_FLAG=1;		//K1键标志位置1，以便进行时钟调整
				ReadValue=Ds1302_ReadSet(0x8d);
				time_buf[6]=((ReadValue&0xf0)>>4)*10 + (ReadValue&0x0F);//将读出数据转化
				ReadValue=Ds1302_ReadSet(0x89);
				time_buf[4]=((ReadValue&0x70)>>4)*10 + (ReadValue&0x0F);//将读出数据转化
		        ReadValue=Ds1302_ReadSet(0x87);
				time_buf[3]=((ReadValue&0x70)>>4)*10 + (ReadValue&0x0F);//将读出数据转化
				ReadValue=Ds1302_ReadSet(0x85);
				time_buf[2]=((ReadValue&0x70)>>4)*10 + (ReadValue&0x0F);//将读出数据转化
		        ReadValue=Ds1302_ReadSet(0x83);
				time_buf[1]=((ReadValue&0x70)>>4)*10 + (ReadValue&0x0F);//将读出数据转化
				Lcd_WriteAddress(0x4d);  // 设置显示位置为第一行的第1个字
                Lcd_delay(5);
				Lcd_WriteData('Y');
				Lcd_delay(5); 
				QH_FLAG=1; //按K1是要“归零”
			}
	}
	      if(a[2]==wl2)            //定义红外功能
		{  		
		        K1_FLAG=1;		//K1键标志位置1，以便进行时钟调整
				ReadValue=Ds1302_ReadSet(0x8d);
				time_buf[6]=((ReadValue&0xf0)>>4)*10 + (ReadValue&0x0F);//将读出数据转化
				ReadValue=Ds1302_ReadSet(0x89);
				time_buf[4]=((ReadValue&0x70)>>4)*10 + (ReadValue&0x0F);//将读出数据转化
		        ReadValue=Ds1302_ReadSet(0x87);
				time_buf[3]=((ReadValue&0x70)>>4)*10 + (ReadValue&0x0F);//将读出数据转化
				ReadValue=Ds1302_ReadSet(0x85);
				time_buf[2]=((ReadValue&0x70)>>4)*10 + (ReadValue&0x0F);//将读出数据转化
		        ReadValue=Ds1302_ReadSet(0x83);
				time_buf[1]=((ReadValue&0x70)>>4)*10 + (ReadValue&0x0F);//将读出数据转化
				Lcd_WriteAddress(0x4d);  // 设置显示位置为第一行的第1个字
                Lcd_delay(1);
				Lcd_WriteData('Y');
				Lcd_delay(1); 
				QH_FLAG=1; //按K1是要“归零”
			    a[2]=0;	
		}
	}

  if(K1_FLAG==1)
		{ 
		KeyProcess();		//若K1_FLAG为1，则进行走时调整
		}
  else{
  Lcd_WriteAddress(0x40);    //显示三个空格防止乱码
	Lcd_delay(1);
	Lcd_WriteData(' ');    
	Lcd_delay(1);
	Lcd_WriteData(' ');    
	Lcd_delay(1);		   
	Lcd_WriteData(' ');    
	Lcd_delay(1);        //延时1ms给硬件一点反应时间 

    ReadValue = Ds1302_ReadSet(0x81);   //从秒寄存器读数据
     second=((ReadValue&0x70)>>4)*10 + (ReadValue&0x0F);//将读出数据转化
	  Ds1302_DisplaySecond(second);          //显示秒
	  ReadValue = Ds1302_ReadSet(0x83);  //从分寄存器读
     minute=((ReadValue&0x70)>>4)*10 + (ReadValue&0x0F); //将读出数据转化
	  Ds1302_DisplayMinute(minute);	       //显示分
     ReadValue = Ds1302_ReadSet(0x85);  //从时寄存器读
     hour=((ReadValue&0x70)>>4)*10 + (ReadValue&0x0F); //将读出数据转化
	  Ds1302_DisplayHour(hour);	             //显示小时
     ReadValue = Ds1302_ReadSet(0x87);  //从分寄存器读
     day=((ReadValue&0x70)>>4)*10 + (ReadValue&0x0F); //将读出数据转化
	  Ds1302_DisplayDay(day);                //显示日
	  ReadValue = Ds1302_ReadSet(0x89);  //从分寄存器读
     month=((ReadValue&0x70)>>4)*10 + (ReadValue&0x0F); //将读出数据转化
	  Ds1302_DisplayMonth(month);            //显示月
	  ReadValue = Ds1302_ReadSet(0x8d);  //从分寄存器读
     year=((ReadValue&0xf0)>>4)*10 + (ReadValue&0x0F); //将读出数据转化
	  Ds1302_DisplayYear(year);              //显示年

	  Lcd_WriteAddress(0x4b);    //显示四个空格防止乱码
	Lcd_delay(1);
	Lcd_WriteData(' ');    
	Lcd_delay(1);
	Lcd_WriteData(' ');
	Lcd_delay(1);
	Lcd_WriteData(' ');    
	Lcd_delay(1);		   
	Lcd_WriteData(' ');    
	Lcd_delay(1);        //延时1ms给硬件一点反应时间

	    }
}
/********以下是按键处理函数********/
void KeyProcess()
{
  unsigned char min16,hour16,day16,month16,year16;				//定义16进制的分钟和小时变量
  Ds1302_WriteSet(0x8e,0x00);  			//DS1302写保护控制字，允许写
  Ds1302_WriteSet(0x80,0x80);                   //时钟停止运行
   if(K2==0)                               //K2键用来对小时进行加1调整
  {
  	Lcd_delay(10);				//延时去抖
  	if(K2==0)
  	{
			while(!K2);						//等待K2键释放
			Ds1302_beep();	  
			QH_FLAG++;
			if(QH_FLAG>5)
			{ QH_FLAG=1;
			}	
			  
	   switch(QH_FLAG)
		{case 1:
		        Lcd_WriteAddress(0x4d);  // 设置显示位置为第一行的第1个字
                Lcd_delay(1);
				Lcd_WriteData('Y');
				Lcd_delay(1); break;
		 case 2:
		        Lcd_WriteAddress(0x4d);  // 设置显示位置为第一行的第1个字
                Lcd_delay(1);
				Lcd_WriteData('M');
				Lcd_delay(1);  break;
	     case 3:
		        Lcd_WriteAddress(0x4d);  // 设置显示位置为第一行的第1个字
                Lcd_delay(1);
				Lcd_WriteData('D');
				Lcd_delay(1);  break;
		  case 4:
		        Lcd_WriteAddress(0x4d);  // 设置显示位置为第一行的第1个字
                Lcd_delay(1);
				Lcd_WriteData('H');
				Lcd_delay(1);  break;
		  case 5:
		        Lcd_WriteAddress(0x4d);  // 设置显示位置为第一行的第1个字
                Lcd_delay(1);
				Lcd_WriteData('F');
				Lcd_delay(1);  break;
		}		                       
        }
		}

		if(a[2]==wl6)                              // 类似K2键	   向右切换年月日
 	{
			 QH_FLAG++;
			if(QH_FLAG>5)
			{ QH_FLAG=1;
			    }	
			  
	   switch(QH_FLAG)
		{case 1:
		        Lcd_WriteAddress(0x4d);  // 设置显示位置为第一行的第1个字
                Lcd_delay(1);
				Lcd_WriteData('Y');
				Lcd_delay(1); break;
		 case 2:
		        Lcd_WriteAddress(0x4d);  // 设置显示位置为第一行的第1个字
                Lcd_delay(1);
				Lcd_WriteData('M');
				Lcd_delay(1);  break;
	     case 3:
		        Lcd_WriteAddress(0x4d);  // 设置显示位置为第一行的第1个字
                Lcd_delay(1);
				Lcd_WriteData('D');
				Lcd_delay(1);  break;
		  case 4:
		        Lcd_WriteAddress(0x4d);  // 设置显示位置为第一行的第1个字
                Lcd_delay(1);
				Lcd_WriteData('H');
				Lcd_delay(1);  break;
		  case 5:
		        Lcd_WriteAddress(0x4d);  // 设置显示位置为第一行的第1个字
                Lcd_delay(1);
				Lcd_WriteData('F');
				Lcd_delay(1);  break;
		}		                       
			 a[2]=0;

   	  }
	  if(a[2]==wl7)                              // 类似K2键	   向左切换年月日
 	{
			 QH_FLAG--;
			if(QH_FLAG<1)
			{ QH_FLAG=5;
			    }	
			  
	   switch(QH_FLAG)
		{case 1:
		        Lcd_WriteAddress(0x4d);  // 设置显示位置为第一行的第1个字
                Lcd_delay(1);
				Lcd_WriteData('Y');
				Lcd_delay(1); break;
		 case 2:
		        Lcd_WriteAddress(0x4d);  // 设置显示位置为第一行的第1个字
                Lcd_delay(1);
				Lcd_WriteData('M');
				Lcd_delay(1);  break;
	     case 3:
		        Lcd_WriteAddress(0x4d);  // 设置显示位置为第一行的第1个字
                Lcd_delay(1);
				Lcd_WriteData('D');
				Lcd_delay(1);  break;
		  case 4:
		        Lcd_WriteAddress(0x4d);  // 设置显示位置为第一行的第1个字
                Lcd_delay(1);
				Lcd_WriteData('H');
				Lcd_delay(1);  break;
		  case 5:
		        Lcd_WriteAddress(0x4d);  // 设置显示位置为第一行的第1个字
                Lcd_delay(1);
				Lcd_WriteData('F');
				Lcd_delay(1);  break;
		}		                       
			 a[2]=0;

   	  }

	if(K3==0)                              // K3键用来进行加1调整
 	{
 		Lcd_delay(10);                      //延时去抖
      	if(K3==0)                                
 		{
			while(!K3);						//等待K3键释放
			Ds1302_beep();
			switch(QH_FLAG)
		{	case 1:       
			time_buf[6]=time_buf[6]+1;       		//年加1
       		if(time_buf[6]>99) time_buf[6]=0; 		//当分钟加到60时初始化为0
          	year16=time_buf[6]/10*16+time_buf[6]%10;  //将所得的分钟数据转变成16进制数据
			Ds1302_WriteSet(0x8c,year16);                //将调整后的分钟数据写入DS1302	reak
			Lcd_WriteAddress(0x07);    //写显示地址,将在第2行第7列开始显示
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[6]/10]);    //将百位数字的字符常量写入LCD,不能直接写入，必须转化
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[6]%10]);    //将十位数字的字符常量写入LCD
	        Lcd_delay(1);
			break;

			case 2:        
			time_buf[4]=time_buf[4]+1;       		//月加1
       		if(time_buf[4]>12) time_buf[4]=1; 		//当分钟加到60时初始化为0
          	month16=time_buf[4]/10*16+time_buf[4]%10;  //将所得的分钟数据转变成16进制数据
			Ds1302_WriteSet(0x88,month16);                //将调整后的分钟数据写入DS1302	reak
            Lcd_WriteAddress(0x0a);    //写显示地址,将在第2行第7列开始显示
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[4]/10]);    //将百位数字的字符常量写入LCD
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[4]%10]);    //将十位数字的字符常量写入LCD
	        Lcd_delay(1);
			break;

			case 3:        
			time_buf[3]=time_buf[3]+1;         //日加1  	
			 if((time_buf[4]==1)||(time_buf[4]==3)||(time_buf[4]==5)||(time_buf[4]==7)||(time_buf[4]==8)||(time_buf[4]==10)||(time_buf[4]==12))
			   {if(time_buf[3]>31)
				    time_buf[3]=1;  
				}
			if((time_buf[4]==4)||(time_buf[4]==6)||(time_buf[4]==9)||(time_buf[4]==11))
			   {if(time_buf[3]>30)
				    time_buf[3]=1;  
				}
			 if(time_buf[4]==2)
			 {	if((time_buf[6]%4)&&(time_buf[3]>28)) time_buf[3]=1;
			    if(!(time_buf[6]%4)&&(time_buf[3]>29)) time_buf[3]=1;
			 }
			 day16=time_buf[3]/10*16+time_buf[3]%10;
			 Ds1302_WriteSet(0x86,day16);                //将调整后的分钟数据写入DS1302	reak
		     Lcd_WriteAddress(0x0d);    //写显示地址,将在第2行第7列开始显示
	         Lcd_delay(1);
	         Lcd_WriteData(digit[time_buf[3]/10]);    //将百位数字的字符常量写入LCD
	         Lcd_delay(1);
	         Lcd_WriteData(digit[time_buf[3]%10]);    //将十位数字的字符常量写入LCD
	         Lcd_delay(1);
			 break;

			 case 4:        
			 time_buf[2]=time_buf[2]+1;       		//小时加1
       		 if(time_buf[2]>23) time_buf[2]=0; 		//当分钟加到60时初始化为0
          	 hour16=time_buf[2]/10*16+time_buf[2]%10;  //将所得的分钟数据转变成16进制数据
			 Ds1302_WriteSet(0x84,hour16);                //将调整后的分钟数据写入DS1302	reak
			 Lcd_WriteAddress(0x43);    //写显示地址,将在第2行第7列开始显示
	         Lcd_delay(1);
	         Lcd_WriteData(digit[time_buf[2]/10]);    //将百位数字的字符常量写入LCD
	         Lcd_delay(1);
	         Lcd_WriteData(digit[time_buf[2]%10]);    //将十位数字的字符常量写入LCD
	         Lcd_delay(1);
       		 break;

			 case 5:        
			time_buf[1]=time_buf[1]+1;       		//小时加1
       		if(time_buf[1]>59) time_buf[1]=0; 		//当分钟加到60时初始化为0
          	min16=time_buf[1]/10*16+time_buf[1]%10;  //将所得的分钟数据转变成16进制数据
			Ds1302_WriteSet(0x82,min16);                //将调整后的分钟数据写入DS1302	reak
			Lcd_WriteAddress(0x46);    //写显示地址,将在第2行第7列开始显示
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[1]/10]);    //将百位数字的字符常量写入LCD
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[1]%10]);    //将十位数字的字符常量写入LCD
	        Lcd_delay(1);
       		 break;
			 }

   	  }
 	}

		if(a[2]==wl4)   							//红外 加
		{  
		switch(QH_FLAG)
		{	case 1:       
			time_buf[6]=time_buf[6]+1;       		//年加1
       		if(time_buf[6]>99) time_buf[6]=0; 		//当分钟加到60时初始化为0
          	year16=time_buf[6]/10*16+time_buf[6]%10;  //将所得的分钟数据转变成16进制数据
			Ds1302_WriteSet(0x8c,year16);                //将调整后的分钟数据写入DS1302	reak
			Lcd_WriteAddress(0x07);    //写显示地址,将在第2行第7列开始显示
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[6]/10]);    //将百位数字的字符常量写入LCD,不能直接写入，必须转化
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[6]%10]);    //将十位数字的字符常量写入LCD
	        Lcd_delay(1);
			break;

			case 2:        
			time_buf[4]=time_buf[4]+1;       		//月加1
       		if(time_buf[4]>12) time_buf[4]=1; 		//当分钟加到60时初始化为0
          	month16=time_buf[4]/10*16+time_buf[4]%10;  //将所得的分钟数据转变成16进制数据
			Ds1302_WriteSet(0x88,month16);                //将调整后的分钟数据写入DS1302	reak
            Lcd_WriteAddress(0x0a);    //写显示地址,将在第2行第7列开始显示
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[4]/10]);    //将百位数字的字符常量写入LCD
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[4]%10]);    //将十位数字的字符常量写入LCD
	        Lcd_delay(1);
			break;

			case 3:        
			time_buf[3]=time_buf[3]+1;         //日加1	考虑闰年 月份
			if((time_buf[4]==1)||(time_buf[4]==3)||(time_buf[4]==5)||(time_buf[4]==7)||(time_buf[4]==8)||(time_buf[4]==10)||(time_buf[4]==12))
			   {if(time_buf[3]>31)
				    time_buf[3]=1;  
				}
			if((time_buf[4]==4)||(time_buf[4]==6)||(time_buf[4]==9)||(time_buf[4]==11))
			   {if(time_buf[3]>30)
				    time_buf[3]=1;  
				}
			 if(time_buf[4]==2)
			 {	if((time_buf[6]%4)&&(time_buf[3]>28)) time_buf[3]=1;
			    if(!(time_buf[6]%4)&&(time_buf[3]>29)) time_buf[3]=1;
			 }
			 day16=time_buf[3]/10*16+time_buf[3]%10;
			 Ds1302_WriteSet(0x86,day16);                //将调整后的分钟数据写入DS1302	reak
		     Lcd_WriteAddress(0x0d);    //写显示地址,将在第2行第7列开始显示
	         Lcd_delay(1);
	         Lcd_WriteData(digit[time_buf[3]/10]);    //将百位数字的字符常量写入LCD
	         Lcd_delay(1);
	         Lcd_WriteData(digit[time_buf[3]%10]);    //将十位数字的字符常量写入LCD
	         Lcd_delay(1);
			 break;

			 case 4:        
			 time_buf[2]=time_buf[2]+1;       		//小时加1
       		 if(time_buf[2]>23) time_buf[2]=0; 		//当分钟加到60时初始化为0
          	 hour16=time_buf[2]/10*16+time_buf[2]%10;  //将所得的分钟数据转变成16进制数据
			 Ds1302_WriteSet(0x84,hour16);                //将调整后的分钟数据写入DS1302	reak
			 Lcd_WriteAddress(0x43);    //写显示地址,将在第2行第7列开始显示
	         Lcd_delay(1);
	         Lcd_WriteData(digit[time_buf[2]/10]);    //将百位数字的字符常量写入LCD
	         Lcd_delay(1);
	         Lcd_WriteData(digit[time_buf[2]%10]);    //将十位数字的字符常量写入LCD
	         Lcd_delay(1);
       		 break;

			 case 5:        
			time_buf[1]=time_buf[1]+1;       		//小时加1
       		if(time_buf[1]>59) time_buf[1]=0; 		//当分钟加到60时初始化为0
          	min16=time_buf[1]/10*16+time_buf[1]%10;  //将所得的分钟数据转变成16进制数据
			Ds1302_WriteSet(0x82,min16);                //将调整后的分钟数据写入DS1302	reak
			Lcd_WriteAddress(0x46);    //写显示地址,将在第2行第7列开始显示
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[1]/10]);    //将百位数字的字符常量写入LCD
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[1]%10]);    //将十位数字的字符常量写入LCD
	        Lcd_delay(1);
       		 break;
			 }
			a[2]=0;
   	  }


	   if(K4==0)                              // 减
 	{		Lcd_delay(10);                      //延时去抖
      	if(K4==0)                                
 		 {
			while(!K4);						//等待K4键释放
			Ds1302_beep();
			switch(QH_FLAG)
		   {	
		    case 1:       
			time_buf[6]=time_buf[6]-1;       		//年减1
       		if(time_buf[6]<0) time_buf[6]=99; 		//当年到60时初始化为0
          	year16=time_buf[6]/10*16+time_buf[6]%10;  //将所得的分钟数据转变成16进制数据
			Ds1302_WriteSet(0x8c,year16);                //将调整后的分钟数据写入DS1302	reak
			Lcd_WriteAddress(0x07);    //写显示地址,将在第2行第7列开始显示
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[6]/10]);    //将百位数字的字符常量写入LCD,不能直接写入，必须转化
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[6]%10]);    //将十位数字的字符常量写入LCD
	        Lcd_delay(1);
			break;
			case 2:        
			time_buf[4]=time_buf[4]-1;       		//年减1
       		if(time_buf[4]<1) time_buf[4]=12; 		//当分钟加到60时初始化为0
          	month16=time_buf[4]/10*16+time_buf[4]%10;  //将所得的分钟数据转变成16进制数据
			Ds1302_WriteSet(0x88,month16);                //将调整后的分钟数据写入DS1302	reak
			Lcd_WriteAddress(0x0a);    //写显示地址,将在第2行第7列开始显示
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[4]/10]);    //将百位数字的字符常量写入LCD,不能直接写入，必须转化
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[4]%10]);    //将十位数字的字符常量写入LCD
	        Lcd_delay(1);
			break;
			case 3:        
			time_buf[3]=time_buf[3]-1;       		//年减1
       		if((time_buf[4]==1)||(time_buf[4]==3)||(time_buf[4]==5)||(time_buf[4]==7)||(time_buf[4]==8)||(time_buf[4]==10)||(time_buf[4]==12))
			   {if(time_buf[3]<1)
				    time_buf[3]=31;  
				}
			if((time_buf[4]==4)||(time_buf[4]==6)||(time_buf[4]==9)||(time_buf[4]==11))
			   {if(time_buf[3]<1)
				    time_buf[3]=30;  
				}
			 if(time_buf[4]==2)
			 {	if((time_buf[6]%4)&&(time_buf[3]<1)) time_buf[3]=28;
			    if(!(time_buf[6]%4)&&(time_buf[3]<1)) time_buf[3]=29;
			 }
          	day16=time_buf[3]/10*16+time_buf[3]%10;  //将所得的分钟数据转变成16进制数据
			Ds1302_WriteSet(0x86,day16);                //将调整后的分钟数据写入DS1302	reak
			Lcd_WriteAddress(0x0d);    //写显示地址,将在第2行第7列开始显示
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[3]/10]);    //将百位数字的字符常量写入LCD,不能直接写入，必须转化
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[3]%10]);    //将十位数字的字符常量写入LCD
	        Lcd_delay(1);
			break;
			 case 4:        
			time_buf[2]=time_buf[2]-1;       		//年减1
       		if(time_buf[2]<0) time_buf[2]=23; 		//当分钟加到60时初始化为0
          	hour16=time_buf[2]/10*16+time_buf[2]%10;  //将所得的分钟数据转变成16进制数据
			Ds1302_WriteSet(0x84,hour16);                //将调整后的分钟数据写入DS1302	reak
			Lcd_WriteAddress(0x43);    //写显示地址,将在第2行第7列开始显示
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[2]/10]);    //将百位数字的字符常量写入LCD,不能直接写入，必须转化
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[2]%10]);    //将十位数字的字符常量写入LCD
	        Lcd_delay(1);
			break;

			 case 5:        
			time_buf[1]=time_buf[1]-1;       		//年减1
       		if(time_buf[1]<0) time_buf[1]=59; 		//当分钟加到60时初始化为0
          	min16=time_buf[1]/10*16+time_buf[1]%10;  //将所得的分钟数据转变成16进制数据
			Ds1302_WriteSet(0x82,min16);                //将调整后的分钟数据写入DS1302	reak
			Lcd_WriteAddress(0x46);    //写显示地址,将在第2行第7列开始显示
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[1]/10]);    //将百位数字的字符常量写入LCD,不能直接写入，必须转化
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[1]%10]);    //将十位数字的字符常量写入LCD
	        Lcd_delay(1);
			break;
	}
	}

   	}
	  if(a[2]==wl5)                              // 红外减
 	{
			switch(QH_FLAG)
		   {	
		    case 1:       
			time_buf[6]=time_buf[6]-1;       		//年减1
       		if(time_buf[6]<0) time_buf[6]=99; 		//当年到60时初始化为0
          	year16=time_buf[6]/10*16+time_buf[6]%10;  //将所得的分钟数据转变成16进制数据
			Ds1302_WriteSet(0x8c,year16);                //将调整后的分钟数据写入DS1302	reak
			Lcd_WriteAddress(0x07);    //写显示地址,将在第2行第7列开始显示
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[6]/10]);    //将百位数字的字符常量写入LCD,不能直接写入，必须转化
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[6]%10]);    //将十位数字的字符常量写入LCD
	        Lcd_delay(1);
			break;
			case 2:        
			time_buf[4]=time_buf[4]-1;       		//月减1
       		if(time_buf[4]<1) time_buf[4]=12; 		//当分钟加到60时初始化为0
          	month16=time_buf[4]/10*16+time_buf[4]%10;  //将所得的分钟数据转变成16进制数据
			Ds1302_WriteSet(0x88,month16);                //将调整后的分钟数据写入DS1302	reak
			Lcd_WriteAddress(0x0a);    //写显示地址,将在第2行第7列开始显示
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[4]/10]);    //将百位数字的字符常量写入LCD,不能直接写入，必须转化
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[4]%10]);    //将十位数字的字符常量写入LCD
	        Lcd_delay(1);
			break;
			case 3:        
			time_buf[3]=time_buf[3]-1;       		//日减1
       		if((time_buf[4]==1)||(time_buf[4]==3)||(time_buf[4]==5)||(time_buf[4]==7)||(time_buf[4]==8)||(time_buf[4]==10)||(time_buf[4]==12))
			   {if(time_buf[3]<1)
				    time_buf[3]=31;  
				}
			if((time_buf[4]==4)||(time_buf[4]==6)||(time_buf[4]==9)||(time_buf[4]==11))
			   {if(time_buf[3]<1)
				    time_buf[3]=30;  
				}
			 if(time_buf[4]==2)
			 {	if((time_buf[6]%4)&&(time_buf[3]<1)) time_buf[3]=28;
			    if(!(time_buf[6]%4)&&(time_buf[3]<1)) time_buf[3]=29;
			 }
          	day16=time_buf[3]/10*16+time_buf[3]%10;  //将所得的分钟数据转变成16进制数据
			Ds1302_WriteSet(0x86,day16);                //将调整后的分钟数据写入DS1302	reak
			Lcd_WriteAddress(0x0d);    //写显示地址,将在第2行第7列开始显示
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[3]/10]);    //将百位数字的字符常量写入LCD,不能直接写入，必须转化
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[3]%10]);    //将十位数字的字符常量写入LCD
	        Lcd_delay(1);
			break;
			 case 4:        
			time_buf[2]=time_buf[2]-1;       		//年减1
       		if(time_buf[2]<0) time_buf[2]=23; 		//当分钟加到60时初始化为0
          	hour16=time_buf[2]/10*16+time_buf[2]%10;  //将所得的分钟数据转变成16进制数据
			Ds1302_WriteSet(0x84,hour16);                //将调整后的分钟数据写入DS1302	reak
			Lcd_WriteAddress(0x43);    //写显示地址,将在第2行第7列开始显示
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[2]/10]);    //将百位数字的字符常量写入LCD,不能直接写入，必须转化
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[2]%10]);    //将十位数字的字符常量写入LCD
	        Lcd_delay(1);
			break;

			 case 5:        
			time_buf[1]=time_buf[1]-1;       		//年减1
       		if(time_buf[1]<0) time_buf[1]=59; 		//当分钟加到60时初始化为0
          	min16=time_buf[1]/10*16+time_buf[1]%10;  //将所得的分钟数据转变成16进制数据
			Ds1302_WriteSet(0x82,min16);                //将调整后的分钟数据写入DS1302	reak
			Lcd_WriteAddress(0x46);    //写显示地址,将在第2行第7列开始显示
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[1]/10]);    //将百位数字的字符常量写入LCD,不能直接写入，必须转化
	        Lcd_delay(1);
	        Lcd_WriteData(digit[time_buf[1]%10]);    //将十位数字的字符常量写入LCD
	        Lcd_delay(1);
			break;
	}
			 a[2]=0;

   	}

 	if(K1==0)				//K1键是确认键
	{
		Lcd_delay(10);		//延时去抖
		if(K1==0)
		{
			while(!K1);			//等待K4键释放
			Ds1302_beep();
			Ds1302_WriteSet(0x80,0x00);  //调整完毕后，启动时钟运行
 			Ds1302_WriteSet(0x8e,0x80);  //写保护控制字，禁止写
			K1_FLAG=0;			//将K1键按下标志位清零 
			Lcd_WriteAddress(0x4d);  // 设置显示位置为第一行的第1个字
            Lcd_delay(1);
		    Lcd_WriteData(' ');
		    Lcd_delay(1 );  
		}
	}
	if(a[2]==wl2)				//K4键是确认键
	{
		
			
			Ds1302_WriteSet(0x80,0x00);  //调整完毕后，启动时钟运行
 			Ds1302_WriteSet(0x8e,0x80);  //写保护控制字，禁止写
			K1_FLAG=0;			//将K1键按下标志位清零 
			 Lcd_WriteAddress(0x4d);  // 设置显示位置为第一行的第1个字
                Lcd_delay(1);
				Lcd_WriteData(' ');
				Lcd_delay(1); 
				a[2]=0; 
	}
}
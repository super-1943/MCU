					

#include<intrins.h>  //包含_nop_()函数定义的头文件
#include<1602.h>

unsigned char code string1[ ]= {"WELCOME TO YAN "};   //第一行显示的字符
unsigned char code string2[ ]={"SHAN UNIVERSITY"};	  //第二行显示的字符

/*****************************************************
函数功能：延时1ms
注：不同单片机不同晶振需要对此函数进行修改
***************************************************/
void Lcd_delay1ms()
{
   		unsigned char i,j;	
	 	for(i=0;i<25;i++)
	  	for(j=0;j<33;j++);		 
 }
 /*****************************************************
函数功能：延时若干毫秒
入口参数：n
***************************************************/
 void Lcd_delay(unsigned int n)
 {
   	unsigned int i;
	for(i=0;i<n;i++)
	Lcd_delay1ms();
 }
/*****************************************************
函数功能：判断液晶模块的忙碌状态
返回值：result。result=1，忙碌;result=0，不忙
***************************************************/
 bit Lcd_BusyTest(void)
  {
    	bit result;
		RS=0;       //根据规定，RS为低电平，RW为高电平时，可以读状态
    	RW=1;
    	E=1;        //E=1，才允许读写
    	_nop_();   //空操作
    	_nop_();
    	_nop_(); 
   		_nop_();   //空操作四个机器周期，给硬件反应时间	
    	result=BF;  //将忙碌标志电平赋给result
		E=0;
    	return result;
  }
/*****************************************************
函数功能：将模式设置指令或显示地址写入液晶模块
入口参数：dictate
***************************************************/
void Lcd_WriteCom (unsigned char dictate)
{   
    while(Lcd_BusyTest()==1); //如果忙就等待
	 RS=0;                  //根据规定，RS和R/W同时为低电平时，可以写入指令
	 RW=0;   
	 E=0;                   //E置低电平(写指令时，
                             // 就是让E从0到1发生正跳变，所以应先置"0"
	 _nop_();
	 _nop_();             //空操作两个机器周期，给硬件反应时间
	 Lcd_Data=dictate;            //将数据送入P0口，即写入指令或地址
	 _nop_();
	 _nop_();
	 _nop_();
	 _nop_();               //空操作四个机器周期，给硬件反应时间
	 E=1;                   //E置高电平
	 _nop_();
	 _nop_();
	 _nop_();
	 _nop_();               //空操作四个机器周期，给硬件反应时间
	  E=0;                  //当E由高电平跳变成低电平时，液晶模块开始执行命令
 }
/*****************************************************
函数功能：指定字符显示的实际地址
入口参数：x
注：此函数已经加上了0x80,故只需写上实际地址就行
***************************************************/
 void Lcd_WriteAddress(unsigned char x)
 {
     Lcd_WriteCom(x|0x80); //显示位置的确定方法规定为"80H+地址码x"	
 }
/*****************************************************
函数功能：将数据(字符的标准ASCII码)写入液晶模块
入口参数：y(为字符常量)
***************************************************/
 void Lcd_WriteData(unsigned char y)
 {
    while(Lcd_BusyTest()==1);  
	  RS=1;           //RS为高电平，RW为低电平时，可以写入数据
	  RW=0;
	  E=0;            //E置低电平(写指令时，，
                       // 就是让E从0到1发生正跳变，所以应先置"0"
	  Lcd_Data=y;           //将数据送入P0口，即将数据写入液晶模块
	  _nop_();
	  _nop_();
 	  _nop_();
    	  _nop_();       //空操作四个机器周期，给硬件反应时间
	  E=1;          //E置高电平
	  _nop_();
	  _nop_();
	  _nop_();
	  _nop_();        //空操作四个机器周期，给硬件反应时间
	  E=0;            //当E由高电平跳变成低电平时，液晶模块开始执行命令
 }
/*****************************************************
函数功能：对LCD的显示模式进行初始化设置
***************************************************/
void Lcd_Int(void)
{
   	Lcd_delay(15);             //延时15ms，首次写指令时应给LCD一段较长的反应时间
   	Lcd_WriteCom(0x38);  //显示模式设置：16×2显示，5×7点阵，8位数据接口
	Lcd_delay(5);   //延时5ms　
	Lcd_WriteCom(0x38);
	Lcd_delay(5);
	Lcd_WriteCom(0x38); //3次写 设置模式
	Lcd_delay(5);
	Lcd_WriteCom(0x0C);  //显示模式设置：显示开，有光标，光标闪烁
	Lcd_delay(5);
	Lcd_WriteCom(0x06);  //显示模式设置：光标右移，字符不移
	Lcd_delay(5);											  
	Lcd_WriteCom(0x01);  //清屏幕指令，将以前的显示内容清除
	Lcd_delay(5);
 }
 void hanying_show(void)
 {  unsigned char Lcd_i;
 Lcd_WriteCom(0x01);//清显示：清屏幕指令
	Lcd_delay(5);
	Lcd_WriteAddress(0x00);  // 设置显示位置为第一行的第1个字
    Lcd_delay(5);
	Lcd_i=0;
	while(string1[Lcd_i] != '\0')    //'\0'是数组结束标志   // 显示字符WELCOM TO YAN
	  {						
		  Lcd_WriteData(string1[Lcd_i]);
		  Lcd_i++;
		  Lcd_delay(150);
	   }			  
								 
	Lcd_WriteAddress(0x40);  // 设置显示位置为第二行的第1个字
	 Lcd_i = 0;
	while(string2[Lcd_i] != '\0')   //'\0'是数组结束标志
	  {						// 显示字符	SHAN UNIVERSITY
		  Lcd_WriteData(string2[Lcd_i]);
		  Lcd_i++;
		  Lcd_delay(150);
	   }  
	 Lcd_delay(1500);	
			    
      //右侧移位进来
	Lcd_WriteCom(0x01);//清显示：清屏幕指令
	Lcd_delay(5);
	Lcd_WriteAddress(0x10);  // 设置显示位置为最右侧
	Lcd_delay(5);
	Lcd_i = 0;
	while(string1[Lcd_i] != '\0')    //'\0'是数组结束标志   	  需先将字符存入
	{						
	    Lcd_WriteData(string1[Lcd_i]);	 // 显示字符	WELCOM TO YAN
	    Lcd_i++;	
	    Lcd_delay(5);
	}
	Lcd_WriteAddress(0x50);  // 设置显示位置为第二行的第1个字
	Lcd_i = 0;
	while(string2[Lcd_i] != '\0')   //'\0'是数组结束标志
		{						// 显示字符	HAN UNIVERSITY
	    	Lcd_WriteData(string2[Lcd_i]);
			Lcd_i++;
			Lcd_delay(5);
		}
	for(Lcd_i=0;Lcd_i<16;Lcd_i++ )  //开始左移
		{
			Lcd_WriteCom(0x18); //左移指令
        	Lcd_delay(500);	   
					  
		}				
     Lcd_delay(1000);
	 Lcd_WriteCom(0x08);
	 Lcd_delay(400);
	 Lcd_WriteCom(0x0c);
	 Lcd_delay(400);
	 Lcd_WriteCom(0x08);
	 Lcd_delay(400);
	 Lcd_WriteCom(0x0c);
	 Lcd_delay(400);
	 Lcd_WriteCom(0x08);
	 Lcd_delay(400);
	 Lcd_WriteCom(0x0c);
	 Lcd_delay(400);
	 Lcd_WriteCom(0x08);
	 Lcd_delay(400);
	 Lcd_WriteCom(0x0c);
	 Lcd_delay(1);
	 Lcd_WriteCom(0x01);
	  Lcd_delay(1);

	 
   } 
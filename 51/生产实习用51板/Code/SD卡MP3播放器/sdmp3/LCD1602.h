
#include<intrins.h>  //包含_nop_()函数定义的头文件
sbit RS=P3^7;    //寄存器选择位，将RS位定义为P2.0引脚
sbit RW=P3^6;    //读写选择位，将RW位定义为P2.1引脚
sbit E=P2^7;     //使能信号位，将E位定义为P2.2引脚
sbit BF=P0^7;    //忙碌标志位，，将BF位定义为P0.7引脚
unsigned char code string[ ]= {"WELCOME TO YAN "}; 
unsigned char code string1[ ]={"SHAN UNIVERSITY"};
unsigned char code string2[ ]= {"      INIT "};
unsigned char code string3[ ]= {"  PLEASE WAIT"};
/*****************************************************
函数功能：延时1ms
***************************************************/
void delay1ms()
{
   		unsigned char i,j;	
	 	for(i=0;i<10;i++)
	  	for(j=0;j<33;j++)
	   ;		 
 }
 /*****************************************************
函数功能：延时若干毫秒
入口参数：n
***************************************************/
 void Lcddelay(unsigned int n)
 {
   	unsigned int i;
	for(i=0;i<n;i++)
	delay1ms();
 }
/*****************************************************
函数功能：判断液晶模块的忙碌状态
返回值：result。result=1，忙碌;result=0，不忙
***************************************************/
 bit BusyTest(void)
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
void Write_com (unsigned char dictate)
{   
    while(BusyTest()==1); //如果忙就等待
	 RS=0;                  //根据规定，RS和R/W同时为低电平时，可以写入指令
	 RW=0;   
	 E=0;                   //E置低电平(写指令时，
                             // 就是让E从0到1发生正跳变，所以应先置"0"
	 _nop_();
	 _nop_();             //空操作两个机器周期，给硬件反应时间
	 P0=dictate;            //将数据送入P0口，即写入指令或地址
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
***************************************************/
 void WriteAddress(unsigned char x)
 {
     Write_com(x|0x80); //显示位置的确定方法规定为"80H+地址码x"	
 }
/*****************************************************
函数功能：将数据(字符的标准ASCII码)写入液晶模块
入口参数：y(为字符常量)
***************************************************/
 void WriteData(unsigned char y)
 {
    while(BusyTest()==1);  
	  RS=1;           //RS为高电平，RW为低电平时，可以写入数据
	  RW=0;
	  E=0;            //E置低电平(写指令时，，
                       // 就是让E从0到1发生正跳变，所以应先置"0"
	  P0=y;           //将数据送入P0口，即将数据写入液晶模块
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
void LcdInt(void)
{
   	Lcddelay(15);             //延时15ms，首次写指令时应给LCD一段较长的反应时间
   	Write_com(0x38);  //显示模式设置：16×2显示，5×7点阵，8位数据接口
	Lcddelay(5);   //延时5ms　
	Write_com(0x38);
	Lcddelay(5);
	Write_com(0x38); //3次写 设置模式
	Lcddelay(5);
	Write_com(0x0C);  //显示模式设置：显示开，有光标，光标闪烁
	Lcddelay(5);
	Write_com(0x06);  //显示模式设置：光标右移，字符不移
	Lcddelay(5);											  
	Write_com(0x01);  //清屏幕指令，将以前的显示内容清除
	Lcddelay(5);
 }
 /**************************************************
 函数功能：直接调用该函数即可完成相应的显示
 ************************************************/
 void LcdShow(void)
 {unsigned char Lcd_i,Lcd_j;
    LcdInt();         //调用LCD初始化函数  
    Lcddelay(10);
    Write_com(0x01);//清显示：清屏幕指令
    Lcddelay(5);
    WriteAddress(0x00);  // 设置显示位置为第一行的第1个字
    Lcddelay(5);
    Lcd_i = 0;
	     while(string[Lcd_i] != '\0')    //'\0'是数组结束标志 
			{						// 显示字符WELCOM TO YAN
					WriteData(string[Lcd_i]);
					Lcd_i++;
					Lcddelay(650);
			}			  

			 WriteAddress(0x40);  // 设置显示位置为第二行的第1个字
	  	     Lcd_i = 0;
		while(string1[Lcd_i] != '\0')   //'\0'是数组结束标志
			{						// 显示字符	SHAN UNIVERSITY
					WriteData(string1[Lcd_i]);
					Lcd_i++;
					Lcddelay(650);
			}  
		Lcddelay(3000);	
			    

					//右侧移位进来
				 	Write_com(0x01);//清显示：清屏幕指令
				 	Lcddelay(30);
		 			WriteAddress(0x10);  // 设置显示位置为最右侧
					Lcddelay(30);
	  	     		Lcd_i = 0;
		while(string[Lcd_i] != '\0')    //'\0'是数组结束标志 
			{						// 显示字符	WELCOM TO YAN
					WriteData(string[Lcd_i]);
					Lcd_i++;	
					Lcddelay(10);
			}
			
			 WriteAddress(0x50);  // 设置显示位置为第二行的第1个字
	  	     Lcd_i = 0;
		while(string[Lcd_i] != '\0')   //'\0'是数组结束标志
			{						// 显示字符	HAN UNIVERSITY
					WriteData(string1[Lcd_i]);
					Lcd_i++;
					Lcddelay(10);
			}
			for(Lcd_j=0;Lcd_j<16;Lcd_j++ ) 
			{
				Write_com(0x18); //左移指令
				for(Lcd_i=0;Lcd_i<10;Lcd_i++)
        		Lcddelay(100);	   
					  
			}				
        	Lcddelay(3000);	
 } 
void LcdShow_init(void)
{ 	unsigned char Lcd_i;
 Write_com(0x01);//清显示：清屏幕指令
    Lcddelay(5);
    WriteAddress(0x00);  // 设置显示位置为第一行的第1个字
    Lcddelay(5);
    Lcd_i = 0;
	     while(string2[Lcd_i] != '\0')    //'\0'是数组结束标志 
			{						// 显示字符WELCOM TO YAN
					WriteData(string2[Lcd_i]);
					Lcd_i++;
					Lcddelay(150);
			}			  

			 WriteAddress(0x40);  // 设置显示位置为第二行的第1个字
	  	     Lcd_i = 0;
		while(string3[Lcd_i] != '\0')   //'\0'是数组结束标志
			{						// 显示字符	SHAN UNIVERSITY
					WriteData(string3[Lcd_i]);
					Lcd_i++;
					Lcddelay(150);
			}  
}
void UART_Send_Str1(char *s)
{  unsigned char Lcd_j;
Write_com(0x01);//清显示：清屏幕指令
    Lcddelay(5);
    WriteAddress(0x00);  // 设置显示位置为第一行的第1个字
    Lcddelay(5);
    Lcd_j = 0;
	     while(s[Lcd_j] != '\0')    //'\0'是数组结束标志 
			{						// 显示字符WELCOM TO YAN
					WriteData(s[Lcd_j]);
					Lcd_j++;
					Lcddelay(150);
			}	
}
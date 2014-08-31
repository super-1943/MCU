#include<reg52.h>       //包含单片机寄存器的头文件
#include<1602.h>
#include<1302.h>
#include<18b20.h>
#include<hongwai.h>
unsigned char code string[ ]= {"1602IR-CODE TEST"};
extern unsigned char keyflag;
void main()
{  unsigned char Hw_i;
Ds1302_Int();       //将1302初始化
 Lcd_Int();			 //1602初始化
 Hw_Int();
 //hanying_show();
 while(1)
 {   if(!keyflag)			//显示时间
     {
	 Ds1302_QLShow();	 //在对应位置显示data——
      time_get_show(); //获取时间
	  }
	  if(keyflag==1)
	  {	if(DS18B20_Init()==1)	  //在判断的同时又进行了初始化
	  DS18B20_display_error();	
	  else{DS18B20_display_explain();	  //显示温度说明
   	   DS18B20_display_symbol();     //显示温度符号
       DS18B20_display_dot();       //显示温度的小数点
       DS18B20_display_cent();      //显示温度的单位
	   Ds18B20_GetTemperture();		//读取温度值
	   Ds18B20_TempConv();			//将温度转换为适合LCD显示的数据
	   Ds18B20_Display();	  
	      }
	  }
	  if(keyflag==2)
	  {Lcd_WriteAddress(0x00);  // 设置显示位置为第一行的第1个字
	  Hw_delay(5);
	  Hw_i = 0;
		while(string[Hw_i] != '\0')    //'\0'是数组结束标志 
			{						// 显示字符	WWW.RICHMCU.COM
				Lcd_WriteData(string[Hw_i]);
				Hw_i++;
				Hw_delay(5);	
			}
			Hw_Disp();	 
        }
   }
   }
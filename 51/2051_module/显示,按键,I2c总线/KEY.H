/*****************************************************************
   文件名称：key.h  (行列式键盘扫描程序) 
   作 者： 	 徐修亮
   版 本： 
   说 明：
   日期 :    2008 4 26 
   修改记录：2008 7 20 14:00  修改后能直接返回0-16的键值 
   			 2008 7 20  17:30  优化了代码

 *******************************************************************/
#ifndef __key_h__
#define __key_h__


#include <reg51.h>
#define uchar unsigned char 
#define PORT P2  //义键盘行列端口，低位为行，高位为列，
 uchar scan (void);
 uchar key(void);	
 void delay100us(uchar t);


/*********************************************************
  	  函数名称：uchar key(void) 
      函数功能：按顺充返回键值0到15,其中若为16则说明无键按下  
      入口参数：无 
      出口参数：uchar key() 即返回的键值 
      备 注： 利用算法对代码进行优化使程序与前面的单独进行比较
	          方法相比,代码减少96个字节 ,虽然RAM多两个

***********************************************************/
uchar key(void)
{ uchar y,high4,low4,temp,i,j;
  y=scan();
  if(y==0) temp=16;
  else 
  {	 
    high4=0x10;
	low4 =0x01;
    for(i=0;i<4;i++)
	for(j=0;j<4;j++)
	  {	
	     if(y==(high4<<j)+(low4<<i)) 
	             temp=4*i+j;
				 }
	}
    return temp ;
}
   
   /*************************************************
         函数名称：uchar key(uchar x) 
         函数功能：按顺充返回键值0到15,其中若为16则说明无键按下  
         入口参数：无 
         出口参数：uchar key() 即返回的键值 
         备 注： 
 *************************************************/
/*
  uchar key(void)
{ 	uchar temp ;
    switch(scan())
 {
   case 0     :	temp=16  ; break;       //无键按下返回16
   case 0x11  : temp=0   ; break; 	    //返回键值
   case 0x21  : temp=1   ; break;
   case 0x41  : temp=2   ; break;
   case 0x81  : temp=3   ; break;
   case 0x12  : temp=4   ; break;
   case 0x22  : temp=5   ; break;
   case 0x42  : temp=6   ; break;
   case 0x82  : temp=7   ; break;
   case 0x14  : temp=8   ; break;
   case 0x24  : temp=9   ; break;
   case 0x44  : temp=10  ; break;
   case 0x84  : temp=11  ; break;
   case 0x18  : temp=12  ; break;
   case 0x28  : temp=13  ; break;
   case 0x48  : temp=14  ; break;
   case 0x88  : temp=15	 ; break;
   						  
 }
  	return temp ;
}		
			*/


		

 uchar scan(void)
 { uchar idata  sccode;
   uchar idata  recode;
   PORT =0xf0;
  if((PORT&0xf0)!=0xf0)    
   {	  delay100us(100);	                	// 延时10ms去抖动
  	 if ((PORT&0xf0)!=0xf0)           
     {	sccode=0xfe;   
	   while((sccode&0x10)!=0)              //没有扫描到最后一行，则往下执行
  	
	   { PORT=sccode;  	
		if((PORT&0xf0)!=0xf0)               //若有键按下则往下执行
		 {  recode=(PORT&0xf0)|0x0f;
		   return ( (~sccode)+(~recode)) ;	//特征值
	      }	
        else 
	       sccode=((sccode<<1)|0x01);
	     }
    }				 
   }
 }
    /******************************
         函数名称：delay(uchar t) 
         函数功能：  延时t/10 ms 
         入口参数： 	uchar t 
         出口参数： 	无
         备 注： 	
   ******************************/
  void delay100us(uchar t)
  {	
     uchar  j;
	 while(t--)
	   {
	   for (j=50 ;j>0;j--);
	   }
   }

   /******************************************************/
     #endif 
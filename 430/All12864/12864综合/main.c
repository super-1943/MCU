//说明:为了避免clear()函数带来的闪烁，在动态显示图片时将其屏蔽了
#include <msp430x15x.h>
#include"12864module.h"
int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  int i=130,j,k;//i调节延时
  init_12864();
 while(1)
 {  show_shuzi(24,0,0);
   show_shuzi(32,0,7);
   show_hanzi(hanzi2,40,0,4,0);
   show_shuzi(14,4,2);
   show_shuzi(22,4,0);
   show_shuzi(30,4,0);
   show_shuzi(38,4,9);
   show_hanzi(hanzi3,46,4,1,0);
   show_shuzi(62,4,7);
   show_hanzi(hanzi3,70,4,1,1);
   show_shuzi(86,4,2);
   show_shuzi(94,4,3);
   show_hanzi(hanzi3,102,4,1,2);
   delay(5000);
   clear();
  for(j=0;j<5;j++)
   { show_picture(picture_sl_1,19,32);
    delay(i);
    show_picture(picture_sl_2,19,32);
    delay(i);
    show_picture(picture_sl_3,19,32);
    delay(i);
    show_picture(picture_sl_4,19,32);
    delay(i);
    show_picture(picture_sl_5,19,32);
    delay(i);
    show_picture(picture_sl_6,19,32);
    delay(i);
    show_picture(picture_sl_7,19,32);
    delay(i);
    }
   clear();
     show_hanzi(hanzi1,0,0,6,0);
     show_hanzi(hanzi1,0,2,6,6);
     show_hanzi(hanzi1,0,4,6,12);
     show_hanzi(hanzi1,0,6,6,18);
     for(k=0;k<2;k++)
     for(j=0x40;j<0x80;j++)
      { delay(150);
       send_cmd(j);
       if(j==0x40)
         delay(2000);
      }
     clear();
 for(j=0;j<5;j++)
   { show_picture(picture_sl_1,19,32);
  delay(i);
  show_picture(picture_sl_2,19,32);
 delay(i);
 show_picture(picture_sl_3,19,32);
  delay(i);
  show_picture(picture_sl_4,19,32);
delay(i);
 show_picture(picture_sl_5,19,32);
 delay(i);
  show_picture(picture_sl_6,19,32);
 delay(i);
 show_picture(picture_sl_7,19,32);
 delay(i);
   }
 clear();
    show_ascii(4,2,'A');
    show_ascii(5,2,'S');
    show_ascii(6,2,'C');
    show_ascii(7,2,'I');
    show_ascii(8,2,'I');
    show_ascii(9,2,':');
    show_hanzi(hanzi4,0,4,4,0);
    show_ascii(9,4,':');
    show_ascii(10,4,'\'');
    show_ascii(12,4,'\'');
    for(k=33;k<127;k++)
  { 
    show_ascii(11,4,k);//k的置即为ASCII
    
    show_shuzi(72,2,k/100);
     show_shuzi(80,2,(k%100)/10);
      show_shuzi(88,2,k%10);
    delay(1000);
  }
  clear();
  for(j=0;j<5;j++)
   { show_picture(picture_sl_1,19,32);
  delay(i);
  show_picture(picture_sl_2,19,32);
 delay(i);
 show_picture(picture_sl_3,19,32);
  delay(i);
  show_picture(picture_sl_4,19,32);
delay(i);
 show_picture(picture_sl_5,19,32);
 delay(i);
  show_picture(picture_sl_6,19,32);
 delay(i);
 show_picture(picture_sl_7,19,32);
 delay(i);
   }
  clear();
   show_picture(picture1,101,48);
  for(j=0x40;j<0x80;j++)
  { if(j==0x40)
     delay(2000);
    delay(150);
   send_cmd(j);
   }if(j==0x80)
     delay(2000);
  clear();
  show_picture(picture2,101,48);
  for(j=0x40;j<0x80;j++)
  { delay(150);
   send_cmd(j);
  } if(j==0x80)
     delay(2000);
  clear();
  show_picture(picture3,101,48);
  for(j=0x40;j<0x80;j++)
  { delay(150);
   send_cmd(j); 
  }if(j==0x80)
     delay(2000);
  clear();
  for(j=0;j<5;j++)
  {send_cmd(0x40);
  show_picture(picture_HT_1,101,64);
  delay(i);
  show_picture(picture_HT_2,101,64);
 delay(i);
 show_picture(picture_HT_3,101,64);
  delay(i);
  show_picture(picture_HT_4,101,64);
delay(i);
 show_picture(picture_HT_5,101,64);
 delay(i);
  show_picture(picture_HT_6,101,64);
 delay(i);
 show_picture(picture_HT_7,101,64);
 delay(i);
  show_picture(picture_HT_8,101,64);
 delay(i);
 show_picture(picture_HT_9,101,64);
 delay(i);
  }
  clear();
}
}
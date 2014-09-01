#include "spce061a.h"
#include "ziku12864.h"
#include "a2000.h"
void playsound(int index,int channel)
{
	SACM_A2000_Initial(1);//auto
	SACM_A2000_Play(index,channel,3);
	while((SACM_A2000_Status()&0x0001)!=0)
	{
		SACM_A2000_ServiceLoop();
		*P_Watchdog_Clear=1;
	}
	SACM_A2000_Stop();
}
int main(void)
{
	unsigned char key=0;
	*P_IOA_Dir&=~0x0007;
	*P_IOA_Attrib&=~0x0007;
	*P_IOA_Data&=~0x0007;
	init_12864();
	write_cmd_12864(0x01);
    write_chinese_12864("我叫赵永科哈哈哈",0,0,8);
    
	while(1)
	{
		*P_IOA_Data&=~0x0007;
		key=(*P_IOA_Data)&0x0007;
		switch(key)
		{
			case 1:
				write_chinese_12864("主人请进！",0,0,5);
				playsound(0,3);
				break;
			case 2:
				write_chinese_12864("对不起我不认识你",0,0,8);
				playsound(1,3);
				break;
			case 4:
				write_chinese_12864("你是谁呀？",0,0,5);
				playsound(2,3);
				break;
			default:
				*P_Watchdog_Clear=1;
				write_chinese_12864("我叫赵永科哈哈哈",0,0,8);
		}
	}
}
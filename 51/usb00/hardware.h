#ifndef _hardware_h_kkk
#define _hardware_h_kkk 
unsigned char keyscan(void)
{
	unsigned char i;
	P1=0xff;
	P2=P1;
	for(i=1;i<=8;i++)
	{
		if((P1&(0x01<<(i-1)))==0)
		{
			while((P1&(0x01<<(i-1)))==0);
			return i;
		}
	}
	return 0;
}

#endif
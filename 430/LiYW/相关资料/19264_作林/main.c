#include<avr/io.h>
#include<util/delay.h>
#include"19264.h"
#include"module.h"
unsigned char temp=0,i=0,data=0x01;
int main()
{

	InitLCM();		
	WriteCom(0x3f,'L');				//play on;
	WriteCom(0x3f,'M');
	WriteCom(0x3f,'R');		
	ClearLCM();
	
	//WriteChinese(hzstr1,0,0,'L');
	//WriteChinese(hzstr1,0,0,'M');
	//WriteChinese(hzstr1,0,8,'M');
	//WriteChinese(hzstr1,1,8,'M');
	//WriteChar(string1,1,8,'R');
	while(1)
	{
		WriteBmp(bmp1);
		_delay_ms(5000);
		WriteBmp(bmp2);
		_delay_ms(5000);
	}

	return 0;
}

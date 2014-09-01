#include "fstn.h"
void fstn_delay(unsigned int t)
{
	unsigned char i;
	while(t--)
	{
		for(i=20;i;i--)
		{
		}
	}
}
void w_data(unsigned char d)
{
	DATA_DIR_OUT();
	RS_1;
	WR_0;
	DATAOUT=d;
	WR_1;
	fstn_delay(1);
	
}
unsigned char r_data(void)
{
	unsigned char d;
	DATA_DIR_IN();
	RS_1;
	RD_0;
	fstn_delay(1);
	d=DATAIN;
	RD_1;
	return d;
}
void w_comd(unsigned char d)
{
	DATA_DIR_OUT();
	RS_0;
	WR_0;
	DATAOUT=d;
	WR_1;
	fstn_delay(1);
}
unsigned char r_comd(void)
{
	unsigned char d;
	DATA_DIR_IN();
	RS_0;
	RD_0;
	fstn_delay(1);
	d=DATAIN;
	RD_1;
	return d;
}

void init_fstn(void)
{
	CTRL_DIR_OUT();
	RST_0;
	CS_0;	
	fstn_delay(10);
	RST_1;
	fstn_delay(10);
	WR_1;
	RD_1;
	
	
	w_comd(0x48);
	w_comd(0x60);
	w_comd(0xa1);
	w_comd(0xc8);
	w_comd(0x44);
	w_comd(0x10);
	w_comd(0x40);
	w_comd(0x00);
	w_comd(0xab);
	w_comd(0x66);
	w_comd(0x27);
	w_comd(0x81);
	w_comd(0x20);
	w_comd(0x54);	
	w_comd(0x93);
	w_comd(0x88);
	w_comd(0x00);
	w_comd(0x89);
	w_comd(0x00);
	w_comd(0x8a);
	w_comd(0x88);
	w_comd(0x8b);
	w_comd(0x88);
	w_comd(0x8c);
	w_comd(0xbb);
	w_comd(0x8d);
	w_comd(0xbb);
	w_comd(0x8e);
	w_comd(0xee);
	w_comd(0x8f);
	w_comd(0xee);
	w_comd(0x2c);
	fstn_delay(100);
	w_comd(0x2e);
	fstn_delay(100);	
	w_comd(0x2f);
	fstn_delay(100);		
	w_comd(0xaf);
	fstn_delay(100);
	
	
	
}
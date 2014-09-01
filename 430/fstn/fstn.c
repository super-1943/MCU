#include "fstn.h"

extern const unsigned char Ezk[];



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


/*****************************
����ʱ��ͼд������ֻ��ż������
д��ȥ�������ζ���Ч����
�����ּ���һ��д���塣��������

******************************/
void w_data(unsigned char d)
{
	unsigned char s;
	s=r_comd();
	while(s&0x80)
	{
		s=r_comd();
	}
	DATA_DIR_OUT();
	RS_1;
	WR_0;
	DATAOUT=d;
	WR_1;	
	fstn_delay(1);
	WR_0;
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
	unsigned char s;
	s=r_comd();
	while(s&0x80)
	{
		s=r_comd();
	}
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

void clear_all(void)
{
	unsigned char i,j;


	for(j=0;j<12;j++)
	{
		w_comd(SET_PAGE_ADDR+j);
		w_comd(SET_COL_ADDR_765+0);
		w_comd(SET_COL_ADDR_4321+0);
		for(i=0;i<128;i++)
		{
			w_data(0x00);
		}
	}
}
/********************************************************
FSTNд���ֺ���by KKK
�ܴ�С��128*96�� ��12ҳ��ÿҳ��128�У��ֽڴӵ�λ����λ����
********************************************************/
void show_hanzi(
				const unsigned char *p,//���ֿ����ʼ��ַ
				unsigned char page,//�ڼ�ҳ����Χ0~11
				unsigned char col//�ڼ��У���Χ0~127
			   )
{
	unsigned char j;
	w_comd(SET_PAGE_ADDR+page);
	w_comd(SET_COL_ADDR_765+col/16);
	w_comd(SET_COL_ADDR_4321+col%16);
	for(j=0;j<16;j++)
	{
		w_data(*p++);
	}
	w_comd(SET_PAGE_ADDR+page+1);
	w_comd(SET_COL_ADDR_765+col/16);
	w_comd(SET_COL_ADDR_4321+col%16);
	for(j=0;j<16;j++)
	{
		w_data(*p++);
	}	
}

///================================
//=================================
void show_char(
			   unsigned char it,//ASCII�ַ�
			   unsigned char page,//����pageȡֵΪ0~11�����ϵ���
			   unsigned char col,//����colȡֵΪ0~127������
			   unsigned char isReverse//�Ƿ����أ�1��0��
			   )
{
	unsigned char j;
	w_comd(SET_PAGE_ADDR+page);
	w_comd(SET_COL_ADDR_765+col/16);
	w_comd(SET_COL_ADDR_4321+col%16);
	for(j=0;j<8;j++)
	{
		if(!isReverse)
		{
			w_data(Ezk[(it-0x20)*16+j]);
		}
		else
		{
			w_data(~Ezk[(it-0x20)*16+j]);
		}
	}
	w_comd(SET_PAGE_ADDR+page+1);
	w_comd(SET_COL_ADDR_765+col/16);
	w_comd(SET_COL_ADDR_4321+col%16);
	for(j=0;j<8;j++)
	{
		if(!isReverse)
		{
			w_data(Ezk[(it-0x20)*16+j+8]);
		}
		else
		{
			w_data(~Ezk[(it-0x20)*16+j+8]);
		}
	}	
}

void show_str(	
			   unsigned char *it,//ASCII�ַ�����Ĭ�Ͻ�����Ϊ0x00��NULL
			   unsigned char page,//����pageȡֵΪ0~11�����ϵ���
			   unsigned char col,//����colȡֵΪ0~127������
			   unsigned char isReverse//�Ƿ����أ�1��0��
			   )
{
	while(*it)
	{
		show_char(*it,page,col,isReverse);
		col+=8;
		if(col>=128)
		{
			col=0;
			page+=2;
			if(page>=12)
			{
				page=0;
			}
		}
		it++;
	}
}
void show_int(
			   unsigned int it,//����
			   unsigned char page,//����pageȡֵΪ0~11�����ϵ���
			   unsigned char col,//����colȡֵΪ0~127������
			   unsigned char isReverse//�Ƿ����أ�1��0��
			   )
{
}
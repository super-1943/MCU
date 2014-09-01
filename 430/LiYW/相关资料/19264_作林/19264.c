//========================================================
//19264����,2010��5��3��
//ע��3�ŽӸ�ѹ���������ܵ��ڶԱȶ���ʾ��
//ע��ȡ��ģʱ���˳��19264��ʾ����ȡģ  ÿһ�д��ϵ��°�λ���ֽڵĴӵ͵��ߣ�
//����ע��ȡ��ģ�����ȡģ����!!!
//ע���ȡflash���ݵ�ʱ�����غ���������!!!
//ע���е�ַ�Ǵ��µ���0~63;
//========================================================


#include<avr/io.h>
#include<util/delay.h> 
#include<avr\pgmspace.h>

#include"19264.h"
void InitLCM()
{
	DataDir = 0xff;			//����Ϊ���;
	ComDir = 0xff;			//��������˿�Ϊ���;
	ComBus = 0xff;			//��������˿�Ϊ�ߵ�ƽ;
	ComBus &= ~RST;			//��λһ��;
	_delay_us(10);
	ComBus |= RST;

}
//==========================================
//ѡ������������һ��д������;
//==========================================
void WriteCom(unsigned char com,unsigned char chipselect)
{
	if(chipselect=='L')
		while(ReadBusy('L'));				//read busy,if busy stay here;
	if(chipselect=='M')
		while(ReadBusy('M'));
	if(chipselect=='R')
		while(ReadBusy('R'));
	
	DataDir =0xff;
	ComBus |= EN;
	ComBus &= ~EN;
	_delay_us(10);

	ComBus &= ~RW;
	ComBus &= ~RS;
	if(chipselect=='L')
		ComBus &= ~ChipCS1;
	if(chipselect=='M')
		ComBus &= ~ChipCS2;
	if(chipselect=='R')
		ComBus &= ~ChipCS3;
	DataBus = com;
	_delay_us(10);
	ComBus |= EN;
	_delay_us(10);
	ComBus &= ~EN;
	ComBus |= (ChipCS1|ChipCS2|ChipCS3);
}


//===========================================
//ѡ������������һ��д������;
//===========================================
void WriteData(unsigned char dat,unsigned char chipselect)
{
	if(chipselect=='L')
		while(ReadBusy('L'));				//read busy,if busy stay here;
	if(chipselect=='M')
		while(ReadBusy('M'));
	if(chipselect=='R')
		while(ReadBusy('R'));
	DataDir=0xff;
	ComBus |= EN;
	ComBus &= ~EN;
	_delay_us(10);
	ComBus &= ~RW;
	ComBus |= RS;
	if(chipselect=='L')
		ComBus &= ~ChipCS1;
	if(chipselect=='M')
		ComBus &= ~ChipCS2;
	if(chipselect=='R')
		ComBus &= ~ChipCS3;
	DataBus = dat;
	ComBus |= EN;
	_delay_us(20);					//delay 

	ComBus &= ~EN;
	ComBus |= (ChipCS1|ChipCS2|ChipCS3);
	
}

//=====================================
//����������һ����״̬;
//=====================================
unsigned char ReadStatus(unsigned char chipselect)
{
	unsigned char busydat=0;
	DataDir=0x00;
	ComBus |= EN;
	ComBus &= ~EN;
	_delay_us(10);

	ComBus |= RW;
	ComBus &= ~RS;
	if(chipselect=='L')
		ComBus &= ~ChipCS1;
	if(chipselect=='M')
		ComBus &= ~ChipCS2;
	if(chipselect=='R')
		ComBus &= ~ChipCS3;
	ComBus |= EN;
	_delay_us(20);
	busydat = DataPin;
	ComBus &= ~EN;
	ComBus |= (ChipCS1|ChipCS2|ChipCS3);
	return(busydat);

}

//==============================
//�ж�������������һ���Ƿ���æ״̬;
//==============================
unsigned char ReadBusy(unsigned char chipselect)
{
	if(chipselect=='L')
		return(ReadStatus('L')&0x80);
	if(chipselect=='M')
		return(ReadStatus('M')&0x80);
	else//(chipselect=='R')
		return(ReadStatus('R')&0x80);
}
//==============================
//��ȡ������������һ���Ĵ洢������;
//==============================
unsigned char ReadData(unsigned char chipselect)
{
	unsigned char backdat=0;
	if(chipselect=='L')
		while(ReadBusy('L'));				//read busy,if busy stay here;
	if(chipselect=='M')
		while(ReadBusy('M'));
	if(chipselect=='R')
		while(ReadBusy('R'));
	DataDir=0x00;
	ComBus |= EN;
	ComBus &= ~EN;
	_delay_us(10);

	ComBus |= RW;
	ComBus |= RS;
	if(chipselect=='L')
		ComBus &= ~ChipCS1;
	if(chipselect=='M')
		ComBus &= ~ChipCS2;
	if(chipselect=='R')
		ComBus &= ~ChipCS3;
	ComBus |= EN;
	_delay_us(20);
	backdat = DataPin;
	ComBus &= ~EN;
	ComBus |= (ChipCS1|ChipCS2|ChipCS3);
	return(backdat);
	
}

//===============================
//д���ַ�
//����
//===============================
/*
void WriteChar(unsigned char *ptr,unsigned char page,unsigned char row,unsigned char chipselect)
{
	unsigned char i=0,currentpage=0,currentrow=0;
	
		currentpage+=page+0xb8;
		currentrow+=row+0x40;
		for(i=0;i<64-row;i++)
		{
			WriteCom(pgm_read_byte(ptr),chipselect);
			ptr++;
		}
}*/
//===============================
//д�뺺�֣�����������д��;
//����pageΪ�ڼ���ȡֵ0~3;
//����rowΪ�ڼ���,ȡֵΪ0~63-16;
//����lengthΪ���ֳ���;
//===============================
void WriteChinese(unsigned char *p,unsigned char page,unsigned char row,unsigned char chipselect)
{
	unsigned char i=0,j=0,currentpage=0,currentrow=0;
	currentpage=page*2+0xb8;
	currentrow=row+0x40;
	
		for(j=0;j<2;j++)
		{
			WriteCom(currentpage,chipselect);						//set start page;
			WriteCom(currentrow,chipselect);						//set start row;
			for(i=0;i<16;i++)
			{
				WriteData(pgm_read_byte(p),chipselect);
				p++;
			}
			currentpage++;
		}

}
///================================
//д��һ��.
//����pageȡֵΪ0~7�����ϵ���
//����rowȡֵΪ0~191������
//����chipselectΪƬѡ
//=================================
void WriteChar(unsigned char *str,unsigned char page,unsigned char row,unsigned char chipselect)
{
	unsigned char currentpage=0,currentrow=0,i=0,j=0;
	currentpage=0xb8+page;
	currentrow=0x40+row;

		for(j=0;j<2;j++)
		{
			WriteCom(currentpage,chipselect);						//set start page;
			WriteCom(currentrow,chipselect);						//set start row;
			for(i=0;i<8;i++)
			{
				WriteData(pgm_read_byte(str),chipselect);
				str++;
			}
			currentpage++;
		}
		currentpage++;
}


//===============================
//д���СΪ192*64 ��bmpλͼͼ��;
//===============================
void WriteBmp(unsigned char *ptr)
{
	unsigned char l=0,r=0,startpage=0xb8; 		//startline=0xc0,

	for(r=0;r<8;r++)
	{
		//WriteComL(startline);					//set start line;
		WriteCom(startpage,'L');					//set start page;
		WriteCom(0x40,'L');						//set start row;
		for(l=0;l<64;l++)
		{
			WriteData(pgm_read_byte(ptr),'L');		//pgm_read_byte()Ϊ��ȡflash���ݵĺ���;
			ptr++;
		}
		//startline+=8;
		startpage+=1;
		ptr+=128;									
	}

	startpage=0xb8;
	ptr-=1472;					//ע������ַָ���λ��;��������ּ���һ��128 ���������ַ���Ѿ�����������Դ˴���ַΪptr-(192*64-64);
	for(r=0;r<8;r++)
	{
		WriteCom(startpage,'M');				//set start page;
		WriteCom(0x40,'M');				//set start row;
		for(l=0;l<64;l++)
		{
			WriteData(pgm_read_byte(ptr),'M');
			ptr++;
		}
		//startline+=8;
		startpage+=1;
		ptr+=128;
	}


	startpage=0xb8;
	ptr-=1472;
	for(r=0;r<8;r++)
	{
		WriteCom(startpage,'R');				//set start page;
		WriteCom(0x40,'R');				//set start row;
		for(l=0;l<64;l++)
		{
			WriteData(pgm_read_byte(ptr),'R');
			ptr++;
		}
		//startline+=8;
		startpage+=1;
		ptr+=128;
	}
}
void ClearLCM()
{
	unsigned char l=0,r=0,startpage=0xb8; 		//startline=0xc0,

	for(r=0;r<8;r++)
	{
		//WriteComL(startline);					//set start line;
		WriteCom(startpage,'L');					//set start page;
		WriteCom(0x40,'L');						//set start row;
		for(l=0;l<64;l++)
		{
			WriteData(0x00,'L');		//pgm_read_byte()Ϊ��ȡflash���ݵĺ���;
		}
		//startline+=8;
		startpage+=1;
	}

	startpage=0xb8;
		
	for(r=0;r<8;r++)
	{
		WriteCom(startpage,'M');				//set start page;
		WriteCom(0x40,'M');				//set start row;
		for(l=0;l<64;l++)
		{
			WriteData(0x00,'M');
		}
		//startline+=8;
		startpage+=1;
	}


	startpage=0xb8;
	for(r=0;r<8;r++)
	{
		WriteCom(startpage,'R');				//set start page;
		WriteCom(0x40,'R');				//set start row;
		for(l=0;l<64;l++)
		{
			WriteData(0x00,'R');
		}
		//startline+=8;
		startpage+=1;
	}
}

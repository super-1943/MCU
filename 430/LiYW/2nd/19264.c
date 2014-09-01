//========================================================
//19264����,2010��5��3��
//ע��3�ŽӸ�ѹ���������ܵ��ڶԱȶ���ʾ��
//ע��ȡ��ģʱ���˳��19264��ʾ����ȡģ  ÿһ�д��ϵ��°�λ���ֽڵĴӵ͵��ߣ�
//����ע��ȡ��ģ�����ȡģ����!!!
//ע���ȡflash���ݵ�ʱ�����غ���������!!!
//ע���е�ַ�Ǵ��µ���0~63;
//========================================================



#include"19264.h"
extern const unsigned char hzstr[];
extern const unsigned char SHUstr[];
extern const unsigned char Ezk[];
extern const unsigned char Noinput_zk[];
extern const unsigned char Sheding[];

extern const unsigned char Water[25];
extern unsigned int Analog[25];
/**************************************************
��ʾ����
**************************************************/
void kkk_19264_show(unsigned char page,unsigned char offset)
{
	unsigned int temp;
	unsigned char i;
	for(i=0;i<4;i++)
	{
		WriteChinese(hzstr,i,0,'L');
		WriteChinese(hzstr+32,i,16,'L');
		WriteChinese(hzstr+64,i,32,'L');
		WriteChinese(hzstr+96,i,16,'M');
		WriteChinese(hzstr+128,i,32,'M');
		WriteChinese(hzstr+160,i,48,'M');	
	}
	
	for(i=0;i<4;i++)
	{
		temp=Water[(page+i)%25];
		if(temp>=100)
		{
			WriteChar(Ezk+16*('1'-0x20),2*i,48,'L');
			WriteChar(Ezk+16*('0'-0x20),2*i,56,'L');
			WriteChar(Ezk+16*('0'-0x20),2*i,0,'M');
			WriteChar(Ezk+16*('%'-0x20),2*i,8,'M');
		}
		else if(temp%100/10)
		{
			WriteChar(Ezk+16*(0),2*i,48,'L');//space
			WriteChar(Ezk+16*(temp%100/10+'0'-0x20),2*i,56,'L');
			WriteChar(Ezk+16*(temp%10+'0'-0x20),2*i,0,'M');
			WriteChar(Ezk+16*('%'-0x20),2*i,8,'M');
		}
		else
		{
			WriteChar(Ezk+16*(0),2*i,48,'L');//space
			WriteChar(Ezk+16*(0),2*i,56,'L');
			WriteChar(Ezk+16*(temp%10+'0'-0x20),2*i,0,'M');
			WriteChar(Ezk+16*('%'-0x20),2*i,8,'M');
		}
		
		temp=Analog[(page+i)%25]*RATIO;//�洢ֵ����ϵ���õ�ʵ��ģ����
		if(i==offset)
		{
			if(temp%10000/1000)
			{
				WriteChar_RVS(Ezk+16*(temp%10000/1000+'0'-0x20),2*offset,0,'R');
			}
			else
			{
				WriteChar_RVS(Ezk+16*(0),2*offset,0,'R');
			}
			if((temp%1000/100)||(temp%10000/1000))
			{
				WriteChar_RVS(Ezk+16*(temp%1000/100+'0'-0x20),2*offset,8,'R');
			}
			else
			{
				WriteChar_RVS(Ezk+16*(0),2*offset,8,'R');
			}
			if((temp%1000/100)||(temp%10000/1000)||(temp%100/10))
			{
				WriteChar_RVS(Ezk+16*(temp%100/10+'0'-0x20),2*offset,16,'R');
			}
			else
			{
				WriteChar_RVS(Ezk+16*(0),2*offset,16,'R');
			}
			if((temp%1000/100)||(temp%10000/1000)||(temp%100/10)||(temp%10))
			{
				WriteChar_RVS(Ezk+16*(temp%10+'0'-0x20),2*offset,24,'R');	
			}
			else
			{
				WriteChar_RVS(Ezk+16*('0'-0x20),2*offset,24,'R');
			}
		}
		else
		{
		
			if(temp%10000/1000)
			{
				WriteChar(Ezk+16*(temp%10000/1000+'0'-0x20),2*i,0,'R');
			}
			else
			{
				WriteChar(Ezk+16*(0),2*i,0,'R');
			}
			if((temp%1000/100)||(temp%10000/1000))
			{
				WriteChar(Ezk+16*(temp%1000/100+'0'-0x20),2*i,8,'R');
			}
			else
			{
				WriteChar(Ezk+16*(0),2*i,8,'R');
			}
			if((temp%1000/100)||(temp%10000/1000)||(temp%100/10))
			{
				WriteChar(Ezk+16*(temp%100/10+'0'-0x20),2*i,16,'R');
			}
			else
			{
				WriteChar(Ezk+16*(0),2*i,16,'R');
			}
			if((temp%1000/100)||(temp%10000/1000)||(temp%100/10)||(temp%10))
			{
				WriteChar(Ezk+16*(temp%10+'0'-0x20),2*i,24,'R');	
			}
			else
			{
				WriteChar(Ezk+16*('0'-0x20),2*i,24,'R');
			}
		}
		WriteChar(Ezk+16*('m'-0x20),2*i,48,'R');
		WriteChar(Ezk+16*('V'-0x20),2*i,56,'R');
	}
}







void delay(int x)
{
	while(x--)
	_NOP();
}
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
void WriteData(const unsigned char dat,unsigned char chipselect)
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
void WriteChinese(const unsigned char *p,unsigned char page,unsigned char row,unsigned char chipselect)
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
				WriteData(*p,chipselect);
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
void WriteChar(const unsigned char *str,unsigned char page,unsigned char row,unsigned char chipselect)
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
				WriteData(*str,chipselect);
				str++;
			}
			currentpage++;
		}
		currentpage++;
}
void WriteChar_RVS(const unsigned char *str,unsigned char page,unsigned char row,unsigned char chipselect)
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
				WriteData(~(*str),chipselect);
				str++;
			}
			currentpage++;
		}
		currentpage++;
}

//===============================
//д���СΪ192*64 ��bmpλͼͼ��;
//===============================
void WriteBmp(const unsigned char *ptr)
{
	unsigned char l=0,r=0,startpage=0xb8; 		//startline=0xc0,

	for(r=0;r<8;r++)
	{
		//WriteComL(startline);					//set start line;
		WriteCom(startpage,'L');					//set start page;
		WriteCom(0x40,'L');						//set start row;
		for(l=0;l<64;l++)
		{
			WriteData(*ptr,'L');		//pgm_read_byte()Ϊ��ȡflash���ݵĺ���;
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
			WriteData(*ptr,'M');
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
			WriteData(*ptr,'R');
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

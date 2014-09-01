//========================================================
//19264驱动,2010年5月3号
//注意3脚接负压。这样才能调节对比度显示。
//注意取字模时候的顺序，19264显示纵向取模  每一列从上到下八位是字节的从低到高，
//所以注意取字模软件的取模方向!!!
//注意读取flash内容的时候的相关函数及参数!!!
//注意行地址是从下到上0~63;
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
显示函数
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
		
		temp=Analog[(page+i)%25]*RATIO;//存储值乘上系数得到实际模拟量
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
	DataDir = 0xff;			//设置为输出;
	ComDir = 0xff;			//设置命令端口为输出;
	ComBus = 0xff;			//设置命令端口为高电平;
	ComBus &= ~RST;			//复位一下;
	_delay_us(10);
	ComBus |= RST;

}
//==========================================
//选择向三个屏中一个写入命令;
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
//选择向三个屏中一个写入数据;
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
//读三个屏中一个的状态;
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
//判断三个屏中其中一个是否处于忙状态;
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
//读取三个屏中其中一个的存储区数据;
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
//写入字符
//参数
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
//写入汉字，从左到右依次写入;
//参数page为第几行取值0~3;
//参数row为第几列,取值为0~63-16;
//参数length为汉字长度;
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
//写入一行.
//参数page取值为0~7，从上到下
//参数row取值为0~191从左到右
//参数chipselect为片选
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
//写入大小为192*64 的bmp位图图像;
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
			WriteData(*ptr,'L');		//pgm_read_byte()为读取flash内容的函数;
			ptr++;
		}
		//startline+=8;
		startpage+=1;
		ptr+=128;									
	}

	startpage=0xb8;
	ptr-=1472;					//注意计算地址指针的位置;上面最后又加了一次128 所以上面地址就已经到了最后。所以此处地址为ptr-(192*64-64);
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
			WriteData(0x00,'L');		//pgm_read_byte()为读取flash内容的函数;
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

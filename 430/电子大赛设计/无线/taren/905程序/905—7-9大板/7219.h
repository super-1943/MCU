
#define DIN   P3_4
#define LOAD  P3_1
#define CLK   P3_0

#define nop   _nop_()
#define uchar unsigned char

#define Stop  0x0c    //ͣ������λ�� 0ͣ����1����
#define Code  0x09     //������ƣ�0�����룬1 bcd8421��
#define Light 0x0a     //���ȵ���00~0f  16��
#define  Bit  0x0b     //ɨ��λ��
#define  Test 0x0f     //��ʾ����0�����ԣ�1����

void send_bit(uchar i)
{
    
    uchar temp;
    uchar m=0;
    for(;m<8;m++)
   {
      temp=i&0x80;
      if(temp)
        {
           DIN=1;
           nop;
           CLK=0;
           nop;
           CLK=1;
        }else{
              DIN=0;
               nop;
              CLK=0;
               nop;
               CLK=1;
              }
       i<<=1;
    }
}     

void send(uchar add,uchar dat)
{  
   send_bit(add);
   nop;
   send_bit(dat);
   nop;
   LOAD=0;
   nop;
   LOAD=1;
} 

void initial_7219()
{
    send(Stop,1);
    send(Light,2);
    send(Bit,4);
    send(Test,0);
    send(Code,0x07);
}

#ifndef	__DISPLAY_h__
#define	__DISPLAY_h__
//	write your header here
uint shu[13]={ 0x3f00,0x0600,0x5b00,0x4f00,0x6600,0x6d00,0x7d00,0x0700,0x7f00,0x6f00,0x0000,0x0040,0x0080};   //0-9,关，上午，下午
volatile int dis[8]={0}; 
volatile int larm[8]={1,2,0,0,0,0};
volatile int XueHao[8]={0,4,0,2,0,1,0,1};
void  IO_Init()
{
    *P_IOA_Dir=0xffc0;
    *P_IOA_Attrib=0xfff0;//IOA0-3
    *P_IOA_Data=0x0f;
    
    *P_IOB_Dir=0xff00;
    *P_IOB_Attrib=0xff00;
    *P_IOB_Data=0;	
}           
void dis_delay(uint w)
{
	while(w--)
	{
		uint j=0;
		for(j=0;j<120;j++)
		{
			*P_Watchdog_Clear=1;
		}
	}	
}

void display()
{
   uchar i,j;
   uchar jia=1;   
    if(key4==0)	
     {
  	    dis[7]=t%10;
        dis[6]=t/10;
        dis[5]=second%10;
        dis[4]=second/10;
        dis[3]=minute%10;
        dis[2]=minute/10;
        dis[1]=hour%10;
       dis[0]=hour/10;
     }
     if(key4!=0)	
    {
  	  larm[7]=t%10;
      larm[6]=t/10;
      larm[5]=Alam_second%10;
      larm[4]=Alam_second/10;
      larm[3]=Alam_minute%10;
      larm[2]=Alam_minute/10;
      larm[1]=Alam_hour%10;
     larm[0]=Alam_hour/10;
  } 
  for(j=0;j<2;j++)  
  { 
  	 for(i=8;i<16;i++)
      {
  	    uchar temp,Bshan,Bshan1;
  	    Bshan=1<<(key1+7);
  	    Bshan1=1<<(key4+7);
  	    if(xue==0)
  	      temp=XueHao[i-8];	
  	    else if(key4!=0)
  	      {temp=larm[i-8];}
  	    else 
  	    {temp=dis[i-8];}
  	    *P_IOA_Data=shu[temp];
  	    *P_IOB_Data=jia;
  	    if(halfpoint==1&(jia==0x0200|jia==0x0800))
        {
  	      *P_IOA_Data|=0x8000;
        }
        if((halfpoint==1)&(jia==Bshan|jia==Bshan1))
        {
  	      *P_IOA_Data=shu[10];
  	      *P_IOB_Data=0;
  	      dis_delay(5);
        }
  	    dis_delay(1);
  	    jia<<=1;
  	    *P_Watchdog_Clear=1;
      } 
    if(APM==0) 
      {*P_IOA_Data|=shu[11];}//上午显示
    if(APM==1)
      {*P_IOA_Data|=shu[12];}//下午显示
   }
   
}
#endif

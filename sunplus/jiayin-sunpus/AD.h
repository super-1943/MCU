#ifndef	__AD_h__
#define	__AD_h__
//	write your header here
float wendu[50]={ 2.2706,2.1760,2.0813,1.9867,1.8921,1.8470,1.8109,1.7749,1.7388,1.7027,
                  1.6667,1.6393,1.6118,1.5844,1.5569,1.5295,1.5015,1.4735,1.4454,1.4174,
                  1.3894,1.3615,1.3336,1.3058,1.2778,1.2500,1.2230,1.1959,1.1689,1.1148,
                  1.0892,1.0635,1.0378,1.0122,0.9865,0.9627,0.9388,0.9150,0.8911,0.8673,
                  0.8460,0.8237,0.8019,0.7801,0.7583,0.7387,0.7191,0.6994,0.6798,0.6601	};
unsigned int AD_init()
{
	unsigned long int Td;
	*P_DAC_Ctrl=0x00;
	*P_ADC_Ctrl=0x01;//ADC使能
	Td=*P_ADC_MUX_Data;//ADC启动
}
unsigned int AD_Transform(unsigned char c)
{
   unsigned long int Tdata,Tdata1,Tdata2;
   unsigned int ct;
   if(c==0)//LINE_IN4输入
   {
   	*P_ADC_MUX_Ctrl=0x05;//温度
   }
   if(c==1)
   {
   	*P_ADC_MUX_Ctrl=0x06;//光度
   }
    Tdata2=0;
   for(ct=0;ct<16;ct++)
   {
     AD_init();
   	 *P_Watchdog_Clear=1;
   	 while(!*P_ADC_MUX_Ctrl&0x8000);//等待转换完成
   	 Tdata1=*P_ADC_MUX_Data&0xffc0;
   	 Tdata2+=(Tdata1>>6);
   	 
   } 
   	Tdata=(Tdata2>>4);// /16取平均数
   	return  Tdata;
   
}
int Tmp_measure()
{
  int du;
  float TTTdata,TTTdata1;
  TTTdata1=0.0000;
  TTTdata=AD_Transform(0);
  *P_Watchdog_Clear=1;
  TTTdata1=TTTdata1+TTTdata*3.3/1024;//-1.7400
  for(du=0;du<50;du++)
  {	
  	if(wendu[du]>=TTTdata1)
    {
    	if(TTTdata1>wendu[du+1])
    	{
    		 t=du;
  	         return t;
    	}
    }
    *P_Watchdog_Clear=1;
    
  }
}
void light_measure()
{
    int ldata,ldata1;
    ldata=AD_Transform(1);
    *P_Watchdog_Clear=1;
    ldata1=ldata;
    if(0<ldata1&ldata1<5)//光线太强
    	L_flag=23;
    if(5<ldata1&ldata1<=450)//光线柔和
    	L_flag=22;
    if(ldata1>510)//光线太暗
    	L_flag=21;
    *P_Watchdog_Clear=1;
       
}
#endif

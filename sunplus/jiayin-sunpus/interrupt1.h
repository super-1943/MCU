#ifndef	__INTERRUPT1_h__
#define	__INTERRUPT1_h__
//	write your header here
void IRQ4(void) __attribute__ ((ISR));
volatile	unsigned int min=0;
volatile	unsigned int flag=0;
volatile	unsigned int m=0;
uint key_value=0;
int wait00=0;
int wait11=0;
void IRQ4(void)
{	
	if(*P_INT_Ctrl&C_IRQ4_1KHz	)
	{	
	   *P_INT_Clear=C_IRQ4_1KHz;
	   min++;
	   *P_Watchdog_Clear=1;
	   if(min==30)
	   {playlarm();}
	   if(min>158)
	   { 
	        Tmp_measure();
	  	    *P_Watchdog_Clear=1;
	        light_measure();
	    	*P_Watchdog_Clear=1;
	        min=0;
	        key_value=Get_KeyValue();
	        if(key_value!=0)
	       {
	     	  xue=1;
	     	  stop=1;
	          switch(key_value)
	         {
	           case 0x01:
               {
                  key1++;
                  if(key1>4)
                  key1=0;
               }break;
	           case 0x02:
	          {
                 if(key1==0)//����ʱ��
    	        {
    	    	   PlaySnd_Auto(19,3);//��������
    	    	   dong=0;
    	    	   if(hour<10)
    	    	   {
    	    		  PlaySnd_Auto(hour,3);
    	    	   }
    	    	   if(hour>=10&hour<20)
    	    	   {
    	    		  PlaySnd_Auto(10,3);
    	    		  PlaySnd_Auto(hour%10,3);
    	    	   }
    	    	   if(hour>=20)
    	    	   {
    	    		  PlaySnd_Auto(2,3);
    	    		  PlaySnd_Auto(10,3);
    	    		  PlaySnd_Auto(hour%10,3);
    	    	   }
    	        	PlaySnd_Auto(11,3);//������
    	    	    if(minute<10)
    	    	    {PlaySnd_Auto(minute,3);}
    	    	    if(minute>=10)
    	    	    {
    	    		  PlaySnd_Auto(minute/10,3);
    	    		  PlaySnd_Auto(10,3);
    	    		  PlaySnd_Auto(minute%10,3);
    	    		  *P_Watchdog_Clear=1;
    	    	}
    	    	PlaySnd_Auto(12,3);//������	
    		  }	
		       if(key1==1)
		      {
                    key2=1;
                    dis[0]++;		
		           if(dis[0]>2)
		           dis[0]=0;
		      }
		      if(key1==2)
		     {
                 key2=1;
                if(dis[0]!=2)
               {
              	  dis[1]++;		
		          if(dis[1]>9)
		          dis[1]=0;
               }
              if(dis[0]==2)
              {
              	  dis[1]++;		
		          if(dis[1]>3)
		          dis[1]=0;
              }                    		
		   
		   }
		  if(key1==3)
		   {
              key2=1;
              dis[2]++;		
		     if(dis[2]>5)
		     dis[2]=0;
		   }
		  if(key1==4)
		   {
                     key2=1;
                     dis[3]++;		
		     if(dis[3]>9)
		     dis[3]=0;
		   }
		    if(key4==1)
		   {
              key2=1;
              larm[0]++;		
		     if(larm[0]>2)
		     larm[0]=0;
		   }
		  if(key4==2)
		   {
              key2=1;
              if(larm[0]!=2)
              {
              	  larm[1]++;		
		          if(larm[1]>9)
		          larm[1]=0;
              }
              if(larm[0]==2)
              {
              	  larm[1]++;		
		          if(larm[1]>3)
		          larm[1]=0;
              }
		   }
		  if(key4==3)
		   {
                     key2=1;
                     larm[2]++;		
		     if(larm[2]>5)
		     larm[2]=0;
		   }
		  if(key4==4)
		   {
             key2=1;
             larm[3]++;		
		     if(larm[3]>9)
		     larm[3]=0;
		   }		   
        }break;
		case 0x04:
		{
          if(key1==0)//�����¶Ⱥ͹���	
          {
          	PlaySnd_Auto(13,3);//�¶�
          	if(t<=10&t>=0)
          	  PlaySnd_Auto(t,3);
          	if(t>10&t<20)
          	{  
          	    PlaySnd_Auto(10,3);
          	    *P_Watchdog_Clear=1;
          	    if(t%10!=0)
          	    PlaySnd_Auto(t%10,3);
          	}
          	if(t>=20&t<50)
          	{  
          		PlaySnd_Auto(t/10,3);
          	    PlaySnd_Auto(10,3);
          	    *P_Watchdog_Clear=1;
          	    if(t%10!=0)
          	    PlaySnd_Auto(t%10,3);
          	}
          	*P_Watchdog_Clear=1;	
         	PlaySnd_Auto(14,3);//���϶�
          	PlaySnd_Auto(15,3);//����
          	*P_Watchdog_Clear=1;
          	if(L_flag==21)
          	  PlaySnd_Auto(16,3);//̫��
          	if(L_flag==22)
          	  PlaySnd_Auto(17,3);//���
          	if(L_flag==23)
          	  PlaySnd_Auto(18,3);//̫ǿ
          	 *P_Watchdog_Clear=1;
          }
		  if(key1==1)
		   {
             key2=1;
             dis[0]--;		
		     if(dis[0]<0)
		     dis[0]=2;
		   }
		  if(key1==2)
		   {
               key2=1;
               if(dis[0]!=2)
               {
               	dis[1]--;
               	if(dis[1]<0)
               	   dis[1]=9;
               }
               if(dis[0]==2)
               {
               	dis[1]--;
               	if(dis[1]<0)
               	   dis[1]=3;
               }		
		     		     
		   }
		  if(key1==3)
		   {
                key2=1;
                dis[2]--;		
		     if(dis[2]<0)
		     dis[2]=5;
		   }
		  if(key1==4)
		   {
           key2=1;
           dis[3]--;		
		     if(dis[3]<0)
		     dis[3]=9;
		   }
		   if(key4==1)
		   {
             key2=1;
             larm[0]--;		
		     if(larm[0]<0)
		     larm[0]=2;
		   }
		  if(key4==2)
		   {
               key2=1;
               if(larm[0]!=2)
               {
               	larm[1]--;
               	if(larm[1]<0)
               	   larm[1]=9;
               }
               if(larm[0]==2)
               {
               	larm[1]--;
               	if(larm[1]<0)
               	   larm[1]=3;
               }		
		     		     
		   }
		  if(key4==3)
		   {
                key2=1;
                larm[2]--;		
		     if(larm[2]<0)
		        larm[2]=5;
		   }
		  if(key4==4)
		   {
               key2=1;
               larm[3]--;		
		     if(larm[3]<0)
		     larm[3]=9;
		   }
        }break;
        case 0x08:
        { 
        	key4++;
            if(key4>4)
            { key4=0;}
        }break;
        default: break;
	    }
        stop=0;
	    hour=dis[0]*10+dis[1];
	    minute=dis[2]*10+dis[3];
	    second=dis[4]*10+dis[5];
	    Alam_hour=larm[0]*10+larm[1];
	    Alam_minute=larm[2]*10+larm[3];          
	}
	*P_Watchdog_Clear=1;	
  }	 
 }
  
}
#endif
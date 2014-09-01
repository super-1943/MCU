#ifndef	__CLOCK_h__
#define	__CLOCK_h__
//	write your header here
void makechoice()
{
	if(dis[0]==larm[0])
		{
			if(dis[1]==larm[1])
			{	
				if(dis[2]==larm[2])
				{
					if(dis[3]==larm[3])
					{
                       if(dis[4]==larm[4])
                       {
                       	 if(dis[5]==larm[5])
                       	   dong=1;
                       	 out=~out;
                       }
					}
				}
		   }
	   	}
	
}
void clock()
{
  	second++;
  	makechoice();
  	if(second==60)
  	{
  		second=0;
  		minute++;
  		if(minute==60)
  		{
  			minute=0;
  		    hour++;
  		    if(hour==24)
  		    	hour=0;
  		}
  	}
}

void playlarm()
{
	if(dong==1)
	{
		PlaySnd_Auto(21,3);
	    *P_Watchdog_Clear=1;
	}

}
#endif

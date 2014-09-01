#ifndef	__INTERRUPT_h__
#define	__INTERRUPT_h__
//	write your header here
void IRQ5(void) __attribute__ ((ISR));
volatile  int time=0;
void IRQ5(void)
{
	if(*P_INT_Ctrl&C_IRQ5_2Hz)
	{		
	    *P_INT_Clear=C_IRQ5_2Hz;
	    halfpoint=~halfpoint;
	    time++;
	    
	    if(time==2)
	    {  	
	    	if(out==1)
	    	{makechoice();}	
	        time=0;
	       if(hour>=12)
  		    	APM=1;
  		    else
  		        APM=0;	
	       if(stop==0)
	       {clock();}
	    }
	    
	}
    *P_Watchdog_Clear=1;
}

#endif

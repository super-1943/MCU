#include "msp430x14x.h"
#include "usb.h"

extern EVENT_FLAGS EventFlags; //ÊÂ¼þÐÅºÅ
extern unsigned char EndPoint1Buffer[4];

void delay(unsigned int i)
{
    while(i--);
}

int main( void )
{
    // Stop watchdog timer to prevent time out reset
    WDTCTL = WDTPW + WDTHOLD;
    ReconnectUSB();
    while(1)
    {
        if(EventFlags.Bits.SetupPacket)
        {
            _DINT();
            EventFlags.Bits.SetupPacket = 0;
            ControlHandler();
            _EINT();
        }
        
        if(EventFlags.Bits.Timer)
        {
            EventFlags.Bits.Timer = 0;
        }
        if(EventFlags.Bits.Port1RxDone)
        {
            EventFlags.Bits.Port1RxDone = 0;
        }
    }
}
#pragma vector=PORT1_VECTOR
__interrupt void Port1(void)
{
unsigned int i_st;
_DINT();
EventFlags.Bits.InISR=1;
i_st=D12_ReadInterruptRegister();
if(i_st!=0) 
{
if(i_st&D12_INT_ENDP0OUT) 
   EP0_Out();
if(i_st&D12_INT_ENDP0IN) 
   EP0_In();
if(i_st&D12_INT_ENDP1OUT)
   EP1_Out();
if(i_st&D12_INT_ENDP1IN) 
   EP1_In();
if(i_st&D12_INT_ENDP2OUT)
   EP2_Out();
if(i_st&D12_INT_ENDP2IN) 
   EP2_In();   
}
EventFlags.Bits.InISR=0;
_EINT();
}
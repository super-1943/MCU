#include "pca6107.h"
#include "iic.h"
void set_reg_6107(unsigned char reg,unsigned char da)
{  
    iic_start();
    iic_send_byte(ADDR_pca6107);
    while(iic_read_ack());
    iic_send_byte(reg);
    while(iic_read_ack());
    iic_send_byte(da);
    while(iic_read_ack());
    iic_stop();
}
unsigned char get_reg_6107(unsigned char reg)
{
    unsigned char i;
    iic_start();
    iic_send_byte(ADDR_pca6107);
    while(iic_read_ack());
    iic_send_byte(reg);
    while(iic_read_ack());
    iic_start();
    iic_send_byte(ADDR_pca6107+1);
    while(iic_read_ack());
    i=iic_read_byte();
    iic_stop();  
    return i;
}
#include "reg52modified.h"
#include "types.h"
#include "tusb2136.h"

extern WORD pmb_clk_low_stretch_timer;
extern BYTE previous_crc8;
extern bit PMBus_Busy; // 1 - busy; 0 - idle
extern bit PMBus_Group_Command_Busy; // 1 - busy; 0 - idle
extern bit Set_400KHz; // 1 for 400KHz; 0 for 100KHz
extern BYTE xdata pbOutBufferAddress[EP_MAX_PACKET_SIZE]; // ENDPOINT 1 OUT X buffer

BYTE i2c_start(void);
BYTE i2c_restart(void);
BYTE i2c_stop(void);
BYTE i2c_write_bytes(BYTE num_of_bytes, BYTE * source_buf);
BYTE i2c_read_bytes(BYTE num_of_bytes, BYTE * destination_buf, BYTE nack_byte);
void i2c_reset(void);


BYTE volatile bdata i2c_bits;
sbit i2c_bit7 = i2c_bits ^ 7;
sbit i2c_bit6 = i2c_bits ^ 6;
sbit i2c_bit5 = i2c_bits ^ 5;
sbit i2c_bit4 = i2c_bits ^ 4;
sbit i2c_bit3 = i2c_bits ^ 3;
sbit i2c_bit2 = i2c_bits ^ 2;
sbit i2c_bit1 = i2c_bits ^ 1;
sbit i2c_bit0 = i2c_bits ^ 0;
BYTE delay_count;



BYTE i2c_start(void)
{
    PMB_DATA = 1; // set it high so that we can make it an input
    DELAY_500NS;
    if (!PMB_DATA) return ERROR; // PMB_DATA should never be held low by any slave

    PMB_CLK = 1;  // release it to high so that we can make it an input
    DELAY_500NS;

    // each cycle of the while loop takes from 3us to 3.25us
    while (!PMB_CLK) // slave is holding down or stretching PMB_CLK
    {
        pmb_clk_low_stretch_timer++;
        if (pmb_clk_low_stretch_timer > 8333) return ERROR; // 25ms timeout of PMBus clock low stretching
    }

    // add (1.3us + 4us for bqxxxx) assuming that PMB_CLK was just released by a slave
    // delay = delay_count X .75us + .5us; used for a delay longer than 1.5us
    // for (delay_count = 7; delay_count; delay_count--) _nop_();
    DELAY_1000NS; // WW

    PMB_DATA = 0;

    if (Set_400KHz)
    {
       DELAY_500NS;
    }
    else 
    {
       // Thd_sat = 4.3us + 4us for bqxxxx
       // delay = delay_count X .75us + .5us; used for a delay longer than 1.5us
       // for (delay_count = 10; delay_count; delay_count--) _nop_();
       for (delay_count = 5; delay_count; delay_count--) _nop_(); // WW
    }

    PMB_CLK = 0;

    // Tlow + Tf - RET - LCALL = 4.3 + .3 - 2*.25 - 2*.25= 4.3us + 4us for bqxxxx
    // delay = delay_count X .75us + .5us; used for a delay longer than 1.5us
    // for (delay_count = 10; delay_count; delay_count--) _nop_();
    if (!Set_400KHz) 
    {
       for (delay_count = 3; delay_count; delay_count--) _nop_(); // WW
    }

    return NO_ERROR; // success
}


BYTE i2c_restart(void)
{
    PMB_DATA = 1;
    DELAY_500NS;

    while (!PMB_DATA) // for "data-stretching" from slave bqxxxx
    {
        pmb_clk_low_stretch_timer++;
        if (pmb_clk_low_stretch_timer > 8333) return ERROR; // 25ms timeout of PMBus clock low stretching
    }

    PMB_CLK = 1;  // release it to high so that we can make it an input
    DELAY_500NS;

    // each cycle of the while loop takes from 3us to 3.25us
    while (!PMB_CLK) // slave is holding down or stretching PMB_CLK
    {
        pmb_clk_low_stretch_timer++;
        if (pmb_clk_low_stretch_timer > 8333) return ERROR; // 25ms timeout of PMBus clock low stretching
    }

    // add (1.3us + 4us for bqxxxx) assuming that PMB_CLK was just released by a slave
    // delay = delay_count X .75us + .5us; used for a delay longer than 1.5us
    // for (delay_count = 7; delay_count; delay_count--) _nop_();
    DELAY_1000NS; // WW

    PMB_DATA = 0;

    if (Set_400KHz)
    {
       DELAY_500NS;
    }
    else 
    {
       // Thd_sat = 4.3us + 4us for bqxxxx
       // delay = delay_count X .75us + .5us; used for a delay longer than 1.5us
       // for (delay_count = 10; delay_count; delay_count--) _nop_();
       for (delay_count = 5; delay_count; delay_count--) _nop_(); // WW
    }

    PMB_CLK = 0;

    // Tlow + Tf - RET - LCALL = 4.3 + .3 - 2*.25 - 2*.25= 4.3us + 4us for bqxxxx
    // delay = delay_count X .75us + .5us; used for a delay longer than 1.5us
    // for (delay_count = 10; delay_count; delay_count--) _nop_();
    if (!Set_400KHz) 
    {
       for (delay_count = 3; delay_count; delay_count--) _nop_(); // WW
    }

    return NO_ERROR; // success
}


BYTE i2c_stop(void)
{
    PMB_DATA = 0;
    DELAY_700NS;

    PMB_CLK = 1;
    DELAY_500NS;

    // each cycle of the while loop takes from 3us to 3.25us
    while (!PMB_CLK) // slave is holding down or stretching PMB_CLK
    {
        pmb_clk_low_stretch_timer++;
        if (pmb_clk_low_stretch_timer > 8333) return ERROR; // 25ms timeout of PMBus clock low stretching
    }

    // Tsu_sto + Tr - .5 = 4.0 + 1.0 - .5 = 4.5us + 4us for bqxxxx
    // delay = delay_count X .75us + .5us; used for a delay longer than 1.5us
    // for (delay_count = 10; delay_count; delay_count--) _nop_();
    if (!Set_400KHz) // for 100KHz only
    {
       for (delay_count = 5; delay_count; delay_count--) _nop_(); // WW
    }

    PMB_DATA = 1;

    // delay = delay_count X .75us + .5us; used for a delay longer than 1.5us
    // for (delay_count = 10; delay_count; delay_count--) _nop_();
    if (!Set_400KHz) // for 100KHz only
    {
       for (delay_count = 4; delay_count; delay_count--) _nop_(); // WW
    }

    return NO_ERROR; // success
}


// function: write num_of_bytes of data to slave, whereas the data is from source_buf
// return: 1 if fail
//         0 if success
BYTE i2c_write_bytes(BYTE num_of_bytes, BYTE * source_buf)
{
    BYTE data i = 0;
    BYTE data j = num_of_bytes;
    BYTE data k;

    if (Set_400KHz)
    {
        for (i=0; i < j; i++)
        {
            i2c_bits = *source_buf;
    
            PMB_DATA = i2c_bit7;        
            DELAY_250NS; // Tsu_dat
            PMB_CLK = 1;
            DELAY_250NS;
            // each cycle of the while loop takes from 3us to 3.25us
            while (!PMB_CLK) // slave is holding down or stretching PMB_CLK
            {
                pmb_clk_low_stretch_timer++;
                if (pmb_clk_low_stretch_timer > 8333) return ERROR; // 25ms timeout of PMBus clock low stretching
            }
            PMB_CLK = 0;
    
            DELAY_250NS;
            PMB_DATA = i2c_bit6;
            DELAY_250NS;
            PMB_CLK = 1;
            DELAY_250NS;
            // each cycle of the while loop takes from 3us to 3.25us
            while (!PMB_CLK) // slave is holding down or stretching PMB_CLK
            {
                pmb_clk_low_stretch_timer++;
                if (pmb_clk_low_stretch_timer > 8333) return ERROR; // 25ms timeout of PMBus clock low stretching
            }
            PMB_CLK = 0;
    
            DELAY_250NS;
            PMB_DATA = i2c_bit5;
            DELAY_250NS;
            PMB_CLK = 1;
            DELAY_250NS;
            // each cycle of the while loop takes from 3us to 3.25us
            while (!PMB_CLK) // slave is holding down or stretching PMB_CLK
            {
                pmb_clk_low_stretch_timer++;
                if (pmb_clk_low_stretch_timer > 8333) return ERROR; // 25ms timeout of PMBus clock low stretching
            }
            PMB_CLK = 0;
    
            DELAY_250NS;
            PMB_DATA = i2c_bit4;
            DELAY_250NS;
            PMB_CLK = 1;
            DELAY_250NS;
            // each cycle of the while loop takes from 3us to 3.25us
            while (!PMB_CLK) // slave is holding down or stretching PMB_CLK
            {
                pmb_clk_low_stretch_timer++;
                if (pmb_clk_low_stretch_timer > 8333) return ERROR; // 25ms timeout of PMBus clock low stretching
            }
            PMB_CLK = 0;
    
            DELAY_250NS;
            PMB_DATA = i2c_bit3;
            DELAY_250NS;
            PMB_CLK = 1;
            DELAY_250NS;
            // each cycle of the while loop takes from 3us to 3.25us
            while (!PMB_CLK) // slave is holding down or stretching PMB_CLK
            {
                pmb_clk_low_stretch_timer++;
                if (pmb_clk_low_stretch_timer > 8333) return ERROR; // 25ms timeout of PMBus clock low stretching
            }
            PMB_CLK = 0;
    
            DELAY_250NS;
            PMB_DATA = i2c_bit2;
            DELAY_250NS;
            PMB_CLK = 1;
            DELAY_250NS;
            // each cycle of the while loop takes from 3us to 3.25us
            while (!PMB_CLK) // slave is holding down or stretching PMB_CLK
            {
                pmb_clk_low_stretch_timer++;
                if (pmb_clk_low_stretch_timer > 8333) return ERROR; // 25ms timeout of PMBus clock low stretching
            }
            PMB_CLK = 0;
    
            DELAY_250NS;
            PMB_DATA = i2c_bit1;
            DELAY_250NS;
            PMB_CLK = 1;
            DELAY_250NS;
            // each cycle of the while loop takes from 3us to 3.25us
            while (!PMB_CLK) // slave is holding down or stretching PMB_CLK
            {
                pmb_clk_low_stretch_timer++;
                if (pmb_clk_low_stretch_timer > 8333) return ERROR; // 25ms timeout of PMBus clock low stretching
            }
            PMB_CLK = 0;
    
            DELAY_250NS;
            PMB_DATA = i2c_bit0;
            DELAY_250NS;
            PMB_CLK = 1;
            DELAY_250NS;
            // each cycle of the while loop takes from 3us to 3.25us
            while (!PMB_CLK) // slave is holding down or stretching PMB_CLK
            {
                pmb_clk_low_stretch_timer++;
                if (pmb_clk_low_stretch_timer > 8333) return ERROR; // 25ms timeout of PMBus clock low stretching
            }
            PMB_CLK = 0;
    
            DELAY_250NS;
            PMB_DATA = 1; // release PMB_DATA for floating and configure it for input
            DELAY_750NS;
            PMB_CLK = 1;
            DELAY_250NS;
            // each cycle of the while loop takes from 3us to 3.25us
            while (!PMB_CLK) // slave is holding down or stretching PMB_CLK
            {
                pmb_clk_low_stretch_timer++;
                if (pmb_clk_low_stretch_timer > 8333) return ERROR; // 25ms timeout of PMBus clock low stretching
            }
            if (PMB_DATA) return ERROR;
            PMB_CLK = 0;
    
            source_buf++;
        }
    }
    else // for 100KHz
    {
        for (i=0; i < j; i++)
        {
            i2c_bits = *source_buf;
    
            for (k=0; k<8; k++)
            {
                PMB_DATA = i2c_bit7;
        
                // Tsu_dat
                DELAY_300NS;
                DELAY_500NS;
        
                PMB_CLK = 1;
                DELAY_500NS;
        
                // each cycle of the while loop takes from 3us to 3.25us
                while (!PMB_CLK) // slave is holding down or stretching PMB_CLK
                {
                    pmb_clk_low_stretch_timer++;
                    if (pmb_clk_low_stretch_timer > 8333) return ERROR; // 25ms timeout of PMBus clock low stretching
                }
        
                // Thigh + Tr - JNB = 4.0 + 1.0 - 2*.25 = 4.5us + 4us for bqxxxx
                // delay = delay_count X .75us + .5us; used for a delay longer than 1.5us
                // for (delay_count = 10; delay_count; delay_count--) _nop_();
                for (delay_count = 4; delay_count; delay_count--) _nop_(); // WW
        
                PMB_CLK = 0;
        
                // Thd_dat + Tf = .3 + .3 = .6us
                i2c_bits <<= 1;
        
                // Tlow - Thd_dat = 4.7 - .3 = 4.4us + 4us for bqxxxx
                // delay = delay_count X .75us + .5us; used for a delay longer than 1.5us
                // for (delay_count = 10; delay_count; delay_count--) _nop_();
                for (delay_count = 2; delay_count; delay_count--) _nop_(); // WW 
            }
    
            // delay = delay_count X .75us + .5us; used for a delay longer than 1.5us
            // for (delay_count = 10; delay_count; delay_count--) _nop_();
            for (delay_count = 4; delay_count; delay_count--) _nop_(); // WW
    
            PMB_DATA = 1; // release PMB_DATA for floating and configure it for input
    
            // Tlow - Thd_dat = 4.7 - .3 = 4.4us + 4us for bqxxxx
            // delay = delay_count X .75us + .5us; used for a delay longer than 1.5us
            // for (delay_count = 10; delay_count; delay_count--) _nop_();
            for (delay_count = 4; delay_count; delay_count--) _nop_(); // WW
    
            PMB_CLK = 1;
            DELAY_500NS;
    
            // each cycle of the while loop takes from 3us to 3.25us
            while (!PMB_CLK) // slave is holding down or stretching PMB_CLK
            {
                pmb_clk_low_stretch_timer++;
                if (pmb_clk_low_stretch_timer > 8333) return ERROR; // 25ms timeout of PMBus clock low stretching
            }
    
            if (PMB_DATA) return ERROR; // no slave ACK
            // Thigh + Tr - JNB = 4.0 + 1.0 - 2*.25 = 4.5us + 4us for bqxxxx
            // delay = delay_count X .75us + .5us; used for a delay longer than 1.5us
            // for (delay_count = 10; delay_count; delay_count--) _nop_();
            for (delay_count = 3; delay_count; delay_count--) _nop_(); // WW
    
            PMB_CLK = 0;
    
            // delay = delay_count X .75us + .5us; used for a delay longer than 1.5us
            // for (delay_count = 10; delay_count; delay_count--) _nop_();
            for (delay_count = 4; delay_count; delay_count--) _nop_(); // WW
            
            source_buf++;
        }
    }

    return NO_ERROR; // success
}


// function: read in num_of_bytes from slave and store the data pointed by destination_buf
//           if nack_byte = 0xFF, need to do a NACK for the last byte; otherwise, do ACK for each byte.
// return: 1 if fail
//         0 if success
BYTE i2c_read_bytes(BYTE num_of_bytes, BYTE * destination_buf, BYTE nack_byte)
{
    BYTE data i = 0;
    BYTE data j = num_of_bytes;
    BYTE data k;

    PMB_DATA = 1; 

    if (Set_400KHz)
    {
        for (i=0; i < j; i++)
        {
            PMB_CLK = 1;
            DELAY_250NS;
    
            // each cycle of the while loop takes from 3us to 3.25us
            while (!PMB_CLK) // slave is holding down or stretching PMB_CLK
            {
                pmb_clk_low_stretch_timer++;
                if (pmb_clk_low_stretch_timer > 8333) return ERROR; // 25ms timeout of PMBus clock low stretching
            }
    
            // i2c_bit7 = PMB_DATA;
            CY = PMB_DATA;
    
            PMB_CLK = 0;
            i2c_bit7 = CY;
    
            // Tlow + Tf = 4.7 + .3 = 5.0us + 4us for bqxxxx
            // delay = delay_count X .75us + .5us; used for a delay longer than 1.5us
            // for (delay_count = 11; delay_count; delay_count--) _nop_();
            DELAY_500NS; // for (delay_count = 5; delay_count; delay_count--) _nop_(); // WW
    
            PMB_CLK = 1;
            DELAY_250NS;
    
            // each cycle of the while loop takes from 3us to 3.25us
            while (!PMB_CLK) // slave is holding down or stretching PMB_CLK
            {
                pmb_clk_low_stretch_timer++;
                if (pmb_clk_low_stretch_timer > 8333) return ERROR; // 25ms timeout of PMBus clock low stretching
            }
    
            // i2c_bit6 = PMB_DATA;
            CY = PMB_DATA;
    
            PMB_CLK = 0;
            i2c_bit6 = CY;
    
            // Tlow + Tf = 4.7 + .3 = 5.0us + 4us for bqxxxx
            // delay = delay_count X .75us + .5us; used for a delay longer than 1.5us
            // for (delay_count = 11; delay_count; delay_count--) _nop_();
            DELAY_500NS; // for (delay_count = 5; delay_count; delay_count--) _nop_(); // WW
    
            PMB_CLK = 1;
            DELAY_250NS;
    
            // each cycle of the while loop takes from 3us to 3.25us
            while (!PMB_CLK) // slave is holding down or stretching PMB_CLK
            {
                pmb_clk_low_stretch_timer++;
                if (pmb_clk_low_stretch_timer > 8333) return ERROR; // 25ms timeout of PMBus clock low stretching
            }
    
            // i2c_bit5 = PMB_DATA;
            CY = PMB_DATA;
    
            PMB_CLK = 0;
            i2c_bit5 = CY;
    
            // Tlow + Tf = 4.7 + .3 = 5.0us + 4us for bqxxxx
            // delay = delay_count X .75us + .5us; used for a delay longer than 1.5us
            // for (delay_count = 11; delay_count; delay_count--) _nop_();
            DELAY_500NS; // for (delay_count = 5; delay_count; delay_count--) _nop_(); // WW
    
            PMB_CLK = 1;
            DELAY_250NS;
    
            // each cycle of the while loop takes from 3us to 3.25us
            while (!PMB_CLK) // slave is holding down or stretching PMB_CLK
            {
                pmb_clk_low_stretch_timer++;
                if (pmb_clk_low_stretch_timer > 8333) return ERROR; // 25ms timeout of PMBus clock low stretching
            }
    
            // i2c_bit4 = PMB_DATA;
            CY = PMB_DATA;
    
            PMB_CLK = 0;
            i2c_bit4 = CY;
    
            // Tlow + Tf = 4.7 + .3 = 5.0us + 4us for bqxxxx
            // delay = delay_count X .75us + .5us; used for a delay longer than 1.5us
            // for (delay_count = 11; delay_count; delay_count--) _nop_();
            DELAY_500NS; // for (delay_count = 5; delay_count; delay_count--) _nop_(); // WW
    
            PMB_CLK = 1;
            DELAY_250NS;
    
            // each cycle of the while loop takes from 3us to 3.25us
            while (!PMB_CLK) // slave is holding down or stretching PMB_CLK
            {
                pmb_clk_low_stretch_timer++;
                if (pmb_clk_low_stretch_timer > 8333) return ERROR; // 25ms timeout of PMBus clock low stretching
            }
    
            // i2c_bit3 = PMB_DATA;
            CY = PMB_DATA;
    
            PMB_CLK = 0;
            i2c_bit3 = CY;
    
            // Tlow + Tf = 4.7 + .3 = 5.0us + 4us for bqxxxx
            // delay = delay_count X .75us + .5us; used for a delay longer than 1.5us
            // for (delay_count = 11; delay_count; delay_count--) _nop_();
            DELAY_500NS; // for (delay_count = 5; delay_count; delay_count--) _nop_(); // WW
    
            PMB_CLK = 1;
            DELAY_250NS;
    
            // each cycle of the while loop takes from 3us to 3.25us
            while (!PMB_CLK) // slave is holding down or stretching PMB_CLK
            {
                pmb_clk_low_stretch_timer++;
                if (pmb_clk_low_stretch_timer > 8333) return ERROR; // 25ms timeout of PMBus clock low stretching
            }
    
            // i2c_bit2 = PMB_DATA;
            CY = PMB_DATA;
    
            PMB_CLK = 0;
            i2c_bit2 = CY;
    
            // Tlow + Tf = 4.7 + .3 = 5.0us + 4us for bqxxxx
            // delay = delay_count X .75us + .5us; used for a delay longer than 1.5us
            // for (delay_count = 11; delay_count; delay_count--) _nop_();
            DELAY_500NS; // for (delay_count = 5; delay_count; delay_count--) _nop_(); // WW
    
            PMB_CLK = 1;
            DELAY_250NS;
    
            // each cycle of the while loop takes from 3us to 3.25us
            while (!PMB_CLK) // slave is holding down or stretching PMB_CLK
            {
                pmb_clk_low_stretch_timer++;
                if (pmb_clk_low_stretch_timer > 8333) return ERROR; // 25ms timeout of PMBus clock low stretching
            }
    
            // i2c_bit1 = PMB_DATA;
            CY = PMB_DATA;
    
            PMB_CLK = 0;
            i2c_bit1 = CY;
    
            // Tlow + Tf = 4.7 + .3 = 5.0us + 4us for bqxxxx
            // delay = delay_count X .75us + .5us; used for a delay longer than 1.5us
            // for (delay_count = 11; delay_count; delay_count--) _nop_();
            DELAY_500NS; // for (delay_count = 5; delay_count; delay_count--) _nop_(); // WW
    
            PMB_CLK = 1;
            DELAY_250NS;
    
            // each cycle of the while loop takes from 3us to 3.25us
            while (!PMB_CLK) // slave is holding down or stretching PMB_CLK
            {
                pmb_clk_low_stretch_timer++;
                if (pmb_clk_low_stretch_timer > 8333) return ERROR; // 25ms timeout of PMBus clock low stretching
            }
    
            // i2c_bit0 = PMB_DATA;
            CY = PMB_DATA;
    
            PMB_CLK = 0;
            i2c_bit0 = CY;
    
            if ((i == (j-1)) && (nack_byte == 0xFF)) 
                PMB_DATA = 1;  // do a NACK if the last byte has been read
            else PMB_DATA = 0; // if not the last byte to read, pull PMB_DATA low to indicate a master ACK to slave
    
            // Tlow + Tf - 4*.25 = 4.7 + .3 - 4*.25 = 4.0us + 4us for bqxxxx
            // delay = delay_count X .75us + .5us; used for a delay longer than 1.5us
            // for (delay_count = 10; delay_count; delay_count--) _nop_();
            DELAY_500NS; // for (delay_count = 4; delay_count; delay_count--) _nop_(); // WW
    
            PMB_CLK = 1;
            DELAY_250NS;
    
            // each cycle of the while loop takes from 3us to 3.25us
            while (!PMB_CLK) // slave is holding down or stretching PMB_CLK
            {
                pmb_clk_low_stretch_timer++;
                if (pmb_clk_low_stretch_timer > 8333) return ERROR; // 25ms timeout of PMBus clock low stretching
            }
    
            // Thigh + Tr - JNB = 4.0 + 1.0 - 2*.25 = 4.5us + 4us for bqxxxx
            // delay = delay_count X .75us + .5us; used for a delay longer than 1.5us
            // for (delay_count = 10; delay_count; delay_count--) _nop_();
            DELAY_500NS; // for (delay_count = 4; delay_count; delay_count--) _nop_(); // WW
    
            PMB_CLK = 0;
    
            // delay = delay_count X .75us + .5us; used for a delay longer than 1.5us
            // for (delay_count = 20; delay_count; delay_count--) _nop_();
            // for (delay_count = 8; delay_count; delay_count--) _nop_(); // WW
            
            *destination_buf = i2c_bits; // save it
            destination_buf++; // read next byte
            
            PMB_DATA = 1; // release PMB_DATA to floating and become an input
        }
    }
    else
    {
        for (i=0; i < j; i++)
        {
            for (k=0; k<8; k++)
            {
                i2c_bits <<= 1; 
    
                PMB_CLK = 1;
                DELAY_500NS;
        
                // each cycle of the while loop takes from 3us to 3.25us
                while (!PMB_CLK) // slave is holding down or stretching PMB_CLK
                {
                    pmb_clk_low_stretch_timer++;
                    if (pmb_clk_low_stretch_timer > 8333) return ERROR; // 25ms timeout of PMBus clock low stretching
                }
    
                // Tr - JNB = 1.0 - 2*.25 = .5us
                DELAY_500NS;
                i2c_bit0 = PMB_DATA;
        
                // Thigh + Tr - JNB - MOV - .5 = 4.0 + 1.0 - 2*.25 - .25 - .5 = 3.75us + 4us for bqxxxx
                // delay = delay_count X .75us + .5us; used for a delay longer than 1.5us
                // for (delay_count = 10; delay_count; delay_count--) _nop_();
                for (delay_count = 4; delay_count; delay_count--) _nop_(); // WW
        
                PMB_CLK = 0;
        
                // Tlow + Tf = 4.7 + .3 = 5.0us + 4us for bqxxxx
                // delay = delay_count X .75us + .5us; used for a delay longer than 1.5us
                // for (delay_count = 11; delay_count; delay_count--) _nop_();
                for (delay_count = 2; delay_count; delay_count--) _nop_(); // WW
            }
    
            if ((i == (j-1)) && (nack_byte == 0xFF)) 
                PMB_DATA = 1;  // do a NACK if the last byte has been read
            else PMB_DATA = 0; // if not the last byte to read, pull PMB_DATA low to indicate a master ACK to slave
    
            // Tlow + Tf - 4*.25 = 4.7 + .3 - 4*.25 = 4.0us + 4us for bqxxxx
            // delay = delay_count X .75us + .5us; used for a delay longer than 1.5us
            // for (delay_count = 10; delay_count; delay_count--) _nop_();
            for (delay_count = 4; delay_count; delay_count--) _nop_(); // WW
    
            if ((i == (j-1)) && (nack_byte == 0xFF)) 
                PMB_DATA = 1;  // do a NACK if the last byte has been read
            else PMB_DATA = 0; // if not the last byte to read, pull PMB_DATA low to indicate a master ACK to slave
    
            // Tlow + Tf - 4*.25 = 4.7 + .3 - 4*.25 = 4.0us + 4us for bqxxxx
            // delay = delay_count X .75us + .5us; used for a delay longer than 1.5us
            // for (delay_count = 10; delay_count; delay_count--) _nop_();
            for (delay_count = 4; delay_count; delay_count--) _nop_(); // WW
    
            PMB_CLK = 1;
            DELAY_500NS;
    
            // each cycle of the while loop takes from 3us to 3.25us
            while (!PMB_CLK) // slave is holding down or stretching PMB_CLK
            {
                pmb_clk_low_stretch_timer++;
                if (pmb_clk_low_stretch_timer > 8333) return ERROR; // 25ms timeout of PMBus clock low stretching
            }
    
            // Thigh + Tr - JNB = 4.0 + 1.0 - 2*.25 = 4.5us + 4us for bqxxxx
            // delay = delay_count X .75us + .5us; used for a delay longer than 1.5us
            // for (delay_count = 10; delay_count; delay_count--) _nop_();
            for (delay_count = 4; delay_count; delay_count--) _nop_(); // WW
    
            PMB_CLK = 0;
    
            // delay = delay_count X .75us + .5us; used for a delay longer than 1.5us
            // for (delay_count = 20; delay_count; delay_count--) _nop_();
            for (delay_count = 8; delay_count; delay_count--) _nop_(); // WW
            
            *destination_buf = i2c_bits; // save it
            destination_buf++; // read next byte
            
            PMB_DATA = 1; // release PMB_DATA to floating and become an input
        }
    }

    return NO_ERROR; // success
}


void i2c_reset(void)
{
    PMB_DATA = 1;      // release data to float or high
    DELAY_500NS;
    // WW while (!PMB_DATA); // slave(s) is holding down PMB_DATA
    PMB_CLK = 1;       // release clk to float or high
    DELAY_500NS;
    // WW while (!PMB_CLK);  // slave(s) is holding down PMB_CLK

    PMBus_Busy = 0;    // release PMBus
    PMBus_Group_Command_Busy = 0;
    previous_crc8 = 0; // this is for group command
}

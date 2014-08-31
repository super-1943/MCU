#include "reg52modified.h"
#include "types.h"
#include "tusb2136.h"


BYTE eeprom_read(WORD wAddress, BYTE bNumber, PBYTE pbDataArray);
BYTE eeprom_write(WORD wAddress, BYTE bNumber, PBYTE pbDataArray);


//----------------------------------------------------------------------------
BYTE eeprom_read(WORD wAddress, BYTE bNumber, PBYTE pbDataArray)
{
    // If error, return a value other than zero.
    if(bNumber == 0x00) return NO_ERROR;

    bI2CSTA = 0x10; // set to 400KHz, clear everthing else
    bI2CADR = 0xA0; // 0xA0 for EEPROM address + 0 for write

	bI2CDAO = (BYTE)(wAddress >> 8); // write high byte of EEPROM address word
	while(!(bI2CSTA & I2CSTA_TXE)); // wait for previous EEPROM write to finish
    if (bI2CSTA & I2CSTA_ERR) return ERROR;

	bI2CDAO = (BYTE)wAddress; // write low byte of EEPROM address word
	while(!(bI2CSTA & I2CSTA_TXE)); // wait for previous EEPROM write to finish
    if (bI2CSTA & I2CSTA_ERR) return ERROR;

    bI2CADR = 0xA1; // 0xA0 for EEPROM address + 1 for read
    bI2CDAO = 0x00; // write a dummy byte to start read

    // SRD should be cleared
    while(bNumber > 1)
    {
        while(!(bI2CSTA & I2CSTA_RXF)); // wait for reading a byte
        if (bI2CSTA & I2CSTA_ERR) return ERROR;
        *pbDataArray++ = bI2CDAI;
        bNumber--;
    }
   
    // read the last byte 
    bI2CSTA |= I2CSTA_SRD;
    while(!(bI2CSTA & I2CSTA_RXF)); // wait for reading a byte
    if (bI2CSTA & I2CSTA_ERR) return ERROR;
    *pbDataArray = bI2CDAI;

    return NO_ERROR;
}


//----------------------------------------------------------------------------
BYTE eeprom_write(WORD wAddress, BYTE bNumber, PBYTE pbDataArray)
{
    // If error, return a value other than zero.
    if(bNumber == 0x00) return NO_ERROR;

    bI2CSTA = 0x10; // set to 400KHz, clear everthing else
    bI2CADR = 0xA0; // 0xA0 for EEPROM address + 0 for write

	bI2CDAO = (BYTE)(wAddress >> 8); // write high byte of EEPROM address word
	while(!(bI2CSTA & I2CSTA_TXE)); // wait for previous EEPROM write to finish
    if (bI2CSTA & I2CSTA_ERR) return ERROR;

	bI2CDAO = (BYTE)wAddress; // write low byte of EEPROM address word
	while(!(bI2CSTA & I2CSTA_TXE)); // wait for previous EEPROM write to finish
    if (bI2CSTA & I2CSTA_ERR) return ERROR;

    // SRD should be cleared.
    while(bNumber > 1){
        bI2CDAO = *pbDataArray++;
    	while(!(bI2CSTA & I2CSTA_TXE)); // wait for previous EEPROM write to finish
        if (bI2CSTA & I2CSTA_ERR) return ERROR;
        bNumber--;
    }

    // write the last byte
	//sendUartString("Writing the last byte \n\r");
    bI2CSTA |= I2CSTA_SWR;                          // set SWR bit
    bI2CDAO  = *pbDataArray;                        // write out the data
	while(!(bI2CSTA & I2CSTA_TXE)); // wait for previous EEPROM write to finish
    if (bI2CSTA & I2CSTA_ERR) return ERROR;

    return NO_ERROR;
}

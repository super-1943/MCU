/******************************************************************************
 *                         VAULT INFORMATION SERVICES                         *
 *                          TEXAS INSTRUMENTS, INC.                           *
 *                                                                            * 
 *                             TUSB2136 Header File                           *
 *                                                                            *  
 *----------------------------------------------------------------------------*
 * Programmed by: Lobo Tai (lobotai@ti.com)                                   *
 * Develop Date:  30/Sep/2000                                                 *  
 *----------------------------------------------------------------------------*
 * Description: This header file defines constants that relate to the         *
 *   TUSB2136 design, such as the endpoint configuration, hub config, etc.    *
 *   Constants relating to USB-specific values are contained in usb.h.        *
 ******************************************************************************/

#ifndef _TUSB2136_H_
#define _TUSB2136_H_

#ifdef __cplusplus
extern "C"
{
#endif

// EDB Data Structure
typedef struct _tEDB
{
    BYTE    bEPCNF;             // Endpoint Configuration
    BYTE    bEPBBAX;            // Endpoint X Buffer Base Address
    BYTE    bEPBCTX;            // Endpoint X Buffer byte Count
    BYTE    bSPARE0;            // no used
    BYTE    bSPARE1;            // no used
    BYTE    bEPBBAY;            // Endpoint Y Buffer Base Address
    BYTE    bEPBCTY;            // Endpoint Y Buffer byte Count
    BYTE    bEPSIZXY;           // Endpoint XY Buffer Size
} tEDB, *tpEDB;

typedef struct _tEDB0
{
    BYTE    bIEPCNFG;           // Input Endpoint 0 Configuration Register
    BYTE    bIEPBCNT;           // Input Endpoint 0 Buffer Byte Count
    BYTE    bOEPCNFG;           // Output Endpoint 0 Configuration Register
    BYTE    bOEPBCNT;           // Output Endpoint 0 Buffer Byte Count
} tEDB0, *tpEDB0;

#define SYS_CLOCK 12

/*----------------------------------------------------------------------------+
| Constant Definition                                                         |
+----------------------------------------------------------------------------*/
#define SIZEOF_BOOTCODE_CONFIG_DESC_GROUP SIZEOF_CONFIG_DESCRIPTOR+SIZEOF_INTERFACE_DESCRIPTOR+SIZEOF_ENDPOINT_DESCRIPTOR+SIZEOF_KEYBD_HID_DESCRIPTOR+SIZEOF_ENDPOINT_DESCRIPTOR
#define SIZEOF_BOOTCODE_STRING_DESC_GROUP 0x50

#define pbExternalRAM  ((unsigned char xdata *)0x0000)       // use this for the future design
#define pbInternalROM  ((unsigned char code *)0x0000)

// TUSB2136 VID and PID Definition
#ifdef XXX
#define HUB_VID_L       0x51        // TI = 0x0451
#define HUB_VID_H       0x04
#define HUB_PID_L       0x45        // 1 external interface
#define HUB_PID_H       0x31
#define FUNCTION_PID_L  0x36
#define FUNCTION_PID_H  0x21
#endif

// USB related Constant
#define MAX_ENDPOINT_NUMBER     0x03
#define EP0_MAX_PACKET_SIZE     0x08
#define EP_MAX_PACKET_SIZE      0x40

// redefine base addresses. WW
#define OEP1_X_BUFFER_ADDRESS   0xFD80  // Output  Endpoint 1 X Buffer Base-address
#define OEP1_Y_BUFFER_ADDRESS   0xFDC0  // Output  Endpoint 1 Y Buffer Base-address
#define IEP1_X_BUFFER_ADDRESS   0xFE00  // Input Endpoint 1 X Buffer Base-address
#define IEP1_Y_BUFFER_ADDRESS   0xFE40  // Input Endpoint 1 Y Buffer Base-address

#define IEP2_X_BUFFER_ADDRESS   0xFE80  // Input  Endpoint 2 X Buffer Base-address
#define IEP2_Y_BUFFER_ADDRESS   0xFE90  // Input  Endpoint 2 Y Buffer Base-address
#define OEP2_X_BUFFER_ADDRESS   0xFEA0  // Output Endpoint 2 X Buffer Base-address
#define OEP2_Y_BUFFER_ADDRESS   0xFEB0  // Output Endpoint 2 Y Buffer Base-address
#define IEP3_X_BUFFER_ADDRESS   0xFEC0  // Input  Endpoint 3 X Buffer Base-address
#define IEP3_Y_BUFFER_ADDRESS   0xFED0  // Input  Endpoint 3 Y Buffer Base-address
#define OEP3_X_BUFFER_ADDRESS   0xFEE0  // Output Endpoint 3 X Buffer Base-address
#define OEP3_Y_BUFFER_ADDRESS   0xFEE8  // Output Endpoint 3 Y Buffer Base-address

// Miscellaneous Registers
#define MCNFG_SDW       0x01
#define MCNFG_R0        0x02    // Revision Number R[3:0]
#define MCNFG_R1        0x04
#define MCNFG_R2        0x08
#define MCNFG_R3        0x10
#define MCNFG_OVCE      0x20    // Overcurrent detection enable bit
                                // 0:disable, 1:enable
#define MCNFG_XINT      0x40    // INT1 source control bit
                                // 0:p3.3 1:P2[7:0]
#define MCNFG_48MHZ     0x80    // 48MHz
#define WDCSR_WDT       0x01    // Watchdog timer reset bit
                                // write a 1 to reset timer
#define WDCSR_WDR       0x40    // Watchdog reset indication bit
                                // 0:a power-up or USB reset
                                // 1:watchdog timeout reset occurred.
#define WDCSR_WDE       0x80    // Watchdog timer enable bit
                                // 0:disable(only cleared on power-up, USB or WDT reset)
                                // 1:enable

// Power Control Register (@ SFR 87h)
// PCON            0x87    // sfr 0x87
#define PCON_IDL        0x01    // MCU idle bit
                                // 0: MCU NOT in idle, 1:MCU idle
#define PCON_GF0        0x04    // General purpose bit
#define PCON_GF1        0x08    // General purpose bit
#define PCON_SMOD       0x80    // Double baud rate control bit

// EndPoint Desciptor Block
#define EPCNF_USBIE     0x04    // USB Interrupt on Transaction Completion. Set By MCU
                                // 0:No Interrupt, 1:Interrupt on completion
#define EPCNF_STALL     0x08    // USB Stall Condition Indication. Set by UBM
                                // 0: No Stall, 1:USB Install Condition
#define EPCNF_DBUF      0x10    // Double Buffer Enable. Set by MCU
                                // 0: Primary Buffer Only(x-buffer only), 1:Toggle Bit Selects Buffer
#define EPCNF_TOGLE     0x20    // USB Toggle bit. This bit reflects the toggle sequence bit of DATA0 and DATA1.
#define EPCNF_ISO       0x40    // ISO=0, Non Isochronous transfer. This bit must be cleared by MCU since only non isochronous transfer is supported.
#define EPCNF_UBME      0x80    // UBM Enable or Disable bit. Set or Clear by MCU.
                                // 0:UBM can't use this endpoint
                                // 1:UBM can use this endpoint
#define EPBCT_BYTECNT_MASK 0x7F // MASK for Buffer Byte Count
#define EPBCT_NAK       0x80    // NAK, 0:No Valid in buffer, 1:Valid packet in buffer

// Endpoint 0 Descriptor Registers
#define EPBCNT_NAK      0x80    // NAK bit
                                // 0:buffer contains valid data
                                // 1:buffer is empty

// USB Registers
#define USBSTA_STPOW    0x01    // Setup Overwrite Bit. Set by hardware when setup packet is received
                                // while there is already a packet in the setup buffer.
                                // 0:Nothing, 1:Setup Overwrite
#define USBSTA_RWUP		0x02	// Remote wakeup overwrite bit
#define USBSTA_SETUP    0x04    // Setup Transaction Received Bit. As long as SETUP is '1',
                                // IN and OUT on endpoint-0 will be NAKed regardless of their real NAK bits values.
#define USBSTA_PWON     0x08    // Power Request for port3
#define USBSTA_PWOFF    0x10    // Power Off Request for port3
#define USBSTA_RESR     0x20    // Function Resume Request Bit. 0:clear by MCU, 1:Function Resume is detected.
#define USBSTA_SUSR     0x40    // Function Suspended Request Bit. 0:clear by MCU, 1:Function Suspend is detected.
#define USBSTA_RSTR     0x80    // Function Reset Request Bit. This bit is set in response to a global or selective suspend condition.
                                // 0:clear by MCU, 1:Function reset is detected.

#define USBMSK_STPOW    0x01    // Setup Overwrite Interrupt Enable Bit
                                // 0: disable, 1:enable
#define USBMSK_RWUP		0x02	
#define USBMSK_SETUP    0x04    // Setup Interrupt Enable Bit
                                // 0: disable, 1:enable
#define USBMSK_RESR     0x20    // Function Resume Interrupt Enable Bit
                                // 0: disable, 1:enable
#define USBMSK_SUSR     0x40    // Function Suspend Interrupt Enable Bit
                                // 0: disable, 1:enable
#define USBMSK_RSTR     0x80    // Function Reset Interrupt Enable Bit
                                // 0: disable, 1:enable

#define USBCTL_DIR      0x01    // USB traffic direction 0: USB out packet, 1:in packet (from TUSB5152 to Host)
#define USBCTL_SIR      0x02    // Setup interrupt status bit
                                // 0: SETUP interrupt is not served.
                                // 1: SETUP interrupt in progess
#define USBCTL_SELF     0x04    // Bus/self powered bit
                                // 0: bus, 1:self
#define USBCTL_RWE      0x08    // remote wakeup enable bit
                                // 0: disable, 1:enable                                
#define USBCTL_FRSTE    0x10    // Function Reset Condition Bit.
                                // This bit connects or disconnects the USB Function Reset from the MCU reset
                                // 0:not connect, 1:connect
#define USBCTL_RWUP     0x20    // Device Remote Wakeup Request
                                // 0:nothing, 1:remote wakeup request to USB Host
#define USBCTL_U12      0x40    // USB Hub version
                                // 0:1.x, 1:2.x
#define USBCTL_CONT     0x80    // Connect or Disconnect Bit
                                // 0:Upstream port is disconnected. Pull-up disabled
                                // 1:Upstream port is connected. Pull-up enabled

#define HUBCNFG_P1E         0x01    // Hub Port 1 enable/disable control bit
                                    // 0: disable, 1:enable
#define HUBCNFG_P1A         0x02    // Hub Port 1 connection bit
                                    // 0: removable, 1:fixed
#define HUBCNFG_P2E         0x04    // Hub Port 1 enable/disable control bit
                                    // 0: disable, 1:enable
#define HUBCNFG_P2A         0x08    // Hub Port 1 connection bit
                                    // 0: removable, 1:fixed
#define HUBCNFG_P3_MASK     0x30    // Hub Port 3 setting bits
                                    // 00b: Port 3 disable
                                    // 01b: Port 3 enable and fixed
                                    // 10b: Port 3 enable but removable and not-attached
                                    // 11b: Port 3 enable but removable and attached
#define HUBCNFG_P3_FIXED    0x10    // 01b
#define HUBCNFG_P3_MOV_DIS  0x20    // 10b
#define HUBCNFG_P3_MOV_ENA  0x30    // 11b

#define HUBCNFG_IG          0x40    // Hub Power control bit
                                    // 0: individual, 1:ganged
#define HUBCNFG_OCP       	0x80    // Overcurrent protection control bit
                                    // 0: not available, 1:available


#define HUBPOTG_100MS   0x32        // power-on to power-good time is 100ms ( in 2ms increment)
#define HUBCURT_100MA   0x64        // hub requires 100mA

#define VECINT_NO_INTERRUPT             0x00
#define VECINT_OUTPUT_ENDPOINT1         0x12
#define VECINT_OUTPUT_ENDPOINT2         0x14
#define VECINT_OUTPUT_ENDPOINT3         0x16

#define VECINT_INPUT_ENDPOINT1          0x22
#define VECINT_INPUT_ENDPOINT2          0x24
#define VECINT_INPUT_ENDPOINT3          0x26

#define VECINT_STPOW_PACKET_RECEIVED    0x30            // USBSTA
#define VECINT_SETUP_PACKET_RECEIVED    0x32            // USBSTA
#define VECINT_POWER_ON                 0x34
#define VECINT_POWER_OFF                0x36
#define VECINT_RESR_INTERRUPT           0x38            // USBSTA
#define VECINT_SUSR_INTERRUPT           0x3A            // USBSTA
#define VECINT_RSTR_INTERRUPT           0x3C            // USBSTA
#define VECINT_I2C_RXF_INTERRUPT        0x40            // I2CSTA
#define VECINT_I2C_TXE_INTERRUPT        0x42            // I2CSTA
#define VECINT_INPUT_ENDPOINT0          0x44
#define VECINT_OUTPUT_ENDPOINT0         0x46

//I2C Registers
#define I2CSTA_SWR          0x01        // Stop Write Enable
                                        // 0:disable, 1:enable
#define I2CSTA_SRD          0x02        // Stop Read Enable
                                        // 0:disable, 1:enable
#define I2CSTA_TIE          0x04        // I2C Transmitter Empty Interrupt Enable
                                        // 0:disable, 1:enable
#define I2CSTA_TXE          0x08        // I2C Transmitter Empty
                                        // 0:full, 1:empty
#define I2CSTA_400K         0x10        // I2C Speed Select
                                        // 0:100kHz, 1:400kHz
#define I2CSTA_ERR          0x20        // Bus Error Condition
                                        // 0:no bus error, 1:bus error
#define I2CSTA_RIE          0x40        // I2C Receiver Ready Interrupt Enable
                                        // 0:disable, 1:enable
#define I2CSTA_RXF          0x80        // I2C Receiver Full
                                        // 0:empty, 1:full
#define I2CADR_READ         0x01        // Read Write Command Bit
                                        // 0:write, 1:read

//-----------------------------------------------------------------------------------------------
// register address definition
//-----------------------------------------------------------------------------------------------

// EndPoint Desciptor Block
// USB Data Buffer
#define bOEP0_BUFFER_ADDRESS    (* (unsigned char xdata *)0xFEF0)    // Output Endpoint 0 Buffer Base-address
#define bIEP0_BUFFER_ADDRESS    (* (unsigned char xdata *)0xFEF8)    // Input  Endpoint 0 Buffer Base-address
#define bEP0_SETUP_ADDRESS      (* (unsigned char xdata *)0xFF00)    // setup packet

#define pbOEP0_BUFFER_ADDRESS   ( (unsigned char xdata *)0xFEF0)    // Output Endpoint 0 Buffer Base-address
#define pbIEP0_BUFFER_ADDRESS   ( (unsigned char xdata *)0xFEF8)    // Input  Endpoint 0 Buffer Base-address
#define pbEP0_SETUP_ADDRESS     ( (unsigned char xdata *)0xFF00)    // setup packet

// Endpoint descriptor block
#define bOEPCNF_1               (* (unsigned char xdata *)0xFF08)    // Output Endpoint 1 Configuration
#define bOEPCNF_2               (* (unsigned char xdata *)0xFF10)    // Output Endpoint 2 Configuration
#define bOEPCNF_3               (* (unsigned char xdata *)0xFF18)    // Output Endpoint 3 Configuration

#define bOEPBBAX_1              (* (unsigned char xdata *)0xFF09)    // Output Endpoint 1 X-Buffer Base-address
#define bOEPBBAX_2              (* (unsigned char xdata *)0xFF11)    // Output Endpoint 2 X-Buffer Base-address
#define bOEPBBAX_3              (* (unsigned char xdata *)0xFF19)    // Output Endpoint 3 X-Buffer Base-address

#define bOEPDCTX_1              (* (unsigned char xdata *)0xFF0A)    // Output Endpoint 1 X Byte Count
#define bOEPDCTX_2              (* (unsigned char xdata *)0xFF12)    // Output Endpoint 2 X Byte Count
#define bOEPDCTX_3              (* (unsigned char xdata *)0xFF1A)    // Output Endpoint 3 X Byte Count

#define bOEPBBAY_1              (* (unsigned char xdata *)0xFF0D)    // Output Endpoint 1 Y-Buffer Base-address
#define bOEPBBAY_2              (* (unsigned char xdata *)0xFF15)    // Output Endpoint 2 Y-Buffer Base-address
#define bOEPBBAY_3              (* (unsigned char xdata *)0xFF1D)    // Output Endpoint 3 Y-Buffer Base-address

#define bOEPDCTY_1              (* (unsigned char xdata *)0xFF0E)    // Output Endpoint 1 Y Byte Count
#define bOEPDCTY_2              (* (unsigned char xdata *)0xFF16)    // Output Endpoint 2 Y Byte Count
#define bOEPDCTY_3              (* (unsigned char xdata *)0xFF1E)    // Output Endpoint 3 Y Byte Count

#define bOEPSIZXY_1             (* (unsigned char xdata *)0xFF0F)    // Output Endpoint 1 XY-Buffer Size
#define bOEPSIZXY_2             (* (unsigned char xdata *)0xFF17)    // Output Endpoint 2 XY-Buffer Size
#define bOEPSIZXY_3             (* (unsigned char xdata *)0xFF1F)    // Output Endpoint 3 XY-Buffer Size

#define bIEPCNF_1               (* (unsigned char xdata *)0xFF48)    // Input Endpoint 1 Configuration
#define bIEPCNF_2               (* (unsigned char xdata *)0xFF50)    // Input Endpoint 2 Configuration
#define bIEPCNF_3               (* (unsigned char xdata *)0xFF58)    // Input Endpoint 3 Configuration

#define bIEPBBAX_1              (* (unsigned char xdata *)0xFF49)    // Input Endpoint 1 X-Buffer Base-address
#define bIEPBBAX_2              (* (unsigned char xdata *)0xFF51)    // Input Endpoint 2 X-Buffer Base-address
#define bIEPBBAX_3              (* (unsigned char xdata *)0xFF59)    // Input Endpoint 3 X-Buffer Base-address

#define bIEPDCTX_1              (* (unsigned char xdata *)0xFF4A)    // Input Endpoint 1 X Byte Count
#define bIEPDCTX_2              (* (unsigned char xdata *)0xFF52)    // Input Endpoint 2 X Byte Count
#define bIEPDCTX_3              (* (unsigned char xdata *)0xFF5A)    // Input Endpoint 3 X Byte Count

#define bIEPBBAY_1              (* (unsigned char xdata *)0xFF4D)    // Input Endpoint 1 Y-Buffer Base-address
#define bIEPBBAY_2              (* (unsigned char xdata *)0xFF55)    // Input Endpoint 2 Y-Buffer Base-address
#define bIEPBBAY_3              (* (unsigned char xdata *)0xFF5D)    // Input Endpoint 3 Y-Buffer Base-address

#define bIEPDCTY_1              (* (unsigned char xdata *)0xFF4E)    // Input Endpoint 1 Y Byte Count
#define bIEPDCTY_2              (* (unsigned char xdata *)0xFF56)    // Input Endpoint 2 Y Byte Count
#define bIEPDCTY_3              (* (unsigned char xdata *)0xFF5E)    // Input Endpoint 3 Y Byte Count

#define bIEPSIZXY_1             (* (unsigned char xdata *)0xFF4F)    // Input Endpoint 1 XY-Buffer Size
#define bIEPSIZXY_2             (* (unsigned char xdata *)0xFF57)    // Input Endpoint 2 XY-Buffer Size
#define bIEPSIZXY_3             (* (unsigned char xdata *)0xFF5F)    // Input Endpoint 3 XY-Buffer Size

// Endpoint 0 Descriptor Registers
#define bIEPCNFG_0              (* (unsigned char xdata *)0xFF80)    // Input Endpoint Configuration Register
#define bIEPBCNT_0              (* (unsigned char xdata *)0xFF81)    // Input Endpoint 0 Byte Count
#define bOEPCNFG_0              (* (unsigned char xdata *)0xFF82)    // Output Endpoint Configuration Register
#define bOEPBCNT_0              (* (unsigned char xdata *)0xFF83)    // Output Endpoint 0 Byte Count

// Miscellaneous Registers
#define bMCNFG                  (* (unsigned char xdata *)0xFF90)    // MCU Configuration Register
#define bVECINT                 (* (unsigned char xdata *)0xFF92)    // Vector Interrupt Register
#define bWDCSR                  (* (unsigned char xdata *)0xFF93)    // Watchdog Timer, Control & Status Register

#define bPUR3                  	(* (unsigned char xdata *)0xFF97)    // Pull-up control register 1=Enabled 0=Disabled
#define bPUR2                  	(* (unsigned char xdata *)0xFF96)    // Pull-up control register 1=Enabled 0=Disabled
#define bPUR1                  	(* (unsigned char xdata *)0xFF95)    // Pull-up control register 1=Enabled 0=Disabled
#define bPUR0                  	(* (unsigned char xdata *)0xFF94)    // Pull-up control register 1=Enabled 0=Disabled


// I2C Registers
#define bI2CSTA                 (* (unsigned char xdata *)0xFFF0)    // I2C Status and Control Register
#define bI2CDAO                 (* (unsigned char xdata *)0xFFF1)    // I2C Data Out Register
#define bI2CDAI                 (* (unsigned char xdata *)0xFFF2)    // I2C Data In Register
#define bI2CADR                 (* (unsigned char xdata *)0xFFF3)    // I2C Address Register

// USB Registers
#define bHUBCURT                (* (unsigned char xdata *)0xFFF4)    // HUB Current Descriptor Register
#define bHUBPOTG                (* (unsigned char xdata *)0xFFF5)    // HUB Power-on to Power-Good Descriptor Register
#define bVIDSTA                 (* (unsigned char xdata *)0xFFF6)    // VID/PID status register
#define bHUBCNFG                (* (unsigned char xdata *)0xFFF7)    // HUB Configuration Register
#define bHUBPIDL                (* (unsigned char xdata *)0xFFF8)    // HUB PID Low-byte Register
#define bHUBPIDH                (* (unsigned char xdata *)0xFFF9)    // HUB PID High-byte Register
#define bHUBVIDL                (* (unsigned char xdata *)0xFFFA)    // HUB VID Low-byte Register
#define bHUBVIDH                (* (unsigned char xdata *)0xFFFB)    // HUB VID High-byte Register
#define bUSBCTL                 (* (unsigned char xdata *)0xFFFC)    // USB Control Register
#define bUSBMSK                 (* (unsigned char xdata *)0xFFFD)    // USB Interrupt Mask Register
#define bUSBSTA                 (* (unsigned char xdata *)0xFFFE)    // USB Status Register
#define bFUNADR                 (* (unsigned char xdata *)0xFFFF)    // This register contains the device function address.

#define bINTCFG                 (* (unsigned char xdata *)0xFF84)    // Interrupt P2 delay

#define NO_MORE_DATA 0xFFFF
#define USB_RETURN_DATA_LENGTH 4


#ifdef __cplusplus
}
#endif
#endif /* _TUSB2136_H_ */

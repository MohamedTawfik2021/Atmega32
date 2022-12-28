/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <DIO>
 *       Module:  Digital input output
 *
 *  Description:  DIO header file    
 *  
 *********************************************************************************************************************/
#ifndef DIO_H_
#define DIO_H_

#include "StdTypes.h"
#include "DIO_cfg.h"

typedef enum
{
    PortA=0,
    PortB,
    PortC,
    PortD
}PortID;

typedef enum
{
    PIN_0A=0,
    PIN_1A,
    PIN_2A,
    PIN_3A,
    PIN_4A,
    PIN_5A,
    PIN_6A,
    PIN_7A,

    PIN_0B,
    PIN_1B,
    PIN_2B,
    PIN_3B,
    PIN_4B,
    PIN_5B,
    PIN_6B,
    PIN_7B,

    PIN_0C,
    PIN_1C,
    PIN_2C,
    PIN_3C,
    PIN_4C,
    PIN_5C,
    PIN_6C,
    PIN_7C,

    PIN_0D,
    PIN_1D,
    PIN_2D,
    PIN_3D,
    PIN_4D,
    PIN_5D,
    PIN_6D,
    PIN_7D,

}PinID;

typedef enum
{
   INfree=0,
   INup,
   OUT

}Direction;

void DIO_Define_Pin(PinID,Direction);
void DIO_SET_Pin(PinID);
void DIO_CLR_Pin(PinID);
void DIO_TOG_Pin(PinID);
u8 DIO_Read_Pin(PinID);

void DIO_Define_Port(PortID, u8 mask);
void DIO_Write_Port(PortID,u8 value);
u8   DIO_Read_Port(PortID);


 
#endif  /* DIO_H_ */

/**********************************************************************************************************************
 *  END OF FILE: DIO_H_
 *********************************************************************************************************************/

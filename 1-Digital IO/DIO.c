/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  DIO.c
 *        \brief  Digital input output 
 *
 *      \details  ATmega32 DIO Program file
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <avr/io.h>
#include "DIO.h"
#include "BitMath.h"
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void DIO_Define_Pin(PinID,Direction)        
* \Description     : Define a Dio Pin and Set the direction                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : PIN_ID , Direction State                    
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void DIO_Define_Pin(PinID pin ,Direction state)
{
	if (pin <8)
    {	switch(state)
		{
          case OUT:
			SET_BIT(DDRA,pin);
			break;
		  case INup:
			CLR_BIT(DDRA,pin);
			SET_BIT(PORTA,pin);
			break;
		  case INfree:
			CLR_BIT(DDRA,pin);
			break;
		}
    }
	else if (pin >7 && pin <16)
    {	pin%=8; 
        switch(state)
		{
          case OUT:
			SET_BIT(DDRB,pin);
			break;
		  case INup:
			CLR_BIT(DDRB,pin);
			SET_BIT(PORTB,pin);
			break;
		  case INfree:
			CLR_BIT(DDRB,pin);
			break;
		}
    }	
	else if (pin >15 && pin <24)
    {	pin%=16; 
        switch(state)
		{
          case OUT:
			SET_BIT(DDRC,pin);
			break;
		  case INup:
			CLR_BIT(DDRC,pin);
			SET_BIT(PORTC,pin);
			break;
		  case INfree:
			CLR_BIT(DDRC,pin);
			break;
		}
    } 
	else if (pin >23 && pin <32)
    {	pin%=24; 
        switch(state)
		{
          case OUT:
			SET_BIT(DDRD,pin);
			break;
		  case INup:
			CLR_BIT(DDRD,pin);
			SET_BIT(PORTD,pin);
			break;
		  case INfree:
			CLR_BIT(DDRD,pin);
			break;
		}
    }         
}

/******************************************************************************
* \Syntax          : void DIO_Set_Pin(PinID)     
* \Description     : Set PIN in HIGH State                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : PIN_ID                 
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void DIO_SET_Pin(PinID pin) 
{
	if (pin <8)
    {
        SET_BIT(PORTA,pin);
    }
	else if (pin >7 && pin <16)
    {	pin%=8; 
        SET_BIT(PORTB,pin);
    }	
	else if (pin >15 && pin <24)
    {	pin%=16; 
        SET_BIT(PORTC,pin);
    }	    
    else if (pin >23 && pin <32)
    {	pin%=24; 
        SET_BIT(PORTD,pin);
    }	
}

/******************************************************************************
* \Syntax          : void DIO_Clr_Pin(PinID pin)      
* \Description     : Set PIN in LOW State                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : PIN_ID                 
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void DIO_CLR_Pin(PinID pin) 
{
	if (pin <8)
    {
        CLR_BIT(PORTA,pin);
    }
	else if (pin >7 && pin <16)
    {	pin%=8; 
        CLR_BIT(PORTB,pin);
    }	
	else if (pin >15 && pin <24)
    {	pin%=16; 
        CLR_BIT(PORTC,pin);
    }	    
    else if (pin >23 && pin <32)
    {	pin%=24; 
        CLR_BIT(PORTD,pin);
    }	
	
}

/******************************************************************************
* \Syntax          : void DIO_Togg_Pin(PinID pin)      
* \Description     : Toggle PIN State                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : PIN_ID                 
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void DIO_TOG_Pin(PinID pin) 
{
	if (pin <8)
    {
        TOG_BIT(PORTA,pin);
    }
	else if (pin >7 && pin <16)
    {	pin%=8; 
        TOG_BIT(PORTB,pin);
    }	
	else if (pin >15 && pin <24)
    {	pin%=16; 
        TOG_BIT(PORTC,pin);
    }	    
    else if (pin >23 && pin <32)
    {	pin%=24; 
        TOG_BIT(PORTD,pin);
    }	
	
}

/******************************************************************************
* \Syntax          : u8 DIO_Read_Pin(PinID pin)      
* \Description     : Read PIN State                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : PIN_ID                 
* \Parameters (out): None                                                      
* \Return value:   : PIN State
*                                                                     
*******************************************************************************/
u8 DIO_Read_Pin(PinID pin) 
{
    u8 pin_state=0;
	if (pin <8)
    {
      pin_state = GET_BIT(PINA,pin);
    }
	else if (pin >7 && pin <16)
    {	pin%=8; 
      pin_state = GET_BIT(PINB,pin);
    }	
	else if (pin >15 && pin <24)
    {	pin%=16; 
      pin_state = GET_BIT(PINC,pin);
    }	    
    else if (pin >23 && pin <32)
    {	pin%=24; 
      pin_state = GET_BIT(PIND,pin);
    }	
	
    return pin_state;
}

/******************************************************************************
* \Syntax          : void DIO_Def_Port(PortID, u8 mask);       
* \Description     : Define a Dio Port and Set the direction                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : PORT_ID , Direction Mask                    
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void DIO_Define_Port(PortID port, u8 mask)
{
    switch(port)
	{
	  case PortA:
		DDRA=mask;
		break;
	  case PortB:
		DDRB=mask;
		break;
	  case PortC:
	    DDRC=mask;
		break;
	  case PortD:
		DDRD=mask;
		break;
    }	
	
}

/******************************************************************************
* \Syntax          : void DIO_Set_Port(PortID,u8 value)     
* \Description     : Set PORT State Value                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : PORT_ID                 
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void DIO_Write_Port(PortID port ,u8 value)
{
 switch(port)
	{
	  case PortA:
		PORTA=value;
		break;
	  case PortB:
		PORTB=value;
		break;
	  case PortC:
	    PORTC=value;
		break;
	  case PortD:
		PORTD=value;
		break;
    }	
		
	
}

/******************************************************************************
* \Syntax          : u8 DIO_Read_Port(PortID)     
* \Description     : Read PORT State                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : PORT_ID                 
* \Parameters (out): None                                                      
* \Return value:   : PORT State
*                                                                     
*******************************************************************************/
u8 DIO_Read_Port(PortID port) 
{   u8 port_state=0x00;
	 switch(port)
	{
	  case PortA:
		port_state = PINA;
		break;
	  case PortB:
		port_state = PINB;
		break;
	  case PortC:
	    port_state = PINC;
		break;
	  case PortD:
		port_state = PIND;
		break;
    }	
	return port_state;
	
}
/**********************************************************************************************************************
 *  END OF FILE: DIO.c
 *********************************************************************************************************************/

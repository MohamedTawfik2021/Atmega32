/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  ADC.c
 *        \brief  Analog to Digital Converter program
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/
#include <avr/io.h>
#include "ADC.h"


/******************************************************************************
* \Syntax          : void ADC_Init()        
* \Description     : ADC Initialization                                     
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                    
* \Parameters (out): None                                                      
* \Return value:   : void                                 
*******************************************************************************/
void ADC_Init()
{
	ADMUX |= (1<<REFS0);		                                        /*Vref: Avcc, ADC channel: 0 */
#if (INT_ENABLE == 0)
    ADCSRA |=((1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)) ;		        /*Enable ADC, P=freq/128  */
#else
	ADCSRA |=((1<<ADEN)|(1<<ADIE)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)) ;  /*Enable ADC,Enable Interrupt, P=freq/128  */
#endif
	
}

/******************************************************************************
* \Syntax          : u16 ADC_Read(Adc_Input channel)        
* \Description     : Read The ADC Data Register                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ADC_INPUT   ADC Channel Input                    
* \Parameters (out): None                                                      
* \Return value:   : u16 Sample Digital value
*                                                                     
*******************************************************************************/
u16 ADC_Read(ADC_INPUT channel)
{
	u8 AinH,AinLow;
	ADMUX|=(channel & 0x0f);		   /* set input channel to read */

	ADCSRA |= (1<<ADSC);		       /* start conversion */
	while((ADCSRA&(1<<ADIF))==0);	   /*monitor end of conversion interrupt flag */
	

	AinLow = (u8)ADCL;				   /*read lower byte*/
	AinH = (u8)ADCH*256;			   /*read higher 2 bits, Multiply with bit weight*/
		  		
	return(AinH + AinLow);  	       /*return digital value*/
}
/**********************************************************************************************************************
 *  END OF FILE: ADC.c
 *********************************************************************************************************************/

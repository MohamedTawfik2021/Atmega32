/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  ADC.h
 *       Module:  Analog to Digital Converter
 *
 *  Description:  ADC header file    
 *  
 *********************************************************************************************************************/
#ifndef ADC_H
#define ADC_H

#include "StdTypes.h"
#include "ADC_cfg.h"

typedef enum ADC_INPUT
{
	ADC0=0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7
	
}ADC_INPUT;


void ADC_Init();
u16 ADC_Read(ADC_INPUT channel);

#endif  /* ADC_H */

/**********************************************************************************************************************
 *  END OF FILE: ADC.h
 *********************************************************************************************************************/
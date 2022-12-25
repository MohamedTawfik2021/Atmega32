/*
 * ADC.c
 *
 * Created: 06-Dec-22 4:34:12 AM
 * Author : Moham
 */ 

#include <avr/io.h>
#include "ADC.h"

int main(void)
{
	u16 Analog=0;
	ADC_Init();
    /* Replace with your application code */
    while (1) 
    { 
		Analog = (ADC_Read(ADC0)*5000/1024);  /*result in mV*/
    }
}


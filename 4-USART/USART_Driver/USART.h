#ifndef USART_H_				       /* Define library H file if not defined */
#define USART_H_
#include "StdTypes.h"


#define F_CPU 8000000UL					/* Define CPU clock Frequency e.g. here its 8MHz */

void USART_Init(u32);				    /* USART initialize function */
u8 USART_RxChar();						/* Data receiving function */
void USART_TxChar(u8);					/* Data transmitting function */
void USART_SendString(u8*);				/* Send string of USART data function */


#endif									/* USART_H */
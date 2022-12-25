#include <avr/io.h>
#include "USART.h"
#include "StdTypes.h"

void USART_Init( u32 baudrate )
{
u32 baudPrescale = ((F_CPU / (baudrate * 16UL)) - 1);
/* Set baud rate */
UBRRH = (u8)(baudPrescale >>8);
UBRRL = (u8)baudPrescale ;
/* Enable receiver and transmitter */
UCSRB = (1<<RXEN)|(1<<TXEN);
/* Set frame format: 8data, 1stop bit */
UCSRC = (1<<URSEL)|(3<<UCSZ0);
}

void USART_TxChar( u8 data )
{
/* Wait for empty transmit buffer */
while ( !( UCSRA & (1<<UDRE)) );

/* Put data into buffer, sends the data */
UDR = data;
}

u8 USART_RxChar( void )
{
/* Wait for data to be received */
while ( !(UCSRA & (1<<RXC)) );

/* Get and return received data from buffer */
return UDR;
}


void USART_SendString(u8 *str)					/* Send string of USART data function */ 
{
	u8 i=0;																	
	while (str[i]!=0)
	{
		USART_TxChar(str[i]);						/* Send each char of string till the NULL */
		i++;
	}
}

ISR(USART_RXC_vect)
{
   USART_RxChar();
}

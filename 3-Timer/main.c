/*
 * Atmega32_Timer1.c
 *
 * Created: 11-Dec-22 10:38:36 PM
 * Author : Mohamed Tawfik
 */ 
#include <stdlib.h>
#include <avr/io.h>
#include "DIO.h"
#include "Timer1.h"
#include <util/delay.h>
#include "LCD.h"
	
int main(void)
{
	DIO_Init();
	LCD_Init();
	Timer1_Init();
  //u8 array[10]={'A','L','L','A','H',' ','A','K','B','R'};
  //u8 array[10]={"ALLAH AKBR"};
  //u8 disp1[6]={"Freq="};  
  //u8 disp2[6]={"Duty="}; 	
	  
	u8 freq_buffer[14];             // Output of the itoa function	
	u8 duty_buffer[7];             // Output of the itoa function	
  //itoa(int_value, buffer, 10);   // Convert the read value to an ascii string 

	u32 freq=0;
	f32 duty=0;
	
	while (1)
	{
        
	    GetPulseCapture(&freq,&duty);
		ltoa(freq, freq_buffer, 10); 
		itoa((u32)duty, duty_buffer, 10); 
		
        LCD_Cursor_pos(0,0);
		LCD_String(6,"Freq: ");
		LCD_String(7,freq_buffer);
		LCD_String(3," Hz");
			
		LCD_Cursor_pos(1,0);
		LCD_String(6,"Duty: ");
		LCD_String(4,duty_buffer);
		LCD_String(2," %");
		_delay_ms(100);
	 
	}
	
	
}

/*
 * LCD_prog.c
 *
 *  Created on: Sep 6, 2019
 *      Author: Mohamed Tawfik
 */

#define F_CPU 8000000UL
#include "StdTypes.h"
#include <util/delay.h>
#include "DIO.h"
#include "LCD.h"


void LCD_Init(void)
{
	//Set directions output for control pins and Data pins
	DIO_Define_Port(LCD_DATA_PORT,0xFF);
	DIO_Define_Pin(LCD_RS,OUT);
	DIO_Define_Pin(LCD_RW,OUT);
	DIO_Define_Pin(LCD_E,OUT);

	_delay_ms(40);
	LCD_cmnd(CMND_FUNCTION_SET_CMND);

	_delay_us(40);

	LCD_cmnd(CMND_DISPLAY_ON_CURSOR_OFF);

	_delay_us(40);

	LCD_cmnd(CMND_DISPLAY_CLEAR);

	_delay_ms(2);

	LCD_cmnd(CMND_ENTRY_MODE_SET);


}

void LCD_cmnd(u8 cmnd)
{
	
	//RS = 0 register of the commands
	DIO_CLR_Pin(LCD_RS);

	//RW = 0 write on the lcd
	DIO_CLR_Pin(LCD_RW);

	//PUT command on the LCD_DATA PORT
	DIO_Write_Port(LCD_DATA_PORT,cmnd);

	//Latching  E = High
	DIO_SET_Pin(LCD_E);


	//delay
   _delay_ms(1);

	//latching E = low
   DIO_CLR_Pin(LCD_E);
  
}


void LCD_write(u8 data)
{
	//RS = 1 register of the Data
	DIO_SET_Pin(LCD_RS);

	//RW = 0 write on the lcd
	DIO_CLR_Pin(LCD_RW);

	//PUT data on the LCD_DATA PORT
	DIO_Write_Port(LCD_DATA_PORT,data);

	//Latching  E = High
	DIO_SET_Pin(LCD_E);


	//delay
    _delay_ms(1);

	//latching E = low
    DIO_CLR_Pin(LCD_E);

}



void LCD_String (u8 length , u8 *str)		/* Send string to LCD function */
{
	  
	for(u8 i=0; i<length ;i++)		
	{  
		
		LCD_write(str[i]);
	}	
}

void LCD_Clear()
{
	LCD_cmnd(0x01);		/* clear display */
  //LCD_cmnd(0x02);     /* cursor at home position LCD Version 1*/
	LCD_cmnd(0x80);		/* cursor at home position LCD Version 2 */
}


void LCD_String_xy (u8 row, u8 pos, u8 length ,u8 *str)     /* Send string to LCD with xy position */
{
	if (row == 0 && pos<16)
	LCD_cmnd((pos & 0x0F)|0x80);	    /* Command of first row and required position<16 */
	else if (row == 1 && pos<16)
	LCD_cmnd((pos & 0x0F)|0xC0);   	/* Command of first row and required position<16 */
	LCD_String(length ,str);	              	/* Call LCD string function */
}


void LCD_Cursor_pos(u8 row , u8 col)
{
	if (row == 0 && col<16)
	LCD_cmnd((col & 0x0F)|0x80);	    /* Command of first row and required position<16 */
	else if (row == 1 && col<16)
	LCD_cmnd((col & 0x0F)|0xC0);   	/* Command of first row and required position<16 */
		
}
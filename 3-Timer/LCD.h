/*
 * LCD_int.h
 *
 *  Created on: Sep 6, 2019
 *      Author: Mohamed Tawfik
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

/** LCD Data Pins     */
#define LCD_DATA_PORT      PortB

/*LCD Control Pins */
#define LCD_CONTROL_PORT   PortC
#define LCD_RS             PIN_0C
#define LCD_RW             PIN_1C
#define LCD_E              PIN_2C

/*LCD Control Instruction Commands */
#define CMND_FUNCTION_SET_CMND         0x38  
#define CMND_DISPLAY_ON_CURSOR_OFF     0x0c
#define CMND_DISPLAY_CLEAR             0x01
#define CMND_ENTRY_MODE_SET            0x06
#define CMND_RETURN_HOME               0X02



/****LCD Functions decleration****/
void LCD_Init(void);
void LCD_cmnd(u8 cmnd);
void LCD_write(u8 data);
void LCD_String(u8 length ,u8 *str); // string[length]
void LCD_String_xy (u8 row, u8 pos,u8 length , u8 *str) ;  // string[length]
void LCD_Cursor_pos(u8 row , u8 col);
void LCD_Clear();

#endif /* LCD_INT_H_ */

/*
 * LCD_Confg.h
 *
 *  Created on: Aug 20, 2023
 *      Author: Mostafa Hisham
 */

#ifndef LCD_CONFG_H_
#define LCD_CONFG_H_


                               /********DATA PORT********/
#define  DATA_PORT		DIO_PORTC

                                /********CONTROL PORT********/
#define CTRL_PORT       DIO_PORTD

                                /********CONTROL PIN********/
#define CTRL_RS			DIO_PIN0
#define CTRL_RW			DIO_PIN1
#define CTRL_E			DIO_PIN2
                                /********LCD DISPLAY CONFIGURATION CONTROL********/
#define LCD_DISPLAY_MODE LCD_DISPLAY_ON
#define LCD_CURSOR_MODE  LCD_CURSOR_OFF
#define LCD_LINES_NUMBER LCD_TWO_LINES
#define LCD_FONT_MODE 	 FONT_SIZE_5X7



#endif /* LCD_CONFG_H_ */

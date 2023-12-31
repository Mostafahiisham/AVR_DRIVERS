/*
 * LCD.h
 *
 *  Created on: Aug 20, 2023
 *      Author: Mostafa Hisham
 *      Layer :LCD
 */

#ifndef INCLUDE_LCD_H_
#define INCLUDE_LCD_H_


typedef enum{
    LCD_DISPLAY_OFF,
	LCD_DISPLAY_ON
}LCD_DISPLAY_Status;
typedef enum{
    LCD_CURSOR_OFF,
    LCD_CURSOR_ON_BLINK,
	LCD_CURSOR_ON_NOT_BLINK,
}LCD_CURSOR_Status;

typedef enum{
    LCD_ONE_LINE,
    LCD_TWO_LINES
}LCD_LINES_Status;
typedef enum{
	FONT_SIZE_5X7,
    FONT_SIZE_5X10
}LCD_FONT_Status;

typedef struct
{
	LCD_DISPLAY_Status Display_status;
	LCD_CURSOR_Status Cursor_status;
	LCD_LINES_Status Line_status;
	LCD_FONT_Status Font_status;
}LCD_ControlDisplay;

void LCD_Init(void);
void LCD_DisplayStatus(LCD_ControlDisplay display);
void LCD_DisplayClear();
void LCD_DisplayReturnHome();
void LCD_ShiftCursorRight(u8 counter);
void LCD_ShiftCursorLeft(u8 counter);
void LCD_ShiftDisplayRight(u8 counter);
void LCD_ShiftDisplayLeft(u8 counter);
void LCD_SendString(const u8* Send_string);
void LCD_DisplayNumber(s64 s_number);
void LCD_SaveCustomCharacter(u8 CGRAM_Index,u8* Custom);
void LCD_DisplayCustomCharacter(u8 CGRAM_Index);
void LCD_CursorPosition(u8 line_no,u8 line_Position);

#endif /* INCLUDE_LCD_H_ */

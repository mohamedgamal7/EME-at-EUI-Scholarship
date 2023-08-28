/********************************************************************************************/
/* Author: Mohamed Gamal Rousdhy                                                             */
/* Version: V01                                                                              */
/* Date: 20/08/2023                                                                          */
/* Description: LCD driver configuration file                                               */
/********************************************************************************************/
#ifndef _LCD_INTERFACE_H
#define _LCD_INTERFACE_H

/* LCD MODES */
#define FOUR_BITS_MODE    0
#define EIGHT_BITS_MODE   1

/* LCD high data bits */
#define LCD_HIGH_BITS  0x0fu
#define LCD_LOW_BITS   0xf0u

/* LCD COMMANDS */
#define LCD_CLEAR                0x01U /* Clear display screen */
#define INC_CURSOR               0x06U /* Increment cursor (shift cursor to right) */
#define DISPLAY_ON_CURSOROFF     0xOCU /* Display ON, cursor OFF */
#define DIS_ON_CURSOR_BLINK      0x0FU /* Display ON, cursor blinking */
#define FORCE_FIRSTL             0x80U /* Force cursor to beginning of first line */
#define FORCE_SECONDL            0xC0U /* Force cursor to beginning of second line */
#define SHIFT_CURSORL            0X10U /* Shift cursor position to the left */
#define SHIFT_CURSORR            0X14U /* Shift cursor position to the right */
#define SHIFT_DIS_L              0x18U /* Shift display left */
#define SHIFT_DIS_R              0x1CU /* Shift display right */
#define TWOLINES_5X7_8BIT_MODE   0x38U /* 2 lines and 5×8 matrix 8 8 bits mode */
#define TWOLINES_5X7_4BIT_MODE   0x28U /* 2 lines and 5×8 matrix 8 8 bits mode */
#define ONEL_8BITS_MODE          0X30U /* 1 line 8 bits mode */
#define ONEL_4BITS_MODE          0X20U /* 1 line 4 bits mode */
#define INIT_4_BITS_MODE         0x02U /* Initialize 4 bits mode */

/* FUNCTION PROTOTYPES */
void LCD_Init(void);
void LCD_SendCommand(u8 Cpy_Command);
void LCD_DisplayCharacter(u8 Cpy_CharToSend);
void LCD_DisplayString(const u8 * str);

#endif

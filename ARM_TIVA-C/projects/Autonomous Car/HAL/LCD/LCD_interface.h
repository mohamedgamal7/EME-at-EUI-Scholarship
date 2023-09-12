/********************************************************************************************/
/* File: LCD_Interface.h                                                                    */
/* Authors: Mohamed Gamal, Ehab Roushdy, Mohamed abelmoteleb, and Aya Yasser                */
/* Version: V01                                                                             */
/* Date: 10/09/2023                                                                         */
/* Description: Header file for the LCD Interface module.                                   */
/********************************************************************************************/
#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

/* Command Definitions */
#define CLEAR_DISPLAY       0x01 /**< Command to clear the display. */
#define RETURN_HOME         0x02 /**< Command to return to the home position. */

/* Function Set Commands */
#define MODE_4_BIT          0x20 /**< 4-bit mode command. */
#define MODE_8_BIT          0x30 /**< 8-bit mode command. */
#define DISPLAY_1_LINE      0x20 /**< Single-line display command. */
#define DISPLAY_2_LINE      0x28 /**< Two-line display command. */
#define FONT_5X7            0x20 /**< 5x7 font command. */
#define FONT_5X10           0x24 /**< 5x10 font command. */

/* Entry Mode Set Commands */
#define CURSOR_AUTO_SHIFT_RIGHT     0x06 /**< Auto-increment cursor and shift right command. */
#define DISPLAY_AUTO_SHIFT          0x05 /**< Display shift with no cursor movement command. */

/* Display/Cursor/Blink On/Off Control Commands */
#define DISPLAY_ON          0x0C /**< Display on command. */
#define CURSOR_ON           0x0A /**< Cursor on command. */
#define BLINK_ON            0x09 /**< Blink on command. */

/* Display/Cursor Switch with No Data Entry Commands */
#define SHIFT_CURSOR_POSITION_LEFT  0x10 /**< Shift cursor position left command. */
#define SHIFT_CURSOR_POSITION_RIGHT 0x14 /**< Shift cursor position right command. */
#define SHIFT_DISPLAY_LEFT          0x18 /**< Shift display left command. */
#define SHIFT_DISPLAY_RIGHT         0x1C /**< Shift display right command. */

/* Row Definitions */
#define ROW1                0x00 /**< Row 1 constant for goTo function. */
#define ROW2                0x01 /**< Row 2 constant for goTo function. */

/* Column Definitions */
#define COL1                0x00 /**< Column 1 constant for goTo function. */
#define COL2                0x01 /**< Column 2 constant for goTo function. */
#define COL3                0x02 /**< Column 3 constant for goTo function. */
#define COL4                0x03 /**< Column 4 constant for goTo function. */
#define COL5                0x04 /**< Column 5 constant for goTo function. */
#define COL6                0x05 /**< Column 6 constant for goTo function. */
#define COL7                0x06 /**< Column 7 constant for goTo function. */
#define COL8                0x07 /**< Column 8 constant for goTo function. */
#define COL9                0x08 /**< Column 9 constant for goTo function. */
#define COL10               0x09 /**< Column 10 constant for goTo function. */
#define COL11               0x0A /**< Column 11 constant for goTo function. */
#define COL12               0x0B /**< Column 12 constant for goTo function. */
#define COL13               0x0C /**< Column 13 constant for goTo function. */
#define COL14               0x0D /**< Column 14 constant for goTo function. */
#define COL15               0x0E /**< Column 15 constant for goTo function. */
#define COL16               0x0F /**< Column 16 constant for goTo function. */

/**
 * @brief Initializes the LCD module with specified configuration.
 *
 * @details This function initializes the LCD module with the specified configuration.
 * It sets up the data port, data pins, RS (Register Select) port and pin, and EN (Enable) port and pin.
 * This function must be called before using any other LCD functions.
 *
 * @param None.
 *
 * @return None.
 */
void LcdInit(void);

/**
 * @brief Sends a command to the LCD module.
 *
 * @details This function sends a command to configure the LCD module.
 *
 * @param c: The command to be sent to the LCD module.
 *
 * @return None.
 */
void LcdSendCommand(char c);

/**
 * @brief Sends character data to be displayed on the LCD screen.
 *
 * @details This function sends character data to the LCD module to be displayed on the screen.
 *
 * @param c: The character data to be sent to the LCD module.
 *
 * @return None.
 */
void LcdSendData(char c);

/**
 * @brief Sends a sequence of characters (a string) to be displayed on the LCD screen.
 *
 * @details This function sends a sequence of characters (a string) to the LCD module to be displayed on the screen.
 *
 * @param str: Pointer to a char array (string) containing the data to be sent.
 *
 * @return None.
 */
void LcdSendString(char* str);

/**
 * @brief Moves the cursor to a specified row and column on the LCD screen.
 *
 * @details This function moves the cursor to the specified row and column on the LCD screen.
 *
 * @param row: The row to move the cursor to (ROW1 or ROW2).
 * @param col: The column to move the cursor to (COL1 to COL16).
 *
 * @return None.
 */
void LcdGoTo(unsigned char row, unsigned char col);

/**
 * @brief Saves a custom character pattern to the LCD module.
 *
 * @details This function saves a custom character pattern to the LCD module with a specified ID.
 * The custom character pattern is defined by the provided array of data.
 *
 * @param c: The array of custom character data (8 bytes).
 * @param ID: The ID (location) to store the custom character (0 to 7).
 *
 * @return None.
 */
void LcdSaveCustomChar(unsigned char c[8], unsigned char ID);

/**
 * @brief Sends an integer value to be displayed on the LCD screen.
 *
 * @details This function sends an integer value to the LCD module to be displayed on the screen.
 *
 * @param num: The integer value to be displayed.
 *
 * @return None.
 */
void LCDSendInt(unsigned int num);

#endif /*LCD_INTERFACE_H*/

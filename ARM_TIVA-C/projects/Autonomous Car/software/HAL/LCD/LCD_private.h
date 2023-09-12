/********************************************************************************************/
/* File: LCD_Driver_Private.h                                                               */
/* Authors: Mohamed Gamal, Ehab Roushdy, Mohamed abelmoteleb, and Aya Yasser                */
/* Version: V01                                                                             */
/* Date: 10/09/2023                                                                         */
/* Description: Private Header File for the LCD Driver Module.                              */
/********************************************************************************************/

#ifndef LCD_PRIVATE_H
#define LCD_PRIVATE_H

/* Static Helper Function Declarations */


/**
 * @brief Sends an enable pulse to the LCD module.
 *
 * @details This static function sends an enable (EN) pulse to the LCD module
 * to latch the data/command being sent.
 *
 * @param None.
 *
 * @return None.
 */
static void sendEnablePulse(void);

/**
 * @brief Sets the data mode for the LCD module (4-bit or 8-bit mode).
 *
 * @details This static function sets the data mode for the LCD module based
 * on the configuration (4-bit or 8-bit) defined in the configuration header.
 *
 * @param None.
 *
 * @return None.
 */
static void lcdSetMode(void);

/* Static Variables Declarations */

/**
 * @brief Array to store the data ports used for LCD communication.
 *
 * @details This array stores the data ports used for communication with the LCD module.
 * The actual port values are configured in the configuration header.
 */
static unsigned char dataPorts[4];

/**
 * @brief Array to store the data pins used for LCD communication.
 *
 * @details This array stores the data pins used for communication with the LCD module.
 * The actual pin values are configured in the configuration header.
 */
static unsigned char dataPins[4];

#endif /*LCD_DRIVER_PRIVATE_H*/


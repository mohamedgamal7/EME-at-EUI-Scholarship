/********************************************************************************************/
/*Author: Mohamed Gamal Rousdhy                                                             */
/*Version: V01                                                                              */
/*Date: 20/08/2023                                                                          */
/*Description: LCD driver configuration file                                               */
/********************************************************************************************/
#ifndef _LCD_CONFIG_H
#define _LCD_CONFIG_H




// LCD MODE SELECTION
// 4bit mode or 8 bit mode

#define LCD_MODE  FOUR_BITS_MODE



// LCD_PORTS
// select suitable data and control ports

#define LCD_DATAPORT PORTB_ID
#define LCD_CTRLPORT PORTA_ID



// LCD PINS

#define RS P3
#define EN P2

#endif

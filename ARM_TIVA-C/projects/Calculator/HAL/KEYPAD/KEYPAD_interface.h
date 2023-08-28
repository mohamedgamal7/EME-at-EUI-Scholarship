/********************************************************************************************/
/*Author: Mohamed Gamal Rousdhy                                                             */
/*Version: V01                                                                              */
/*Date: 19/08/2023                                                                          */
/*Description: KEYPAD driver configuration file                                               */
/********************************************************************************************/
#ifndef _KEYPAD_INTERFACE_H
#define _KEYPAD_INTERFACE_H

#define ROWS 4
#define COLS 4

#define NO_KEY 0

void KEYPAD_Init();
u8 KEYPAD_GetKeyPressed();


#endif

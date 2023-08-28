/********************************************************************************************/
/*Author: Mohamed Gamal Rousdhy                                                             */
/*Version: V01                                                                              */
/*Date: 19/08/2023                                                                          */
/*Description: KEYPAD driver configuration file                                               */
/********************************************************************************************/
#ifndef _KEYPAD_INTERFACE_H
#define _KEYPAD_INTERFACE_H

#define ROWS 4U
#define COLS 4U


#define NO_KEY 0U

void KEYPAD_Init(void);
u8 KEYPAD_GetKeyPressed(void);


#endif

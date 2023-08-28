/********************************************************************************************/
/*Author: Mohamed Gamal Rousdhy                                                             */
/*Version: V01                                                                              */
/*Date: 19/08/2023                                                                          */
/*Description: KEYPAD driver configuration file                                             */
/********************************************************************************************/
#ifndef _KEYPAD_CONFIG_H
#define _KEYPAD_CONFIG_H

#define KEYPAD_COLSPORT PORTE_ID
#define KEYPAD_ROWSPORT PORTD_ID

#define KEYPAD_COL_BITS  P4|P3|P2|P1
#define KEYPAD_ROW_BITS  P3|P2|P1|P0

#define ROWS_START 0
#define COLS_START 1

#endif

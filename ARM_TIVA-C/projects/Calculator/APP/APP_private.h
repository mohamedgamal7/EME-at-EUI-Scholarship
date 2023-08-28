
/*Author:      Mohamed Gamal ROushdy                                                                      
  Version:     v01                                                                       
  Date:        22/08/2023                                                                             
  Description: APP driver private file                                       
*/
#ifndef _APP_PRIVATE_H
#define _APP_PRIVATE_H

/* extern variables */
extern u8 INT_FLAG_PORTE; /* interuupt flag */

/* global variables */
static s8  ParsedInputString[17];
static s64 ParsedNumbers[8];
static s8  ParsedOperands[8];

/* Helper functions */

static void _delay_ms(u32 msecs);
static void ParseInputString(void);
static f64 CalculateResultWithPriority(void);
static void ResetVariables(void);
static void TrimFloat(s8* str);
static void Reverse(s8* str, s32 len);
static s32 IntToStr(s64 x, s8 str[], s32 d);
static void Ftoa(f64* n, s8* res, s32 afterpoint);


#endif


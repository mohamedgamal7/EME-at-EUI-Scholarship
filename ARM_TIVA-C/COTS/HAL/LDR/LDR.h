/********************************************************************************************/
/* Authors: Mohamed Gamal, Ehab Roushdy, Mohamed abelmoteleb and Aya Yasser                 */
/* Version: V01                                                                             */
/* Date: 10/09/2023                                                                         */
/* Description: LDR Driver header                                                          */
/********************************************************************************************/
#ifndef LDR_H__
#define LDR_H__

#include <stdint.h>
#include "MCAL/ADC/ADC.h"

/*thresold of difference*/
#define MIN_DIFFERENCE 500

/*directions enum*/
typedef enum{
    STAY = 0,
    RIGHT,
    LEFT
}dirType;

/*Functions prototypes*/

/********************************************************************************************/
/* Function: LDR_Init                                                                       */
/* Description: Initializes the LDR (Light Dependent Resistor) system for reading light     */
/*              levels. This function configures and prepares the LDR sensors for readings. */
/*              It should be called once before using any other LDR functions.              */
/********************************************************************************************/
void LDR_Init(void);

/********************************************************************************************/
/* Function: LDR_Comp                                                                        */
/* Description: Compares LDR (Light Dependent Resistor) readings and determines the          */
/*              direction of light change. This function reads the LDR sensors and calculates*/
/*              the difference between the readings. Based on the difference, it determines  */
/*              the direction of light change (e.g., left, right, or no change).             */
/* Arguments:                                                                                */
/*   - difference: A pointer to an integer where the calculated difference in LDR readings   */
/*                 will be stored.                                                           */
/* Return Value:                                                                             */
/*   - dirType: An enumeration indicating the direction of light change (LEFT, RIGHT, or     */
/*              STAY).                                                                       */
/********************************************************************************************/
dirType LDR_Comp(int32_t *difference);

#endif

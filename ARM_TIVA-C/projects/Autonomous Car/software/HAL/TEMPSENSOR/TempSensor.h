/********************************************************************************************/
/* Authors: Mohamed Gamal, Ehab Roushdy, Mohamed abelmoteleb and Aya Yasser                 */
/* Version: V01                                                                             */
/* Date: 10/09/2023                                                                         */
/* Description: Temperature Sensor Header file                                              */
/********************************************************************************************/
#ifndef TEMPSENSOR_H__
#define TEMPSENSOR_H__

#include <stdbool.h>
#include <stdint.h>
#include "MCAL/ADC/ADC.h"



/*Function protutypes*/

/********************************************************************************************/
/* Function: TempInit                                                                     */
/* Description: Initializes the temperature sensor system. This function sets up the         */
/*              necessary configurations and prepares the temperature sensor for readings.    */
/*              It should be called once before using any other temperature sensor functions.*/
/********************************************************************************************/
void TempInit(void);

/********************************************************************************************/
/* Function: TempRead                                                                     */
/* Description: Reads the temperature from the sensor. This function retrieves the current   */
/*              temperature reading from the temperature sensor and returns it as an unsigned */
/*              integer value.                                                              */
/* Return Value:                                                                          */
/*   - unsigned int: The temperature reading from the sensor as an unsigned integer value.  */
/********************************************************************************************/
uint32_t TempRead(void);



#endif

/********************************************************************************************/
/* Authors: Mohamed Gamal, Ehab Roushdy, Mohamed abelmoteleb and Aya Yasser                 */
/* Version: V01                                                                             */
/* Date: 10/09/2023                                                                         */
/* Description: CAR application Driver Header                                               */
/********************************************************************************************/
#ifndef _APP_H
#define _APP_H

/*Library includes*/
#include "LIB/Delay.h"
/*MCAL includes*/
#include "MCAL/DIO/DIO.h"
#include "MCAL/SYSTICK/Systick.h"
/*HAL includes*/
#include "HAL/ULTRASONIC/ULTRASONIC_interface.h"
#include "HAL/MOTOR/Motor.h"
#include "HAL/LDR/LDR.h"
#include "HAL/LCD/LCD_interface.h"
#include "HAL/TEMPSENSOR/TempSensor.h"

/* Chosen Periodicities of Tasks*/
#define LDR_PERIOD              100
#define LCD_PERIOD              200
#define ULTRASONIC_PERIOD       40

/*Chosen Motor speed percentage*/
#define Speed_percent 100

/*Distance thresolds*/
#define MAX_DISTANCE 10
#define WRONG_MEASUREMENT -1
#define BACK_DISTANCE 20

/*Engine powers*/
#define ENGINE_POWER_FORWARD 65
#define ENGINE_POWER_LEFT    100
#define ENGINE_POWER_RIGHT   100

typedef enum
{
    free_running,blocked_turning,blocked_reverse
}car_state;



/* Tasks Prototypes */

/************************************************************************************
* Task Name: ldr_swing_car
* Sync/Async: sync
* Reentrancy: Non reentrant
* Parameters (in): void
* Parameters (out): void
* Description: Moves the car either forward, Right or left based on LDR readings
************************************************************************************/
void ldr_swing_car(void);
/************************************************************************************
* Task Name: lcd_display
* Sync/Async: sync
* Reentrancy: Non reentrant
* Parameters (in): void
* Parameters (out): void
* Description: Displays various data like Temp, LDR readings and Time of operation
************************************************************************************/
void lcd_display(void);
/************************************************************************************
* Task Name: avoid_obstacles
* Sync/Async: sync
* Reentrancy: Non reentrant
* Parameters (in): void
* Parameters (out): void
* Description: Avoids obstacles in the Cars way based on a distance thresold
************************************************************************************/
void avoid_obstacles(void);

/* Functions Prototypes */
void lcd_display_const_string(void);

#endif

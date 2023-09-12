/********************************************************************************************/
/*Authors: Mohamed Gamal, Ehab Roushdy, Mohamed abelmoteleb and Aya Yasser                  */
/*Version: V01                                                                              */
/*Date: 10/09/2023                                                                          */
/*Description: Main Autonoumous car program                                                 */
/********************************************************************************************/

/*Library of general functions includes*/
#include "LIB/Delay.h"
/*MCAL includes*/
#include "MCAL/DIO/DIO.h"
/*HAL includes*/
#include "HAL/ULTRASONIC/ULTRASONIC_interface.h"
#include "HAL/MOTOR/Motor.h"
#include "HAL/LDR/LDR.h"
#include "HAL/LCD/LCD_interface.h"
#include "HAL/TEMPSENSOR/TempSensor.h"
/*SERIVCE includes*/
#include "SERVICE/Scheduler.h"
/*APP includes*/
#include "APP/APP.h"


int main(){

    /*Hardware initialization*/
    PORTS_Operation();
    Ultrasonic_Init();
    MotorInit();
    LcdInit();
    LDR_Init();
    TempInit();
    /*Display strings of Temp, LDR and TIME*/
    lcd_display_const_string();
    /*Tasks Creation*/
    create_task(ldr_swing_car, LDR_PERIOD);
    create_task(lcd_display, LCD_PERIOD);
    create_task(avoid_obstacles, ULTRASONIC_PERIOD  );
    /*Schedualing*/
    tasks_scheduler();
}


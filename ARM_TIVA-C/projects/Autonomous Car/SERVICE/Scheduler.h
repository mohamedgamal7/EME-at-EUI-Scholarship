/********************************************************************************************/
/*Authors: Mohamed Gamal, Ehab Roushdy, Mohamed abelmoteleb and Aya Yasser                  */
/*Version: V01                                                                              */
/*Date: 19/08/2023                                                                          */
/*Description: Schedular Driver header                                                      */
/********************************************************************************************/

#ifndef SCHEDULER_H__
#define SCHEDULER_H__

#include "Scheduler_Types.h"
#include "MCAL/SYSTICK/Systick.h"
#include "HAL/MOTOR/Motor.h"
#include "HAL/LCD/LCD_interface.h"
#include "MCAL/DIO/DIO.h"
#include "LIB/types.h"

/*MAX number of tasks*/
#define MAX_TASKS 10

/**
 * @brief Scheduler function that manages the execution of tasks.
 */
void tasks_scheduler(void);

/**
 * @brief Creates a new task with a specified period.
 *
 * @param ptr A pointer to the task function to be executed.
 * @param period The period (in milliseconds) at which the task should run.
 */
void create_task(void (*ptr)(), uint32_t period);

/**
 * @brief Turns the scheduler ON, allowing tasks to be executed.
 */
void Scheduler_ON(void);

/**
 * @brief Turns the scheduler OFF, pausing task execution.
 */
void Scheduler_OFF(void);

#endif

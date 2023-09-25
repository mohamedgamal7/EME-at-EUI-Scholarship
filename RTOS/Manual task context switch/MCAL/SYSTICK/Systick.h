/********************************************************************************************/
/* Authors: Mohamed Gamal, Ehab Roushdy, Mohamed abelmoteleb, and Aya Yasser                */
/* Version: V01                                                                             */
/* Date: 10/09/2023                                                                         */
/* Description: Systick timer driver header                                                 */
/********************************************************************************************/


#ifndef SYSTICK_H__
#define SYSTICK_H__

/*systick rate of interuppt*/
#define SYSTIC_INT_PERIOD_MS    100

/*systick registers*/
#define NVIC_ST_CTRL_R          (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R        (*((volatile unsigned long *)0xE000E014))
#define NVIC_ST_CURRENT_R       (*((volatile unsigned long *)0xE000E018))

/********************************************************************************************/
/* Function: Systick_Init                                                                   */
/* Description: Initializes the SysTick timer.                                              */
/********************************************************************************************/
void Systick_Init(void);

/********************************************************************************************/
/* Function: Systick_Set_ISR                                                                */
/* Description: Sets the SysTick timer interrupt service routine (ISR).                     */
/* Parameters:                                                                              */
/*   - funcPtr: A pointer to the function that will serve as the ISR for SysTick interrupts.*/
/********************************************************************************************/
void Systick_Set_ISR(void (*funcPtr)());

/********************************************************************************************/
/* Function: Systick_off                                                                    */
/* Description: Turns off the SysTick timer.                                                */
/********************************************************************************************/
void Systick_off(void);


#endif

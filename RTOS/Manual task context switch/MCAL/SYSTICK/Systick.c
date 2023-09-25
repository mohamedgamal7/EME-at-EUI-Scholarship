/********************************************************************************************/
/* Authors: Mohamed Gamal, Ehab Roushdy, Mohamed abelmoteleb, and Aya Yasser                */
/* Version: V01                                                                             */
/* Date: 10/09/2023                                                                         */
/* Description: Systick timer driver program                                                */
/********************************************************************************************/

#include "MCAL/SYSTICK/Systick.h"

void(*systick)(void);


/************************************************************************************
* Service Name: Systick_Init
* Sync/Async: -
* Reentrancy: -
* Parameters (in): -
* Parameters (inout): -
* Parameters (out): -
* Return value: -
* Description: -
************************************************************************************/
void Systick_Init(void){
    NVIC_ST_CTRL_R |= 0x07;
    NVIC_ST_RELOAD_R = SYSTIC_INT_PERIOD_MS * 16000 - 1;
}


/************************************************************************************
* Service Name: Systick_Set_ISR
* Sync/Async: -
* Reentrancy: -
* Parameters (in): funcPtr
* Parameters (inout): -
* Parameters (out): -
* Return value: -
* Description: -
************************************************************************************/
void Systick_Set_ISR(void (*funcPtr)()){
    systick = funcPtr;
}

/************************************************************************************
* Service Name: Systick_Handler
* Sync/Async: -
* Reentrancy: -
* Parameters (in): -
* Parameters (inout): -
* Parameters (out): -
* Return value: -
* Description: -
************************************************************************************/
//void Systick_Handler(void){
//    (NVIC_ST_CTRL_R >> 16);
//    if(systick != 0x00){
//        (void)systick();
//    }
//}

/************************************************************************************
* Service Name: Systick_off
* Sync/Async: -
* Reentrancy: -
* Parameters (in): -
* Parameters (inout): -
* Parameters (out): -
* Return value: -
* Description: -
************************************************************************************/
void Systick_off(void){
    NVIC_ST_CTRL_R &= ~(1 << 0);
}

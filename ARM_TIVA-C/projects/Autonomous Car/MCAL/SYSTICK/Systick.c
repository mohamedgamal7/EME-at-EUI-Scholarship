/******************************************************************************
*
* [FILE NAME]: <Systick.c>
*
* [AUTHOR]: Teleb, Aya, Ehab, Jemy
*
* [DATE CREATED]: <09/09/2023>
*
* [DESCRIPTION]:
*
*******************************************************************************/

#include "../MCAL/Systick.h"

void(*systick)(void);


/************************************************************************************
* Service Name: Systick_Init1ms
* Sync/Async: -
* Reentrancy: -
* Parameters (in): -
* Parameters (inout): -
* Parameters (out): -
* Return value: -
* Description: -
************************************************************************************/
void Systick_Init1ms(void){
    NVIC_ST_CTRL_R |= 0x07;
    NVIC_ST_RELOAD_R = 16000-1;
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
void Systick_Handler(void){
    if(systick != 0x00){
        (void)systick();
    }
}


void Systick_off(void){
    NVIC_ST_CTRL_R |= 0;
}
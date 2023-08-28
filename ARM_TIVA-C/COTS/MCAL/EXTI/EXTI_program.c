/*Author:      Mohamed Gamal Roushdy                                                                      
  Version:     V01                                                                       
  Date:        22/08/2023
  Description: EXTI driver program file    
*/
#include "./LIB/BIT_MATH.h"
#include "./LIB/STD_TYPES.h"

#include "./MCAL/EXTI/EXTI_interface.h"
#include "./MCAL/EXTI/EXTI_private.h"
#include "./MCAL/EXTI/EXTI_config.h"


void(*EXTI_CALLBACK)(void);

void EXTI_Init(u8 CpyPort_ID,u8 CpyPinMask, u8 CPyPinValue, u8 CpyIntNum)
{
    if(CpyPort_ID<6)
    {
        // edge or level detection
        #if(DETECTION_SEL==EDGE_DETECTION)
        {
          *((volatile unsigned long *)GPIO_PORT_ADDRESS(IS_OFFSET)) &=~(CpyPinMask&CPyPinValue);
        }
        #elif(DETECTION_SEL==LEVEL_DETECTION)
        {
          *((volatile unsigned long *)GPIO_PORT_ADDRESS(IS_OFFSET)) |= (CpyPinMask&CPyPinValue);
        }
        #endif

        // single edge or both edges
        #if(EDGE_OR_EDGES==SINGLE_EDGE)
        {
         *((volatile unsigned long *)GPIO_PORT_ADDRESS(IBE_OFFSET)) &=~(CpyPinMask&CPyPinValue);
        }
        #elif(EDGE_OR_EDGES==BOTH_EDGES)
        {
         *((volatile unsigned long *)GPIO_PORT_ADDRESS(IBE_OFFSET)) |= (CpyPinMask&CPyPinValue);
        }
        #elif(EDGE_OR_EDGES==NO_EDGES)
        {
        }
        #endif

        // rising edge or falling edge
        #if(EDGE_SEL==FALLING_EDGE)
        {
          *((volatile unsigned long *)GPIO_PORT_ADDRESS(IEV_OFFSET)) &=~(CpyPinMask&CPyPinValue);
        }
        #elif(EDGE_SEL==RISING_EDGE)
        {
          *((volatile unsigned long *)GPIO_PORT_ADDRESS(IEV_OFFSET)) |= (CpyPinMask&CPyPinValue);
        }
        #endif

        // unmask the interuppt
        *((volatile unsigned long *)GPIO_PORT_ADDRESS(IM_OFFSET)) |= (CpyPinMask);

        // enable interuppt
        NVIC_EN0_R|=(1<<CpyIntNum);

        // enable processor interuppt
        __asm(" CPSIE i ");
    }
}

u8 EXTICheckIntPin(u8 CpyPort_ID,u8 CPyPinValue)
    {
        u8 Local_Temp = (GET_BIT(*((volatile unsigned long *)GPIO_PORT_ADDRESS(MIS_OFFSET)),CPyPinValue));
      return Local_Temp;
    }

void EXTI_Set_Callback(void(*ptr)(void))
    {
        EXTI_CALLBACK = ptr;
    }


//handle interuppt on Port E
void GPIOPortE_handler(void)
{
        EXTI_CALLBACK();
        GPIO_PORTE_ICR_R = 0XFF;

}
// handle interrupts on PORTF
void GPIOPortF_handler(void)
{

        EXTI_CALLBACK();
        GPIO_PORTF_ICR_R = 0XFF;
}

/********************************************************************************************/
/* Author: Mohamed Gamal Rousdhy                                                            */
/* Version: V01                                                                             */
/* Date:    19/08/2023                                                                      */
/* Description: GPIO driver program file                                                    */
/********************************************************************************************/
#include "./LIB/BIT_MATH.h"
#include "./LIB/STD_TYPES.h"

#include "./MCAL/GPIO/GPIO_interface.h"
#include "./MCAL/GPIO/GPIO_private.h"
#include "./MCAL/GPIO/GPIO_config.h"

void GPIO_Init_Port(u8 CpyPort_ID, u8 Cpy_inputMaskPins, u8 Cpy_outputMaskPins)
{
    if (CpyPort_ID < 6u)
    {
        SET_BIT(SYSCTL_RCGCGPIO_R, CpyPort_ID); /* Enable the clock on the selected port */
        while (GET_BIT(SYSCTL_PRGPIO_R, CpyPort_ID) == 0); /* Wait for the clock to be enabled */

        /* Unlock the peripheral */
        *((volatile unsigned long *)GPIO_PORT_ADDRESS(GPIOLOCK_OFFSET)) = 0x4c4f434b;
        /* When Bits are set in GPIOCR there effects are seen */
        *((volatile unsigned long *)GPIO_PORT_ADDRESS(GPIOCR_OFFSET)) = (Cpy_inputMaskPins | Cpy_outputMaskPins);
        /* Set direction of Input and output pins */
        *((volatile unsigned long *)GPIO_PORT_ADDRESS(GPIODIR_OFFSET)) = Cpy_outputMaskPins & ~(Cpy_inputMaskPins);
        /* The bits set are initialized as pull up */
        *((volatile unsigned long *)GPIO_PORT_ADDRESS(GPIOPUR_OFFSET)) = (Cpy_inputMaskPins | Cpy_outputMaskPins);
        /* Setting Enables data for these bits */
        *((volatile unsigned long *)GPIO_PORT_ADDRESS(GPIODEN_OFFSET)) = (Cpy_inputMaskPins | Cpy_outputMaskPins);
    }
}

void GPIO_Write(u8 CpyPort_ID, u8 CpyPinMask, u8 CpyValue)
{
    /* Use bit banding to write directly the value on the PORT */
    ((volatile unsigned long *)GPIO_PORT_ADDRESS(NO_OFFSET))[CpyPinMask] = CpyValue;
}

u8 GPIO_Read(u8 CpyPort_ID, u8 CpyPinMask)
{
    /* Use bit banding to read the port */
    return ((volatile unsigned long *)GPIO_PORT_ADDRESS(NO_OFFSET))[CpyPinMask];
}

/********************************************************************************************/
/*Author: Mohamed Gamal Rousdhy                                                             */
/*Version: V01																			    */
/*Date:	19/08/2023																			*/
/*Description: GPIO driver interface file 												*/
/********************************************************************************************/


#ifndef _GPIO_INTERFACE_H
#define _GPIO_INTERFACE_H

/* Pin masks */

#define P0          0x01U
#define P1          0x02U
#define P2          0x04U
#define P3          0x08U
#define P4          0x10U
#define P5          0x20U
#define P6          0x40U
#define P7          0x80U
#define NO_PINS     0x00U
#define ALL_PINS    0xFFU
#define HIGH_NIBBLE 0XF0U
#define LOW_NIBBLE  0X0FU


/*states*/
#define HIGH      0xFFU
#define LOW       0x00U



/*Ports MACROS*/
#define PORTA_ID  0U
#define PORTB_ID  1U
#define PORTC_ID  2U
#define PORTD_ID  3U
#define PORTE_ID  4U
#define PORTF_ID  5U

/**
 * Function: GPIO_Init_Port
 * Description: Inititalize GPIO port using input and output mask
 * by oring all the pins you want as input and all the pins you want as output
 * Parameters: CpyPort_ID, Cpy_inputMaskPins, Cpy_outputMaskPins
 * Return: void  
 **/
void GPIO_Init_Port(u8 CpyPort_ID, u8 Cpy_inputMaskPins, u8 Cpy_outputMaskPins);
/**
 * Function: GPIO_Write
 * Description: A general function to write a value on Pins based on
 *				a mask .
 * Parameters: CpyPort_ID, CpyPinMask, CpyValue
 * Return: void       
 **/
void GPIO_Write(u8 CpyPort_ID, u8 CpyPinMask, u8 CpyValue);
/**
 * Function: GPIO_Read 
 * Description: Read the value written on the masked pins  
 * Parameters: CpyPort_ID, CpyPinMask
 * Return: void
 **/
u8 GPIO_Read(u8 CpyPort_ID, u8 CpyPinMask);



#endif

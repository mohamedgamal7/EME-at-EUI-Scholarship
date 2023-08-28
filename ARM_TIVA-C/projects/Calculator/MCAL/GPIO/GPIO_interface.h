/********************************************************************************************/
/*Author: Mohamed Gamal Rousdhy                                                             */
/*Version: V01																			    */
/*Date:	19/08/2023																			*/
/*Description: GPIO driver interface file 												*/
/********************************************************************************************/


#ifndef _GPIO_INTERFACE_H
#define _GPIO_INTERFACE_H

// Pin masks

#define P0          0x01
#define P1          0x02
#define P2          0x04
#define P3          0x08
#define P4          0x10
#define P5          0x20
#define P6          0x40
#define P7          0x80
#define NO_PINS     0x00
#define ALL_PINS    0xFF
#define HIGH_NIBBLE 0XF0
#define LOW_NIBBLE  0X0F


// states
#define HIGH      0xFF
#define LOW       0x00



// Ports MACROS
#define PORTA_ID  0
#define PORTB_ID  1
#define PORTC_ID  2
#define PORTD_ID  3
#define PORTE_ID  4
#define PORTF_ID  5

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

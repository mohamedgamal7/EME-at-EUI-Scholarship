/*Author:      Mohamed Gamal Roushdy                                                                      
  Version:     V01                                                                       
  Date:        23/08/2023                                                                             
  Description: EXTI driver interface file      
*/

#ifndef _EXTI_INTERFACE_H
#define _EXTI_INTERFACE_H
/* Pin masks */

#define EXTI_P0          0x01
#define EXTI_P1          0x02
#define EXTI_P2          0x04
#define EXTI_P3          0x08
#define EXTI_P4          0x10
#define EXTI_P5          0x20
#define EXTI_P6          0x40
#define EXTI_P7          0x80
#define EXTI_NO_PINS     0x00
#define EXTI_ALL_PINS    0xFF
#define EXTI_HIGH_NIBBLE 0XF0
#define EXTI_LOW_NIBBLE  0X0F





/* Ports MACROS */
#define EXTI_PORTA_ID  0u
#define EXTI_PORTF_ID  5



/* edge or level detection */
#define EDGE_DETECTION  0
#define LEVEL_DETECTION 1

/* single edge or both edges or no edges */
#define SINGLE_EDGE   0
#define BOTH_EDGES    1
#define NO_EDGES      2

/* RISING OR FALLING EDGE */
#define FALLING_EDGE 0
#define RISING_EDGE  1

/* INTEURRPT MASK SENT TO NVIC */
#define MASKED     0
#define UNMAKSED   1

/* Interuppt Number */
#define  IN_PORTA    0u
#define  IN_PORTB    1u
#define  IN_PORTC    2u
#define  IN_PORTD    3u
#define  IN_PORTE    4u
#define  IN_PORTF    30u









/* FUNCTION PROTOTYPES */
void EXTI_Init(u8 CpyPort_ID,u8 CpyPinMask,u8 CPyPinValue);
void GPIOPortE_handler(void);


#endif

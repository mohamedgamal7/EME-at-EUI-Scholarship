/*Author:      Mohamed Gamal Roushdy                                                                      
  Version:     V01                                                                       
  Date:        23/08/2023                                                                             
  Description: EXTI driver interface file      
*/


#ifndef _EXTI_INTERFACE_H
#define _EXTI_INTERFACE_H

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
#define UNMASKED   1

/* Interuppt Number */
#define  IN_PORTA    0U
#define  IN_PORTB    1U
#define  IN_PORTC    2U
#define  IN_PORTD    3U
#define  IN_PORTE    4U
#define  IN_PORTF    30U

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
#define EXTI_HIGH_NIBBLE 0xF0
#define EXTI_LOW_NIBBLE  0x0F

/* PINS positions */
#define P0_POS 0u
#define P1_POS 1u
#define P2_POS 2u
#define P3_POS 3u
#define P4_POS 4u
#define P5_POS 5u
#define P6_POS 6u
#define P7_POS 7u

/* Ports MACROS */
#define EXTI_PORTA_ID  0
#define EXTI_PORTF_ID  5

/*FUNCTION PROTOTYPES*/
void EXTI_Init(u8 CpyPort_ID,u8 CpyPinMask,u8 CPyPinValue, u8 CpyIntNum);
u8 EXTICheckIntPin(u8 CpyPort_ID, u8 CPyPinValue);
void EXTI_Set_Callback(void(*ptr)(void));

#endif

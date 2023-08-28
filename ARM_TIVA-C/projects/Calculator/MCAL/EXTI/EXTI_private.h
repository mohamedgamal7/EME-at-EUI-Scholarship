
/*Author:      Mohamed Gamal Roushdy                                                                      
  Version:     V01                                                                       
  Date:        23/08/2023                                                                             
  Description: EXTI driver private file                                       
*/
#ifndef _EXTI_PRIVATE_H
#define _EXTI_PRIVATE_H

// Register definitions
#define PORTS_BASE_ADDRESS  0x40004000
#define PORT_OFFSET(CpyPort_ID)  (((CpyPort_ID%4)<<12) + (CpyPort_ID/4)*(2<<16))
#define GPIO_PORT_ADDRESS(REG_OFFSET)   (PORTS_BASE_ADDRESS +PORT_OFFSET(CpyPort_ID) + REG_OFFSET)

#define IS_OFFSET       0x404
#define IBE_OFFSET      0x408
#define IEV_OFFSET      0x40C
#define IM_OFFSET       0x410
#define MIS_OFFSET      0x418
#define ICR_OFFSET      0x41C

// Register definitions

// NVIC Enable registers according to order of interuppts
#define NVIC_EN0_R              (*((volatile unsigned long *)0xE000E100))
#define NVIC_EN1_R              (*((volatile unsigned long *)0xE000E104))
#define NVIC_EN2_R              (*((volatile unsigned long *)0xE000E108))
#define NVIC_EN3_R              (*((volatile unsigned long *)0xE000E10C))

// Interupt clear register
#define GPIO_PORTE_ICR_R        (*((volatile unsigned long *)0x4002441C))

#endif


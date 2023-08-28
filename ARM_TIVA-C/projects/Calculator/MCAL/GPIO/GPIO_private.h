/********************************************************************************************/
/*Author: Mohamed Gamal Rousdhy                                                             */
/*Version: V01																			    */
/*Date:	19/08/2023																			*/
/*Description: GPIO driver prvate file 												*/
/********************************************************************************************/
#ifndef _GPIO_PRIVATE_H
#define _GPIO_PRIVATE_H


#define PORTS_BASE_ADDRESS 	0x40004000
#define PORT_OFFSET(CpyPort_ID)  ((((CpyPort_ID)%4)<<12) + ((CpyPort_ID)/4)*(2<<16))
#define GPIO_PORT_ADDRESS(REG_OFFSET)  	(PORTS_BASE_ADDRESS +PORT_OFFSET(CpyPort_ID) + REG_OFFSET)

#define GPIOLOCK_OFFSET 	0x520
#define GPIOCR_OFFSET  		0x524
#define GPIODIR_OFFSET 		0x400
#define GPIOPUR_OFFSET 		0x510
#define GPIODEN_OFFSET 		0x51c
#define GPIODATA_OFFSET		0x3fc
#define NO_OFFSET           0x000



/* Clock gating register */
#define SYSCTL_RCGCGPIO_R       (*((volatile unsigned long *)0x400FE608))
/*  General-Purpose Input/Output Peripheral Ready register */
#define SYSCTL_PRGPIO_R         (*((volatile unsigned long *)0x400FEA08))


#endif


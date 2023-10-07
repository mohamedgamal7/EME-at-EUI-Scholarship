#include "Port.h"

void Port_Init()
{
    /*Enable clock for port F*/
    SYSCTL_RCGCGPIO_R|=(1<<5);
    /*Wait until the peripheral is enabled */
    while((SYSCTL_PRGPIO_R & 0x00000020)==0);
    /*Unlock the peripheral*/
    GPIO_PORTF_LOCK_R = 0x4c4f434b ;
    /* when Bits are set in GPIOCR there effects are seen*/
    GPIO_PORTF_CR_R|= 0xFF;
    /*Set direction of Input and output pins*/
    GPIO_PORTF_DIR_R |= 0x0E;
    /*The bits set are intiallized as pull up*/
    GPIO_PORTF_PUR_R =0x11;
   /*Setting Enables data for these bits*/
    GPIO_PORTF_DEN_R =0x1F;

}

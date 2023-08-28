/*simple gpio*/

/**
 * main.c
 */
#include "types.h"
#include "bitmath.h"
#include "tm4c123gh6pm.h"


int main(void)
{
    // Initializations

    SYSCTL_RCGCGPIO_R |= 0x20 ;
    while((SYSCTL_PRGPIO_R & 0x00000020)==0);
    GPIO_PORTF_LOCK_R = 0x4C4F434B;
    GPIO_PORTF_CR_R = 0x1F;
    GPIO_PORTF_DIR_R = 0x0E;
    GPIO_PORTF_PUR_R =0x11;
    GPIO_PORTF_DEN_R =0x1F;
    while(1)
    {
       if(!(GPIO_PORTF_DATA_R& 0x01) || !(GPIO_PORTF_DATA_R& 0x10))
        {
           GPIO_PORTF_DATA_R |= 0x2;
        }
       else
        {
           GPIO_PORTF_DATA_R &= 0x00;
         }



    }

}

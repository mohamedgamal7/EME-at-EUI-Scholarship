

/**
 * main.c
 */
// switch control using simple state machine 

#include "tm4c123gh6pm.h"

#define LED_RED (1<<1)
#define LED_BLUE (1<<2)
#define LED_GREEN (1<<3)

#define SWITCH_1 (1<<0)
#define SWITCH_2 (1<<4)

#define BASE_ADDRESS_PORTF ((volatile unsigned long *)0x40025000)

#define RED_STATE      0
#define BLUE_STATE     1 
#define GREEN_STATE    2 

#define ROTATE_LEFT(REG,BIT,SIZE) REG=(REG>>BIT)|(REG<<SIZE-BIT)

volatile signed char state = 0 ;

void GPIOPortF_handler(void)
{


	if((GPIO_PORTF_MIS_R & 0x10) == 0x10) //switch 2
	{
        GPIO_PORTF_ICR_R|=(1<<4); //clear interrupt flag


		state++;
		if(state==3)
		{state = RED_STATE;}
	}
	else if (GPIO_PORTF_MIS_R & 0x01) // switch 1
	{
	    GPIO_PORTF_ICR_R|=(1<<0); //clear interrupt flag
		state--;
		if(state==-1)
		{state = GREEN_STATE;}
		
	}
			
	for(int i = 0 ; i< 100 ; i++);

}



int main(void)
{
    // Initializations for GPIO

    SYSCTL_RCGCGPIO_R |= 0x20 ;
    while((SYSCTL_PRGPIO_R & 0x00000020)==0);
    GPIO_PORTF_LOCK_R = 0x4C4F434B;
    GPIO_PORTF_CR_R = 0x1F;
    GPIO_PORTF_DIR_R = 0x0E;
    GPIO_PORTF_PUR_R =0x11;
    GPIO_PORTF_DEN_R =0x1F;
	
// interrupt initialzation

// set as edge detection
GPIO_PORTF_IS_R &= ~(1<<0); //switch 0 and 4
GPIO_PORTF_IS_R &=~(1<<4);
// set as single edge 
GPIO_PORTF_IBE_R &= ~(1<<0) ;
GPIO_PORTF_IBE_R &=~(1<<4);
// set as falling edge 
GPIO_PORTF_IEV_R&= ~(1<<0);
GPIO_PORTF_IEV_R&= ~(1<<4);
// allow sending the input to the controller
GPIO_PORTF_IM_R|=(1<<0);
GPIO_PORTF_IM_R |=(1<<4);
// enable interrupt
NVIC_EN0_R|=(1<<30);
// enable processor Interrupt
__asm(" CPSIE I ");

// intitial state

GPIO_PORTF_DATA_R = 0x0F;
ROTATE_LEFT(GPIO_PORTF_DATA_R,4,8);

    while(1)
    {
       if(state == RED_STATE)
	   {
		   GPIO_PORTF_DATA_R  = 0x02;
	   }  
	   else if (state == BLUE_STATE)
	   {
		   GPIO_PORTF_DATA_R = 0x04;
	   }  
	   else if (state == GREEN_STATE)
	   {
		   GPIO_PORTF_DATA_R = 0x08;
	   }

    }

}

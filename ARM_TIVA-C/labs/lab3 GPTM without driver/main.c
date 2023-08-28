// raw trial of GPTM periodic / pwm / edge time on tiva c

#include "tm4c123gh6pm.h"
#include "./LIB/BIT_MATH.h"
#include "./LIB/STD_TYPES.h"

#include "MCAL/GPIO/GPIO_interface.h"

#define PWM


void _delay_ms(u32 n)
{
    int i,j;
     for(i=0;i<n;i++)
     for(j=0;j<3180;j++)
     {};
}

#ifdef PWM

int main(void)
{
    // pwm to control blinking of red LED using GPTM
    GPIO_Init_Port(PORTF_ID, NO_PINS, P1);
    // alternative function select for pin 1 port f
    GPIO_PORTF_AFSEL_R|=(1<<1);
    // control port GPIO portf pin 1 with mux 7
    GPIO_PORTF_PCTL_R|=(0x7<<4);

    // send clock to timer 0
    SYSCTL_RCGCTIMER_R|=(1<<0);
    // diable timer
    TIMER0_CTL_R&=~(1<<8);
    // config value for PWM
    TIMER0_CFG_R=0x04;

    // timer mode
    // enable pwm
    TIMER0_TBMR_R|=(1<<3);
    // clear TMBCMR to set it as edge count
    TIMER0_TBMR_R&=~(1<<2);
    // set as periodic
    TIMER0_TBMR_R|=(1<<1);


    // inverting or non inverting mode (non inverting)
    TIMER0_CTL_R|=(1<<14);
//    // select prescaler value to achieve 1 sec
//    TIMER0_TBPR_R = 255;

    // load the timer start value counts up to 4.096 ms
    TIMER0_TBILR_R = 65535 ;
    // load the  match value
    TIMER0_TBMATCHR_R = 0 ;

    // enable the timer
    TIMER0_CTL_R|=(1<<8);

while (1)
{
   u32 i;
    for (i = 0 ; i<65535 ; i+=655) // increase led brightness by 1 percent
    {
        TIMER0_TBMATCHR_R = i ;
        _delay_ms(10);
    }

}


}
#endif


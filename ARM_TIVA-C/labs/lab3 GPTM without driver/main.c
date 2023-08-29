// raw trial of GPTM periodic / pwm / edge time on tiva c

#include "tm4c123gh6pm.h"
#include "./LIB/BIT_MATH.h"
#include "./LIB/STD_TYPES.h"

#include "MCAL/GPIO/GPIO_interface.h"
#include "MCAL/EXTI/EXTI_interface.h"

#define FCPU 16000000UL

//#define EDGE_TIME
//#define PWM
#define PERIODIC

void _delay_ms(u32 n)
{
    int i,j;
     for(i=0;i<n;i++)
     for(j=0;j<3180;j++)
     {};
}
void timer0_handler()
{
        SET_BIT(TIMER0_ICR_R, 0);
        TOG_BIT(GPIO_PORTF_DATA_R, 1);
        TOG_BIT(GPIO_PORTF_DATA_R, 2);
        TOG_BIT(GPIO_PORTF_DATA_R, 3);

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

#ifdef EDGE_TIME



void switch1_handler()
{
    if(EXTICheckIntPin(PORTF_ID,P4_POS))
    {
        GPIO_Write(PORTF_ID, P0, LOW); //put a low value on pin0 port f
    }

}
f32 ticksToSecs(u32 ticks)
{
   return (240000000-ticks)/FCPU;

}

int main(void)
{
    // EDge time working on timer 0 A

    // initialize port F pin 1,2,3 as output
    // initialize port f pin 4 as input and pin 0 as output
    GPIO_Init_Port(PORTF_ID, P4, P1|P2|P3|P0);
    // write one to protf pin 0
    GPIO_Write(PORTF_ID, P0, HIGH); //put a low value on pin0 port f
    // init port c as input
    GPIO_Init_Port(PORTC_ID,P4, NO_PINS);
    // init interuppt for port f pin 4
    EXTI_Init(PORTF_ID, P4, HIGH, IN_PORTF);
    // set callback function
    EXTI_Set_Callback(&switch1_handler);


    //afsel for pin 4 port c
    GPIO_PORTC_AFSEL_R|=(1<<4);
    // set it as wtimer0 in prot ctl
    GPIO_PORTC_PCTL_R|=(0x7<<4*4);


    // send clock to wide timer 0
    SYSCTL_RCGCWTIMER_R|=(1<<0);
    // diable timer 0A
    WTIMER0_CTL_R&=~(1<<0);
    // config value selects a 32 bit configuration
    WTIMER0_CFG_R=0x04;
    // timer mode of timer0 A
    // set TACMR to set it as edge time
    WTIMER0_TAMR_R|=(1<<2);
    // set as capture mode
    WTIMER0_TAMR_R|=(1<<1);
    WTIMER0_TAMR_R|=(1<<0);

    // configure the type of event the timer captures
      WTIMER0_CTL_R|=(1<<2);

    // load the timer start value to count 15 sec
    WTIMER0_TAILR_R = 240000000 ;
    // enable the timer
    WTIMER0_CTL_R|=(1<<0);

    // variable to capture time
    f32 Local_time_captured = 0 ;
while (1)
{
    if(!GPIO_Read(PORTC_ID, P4)) // and edge happened
    {
        Local_time_captured =ticksToSecs(WTIMER0_TAR_R);

        if (Local_time_captured<=5)
        {
            GPIO_Write(PORTF_ID, P1, HIGH);
            GPIO_Write(PORTF_ID, P2, LOW);
            GPIO_Write(PORTF_ID, P3, LOW);
        }
        else if (Local_time_captured<=10)
        {
            GPIO_Write(PORTF_ID, P1, LOW);
            GPIO_Write(PORTF_ID, P2, HIGH);
            GPIO_Write(PORTF_ID, P3, LOW);
        }
        else if (Local_time_captured<=15)
        {
            GPIO_Write(PORTF_ID, P1, LOW);
            GPIO_Write(PORTF_ID, P2, LOW);
            GPIO_Write(PORTF_ID, P3, HIGH);
        }

//        // load the timer start value to count 15 sec
//        WTIMER0_TAILR_R = 240000000 ;
        GPIO_Write(PORTF_ID, P0, HIGH);

    }


}


}
#endif


#ifdef PERIODIC

void main(void)
{

    GPIO_Init_Port(PORTF_ID, NO_PINS, P1|P2|P3);
    // Enabling the RCC For the Timer
        SET_BIT(SYSCTL_RCGCTIMER_R, 0);

        CLR_BIT(TIMER0_CTL_R,0);

        TIMER0_CFG_R=0x04;

        TIMER0_TAMR_R=0x2;

        CLR_BIT(TIMER0_TAMR_R,4);

        TIMER0_TAILR_R=65535;

        TIMER0_TAPR_R = 122;

        SET_BIT(TIMER0_IMR_R,0);

        SET_BIT(TIMER0_CTL_R,0);

        SET_BIT(TIMER0_ICR_R,0);

        SET_BIT(NVIC_EN0_R, 19);

        while(1)
        {

        }
}



#endif


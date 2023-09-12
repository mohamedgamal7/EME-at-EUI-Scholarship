//
//
///*Library includes*/
#include "LIB/BIT_MATH.h"
#include "LIB/tm4c123gh6pm.h"
#include "LIB/types.h"
#include "LIB/Delay.h"
//
/*MCAL includes*/
#include "MCAL/GPTM/GPTM.h"
#include "MCAL/GPTM/GPTM_Types.h"
#include "MCAL/DIO/DIO.h"


/*Ulttrasonic includes*/
#include "./HAL/ULTRASONIC/ULTRASONIC_interface.h"
#include "./HAL/ULTRASONIC/ULTRASONIC_private.h"
#include "./HAL/ULTRASONIC/ULTRASONIC_config.h"

volatile uint32_t Rise, Fall;
volatile uint8_t Interrupt_Entry=0; /*State that checks if i am going to read positive edge or negative edge*/
float Distance;
int Difference;
float Period = 0U;

void Ultrasonic_Init(void)
{


    Ultrasonic_GPIO_Init();
    Ultrasonic_Timer_Init();
}

void trigger_measurement(void)
{

      DIO_Write(PORTB, P0, HIGH);
      delay_us(160);
      DIO_Write(PORTB, P0, LOW);


}

static void Ultrasonic_GPIO_Init(void)
{


    GPIOPinConfigure(GPIO_PD0_WT2CCP0);
    GPIO_PORTD_AFSEL_R|=(1<<0);
    GPIO_PORTD_PCTL_R|=(0x7<<0);
    //GPIOPinTypeTimer(GPIO_PORTD_BASE, GPIO_PIN_0); /* PD0 for timer for ECHO */

}

static void Ultrasonic_Timer_Init(void)
{
    /* Enable WTIMER2 Clock */
    //SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER2);
    TimerStartUse(WTIMER_0);
    //TimerDisable(WTIMER2_BASE, TIMER_A);
    TimerDisable( WTIMER_0,TIMERA);
    //TimerConfigure(WTIMER2_BASE, TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_CAP_TIME); /* Timer A with Capture edge time mode */
    TimerConfigure (WTIMER_2, TIMERA, WTIMER_MODE32 , TMR_CAPTURE);
    //TimerControlEvent(WTIMER2_BASE, TIMER_A, TIMER_EVENT_BOTH_EDGES); /* Capture on rising edge */
    //TimerControlEvents(WTIMER_2,TIMERA, BOTH_EDGES) /* Capture on rising edge */
    //IntEnable(INT_WTIMER2A);
    //TimerIntRegister(0WTIMER_2, TIMERA, &Ultrasonic_Callback);
    //TimerIntEnable(WTIMER_2, TIMER_CAPA_EVENT);
    //IntMasterEnable();
    TimerEnable(WTIMER_2, TIMERA); /* Enable Timer A */
}

void Ultrasonic_Callback(void)
{
    //GPIOIntClear(GPIO_PORTD_BASE, GPIO_PIN_0);
    if (!Interrupt_Entry)
    {
        Rise = TimerValueGet(WTIMER2_BASE, TIMER_A);
        Interrupt_Entry = 1U;
    }
    //TIMER_TAR 4244408905 (Decimal)    GPTM Timer A [Memory Mapped]

    else
    {
        Fall = TimerValueGet(WTIMER2_BASE, TIMER_A);
        Interrupt_Entry = 0U;
        Difference = Rise - Fall;
        Period = Difference / 16000000.0;
        Distance = (Period * 34000U) / 2U;

    }
    TimerIntClear(WTIMER2_BASE, TIMER_CAPA_EVENT);

}

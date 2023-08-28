/********************************************************************************************/
/* Author: Mohamed Gamal Rousdhy                                                           */
/* Version: V01                                                                            */
/* Date: 19/08/2023                                                                        */
/* Description: SYTCK driver program file                                                  */
/********************************************************************************************/

#include "./LIB/BIT_MATH.h"
#include "./LIB/STD_TYPES.h"

#include "./MCAL/SYSTCK/SYSTCK_interface.h"
#include "./MCAL/SYSTCK/SYSTCK_private.h"
#include "./MCAL/SYSTCK/SYSTCK_config.h"

/* global variables */
void(*SYSTICK_CallBack)(void); /* callback ptr */
volatile u8 IntMode = NO_INT;

void Systick_Init(void)
{
    /* select clk source for systick */
    #if (CLK_SRC_SEL == SYS_CLOCK)
    {
        SET_BIT(SYSTICK->STCTRL_R, CLK_SRC);
    }
    #elif (CLK_SRC_SEL == PIOSC_4)
    {
        CLR_BIT(SYSTICK->STCTRL_R, CLK_SRC);
    }
    #endif

    /* disable interupts initially */
    CLR_BIT(SYSTICK->STCTRL_R,INTEN);
    /* disable timer intitially */
    CLR_BIT(SYSTICK->STCTRL_R,ENABLE);
}

void Systick_SetBusyWait(u32 Cpy_Ticks)
{
    /* load ticks into reload register */
    SYSTICK->STRELOAD_R = Cpy_Ticks;
    /* enable timer */
    SET_BIT(SYSTICK->STCTRL_R,ENABLE);
    /* poll for the count flag */
    while(GET_BIT(SYSTICK->STCTRL_R,COUNT)==0);
    /* disable timer */
    CLR_BIT(SYSTICK->STCTRL_R,ENABLE);
}

void Systick_SetIntervalSingle(u32 Cpy_Ticks, void(*Ptr)(void))
{
    /* load ticks into reload register */
    SYSTICK->STRELOAD_R = Cpy_Ticks;
    /* set callback function */
    SYSTICK_CallBack = Ptr;
    /* Set mode to single interval */
    IntMode = SINGLE_INTERVAL;
    /* enable timer */
    SET_BIT(SYSTICK->STCTRL_R,ENABLE);
    /* enable interupts */
    SET_BIT(SYSTICK->STCTRL_R,INTEN);
}

void Systick_SetIntervalPeriodic(u32 Cpy_Ticks, void(*Ptr)(void))
{
    /* load ticks into reload register */
    SYSTICK->STRELOAD_R = Cpy_Ticks -1;
    /* set callback function */
    SYSTICK_CallBack = Ptr;
    /* Set mode to periodic interval */
    IntMode = PERIODIC_INTERVAL;
    /* enable timer */
    SET_BIT(SYSTICK->STCTRL_R,ENABLE);
    /* enable interupts */
    SET_BIT(SYSTICK->STCTRL_R,INTEN);
}

void Systick_StopInterval(void)
{
    /* disable timer */
    SET_BIT(SYSTICK->STCTRL_R,ENABLE);
    /* disable interupts */
    SET_BIT(SYSTICK->STCTRL_R,INTEN);
    /* zero out the reload register */
    SYSTICK->STRELOAD_R = 0;
    /* zero out the CTRL register */
    SYSTICK->STCURRENT_R = 0;
}

u32 Systick_GetElapsedTime(void)
{
    return ( SYSTICK->STRELOAD_R -  SYSTICK->STCURRENT_R );
}

u32 Systick_GetRemainingTime(void)
{
    return ( SYSTICK->STCURRENT_R );
}

u8 Systick_GetCountFlag(void)
{
    return GET_BIT(SYSTICK->STCTRL_R,COUNT);
}

void Systic_DelayBusyWait(u32 mSecs)
{

    #if (CLK_SRC_SEL == SYS_CLOCK)
    {
        Systick_SetBusyWait(mSecs*16*1000);
    }
    #elif (CLK_SRC_SEL == PIOSC_4)
    {
       Systick_SetBusyWait(mSecs*4*1000);
    }
    #endif

}
void Systic_SEtDelayPeriodic(u32 mSecs,void(*Ptr)(void))
{

    #if (CLK_SRC_SEL == SYS_CLOCK)
    {
        Systick_SetIntervalPeriodic(mSecs*16*1000,Ptr);
    }
    #elif (CLK_SRC_SEL == PIOSC_4)
    {
        Systick_SetIntervalPeriodic(mSecs*4*1000,Ptr);
    }
    #endif
}



void SysTickHandler(void)
{
    volatile u8 Local_Temporary;

    if (IntMode == SINGLE_INTERVAL)
    {
        /* Disable STK Interrupt */
        CLR_BIT(SYSTICK->STCTRL_R, INTEN);
        /* Stop Timer */
        CLR_BIT(SYSTICK->STCTRL_R, ENABLE);
        /* zero out the reload register */
        SYSTICK->STRELOAD_R = 0;
        /* zero out the CTRL register */
        SYSTICK->STCURRENT_R = 0;
        /* reset mode */
        IntMode =NO_INT;
    }

    /* Callback notification to asynchronous function */
    SYSTICK_CallBack();
    /* Clear interrupt flag */
    Local_Temporary = GET_BIT(SYSTICK->STCTRL_R,COUNT);
}

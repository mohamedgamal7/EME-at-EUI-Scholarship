/* LIB */
#include "./LIB/BIT_MATH.h"
#include "./LIB/STD_TYPES.h"
/* MCAL drivers */
#include "./MCAL/GPIO/GPIO_interface.h"
#include "./MCAL/SYSTCK/SYSTCK_interface.h"
#include "./MCAL/EXTI/EXTI_interface.h"

/* HAL drivers */
#include "./HAL/LCD/LCD_interface.h"

/* global volatiles */
volatile u8 switch1_pressed;
volatile u8 switch2_pressed;
volatile u64 time_passed;
volatile u8 secs;
volatile u8 mins;
volatile u8 hours;

/* A global that holds the String to display on the LCD */
u8 Str_To_display[10];
u8 state;

/*Prototypes*/
void switches_press(void);
void Inc_Time(void);
void Fill_string(void);

/* main prototype for misra c rules */
u32 main(void);


u32 main(void)
{


    /* init switches as input pull up */
    GPIO_Init_Port(PORTF_ID, P0|P4, NO_PINS);
    /* init LCD */
    LCD_Init();
    /* init systick */
    Systick_Init();
    /* intitialize external interrupt */
    EXTI_Init(PORTF_ID, P0|P4, HIGH, IN_PORTF);
    /* set callback function */
    EXTI_Set_Callback(&switches_press);

    Fill_string();
    LCD_SendCommand(LCD_CLEAR); /* clear the LCD */
    LCD_SendCommand(FORCE_FIRSTL);
    LCD_DisplayString(Str_To_display);
    while(1)
    {

        if (switch2_pressed) /* Reset the stop watch and start counting */
        {
            switch2_pressed = 0u ;
            time_passed  = 0u;
            secs  = 0u;
            mins  = 0u;
            hours = 0u;
            LCD_SendCommand(LCD_CLEAR); /* clear the LCD */
            LCD_SendCommand(FORCE_FIRSTL);
            Systic_SEtDelayPeriodic(1000u,&Inc_Time);
        }
        else if (switch1_pressed) /* pause the LCD */
        {
            if(state==0)
            {
                switch1_pressed = 0u ;
                Systick_StopInterval();
                LCD_SendCommand(LCD_CLEAR); /* clear the LCD */
                LCD_SendCommand(FORCE_FIRSTL);
                LCD_DisplayString(Str_To_display);
                state++;

            }
            else
            {   switch1_pressed = 0u ;
                LCD_SendCommand(LCD_CLEAR); /* clear the LCD */
                LCD_SendCommand(FORCE_FIRSTL);
                Systic_SEtDelayPeriodic(1000u,&Inc_Time);

                state--;
            }
        }

        else
            {
                /* do noothing */
            }


    }
}

void switches_press(void)
{
    if (EXTICheckIntPin(PORTF_ID, P0_POS))
    {
        switch2_pressed = 1U;
    }
    else if (EXTICheckIntPin(PORTF_ID, P4_POS))
    {
        switch1_pressed = 1U;
    }
    else
    {
        /* Handle other cases if needed */
    }
}

/* increment timing every one sec */
void Inc_Time(void)
    {
        time_passed++;
        Fill_string();
        LCD_SendCommand(LCD_CLEAR); /* clear the LCD */
        LCD_SendCommand(FORCE_FIRSTL);
        LCD_DisplayString(Str_To_display);
    }



void Fill_string(void)
    {
          secs =  (u8)(time_passed % 60u);
          mins =  (u8)(time_passed / 60u);
          hours = (u8)(time_passed / 3600u);
        /* Todo: find a cleaner implementation */
          Str_To_display[0] = (hours / 10) + '0';
          Str_To_display[1] = (hours % 10) + '0';
          Str_To_display[2] = ':';
          Str_To_display[3] = (mins / 10) + '0';
          Str_To_display[4] = (mins % 10) + '0';
          Str_To_display[5] = ':';
          Str_To_display[6] = (secs / 10) + '0';
          Str_To_display[7] = (secs % 10) + '0';
    }

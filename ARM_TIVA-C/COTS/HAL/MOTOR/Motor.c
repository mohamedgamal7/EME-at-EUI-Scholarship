/********************************************************************************************/
/* Authors: Mohamed Gamal, Ehab Roushdy, Mohamed abelmoteleb and Aya Yasse                  */
/* Version: V01                                                                             */
/* Date: 10/09/2023                                                                         */
/* Description: Motor driver Progran file                                                   */
/********************************************************************************************/

/*Library includes*/
#include "LIB/types.h"
/*MCAL includes*/
#include "MCAL/DIO/DIO.h"
#include "MCAL/PWM/PWM_interface.h"

void MotorInit(void)
{
    /* Initialize pwm module 0 generators 0, 1 to be used*/
    pwm_init();

    /* Initially Motors go forward */
    DIO_Write(PORTC,  P6 | P7, P6);
    DIO_Write(PORTD,  P6 | P7, P6);

}

void MotorForward(unsigned char percent)
{
    /* Motors goes forward */
    DIO_Write(PORTC,  P6 | P7, P6);
    DIO_Write(PORTD,  P6 | P7, P6);
    /*Set duty cycle to control speed*/
    pwm_set_duty_cycle(percent);
}

void MotorTurnRight(unsigned char percent)
{
    /* initially all forward */
    DIO_Write(PORTC,  P6 | P7, P7);
    DIO_Write(PORTD,  P6 | P7, P6);

    /*Set duty cycle.*/
    pwm_set_duty_cycle(percent);

}

void MotorTurnLeft(unsigned char percent)
{
    /* initially all forward */
    DIO_Write(PORTC,  P6 | P7, P6);
    DIO_Write(PORTD,  P6 | P7, P7);

    /*Set duty cycle.*/
    pwm_set_duty_cycle(percent);
}

void MotorBackward(unsigned char percent)
{

    /* initially all forward */
    DIO_Write(PORTC,  P6 | P7, P7);
    DIO_Write(PORTD,  P6 | P7, P7);

    /*Set duty cycle.*/
    pwm_set_duty_cycle(percent);

}

void MotorStop(void)
{
    DIO_Write(PORTC,  P6 | P7, P6 | P7);
    DIO_Write(PORTD,  P6 | P7, P6 | P7);
}

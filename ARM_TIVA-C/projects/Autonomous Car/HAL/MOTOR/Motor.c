#include "MCAL/PWM/PWM_interface.h"

void MotorInit(void)
{
    // Initialize pwm module 0 generators 0, 1 to be used
    pwm_init();

    // Enable the GPIOA peripheral
//    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
//    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);

    // Enable the GPIOA peripheral
//    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOC));
//    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOD));

//    GPIOUnlockPin(GPIO_PORTD_BASE, GPIO_PIN_7);

    // Set pins 0 and  as output, SW controlled.
//    GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE, GPIO_PIN_6 | GPIO_PIN_7);
//    GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_6 | GPIO_PIN_7);

    /* initially all forward */
//    GPIOPinWrite(GPIO_PORTC_BASE,  GPIO_PIN_6 | GPIO_PIN_7, GPIO_PIN_6);
//    GPIOPinWrite(GPIO_PORTD_BASE,  GPIO_PIN_6 | GPIO_PIN_7, GPIO_PIN_6);

}

void MotorForward(unsigned char percent)
{
    /* initially all forward */
//    GPIOPinWrite(GPIO_PORTC_BASE,  GPIO_PIN_6 | GPIO_PIN_7, GPIO_PIN_6);
//    GPIOPinWrite(GPIO_PORTD_BASE,  GPIO_PIN_6 | GPIO_PIN_7, GPIO_PIN_6);

    // Set duty cycle.
    pwm_set_duty_cycle(percent);

}

void MotorTurnRight(unsigned char percent)
{
    /* initially all forward */
//    GPIOPinWrite(GPIO_PORTC_BASE,  GPIO_PIN_6 | GPIO_PIN_7, GPIO_PIN_7);
//    GPIOPinWrite(GPIO_PORTD_BASE,  GPIO_PIN_6 | GPIO_PIN_7, GPIO_PIN_6);

    // Set duty cycle.
    pwm_set_duty_cycle(percent);

}

void MotorTurnLeft(unsigned char percent)
{
    /* initially all forward */
//    GPIOPinWrite(GPIO_PORTC_BASE,  GPIO_PIN_6 | GPIO_PIN_7, GPIO_PIN_6);
//    GPIOPinWrite(GPIO_PORTD_BASE,  GPIO_PIN_6 | GPIO_PIN_7, GPIO_PIN_7);

    // Set duty cycle.
    pwm_set_duty_cycle(percent);
}

void MotorBackward(unsigned char percent)
{
    /* clamp percent between 100 and 0 */
//    percent = ((percent > 100) ? 100 : ((percent < 0) ? 0 : percent)) / 100;

    /* initially all forward */
//    GPIOPinWrite(GPIO_PORTC_BASE,  GPIO_PIN_6 | GPIO_PIN_7, GPIO_PIN_7);
//    GPIOPinWrite(GPIO_PORTD_BASE,  GPIO_PIN_6 | GPIO_PIN_7, GPIO_PIN_7);

    // Set duty cycle.
    pwm_set_duty_cycle(percent);

}

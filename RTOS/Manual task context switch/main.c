

#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_ints.h"
#include "inc/hw_i2c.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"

#include "driverlib/interrupt.h"
#include "driverlib/i2c.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"
#include "utils/uartstdio.c"
#include "driverlib/flash.h"
#include "driverlib/systick.h"
#include "driverlib/fpu.h"

uint32_t counter;

uint32_t stack_RedBlinky[40];
uint32_t *sp_RedBlinky = &stack_RedBlinky[40];

uint32_t stack_BlueBlinky[40];
uint32_t *sp_BlueBlinky = &stack_BlueBlinky[40];
void Systick_Handler(void){

   counter =(counter+1)%5;
}

void task1(void)
{

    while(1)
    {
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0);
        while((counter%5)!=0 || counter==0);
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, GPIO_PIN_1);
        while((counter%5)!=0 || counter==0);
    }

}

void task2(void)
{

    while(1)
    {
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0);
        while((counter%5)!=0 || counter==0);
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_PIN_2);
        while((counter%5)!=0 || counter==0);

    }

}


int main(void)
{
    sp_RedBlinky--;
    *sp_RedBlinky =(1<<24); //PSR
    sp_RedBlinky--;
    *sp_RedBlinky =(uint32_t)&task1; //PC
    sp_RedBlinky--;
    *sp_RedBlinky =0xFFFFFFF9; //LR


    sp_BlueBlinky--;
    *sp_BlueBlinky =(1<<24); //PSR
    sp_BlueBlinky--;
    *sp_BlueBlinky =(uint32_t)&task2; //PC
    sp_BlueBlinky--;
    *sp_BlueBlinky =0xFFFFFFF9; //LR


    /*FPU disable*/
    FPUDisable();
    /*Hardware init */
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);

    SysTickPeriodSet(100*16000-1);
    SysTickIntRegister(Systick_Handler);
    SysTickIntEnable();
    IntMasterEnable();
    SysTickEnable();

    /*call task 1*/
    task1(); //0x0718

    //task2(); //0x0760

while(1)
{

}


}


/*
 * main.c
 *
 *  Created on: Sep 3, 2023
 *      Author: Mohamed_Gamal
 */

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
#include "inc/hw_i2c.h"



#define SLAVE_ADDRESS 0x42

void Master_Init(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C1);
    GPIOPinConfigure(GPIO_PA6_I2C1SCL);
    GPIOPinConfigure(GPIO_PA7_I2C1SDA);
    GPIOPinTypeI2CSCL(GPIO_PORTA_BASE, GPIO_PIN_6);
    GPIOPinTypeI2C(GPIO_PORTA_BASE, GPIO_PIN_7);
    I2CMasterInitExpClk(I2C1_BASE, SysCtlClockGet(), false);
    I2CMasterEnable(I2C1_BASE);
    I2CMasterSlaveAddrSet(I2C1_BASE, SLAVE_ADDRESS, false);
}

void Slave_Init(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOE));

    SysCtlPeripheralDisable(SYSCTL_PERIPH_I2C2);
    SysCtlPeripheralReset(SYSCTL_PERIPH_I2C2);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C2);

    GPIOPinConfigure(GPIO_PE4_I2C2SCL);
    GPIOPinConfigure(GPIO_PE5_I2C2SDA);
    GPIOPinTypeI2CSCL(GPIO_PORTE_BASE, GPIO_PIN_4);
    GPIOPinTypeI2C(GPIO_PORTE_BASE, GPIO_PIN_5);
    GPIOPadConfigSet(GPIO_PORTE_BASE, GPIO_PIN_5, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
    I2CSlaveEnable(I2C2_BASE);
    I2CSlaveInit(I2C2_BASE, SLAVE_ADDRESS);

}


uint8_t data[40];
uint8_t * str = "123456789";
uint8_t i ;
int main(void) {
    Master_Init();
    Slave_Init();


    while (1) {

        for (i = 0; str[i]; ++i)
        {
            I2CMasterDataPut(I2C1_BASE, str[i]);
                   //        Initiate sned data character
            I2CMasterControl(I2C1_BASE, I2C_MASTER_CMD_SINGLE_SEND);
            while(I2CMasterBusy(I2C1_BASE));
            data[i] = I2CSlaveDataGet(I2C2_BASE);
        }





    }
}
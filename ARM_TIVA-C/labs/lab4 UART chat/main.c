#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"

uint8_t UART_STATE = 0 ;

void UARTSend(uint32_t ui32UARTBase, const uint8_t *pui8Buffer, uint32_t ui32Count)
{
  
    /* Loop while there are more characters to send.*/
   
    while(ui32Count--)
    {
        //
        // Write the next character to the UART.
        //
        UARTCharPut(ui32UARTBase, *pui8Buffer++);
    }
}

int main(void)
{
    SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

    // Enable the peripherals used by this example.
    // The UART itself needs to be enabled, as well as the GPIO port
    // containing the pins that will be used.
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART1);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_0 | GPIO_PIN_4);
    GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_0 | GPIO_PIN_4, GPIO_STRENGTH_12MA, GPIO_PIN_TYPE_STD_WPU);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);

    // Configure the GPIO pin muxing for the UART function.
    // This is only necessary if your part supports GPIO pin function muxing.
    // Study the data sheet to see which functions are allocated per pin.
    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    GPIOPinConfigure(GPIO_PB0_U1RX);
    GPIOPinConfigure(GPIO_PB1_U1TX);

    // Since GPIO A0 and A1 are used for the UART function, they must be
    // configured for use as a peripheral function (instead of GPIO).
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
    GPIOPinTypeUART(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1);

    // Configure the UART for 115,200, 8-N-1 operation.
    // This function uses SysCtlClockGet() or ui32SysClock to get the system clock
    // frequency.  This could be also be a variable or hard coded value
    // instead of a function call.
    UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 115200, (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));
    UARTConfigSetExpClk(UART1_BASE, SysCtlClockGet(), 115200, (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));

    UARTSend(UART0_BASE, (uint8_t *)"\033[2J\033[1;1H", 10);


    uint8_t data[200] = {0};
    uint8_t i = 0;
    while(1)
    {
        i = 0;
        /* idle */
        if(!UART_STATE)
        {
            if(!GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_4))
            {
                UART_STATE += 1;
            }

        }
        /* start at receiving state  */
        else if (1==UART_STATE)
        {
            while(UARTCharsAvail(UART0_BASE))
                UARTCharGet(UART0_BASE);
            while(UARTCharsAvail(UART1_BASE))
                UARTCharGet(UART1_BASE);

            UARTSend(UART0_BASE, "Ehab Roshdy: ",14);

               for (i = 0; i < 200; ++i)
               {
                   data[i] = UARTCharGet(UART1_BASE);

                   if(data[i]=='#') {break;}
                   UARTCharPut(UART0_BASE, data[i]);

               }
               UART_STATE++;
               UARTCharPut(UART0_BASE, '\n');
               UARTCharPut(UART0_BASE, '\r');
        }

        /* sending state */
        else if (2==UART_STATE)
        {
            while(UARTCharsAvail(UART0_BASE))
                UARTCharGet(UART0_BASE);
            while(UARTCharsAvail(UART1_BASE))
                UARTCharGet(UART1_BASE);
            UARTSend(UART0_BASE, "Mohamed Gamal: ",16);
            for (i = 0; i < 200; ++i)
                {

                    data[i] = UARTCharGet(UART0_BASE);
                    if(data[i] == '#')

                    {

                        ++i;
                        break;
                    }
                    UARTCharPut(UART0_BASE, data[i]);
                    if(i >= 100)
                        GPIOPinWrite(GPIO_PORTF_BASE, (GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3), GPIO_PIN_3);
                    else if(i >= 150)
                        GPIOPinWrite(GPIO_PORTF_BASE, (GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3), GPIO_PIN_2);

                }

                if(i >= 200)
                    GPIOPinWrite(GPIO_PORTF_BASE, (GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3), GPIO_PIN_1);

                UARTSend(UART1_BASE, data, i);

                UART_STATE--;
               UARTCharPut(UART0_BASE, '\n');
               UARTCharPut(UART0_BASE, '\r');
        }
    }


    return 0;
}

// Include necessary TivaWare and FreeRTOS headers

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

// Define LED pin
#define LED_PIN GPIO_PIN_1
#define LED_PORT GPIO_PORTF_BASE


QueueHandle_t queueHandler;


void vApplicationStackOverflowHook(xTaskHandle *pxTask, signed char *pcTaskName){
    while(1);
}

typedef struct
{
    int sensor_value;
    uint32_t sensor_ID;

} xdata;

// Task function to send 1
void Sender1(void) {
    xdata data1;
    data1.sensor_ID =0x55;
    data1.sensor_value = 0;
    while (1)
    {
        xQueueSend(queueHandler,&data1,100/portTICK_PERIOD_MS);
        ++data1.sensor_value;
//        taskYIELD();
    }
}

// Task function to send 2
void Sender2(void) {
      xdata data2;
      data2.sensor_ID =0x56;
      data2.sensor_value = 0;
      while (1)
      {
          xQueueSend(queueHandler,&data2,100/portTICK_PERIOD_MS);
          ++data2.sensor_value;
//          taskYIELD();
      }

}
void receive(void) {
    xdata data_receive;
    while (1)
    {
        xQueueReceive(queueHandler,&data_receive,0);

    }
}

int main(void) {
    // Initialize the system clock
    SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

    // Enable the GPIO port F
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    GPIOPinTypeGPIOOutput(LED_PORT, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);

    // Create the LED blinking task
    xTaskCreate(Sender1, "first sender", configMINIMAL_STACK_SIZE, NULL,2, NULL);
    xTaskCreate(Sender2, "second sender", configMINIMAL_STACK_SIZE, NULL,2, NULL);
    xTaskCreate(receive, "receiver", configMINIMAL_STACK_SIZE, NULL,1, NULL);
    // queue creation
    queueHandler = xQueueCreate(4,sizeof(xdata));
    // Start the FreeRTOS scheduler
    vTaskStartScheduler();

    // The scheduler should never return, but if it does, something went wrong
    while (1);
}

// Include necessary TivaWare and FreeRTOS headers
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_ints.h"

#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"



#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "queue.h"

// Define LED pin
#define LED_PIN GPIO_PIN_1
#define LED_PORT GPIO_PORTF_BASE

void vApplicationStackOverflowHook(xTaskHandle *pxTask, signed char *pcTaskName){
    while(1);
}

//SemaphoreHandle_t binary_semph;
//SemaphoreHandle_t counting_semph;
SemaphoreHandle_t mutex;

// Task function to blink the LED
void RED(void *pvParameters) {
    while (1) {
    if(xSemaphoreTake(mutex,portMAX_DELAY)==pdTRUE)

    {
     int i;
     for(i=0;i<5;i++)
     {
        // Toggle the LED
        GPIOPinWrite(LED_PORT, GPIO_PIN_1,GPIO_PIN_1);
        SysCtlDelay(8000000/3);
        GPIOPinWrite(LED_PORT, GPIO_PIN_1,0);
      SysCtlDelay(8000000/3);
     }
     xSemaphoreGive(mutex);
    vTaskDelay(pdMS_TO_TICKS(100)); // Delay for 500 ms

    }

    }
}

// Task function to blink the LED
void BLUE(void *pvParameters) {
    while (1) {
     if(xSemaphoreTake(mutex,portMAX_DELAY)==pdTRUE)
     {

          int i;
          for(i=0;i<5;i++)
          {
            // Toggle the LED
            GPIOPinWrite(LED_PORT,GPIO_PIN_2,GPIO_PIN_2);
            SysCtlDelay(8000000/3);
            GPIOPinWrite(LED_PORT, GPIO_PIN_2,0);
            SysCtlDelay(8000000/3);
//           xSemaphoreGive(binary_semph);
          }
          xSemaphoreGive(mutex);
//          vTaskDelay(pdMS_TO_TICKS(100)); // Delay for 500 ms

     }
    }
}

//void IntHandler(void)
//{
//    GPIOIntClear(LED_PORT, GPIO_INT_PIN_4);
//    BaseType_t xHigherPriorityTaskWoken;
//     xHigherPriorityTaskWoken = pdFALSE;
//     xSemaphoreGiveFromISR(mutex, &xHigherPriorityTaskWoken );
//      portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
//
//}

//void GREEN(void *pvParameters) {
//    while (1) {
//        // Toggle the LED
//        GPIOPinWrite(LED_PORT,GPIO_PIN_3,GPIO_PIN_3);
//        SysCtlDelay(8000000/3);
//        GPIOPinWrite(LED_PORT, GPIO_PIN_3,0);
//       vTaskDelay(pdMS_TO_TICKS(500)); // Delay for 500 ms
//
//    }
//}

int main(void) {
    // Initialize the system clock
    SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

    // Enable the GPIO port F
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    GPIOPinTypeGPIOOutput(LED_PORT, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);
//    GPIOPinTypeGPIOInput(LED_PORT, GPIO_PIN_4);
//    GPIOPadConfigSet(LED_PORT, GPIO_INT_PIN_4,GPIO_STRENGTH_10MA, GPIO_PIN_TYPE_STD_WPU);

//    GPIOIntRegister(LED_PORT, IntHandler);
//    GPIOIntTypeSet(LED_PORT, GPIO_INT_PIN_4, GPIO_FALLING_EDGE);
//    GPIOIntEnable(LED_PORT, GPIO_INT_PIN_4);
//    IntEnable(INT_GPIOF);
//    IntMasterEnable();

    // create binary semaphore
//    binary_semph = xSemaphoreCreateBinary();
    // create counting semphore
    // create mutex
    mutex= xSemaphoreCreateMutex();
//    counting_semph = xSemaphoreCreateCounting(10,0);
    // Create the LED blinking task
    if( mutex != NULL )
    {
    xTaskCreate(RED, "LEDRED_Blink", configMINIMAL_STACK_SIZE+128, NULL,3, NULL);
    xTaskCreate(BLUE, "LEDBLUE_Blink", configMINIMAL_STACK_SIZE+128, NULL,1, NULL);
    }
//    xTaskCreate(GREEN, "LEDGREEN_Blink", configMINIMAL_STACK_SIZE, NULL,3, NULL);
//    vTaskSuspendAll();
    // Start the FreeRTOS scheduler
    vTaskStartScheduler();



    // The scheduler should never return, but if it does, something went wrong
    while (1);
}

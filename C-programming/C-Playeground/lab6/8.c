#include <stdio.h>
typedef unsigned char uint8_t;

typedef struct
{
    volatile uint8_t Busy : 1;
    volatile uint8_t state : 2;
    volatile uint8_t : 3;
    volatile uint8_t ovf : 1;
    volatile uint8_t frame : 1;
} UART_STATUS_R_t;

#define UART_STATUS_R_T (*(volatile UART_STATUS_R_t *)(0x48))
int main()
{
}
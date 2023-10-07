

/**
 * main.c
 */
#include "DIO/Dio.h"
#include "PORT/Port.h"

static void delay_ms(int m){
    int i, j;
    for(i = 0; i < m; i++){
        for(j = 0; j < 1514; j++);
    }
}

int main(void)
{
    Port_Init();

    while(1)
    {
        Dio_WriteChannel(41, STD_HIGH);
        delay_ms(1000);
        Dio_WriteChannel(41, STD_LOW);
        delay_ms(1000);
    }
}

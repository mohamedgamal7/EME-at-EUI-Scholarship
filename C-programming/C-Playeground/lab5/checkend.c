#include <stdio.h>

typedef union
{
    int data;
    char bytes;
} data_t;

int main()
{
    int data = 0xABCD;
    char *ptrData = (char *)&data;
    if (*ptrData == 0xCD)
    {
        printf("little endian\n");
    }
    else
    {
        printf("big endian \n");
    }

    data_t d1;
    d1.data = 0xABCD;
    if (d1.bytes == 0XCD)
    {
        printf("little endian\n");
    }
    else
    {
        printf("big endian \n");
    }
}
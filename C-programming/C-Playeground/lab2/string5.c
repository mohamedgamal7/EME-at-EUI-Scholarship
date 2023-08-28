#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int DigitorAlpha(char *character)
{
    return (*character > '0' && *character <= '9') ? 1 : 0;
}

int main()
{
    char a = 'A';
    printf("%d", DigitorAlpha(&a));
}
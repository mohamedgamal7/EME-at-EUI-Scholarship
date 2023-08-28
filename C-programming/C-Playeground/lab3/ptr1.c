#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swapVariables(int *x, int *y)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

void swapPointers(int **p1, int **p2)
{
    int *temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main()
{
    int x = 3;
    int y = 4;
    int *p1 = &x;
    int *p2 = &y;

    printf("%p   %p\n", p1, p2);
    swapPointers(&p1, &p2);
    printf("%p   %p\n", p1, p2);
}

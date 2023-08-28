#include <stdio.h>

int revNum(int num)
{
    int reversed = 0;
    int remainder = 0;
    while (num != 0)
    {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num /= 10;
    }
    return reversed;
}

void setNthbit(int *num, int n)
{
    *num |= (1 << n);
}

int main()
{
    int num = 1;
    setNthbit(&num, 2);
    for (int i = 31; i >= 0; i--)
    {
        if ((num >> i) & 1 == 1)
        {
            printf("1 ");
        }
        else
        {
            printf("0 ");
        }
    }
    printf("\n");
}
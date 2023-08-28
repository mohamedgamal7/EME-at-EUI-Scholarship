#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void findbig2(int *arr, int size, int *largest, int *second)
{

    *largest = INT_MIN;
    *second = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > *largest)
        {
            *second = *largest;
            *largest = arr[i];
        }
        else if (arr[i] > *second && arr[i] != *largest)
        {
            *second = arr[i];
        }
    }
}

int main()
{
    int arr[] = {100, 100, 5, -6, 4, -8, -2147483647, -9, -10, -1, 99, -3, 10, 99, 3, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int largest, second;
    findbig2(arr, size, &largest, &second);
    printf("The largest num is: %d, The second num is: %d", largest, second);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void bubblesort(int *array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

void print2max(int *sortedarray, int size)
{

    if (size == 2) // when array has only two elements
    {

        printf("The 1st max number is : %d  \n", sortedarray[size - 1]);
        printf("The 2nd max number is : %d  \n", sortedarray[size - 2]);
    }

    else
    {

        printf("The 1st max number is :%d \n", sortedarray[size - 1]);
        for (int i = 0; i < size; i++)
        {
            if (sortedarray[size - 2 - i] != sortedarray[size - 1])
            {
                printf("The 2nd max number is :%d \n", sortedarray[size - 2 - i]);
                break;
            }
        }
    }
}

int main()
{

    int array[] = {100, 100, 5, -6, 4, -8, -9, -10, -1, 99, -3, 10, 99, 3, 2};
    int size = sizeof(array) / sizeof(array[0]);

    printf("array before sorting : \n");

    for (int i = 0; i < size; i++)
    {
        printf("%d\n", array[i]);
    }
    bubblesort(array, size);

    printf("array after sorting : \n");

    for (int i = 0; i < size; i++)
    {
        printf("%d\n", array[i]);
    }
    print2max(array, size);
}
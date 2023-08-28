#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void (*callback_compare)(int *, int);

typedef enum
{
    asccending,
    descending
} sorting_method_t;

int sumDigits(int num)
{
    int remainder;
    int sum = 0;
    while (num != 0)
    {
        remainder = num % 10;
        sum += remainder;
        num /= 10;
    }
    return sum;
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void bubblesort(int *array, int size, sorting_method_t sorting_method)
{
    if (sorting_method == asccending)
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
    else if (sorting_method == descending)
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - 1 - i; j++)
            {
                if (sumDigits(array[j]) < sumDigits(array[j + 1]))
                {
                    swap(&array[j], &array[j + 1]);
                }
            }
        }
    }
}

void bubblesortMod(int *array, int size, sorting_method_t sorting_method)
{
    if (sorting_method == asccending)
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
    else if (sorting_method == descending)
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - 1 - i; j++)
            {
                if (array[j] < array[j + 1])
                {
                    swap(&array[j], &array[j + 1]);
                }
            }
        }
    }
}

void bubblesortAscend(int *array, int size)
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

void bubblesortDescend(int *array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (array[j] < array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

void bubblesortMod2(int *array, int size, void (*ptr)(int *, int))
{
    // callback_compare = ptr;
    // callback_compare(array, size);
    ptr(array, size);
}

int main()
{
    int array[] = {1, 3, 4, 55, 54, 3, 3, 45, 3, 3, 2, 392, 2, 2};
    int size = sizeof(array) / sizeof(array[0]);

    printf("array before sorting : \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", array[i]);
    }

    bubblesortMod2(array, size, bubblesortAscend);

    printf("array after sorting : \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", array[i]);
    }

    printf("array before sorting : \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", array[i]);
    }

    bubblesortMod2(array, size, bubblesortDescend);

    printf("array after sorting : \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", array[i]);
    }
}

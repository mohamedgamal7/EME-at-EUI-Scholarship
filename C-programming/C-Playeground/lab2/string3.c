#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to swap two given characters
void swap(char *x, char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}
void reverseTailRec(char *str, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    swap(&str[start], &str[end]);
    reverseTailRec(str, start + 1, end - 1);
}

void recursiveReverse(char *str, int k)
{
    static int i = 0;

    if (*(str + k) == '\0')
    {
        return;
    }

    recursiveReverse(str, k + 1);

    if (i <= k)
    {
        swap(&str[i++], &str[k]);
    }
}

int main()
{
    char string[] = "mohamed gamal";
    recursiveReverse(string, 0);
    printf("%s", string);

    return 0;
}
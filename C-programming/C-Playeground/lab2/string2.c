#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse_string(char *string)
{
    char temp;
    int size = strlen(string);
    for (int i = 0; i < size / 2; i++)
    {
        temp = string[i];
        string[i] = string[size - 1 - i];
        string[size - 1 - i] = temp;
    }
}

int main()
{
    char string[] = "mohamed gamal";
    reverse_string(string);
    printf("%s", string);
    return 0;
}
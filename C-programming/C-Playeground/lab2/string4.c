#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 150

int CountSpaces(char *line)
{
    int count = 0;
    int size = strlen(line);
    for (int i = 0; i < size; i++)
    {
        if (' ' == line[i])
        {
            count++;
        }
    }
    return count;
}

int main()
{
    printf("please enter a certain line\n");
    char line[MAX_SIZE];
    gets(line);
    printf("%d", CountSpaces(line));
}
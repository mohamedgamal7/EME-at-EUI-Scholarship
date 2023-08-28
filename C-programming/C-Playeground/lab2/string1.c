#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare(void const *a, void const *b)
{

    return strcmp(*(const char **)a, *(const char **)b);
}

int main()
{
    char names[5][50];
    char *ptrs[5];
    for (int i = 0; i < 5; i++)
    {
        printf("please enter name no %d :\n", i + 1);
        gets(names[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        ptrs[i] = names[i];
    }
    qsort(ptrs, 5, sizeof(const char *), compare);

    printf("The sorted array of strings is :\n");
    for (int i = 0; i < 5; i++)
    {

        printf("%s \n", ptrs[i]);
    }

    return 0;
}
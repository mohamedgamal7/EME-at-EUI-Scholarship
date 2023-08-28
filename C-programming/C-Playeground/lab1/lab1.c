#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <time.h>

#define first_method 0
#define second_method 1
#define method first_method

int SumtoNUm(int num)
{
    // using gaus formula
    return num * (num + 1) / 2;
}

void greatestofThree(int *num1, int *num2, int *num3)
{
    int max = *num1;

    if (*num2 > max && *num2 > *num3)
    {
        max = *num2;
    }
    else if (*num3 > max && *num3 > *num2)
    {
        max = *num3;
    }
    printf("The max number is : %d \n", max);
}

int EvenOdd(int num)
{
    if (method == first_method)
    {
        if (num % 2)
        {
            return 1;
        }
        else
        {
            return 0; // odd
        }
    }
    else if (method == second_method)
    {
        if ((num >> 0) & 1 == 1)
        {
            return 0; // odd
        }
        else
        {
            return 1;
        }
    }
}

int sumEven(void)
{
    int sum = 0;
    for (int i = 0; i < 21; i++)
    {
        /* code */
        if (EvenOdd(i))
        {
            sum += i;
        }
    }
    printf("The final sum is %d", sum);
}

void printGrade(float percentage)
{
    if (percentage > 100 || percentage < 0)
    {
        printf("incorrect result");
    }
    if (percentage >= 85)
    {
        printf("Excellent");
    }
    else if (percentage >= 75)
    {
        printf("Very good");
    }
    else if (percentage >= 65)
    {
        printf("Good");
    }
    else if (percentage >= 50)
    {
        printf("Pass");
    }
    else if (percentage < 50)
    {
        printf("fail");
    }
}

int VariadicSum(int n, ...)
{
    int Sum = 0;

    // Declaring pointer to the
    // argument list
    va_list ptr;

    // Initializing argument to the
    // list pointer
    va_start(ptr, n);

    for (int i = 0; i < n; i++)

        // Accessing current variable
        // and pointing to next one
        Sum += va_arg(ptr, int);

    // Ending argument list traversal
    va_end(ptr);

    return Sum;
}

int sumdigits(int num)
{

    int sum = 0;
    int remainder;
    for (int i = 0; num != 0; num++)
    {
        remainder = num % 10;
        sum += remainder;
        num /= 10;
    }
    return sum;
}

int validPalindrome(int num)
{
    int result = 0;
    int digits[5];
    for (int i = 0; i < 5; i++)
    {
        digits[i] = num % 10;
        num /= 10;
    }

    for (int i = 0; i < 5; i++)
    {
        if (digits[i] != digits[4 - i])
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

int CopyfromS2D(char *source, char *destination, int size)
{
    for (int i = 0; i < size; i++)
    {
        destination[i] = source[i];
    }
}

int inclusiveRand(int min, int max)
{
    srand(time(NULL));
    return rand() % (max - min + 1) + min;
}

int sumHoles(int num)
{
    int remainder = 0;
    int sum = 0;
    while (num != 0)
    {
        remainder = num % 10;
        if (remainder == 0 || remainder == 4 || remainder == 6 || remainder == 9)
        {
            sum += 1;
        }
        else if (remainder == 8)
        {
            sum += 2;
        }
        num /= 10;
    }
    return sum;
}

int main()
{
    /* 1 - 2 */

    // int n;
    // printf("please enter the number to sum \n");
    // scanf("%d", &n);
    // printf("The sum is :%d", SumtoNUm(n));

    /*  3   */
    // int num1 = 10, num2 = -1, num3 = 11;
    // greatestofThree(&num1, &num2, &num3);

    /* 4 */
    // int num;
    // scanf("%d",num);
    // EvenOdd(num);

    /* 5 */
    // sumEven();

    /*6*/
    // first method
    // char string[] ="mohamed";
    // printf(%s,string);

    // char string[] ="mohamed";
    // for(int i = 0 ; i<sizeof(string); i++)
    // {
    //     printf("%c",string[i]);
    // }

    // char string[] = "mohamed";
    // for (int i = 0; string[i] != NULL; i++)
    // {
    //     printf("%c", string[i]);
    // }

    /*7*/
    // print ASCII
    // char x = "a";
    // printf("%d",x);

    /* 8 - 9 */
    // float percentage =97;
    // printGrade(percentage);

    /* 13 */
    // int a = 11511;
    // printf("%d", validPalindrome(a));

    printf("%d", sumHoles(1288));

    return 0;
}
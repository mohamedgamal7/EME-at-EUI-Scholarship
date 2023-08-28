#include <stdio.h>
// #define string
// typedef struct
// {
//     char *name;
//     int age;
//     int SSN;
//     double salary;
// } EmployeeType;

// EmployeeType *Find(EmployeeType *employees, int EmployeeCount)
// {
//     for (int i = 0; i < EmployeeCount; i++)
//     {
//     }
// }

// int main()
// {
//     EmployeeType employees[3] = {{"karim", 23, 2, 23}, {"ahmed", 12, 3, 543}, {"ahmed", 12, 3, 43}};
// }

void swapEndianess2(unsigned int *data)
{
    *data = (*data & (0XFF000000) >> 24) | (*data & (0X000000FF) << 24) | (*data & (0X00FF0000) >> 8) | (*data & (0X0000FF00) << 8);
}

int main()
{

    unsigned int data = 0xABCDEF12;
    printf("%X\n", data);
    swapEndianess2(&data);
    printf("%X", data);

    return 0;
}
#include <stdio.h>
#include <stdarg.h>

#define GET_BIT(REG, BIT) ((REG >> BIT) & 1)
#define GET_BITS(REG, K, P) ((1 << k) - 1) & (REG >> (P))
#define INSERT_BIT(REG, BIT, VALUE) (REG = (REG & ~(1 << BIT)) | (VALUE << BIT))
#define INSERT_BITS(REG, VAlUE, P, K) (REG = (REG & (~(((1 << k) - 1) << P)) | (VALUE & (~((1 << k) - 1)) << P)))

void set_bits(unsigned int *reg, int n, ...)
{
    va_list ptr;
    va_start(ptr, n);
    unsigned int temp = 0;
    for (int i = 0; i < n; i++)
    {
        temp |= (1 << va_arg(ptr, int)); // use of a temp variable is better for register protection
    }

    *reg |= temp;

    va_end(ptr);
}
int main()
{
    unsigned int reg = 0;
    set_bits(&reg, 2, 0, 1);
    printf("%d", reg);
}

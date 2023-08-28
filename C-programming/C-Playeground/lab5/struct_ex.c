#include <stdio.h>
#include <stdlib.h>
typedef unsigned char u8_t;

u8_t and (u8_t x, u8_t y)
{
    return x & y;
}

u8_t or (u8_t x, u8_t y)
{
    return x | y;
}
u8_t xor (u8_t x, u8_t y) {
    return x ^ y;
}

    u8_t nand(u8_t x, u8_t y)
{
    return !(x & y);
}
u8_t (*ConditionFunction[4])(u8_t x, u8_t y) = { and, or, xor, nand};

struct condition
{
    u8_t x : 1;
    u8_t y : 1;
    u8_t operator: 2;
};

struct logical
{
    struct condition *c1;
    struct condition *c2;
    u8_t operator: 2;
};
u8_t conditionEvaluate(struct condition *conditionPtr)
{

    /* poiinter to function implementation */
    return ConditionFunction[conditionPtr->operator](conditionPtr->x,conditionPtr->y);
    /* switch case implementation */
    // switch(conditionPtr->operator)
    // {
    //     case 0: result = conditionPtr->x & conditionPtr->y;break;
    //     case 1:result = conditionPtr->x | conditionPtr->y;break;
    //     case 2:result = conditionPtr->x ^ conditionPtr->y;break;
    //     case 3:result = !(conditionPtr->x & conditionPtr->y);break;
    //     default:

    // }
}

u8_t logicalExpressionEvaluate(struct logical *logicalPtr)
{
     return ConditionFunction[logicalPtr->operator](conditionEvaluate(logicalPtr->c1),conditionEvaluate(logicalPtr->c2));
}

int main()
{
     struct condition *conditionPtr = NULL;
     conditionPtr = (struct condition *)malloc(sizeof(struct condition));
     conditionPtr->x = 0;
     conditionPtr->y = 1;
     conditionPtr->operator= 1;
     printf("%d", conditionEvaluate(conditionPtr));
}

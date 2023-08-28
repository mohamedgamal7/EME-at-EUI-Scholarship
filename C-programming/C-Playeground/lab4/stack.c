#include <stdio.h>

struct stackNode
{
    char data;                 // define data as an int
    struct stackNode *nextPtr; // stackNode pointer
};

typedef struct stackNode StackNode; // synonym for struct stackNode
typedef StackNode *StackNodePtr;    // synonym for StackNode*

void convertToPostfix(char infix[], char postfix[])
{
}
int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^') ? (1) : (0);
}
int precedence(char operator1, char operator2)
{
    const char operators[] = " +-*/^%";
    const int precedenceLevels[] = {1, 1, 2, 2, 2};
    int index1 = -1;
    int index2 = -1;
    for (int i = 0; i < sizeof(operators) - 1; ++i)
    {
        if (operator1 == operators[i])
        {
            index1 = i;
        }
        if (operator2 == operators[i])
        {
            index2 = i;
        }
    }

    // If either operator is not found, return an error value
    if (index1 == -1 || index2 == -1)
    {
        return -2; // Indicates error
    }

    // Compare the precedence levels and return the appropriate value
    if (precedenceLevels[index1] < precedenceLevels[index2])
    {
        return -1; // operator1 has lower precedence
    }
    else if (precedenceLevels[index1] > precedenceLevels[index2])
    {
        return 1; // operator1 has higher precedence
    }
    else
    {
        return 0; // operator1 and operator2 have equal precedence
    }
}

void push(StackNodePtr *topPtr, char value)
{
    StackNodePtr newPtr = malloc(sizeof(StackNode));

    // insert the node at stack top
    if (newPtr != NULL)
    {
        newPtr->data = value;
        newPtr->nextPtr = *topPtr;
        *topPtr = newPtr;
    }
    else
    { // no space available
        printf("%d not inserted. No memory available.\n", value);
    }
}
char pop(StackNodePtr *topPtr)
{
    StackNodePtr tempPtr = *topPtr;
    int popValue = (*topPtr)->data;
    *topPtr = (*topPtr)->nextPtr;
    free(tempPtr);
    return popValue;
}
char stackTop(StackNodePtr topPtr)
{
    if (topPtr != NULL)
        return topPtr->data;
    else
        return '\0';
}

void printStack(StackNodePtr currentPtr)
{
    // if stack is empty
    if (currentPtr == NULL)
    {
        puts("The stack is empty.\n");
    }
    else
    {
        puts("The stack is:");

        // while not the end of the stack
        while (currentPtr != NULL)
        {
            printf("%d --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }

        puts("NULL\n");
    }
}

int isEmpty(StackNodePtr topPtr)
{
    return topPtr == NULL;
}

int main()
{
    StackNodePtr topPtr = NULL;
    push(topPtr, '(');
    char infix[100];
    gets(infix);
    infix[strlen(infix) + 1] = ')';

   for(int i = 0 ; i <)
    {
    }
}
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

// self-referential structure
struct listNode
{
    char data;                // each listNode contains a character
    struct listNode *nextPtr; // pointer to next node
};

typedef struct listNode ListNode; // synonym for struct listNode
typedef ListNode *ListNodePtr;    // synonym for ListNode*

// prototypes
void insert(ListNodePtr *sPtr, char value);
char delete(ListNodePtr *sPtr, char value);
int isEmpty(ListNodePtr sPtr);
void printList(ListNodePtr currentPtr);
void instructions(void);

// display program instructions to user
void instructions(void)
{
    puts("Enter your choice:\n"
         "   1 to insert an element into the list.\n"
         "   2 to delete an element from the list.\n"
         "   3 to end.");
}

// insert a new value into the list in sorted order
void insert(ListNodePtr *sPtr, char value)
{
    ListNodePtr newPtr = malloc(sizeof(ListNode)); // create node

    if (newPtr != NULL)
    {                           // is space available
        newPtr->data = value;   // place value in node
        newPtr->nextPtr = NULL; // node does not link to another node

        ListNodePtr previousPtr = NULL;
        ListNodePtr currentPtr = *sPtr;

        // loop to find the correct location in the list
        while (currentPtr != NULL && value > currentPtr->data)
        {
            previousPtr = currentPtr;         // walk to ...
            currentPtr = currentPtr->nextPtr; // ... next node
        }

        // insert new node at beginning of list
        if (previousPtr == NULL)
        {
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        }
        else
        { // insert new node between previousPtr and currentPtr
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    }
    else
    {
        printf("%c not inserted. No memory available.\n", value);
    }
}

// delete a list element
char delete(ListNodePtr *sPtr, char value)
{
    // delete first node if a match is found
    if (value == (*sPtr)->data)
    {
        ListNodePtr tempPtr = *sPtr; // hold onto node being removed
        *sPtr = (*sPtr)->nextPtr;    // de-thread the node
        free(tempPtr);               // free the de-threaded node
        return value;
    }
    else
    {
        ListNodePtr previousPtr = *sPtr;
        ListNodePtr currentPtr = (*sPtr)->nextPtr;

        // loop to find the correct location in the list
        while (currentPtr != NULL && currentPtr->data != value)
        {
            previousPtr = currentPtr;         // walk to ...
            currentPtr = currentPtr->nextPtr; // ... next node
        }

        // delete node at currentPtr
        if (currentPtr != NULL)
        {
            ListNodePtr tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            free(tempPtr);
            return value;
        }
    }

    return '\0';
}

// return 1 if the list is empty, 0 otherwise
int isEmpty(ListNodePtr sPtr)
{
    return sPtr == NULL;
}

// print the list
void printList(ListNodePtr currentPtr)
{
    // if list is empty
    if (isEmpty(currentPtr))
    {
        puts("List is empty.\n");
    }
    else
    {
        puts("The list is:");

        // while not the end of the list
        while (currentPtr != NULL)
        {
            printf("%c --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }

        puts("NULL\n");
    }
}

unsigned int GetLength(ListNodePtr currentPtr)
{
    // if list is empty
    if (isEmpty(currentPtr))
    {
        return 0;
    }
    else
    {
        unsigned int count = 0;
        // while not the end of the list
        while (currentPtr != NULL)
        {
            count++;
            currentPtr = currentPtr->nextPtr;
        }
        return count;
    }
}

char GetMiddleElement(ListNodePtr currentPtr)
{
    int i = 0;
    int length = GetLength(currentPtr);

    while (i < length / 2)
    {
        currentPtr = currentPtr->nextPtr;
        i++;
    }
    return (currentPtr != NULL) ? (currentPtr->data) : (-1);
}

void GetMiddleBetter(ListNodePtr currentPtr)
{

    ListNodePtr slow, fast;
    slow = fast = currentPtr;
    while (fast != NULL && fast->nextPtr != NULL)
    {
        fast = fast->nextPtr->nextPtr;
        slow = slow->nextPtr;
    }
    printf("mid : %d", slow->data);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    ListNodePtr startnode = NULL;
    for (int i = 0; i < size; i++)
    {
        insert(&startnode, (char)arr[i]);
    }
    GetMiddleBetter(startnode);
}
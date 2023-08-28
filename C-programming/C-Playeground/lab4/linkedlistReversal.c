#include <stdio.h>

// Link list node
struct Node
{
    int data;
    struct Node *next;
};

void insert(struct Node **head_ref,
            int new_data)
{
    // Allocate node
    struct Node *new_node =
        (struct Node *)malloc(sizeof(struct Node));
    if (new_node != NULL)
    {
        // Put in the data
        new_node->data = new_data;

        // Link the old list of the new node
        new_node->next = NULL;

        // Move the head to point to the new node
        (*head_ref) = new_node;
    }
}

// A utility function to print a given
//  linked list
void printList(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
}

// Iterative C program to reverse a linked list
#include <stdio.h>
#include <stdlib.h>

/* Link list node */
struct Node
{
    int data;
    struct Node *next;
};

/* Function to reverse the linked list */
static void reverse(struct Node **head_ref)
{
    struct Node *prev = NULL;
    struct Node *current = *head_ref;
    struct Node *next = NULL;
    while (current != NULL)
    {
        // Store next
        next = current->next;

        // Reverse current node's pointer
        current->next = prev;

        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

// Driver code
int main()
{
    // Start with the empty list
    struct Node *head = NULL;
    int i;

    for (i = 5; i > 0; i--)
    {
        insert(&head, i);
        printList(head);
    }
    return 0;
}
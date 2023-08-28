#include <stdio.h>

#include <stdio.h>

// Link list node
struct Node
{
    int data;
    struct Node *next;
};

struct Node *pushFront(struct Node **head_ref, int new_data)
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

struct Node *insertAt(struct Node *head, int data, int position)
{
}

int main()
{
}
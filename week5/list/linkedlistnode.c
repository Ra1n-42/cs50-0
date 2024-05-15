#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if 0
    Inserting and Unloading a Linked List

1.  TODO: implement code to add a node to linkedlist.
    Ensure that list always points to the head of the linked list.
    Also ensure your new node contains a phrase.
2.  TODO: implement unload such that all nodes in the linked
    list are free'd when the function is called.Return true when
    successfull.
#endif

typedef struct node
{
    string phrase;
    struct node *next;
}
node;

#define LIST_SIZE 2

bool unload(node *list);
void visualizer(node *list);

int main(void)
{
    node *list = NULL;

    // Add items to list
    for (int i = 0; i < LIST_SIZE; i++)
    {
        string phrase = get_string("Enter a new phrase: ");

        // TODO: add phrase to new node in list

        // create new node with name of n and malloc the size of node
        node *n = malloc(sizeof(node));

        // if node is empty return 1
        if (n == NULL)
        {
            return 1;
        }
        // set n node.phrase to phrase
        n->phrase = phrase;
        // set n node.next to NULL
        n->next = NULL;

        // 
        n->next = list;
        list = n;

        // Visualize list after adding a node.
        visualizer(list);
    }

    // Free all memory used
    if (!unload(list))
    {
        printf("Error freeing the list.\n");
        return 1;
    }

    printf("Freed the list.\n");
    return 0;
}

bool unload(node *list)
{
    // TODO: Free all allocated nodes
    node *ptr = list; // copy list node with pointer(ptr)

    // do loop, while there is no more pointer to list->next
    while (ptr != NULL)
    {
        // ptr equals what list node in next
        ptr = list->next;
        // free memory on list
        free(list);
        // list equals pointer of list->next
        list = ptr;
    }

    return true;
}

void visualizer(node *list)
{
    printf("\n+-- List Visualizer --+\n\n");
    while (list != NULL)
    {
        printf("Location %p\nPhrase: \"%s\"\nNext: %p\n\n", list, list->phrase, list->next);
        list = list->next;
    }
    printf("+---------------------+\n\n");
}

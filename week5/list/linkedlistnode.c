#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

typedef struct node
{
    string phrase;
    struct node *next;
} node;



int main(void)
{
    node *list = NULL;

    node *n = malloc(sizeof(node));

    n->phrase = "Hi!";
    n->next = NULL;
    list = n;

    printf("%s\n", *list[0]);

    return 0;
}

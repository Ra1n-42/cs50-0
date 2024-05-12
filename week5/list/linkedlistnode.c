#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char *phrase;
    struct node *next;
} node;



int main(void)
{
    node *list = NULL;

    node *n = malloc(sizeof(node));

    n->phrase = "Hi!";
    n->next = NULL;
    list = n;

    printf("%s\n", list[0]);

}

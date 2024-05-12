#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#if 0
    Hashing

    TODO: complete hash to return a number, 0-25, depending on
    the first character in the word.
#endif


typedef struct node
{
    string phrase;
    struct node *next;
}
node;

node *table[26];

int hash(string phrase);
bool unload(node *list);
void visualizer(node *list);

int main(void)
{
    // Add items
    for (int i = 0; i < 3; i++)
    {
        string phrase = get_string("Enter a new phrase: ");

        // Find phrase bucket
        int bucket = hash(phrase);
        printf("%s hashes to %i\n", phrase, bucket);
    }
}

// TODO: return the correct bucket for a given phrase
int hash(string phrase)
{
    // take the first letter, upper it and calc by 'A'
    return toupper(phrase[0]) - 'A';
}

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string phrase = get_string("Enter a phrase: ");

    for( int i = 0, length = strlen(phrase); i < length; i++)
    {
        printf("%i ", phrase[i]);
    }
    printf("\n");
}

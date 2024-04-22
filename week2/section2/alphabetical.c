#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string phrase = get_string("Enter a phrase: ");

    for( int i = 0, length = strlen(phrase) - 1; i < length; i++)
    {
        // check if character are not alphabetical
        if (phrase[i] > phrase[i + 1])
        {
            printf("Not in alphabetical order.\n");
            return 0;
        }
        else
        {
            printf("string is in alphabetical order.\n");
            return 0;
        }
    }
    printf("\n");
}

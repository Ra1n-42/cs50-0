#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    // if only 1 argument
    if (argc != 2)
    {
        for (int i = 0; argv[1][i] != '\0'; i++)
        {
            if (!isdigit((unsigned char)argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int k = atoi(argv[1]);
    string text = "abc";
    printf("%i", k);
    printf("\n");
}

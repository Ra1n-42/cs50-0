#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int k = atoi(argv[1]);
    string text = "abc";
    printf("%i", k);

    // int len = strlen(text);
    // for (int i = 0; i < len; i++)
    // {
    //     printf("%c", text[i] + k);
    // }
    printf("\n");
}

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
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else{
        string text = argv[1];
        int len = strlen(text);
        for (int i = 0; i < len; i++)
        {
            if(!isdigit(text[i])){
                printf("Usage: ./caesar key\n");
                return 1;
            }
            printf("%c\n", text[i]);
        }
    }
}

bool is_valid_

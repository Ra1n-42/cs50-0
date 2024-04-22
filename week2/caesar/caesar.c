#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool only_digits(string s);

int main(int argc, string argv[])
{
    // if only 1 argument
    if (argc != 2 && !only_digits(argv[1]))
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

bool only_digits(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
        {
            if(!isdigit(s[i])){
                return false;
            }
        }
    return true;
}

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool only_digits(string s);

int main(int argc, string argv[])
{
    // take the second argument
    string text = argv[1];

    // if only 1 argument
    if (argc != 2 || !only_digits(text))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    printf("%s\n", text);

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

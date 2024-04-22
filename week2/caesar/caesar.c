#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool only_digits(string s);
void cypher_text(int k, string text);


int main(int argc, string argv[])
{
    // take the second argument
    string argument2 = argv[1];

    // if only 1 argument
    if (argc != 2 || !only_digits(argument2))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int k = atoi(argument2);
    string p = get_string("plaintext: ");
    cypher_text(k, p);

}

void cypher_text(int k, string text)
{
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        text[i] = text[i] + k;
        printf("%c\n", text[i]);
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

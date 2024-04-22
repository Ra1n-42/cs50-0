#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Input: ");
    printf("Output: ");

    // wrong way to do: strlen in expression is everytime executed
    // (int i = 0; i < strlen(s); i++)
    // right way: n = strlen(s) is in the initialisation 
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");

}

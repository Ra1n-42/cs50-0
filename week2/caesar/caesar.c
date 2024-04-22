#include <cs50.h>
#include <stdio.h>
#include <string.h>



int main(int argc, string argv[])
{
    int k = (int) argv[1];
    string text = "abc";

    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        printf("%c",text[i] + k);
    }

    printf("\n");
}

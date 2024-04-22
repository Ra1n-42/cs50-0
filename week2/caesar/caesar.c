#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int k = 1;
    string p = "abc";
    for (int i = 0, len = strlen(p); i < len; i++)
    {
        printf("%c", p[i] + k);
    }
    printf("\n");
}

char cipher 

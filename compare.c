#include <cs50.h>
#include <stdio.h>

int main(void){
    int x = get_int("What's is x? ");
    int y = get_int("What's is y? ");
    if (x < y)
    {
        printf("x is less than y\n");
    }
}

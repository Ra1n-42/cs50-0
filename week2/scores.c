#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int top = 3
    int scores[top];
    for (int i =0; i < top; i++)
    {
        scores[i] = get_int("Score: ")
    }


    printf("Average: %f\n",(scores[0] + scores[1] + scores[2]) / 3.0);
}

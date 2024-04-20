#include <cs50.h>
#include <stdio.h>

void print_pyramide(int space, int bricks);

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1);
    for (int i = 0; i < n; i++)
    {
        // Print row of bricks
        print_pyramide(n ,i + 1);
    }
}

void print_pyramide(int space, int bricks)
{
    string s;
    for (int i = 0; i < bricks; i++)
    {

       printf("%.*s",bricks,"#");
    }

    printf("\n");
}

#include <stdio.h>
#include <cs50.h>


int add(int x, int y);

int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");

    int result = add(x, y);

    printf("%i\n", result);
}

int add(int x, int y)
{
    return x + y;
}

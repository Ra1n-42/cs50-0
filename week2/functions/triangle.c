#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>

bool valid_triangle(int a, int b, int c);
int add_two(int x, int y);


int main(void)
{
    int side_a = 1;
    int side_b = 2;
    int side_c = 5;

    printf("%d\n", valid_triangle(side_a, side_b, side_c));
}


bool valid_triangle(int a, int b, int c)
{
    if (a < 1 || b < 1 || c < 1 )
    {
        printf("sides should not be negative or zero\n");
        return false;
    }
    else
    {
        return add_two(a, b) > c || add_two(c, b) > a || add_two(a , c) > b;
    }
}


int add_two(int x, int y)
{
    return x + y;
}

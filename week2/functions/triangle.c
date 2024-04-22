#include <cs50.h>
#include <stdio.h>

bool valid_triangle(int a, int b, int c);

int main(void)
{
    int side_a = 1;
    int side_b = 2;
    int side_c = 4;

    printf("%c\n", valid_triangle(side_a, side_b, side_c));
}


bool valid_triangle(int a, int b, int c)
{
    if (a < 1 || b < 1 || c < 1 )
    {
        return false;
    }
    return a + b > c || b + c > a || a + c > b ;
}

#include <cs50.h>
#include <stdio.h>

int main(void)
{

}


bool valid_triangle(int a, int b, int c)
{
    if (a < 1 || b < 1 || c < 1 || )
    {
        return false;
    }
    return a + b > c || b + c > a || a + c > b ;
}

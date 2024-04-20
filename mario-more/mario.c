#include <cs50.h>
#include <stdio.h>

void print_pyramid(int bricks);

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1);

    print_pyramid(n + 1);

}

void print_pyramid(int bricks) {
    // rows
    string s;
    for (int i = 1; i <= bricks; i++) {
        for (int j = 0; i < bricks-i; j += i)
        {
            s += " ";
        }
        s += "#";
        printf("%s",s)
        printf("\n");
    }
}

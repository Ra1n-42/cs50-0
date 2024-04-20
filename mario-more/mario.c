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

    print_pyramid(n);

}

void print_pyramid(int bricks) {
    for (int i = 0; i <= bricks; i++) {
        // space to hash
        for (int j = 0; j < bricks - i; j++) {
            printf(" ");
        }
        // left side pyramid
        for (int j = 0; j < i; j++) {
            printf("#");
        }
        // gap
        printf("  ");
        // right side pyramid
        for (int j = 0; j < i; j++) {
            printf("#");
        }
        printf("\n");
    }
}

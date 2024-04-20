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
    for (int i = 1; i <= bricks; i++) {
        // Leerzeichen für die Ausrichtung drucken
        for (int j = 0; j < bricks - i; j++) {
            printf(" ");
        }
        // Steine für die Pyramide drucken
        for (int j = 0; j < 2 * i - 1; j++) {
            printf("#");
        }
        printf("\n");
    }
}

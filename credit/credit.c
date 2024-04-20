#include <cs50.h>
#include <stdio.h>
#include <math.h>

int count_digits(long num);

int main(void)
{
    // int number = get_int("Number: ");
    long card = 4111111123456789;
    int digit_count = count_digits(card);
    printf("Die maximale Anzahl der Ziffern in der Zahl %ld ist: %d\n", card, digit_count);
}


int count_digits(long num) {
    int count = 0;
    while (num != 0) {
        num = num / 10;
        count++;
    }
    return count;
}

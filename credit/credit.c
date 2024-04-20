#include <cs50.h>
#include <stdio.h>
#include <math.h>

int count_digits(long num);

int main(void)
{
    // int number = get_long("Number: ");
    long card = 4111111123456789;

    // let’s first underline every other digit, starting with the number’s second-to-last digit
    // let’s multiply each of the underlined digits by 2
    // Now let’s add those products’ digits (i.e., not the products themselves) together
    // Now let’s add that sum (13) to the sum of the digits that weren’t multiplied by 2 (starting from the end)
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

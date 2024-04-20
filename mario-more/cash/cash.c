#include <stdio.h>
#include <cs50.h>

int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Prompt the user for change owed, in cents
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);
    // Calculate how many quarters you should give customer
    int quaters = calculate_quarters(cents);
    // Subtract the value of those quarters from cents
    cents -= quaters * 25;
    // Calculate how many dimes you should give customer
    int dimes = calculate_dimes(cents);
    // Subtract the value of those dimes from remaining cents
    cents -= dimes * 10;
    // Calculate how many nickels you should give customer
    int nickels = calculate_nickels(cents);
    // Subtract the value of those nickels from remaining cents
    cents -= nickels * 5;
    // Calculate how many pennies you should give customer
    int pennies = calculate_pennies(cents);
    // Subtract the value of those pennies from remaining cents
    cents -= pennies;
    // Sum the number of quarters, dimes, nickels, and pennies used
    int sum = dimes + nickels + pennies;
    // Print that sum
    printf("%d \n",sum);


}


int calculate_quarters(int cents)
{
    // Calculate how many quarters you should give customer
    int quarters = 0;
    if (cents == 25)
    {
        return 1;
    }
    while (cents >= 25)
    {
        quarters++;
        cents = cents - 25;
    }
    return quarters;
}

int calculate_dimes(int cents)
{
    // Calculate how many dimes you should give customer
    int dimes = 0;
    if (cents == 10)
    {
        return 1;
    }
    while (cents >= 10)
    {
        dimes++;
        cents = cents - 10;
    }
    return dimes;
}

int calculate_nickels(int cents)
{
    // Calculate how many nickels you should give customer
    int nickels = 0;
    if (cents == 5)
    {
        return 1;
    }
    while (cents >= 5)
    {
        nickels++;
        cents = cents - 5;
    }
    return nickels;
}

int calculate_pennies(int cents)
{
    // Calculate how many pennies you should give customer
    int pennies = 0;
    while (cents >= 1)
    {
        pennies++;
        cents = cents - 1;
    }
    return pennies;
}

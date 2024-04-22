#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    /*

        O(log sub n)

        In Psudecode:
        repeat, until the (sub)array is of size 0:
        * calculate the middle point of the current (sub)array.
        * if target is at the middle, stop.
        * otherwise, if target is less than whats at the middle, repeat,
        changing the end point to be just to the left od the middle.
        * otherwise, if the target is greather than wats at the middle,
        repeat, changing the start point to be just of the right of the middle.
    */

    string person[] = {"Lea", "Johnson", "Eli", "Carter", "Emily"};
    string name = get_string("Name: ");

    int person_count = 5;

    // iterating from left to right
    for (int i = 0; i < person_count; i++)
    {
        // comparing every single element
        if (strcmp(person[i], name) == 0)
        {
            printf("Person %s found.\n", name);
            return 0;
        }
    }
    printf("Person %s not found.\n", name);
    return 1;
}

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    /*

        O(n)

        In Psudecode:
        repeat, start at the first element
        if the firste lement ist what you are looking for (target), stop.
        Otherwise, move to the next element.
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

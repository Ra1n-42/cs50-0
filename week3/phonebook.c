#include <cs50.h>
#include <stdio.h>
#include <string.h>


typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    // string names[] = {"Carter", "David", "John"};
    // string numbers[] = {"+1-617-495-1000", "+1-617-495-1000", "+1-949-468-2750"};

    person people[3];
    string name = get_string("Name: ");

    for (int i = 0; i < 3; i++)
    {
        if (strcmp(names[i], name)==0)
        {
            printf("Found %s\n", numbers[i]);
            return 0;
        }
    }
    printf("not found\n");
    return 1;
}

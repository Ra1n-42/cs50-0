#include <cs50.h>
#include <stdio.h>
#include <string.h>


int array_len(int b);

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

    // unsorted list (duh!) 15 elements (LIST MUST BE SORTED)
    int numbers[] = {11, 23, 8, 14, 30, 9, 6, 17, 22, 28, 25, 15, 7, 10, 19};

    // to searched number
    int target = 19;

    // search settings
    int start = 0;
    int end = sizeof(numbers) / sizeof(numbers[0]);
    int middle = end / 2;

    // first sort array
    for (int i =0; i < end; i++)
    {
        int current = numbers[i];
        int next = numbers[i + 1];
        if (current > next)
        {
            // swap numbers
            numbers[i] = next;
            numbers[i + 1] = current;

        }
        printf("%d\n", numbers[i]);
    }
}


int linear_sort(int a[])
{

}

#include <cs50.h>
#include <stdio.h>
#include <string.h>


void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);
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

    printf("Unsorted array: \n");
    for (int i = 0; i < end; i++)
        printf("%d ", numbers[i]);
    printf("\n");

    mergeSort(numbers, 0, end - 1);

    printf("sorted array: \n");
    for (int i = 0; i < end; i++)
        printf("%d ", numbers[i]);
    printf("\n");
}


// Merge-Sort-Funktion
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Finden des Mittelpunkts
        int m = l + (r - l) / 2;

        // Sortieren des ersten und zweiten Halbfeldes
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Zusammenführen der sortierten Halbfelder
        merge(arr, l, m, r);
    }
}

// Merge-Funktion, um zwei sortierte Arrays zusammenzuführen
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Temporäre Arrays
    int L[n1], R[n2];

    // Kopiere Daten in temporäre Arrays L[] und R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Zusammenführen der temporären Arrays in arr[l..r]
    i = 0; // Initialisierung des Index für das erste Unterray
    j = 0; // Initialisierung des Index für das zweite Unterray
    k = l; // Initialisierung des Index für das zusammengeführte Unterray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Kopiere die restlichen Elemente von L[], falls vorhanden
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Kopiere die restlichen Elemente von R[], falls vorhanden
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

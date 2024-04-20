#include <cs50.h>
#include <stdio.h>


int get_first_digit(long number);
int get_first_two_digits(long number);

int main(void){
    long num;
    do{
        num = get_long("Number: ");
    }
    while (num < 1);


    long temp = num; // Eine temporäre Variable, um die ursprüngliche Zahl nicht zu ändern
    int digit_count = 0;
    int sum = 0;

    // Schleife, um nacheinander jede Ziffer zu betrachten
    while (temp > 0) {
        int digit = temp % 10; // Die aktuelle Ziffer extrahieren
        digit_count++; // Die Anzahl der Ziffern erhöhen
        if (digit_count % 2 == 0) { // Überprüfen, ob die Ziffer an einer "jede zweite von hinten" Position ist
            digit *= 2; // Verdopple die Ziffer
            if (digit > 9) { // Wenn das Ergebnis zweistellig ist, addiere die Ziffern dieses Ergebnisses
                digit = digit / 10 + digit % 10;
            }
        }
        sum += digit; // Summiere die Ziffer auf
        temp = temp / 10; // Die aktuelle Ziffer entfernen, um zur nächsten Ziffer zu gelangen
    }


    if (sum % 10 != 0 || digit_count < 13 || digit_count > 16) { // Überprüfe, ob die Summe durch 10 ohne Rest teilbar ist
        printf("INVALID\n");
    }
    else{

        // card identification: American Express uses 15-digit numbers, MasterCard uses 16-digit numbers, and Visa uses 13- and 16-digit numbers.
        // All American Express numbers start with 34 or 37; most MasterCard numbers start with 51, 52, 53, 54, or 55 and all Visa numbers start with 4.

        int first_two =  get_first_two_digits(num);
        int first = get_first_digit(num);

        if (digit_count == 13 || digit_count == 16 ){
            if ( first==4 ){
                printf("VISA\n");
            }
        }
        if (digit_count == 16){
            if ( first_two == 34 || first_two == 37 || first_two == 22 || first_two == 55 || first_two == 51){
                printf("MASTERCARD\n");
            }
        }
        if (digit_count == 15){
            if ( first_two == 51 || first_two == 52 || first_two == 53 || first_two == 54 || first_two == 55 ){
                printf("American Express.\n");
            }
        }
        if (digit_count == 15){
            if ( first_two == 37 || first_two == 52 || first_two == 53 || first_two == 54 || first_two == 55 ){
                printf("American Express.\n");
            }
        }
    }

}

int get_first_digit(long number) {
    while (number >= 10) {
        number /= 10;
    }
    return number;
}
int get_first_two_digits(long number) {
    while (number >= 100) {
        number /= 10;
    }
    return number;
}

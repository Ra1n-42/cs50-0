#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

bool only_digits(string s);
char rotate(char c, int n);
void encrypt(string plaintext, int key);

int main(int argc, string argv[])
{
    // Überprüfe, ob genau 1 Argument gegeben ist und ob es nur aus Ziffern besteht
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Konvertiere das Argument in eine ganze Zahl (den Schlüssel)
    int key = atoi(argv[1]);

    // Lese den Klartext vom Benutzer ein
    string plaintext = get_string("plaintext: ");

    // Verschlüssele und gib den Klartext aus
    encrypt(plaintext, key);

    return 0;
}

void encrypt(string plaintext, int key)
{
    printf("ciphertext: ");
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        char encrypted_char = rotate(plaintext[i], key);
        printf("%c", encrypted_char);
    }
    printf("\n");
}

char rotate(char c, int n)
{
    if (isalpha(c))
    {
        // Prüfe, ob der Buchstabe ein Kleinbuchstabe ist
        if (islower(c))
        {
            return 'a' + (c - 'a' + n) % 26;
        }
        // Prüfe, ob der Buchstabe ein Großbuchstabe ist
        else if (isupper(c))
        {
            return 'A' + (c - 'A' + n) % 26;
        }
    }
    // Wenn c kein Buchstabe ist, gib c unverändert zurück
    return c;
}

bool only_digits(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

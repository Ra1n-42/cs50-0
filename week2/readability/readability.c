#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    // int words = count_words(text);
    // int sentences = count_sentences(text);

    // Compute the Coleman-Liau index

    printf("%d,\n", letters);

    // Print the grade level
}

int count_letters(string text)
{
    // Return the number of letters in text
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        printf("%c\n", text[i]);
    }

    return 1;
}

int count_words(string text)
{
    // Return the number of words in text
    return 1;
}

int count_sentences(string text)
{
    // Return the number of sentences in text
    return 1;
}

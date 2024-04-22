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
    int words = count_words(text);
    // int sentences = count_sentences(text);

    // Compute the Coleman-Liau index

    printf("%d lettes count\n", letters);

    // Print the grade level
}

int count_letters(string text)
{
    int letters_count = 0;
    // Return the number of letters in text
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        // printf("%c is ",text[i]);
        if (isalpha(text[i]) == 0)
        {
            // printf("not");
        }
        else{
            letters_count ++;
            // printf("a");
        }
        // printf(" letter\n");
    }

    return letters_count;
}

int count_words(string text)
{
    int words_count = 0;
    // Return the number of words in text
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        // letter found
        if (isalpha(text[i]) != 0)
        {

        }
        // space found
        else if (isspace(text[i]) !=0)
        {

        }
    }
    return words_count;
}

int count_sentences(string text)
{
    // Return the number of sentences in text
    return 1;
}

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
    int sentences = count_sentences(text);

    // Compute the Coleman-Liau index

    printf("%d sentences count\n", sentences);

    // Print the grade level
}

int count_letters(string text)
{
    int letters_count = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {

        if ((text[i] == '.') || (text[i] == '!') || (text[i]=='?'))
        {
            letters_count ++;
        }
    }

    return letters_count;
}

int count_words(string text)
{
    int words_count = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        // space found
        if (isspace(text[i]) != 0)
        {
            words_count++;
        }
    }
    return words_count + 1;
}

int count_sentences(string text)
{
    int sentence_count = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (ispunct(text[i])) {
            sentence_count ++;
        }
    }
    return sentence_count;
}

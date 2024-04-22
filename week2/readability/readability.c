#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
float coleman_liau_index(float L, float S);
float rounding_up(float x);


int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float L = (float) letters / words * 100;/*  the number of letters divided by the number of words, all multiplied by 100. */
    float S = (float) sentences / words *100;/* the number of sentences divided by the number of words, all multiplied by 100 */

    // Compute the Coleman-Liau index
    float index = coleman_liau_index(L, S);

    // rounding
    float grade = rounding_up(index);

    if (grade < 1)
    {
        printf("Before Grade 1");
    }
    else if (grade >=16){
        printf("Grade 16+\n");
    }
    else{

        printf("Grade %i\n", (int) grade);
    }

}

float rounding_up(float x)
{
    float fractional_part = x - floor(x);
    if (fractional_part >= 0.5) {
        return ceil(x);
    } else {
        return floor(x);
    }
}
int count_letters(string text)
{
    int letters_count = 0;
    // Return the number of letters in text
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        // letter found
        if (isalpha(text[i]) != 0)
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
    int punctuation_count = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            punctuation_count++;
        }
    }
    return punctuation_count;
}

float coleman_liau_index(float L, float S)
{
    return 0.0588 * L - 0.296 * S - 15.8;
}

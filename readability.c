#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt user for text
    string t = get_string("Text: ");

    // Run function to count letters in words
    float w = count_letters(t);

    // Run function to count words in text
    float y = count_words(t);

    // Run function to count sentences in text
    float z = count_sentences(t);

    // Define L as average number of letters per 100 words
    float L = w / y * 100;

    // Define S as average number of sentences per 100 words
    float S = z / y * 100;

    //Run Coleman-Liau index
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Print number of letters
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
int count_letters(string text)
{
    // Compute and return number of letters in text
    int letters = 0;

    int n;

    // Run function as long as character does not equal null
    for (n = 0; text[n] != 0; n++)
        // If the value is a letter add 1 and store the total
        if (isalpha(text[n]))
        {
            letters = letters + 1;
        }
        else
        {
            letters = letters + 0;
        }
    // Return the total
    return letters;
}
int count_words(string text)
{
    //Compute and return the number of words in the text
    int words = 1;

    int n;

    // Run function as long as character does not equal null
    for (n = 0; text[n] != 0; n++)
        // If the value is a space add 1 word and store the total
        if (isspace(text[n]))
        {
            words = words + 1;
        }
        else
        {
            words = words + 0;
        }
    // Return the total
    return words;
}
int count_sentences(string text)
{
    //Compute and return the number of sentences in the text
    int sents = 0;

    int n;

    // Run function as long as character does not equal null
    for (n = 0; text[n] != 0; n++)
        // If the value is a ., !, or ? add 1 sentence and store the total
        if (((text[n]) == '.') || ((text[n]) == '?') || ((text[n]) == '!'))
        {
            sents = sents + 1;
        }
        else
        {
            sents = sents + 0;
        }
    // Return the total
    return sents;
}

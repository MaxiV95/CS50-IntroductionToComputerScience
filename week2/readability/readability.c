#include <cs50.h>
#include <math.h>
#include <stdio.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float L = ((float) letters / words) * 100.0;
    float S = ((float) sentences / words) * 100.0;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text)
{
    int letters = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (('A' <= text[i] && text[i] <= 'Z') || ('a' <= text[i] && text[i] <= 'z'))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    int words = 1;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ' ' && (text[i + 1] != ' ' && text[i + 1] != '\0'))
        {
            words++;
        }
    }
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}
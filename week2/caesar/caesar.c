#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string word);
char rotate(char character, int n);

int main(int argc, string argv[])
{
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }

    int k = atoi(argv[1]);

    string plaintext = get_string("plaintext:  ");

    printf("ciphertext: ");
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        char encrypted = rotate(plaintext[i], k);
        printf("%c", encrypted);
    }
    printf("\n");
}

bool only_digits(string word)
{
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (!isdigit(word[i]))
        {
            return false;
        }
    }
    return true;
}

char rotate(char character, int n)
{
    if (isupper(character))
    {
        return (char) (((character - 'A' + n) % 26) + 'A');
    }
    else if (islower(character))
    {
        return (char) (((character - 'a' + n) % 26) + 'a');
    }
    else
    {
        return character;
    }
}
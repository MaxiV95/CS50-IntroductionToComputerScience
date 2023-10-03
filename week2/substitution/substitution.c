#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool is_valid_key(string key);
void encrypt(string plaintext, string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (!is_valid_key(argv[1]))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    string plaintext = get_string("plaintext:  ");
    printf("ciphertext: ");
    encrypt(plaintext, argv[1]);
    printf("\n");

    return 0;
}

bool is_valid_key(string key)
{
    int length = strlen(key);

    if (length != 26)
    {
        return false;
    }

    bool used[26] = {false};
    for (int i = 0; i < length; i++)
    {
        char character = key[i];

        if (!isalpha(character))
        {
            return false;
        }

        int index = tolower(character) - 'a';

        if (used[index])
        {
            return false;
        }

        used[index] = true;
    }

    return true;
}

void encrypt(string plaintext, string key)
{
    int length = strlen(plaintext);

    for (int i = 0; i < length; i++)
    {
        char character = plaintext[i];
        char encrypted_char = character;

        if (isalpha(character))
        {
            char base = islower(character) ? 'a' : 'A';
            int index = tolower(character) - 'a';
            encrypted_char = islower(character) ? tolower(key[index]) : toupper(key[index]);
        }

        printf("%c", encrypted_char);
    }
}

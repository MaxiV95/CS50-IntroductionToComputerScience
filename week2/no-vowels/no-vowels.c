// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Enter only one word. \n");
        return 1;
    }

    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        switch (argv[1][i])
        {
            case 'a':
                argv[1][i] = '4';
                break;

            case 'e':
                argv[1][i] = '3';
                break;

            case 'i':
                argv[1][i] = '1';
                break;

            case 'o':
                argv[1][i] = '0';
                break;

            default:
                break;
        }
    }

    printf("%s \n", argv[1]);
}

#include <cs50.h>
#include <stdio.h>

int get_size(void);

int main(void)
{
    int height = get_size();

    for (int i = 0; i < height; i++)
    {
        for (int j = height - i; j > 1; j--)
        {
            printf(" ");
        }

        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }

        printf("\n");
    }
}

int get_size(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (1 > n || n > 8);
    return n;
}
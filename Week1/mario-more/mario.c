#include <cs50.h>
#include <stdio.h>

int get_size(void);
void print_hashes(int n);

int main(void)
{
    int height = get_size();

    for (int i = 0; i < height; i++)
    {
        for (int j = height - i; j > 1; j--)
        {
            printf(" ");
        }

        print_hashes(i);

        printf("  ");

        print_hashes(i);

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

void print_hashes(int n)
{
    for (int k = 0; k <= n; k++)
    {
        printf("#");
    }
}
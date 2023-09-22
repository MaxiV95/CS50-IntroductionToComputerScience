// Abstraction with parameterization

#include <cs50.h>
#include <stdio.h>

int get_size(void);
void meow(int n);

int main(void)
{
    int n = get_size();
    meow(n);
}

int get_size(void)
{
    int n;
    do
    {
        n = get_int("Count: ");
    }
    while (n < 1);
    return n;
}

// Meow some number of times
void meow(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("  Meow %i! \n", i+1);
    }
}
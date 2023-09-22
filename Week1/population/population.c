#include <cs50.h>
#include <stdio.h>

int get_size(string message, int size);

int main(void)
{
    // TODO: Prompt for start size
    int start = get_size("Start", 9);

    // TODO: Prompt for end size
    int end = get_size("End", start);

    // TODO: Calculate number of years until we reach threshold
    int years = 0;
    int current_size = start;

    while (current_size < end)
    {
        current_size = current_size + current_size / 3 - current_size / 4;
        years++;
    }

    // TODO: Print number of years
    printf("Years: %i\n", years);
}

int get_size(string message, int size)
{
    int n;
    do
    {
        n = get_int("%s: ", message);
    }
    while (n < size);
    return n;
}

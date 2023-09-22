#include <cs50.h>
#include <stdio.h>

int calculateDigitsNumber(long cardNumber);
void separateDigits(long cardNumber, int numDigits, int digits[]);
int algorithmHansPeterLuhn(int numDigits, int digits[]);

int main(void)
{
    long cardNumber = get_long("Card number: ");

    int numDigits = calculateDigitsNumber(cardNumber);

    int digits[numDigits];

    separateDigits(cardNumber, numDigits, digits);

    int result = algorithmHansPeterLuhn(numDigits, digits);

    if (result % 10 != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        printf("VISA\n");
    }
}

int calculateDigitsNumber(long cardNumber)
{
    int numDigits = 0;
    while (cardNumber > 0)
    {
        cardNumber /= 10;
        numDigits++;
    }
    return numDigits;
}

void separateDigits(long cardNumber, int numDigits, int digits[])
{
    for (int i = numDigits - 1; i >= 0; i--)
    {
        digits[i] = cardNumber % 10;
        cardNumber /= 10;
    }
}

int algorithmHansPeterLuhn(int numDigits, int digits[])
{
    int multipliedNumbers = 0;
    int summedNumbers = 0;
    for (int j = 0; j < numDigits; j += 2)
    {
        int n = digits[j] * 2;
        multipliedNumbers += n % 10 + n / 10;
        summedNumbers += digits[j + 1];
    }
    return multipliedNumbers + summedNumbers;
}
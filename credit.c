#include <cs50.h>
#include <stdio.h>

int get_length(long number);

int main(void)
{
    // Prompt for input
    long card_number = get_long("Enter valid number: "); // input assigned to variable

    // CALCULATE CHECKSUM

    // select every other digits, starting with the number’s second-to-last digit and multiply by 2
    int d2, d4, d6, d8, d10, d12, d14, d16;
    d2 = ((card_number % 100) / 10) * 2;
    d4 = ((card_number % 10000) / 1000) * 2;
    d6 = ((card_number % 1000000) / 100000) * 2;
    d8 = ((card_number % 100000000) / 10000000) * 2;
    d10 = ((card_number % 10000000000) / 1000000000) * 2;
    d12 = ((card_number % 1000000000000) / 100000000000) * 2;
    d14 = ((card_number % 100000000000000) / 10000000000000) * 2;
    d16 = ((card_number % 10000000000000000) / 1000000000000000) * 2;

    // add those products’ digits together
    d2 = (d2 / 10) + (d2 % 10);
    d4 = (d4 / 10) + (d4 % 10);
    d6 = (d6 / 10) + (d6 % 10);
    d8 = (d8 / 10) + (d8 % 10);
    d10 = (d10 / 10) + (d10 % 10);
    d12 = (d12 / 10) + (d12 % 10);
    d14 = (d14 / 10) + (d14 % 10);
    d16 = (d16 / 10) + (d16 % 10);

    // Sum up the previous digits together
    int sum1 = d2 + d4 + d6 + d8 + d10 + d12 + d14 + d16;

    // select the digits that weren't multiplied
    int d1, d3, d5, d7, d9, d11, d13, d15;
    d1 = card_number % 10;
    d3 = (card_number % 1000) / 100;
    d5 = (card_number % 100000) / 10000;
    d7 = (card_number % 10000000) / 1000000;
    d9 = (card_number % 1000000000) / 100000000;
    d11 = (card_number % 100000000000) / 10000000000;
    d13 = (card_number % 10000000000000) / 1000000000000;
    d15 = (card_number % 1000000000000000) / 100000000000000;

    // Sum up the multiplied numbers and the others
    int sum2 = sum1 + d1 + d3 + d5 + d7 + d9 + d11 + d13 + d15;

    // Final validation for checksum
    if (sum2 % 10 == 0)
    {
        // CHECK TYPE OF CARD

        // Calculate number length
        int length = get_length(card_number);

        if (length == 13) // Is it a VISA ?
        {
            // select first digit
            int digit1 = (card_number % 10000000000000) / 1000000000000;
            // check if first digit is 4
            if (digit1 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (length == 15) // Is it an AMERICAN EXPRESS ?
        {
            // select first two digits
            int digit_one, digit_two;
            digit_one = (card_number % 1000000000000000) / 100000000000000;
            digit_two = (card_number % 100000000000000) / 10000000000000;
            // Check if first two digits are 34 or 37
            if (digit_one == 3 & digit_two == 4 || digit_two == 7)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (length == 16) // Is it a MASTERCARD or VISA?
        {
            // select first two digits
            int digit_uno, digit_dos;
            digit_uno = (card_number % 10000000000000000) / 1000000000000000;
            digit_dos = (card_number % 1000000000000000) / 100000000000000;
            // check if first two digits are 51, 52, 53, 54 or 55 (MASTERCARD)
            if (digit_uno == 5 & digit_dos == 1 || digit_dos == 2 || digit_dos == 3 || digit_dos == 4 || digit_dos == 5)
            {
                printf("MASTERCARD\n");
            }
            // check if first digit is 4 (VISA)
            else if (digit_uno == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

// Calculate number length
int get_length(long number)
{
    // Calculate how many steps for (number % i) to equal number, with i initialized as 1 and multiplied by 10 every step of the way
    int steps;
    for (long i = 1, j = 1; number != (number % i); i *= 10, j++)
    {
        steps = j;
    }
    return steps;
}

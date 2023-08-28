#include <stdio.h>
#include <math.h>

/**
 * largest_prime_factor - finds the largest prime factor of a number
 * @n: the number
 *
 * Return: the largest prime factor
 */
long largest_prime_factor(long n)
{
    long i;

    // Divide by 2 until it's no longer divisible
    while (n % 2 == 0)
    {
        n /= 2;
    }

    // Check for larger prime factors starting from 3
    for (i = 3; i <= sqrt(n); i += 2)
    {
        while (n % i == 0)
        {
            n /= i;
        }
    }

    // If n is still greater than 2, it's the largest prime factor
    if (n > 2)
    {
        return n;
    }

    return i - 2;
}

int main(void)
{
    long number = 612852475143;
    long largest_factor = largest_prime_factor(number);

    printf("%ld\n", largest_factor);

    return 0;
}

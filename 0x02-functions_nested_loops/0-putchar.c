#include "main.h"

/**
 * main -  prints _putchar, followed by a new line
 * Return: Always 0 (Success)
 */

int main(void)
{
    char str[] = "_putchar\n";

    char *ptr = str;
    while (*ptr != '\0')
        _putchar(*ptr++);

    return (0);
}

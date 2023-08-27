#include <stdio.h>
#include <stdlib.h>

int _isdigit(char c)
{
    return c >= '0' && c <= '9';
}

int _strlen(char *str)
{
    int len = 0;
    while (str[len] != '\0')
        len++;
    return len;
}

void _print_error(void)
{
    printf("Error\n");
    exit(98);
}

void _multiply(char *num1, char *num2)
{
    int len1 = _strlen(num1);
    int len2 = _strlen(num2);
    int len_result = len1 + len2;
    int *result = calloc(len_result, sizeof(int));

    if (result == NULL)
        _print_error();

    for (int i = len1 - 1; i >= 0; i--)
    {
        for (int j = len2 - 1; j >= 0; j--)
        {
            int digit1 = num1[i] - '0';
            int digit2 = num2[j] - '0';
            int product = digit1 * digit2;

            int pos1 = i + j;
            int pos2 = i + j + 1;

            product += result[pos2];

            result[pos1] += product / 10;
            result[pos2] = product % 10;
        }
    }

    int non_zero_found = 0;
    for (int i = 0; i < len_result; i++)
    {
        if (result[i] != 0)
            non_zero_found = 1;
        if (non_zero_found)
            printf("%d", result[i]);
    }

    printf("\n");

    free(result);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
        _print_error();

    char *num1 = argv[1];
    char *num2 = argv[2];

    int len1 = _strlen(num1);
    int len2 = _strlen(num2);

    for (int i = 0; i < len1; i++)
    {
        if (!_isdigit(num1[i]))
            _print_error();
    }

    for (int i = 0; i < len2; i++)
    {
        if (!_isdigit(num2[i]))
            _print_error();
    }

    _multiply(num1, num2);

    return 0;
}

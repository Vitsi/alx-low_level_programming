#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: prints the first 50 Fibonacci numbers
 *		starting with 1 and 2 folled by a new line
 *
 * Return: Always 0 (Success)
*/

int fibonacci(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else if (n == 2)
	{
		return 2;
	}
	else
	{
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}
int main()
{
	int n = 50;
	int result = fibonacci(n);
	printf("%d\n", result);
	return (0);
}

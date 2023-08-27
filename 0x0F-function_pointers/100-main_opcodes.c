#include <stdio.h>
#include <stdlib.h>

/**
 * print_opcodes - Prints the opcodes of a given function.
 * @function_address: The starting address of the function.
 * @num_bytes: The number of bytes to print.
 */
void print_opcodes(char *function_address, int num_bytes)
{
	int i;

	for (i = 0; i < num_bytes; i++)
	{
		printf("%02hhx ", function_address[i]);
	}

	printf("\n");
}

/**
 * main - Entry point of the program.
 * @argc: The argument count.
 * @argv: The argument vector.
 *
 * Return: 0 on success, 1 for incorrect number of arguments, 2 for negative bytes.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Error\n");
		return 1;
	}

	int num_bytes = atoi(argv[1]);

	if (num_bytes < 0)
	{
		printf("Error\n");
		return 2;
	}

	print_opcodes((char *)&main, num_bytes);

	return 0;
}

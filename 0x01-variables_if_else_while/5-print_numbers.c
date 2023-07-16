#include<stdio.h>

/**
 * main - Entry point
 *
 * Description: print all single digit numbers
 *
 * Return: Always 0 (Success)
*/

int main(void){
	int n;
	while(n>=0 && n<=9){
			printf("%i",n);
			++n;
	}
		printf("\n");

	return (0);
}

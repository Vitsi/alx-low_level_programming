#include <stdio.h>

/**
 * main - computes and prints the sum of all the multiples
 * of 3 or 5 below 1024
 * Return: Always 0 (Success)
 */
int main(void)
{
	int numT, numF, numB, sum;

	numT=3;
	numF=5;

	numB=1024;
	sum=0;
	
	for(num = 0; num < numB; num++){
		if(num % numT == 0|| num % numF == 0){
			sum += num;
		}
	}

	printf("The sum is %d\n", sum);

	return 0;
}

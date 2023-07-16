#include <stdlib.h>
#include <time.h>
#include <stdout.h>

/*
 * main- entry point
 *
 *description:  number stored in the variable n is positive or negative.
 *
 * return: alwyas 0 (success)
*/
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	/* my code */
	if(n>0){
		printf("%i is positive\n",n)
	}
	else if (n == 0)
		printf("%i is zero\n", n);
	else
		printf("%i is negative\n", n);


	return (0);
}

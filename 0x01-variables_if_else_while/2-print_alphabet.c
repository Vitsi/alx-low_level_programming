#include stdout.h

/**
 * main - Entry point
 *
 * Description: print all aplhabet letters
 *
 * Return: Always 0 (Success)
*/
int (void){
	char ch = 'a';
	while(ch <= 'z'){
		putchar(ch);
		++ch;
	}
	putchar('\n');
	return(0);
}


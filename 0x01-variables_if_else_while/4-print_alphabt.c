#include<stdio.h>

/**
 * main - Entry point
 *
 * Description: print all aplhabet letters except q and e
 *
 * Return: Always 0 (Success)
*/

int main(void){
	char ch='a';
	while(ch<=0){
		if(ch!=q && ch!=e){
			putchar(ch);
			ch++;
		}
		else{
			++ch;
		}
		
	}
	
	putchar('\n');
	return(0);

}

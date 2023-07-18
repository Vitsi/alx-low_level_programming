#include "main.h"

/**
 * main -  prints _putchar, followed by a new line
 * Return: Always 0 (Success)
 */
int main() {
   char str[] = "_putchar";
   int i;

   for(i = 0; str[i] != '\0'; i++) {
      putchar(str[i]);
   }
   putchar('\n');

   return 0;
}

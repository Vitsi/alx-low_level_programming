#ifndef MAIN_H
#define MAIN_H

void *malloc_checked(unsigned int b);
int _putchar(char c);
int *array_range(int min, int max);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_calloc(unsigned int nmemb, unsigned int size);
char *string_nconcat(char *s1, char *s2, unsigned int n);

#endif /* MAIN_H */

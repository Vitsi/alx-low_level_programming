#include "main.h"
#include <stdio.h>
#include <stdlib.h>

void *malloc_checked(unsigned int b)
{
    void *ptr = malloc(b);

    if (ptr == NULL)
    {
        printf("Error: malloc failed\n");
        exit(98);
    }

    return ptr;
}

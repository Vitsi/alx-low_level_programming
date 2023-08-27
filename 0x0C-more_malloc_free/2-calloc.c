#include "main.h"
#include <stdlib.h>

void *_calloc(unsigned int nmemb, unsigned int size)
{
    void *ptr;

    if (nmemb == 0 || size == 0)
        return NULL;

    ptr = calloc(nmemb, size);

    if (ptr == NULL)
        return NULL;

    return ptr;
}

#include "main.h"
#include <stdlib.h>

char *_strdup(char *str)
{
    char *duplicate;
    unsigned int length;
    unsigned int i;

    if (str == NULL)
        return NULL;

    length = 0;
    while (str[length] != '\0')
        length++;

    duplicate = malloc(sizeof(char) * (length + 1));
    if (duplicate == NULL)
        return NULL;

    for (i = 0; i <= length; i++)
        duplicate[i] = str[i];

    return duplicate;
}

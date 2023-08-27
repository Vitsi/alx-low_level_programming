#include "main.h"
#include <stdlib.h>
#include <string.h>

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
    unsigned int len1 = (s1 == NULL) ? 0 : strlen(s1);
    unsigned int len2 = (s2 == NULL) ? 0 : strlen(s2);
    unsigned int concat_len = (n >= len2) ? len1 + len2 : len1 + n;
    char *concat = malloc((concat_len + 1) * sizeof(char));

    if (concat == NULL)
        return NULL;

    if (s1 != NULL)
        strcpy(concat, s1);
    if (n >= len2 || s2 == NULL)
        strcat(concat, (s2 == NULL) ? "" : s2);
    else
        strncat(concat, s2, n);

    return concat;
}

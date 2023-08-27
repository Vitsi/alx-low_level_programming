#include "main.h"
#include <stdlib.h>
#include <stdio.h>

char *argstostr(int ac, char **av)
{
    if (ac == 0 || av == NULL)
        return NULL;

    int total_length = 0;
    int i, j;

    // Calculate the total length of the concatenated string
    for (i = 0; i < ac; i++)
    {
        j = 0;
        while (av[i][j] != '\0')
        {
            total_length++;
            j++;
        }
        total_length++; // Account for the newline character
    }

    // Allocate memory for the concatenated string
    char *concatenated = malloc(sizeof(char) * (total_length + 1));
    if (concatenated == NULL)
        return NULL;

    int index = 0;

    // Copy the arguments into the concatenated string
    for (i = 0; i < ac; i++)
    {
        j = 0;
        while (av[i][j] != '\0')
        {
            concatenated[index] = av[i][j];
            index++;
            j++;
        }
        concatenated[index] = '\n'; // Add the newline character
        index++;
    }

    concatenated[index] = '\0'; // Add the null terminator

    return concatenated;
}

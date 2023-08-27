#include "main.h"
#include <stdlib.h>

char *argstostr(int ac, char **av)
{
    if (ac == 0 || av == NULL)
        return NULL;

    int i, j, total_length = 0, current_index = 0;
    char *result;

    // Calculate the total length of the concatenated string
    for (i = 0; i < ac; i++)
    {
        j = 0;
        while (av[i][j] != '\0')
        {
            total_length++;
            j++;
        }
        total_length++; // Account for the space between arguments
    }

    result = (char *)malloc(sizeof(char) * (total_length + 1));
    if (result == NULL)
        return NULL;

    // Copy the arguments into the concatenated string
    for (i = 0; i < ac; i++)
    {
        j = 0;
        while (av[i][j] != '\0')
        {
            result[current_index] = av[i][j];
            current_index++;
            j++;
        }
        result[current_index] = ' '; // Insert space between arguments
        current_index++;
    }

    result[current_index - 1] = '\0'; // Replace the last space with null terminator

    return result;
}

#include "main.h"
#include <stdlib.h>
#include <stdio.h>

int count_words(char *str);
int word_length(char *str);
char **allocate_memory(int words, int max_word_length);
void free_memory(char **words);

char **strtow(char *str)
{
    if (str == NULL || *str == '\0')
        return NULL;

    int words = count_words(str);
    if (words == 0)
        return NULL;

    char **word_array = allocate_memory(words, word_length(str));
    if (word_array == NULL)
        return NULL;

    int i, j, k;
    int word_index = 0;
    int word_length = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ')
        {
            word_length++;
            if (word_length == 1)
                j = i;
        }
        else if (word_length > 0)
        {
            word_array[word_index] = malloc(sizeof(char) * (word_length + 1));
            if (word_array[word_index] == NULL)
            {
                free_memory(word_array);
                return NULL;
            }

            for (k = 0; k < word_length; k++)
                word_array[word_index][k] = str[j++];

            word_array[word_index][k] = '\0';
            word_index++;
            word_length = 0;
        }
    }

    if (word_length > 0)
    {
        word_array[word_index] = malloc(sizeof(char) * (word_length + 1));
        if (word_array[word_index] == NULL)
        {
            free_memory(word_array);
            return NULL;
        }

        for (k = 0; k < word_length; k++)
            word_array[word_index][k] = str[j++];

        word_array[word_index][k] = '\0';
        word_index++;
    }

    word_array[word_index] = NULL;

    return word_array;
}

int count_words(char *str)
{
    int count = 0;
    int i, word_started = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ' && word_started == 0)
        {
            count++;
            word_started = 1;
        }
        else if (str[i] == ' ')
        {
            word_started = 0;
        }
    }

    return count;
}

int word_length(char *str)
{
    int length = 0;
    int i, word_started = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ' && word_started == 0)
        {
            word_started = 1;
        }
        else if (str[i] == ' ' && word_started == 1)
        {
            break;
        }

        if (word_started == 1)
            length++;
    }

    return length;
}

char **allocate_memory(int words, int max_word_length)
{
    char **word_array = malloc(sizeof(char *) * (words + 1));
    if (word_array == NULL)
        return NULL;

    int i;
    for (i = 0; i < words; i++)
    {
        word_array[i] = malloc(sizeof(char) * (max_word_length + 1));
        if (word_array[i] == NULL)
        {
            free_memory(word_array);
            return NULL;
        }
    }

    return word_array;
}

void free_memory(char **words)
{
    int i;
    for (i = 0; words[i] != NULL; i++)
    {
        free(words[i]);
    }
    free(words);
}

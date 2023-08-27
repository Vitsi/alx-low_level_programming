#include <stdlib.h>
#include "main.h"

int count_words(char *str);
char **allocate_memory(int words);
void free_memory(char **words);
void copy_word(char *src, char *dest);

char **strtow(char *str)
{
    if (str == NULL || *str == '\0')
        return NULL;

    int words = count_words(str);
    if (words == 0)
        return NULL;

    char **word_array = allocate_memory(words);
    if (word_array == NULL)
        return NULL;

    int i, j, word_index = 0;
    int in_word = 0; // Flag to track if we are inside a word
    int word_length = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ')
        {
            if (!in_word)
            {
                in_word = 1;
                word_length = 0;
                j = i;
            }
            word_length++;
        }
        else if (in_word)
        {
            in_word = 0;
            word_array[word_index] = malloc(sizeof(char) * (word_length + 1));
            if (word_array[word_index] == NULL)
            {
                free_memory(word_array);
                return NULL;
            }
            copy_word(&str[j], word_array[word_index]);
            word_index++;
        }
    }

    if (in_word)
    {
        in_word = 0;
        word_array[word_index] = malloc(sizeof(char) * (word_length + 1));
        if (word_array[word_index] == NULL)
        {
            free_memory(word_array);
            return NULL;
        }
        copy_word(&str[j], word_array[word_index]);
        word_index++;
    }

    word_array[word_index] = NULL;

    return word_array;
}

int count_words(char *str)
{
    int count = 0;
    int in_word = 0; // Flag to track if we are inside a word

    while (*str != '\0')
    {
        if (*str != ' ')
        {
            if (!in_word)
            {
                in_word = 1;
                count++;
            }
        }
        else
        {
            in_word = 0;
        }
        str++;
    }

    return count;
}

char **allocate_memory(int words)
{
    char **word_array = malloc(sizeof(char *) * (words + 1));
    if (word_array == NULL)
        return NULL;

    return word_array;
}

void free_memory(char **words)
{
    if (words == NULL)
        return;

    int i;
    for (i = 0; words[i] != NULL; i++)
    {
        free(words[i]);
    }
    free(words);
}

void copy_word(char *src, char *dest)
{
    while (*src != ' ' && *src != '\0')
    {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
}

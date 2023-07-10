/*
** EPITECH PROJECT, 2020
** array_cpy
** File description:
** array_cpy
*/

#include "my.h"

char **my_arraycpy(char const * const *array)
{
    char **new_array = malloc(sizeof(char *) * (array_len(array) + 1));
    char **i = new_array;

    if (!new_array)
        return (NULL);
    for (; *i; ++i, ++array)
        if (!(*i = my_strcpy_m(*array)))
            return (NULL);
    *i = NULL;
    return (new_array);
}

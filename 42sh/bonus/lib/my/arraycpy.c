/*
** EPITECH PROJECT, 2020
** array_cpy
** File description:
** array_cpy
*/

#include "include/my.h"

char **my_arraycpy(char const * const *array)
{
    int nbr_line = count_nbr_line(array);
    char **new_array = malloc(sizeof(char *) * (nbr_line + 1));

    if (new_array == NULL)
        return (NULL);
    for (int y = 0; array[y]; ++y) {
        new_array[y] = my_strcpy_m(array[y]);
        if (!new_array[y])
            return (NULL);
    }
    new_array[nbr_line] = NULL;
    return (new_array);
}

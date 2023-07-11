/*
** EPITECH PROJECT, 2019
** my_strlen_2
** File description:
** my_strlen_2
*/

#include "include/my.h"

int my_3d_array_len(char const * const * const *array)
{
    char const * const * const *i = array;

    for (; *i; ++i);
    return (i - array);
}

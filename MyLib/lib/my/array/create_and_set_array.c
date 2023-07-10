/*
** EPITECH PROJECT, 2019
** create_and_set_array
** File description:
** create_and_set_array
*/

#include "my.h"

char **create_and_set_2d_array(unsigned int len, ...)
{
    char **array = malloc(sizeof(char **) * (len + 1));
    char **i = array;
    va_list list;

    if (!array) return (NULL);
    va_start(list, len);
    for (; len; --len, ++i)
        *i = my_strcpy_m(va_arg(list, char *));
    *i = NULL;
    va_end(list);
    return (array);
}

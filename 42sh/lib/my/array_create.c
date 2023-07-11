/*
** EPITECH PROJECT, 2020
** array_create
** File description:
** array_create
*/

#include "include/my.h"

char **create_2darray(int const len, ...)
{
    va_list str;
    char **array = malloc(sizeof(char *) * (len + 1));
    char *tmp = NULL;

    if (!array) return (NULL);
    va_start(str, len);
    for (int i = 0; i < len; ++i) {
        array[i] = my_strcpy_m(va_arg(str, char const *));
        if (!array[i]) {
            va_end(str);
            return (NULL);
        }
    }
    array[len] = NULL;
    va_end(str);
    return (array);
}

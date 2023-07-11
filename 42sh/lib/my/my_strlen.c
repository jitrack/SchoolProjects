/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** count string
*/

#include "include/my.h"

int my_strlen(char const *str)
{
    register char const *i = str;

    for (; *i; ++i);
    return (i - str);
}

int my_strlen_crt(char const *str, char const end)
{
    register char const *i = str;

    if (str == NULL || *str == end) return (0);
    for (; *i && *i != end; i++);
    return (i - str);
}

int my_strlen_end(char const *str, char const *flag)
{
    register char const *i = str;

    for (; *i && flag_cmp(*i, flag) == 0; ++i);
    return (i - str);
}

int count_nbr_line(char const * const *array)
{
    register char const * const *i = array;

    for (; *i; ++i);
    return (i - array);
}

int my_strlen_cmp(char const *str, char const *end)
{
    int count = 0;

    for (; *str; str++)
        for (char const *i = end; *i; i++)
            count += ((*str == *i) ? (1) : (0));
    return (count);
}

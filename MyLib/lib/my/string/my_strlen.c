/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** count string
*/

#include "my.h"

unsigned int my_strlen(char const *str)
{
    register char const *i = str;

    for (; *i; ++i);
    return (i - str);
}

unsigned int my_strlen_to_crt(char const *str, char const end)
{
    register char const *i = str;

    if (!str || *str == end) return (0);
    for (; *i && *i != end; i++);
    return (i - str);
}

unsigned int my_strlen_to_flag(char const *str, char const *flag,
                               bool const my_bool)
{
    register char const *i = str;

    if (!str || !flag) return (0);
    for (; *i && flag_cmp(*i, flag) == my_bool; ++i);
    return (i - str);
}

unsigned int my_strlen_cmp(char const *str, char const *flag)
{
    unsigned int count = 0;

    for (; *str; str++)
        for (register char const *i = flag; *i; i++)
            count += *str == *i;
    return (count);
}

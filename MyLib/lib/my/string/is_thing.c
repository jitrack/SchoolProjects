/*
** EPITECH PROJECT, 2019
** my_str_isnum
** File description:
** my_str_isnum
*/

#include <stdbool.h>

char is_num(char const *str)
{
    for (; *str ;++str)
        if (*str < '0' || *str > '9')
            return (false);
    return (true);
}

char is_alpha(char const *str)
{
    for (; *str; ++str)
        if (*str <= 'a' || (*str > 'z' && *str < 'A') || *str > 'Z')
            return (false);
    return (true);
}

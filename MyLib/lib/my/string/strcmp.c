/*
** EPITECH PROJECT, 2020
** str_compare
** File description:
** compare two string in alphabetical order
*/

#include <stdbool.h>

bool flag_cmp(char const crt, char const *flag)
{
    for (register char const *i = flag; *i; ++i)
        if (crt == *i) return (true);
    return (false);
}

char my_strcmp(char const *s1, char const *s2)
{
    if (!s1 || !s2) return (84);
    for (; *s1 && *s2 && *s1 == *s2; ++s1, ++s2);
    return (*s1 - *s2);
}

char strcmp_to_crt(char const *s1, char const *s2, char const crt)
{
    for (; *s1 && *s2 && *s1 == *s2 && *(s1 + 1) != crt &&
    *(s2 + 1) != crt; ++s1, ++s2);
    return (*s1 - *s2);
}

char strcmp_to_flag(char const *s1, char const *s2, char const *flag)
{
    for (; *s1 && *s2 && *s1 == *s2 && flag_cmp(s1[1], flag) == false &&
    flag_cmp(s2[1], flag) == false; ++s1, ++s2);
    return (*s1 - *s2);
}

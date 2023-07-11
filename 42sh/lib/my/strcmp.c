/*
** EPITECH PROJECT, 2020
** str_compare
** File description:
** compare two string in alphabetical order
*/

#include <stdbool.h>

char flag_cmp(char const crt, char const *fl)
{
    if (crt == 0)
        return (0);
    for (char const *i = fl; *i; ++i)
        if (crt == *i) return (1);
    return (0);
}

int my_strcmp(char const *s1, char const *s2)
{
    if (!s1 || !s2) return (84);
    while (*s1 && *s2 && *s1 == *s2) {
        ++s1;
        ++s2;
    }
    return (*s1 - *s2);
}

char strcmp_crt(char const *s1, char const *s2, char const crt)
{
    for (; *s1 && *s2 && *s1 == *s2 && *(s1 + 1) != crt &&
    *(s2 + 1) != crt; ++s1, ++s2);
    return (*s1 - *s2);
}

char strcmp_flag(char const *s1, char const *s2, char const *flag)
{
    for (; *s1 && *s2 && *s1 == *s2 && flag_cmp(s1[1], flag) == false &&
    flag_cmp(s2[1], flag) == false; ++s1, ++s2);
    return (*s1 - *s2);
}

short int find_word_in_list(char const *line, char const * const *list,
                            char const *end)
{
    for (char const * const *i = list; *i; ++i) {
        if (!(strcmp_flag(line, *i, end)))
            return (i - list);
    }
    return (-1);
}

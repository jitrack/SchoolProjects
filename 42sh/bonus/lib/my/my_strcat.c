/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** strcat
*/

#include "include/my.h"

char *my_strcat(char const *s1, char const *s2)
{
    char *ret = malloc(my_strlen(s1) + my_strlen(s2) + 1);
    char *i = ret;

    if (!ret) return (NULL);
    for (; *s1; ++s1, ++i)
        *i = *s1;
    for (; *s2; ++s2, ++i)
        *i = *s2;
    *i = '\0';
    return (ret);
}

char *my_strcat_crt(char const *s1, char const *s2, char const crt)
{
    char *new_str = malloc(my_strlen(s1) + my_strlen(s2) + 2);
    int x = -1;

    if (!new_str) return (NULL);
    for (; *s1; ++s1)
        new_str[++x] = *s1;
    new_str[++x] = crt;
    for (; *s2; ++s2)
        new_str[++x] = *s2;
    new_str[++x] = '\0';
    return (new_str);
}

char *my_strcat_end_crt(char const *s1, char const *s2, char const end,
                        char const crt)
{
    char *new_str = malloc(my_strlen_crt(s1, end) + my_strlen(s2) + 2);
    int x = -1;

    if (!new_str) return (NULL);
    for (; *s1 && *s1 != end; ++s1)
        new_str[++x] = *s1;
    new_str[++x] = crt;
    for (; *s2; ++s2)
        new_str[++x] = *s2;
    new_str[++x] = '\0';
    return (new_str);
}

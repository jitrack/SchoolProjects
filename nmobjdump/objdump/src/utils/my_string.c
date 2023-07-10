/*
** EPITECH PROJECT, 2021
** string
** File description:
** string
*/

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int find_last_of(char const *s, char const crt)
{
    char const *i = NULL;

    if (!s)
        return (-1);
    for (; *s; ++s)
        if (*s == crt)
            i = s;
    return (i ? s - i : -1);
}

bool check_extensions(char const *s, char const *ext)
{
    int pos = -1;

    if (!s || !ext)
        return (false);
    return ((pos = find_last_of(s, *ext)) >= 0 && !strcmp(s + pos, ext));
}

unsigned int my_strlen(char const *str)
{
    register char const *i = str;

    if (!str || !*str) return (0);
    for (; *i; ++i);
    return (i - str);
}

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

/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** copy a string into an other
*/

#include "include/my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    if (src[0] == '\0' || !src || !dest) return (NULL);
    for (; src[i]; ++i)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}

char *my_strcpy_m(char const *src)
{
    char *dest = malloc(my_strlen(src) + 1);
    char *i = dest;

    if (!src || !dest || *src == '\0') return (NULL);
    for (; *src; ++src, ++i)
        *i = *src;
    *i = '\0';
    return (dest);
}

char *my_strcpy_crt_m(char const *src, char const n)
{
    char *dest = malloc(my_strlen_crt(src, n) + 1);
    int i = 0;

    if (!src || src[0] == '\0' || !dest) return (NULL);
    for (; src[i] && src[i] != n; ++i)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}

char *my_strcpy_crt(char *dest, char const *src, char const n)
{
    int i = 0;

    if (src[0] == '\0' || !src || !dest) return (NULL);
    for (; src[i] && src[i] != n; ++i)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}

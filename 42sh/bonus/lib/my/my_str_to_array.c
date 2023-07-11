/*
** EPITECH PROJECT, 2020
** my_str_to_array
** File description:
** my_str_to_array
*/

#include "include/my.h"

int nbr_ln(char const *str, char const sptr, int *count)
{
    for (; *str; str++)
        if ((*str != sptr && (*(str + 1) == '\0') || *(str + 1) == sptr))
            ++*count;
    return (*count);
}

int size_line(char const *str, char const sptr)
{
    char const *i = str;

    for (; *i != sptr && *i; i++);
    return (i - str);
}

int create_new_line(char const *str, int *x, int *y, char const sptr)
{
    char const *i = str;

    ++*y;
    *x = 0;
    for (; (*i) && (*i) == sptr; i++);
    return (i - str - 1);
}

char **str_to_array(char const *str, char const sptr)
{
    int ct = 0;
    char **array = malloc(sizeof(char *) * (nbr_ln(str, sptr, &ct) + 1));
    int y = 0;
    int x = 0;

    if (array == NULL) return (NULL);
    array[0] = malloc(size_line(str, sptr) + 1);
    for (int i = 0; str[i] && y < ct; ++i) {
        if (*(array + i) ==  NULL) return (NULL);
        if (str[i] == sptr) {
            array[y][x] = '\0';
            array[y + 1] = malloc(size_line(str + i + 1, sptr) + 1);
            i += create_new_line(str + i, &x, &y, sptr);
        } else if (y < ct) {
            array[y][x] = str[i];
            ++x;
        }
    }
    array[y][x] = '\0';
    array[ct] = NULL;
    return (array);
}

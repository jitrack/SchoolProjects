/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** returns an int
*/

#include <unistd.h>

int nbr_detect(int st, char const *str)
{
    char const *i = str + st;

    for (; *i && (*i < 48 || *i > 57); i++);
    if (!*i)
        return (-1);
    return (i - str);
}

int my_getnbr(char const *str)
{
    int j = nbr_detect(0, str);
    int neg = 0;
    int nb = 0;

    if (j == -1)
        return (-0);
    for (char x = j; str[x] == '-'; --x)
        ++neg;
    for (char const *i = str + j; *i >= 47 && *i <= 57; i++)
        nb = (nb * 10) + (*i - 48);
    return ((neg & 1) == 1 ? (nb * -1) : (nb));
}

int my_getnbr_st(char const *str, int start)
{
    int j = nbr_detect(start, str);
    int i = j;
    int neg = 0;
    int nb = 0;

    if (i == -1)
        return (-0);
    while (str[j] == '-') {
        ++neg;
        --j;
    }
    while (str[i] >= 48 && str[i] <= 57) {
        nb = (nb * 10) + (str[i] - 48);
        ++i;
    }
    if (neg % 2 != 0)
        nb *= -1;
    return (nb);
}

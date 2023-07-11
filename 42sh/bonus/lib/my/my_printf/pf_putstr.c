/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** displays a string
*/

#include "my_printf.h"
#include <unistd.h>

int my_len(char const *str)
{
    char const *i = str;

    for (; (*i); i++);
    return (i - str);
}

int pf_putstr(va_list ls, int ch)
{
    char const *str = va_arg(ls, char *);
    int len = my_len(str);

    write(ch, str, len);
    return (len);
}

int pf_print_ch(va_list ls, int ch __attribute__((unused)))
{
    char const *str = va_arg(ls, char *);
    int channel = va_arg(ls, int);
    int len = my_len(str);

    write(channel, str, len);
    return (len);
}

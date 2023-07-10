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
    register char const *i = str;

    for (; *i; i++);
    return (i - str);
}

int pf_putstr(va_list const ls, unsigned char const ch)
{
    char const *str = va_arg(ls, char *);
    int len = my_len(str);

    write(ch, str, len);
    return (len);
}

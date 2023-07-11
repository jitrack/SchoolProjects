/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** my_printf
*/

#include "my_printf.h"
#include <stdarg.h>

void str_analys(va_list ls, char const *str, int *len, int ch)
{
    char *fl = "dcsw";
    char *i = fl;

    for (; (*i) && (*i) != (*str); i++);
    *len += fl_fct[i - fl](ls, ch);
}

int my_printf(char const ch, char const *str, ...)
{
    va_list ls;
    int ofst = 0;
    int i = 0;
    int len = 0;

    va_start(ls, str);
    for (; str[i]; ++i)
        if (str[i] == '%') {
            write(ch, str + ofst, i - ofst);
            str_analys(ls, str + i + 1, &len, ch);
            len += i - ofst;
            ofst = i + 2;
        }
    write(ch, str + ofst, i - ofst);
    va_end(ls);
    return (len + (i - ofst));
}

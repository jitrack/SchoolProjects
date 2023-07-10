/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** my_printf
*/

#include "my_printf.h"
#include <stdarg.h>

int pf_put_gfloat_nbr(va_list const ls, unsigned char const);

int pf_put_float_nbr(va_list const ls, unsigned char const);

static void str_analys(va_list ls, char const *str, int *len,
                        unsigned char const ch)
{
    static int (*fl_fct[5])(va_list const, unsigned char const)
    __attribute__((unused)) =
    {&pf_put_int_nbr, &pf_putchar, &pf_putstr,
    &pf_put_float_nbr, &pf_put_gfloat_nbr};
    char const *fl = "dcsfg";
    register char const *i = fl;

    for (; *i && *i != *str; i++);
    *len += fl_fct[i - fl](ls, ch);
}

unsigned int my_printf(unsigned char const ch, char const *str, ...)
{
    va_list ls;
    int len = 0;
    char const *i = str;
    char const *start = str;

    va_start(ls, str);
    for (; *i; ++i)
        if (*i == '%') {
            write(ch, start, i - start);
            str_analys(ls, i + 1, &len, ch);
            len += i - start - 2;
            start = i + 2;
        }
    write(ch, start, i - start);
    va_end(ls);
    return (len + (i - start));
}

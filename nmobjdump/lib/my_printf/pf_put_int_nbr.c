/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** displays numbers
*/

#include "my_printf.h"

int count_nbr_printf(int nb, int size, int *len)
{
    while (nb > 0) {
        nb /= 10;
        size *= 10;
        ++*len;
    }
    return (size);
}

int pf_put_int_nbr(va_list const ls, unsigned char const ch)
{
    int nb = va_arg(ls, int);
    int size = 1;
    int len = 0;

    (nb < 0) ? (my_ptc('-', ch)) : (nb);
    (nb < 0) ? (nb *= -1) : (nb);
    size = count_nbr_printf(nb, size, &len);
    if (size != 1) {
        for (int i = size / 10; i > 0; i /= 10)
            my_ptc(((nb / i) % 10) + 48, ch);
    } else
        my_ptc(nb + 48, ch);
    return (len);
}

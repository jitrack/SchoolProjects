/*
** EPITECH PROJECT, 2020
** pf_put_float_nbr
** File description:
** pf_put_float_nbr
*/

#include "my_printf.h"

int pf_put_float_nbr(va_list const ls, unsigned char const ch)
{
    float decimal_part = va_arg(ls, double);
    int size = 1, len = 0, int_part = 0;

    if (decimal_part < 0) {
        my_ptc('-', ch);
        decimal_part *= -1;
    }
    int_part = decimal_part;
    if ((size = count_nbr_printf(int_part, size, &len)) != 1) {
        for (int i = size / 10; i > 0; i /= 10)
            my_ptc(((int_part / i) % 10) + 48, ch);
    } else
        my_ptc(int_part + 48, ch);
    my_ptc('.', ch);
    for (char i = 0; i < 5; ++i) {
        decimal_part *= 10;
        my_ptc((int)(decimal_part) % 10 + 48, ch);
    }
    return (len + 7);
}

static int handle_float_part(int const len, unsigned char const ch,
                            float decimal_part)
{
    char decimal[6];
    char offset = 0;
    char i = 5;

    if ((int)decimal_part == 0) decimal_part += 1;
    decimal_part += (((int)decimal_part == 0) ? (1) : (0));
    *decimal = '.';
    for (char i = 1; i < 6; ++i) {
        decimal_part *= 10;
        decimal[i] = (int)(decimal_part) % 10 + 48;
    }
    for (; decimal[i] == '0'; --i);
    if (decimal[i] == '.')
        return (len);
    else
        write(ch, decimal, i + 1);
    return (len + i + 1);
}

int pf_put_gfloat_nbr(va_list const ls, unsigned char const ch)
{
    float decimal_part = va_arg(ls, double);
    int int_part = 0;
    int size = 1;
    int len = 0;

    if (decimal_part < 0) {
        my_ptc('-', ch);
        decimal_part *= -1;
    }
    int_part = decimal_part;
    size = count_nbr_printf(int_part, size, &len);
    if (size != 1) {
        for (unsigned int i = size / 10; i > 0; i /= 10)
            my_ptc(((int_part / i) % 10) + 48, ch);
    } else
        my_ptc(int_part + 48, ch);
    return (handle_float_part(len, ch, decimal_part));
}

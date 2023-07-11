/*
** EPITECH PROJECT, 2019
** my_putchar
** File description:
** display char caracters
*/

#include "my_printf.h"
#include <unistd.h>

int pf_putchar(va_list ls, int ch)
{
    char const c = va_arg(ls, int);

    write(ch, &c, 1);
    return (1);
}

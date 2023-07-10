/*
** EPITECH PROJECT, 2019
** my_putchar
** File description:
** display char caracters
*/

#include "my_printf.h"
#include <unistd.h>

void my_ptc(char const c, unsigned char const ch)
{
    write(ch, &c, 1);
}

int pf_putchar(va_list const ls, unsigned char const ch)
{
    char const c = va_arg(ls, int);

    write(ch, &c, 1);
    return (1);
}

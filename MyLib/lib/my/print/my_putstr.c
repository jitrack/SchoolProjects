/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** displays strings
*/

#include "my.h"
#include <unistd.h>

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}

void my_putstr_ch(char const *str, int const ch)
{
    write(ch, str, my_strlen(str));
}

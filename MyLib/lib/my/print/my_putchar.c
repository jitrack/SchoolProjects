/*
** EPITECH PROJECT, 2019
** my_putchar
** File description:
** display a char
*/

#include <unistd.h>

void my_putchar(char const c)
{
    write(1, &c, 1);
}

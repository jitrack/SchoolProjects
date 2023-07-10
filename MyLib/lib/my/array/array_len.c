/*
** EPITECH PROJECT, 2020
** array_len
** File description:
** array_len
*/

#include "my.h"

unsigned int array_len(void const *start)
{
    register intptr_t const *i = start;

    for (; *i; ++i);
    return ((i - (intptr_t const *)start));
}

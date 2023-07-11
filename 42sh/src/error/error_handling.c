/*
** EPITECH PROJECT, 2020
** error_handling
** File description:
** error_handling
*/

#include "../../include/src.h"

int error_start(int const ac, char const * const *env)
{
    if (ac != 1 || !env || !env[0])
        exit(84);
    return (0);
}

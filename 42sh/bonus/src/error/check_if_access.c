/*
** EPITECH PROJECT, 2020
** check_if_access
** File description:
** check_if_access
*/

#include "../../include/src.h"

bool check_right(char const *path, int const mode)
{
    int rights = access(path, mode);

    if (rights == 0)
        return (true);
    return (false);
}

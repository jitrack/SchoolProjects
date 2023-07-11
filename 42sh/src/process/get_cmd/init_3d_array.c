/*
** EPITECH PROJECT, 2020
** init_3d_array
** File description:
** init_3d_array
*/

#include "src.h"

char ***init_3d_array(char ****x, int *nb_cmd)
{
    char const error[2][29] = {{"Missing name for redirect.\n"},
                            {"Invalid null command.\n"}};
    char ***array = NULL;

    if (*nb_cmd < 0 && *nb_cmd > -3) {
        my_printf(2, "%s", error[*nb_cmd + 2]);
        return (NULL);
    }
    array = malloc(sizeof(char **) * ((*nb_cmd = *nb_cmd * 2 - 1) + 1));
    *x = array;
    return (array);
}

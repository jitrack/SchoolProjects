/*
** EPITECH PROJECT, 2019
** my_int_to_array
** File description:
** put numbers in a string
*/

#include "include/my.h"
#include <unistd.h>

int my_nbr_len(int nb)
{
    int ret = 2;

    if (nb < 0) {
        nb *= -1;
        ++ret;
    }
    while (nb >= 10) {
        nb /= 10;
        ++ret;
    }
    return (ret);
}

char *my_int_to_array(int nb)
{
    int nbsrc;
    int div = 1;
    char *res = malloc(my_nbr_len(nb));
    int filler = 0;

    if (nb < 0)
        res[filler++] = '-';
    nbsrc = nb;
    while (nb > 0) {
        nb /= 10;
        div *= 10;
    }
    if (div != 1) {
        for (int i = div / 10; i > 0; i /= 10)
            res[filler++] = ((nbsrc / i) % 10) + 48;
    } else
        res[filler++] = nbsrc + 48;
    res[my_nbr_len(nbsrc) - 1] = '\0';
    return (res);
}

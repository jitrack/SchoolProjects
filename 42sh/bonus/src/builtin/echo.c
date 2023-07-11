/*
** EPITECH PROJECT, 2020
** echo
** File description:
** echo
*/

#include "../../include/src.h"

static void print_words(sh_t *sh, char **cmd, char flag, int nbr)
{
    int index = (('0' == flag) ? (2) : (1));

    if (2 == nbr && 0 == my_strcmp(cmd[1], "-n"))
        return;
    for (int i = index; cmd[i]; ++i) {
        if (0 == my_strcmp(cmd[i], "$?"))
            my_printf(1, "%d", sh->last);
        else
            my_putstr(cmd[i]);
        if (NULL != cmd[i + 1])
            my_putchar(' ');
    }
    if ('1' == flag)
        my_putchar('\n');
}

static char find_flag(char **cmd)
{
    int nbr = count_nbr_line((char const * const *)cmd);

    if (1 == nbr)
        return ('1');
    if (0 != my_strcmp(cmd[1], "-n"))
        return ('1');
    return ('0');
}

int my_echo(sh_t *sh, char **cmd)
{
    char flag = find_flag(cmd);
    int nbr = count_nbr_line((char const * const *)cmd);

    if (1 == nbr)
        my_putchar('\n');
    else
        print_words(sh, cmd, flag, nbr);
    return (0);
}

/*
** EPITECH PROJECT, 2019
** check_setenv
** File description:
** check_setenv
*/

#include "src.h"

static char setenv_check_name(char **cmd)
{
    if (cmd[1] && LET(cmd[1][0]) == 0) {
        my_putstr_ch(SETENV_BAD_NAME, 2);
        return (-1);
    }
    for (int i = 0; cmd[1][i]; ++i)
        if (!('A' <= cmd[1][i] && 'Z' >= cmd[1][i]) &&
            !('a' <= cmd[1][i] && 'z' >= cmd[1][i]) &&
            !('0' <= cmd[1][i] && '9' >= cmd[1][i]) && '_' != cmd[1][i]) {
            my_putstr_ch("setenv: Variable name must contain ", 2);
            my_putstr_ch("alphanumeric characters.\n", 2);
            return (-1);
        }
    return (0);
}

char setenv_check(char **cmd, sh_t *sh)
{
    if (count_nbr_line((char const * const *)(cmd + 1)) > 2) {
        my_putstr_ch(SETENV_ARG_ERROR, 2);
        return (-1);
    }
    if (!cmd[1]) {
        disp_env(sh, cmd);
        return (-1);
    }
    if (-1 == setenv_check_name(cmd))
        return (-1);
    return (0);
}

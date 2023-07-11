/*
** EPITECH PROJECT, 2020
** environement
** File description:
** environement
*/

#include "../../include/src.h"

int disp_env(sh_t *sh, char **cmd)
{
    if (count_nbr_line((char const * const *)cmd) > 1) {
        my_printf(2, "env: ‘%s’: No such file or directory\n", cmd[1]);
        return (-1);
    }
    if (!sh->env || !sh->env[0]) return (84);
    for (char **i = sh->env; *i; ++i) {
        my_putstr(*i);
        my_putchar('\n');
    }
    return (0);
}

int search_environnement_var(char const *name, char const * const *env)
{
    if (!env || !env[0] || !name) return (-1);
    for (char const * const *i = env; *i; i++)
        if (name[0] == (*i)[0] && strcmp_crt(name, *i, '=') == 0)
            return (i - env);
    return (-1);
}

void home_tile_replace(char **str, char const * const *env)
{
    int const home = search_environnement_var("HOME", env);
    char *tmp = *str;

    if (home < 0) return;
    *str = ((my_strlen(*str) > 1) ? (my_strcat(env[home] + 5, *str + 1)) :
            (my_strcpy_m(env[home] + 5)));
    if (tmp) free(tmp);
}

char *get_pwd(void)
{
    return (getcwd(NULL, 0));
}

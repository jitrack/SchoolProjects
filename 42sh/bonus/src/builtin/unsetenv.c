/*
** EPITECH PROJECT, 2020
** unsetenv
** File description:
** unsetenv
*/

#include "../../include/src.h"

static char check_env_var_rm(int y, int *ln, int rm_len)
{
    for (int i = 0; i < rm_len; ++i)
        if (ln[i] == y)
            return (1);
    return (0);
}

static char **rm_env_var(char **env, int *len, int rm_len)
{
    int nbr_line = count_nbr_line((char const * const *)env);
    char **new_env = malloc(sizeof(char *) * (nbr_line - rm_len + 1));
    int offset = 0;

    if (!new_env) return (NULL);
    for (int y = 0; env[y]; ++y)
        if (check_env_var_rm(y, len, rm_len) == 1) {
            freeif(env[y]);
            ++offset;
        } else
            new_env[y - offset] = env[y];
    new_env[nbr_line - rm_len] = NULL;
    freeif(env);
    return (new_env);
}

int my_unsetenv(sh_t *sh, char **cmd)
{
    int rm_len = ((!cmd[1]) ?
                (0) : (count_nbr_line((char const * const *)cmd + 1)));
    int tmp = 0, offset = 0;
    int *rm;

    if (rm_len == 0) {
        my_putstr_ch(UNSETENV_ARG_ERROR, 2);
        return (84);
    } else if (!(rm = malloc(sizeof(int) * rm_len))) return (84);
    for (int i = 0; i < rm_len; ++i) {
        if ((tmp = SEARCH_ENV_VAR(cmd[i + 1])) >= 0) rm[i - offset] = tmp;
        else ++offset;
    }
    sh->env = rm_env_var(sh->env, rm, rm_len - offset);
    freeif(rm);
    sh->bin_path = search_env_var_content(sh, "PATH", true);
    return (0);
}

/*
** EPITECH PROJECT, 2020
** setenv
** File description:
** setenv
*/

#include "../../include/src.h"

static int filling_in(char const *str, char **env, int offset, char crt)
{
    int a = 0;

    for (; str[a]; ++a)
        (*env)[a + offset] = str[a];
    (*env)[a + offset] = crt;
    return (my_strlen(str) + 1);
}

static void replace_env_var(char const *name, char const *val, char **env,
    int bl)
{
    short int vl = ((val) ? (0) : (1));
    int offset = 0;
    int len = my_strlen(name);

    if (bl == 1 && *env)
        free(*env);
    *env = malloc(len + ((vl == 0) ? (my_strlen(val)) : (0)) + 2);
    if (!*env)
        return;
    offset += filling_in(name, env, offset, '=');
    if (vl == 1)
        (*env)[offset] = '\0';
    else
        offset += filling_in(val, env, offset, '\0');
}

static void add_env_var(char ***env, char const *name, char const *value)
{
    int nbr_line = count_nbr_line((char const * const *)*env);
    char **new_env = malloc(sizeof(char *) * (nbr_line + 2));

    if (!new_env)
        return;
    for (int y = 0; (*env)[y]; ++y)
        new_env[y] = (*env)[y];
    replace_env_var(name, value, &new_env[nbr_line], 0);
    new_env[nbr_line + 1] = NULL;
    freeif(*env);
    *env = new_env;
}

int my_setenv(sh_t *sh, char **cmd)
{
    int err = setenv_check(cmd, sh);
    int modif =
        ((cmd[1] && err == 0) ? (search_environnement_var(cmd[1],
        (char const * const *)sh->env)) : (-1));

    if (err == -1)
        return (-2);
    if (modif >= 0)
        replace_env_var(cmd[1], cmd[2], &sh->env[modif], 1);
    else if (!cmd[1])
        disp_env(sh, cmd);
    else
        add_env_var(&sh->env, cmd[1], cmd[2]);
    return (modif);
}

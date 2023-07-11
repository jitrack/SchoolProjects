/*
** EPITECH PROJECT, 2020
** cd
** File description:
** cd
*/

#include "../../include/src.h"

static char if_cd_is_alone(sh_t *sh)
{
    short int home = search_environnement_var("HOME",
    (char const * const *)sh->env);

    if (home >= 0)
        return ((chdir(sh->env[home] + 5) == 0) ? (1) : (84));
    return (84);
}

static char cd_get_back(sh_t *sh, int const old_pwd, int const len,
                        char const * const * cmd)
{
    if (cmd[1][0] == '-' && len > 1) {
        my_printf(2, "Usage: cd [-plvn][-|<dir>].\n");
        return (84);
    } else if (cmd[1][0] == '-' && len == 1 && old_pwd >= 0) {
        if (my_strcmp(sh->pwd, sh->env[old_pwd] + 7) != 0)
            chdir(sh->env[old_pwd] + 7);
        else
            my_printf(2, "%s\n", sh->pwd);
        return (1);
    }
    return (0);
}

static char cd_check(sh_t *sh, int const old_pwd, char **cmd)
{
    int len = 0;

    if (!1[cmd]) return (if_cd_is_alone(sh));
    if (count_nbr_line((char const * const *)cmd) > 2) {
        my_printf(2, "cd: Too many arguments.\n");
        return (84);
    } else if (*(cmd[1]) != '-' && !check_path_right(cmd[1], cmd[1]))
        return (84);
    else if (1[cmd]) {
        len = my_strlen(cmd[1]);
        if (cmd[1][0] == '~' && (len == 1 || (len >= 2 && cmd[1][1] == '/')))
            home_tile_replace(&(*(cmd + 1)), (char const * const *)sh->env);
        else if (cmd[1][0] == '~' && len > 1 && cmd[1][1] != '/') {
            my_printf(2, "Unknown user: %s.\n", cmd[1]);
            return (84);
        }
    }
    if (1[cmd] && cd_get_back(sh, old_pwd, len,
    (char const * const *)cmd) > 0) return (84);
    return (chdir(cmd[1]));
}

int cd(sh_t *sh, char **cmd)
{
    unsigned short int old_pwd =
        search_environnement_var("OLDPWD", (char const * const *)sh->env);
    int error = cd_check(sh, old_pwd, cmd);
    char **tmp = NULL;

    if (error == 85) return (84);
    if (error == -1) my_printf(2, "%s: %s.\n", cmd[1], strerror(errno));
    tmp = create_2darray(3, "cd", "OLDPWD", sh->pwd);
    if (!tmp) return (84);
    my_setenv(sh, tmp);
    freeif(sh->pwd);
    sh->pwd = my_strcpy_m(get_pwd());
    if (!sh->pwd) return (84);
    my_memmove(&(tmp[1]), 3);
    my_setenv(sh, tmp);
    free_2d_array(tmp);
    sh->bin_path = search_env_var_content(sh, "PATH", true);
    return (0);
}

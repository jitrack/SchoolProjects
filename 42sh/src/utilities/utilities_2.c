/*
** EPITECH PROJECT, 2020
** utilities_2
** File description:
** utilities_2
*/

#include "src.h"

int my_strlen_flag(char const *str, char const *flag)
{
    char const *i = str;
    unsigned char into = 0;

    for (; *i; ++i) {
        if (*i == '"') {
            TOGGLE(into, quote_e);
            --str;
        }
        if (BIT(into, quote_e) == 0 && flag_cmp(*i, flag) == 1)
            return (i - str);
    }
    return (i - str);
}

char *search_env_var_content(sh_t *sh, char const *var, bool const remove_name)
{
    short int line = SEARCH_ENV_VAR(var);

    if (line < 0) return (NULL);
    return ((remove_name == true) ?
    (sh->env[line] + my_strlen_crt(sh->env[line], '=') + 1) : (sh->env[line]));
}

bool check_path_right(char const *path, char const *str)
{
    if (check_right(path, F_OK) == false || errno == ENOENT) {
        my_printf(2, "%s: No such file or directory.\n", str);
        return (false);
    } else if (check_right(path, R_OK) == false) {
        my_printf(2, "%s: Permission denied.\n", str);
        return (false);
    }
    return (true);
}
